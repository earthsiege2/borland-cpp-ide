//Copyright Inprise Corporation 1999, all rights reserved, to be used with Borlands Midas-technology only, 
//unless special permission has been given.
var xmldom_vers="1.0";

function item(i) {return this[i];}
Array.prototype.item=item;

var ParseErr=0;

function Document(str)
{
this.borland=1;
this.nodeType=9;
this.parentNode=null;
this.ownerDocument=this;
this.childNodes=new Array();
this.attributes=new Array();
this.removeChild=removeChild;
this.appendChild=appendChild;
this.cloneNode=cloneNode;

this.doctype=null;
this.documentElement=null;
this.createElement=createElement;
this.createDocumentFragment=createDocumentFragment;
this.createTextNode=createTextNode;
this.createComment=createComment;
this.createCDATASection=createCDATASection;
this.createProcessingInstruction=createProcessingInstruction;
this.createAttribute=createAttribute;
this.loadXML=loadXML;
if (str) {this.loadXML(str);if (ParseErr) return null;}
return this;
}

function createElement(n) {return new Element(this,n);}
function createDocumentFragment() {var df=new Element(this,"");df.nodeType=11;return df;}
function createTextNode(v) {return new CharData(this,v);}
function createComment(d) {var co=new CharData(this,d);co.nodeType=8;return co;}
function createCDATASection(v) {var dat=new CharData(this,v);dat.nodeType=4;return dat;}
function createProcessingInstruction(t,d) {var pro=new CharData(this,d);pro.nodeType=7;pro.target=t;return pro;}
 
function createAttribute(n) {return new Attr(n, 0);}

function loadXML(str)
{
ParseErr=0;
ReadDoc(this,str,this.childNodes);this.documentElement=this.childNodes[0];
}

function Element(doc,n)
{
this.tagName=n;
this.parentNode=null;
this.ownerDocument=doc;
this.childNodes=new Array();
}

new Element(null,0);
Element.prototype.nodeType=1;
Element.prototype.removeChild=removeChild;
Element.prototype.appendChild=appendChild;
Element.prototype.cloneNode=cloneNode;
Element.prototype.setAttribute=setAttribute;
Element.prototype.getAttribute=getAttribute;
Element.prototype.removeAttribute=function(n){this.setAttribute(n,null);}
Element.prototype.attributes=null;
Element.prototype.xmlstr=function(){return XmlStr(this,0,1);}
Element.prototype.parsed=0;

function CharData(doc,d)
{
this.parentNode=null;
this.ownerDocument=doc;
this.data=d;
}

new CharData(null,0);
CharData.prototype.nodeType=3;

function appendChild(p){this.childNodes[this.childNodes.length]=p;}
function removeChild(p)
{
var i,cnt;
cnt= this.childNodes.length;
for(i=0;i<cnt;i++)
 if(this.childNodes[i]==p)
 {
  var j;
  for(j=i+1;j<cnt;j++){this.childNodes[j-1]=this.childNodes[j];}
  this.childNodes[cnt-1]=null;
  this.childNodes.length=cnt-1;
  break;
 }
}

function cloneNode(deep)
{
var str=XmlStr(this,0,deep);
var a=new Array();
ReadDoc(this.ownerDocument,str,a);
return a[0];
}

function setAttribute(n,v)
{
if(this.attributes!=null&&this.parsed==0){this.attributes=ReadAttrs(this.attributes);this.parsed=1;}
else
if(this.attributes==null){this.attributes=new Array();this.attributes["item"]=null;this.parsed=1;}
this.attributes[n]=v; return;
}

 
function getAttribute(n)
{
if(this.attributes==null) return null;
if(this.parsed==0){this.attributes=ReadAttrs(this.attributes);this.parsed=1;}
return this.attributes[n];
}

function Attr(n,v) {this.name=n; this.value=v;}
 
function ReadDoc(d,str,c)
{
str=ReadHeader(d,str);
ReadNodes(d,str,null,c);
return ;
}

