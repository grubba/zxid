/* app_demo.java  -  Demonstrate detecting missing session and redirection to zxidsrvlet
 * Adapted from  zxidappdemo.java
 * Copyright (c) 2011-2012 Synergetics (sampo@synergetics.be), All Rights Reserved.
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidappdemo.java,v 1.4 2009-11-29 12:23:06 sampo Exp $
 * 16.10.2009, created --Sampo
 * 6.2.2012, added use of ZXIDConf <init-param> --Sampo
 *
 * This servlet plays the role of "payload" servlet in ZXID SSO servlet
 * integration demonstration. It illustrates the steps
 * 1.  Detect that there is no session and redirect to zxidsrvlet; and
 * 7.  Access to protected resource, with attributes already populated
 *     to the HttpSession (JSESSION)
 * 9.  Making a web service call by directly calling zxid_call()
 *
 * See also: zxid-java.pd, zxidwspdemo.java for server side
 * https://sp.personaldata.eu:8443/e2eTA/app-demo
 */

import zxidjava.*;   // Pull in the zxidjni.az() API
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.Enumeration;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class app_demo extends HttpServlet {
    static final boolean verbose = false;
    static final Pattern fedusername_pat = Pattern.compile("fedusername:[ ]([^\\n]*)");
    static final Pattern idpnid_pat = Pattern.compile("idpnid:[ ]([^\\n]*)");
    static final Pattern nidfmt_pat = Pattern.compile("nidfmt:[ ]([^\\n]*)");
    static final Pattern affid_pat  = Pattern.compile("affid:[ ]([^\\n]*)");
    static final Pattern eid_pat    = Pattern.compile("eid:[ ]([^\\n]*)");
    static final Pattern cn_pat     = Pattern.compile("cn:[ ]([^\\n]*)");
    static final Pattern o_pat      = Pattern.compile("o:[ ]([^\\n]*)");
    static final Pattern ou_pat     = Pattern.compile("ou:[ ]([^\\n]*)");
    static final Pattern role_pat   = Pattern.compile("role:[ ]([^\\n]*)");
    static final Pattern boot_pat   = Pattern.compile("urn:liberty:disco:2006-08:DiscoveryEPR:[ ]([^\\n]*)");

    static zxidjava.zxid_conf cf;
    static String ptm;

    public static String ReadAll(String path) throws IOException {
        FileReader in = new FileReader(path);
        StringBuilder sb = new StringBuilder();
        char[] buf = new char[4096];
        int got = 0;
        do {
            sb.append(buf, 0, got);
            got = in.read(buf);
        } while (got >= 0);
	in.close();
        return sb.toString();
    }

    static {
	System.loadLibrary("zxidjni");
	// CONFIG: You must have created /var/zxid directory hierarchy. See `make dir'
	// CONFIG: You must create edit the URL to match your domain name and port
	// CONFIG: Usually you create and edit /var/zxid/zxid.conf and override the URL there
	//String conf = getServletConfig().getInitParameter("ZXIDConf"); 
	//String conf = getServletContext().getInitParameter("ZXIDConf"); 
	//cf = zxidjni.new_conf_to_cf(conf);
	//zxidjni.set_opt(cf, 1, 1);
	try {
	    ptm = ReadAll("ptm-include.html");
	} catch(IOException e) {
	    System.err.print("File not found(ptm-include.html)\n");
	    System.err.print("Working Directory(" + System.getProperty("user.dir") + ")\n");
	}
    }
    
    public void doGet(HttpServletRequest req, HttpServletResponse res)
	throws ServletException, IOException
    {
	String fullURL = req.getRequestURI();
	String qs = req.getQueryString();
	if (qs != null)
	    fullURL += "?" + req.getQueryString();
	else
	    qs = "";
	System.err.print("========= Start App-Demo GET("+fullURL+")...\n");
	HttpSession ses = req.getSession(false);  // Important: do not allow automatic session.
	if (ses == null) {                        // Instead, redirect to sso servlet.
	    res.sendRedirect("sso?o=E&fr=" + fullURL);
	    return;
	}
	
	if (cf == null) {
	    System.err.print("Running conf\n");
	    String conf = getServletConfig().getInitParameter("ZXIDConf"); 
	    cf = zxidjni.new_conf_to_cf(conf);
	    zxidjni.set_opt(cf, 1, 1);  // Debug on
	    zxidjni.set_opt(cf, 7, 3);  // Cause glibc malloc/free to dump core on error
	}
	String sid = ses.getAttribute("sesid").toString();
	ServletOutputStream out = res.getOutputStream();
	
	res.setContentType("text/html");
	out.print("<title>Demo App Protected Content</title>\n");
	out.print("<link type=\"text/css\" rel=stylesheet href=\"/idpsel.css\">\n<body>");
	out.print("<table align=right><tr><td>");
	//out.print("<a href=\"http://www.tas3.eu/\"><img src=\"tas3-logo.jpg\" height=64 border=0></a>");
	//out.print("<a href=\"http://zxid.org/\"><img src=\"logo-zxid-128x128.png\" height=64 border=0></a>");
	out.print("<a href=\"http://synergetics.be/\"><img src=\"synlogo_s.jpg\" height=67 border=0></a><br>");
	out.print(ptm);
	//out.print("<iframe id=localnav class=nav src=\"/nav.html\"><a href=\"https://idp.i-dent.eu/nav.html\">Navigation iFrame</a></iframe><br>");
	out.print("<br><iframe id=idpnav class=nav width=300 height=300 src=\"https://idp.i-dent.eu/nav.html\"><a href=\"https://idp.i-dent.eu/nav.html\">Navigation iFrame from IdP</a></iframe><br>");
	out.print("</td></tr></table>");
	out.print("<h1>end2end Trust Assurance Demo App Protected Content</h1>\n");
	//out.print("<h1>ZXID Demo App Protected Content</h1> at " + fullURL + "\n");

	// Render logout buttons (optional)

	out.print("[<a href=\"sso?gl=1&s="+sid+"\">Local Logout</a> | <a href=\"sso?gr=1&s="+sid+"\">Single Logout</a>]\n");

	// The SSO servlet will have done one iteration of authorization. The following
	// serves to illustrate, how to explicitly call a PDP from your code.

	System.err.print("----- about to az\n");
	if (zxidjni.az_cf(cf, "Action=Show&Resource=app_demo", sid) == null) {
	    out.print("<p><b>Denied.</b> Normally page would not be shown, but we show the session attributes for debugging purposes.\n");
	    //res.setStatus(302, "Denied");
	} else {
	    out.print("<p>Authorized.\n");
	}

	out.print("<table align=right><tr><td>");
	out.print("<img src=\"tas3-recurs-demo.png\" width=500 border=0>");
	out.print("</td></tr></table>");

	// Render protected content page (your application starts working)

	out.print("<h4>HttpSession dump:</h4>");
	Enumeration val_names = ses.getAttributeNames();
	while (val_names.hasMoreElements()) {
	    String name = (String)val_names.nextElement();
	    if (name.equals("cn")
		|| name.equals("role")
		|| name.equals("o")
		|| name.equals("ou")
		|| name.equals("idpnid")
		|| name.equals("nidfmt")
		|| name.equals("affid")
		|| name.equals("eid")
		|| name.equals("urn:liberty:disco:2006-08:DiscoveryEPR")) {
		out.print("<b>" + name + "</b>: " + ses.getAttribute(name) + "<br>\n");
	    } else {
		if (verbose)
		    out.print(name + ": " + ses.getAttribute(name) + "<br>\n");
	    }
	}
	out.print("<p>");
	out.print("[ <a href=\"?idhrxml\">tas3_call(idhrxml)</a>");
	out.print(" | <a href=\"?x-foobar\">Recursive Echo</a>");
	out.print(" | <a href=\"?leaf\">Leaf Echo</a>");
	out.print(" | <a href=\"?multidi\">Multi discovery</a>");
	out.print(" | <a href=\"?multi\">Multi discovery and call</a>");
	out.print(" | <a href=\"?all\">All</a>");
	out.print(" | <a href=\"?exit\">Exit Java</a>");
	out.print("]<p>");

	// Demo web service call to zxidhrxmlwsp

	String ret;
	zxid_ses zxses = zxidjni.fetch_ses(cf, sid);
	
	System.err.print("----- dispatch qs="+qs+"\n");
	if (qs.equals("idhrxml") || qs.equals("all")) {
	    out.print("<p>Output from idhrxml web service call sid("+sid+"):<br>\n<textarea cols=80 rows=20>");
	    ret = zxidjni.call(cf, zxses,
			       zxidjni.zx_xmlns_idhrxml,
			       "http://sp.tas3.pt:8081/zxidhrxmlwsp?o=B",
			       null,
			       "Resource=hrxml",
			       "<idhrxml:Query>"
			       + "<idhrxml:QueryItem>"
			       + "<idhrxml:Select></idhrxml:Select>"
			       + "</idhrxml:QueryItem>" +
			       "</idhrxml:Query>");

	    ret = zxidjni.extract_body(cf, ret);
	    out.print(ret);
	    out.print("</textarea>");
	}
	
	// Demo another web service call, this time the service by zxidwspdemo.java

	if (qs.equals("x-foobar") || qs.equals("all")) {
	    out.print("<p>Output from recursive web service call:<br>\n");
	    ret = zxidjni.call(cf, zxses, "urn:x-foobar",
			       //"http://sp.tas3.pt:8080/zxidservlet/wspdemo?o=B",
			       "https://sp.employeedata.eu:8444/e2eTA/wspdemo?o=B",
			       null,
			       "Resource=demo",
			       "<foobar>Do it!</foobar>");
	    
	    ret = zxidjni.extract_body(cf, ret);
	    if (ret.indexOf("code=\"OK\"") == -1) {
		out.print("<p>Error from call:<br>\n<textarea cols=80 rows=20>");
		out.print(ret);
		out.print("</textarea>\n");
	    } else {
		out.print("<p>Output from Leaf web services call (relayed by middle call):<br>\n");
		hilite_fields(out, ret, 1);
		out.print("<p>Output from Middle web services call:<br>\n");
		hilite_fields(out, ret, 2);
		if (true || verbose) {
		    out.print("<textarea cols=80 rows=20>");
		    out.print(ret);
		    out.print("</textarea>\n");
		}
	    }
	}
	
	// Demo another web service call, this time the service by zxidwspleaf.java

	if (qs.equals("leaf") || qs.equals("all")) {
	    System.err.print("--- Leaf call\n");
	    zxidjni.set_opt(cf, 7, 3);  // Cause glibc malloc/free to dump core on error
	    ret = zxidjni.call(cf, zxses, "x-recurs", null, null, "Resource=leaf",
			       "<foobar>Do it!</foobar>");
	    System.err.print("--- leaf ret("+ret+")\n");
	    
	    ret = zxidjni.extract_body(cf, ret);
	    if (ret.indexOf("code=\"OK\"") == -1) {
		out.print("<p>Error from call:<br>\n<textarea cols=80 rows=20>");
		out.print(ret);
		out.print("</textarea>\n");
		System.err.print("^^^ leaf err done\n");
	    } else {
		out.print("<p>Output from Leaf web services call:<br>\n");
		hilite_fields(out, ret, 1);
		if (true || verbose) {
		    out.print("<textarea cols=80 rows=20>");
		    out.print(ret);
		    out.print("</textarea>\n");
		}
		System.err.print("^^^ leaf done\n");
	    }
	}
	
	// Multidiscovery

	if (qs.equals("multidi")) {
	    out.print("<h4>Multidiscovery</h4>\n");
	    
	    zxid_epr epr[] = new zxid_epr[100];
	    
	    for (int i=1; i<100; ++i) {
		epr[i] = zxidjni.get_epr(cf, zxses, "urn:x-foobar", null, null, null, i);
		if (epr[i] == null)
		    break;
		out.print("<p>EPR "+i+" <a href=\"?o=call&url="+zxidjni.get_epr_address(cf, epr[i])+"\">Call</a>");
		out.print(" desc("+zxidjni.get_epr_desc(cf, epr[i])+") svctype(urn:x-foobar)<br>\n");
		out.print(" address("+zxidjni.get_epr_address(cf, epr[i])+")<br>\n");
		out.print(" entid("+zxidjni.get_epr_entid(cf, epr[i])+")<br>\n");
	    }
	}

	// Call specific

	if (qs.startsWith("o=call&url=")) {
	    String url = qs.substring(11);
	    out.print("<h4>Specific Call</h4>\n");
	    ret = zxidjni.call(cf, zxses, "urn:x-foobar", url, null, "Resource=demo",
			       "<foobar>do it</foobar>");
	    ret = zxidjni.extract_body(cf, ret);
	    if (ret.indexOf("code=\"OK\"") == -1) {
		out.print("<p>Error from call address("+url+"):<br>\n<textarea cols=80 rows=20>");
		out.print(ret);
		out.print("</textarea>\n");
	    } else {
		out.print("<p>Output from call address("+url+"):<br>\n");
		hilite_fields(out, ret, 1);
		if (verbose) {
		    out.print("<textarea cols=80 rows=20>");
		    out.print(ret);
		    out.print("</textarea>\n");
		}
	    }
	}

	// Multidiscovery and call

	if (qs.equals("multi") || qs.equals("all")) {
	    out.print("<h4>Multidiscovery and Call</h4>\n");
	    
	    zxid_epr epr[] = new zxid_epr[100];
	    
	    for (int i=1; i<100; ++i) {
		epr[i] = zxidjni.get_epr(cf, zxses, "urn:x-foobar", null, null, null, i);
		if (epr[i] == null)
		    break;
		out.print("<p>EPR "+i+" address("+zxidjni.get_epr_address(cf, epr[i])+")\n");
		out.print("<p>EPR "+i+"   entid("+zxidjni.get_epr_entid(cf, epr[i])+")\n");
		out.print("<p>EPR "+i+"    desc("+zxidjni.get_epr_desc(cf, epr[i])+")\n");
	    }
	    
	    for (int i=1; i<100; ++i) {
		if (epr[i] == null)
		    break;
		out.print("<p>Output from multicall "+i+" entid:<br>\n<textarea cols=80 rows=20>");
		ret = zxidjni.call(cf, zxses, "urn:x-foobar",
				   zxidjni.get_epr_entid(cf, epr[i]),
				   null,
				   "Resource=demo",
				   "<foobar>do i="+i+"</foobar>");
		ret = zxidjni.extract_body(cf, ret);
		out.print(ret);
		out.print("</textarea>\n");
		
		out.print("<p>Output from multicall "+i+" address:<br>\n<textarea cols=80 rows=20>");
		ret = zxidjni.call(cf, zxses, "urn:x-foobar",
				   zxidjni.get_epr_address(cf, epr[i]),
				   null,
				   "Resource=demo",
				   "<foobar>do i="+i+"</foobar>");
		ret = zxidjni.extract_body(cf, ret);
		out.print(ret);
		out.print("</textarea>\n");
	    }
	}

	if (qs.equals("exit")) {
	    System.err.print("Controlled exit forced (can be used to cause __gcov_flush())\n");
	    zxidjni.set_opt(cf, 5, 0);
	}

	out.print("<p>Done.\n");
	System.err.print("^^^^^^^^^ DONE App-Demo GET("+fullURL+").\n");
    }

    public void hilite_fields(ServletOutputStream out, String ret, int n)
	throws IOException
    {
	int i;
	try {
	    Matcher matcher = idpnid_pat.matcher(ret);
	    for (i = n; i > 0; --i)
		matcher.find();
	    out.print("<b>fedusername</b>: " + matcher.group(1) + "<br>\n");
	} catch(IllegalStateException e) { }

	try {
	    Matcher matcher = idpnid_pat.matcher(ret);
	    for (i = n; i > 0; --i)
		matcher.find();
	    out.print("<b>idpnid</b>: " + matcher.group(1) + "<br>\n");
	} catch(IllegalStateException e) { }

	try {
	    Matcher matcher2 = nidfmt_pat.matcher(ret);
	    for (i = n; i > 0; --i)
		matcher2.find();
	    out.print("<b>nidfmt</b>: " + matcher2.group(1) + "<br>\n");
	} catch(IllegalStateException e) { }

	try {
	    Matcher matcher3 = affid_pat.matcher(ret);
	    for (i = n; i > 0; --i)
		matcher3.find();
	    out.print("<b>affid</b>: " + matcher3.group(1) + "<br>\n");
	} catch(IllegalStateException e) { }

	try {
	    Matcher matcher = eid_pat.matcher(ret);
	    for (i = n; i > 0; --i)
		matcher.find();
	    out.print("<b>eid</b>: " + matcher.group(1) + "<br>\n");
	} catch(IllegalStateException e) { }

	try {
	    Matcher matcher = cn_pat.matcher(ret);
	    for (i = n; i > 0; --i)
		matcher.find();
	    out.print("<b>cn</b>: " + matcher.group(1) + "<br>\n");
	} catch(IllegalStateException e) { }

	try {
	    Matcher matcher = o_pat.matcher(ret);
	    for (i = n; i > 0; --i)
		matcher.find();
	    out.print("<b>o</b>: " + matcher.group(1) + "<br>\n");
	} catch(IllegalStateException e) { }

	try {
	    Matcher matcher = ou_pat.matcher(ret);
	    for (i = n; i > 0; --i)
		matcher.find();
	    out.print("<b>ou</b>: " + matcher.group(1) + "<br>\n");
	} catch(IllegalStateException e) { }

	try {
	    Matcher matcher = role_pat.matcher(ret);
	    for (i = n; i > 0; --i)
		matcher.find();
	    out.print("<b>role</b>: " + matcher.group(1) + "<br>\n");
	} catch(IllegalStateException e) { }

	try {
	    Matcher matcher = boot_pat.matcher(ret);
	    for (i = n; i > 0; --i)
		matcher.find();
	    out.print("<b>urn:liberty:disco:2006-08:DiscoveryEPR</b>: " + matcher.group(1) + "<br>\n");
	} catch(IllegalStateException e) { }

    }

}

/* EOF */
