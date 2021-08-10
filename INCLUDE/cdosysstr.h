#ifndef __cdostr_h_
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#define __cdostr_h_
//	__CdoCalendar_MODULE_DEFINED__
#define cdoTimeZoneIDURN	L"urn:schemas:calendar:timezoneid"

//	__CdoCharset_MODULE_DEFINED__
#define cdoBIG5	L"big5"
#define cdoEUC_JP	L"euc-jp"
#define cdoEUC_KR	L"euc-kr"
#define cdoGB2312	L"gb2312"
#define cdoISO_2022_JP	L"iso-2022-jp"
#define cdoISO_2022_KR	L"iso-2022-kr"
#define cdoISO_8859_1	L"iso-8859-1"
#define cdoISO_8859_2	L"iso-8859-2"
#define cdoISO_8859_3	L"iso-8859-3"
#define cdoISO_8859_4	L"iso-8859-4"
#define cdoISO_8859_5	L"iso-8859-5"
#define cdoISO_8859_6	L"iso-8859-6"
#define cdoISO_8859_7	L"iso-8859-7"
#define cdoISO_8859_8	L"iso-8859-8"
#define cdoISO_8859_9	L"iso-8859-9"
#define cdoKOI8_R	L"koi8-r"
#define cdoShift_JIS	L"shift-jis"
#define cdoUS_ASCII	L"us-ascii"
#define cdoUTF_7	L"utf-7"
#define cdoUTF_8	L"utf-8"

//	__CdoConfiguration_MODULE_DEFINED__
#define cdoAutoPromoteBodyParts	L"http://schemas.microsoft.com/cdo/configuration/autopromotebodyparts"
#define cdoFlushBuffersOnWrite	L"http://schemas.microsoft.com/cdo/configuration/flushbuffersonwrite"
#define cdoHTTPCookies	L"http://schemas.microsoft.com/cdo/configuration/httpcookies"
#define cdoLanguageCode	L"http://schemas.microsoft.com/cdo/configuration/languagecode"
#define cdoNNTPAccountName	L"http://schemas.microsoft.com/cdo/configuration/nntpaccountname"
#define cdoNNTPAuthenticate	L"http://schemas.microsoft.com/cdo/configuration/nntpauthenticate"
#define cdoNNTPConnectionTimeout	L"http://schemas.microsoft.com/cdo/configuration/nntpconnectiontimeout"
#define cdoNNTPServer	L"http://schemas.microsoft.com/cdo/configuration/nntpserver"
#define cdoNNTPServerPickupDirectory	L"http://schemas.microsoft.com/cdo/configuration/nntpserverpickupdirectory"
#define cdoNNTPServerPort	L"http://schemas.microsoft.com/cdo/configuration/nntpserverport"
#define cdoNNTPUseSSL	L"http://schemas.microsoft.com/cdo/configuration/nntpusessl"
#define cdoPostEmailAddress	L"http://schemas.microsoft.com/cdo/configuration/postemailaddress"
#define cdoPostPassword	L"http://schemas.microsoft.com/cdo/configuration/postpassword"
#define cdoPostUserName	L"http://schemas.microsoft.com/cdo/configuration/postusername"
#define cdoPostUserReplyEmailAddress	L"http://schemas.microsoft.com/cdo/configuration/postuserreplyemailaddress"
#define cdoPostUsingMethod	L"http://schemas.microsoft.com/cdo/configuration/postusing"
#define cdoSaveSentItems	L"http://schemas.microsoft.com/cdo/configuration/savesentitems"
#define cdoSendEmailAddress	L"http://schemas.microsoft.com/cdo/configuration/sendemailaddress"
#define cdoSendPassword	L"http://schemas.microsoft.com/cdo/configuration/sendpassword"
#define cdoSendUserName	L"http://schemas.microsoft.com/cdo/configuration/sendusername"
#define cdoSendUserReplyEmailAddress	L"http://schemas.microsoft.com/cdo/configuration/senduserreplyemailaddress"
#define cdoSendUsingMethod	L"http://schemas.microsoft.com/cdo/configuration/sendusing"
#define cdoSMTPAccountName	L"http://schemas.microsoft.com/cdo/configuration/smtpaccountname"
#define cdoSMTPAuthenticate	L"http://schemas.microsoft.com/cdo/configuration/smtpauthenticate"
#define cdoSMTPConnectionTimeout	L"http://schemas.microsoft.com/cdo/configuration/smtpconnectiontimeout"
#define cdoSMTPServer	L"http://schemas.microsoft.com/cdo/configuration/smtpserver"
#define cdoSMTPServerPickupDirectory	L"http://schemas.microsoft.com/cdo/configuration/smtpserverpickupdirectory"
#define cdoSMTPServerPort	L"http://schemas.microsoft.com/cdo/configuration/smtpserverport"
#define cdoSMTPUseSSL	L"http://schemas.microsoft.com/cdo/configuration/smtpusessl"
#define cdoURLGetLatestVersion	L"http://schemas.microsoft.com/cdo/configuration/urlgetlatestversion"
#define cdoURLProxyBypass	L"http://schemas.microsoft.com/cdo/configuration/urlproxybypass"
#define cdoURLProxyServer	L"http://schemas.microsoft.com/cdo/configuration/urlproxyserver"
#define cdoUseMessageResponseText	L"http://schemas.microsoft.com/cdo/configuration/usemessageresponsetext"

