//Copyright Inprise Corporation 1999, all rights reserved, to be used with Borlands Midas-technology only, 
//unless special permission has been given.
var xmldisp_vers="1.0";
var szNotUpdateable="disabled";
var iUpKey=38, iDownKey=40; 

new xmlDisplay(null,null,null);
xmlDisplay.prototype.fldcnt=0;
xmlDisplay.prototype.rows=0;
xmlDisplay.prototype.bDontPost=0;
xmlDisplay.prototype.scrolloffs=0;
xmlDisplay.prototype.page=0;
xmlDisplay.prototype.fldfirst=0;
xmlDisplay.prototype.KeyMap=null;
xmlDisplay.prototype.focusflag=0;
//methods
xmlDisplay.prototype.getFldDes=function(i){return this.src.Fields.Field[this.names[i]];}
xmlDisplay.prototype.selectRow=function(r){var pos=this.page*this.rows+r+this.scrolloffs;return this.src.setPos(pos);}

xmlDisplay.prototype.getValue=GridGetValue;
xmlDisplay.prototype.putValue=GridPutValue;
xmlDisplay.prototype.getRow=GridGetRow;
xmlDisplay.prototype.valchanged=GridValChanged;
xmlDisplay.prototype.setFocus=GridSetFocus;
xmlDisplay.prototype.xvalidate=GridValidate; 
xmlDisplay.prototype.scroll=GridScroll;
xmlDisplay.prototype.refr=GridRefr;
//public
xmlDisplay.prototype.post=GridPost;
xmlDisplay.prototype.postall=function(){if (this.src.forcepost()) return;this.post();}
xmlDisplay.prototype.removeRow=GridDelete;
xmlDisplay.prototype.newRow=GridNew;
xmlDisplay.prototype.undo=GridUndo;

xmlDisplay.prototype.first=GridFirst;
xmlDisplay.prototype.last=GridLast;
xmlDisplay.prototype.pgup=pgBackw;
xmlDisplay.prototype.pgdown=pgForw;
xmlDisplay.prototype.up=GridUp;//pre-rec
xmlDisplay.prototype.down=GridDown;//next-rec
xmlDisplay.prototype.left=GridL;//prev-field
xmlDisplay.prototype.right=GridR;//next-field
xmlDisplay.prototype.sort=function(n){if(this.src.forcepost())return;var i;for(i=0;i<this.fldcnt;i++){if (this.names[i]==n){this.fCol=i;break;}}this.src.sort(n);this.first();}
xmlDisplay.prototype.xfocus=GridFocus;
xmlDisplay.prototype.keys=GridKeys;
xmlDisplay.prototype.setKeyMap=GridSetKeys;
xmlDisplay.prototype.OnError=function(s){alert(s);return null;}

var fset=0;

function xmlDisplay(src,fldids,names,rstate)
{
this.src=src;
this.fldids=fldids;
this.names=names;
this.rstate=rstate;
if(src==null||src.doc=="") return null;
 
src.regobj(this);
if(fldids){this.fldcnt=fldids.length}else{if(names){this.fldcnt=names.length}else{this.fldcnt=this.src.FieldCnt}};
this.rows=0;
var i;
for(i=0;i<this.fldcnt;i++)
{
 var ref=fldids[i]; 
 var t=ref.type;if(t==null)t=ref[0].type;
 if(t=="text"||t=="textarea")
 {
  var l=ref.length;
  if(isNaN(l)) l=1;
  if(this.rows==0) this.rows=l;
  if(l!=this.rows){this.OnError(names[i]+": inconsistent row-count");if(l<this.rows) this.rows=l;}
 }
 var f=this.getFldDes(i);
 if(f==null) return this.OnError(names[i]+": name not found in rowset");

 if(this.rows!=0){
 if(this.rows==1)
 {
  if(ref.setAttribute)
  {
   if(f.readonly==1) ref.setAttribute(szNotUpdateable,1);
   if(f.maxlength>0&&f.Type!=szUni) ref.setAttribute("maxLength",f.maxlength);
  }
 }
 else
 {
  var j;
  for(j=0;j<ref.length;j++)
  {
   if(ref[j].setAttribute)
   {
    if(f.readonly==1) ref[j].setAttribute(szNotUpdateable,1);
    if(f.maxlength>0) ref[j].setAttribute("maxLength",f.maxlength);
   }
  }
 }
 }
 if(f.readonly==1&&i==this.fldfirst) this.fldfirst++;
}
this.fRow=0;
this.fCol=0;

//Init
this.selectRow(0);
this.refr(1);
if(fset==0&&this.src.parent==null){this.setFocus(0,this.fldfirst);fset++;}
//this.keys=GridKeys;
if(this.rows==1)
{
this.setKeyMap(iUpKey,"left");
this.setKeyMap(iDownKey,"right");
}
else
{
this.setKeyMap(iUpKey,"up");
this.setKeyMap(iDownKey,"down");
}
this.setKeyMap(33,"pgup");
this.setKeyMap(34,"pgdown");
this.setKeyMap(45,"newRow");
this.setKeyMap(13,"right"); 
return this;
}

