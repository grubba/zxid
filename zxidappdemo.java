/* zxidappdemo.java  -  Demonstrate detecting missing session and redirection to zxidsrvlet
 * Copyright (c) 2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidappdemo.java,v 1.4 2009-11-29 12:23:06 sampo Exp $
 * 16.10.2009, created --Sampo
 *
 * This servlet plays the role of "payload" servlet in ZXID SSO servlet
 * integration demonstration. It illustrates the steps
 * 1.  Detect that there is no session and redirect to zxidsrvlet; and
 * 7.  Access to protected resource, with attributes already populated
 *     to the HttpSession (JSESSION)
 * 9.  Making a web service call by directly calling zxid_call()
 *
 * See also: zxid-java.pd, zxidwspdemo.java for server side
 */

import zxidjava.*;   // Pull in the zxidjni.az() API
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class zxidappdemo extends HttpServlet {
    static final String conf = "URL=http://sp1.zxidsp.org:8080/sso&PATH=/var/zxid/";
    static zxidjava.zxid_conf cf;
    static {
	// CONFIG: You must have created /var/zxid directory hierarchy. See `make dir'
	// CONFIG: You must create edit the URL to match your domain name and port
	System.loadLibrary("zxidjni");
	cf = zxidjni.new_conf_to_cf(conf);
	zxidjni.set_opt(cf, 1, 1);
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
	System.err.print("Start ZXID App Demo GET("+fullURL+")...\n");
	HttpSession ses = req.getSession(false);  // Important: do not allow automatic session.
	if (ses == null) {                        // Instead, redirect to sso servlet.
	    res.sendRedirect("sso?o=E&fr=" + fullURL);
	    return;
	}
	ServletOutputStream out = res.getOutputStream();
	
	res.setContentType("text/html");
	out.print("<title>ZXID Demo App Protected Content</title><body>\n");
	out.print("<table align=right><tr><td>");
	out.print("<a href=\"http://www.tas3.eu/\"><img src=\"tas3-logo.jpg\" height=64 border=0></a>");
	out.print("<a href=\"http://zxid.org/\"><img src=\"logo-zxid-128x128.png\" height=64 border=0></a>");
	out.print("</td></tr></table>");
	out.print("<h1>ZXID Demo App Protected Content</h1> at " + fullURL + "\n");

	// Render logout buttons (optional)

	out.print("[<a href=\"sso?gl=1&s="+ses.getValue("sesid")+"\">Local Logout</a> | <a href=\"sso?gr=1&s="+ses.getValue("sesid")+"\">Single Logout</a>]\n");

	// The SSO servlet will have done one iteration of authorization. The following
	// serves to illustrate, how to explicitly call a PDP from your code.

	if (zxidjni.az_cf(cf, "Action=Show", ses.getValue("sesid").toString()) == null) {
	    out.print("<p><b>Denied.</b> Normally page would not be shown, but we show the session attributes for debugging purposes.\n");
	    //res.setStatus(302, "Denied");
	} else {
	    out.print("<p>Authorized.\n");
	}

	out.print("<table align=right><tr><td>");
	out.print("<img src=\"tas3-recurs-demo.png\" border=0>");
	out.print("</td></tr></table>");

	// Render protected content page (your application starts working)

	out.print("<pre>HttpSession dump:\n");
	String[] val_names = ses.getValueNames();
	for (int i = 0; i < val_names.length; ++i) {
	    out.print(val_names[i] + ": " + ses.getValue(val_names[i]) + "\n");
	}
	out.print("</pre><p>");
	out.print("[ <a href=\"?idhrxml\">tas3_call(idhrxml)</a>");
	out.print("| <a href=\"?x-foobar\">Recursive</a>");
	out.print("| <a href=\"?leaf\">Leaf</a>");
	out.print("| <a href=\"?multi\">Multi discovery and call</a>");
	out.print("| <a href=\"?all\">All</a>");
	out.print("]<p>");

	// Demo web service call to zxidhrxmlwsp

	String ret;
	String sid = ses.getValue("sesid").toString();
	zxid_ses zxses = zxidjni.fetch_ses(cf, sid);
	
	if (qs.equals("idhrxml") || qs.equals("all")) {
	    out.print("<p>Output from idhrxml web service call sid("+sid+"):<br>\n<textarea cols=80 rows=20>");
	    ret = zxidjni.call(cf, zxidjni.fetch_ses(cf, sid),
			       zxidjni.zx_xmlns_idhrxml, "http://sp.tas3.pt:8081/zxidhrxmlwsp?o=B", null, null,
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
	    out.print("<p>Output from foobar web service call:<br>\n<textarea cols=80 rows=20>");
	    ret = zxidjni.call(cf, zxses, "urn:x-foobar", "http://sp.tas3.pt:8080/zxidservlet/wspdemo?o=B", null, null,
			       "<foobar>Do it!</foobar>");
	    
	    ret = zxidjni.extract_body(cf, ret);
	    out.print(ret);
	    out.print("</textarea>");
	}
	
	// Demo another web service call, this time the service by zxidwspdemo.java

	if (qs.equals("leaf") || qs.equals("all")) {
	    out.print("<p>Output from Leaf web service call:<br>\n<textarea cols=80 rows=20>");
	    ret = zxidjni.call(cf, zxses, "x-recurs", null, null, null,
			       "<foobar>Do it!</foobar>");
	    
	    ret = zxidjni.extract_body(cf, ret);
	    out.print(ret);
	    out.print("</textarea>");
	}
	
	// Multidiscovery and call

	if (qs.equals("multi") || qs.equals("all")) {
	    out.print("<h4>Multidiscovery</h4>\n");
	    
	    SWIGTYPE_p_zx_a_EndpointReference_s epr[] = new SWIGTYPE_p_zx_a_EndpointReference_s[100];
	    
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
		ret = zxidjni.call(cf, zxses, "urn:x-foobar", zxidjni.get_epr_entid(cf, epr[i]), null, null,
				   "<foobar>do i="+i+"</foobar>");
		ret = zxidjni.extract_body(cf, ret);
		out.print(ret);
		out.print("</textarea>\n");
		
		out.print("<p>Output from multicall "+i+" address:<br>\n<textarea cols=80 rows=20>");
		ret = zxidjni.call(cf, zxses, "urn:x-foobar", zxidjni.get_epr_address(cf, epr[i]), null, null,
				   "<foobar>do i="+i+"</foobar>");
		ret = zxidjni.extract_body(cf, ret);
		out.print(ret);
		out.print("</textarea>\n");
	    }
	}
	out.print("<p>Done.\n");
    }
}

/* EOF */
