//Copyright Inprise Corporation 1999, all rights reserved, to be used with Borlands Midas-technology only, 
//unless special permission has been given.
var xmlerrdisp_vers="1.0";
 
var szActionM="MODIFY",szActionD="DELETE",szActionI="INSERT";
 
 
 


function ErrReconcile(srcd,srcerr,fldids,names, fldiderrmes,fldiderraction )
{
var i;
 

 
this.srcD=srcd;
this.srcE=srcerr;
 
this.srcD.regobj(this);
 
//this.cnt=cnt;
if (fldids){ this.fldcnt=fldids.length} else{ if (names){ this.fldcnt=names.length} else {this.fldcnt = this.srcD.FieldCnt}};
this.fldids=fldids;
var r=fldids[0].length;
if (isNaN(r)) r=1;
this.rows=r;
for (i=0;i<this.fldcnt;i++)
{
var l=fldids[i].length;
if (isNaN(l)) l=1;
if (l!=r)
{
  alert(names[i]+": inconsistent row-count");
  if (l<this.rows) this.rows=l;
}
}

this.names=names;
this.errmes=fldiderrmes;
this.erraction=fldiderraction;
 
this.scrolloffs=0;
this.page=0;
this.selectRow=selectPos;
 
 
this.getValue=GridGetValue;
this.putValue=GridPutValue
 
this.fRow=0;
this.fCol=0;
 
this.setFocus=GridSetFocus;
//public
 
this.post=GridPost;
this.refr=DBGridRefr;
 
this.xfocus=GridFocus;

this.up=GridUp;//pre-rec
this.down=GridDown;//next-rec
this.scroll=GridScroll;

//this.keys=GridKeys;

this.ErrFirst=ErrFirst;
this.ErrNext=ErrNext;

this.DeltaHandled=DeltaHandled;
this.DeltaAdjustAll=DeltaAdjustAll;
this.DeltaAdjust=DeltaAdjust;
 
this.rsECur=null;
this.rsDCur=null;
OpenDetails(srcd);
OpenDetails(srcerr);



this.pModVal=null;
this.pOrgVal=null;
this.pConVal=null;
this.rstate="";
this.ErrStr="";
this.RecsHandled=new Array();
this.AddRecsHandled=AddRecsHandled;
this.bAborted=0;

//this.InitValues(this.srcE,this.srcD);
this.action="";//"correct"; 
this.cancel=ErrCancel;
this.correct=ErrCorrect;
this.merge=ErrMerge;
this.Reapply=Reapply;

this.InitValues=InitValues;
this.ErrFirst(srcerr,srcd);

this.selectRow(0);
this.refr(1);
this.setFocus(1,0);
}


function OpenDetails(rs)
{
 var f,i,rsD;
 for(i=0;i<rs.Fields.Cnt;i++)
 {
   f=rs.Fields.Fieldx[i];
   if (f.Type==szNested)
   {

      rsD=new xmlRowSet(null,rs,f.name);  
      OpenDetails(rsD);
   }     
 } 
}



function GridDown()
{
var r=this.fRow, c=this.fCol;

 
if (r<this.rows-1)
{
  r++
}
else {this.scroll(1);return;}
 
this.setFocus(r,c);
}

function GridUp()
{
var r=this.fRow, c=this.fCol;
 
if (r > 0)
  r--;
else {this.scroll(-1);return;}
this.setFocus(r,c);
}
 

function GridScroll(inc)
{
if (inc>0)
{
if (this.page*this.rows+this.fRow+this.scrolloffs>=this.rsDCur.Fields.Cnt) return; //**

if (this.scrolloffs== this.rows-1)
  {this.scrolloffs=0; this.page++;}
else
  this.scrolloffs++;
}
else
{
if (-this.scrolloffs== this.rows-1)
{
  if (this.page>0) {this.scrolloffs=0; this.page--;}
}
else
{
  this.scrolloffs--;
  if (this.page*this.rows+this.scrolloffs <0) this.scrolloffs=0
}
}
var r=this.fRow;
this.selectRow(r);//??
this.refr(1);
this.setFocus(r,this.fCol);
}
 

 
 
