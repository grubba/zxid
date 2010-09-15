#!/usr/bin/perl
# 15.9.2010, Sampo Kellomaki (sampo@zxid.org)
#
# Very simple mock PDP to be run as CGI script

print <<SOAP;
Content-type: text/plain

<e:Envelope xmlns:e="http://schemas.xmlsoap.org/soap/envelope/">
<e:Header></e:Header>
<e:Body>
<sp:Response xmlns:sp="urn:oasis:names:tc:SAML:2.0:protocol" ID="R3yhGlzrJ_DCeoYj_apS773FQ" IssueInstant="2009-12-19T11:33:55Z" Version="2.0">
<sa:Issuer xmlns:sa="urn:oasis:names:tc:SAML:2.0:assertion">http://idp.tas3.pt:8081/zxididp?o=B</sa:Issuer>

<sp:Status>
<sp:StatusCode Value="urn:oasis:names:tc:SAML:2.0:status:Success"></sp:StatusCode>
</sp:Status>

<sa:Assertion xmlns:sa="urn:oasis:names:tc:SAML:2.0:assertion" ID="A1aRci5gH7kAiQB9xFFRhwwhf" IssueInstant="2009-12-19T11:33:55Z" Version="2.0">
<sa:Issuer>http://idp.tas3.pt:8081/zxididp?o=B</sa:Issuer>
<sa:Conditions NotBefore="2009-12-19T11:33:55Z" NotOnOrAfter="2009-12-19T12:33:55Z"></sa:Conditions>
<xasa:XACMLAuthzDecisionStatement xmlns:xasa="urn:oasis:xacml:2.0:saml:assertion:schema:os">
<xac:Response xmlns:xac="urn:oasis:names:tc:xacml:2.0:context:schema:os">
<xac:Result>
<xac:Decision>Permit</xac:Decision>
<xac:Status>
<xac:StatusCode Value="urn:oasis:names:tc:xacml:1.0:status:ok"></xac:StatusCode>
</xac:Status>
</xac:Result>
</xac:Response>
</xasa:XACMLAuthzDecisionStatement>
</sa:Assertion>

</sp:Response>
</e:Body>
</e:Envelope>
SOAP
    ;

__END__

Example (azrq1):

<e:Envelope xmlns:e="http://schemas.xmlsoap.org/soap/envelope/"><e:Body><xasp:XACMLAuthzDecisionQuery xmlns:xasp="urn:oasis:xacml:2.0:saml:protocol:schema:os" ID="RmQtc_SvgPVYANCPrELYfjl59" IssueInstant="2009-12-19T11:33:54Z" Version="2.0"><sa:Issuer xmlns:sa="urn:oasis:names:tc:SAML:2.0:assertion">http://sp.tas3.pt:8080/zxidservlet/sso?o=B</sa:Issuer><ds:Signature xmlns:ds="http://www.w3.org/2000/09/xmldsig#"><ds:SignedInfo><ds:CanonicalizationMethod Algorithm="http://www.w3.org/2001/10/xml-exc-c14n#"></ds:CanonicalizationMethod><ds:SignatureMethod Algorithm="http://www.w3.org/2000/09/xmldsig#rsa-sha1"></ds:SignatureMethod><ds:Reference URI="#RmQtc_SvgPVYANCPrELYfjl59"><ds:Transforms><ds:Transform Algorithm="http://www.w3.org/2000/09/xmldsig#enveloped-signature"></ds:Transform><ds:Transform Algorithm="http://www.w3.org/2001/10/xml-exc-c14n#"></ds:Transform></ds:Transforms><ds:DigestMethod Algorithm="http://www.w3.org/2000/09/xmldsig#sha1"></ds:DigestMethod><ds:DigestValue>60AyrnQBTal1wgUkU80gWWUAB4Y=</ds:DigestValue></ds:Reference></ds:SignedInfo><ds:SignatureValue>QbXbs9WLovuE0Ft15GRK5n8t9iohQzgPUarSQklRIcvCDFafdewEZTGGYLsprZtarBMUTthmu7iVmxwV+iaW3ZoS5FmgoCta5hakMEIVxC8wAhF6JYi3hY3mYlwc86apYGKh/525KTNIbKXrA5nnQUNX6ORyXK3Vu09qyzMnOTE=</ds:SignatureValue></ds:Signature><xac:Request xmlns:xac="urn:oasis:names:tc:xacml:2.0:context:schema:os"><xac:Subject></xac:Subject><xac:Resource></xac:Resource><xac:Action><xac:Attribute AttributeId="urn:oasis:names:tc:xacml:1.0:action:action-id" DataType="http://www.w3.org/2001/XMLSchema#string"><xac:AttributeValue>Show</xac:AttributeValue></xac:Attribute></xac:Action><xac:Environment></xac:Environment></xac:Request></xasp:XACMLAuthzDecisionQuery></e:Body></e:Envelope>