//	__CdoContentTypeValues_MODULE_DEFINED__
#define cdoGif	L"image/gif"
#define cdoJpeg	L"image/jpeg"
#define cdoMessageExternalBody	L"message/external-body"
#define cdoMessagePartial	L"message/partial"
#define cdoMessageRFC822	L"message/rfc822"
#define cdoMultipartAlternative	L"multipart/alternative"
#define cdoMultipartDigest	L"multipart/digest"
#define cdoMultipartMixed	L"multipart/mixed"
#define cdoMultipartRelated	L"multipart/related"
#define cdoTextHTML	L"text/html"
#define cdoTextPlain	L"text/plain"

//	__CdoDAV_MODULE_DEFINED__
#define cdoContentClass	L"DAV:contentclass"
#define cdoGetContentType	L"DAV:getcontenttype"

//	__CdoEncodingType_MODULE_DEFINED__
#define cdo7bit	L"7bit"
#define cdo8bit	L"8bit"
#define cdoBase64	L"base64"
#define cdoBinary	L"binary"
#define cdoMacBinHex40	L"mac-binhex40"
#define cdoQuotedPrintable	L"quoted-printable"
#define cdoUuencode	L"uuencode"

//	__CdoExchange_MODULE_DEFINED__
#define cdoSensitivity	L"http://schemas.microsoft.com/exchange/sensitivity"

//	__CdoHTTPMail_MODULE_DEFINED__
#define cdoAttachmentFilename	L"urn:schemas:httpmail:attachmentfilename"
#define cdoBcc	L"urn:schemas:httpmail:bcc"
#define cdoCc	L"urn:schemas:httpmail:cc"
#define cdoContentDispositionType	L"urn:schemas:httpmail:content-disposition-type"
#define cdoContentMediaType	L"urn:schemas:httpmail:content-media-type"
#define cdoDate	L"urn:schemas:httpmail:date"
#define cdoDateReceived	L"urn:schemas:httpmail:datereceived"
#define cdoFrom	L"urn:schemas:httpmail:from"
#define cdoHasAttachment	L"urn:schemas:httpmail:hasattachment"
#define cdoHTMLDescription	L"urn:schemas:httpmail:htmldescription"
#define cdoImportance	L"urn:schemas:httpmail:importance"
#define cdoNormalizedSubject	L"urn:schemas:httpmail:normalizedsubject"
#define cdoPriority	L"urn:schemas:httpmail:priority"
#define cdoReplyTo	L"urn:schemas:httpmail:reply-to"
#define cdoSender	L"urn:schemas:httpmail:sender"
#define cdoSubject	L"urn:schemas:httpmail:subject"
#define cdoTextDescription	L"urn:schemas:httpmail:textdescription"
#define cdoThreadTopic	L"urn:schemas:httpmail:thread-topic"
#define cdoTo	L"urn:schemas:httpmail:to"

//	__CdoInterfaces_MODULE_DEFINED__
#define cdoAdoStream	L"_Stream"
#define cdoIBodyPart	L"IBodyPart"
#define cdoIConfiguration	L"IConfiguration"
#define cdoIDataSource	L"IDataSource"
#define cdoIMessage	L"IMessage"
#define cdoIStream	L"IStream"