function GridSetFocus(r,c)
{
if (c>=this.fldcnt ||r>=this.rows) return;
var ref=this.fldids[c];
if (this.rows>1) ref=ref[r];
if(ref.disabled||ref.readonly) return; 
if (ref.focus!=null)
 ref.focus();
}




function GridFocus(r,c)
{

var ref;
 
if (c==null)
{ //r is 'this'
  if(r==null){r=this.fRow;c=this.fCol;ref=this.fldids[c];} else
  {
   var i,j,ref,found=0;
   for (j=0;j<this.fldcnt;j++)
   {
    ref=this.fldids[j];
    if (this.rows==1){if (ref==r) {r=0;c=j;found=1;break;}}   
    else for (i=0;i<this.rows;i++) if (ref[i]==r){r=i;c=j;found=1;break;}
    if (found) {break;}
   }  
   if (found==0) return 0;
  }
}
else
  ref=this.fldids[c];
if (this.rows>1) ref=ref[r];
 

//var f=this.getFldDes(c);
if (c!= 1)// f&&f.readonly)
{
  if(ref.getAttribute && ref.getAttribute("disabled")==true)//explorer only
  {}
  else     
    ref.blur(); 
  return 0;
}
else
{
 if (r!=this.fRow && this.fCol==1)
 {
   var ix=this.fRow+this.page*this.rows+this.scrolloffs;
   if (ix< this.rsDCur.Fields.Cnt)
   {
     if (this.action=="correct")
     {
       var v= this.getValue(this.fCol, this.fRow);
       if (v!=this.pModVal[ix])
       {
         var f=this.rsDCur.Fields.Fieldx[ix];
         var res="";
         if (f)
           res=f.validate(f.frdisp(v));
         if (res !=null)
         {
            v=f.todisp(res);
            this.putValue(this.fCol,this.fRow,v);
            this.pModVal[ix]=v;
         }
         else
         {
           this.setFocus(this.fRow,this.fCol);
           return 1;
         }
       }
      }
      else
      {
        this.putValue(this.fCol,this.fRow,this.pModVal[ix]);
      }
   }
   else
     this.putValue(this.fCol,this.fRow,"");
 }
 if (c!=this.fCol)
 { 
 
 }
 this.fRow=r;
 this.fCol=c;
 this.selectRow(r);
 if (ref.select!=null)
   ref.select();
 
}
return 0;
}


  

 

function GridPutValue(col,row,val)
{
 
var ref=this.fldids[col];
if (this.rows==1) ref.value=val; else ref[row].value = val;
 
}



function GridGetValue(col,row)
{
 
var ref=this.fldids[col];
if (this.rows==1) return ref.value;
return ref[row].value;
 
}

 
function selectPos(row)
{
return 1;

var pos = this.page*this.rows+row+this.scrolloffs;
if (pos>=0&&pos < this.src.RowCnt)
{
  this.src.setPos(pos);
  return 1;
}
return 0;
}



function DBGridRefr(r)
{
if (r==0 && this.rows>1) return;

var rsE=this.rsECur,rsD=this.rsDCur;
if (rsE==null || rsD==null) return;


//debug("refresh pos="+rsD.pos);
var i,j;

var ErrStr=this.ErrStr;
var rstate=this.rstate;
//debug(ErrStr + " " + rstate);

for (i=0; i<this.rows;i++)
{
  var fldname="";
  var ModVal="",OrgVal="",ConVal="";      
  var ix=i+this.page*this.rows+this.scrolloffs;
  if (ix<0) {ix=0;this.scrolloffs=0;}
  if (ix<rsD.Fields.Cnt && this.pModVal)
  {
     fldname=rsD.Fields.Fieldx[ix].name;
     ModVal=this.pModVal[ix];
     OrgVal=this.pOrgVal[ix];
     ConVal=this.pConVal[ix];
  }
  this.putValue(0,i,fldname);  

  this.putValue(2,i,ConVal); 

  if (rstate=="I" ||rstate== "D")
  {
   if (this.action=="cancel")
     this.putValue(1,i, ""); 
   else 
   if (this.action=="merge" && ConVal!="")
      this.putValue(1,i,ConVal);  
   else
      this.putValue(1,i,ModVal);  
  }
  else
  {
   if (this.action=="cancel")
     this.putValue(1,i, "");  
   else
     this.putValue(1,i,ModVal);  

   if ((this.action=="merge" ||this.action=="correct") && ConVal!="")
      this.putValue(3,i,ConVal);  
   else
      this.putValue(3,i,OrgVal);  
  } 
}//

 
if (this.errmes!=null)
{
   this.errmes.value=ErrStr; 
}
if (this.erraction!=null)
{
  var st; 
  if (rstate=="M") st=szActionM; else if(rstate=="D") st=szActionD; else if(rstate=="I") st=szActionI;
  this.erraction.value=st; 
}
}