Example (azrs1):

<e:Envelope xmlns:e="http://schemas.xmlsoap.org/soap/envelope/">
<e:Header></e:Header>
<e:Body>
<sp:Response xmlns:sp="urn:oasis:names:tc:SAML:2.0:protocol" ID="R3yhGlzrJ_DCeoYj_apS773FQ" IssueInstant="2009-12-19T11:33:55Z" Version="2.0">
<sa:Issuer xmlns:sa="urn:oasis:names:tc:SAML:2.0:assertion">http://idp.tas3.pt:8081/zxididp?o=B</sa:Issuer>
<ds:Signature xmlns:ds="http://www.w3.org/2000/09/xmldsig#">
<ds:SignedInfo>
<ds:CanonicalizationMethod Algorithm="http://www.w3.org/2001/10/xml-exc-c14n#"></ds:CanonicalizationMethod>
<ds:SignatureMethod Algorithm="http://www.w3.org/2000/09/xmldsig#rsa-sha1"></ds:SignatureMethod>
<ds:Reference URI="#R3yhGlzrJ_DCeoYj_apS773FQ">
<ds:Transforms>
<ds:Transform Algorithm="http://www.w3.org/2000/09/xmldsig#enveloped-signature"></ds:Transform>
<ds:Transform Algorithm="http://www.w3.org/2001/10/xml-exc-c14n#"></ds:Transform>
</ds:Transforms>
<ds:DigestMethod Algorithm="http://www.w3.org/2000/09/xmldsig#sha1"></ds:DigestMethod>
<ds:DigestValue>B+Mu8P4wXvV8EjW64gzpMN2vFio=</ds:DigestValue>
</ds:Reference>
</ds:SignedInfo>
<ds:SignatureValue>iZJxULLrSbdVmcRg5cqwBfNDs0bpWkRNYyJqFsfeq9TB3styJW2YpdajbFX/GF996ERN1RiQam7T+mkGaa10eBCRaPrf4RWdEPgk6toiwjObWxQxLoN1VPbiOoaeCXKqkYklC25cwnVzmp9PzE4cNvOpowWHc/px+JN4P7OxVpw=</ds:SignatureValue>
</ds:Signature>
<sp:Status>
<sp:StatusCode Value="urn:oasis:names:tc:SAML:2.0:status:Success"></sp:StatusCode>
</sp:Status>

<sa:Assertion xmlns:sa="urn:oasis:names:tc:SAML:2.0:assertion" ID="A1aRci5gH7kAiQB9xFFRhwwhf" IssueInstant="2009-12-19T11:33:55Z" Version="2.0">
<sa:Issuer>http://idp.tas3.pt:8081/zxididp?o=B</sa:Issuer>
<sa:Conditions NotBefore="2009-12-19T11:33:55Z" NotOnOrAfter="2009-12-19T12:33:55Z"></sa:Conditions>
<xasa:XACMLAuthzDecisionStatement xmlns:xasa="urn:oasis:xacml:2.0:saml:assertion:schema:os">
<xac:Response xmlns:xac="urn:oasis:names:tc:xacml:2.0:context:schema:os">
<xac:Result>
<xac:Decision>Permit</xac:Decision>
<xac:Status>
<xac:StatusCode Value="urn:oasis:names:tc:xacml:1.0:status:ok"></xac:StatusCode>
</xac:Status>
</xac:Result>
</xac:Response>
</xasa:XACMLAuthzDecisionStatement>
</sa:Assertion>

</sp:Response>
</e:Body>
</e:Envelope>