function ReadHeader(d,str)
{
var iBeg=str.indexOf("<");
if(str.substring(iBeg,iBeg+5)=="<?xml")
{
 var iEnd=str.indexOf("?>");
 str=str.substring(str.indexOf("<",iEnd+2),str.length);
}
else
if(iBeg) str=str.substring(iBeg,str.length);
return str;
}

function ReadNodes(d,str,p,c)
{
str=ReadWhChar(str);
while(str.length!=0&&ParseErr==0)
{
if(str.charAt(0)=="<")
{
 if(str.charAt(1)=='/')
 {
  var iEnd=str.indexOf(">");
  if(p && iEnd !=-1)
  {
   var Tag=TrimStr(str.substring(2,iEnd));
   if(Tag==p.tagName){str=str.substring(iEnd+1,str.length);return str;}
   if(ParseErr==0){alert("XML-parse error . Expected : "+Tag+"  ,found : "+p.tagName);ParseErr=1;}
   else{str.length=0; return str;}
  }
  else ParseErr=1;
 }
 else
 {
  if(str.charAt(1)=='?'){str=ReadPI(d,str,p,c);}
  else
  {
   if(str.charAt(1)=='!')
   {
    if(str.substring(1,4)=="!--"){str=ReadComment(d,str,p,c);}
    else
    {
     if(str.substring(1,9)=="![CDATA["){str=ReadCData(d,str,p,c);}
     else ParseErr=1;
    }
   }
   else str=ReadElement(d,str,p,c);
  }
 }
}
else str=ReadText(d,str,p,c);
str=ReadWhChar(str);
}
return str;
}

function AttrPos(str)
{
var i=str.indexOf("=");
if(i==-1) return 0;
while(str.charAt(i)!=' '&&i>0) i--;
return i;
}

function ReadText(d,str,p,c)
{
var iBeg=str.indexOf("<");
var node=null;
 
if(iBeg==-1)
{ 
 node=d.createTextNode(ToText(str));
 str="";
}
else
{
 node=d.createTextNode(ToText(str.substring(0,iBeg)));
 str=str.substring(iBeg,str.length);
}
if(p) node.parentNode=p;
c[c.length]=node;
return str;
}

function ReadElement(d,str,p,c)
{
var iEnd=str.indexOf(">");
var bEmpty=(str.charAt(iEnd-1)=='/'); 
if(bEmpty) iEnd-=1;
var Tag=str.substring(1,iEnd);
var iBegA=AttrPos(Tag); 

var Attrs;
var Name;
if(iBegA){Name=Tag.substring(0,iBegA);Attrs=Tag.substring(iBegA+1,Tag.length);}
else{Name=Tag;Attrs=null;}

var el=d.createElement(TrimStr(Name));
el.attributes=Attrs;
 
if(!bEmpty){str=str.substring(iEnd+1,str.length);str=ReadNodes(d,str,el,el.childNodes);}
else{str=str.substring(iEnd+2,str.length);}
el.parentNode=p;
c[c.length]=el;
return str;
}

function ReadPI(d,str,p,c)
{
var iEnd=str.indexOf("?>");
var iEndT=str.indexOf(" ");
var t=str.substring(2,iEndT);
var pi=str.substring(iEndT+1,iEnd);
var node=d.createProcessingInstruction(t,pi);
node.parentNode=p;
c[c.length]=node; 
str=str.substring(iEnd+2,str.length);
return str;
}

function ReadComment(d,str,p,c)
{
var iEnd=str.indexOf("-->");
var com=str.substring(4,iEnd);
var node=d.createComment(com);
node.parentNode=p;
c[c.length]=node; 
str=str.substring(iEnd+3,str.length);
return str;
}

function ReadCData(d,str,p,c)
{
var iEnd=str.indexOf("]]>");
var dat=str.substring(9,iEnd);
var node=d.createCDATASection(dat);
node.parentNode=p;
c[c.length]=node; 
str=str.substring(iEnd+3,str.length);
return str;
}