//	__CdoMailHeader_MODULE_DEFINED__
#define cdoApproved	L"urn:schemas:mailheader:approved"
#define cdoComment	L"urn:schemas:mailheader:comment"
#define cdoContentBase	L"urn:schemas:mailheader:content-base"
#define cdoContentDescription	L"urn:schemas:mailheader:content-description"
#define cdoContentDisposition	L"urn:schemas:mailheader:content-disposition"
#define cdoContentId	L"urn:schemas:mailheader:content-id"
#define cdoContentLanguage	L"urn:schemas:mailheader:content-language"
#define cdoContentLocation	L"urn:schemas:mailheader:content-location"
#define cdoContentTransferEncoding	L"urn:schemas:mailheader:content-transfer-encoding"
#define cdoContentType	L"urn:schemas:mailheader:content-type"
#define cdoControl	L"urn:schemas:mailheader:control"
#define cdoDisposition	L"urn:schemas:mailheader:disposition"
#define cdoDispositionNotificationTo	L"urn:schemas:mailheader:disposition-notification-to"
#define cdoDistribution	L"urn:schemas:mailheader:distribution"
#define cdoExpires	L"urn:schemas:mailheader:expires"
#define cdoFollowupTo	L"urn:schemas:mailheader:followup-to"
#define cdoInReplyTo	L"urn:schemas:mailheader:in-reply-to"
#define cdoLines	L"urn:schemas:mailheader:lines"
#define cdoMessageId	L"urn:schemas:mailheader:message-id"
#define cdoMIMEVersion	L"urn:schemas:mailheader:mime-version"
#define cdoNewsgroups	L"urn:schemas:mailheader:newsgroups"
#define cdoOrganization	L"urn:schemas:mailheader:organization"
#define cdoOriginalRecipient	L"urn:schemas:mailheader:original-recipient"
#define cdoPath	L"urn:schemas:mailheader:path"
#define cdoPostingVersion	L"urn:schemas:mailheader:posting-version"
#define cdoReceived	L"urn:schemas:mailheader:received"
#define cdoReferences	L"urn:schemas:mailheader:references"
#define cdoRelayVersion	L"urn:schemas:mailheader:relay-version"
#define cdoReturnPath	L"urn:schemas:mailheader:return-path"
#define cdoReturnReceiptTo	L"urn:schemas:mailheader:return-receipt-to"
#define cdoSummary	L"urn:schemas:mailheader:summary"
#define cdoThreadIndex	L"urn:schemas:mailheader:thread-index"
#define cdoXMailer	L"urn:schemas:mailheader:x-mailer"
#define cdoXref	L"urn:schemas:mailheader:xref"
#define cdoXUnsent	L"urn:schemas:mailheader:x-unsent"

//	__CdoNamespace_MODULE_DEFINED__
#define cdoNSConfiguration	L"http://schemas.microsoft.com/cdo/configuration/"
#define cdoNSContacts	L"urn:schemas:contacts:"
#define cdoNSHTTPMail	L"urn:schemas:httpmail:"
#define cdoNSMailHeader	L"urn:schemas:mailheader:"
#define cdoNSNNTPEnvelope	L"http://schemas.microsoft.com/cdo/nntpenvelope/"
#define cdoNSSMTPEnvelope	L"http://schemas.microsoft.com/cdo/smtpenvelope/"

//	__CdoNNTPEnvelope_MODULE_DEFINED__
#define cdoNewsgroupList	L"http://schemas.microsoft.com/cdo/nntpenvelope/newsgrouplist"
#define cdoNNTPProcessing	L"http://schemas.microsoft.com/cdo/nntpenvelope/nntpprocessing"

//	__CdoOffice_MODULE_DEFINED__
#define cdoKeywords	L"urn:schemas-microsoft-com:office:office#Keywords"

//	__CdoSMTPEnvelope_MODULE_DEFINED__
#define cdoArrivalTime	L"http://schemas.microsoft.com/cdo/smtpenvelope/arrivaltime"
#define cdoClientIPAddress	L"http://schemas.microsoft.com/cdo/smtpenvelope/clientipaddress"
#define cdoMessageStatus	L"http://schemas.microsoft.com/cdo/smtpenvelope/messagestatus"
#define cdoPickupFileName	L"http://schemas.microsoft.com/cdo/smtpenvelope/pickupfilename"
#define cdoRecipientList	L"http://schemas.microsoft.com/cdo/smtpenvelope/recipientlist"
#define cdoSenderEmailAddress	L"http://schemas.microsoft.com/cdo/smtpenvelope/senderemailaddress"

//	__CdoErrors_MODULE_DEFINED__


#pragma option pop /*P_O_Pop*/
#endif // __cdostr_h_