function GridPost()
{

var rsE=this.rsECur,rsD=this.rsDCur;
if (rsE==null || rsD==null) return 1;
if (this.action=="" || this.action==null) {alert("Please select an action."); return 1;}

var i ;
 
var DeltaPos=rsD.pos;

var rstate=rsD.RowState(DeltaPos);

if (this.action=="cancel")
{
 var row=rsD.getRow(DeltaPos);
 if (row)
   row.removeAttribute(szRowState);
 if (rstate=="M")
 {
   var row=rsD.getRow(DeltaPos-1);
   if (row)
     row.removeAttribute(szRowState);
 }
}
else
if (this.action=="merge")
{
  var  rowE;
  this.AddRecsHandled(rsD);
  //this.RecsHandled[this.RecsHandled.length]=rsD.idx.row(rsD.pos);
  if (rstate=="M")
  {
    rsD.setPos(DeltaPos-1);
    this.AddRecsHandled(rsD);
  }
  rowE=rsE.makeRow();
  rsD.upd(rowE);
}
else
if (this.action=="correct")
{
  if (this.xfocus(this.fRow+1,this.fCol)) return 1;

  if (rstate=="M")
  { //merge
    rsD.setPos(DeltaPos-1);
    rowE=rsE.makeRow();
    rsD.upd(rowE);
    this.AddRecsHandled(rsD);
    rsD.setPos(DeltaPos);
  }
  for (i=0;i<rsD.Fields.Cnt;i++)
  {
    var f = rsD.Fields.Fieldx[i];
    var fldname=f.name;
    v=this.pModVal[i];
    if (v)
       this.pModVal[fldname]=f.frdisp(v);
  }
  rsD.upd(this.pModVal);
  this.AddRecsHandled(rsD);//[this.RecsHandled.length]=rsD.idx.row(rsD.pos);
}
if (this.ErrNext(this.rsECur,this.rsDCur)==0)
{
   this.rstate="";
   this.ErrStr="No more errors to reconcile";
   this.pModVal=null;
}
this.refr(1);
return 0;
}
 

function ErrCancel()
{
this.action="cancel";
this.refr(1);
this.setFocus(this.fRow,this.fCol);
}

function ErrCorrect()
{
this.action="correct";
this.refr(1);
this.setFocus(this.fRow,this.fCol);
}

function ErrMerge()
{
this.action="merge";
this.refr(1);
this.setFocus(this.fRow,this.fCol);
}


function Reapply(frm,el)
{
 if (frm)
 {
  if (this.bAborted==0)
    this.DeltaAdjustAll(this.srcD);
  var delta=this.srcD.root;
  if (this.srcD.RowData.childNodes.length==0)
    el.value="";
  else if (delta.xml!=null)
    el.value=delta.xml;
  else
    el.value=delta.xmlstr();
  frm.submit();
 }
}