function ReadWhChar(s)
{
var i=0;
while(isWhChar(s.charAt(i))) i++;
if(i!=0) return s.substring(i,s.length);
return s;
}

function ReadAttrs(str)
{
var attrs=new Array();
attrs["item"]=null;
while(str.length)
{
var iName=str.indexOf("=");
if(iName==-1) return attrs;
var Name=TrimStr(str.substring(0,iName));
var Val;
var iVal1=str.indexOf("\"");
if(iVal1==-1) return attrs;
var iVal2=str.indexOf("\"",iVal1+1);
if(iVal2==-1) return attrs;
Val=str.substring(iVal1+1,iVal2); 
attrs[Name]=ToText(Val);
str=str.substring(iVal2+1,str.length);
}
return attrs;
}

function TrimStr(str)
{
if(str.indexOf(" ")==-1&&str.indexOf("\t")==-1&&str.indexOf("\r")==-1&&str.indexOf("\n")==-1) return str;
var iBeg=0,iEnd=str.length;
while(iBeg<iEnd&&isWhChar(str.charAt(iBeg))) iBeg++;
while(iEnd>iBeg&&isWhChar(str.charAt(iEnd-1))) iEnd--;//Note -1!
if(iBeg==0&&iEnd==str.length) return str;
return str.substring(iBeg,iEnd);
}

function isWhChar(ch){if(ch==' '||ch=='\t'||ch=='\r'||ch=='\n')return 1;return 0;}

function ToText(str)
{
if(str.indexOf("&")==-1) return str;
var s=new Array();
str+=" ";//Netscape4 bug
s=str.split("&lt;");
str=s.join("<");
s=str.split("&gt;");
str=s.join(">");
s=str.split("&quot;");
str=s.join("\"");
s=str.split("&apos;");
str=s.join("\'");
s=str.split("&amp;");
str=s.join("&");
s=str.split("&#009;");
str=s.join("\t");

s=str.split("&#013;&#010;");
str=s.join("\r\n");
//single new-lines:
s=str.split("&#010;");
str=s.join("\r\n");
s=str.split("&#013;");
str=s.join("\r");
s=str.split("&#092;");
str=s.join("\\");
return str.substring(0,str.length-1);
}
 
function FrText(str)
{
var s=new Array();
str=str+" ";//Netscape4 bug !
s=str.split("&");
str=s.join("&amp;");
s=str.split("<");
str=s.join("&lt;");
s=str.split(">");
 
str=s.join("&gt;");
s=str.split("\"");
str=s.join("&quot;");
s=str.split("\'");
str=s.join("&apos;");

s=str.split("\\");
str=s.join("&#092;");
s=str.split("\t");
str=s.join("&#009;");
s=str.split("\n");
str=s.join("&#010;");
s=str.split("\r");
str=s.join("&#013;");
return str=str.substring(-1,str.length-1);
}

function XmlStr(node,i,deep)
{
var s="";
if(node.nodeType==8){s+=node.data;return s;}
var num=node.childNodes.length;
var empty="";
if(num==0) empty="/";
var tagname=node.tagName;
s+="<"+tagname;
node.getAttribute("a");
var attrs=node.attributes;
if(attrs!=null)
for(var a in attrs){var v=attrs[a];if(v!=null) s+=" "+a+"=\""+FrText(v)+"\"";}
s+=empty+">";
if(num>0)
{
 if(num==1&&node.childNodes.item(0).nodeType==3){s+=FrText(node.childNodes.item(0).data);}
 else
 {var j;
  for(j=0;j<num;j++)
  {
   var child=node.childNodes.item(j);
   if(child.nodeType!=12)
    if(deep>0) s+= XmlStr(child,i+1,deep);
  }
 }
 s+="</"+tagname+">";
}
return s;
}