<e:Envelope xmlns:e="http://schemas.xmlsoap.org/soap/envelope/"><e:Header></e:Header><e:Body><sp:Response xmlns:sp="urn:oasis:names:tc:SAML:2.0:protocol" ID="R3yhGlzrJ_DCeoYj_apS773FQ" IssueInstant="2009-12-19T11:33:55Z" Version="2.0"><sa:Issuer xmlns:sa="urn:oasis:names:tc:SAML:2.0:assertion">http://idp.tas3.pt:8081/zxididp?o=B</sa:Issuer><ds:Signature xmlns:ds="http://www.w3.org/2000/09/xmldsig#"><ds:SignedInfo><ds:CanonicalizationMethod Algorithm="http://www.w3.org/2001/10/xml-exc-c14n#"></ds:CanonicalizationMethod><ds:SignatureMethod Algorithm="http://www.w3.org/2000/09/xmldsig#rsa-sha1"></ds:SignatureMethod><ds:Reference URI="#R3yhGlzrJ_DCeoYj_apS773FQ"><ds:Transforms><ds:Transform Algorithm="http://www.w3.org/2000/09/xmldsig#enveloped-signature"></ds:Transform><ds:Transform Algorithm="http://www.w3.org/2001/10/xml-exc-c14n#"></ds:Transform></ds:Transforms><ds:DigestMethod Algorithm="http://www.w3.org/2000/09/xmldsig#sha1"></ds:DigestMethod><ds:DigestValue>B+Mu8P4wXvV8EjW64gzpMN2vFio=</ds:DigestValue></ds:Reference></ds:SignedInfo><ds:SignatureValue>iZJxULLrSbdVmcRg5cqwBfNDs0bpWkRNYyJqFsfeq9TB3styJW2YpdajbFX/GF996ERN1RiQam7T+mkGaa10eBCRaPrf4RWdEPgk6toiwjObWxQxLoN1VPbiOoaeCXKqkYklC25cwnVzmp9PzE4cNvOpowWHc/px+JN4P7OxVpw=</ds:SignatureValue></ds:Signature><sp:Status><sp:StatusCode Value="urn:oasis:names:tc:SAML:2.0:status:Success"></sp:StatusCode></sp:Status><sa:Assertion xmlns:sa="urn:oasis:names:tc:SAML:2.0:assertion" ID="A1aRci5gH7kAiQB9xFFRhwwhf" IssueInstant="2009-12-19T11:33:55Z" Version="2.0"><sa:Issuer>http://idp.tas3.pt:8081/zxididp?o=B</sa:Issuer><sa:Conditions NotBefore="2009-12-19T11:33:55Z" NotOnOrAfter="2009-12-19T12:33:55Z"></sa:Conditions><xasa:XACMLAuthzDecisionStatement xmlns:xasa="urn:oasis:xacml:2.0:saml:assertion:schema:os"><xac:Response xmlns:xac="urn:oasis:names:tc:xacml:2.0:context:schema:os"><xac:Result><xac:Decision>Permit</xac:Decision><xac:Status><xac:StatusCode Value="urn:oasis:names:tc:xacml:1.0:status:ok"></xac:StatusCode></xac:Status></xac:Result></xac:Response></xasa:XACMLAuthzDecisionStatement></sa:Assertion></sp:Response></e:Body></e:Envelope>

From	"Luk Vervenne" <luk@synergetics.be>
To	<John.power@risaris.com>, "Brian Reynolds" <Brian.Reynolds@risaris.com>, <sampo@synergetics.be>, <bjoern.mueller@captaincasa.com>
Cc	
Date	Wed, 15 Sep 2010 11:49:22 +0200 -- arrived: Ke 15.9. 9h47 -- 20.5K
Subject	roles - luk
As promised:



Roles

1. End-user

Owns PDS, full access + access control

2. Delegate

- Has been granted delegated access-control vis à vis third
  parties, mostly service providers.

- User still keeps full access himself

- Decides in his own right on access of third parties

- Use Case: PES, Public employment services, are granted
  "delegation control" over third sector related individuals by contract,
  since they are not capable of handling themselves and/or their data.

3. Personal coaches :

- Longer term advice and coaching to the individual using service contract

- Has longer term access rights to whole or parts of the portfolio

4. Service providers

- Are granted access through user policies in view of the one
  process the user engages in with the SP

- Enriched data (from the SP, post-process) go back in to PDS, but
  often only in so far they are relevant and/or reusable.

- Policies also define data retention


I will now setup storyboards


Luk Vervenne
CEO





Can I just add some notes for this meeting to ensure we all have an
understanding:

- Luk to provide a list of roles (Done below).

- Bjoern to develop \u2018Policy Editor\u2019 with TAS3 like look and feel
enabling the update of the xml properties file. We will refer to \u2018roles\u2019 in
this application and not users (though internally these are dealt with as
users).

- Bjoern to deliver existing project with policy editor to Brian.

- Brian/Sampo to modify to integrate the zXID sign on (priority 1 )

- Ensure that the modification of the properties is reflected in
the CC application (priority 2).

- Can we also use this for the authorisation for the SOA Gateway so
that we can show a different policy there ? (Priority 3).

- Implement a pseudo PDP in PHP and call this from the CC
authenticate service so show a more accurate TAS3 structure (Priority 4).

- Luk to deliver a story board for the demo.

Does this make sense or have I missed something ?

Best regards,
John 
