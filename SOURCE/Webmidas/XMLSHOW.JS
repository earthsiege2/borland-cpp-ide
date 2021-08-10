var xmlshow_vers="1.0";

function ShowXML(doc)
{
   var w = window.open("","","resizable,scrollbars,width=800,height=600");
   w.title = "XML Datapacket";
   w.document.open();
   w.document.write("<STYLE>");
   w.document.write("  .xml	    {font-size:12pt}"); 
   w.document.write("  .tagName	    {font-size:13pt; color:red;font-weight:bold;}");
   w.document.write("  .attrName	{color:black; font-weight:bold; }");
   w.document.write("  .attrValue	{color:darkgreen; font-weight:bold; }");
   w.document.write("  .text	{color:blue; font-weight:bold; }");
   w.document.write("  .comment	{color:green; font-weight:bold; }");
   w.document.write("</STYLE>");
   var xml = DumpTree(doc,0);
   w.document.write(xml);
   w.document.close();
}

function DumpTree(node,i)
{
  var result = "<DL class=xml><DD>";
  if (node.nodeType == 8)//Comment 
  {
     result += "<span class=comment>&lt;!--" + node.nodeValue + "--&gt;</span>";
     result += "</DD></DL>"
     return result;
  }
  var childCnt= node.childNodes.length;
  var empty = "";
  var tagname = node.tagName;
  if (childCnt == 0) empty = "/";
  result += "<span class=tagName>&lt;" + tagname + "</span>";

//This part is specific for xmldom.js
  if (node.attributes!=null)// && node.attributes.length)
  {
if (node.ownerDocument.borland!=null)
{
 
 node.getAttribute("x");//to force it to be parsed
 var attrs=node.attributes;
 var a;
 for (var a in attrs)
 {
   var v=attrs[a];
   if (v!=null)
   {
    result += " <span class=attrName>" + a + "</span>=<span class=attrValue>\"";
    result +=  FrText(v);
    result += "\"</span>\n";
   }
 }
}
else
{
  var k;
 
  for (k=0; k < node.attributes.length; k++ )
  {
    var a = node.attributes.item(k);
    result += " <span class=attrName>" + a.name + "</span>=<span class=attrValue>\"";
    result +=  a.value;
    result += "\"</span>\n";
    //if (node.attributes.length >1)
    //   result += "\n";
  }
 // if (k) result +="\n";
}
}
  result += "<span class=tagName>" + empty + "&gt;</span>";
  if (childCnt > 0)
  {
    if (childCnt == 1 && node.childNodes.item(0).nodeType == 3)
    {
       result += "<span class=text>";
       result += FrText(node.childNodes.item(0).data);
       result += "</span>"
    }
    else
    {
      var j;
      for (j = 0; j < childCnt; j++)
      {
         result += "\n";
         var child = node.childNodes.item(j);
         result += DumpTree(child,1);
      }
    }
    //EndTag
    result +=  "<span class=tagName>&lt;/" + tagname + "&gt;</span>\n";
  }
  result += "</DD></DL>"
  return result;
}