function GridKeys(el)
{
var e,k;
e=self.event;
if(!e) return true;
if(e!=null){k=e.keyCode;}else{k=e.which;}
 
var found=false;
var r,c;

for(c=0;c<this.fldcnt;c++)
{
 var ref=this.fldids[c];
 if(this.rows==1){if (ref==el) found= true;}
 else
 {
  for(r=0; r<this.rows;r++)
   {if(ref[r]==el){found=true; break;}}
 }
 if(found) break;
} 
if(!found) return true;

if(this.KeyMap==null) return true;
var a=this.KeyMap[k.toString()];
if(a==null||this[a]==null){return true;}
a="this."+a+"();";
eval(a);
return true;  
}

function GridL()
{
var r=this.fRow,c=this.fCol;
do{if(c>0)c--;else c=this.fldcnt-1;}
while(this.getFldDes(c).readonly==1&&c!=this.fCol)
this.setFocus(r,c);
}

function GridR()
{
var r=this.fRow,c=this.fCol;
do{if(c< this.fldcnt-1)c++;else c=0;}
while(this.getFldDes(c).readonly==1&&c!=this.fCol)
this.setFocus(r,c);
}

function GridDown()
{
var r=this.fRow, c=this.fCol;
if(this.rows==1){this.pgdown();return;}
if(r<this.rows-1){r++;}else{this.scroll(1);return;}
this.setFocus(r,c);
}

function GridUp()
{
var r=this.fRow,c=this.fCol;
if(this.rows==1){this.pgup();return;}
if(r>0) r--;else{this.scroll(-1);return;}
this.setFocus(r,c);
}

function pgBackw()
{
if(this.page>0||this.scrolloffs)
{
 if(this.src.forcepost()) return;
 if(this.page) this.page--;else{this.fRow+=this.scrolloffs-this.rows;this.scrolloffs=0}
 if(this.scrolloffs<0&&this.page==0){this.scrolloffs=0;this.fRow=0;}
 if(this.rows==1) this.selectRow(0);
 else this.refr(1);
}
else this.fRow=0;
this.setFocus(this.fRow, this.fCol);
}

function pgForw()
{
if(this.rows*(this.page+2)<this.src.RowCnt) 
{
 if(this.src.forcepost()) return;
 this.page++;
 if(this.rows==1) this.selectRow(0);else this.refr(1);
}
else{this.last();return;}
this.setFocus(this.fRow,this.fCol);
}

function GridScroll(inc)
{
if(inc>0)
{
 if(this.page*this.rows+this.fRow+this.scrolloffs>=this.src.RowCnt) return;
 if(this.scrolloffs==this.rows-1){this.scrolloffs=0;this.page++;}
 else this.scrolloffs++;
}
else
{
 if(-this.scrolloffs==this.rows-1){if(this.page>0){this.scrolloffs=0;this.page--;}}
 else{this.scrolloffs--;if(this.page*this.rows+this.scrolloffs<0)this.scrolloffs=0}
}
var r=this.fRow;
this.selectRow(r);
this.refr(1);
this.setFocus(r,this.fCol);
}

function GridSetFocus(r,c)
{
if(c>=this.fldcnt||r>=this.rows) return;
var ref=this.fldids[c];
if(this.rows>1) ref=ref[r];
if(ref.disabled||ref.readonly) return; 
if(ref.focus!=null){this.focusflag=1;ref.focus();if(this.focusflag==1)this.xfocus(r,c);}
}