function InitValues(rsE,rsD)
{

this.rsECur=rsE;this.rsDCur=rsD;
 
this.pModVal=new Array();
this.pOrgVal=new Array();
this.pConVal=new Array();

var i,j;

this.ErrStr=rsE.Fields.Field["ERROR_MESSAGE"].Value();
var ErrPos=parseInt(rsE.Fields.Field["ERROR_RECORDNO"].Value(),10);
var ErrResponse=parseInt(rsE.Fields.Field["ERROR_RESPONSE"].Value());
if (ErrResponse==2)
  this.bAborted=1;

rsD.setPos(ErrPos-1);
//debug("deltapos = " + ErrPos);

this.rstate=rsD.RowState(rsD.pos);
//debug("rstate="+this.rstate);

for (i=0; i<rsD.Fields.Cnt;i++)
{
  var fldname="";
  var ModVal="",OrgVal="",ConVal="";

  fldname=rsD.Fields.Fieldx[i].name;
  var fD=rsD.Fields.Field[fldname];
  var fE=rsE.Fields.Field[fldname];
 
  if (this.rstate=="D")
  {
    OrgVal=fD.Value();
    if (OrgVal) OrgVal=fD.todisp(OrgVal); 
  }
  else
  {
    ModVal=fD.Value();
    if (ModVal) ModVal=fD.todisp(ModVal);
  }
  ConVal=fE.Value();
  if (ConVal) ConVal=fE.todisp(ConVal);
  if (this.rstate=="M")
  {
    OrgVal=fD.Value(rsD.pos-1);
    if (OrgVal) OrgVal=fD.todisp(OrgVal);
  }
  this.pModVal[i]=ModVal;
  this.pOrgVal[i]=OrgVal;
  this.pConVal[i]=ConVal;   
}
}


//returns 1 if found, positions are in this.rsECur,this.rsDCur
function ErrFirst(rsE,rsD)
{
var i ;
this.action="";

if (rsE.first()==1) return 0;
rsD.first();
if (rsE.pDets)
{
  this.InitValues(rsE,rsD);
  for (i=0;i<rsE.pDets.length;i++)
  {
     if (this.ErrFirst(rsE.pDets[i],rsD.pDets[i])) return 1;    
  } 
}

var st=rsE.Fields.Field["ERROR_MESSAGE"].Value();
if (st && st!="")
{
   this.InitValues(rsE,rsD);
   if (this.rstate!=""&&this.rstate!="DU") return 1;   
}

if (this.ErrNext(rsE,rsD)) return 1;
   
return 0; 
}

function ErrNext(rsE, rsD)
{
 
//this.action="";
while (rsE.next()==0)
{
  if (rsE.pDets)
  {
    var i;
    this.InitValues(rsE,rsD);
    for (i=0;i<rsE.pDets.length;i++)
    {
       if (this.ErrFirst(rsE.pDets[i],rsD.pDets[i])) return 1;    
    } 
  }

  var st=rsE.Fields.Field["ERROR_MESSAGE"].Value();
  if (st && st!="")
  { //found next one
    this.InitValues(rsE,rsD);
    if (this.rstate!=""&&this.rstate!="DU") return 1;   
  }
}

if (rsE.parent)
{
   rsE=rsE.parent; 
   rsD=rsD.parent;
   var st=rsE.Fields.Field["ERROR_MESSAGE"].Value();
   if (st && st!="")
   { //found next one
     this.InitValues(rsE,rsD);
     if (this.rstate!=""&&this.rstate!="DU") return 1;   
   }
//   else
      if (this.ErrNext(rsE,rsD)) return 1;       
} 
return 0;
}

function DeltaHandled(rsD)
{
if(rsD.RowCnt==0)return 1;
var row=rsD.idx.row(rsD.pos);
if (row==null) return 1;
var i;

for (i=0;i<this.RecsHandled.length;i++)
{

  if (row==this.RecsHandled[i])
  {
     return 1;
  }
}
return 0;
}


function DeltaAdjust(rsD)
{
var i;
 
if (rsD.pos>=rsD.RowCnt) return 1;
  
if (rsD.pDets)
{
  for (i=0;i<rsD.pDets.length;i++)
     this.DeltaAdjustAll(rsD.pDets[i]);
} 
if (this.DeltaHandled(rsD)==0)
{
   rsD.del();
}
else
   if (rsD.next()==1) return 1;
return 0;
}

function DeltaAdjustAll(rsD)
{
rsD.first();
while (this.DeltaAdjust(rsD)==0)
  ;
}


function AddRecsHandled(rsD)
{
var pR=rsD.idx.row(rsD.pos);
if (pR==null) return;
var i;
if (rsD.parent)
  this.AddRecsHandled(rsD.parent);
for (i=0;i<this.RecsHandled.length;i++)
   if (this.RecsHandled[i]==pR) return;
this.RecsHandled[this.RecsHandled.length]=pR;

}