function GridFocus(r,c)
{
var ref;
this.focusflag=0;
if(c==null)
{ 
 if(r==null){r=this.fRow;c=this.fCol;ref=this.fldids[c];}
 else
 {
  var i,j,ref,found=0;
  for(j=0;j<this.fldcnt;j++)
  {
   ref=this.fldids[j];
   if(this.rows==1){if(ref==r){r=0;c=j;found=1;break;}}   
   else for(i=0;i<this.rows;i++) if(ref[i]==r){r=i;c=j;found=1;break;}
   if(found) break;
  }  
  if(found==0)return;
 }
}
else ref=this.fldids[c];
if(this.rows>1) ref=ref[r];
var f=this.getFldDes(c);
var p=this.page*this.rows+this.scrolloffs;
if(f&&f.readonly==1)
{
 if(ref.getAttribute&&ref.getAttribute("disabled")==true){}//explorer only
 else ref.blur();
 return;
}
else
{
 if(r!=this.fRow&&this.bDontPost==0)
 {if(this.src.noIns!=0&&(p+r)>=this.src.RowCnt){ref.blur();return;}
   if(this.src.forcepost()!=0)return;
 }
 if(c!=this.fCol){if(this.src.noUpd!=0&&p+this.fRow<this.src.RowCnt&&this.valchanged(p,this.fRow,this.fCol)!=0){this.refr(1);}
     else if(this.valchanged(p,this.fRow,this.fCol)!=0&&this.xvalidate(this.fRow,this.fCol,0)==0)return;}
 this.fRow=r;
 this.fCol=c;
 if(this.rows>1) this.selectRow(r);
 if(ref.select!=null) ref.select();
 this.bDontPost=0;
}
}

function GridUndo()
{
var r=this.fRow;
if(r==-1) return;
var pos=this.page*this.rows+r+this.scrolloffs;
if(pos>=0&&pos<this.src.RowCnt)
{
 this.src.undo(pos);
 if(pos&&pos>=this.src.RowCnt) this.last();
 else this.setFocus(r,this.fCol);
}
if(pos>=this.src.RowCnt){this.refr(1);this.last();}
}

function GridNew()
{
if(this.src.noIns) return;
if(this.src.forcepost()) return;
var pages=0,r=this.src.RowCnt%this.rows;
pages=(this.src.RowCnt-r)/this.rows;
if(r==0&&pages)
{
 if(this.rows==1) pages++;
 else this.scrolloffs=1;
 r=this.rows-1;
 this.page=pages-1;
}
else{this.scrolloffs=0;this.page=pages;}
this.refr(1);
this.setFocus(r,this.fldfirst);
}

function GridFirst()
{
if(this.src.forcepost()) return;
this.scrolloffs=0;
this.page=0;
if(this.rows==1) this.selectRow(0);else{if(this.src.pos!=0)this.refr(1);}
this.setFocus(0,this.fCol);
}

function GridLast()
{
if(this.src.forcepost()) return;
var r=this.src.RowCnt%this.rows ;
pages=(this.src.RowCnt-r)/this.rows;
if(r==0){r=this.rows-1;this.page=pages-1;this.scrolloffs=0;}
else{this.scrolloffs=0;this.page=pages;r--;}

if(this.rows==1) this.selectRow(0);
else this.refr(1);
this.setFocus(r,this.fCol);
}

function GridValChanged(pos,r,c)
{
var f=this.getFldDes(c);
var val="";
if(pos+r<this.src.RowCnt)
{if(f){val=f.Value(pos+r);if(val) val=f.todisp(val);}}
else
{
 if(this.getValue(c,r)!="")return 1;
 return 0;
}
var gval=this.getValue(c,r);
if(val==gval) return 0;
 
if(f&&(f.Type=="string"||f.Type==szUni||f.subtype=="Text"))
  if(txtnorm(val)==txtnorm(gval)) return 0;
if(f&&f.readonly==1){this.OnError(f.name+" : Cannot change readonly field");return 0;}
return 1;
}

function txtnorm(s){var v=new Array();v=s.split("\r\n");s=v.join(" ");v=s.split("\n");s=v.join(" ");v=s.split("\r");s=v.join(" ");return s;}

function GridValidate(r,c,q)
{
if(this.bDontPost) return 0;
var ref;
if(c==null)
{ 
 var i,j,ref,found=0;
 for(j=0;j<this.fldcnt;j++)
 {
  ref=this.fldids[j];
  if(this.rows==1){if (ref==r) {r=0;c=j;found=1;break;}}   
  else for(i=0;i<this.rows;i++) if(ref[i]==r){r=i;c=j;found=1;break;}
  if(found) break;
 }  
 if(found==0) return 1;
}

var v=this.getValue(c,r);
var f=this.getFldDes(c);
var res="";
if(f){if(f.required!=0&&v==""&&q==0)res=v;else res=f.validate(v);}
if(res!=null){v=res;this.putValue(c,r,v);return 1;}

this.setFocus(r,c);
return 0;
}

function GridGetRow(row)
{
var i,f,v,r=new Array();
for(i=0;i<this.fldcnt;i++)
{
 v=this.getValue(i,row);
 f=this.getFldDes(i);
 if(f) r[this.names[i]]=f.frdisp(v);
}
return r;
}

function GridPutValue(col,row,val)
{
var ref=this.fldids[col];
if(this.rows==1)
{
 if(ref.type=="select-one"){var le=ref.length,i;for(i=0;i<le;i++)if(ref[i].value==val)ref[i].selected=true;else ref[i].selected=false;}else
 if(ref.type=="text"||ref.type=="textarea"||ref.type=="select-one") ref.value=val;
 else
 if(ref[0].type=="radio")
 {
  var i;
  for(i=0;i<ref.length;i++)
  {
   if(ref[i].value==val){ref[i].checked=true; break;}
   else ref[i].checked=false;
  } 
 }
}
else ref[row].value = val;
}

function GridGetValue(col,row)
{
var ref=this.fldids[col];
if(this.rows==1)
{
 if(ref.type=="select-one"){var le=ref.length,i;for(i=0;i<le;i++)if(ref[i].selected)return ref[i].value;return ""}
 if(ref.type=="text"||ref.type=="textarea") return ref.value;
 if(ref[0].type=="radio")
 {
  var i;
  for(i=0;i<ref.length;i++)
  {if(ref[i].checked==true) return ref[i].value;}
 }
 return "";
}
return ref[row].value;
}

function GridDelete()
{
if(this.src.noDel) return;
if(this.src.forcepost()) return;
var r=this.fRow;
if(r==-1) return;
var pos=this.page*this.rows+r+this.scrolloffs;
if(pos>=0&&pos<this.src.RowCnt)
{
 this.src.deletex(pos);
 if(pos&&pos>=this.src.RowCnt) this.last();
 else this.setFocus(r,this.fldfirst);
}
}

function GridRefr(r)
{
if(r==0&&this.rows>1) return;
var i,j, pos;
if(r==2){this.scrolloffs=0;this.fRow=0;this.page=0}
if(this.rows==1) {if (this.page<this.src.RowCnt){pos=this.src.pos;this.page=pos;}else pos=this.page}
else pos=this.page*this.rows+this.scrolloffs;
if(pos<0) pos=0;

for(i=0;i<this.rows;i++)
{
for(j=0;j<this.fldcnt;j++)
{
 var val="";
 if(pos<this.src.RowCnt)
 {
  var f=this.getFldDes(j);
  if(f){val=f.Value(pos);if(val)val=f.todisp(val);}
 }
 this.putValue(j,i,val);
}
if(this.rstate)
{
 var st=this.src.RowState(pos);
 if(this.rows==1) this.rstate.value=st;else this.rstate[i].value=st;
}
pos++;
}
}

function GridPost()
{
if(this.bDontPost) return 1;
var src=this.src;
var j,r=this.fRow,pos=this.page*this.rows+this.scrolloffs;
var bMod=0,err=0,bIns=(pos+r>=src.RowCnt)?1:0;
var row=null;

for(j=0;j<this.fldcnt;j++)
{
 if(this.valchanged(pos,r,j))
 { 
  if((bIns==0&&src.noUpd!=0)||(bIns!=0&&src.noIns)){this.refr(1);return 0;}
  f=this.getFldDes(j);
  if(f&&f.readonly!=0)continue;
  bMod=1;
  if(this.xvalidate(r,j,1)==0) return 1;
  if(row==null)row=new Array();
  var f,v;
  v=this.getValue(j,r);
  if(f)row[this.names[j]]=f.frdisp(v);
 }
}
if(bMod)
{
 if(bIns)
 {
  for(j=0;j<this.fldcnt;j++) if(this.xvalidate(r,j,1)==0) return 1;
 }
 if(bIns==0){err=src.modify(pos+r,row);}else{err=src.insert(row,1);}
}
return err;
}

function GridSetKeys(key,action,param)
{
if(this.KeyMap==null) this.KeyMap=new Array();
this.KeyMap[key.toString()]=action;
}
