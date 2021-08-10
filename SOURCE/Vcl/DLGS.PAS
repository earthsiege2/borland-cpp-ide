{ *********************************************************************** }
{                                                                         }
{ Delphi Runtime Library                                                  }
{                                                                         }
{ Copyright (c) 1992-2001 Borland Software Corporation                    }
{                                                                         }
{ *********************************************************************** }

unit Dlgs;

{$WEAKPACKAGEUNIT}

(*$HPPEMIT '#include <dlgs.h>'*)

interface

{ Constants }

const
  {$EXTERNALSYM ctlFirst}
  ctlFirst = $0400;
  {$EXTERNALSYM ctlLast}
  ctlLast = $04ff;

{ Push buttons }

  {$EXTERNALSYM psh1}
  psh1 = $0400;
  {$EXTERNALSYM psh2}
  psh2 = $0401;
  {$EXTERNALSYM psh3}
  psh3 = $0402;
  {$EXTERNALSYM psh4}
  psh4 = $0403;
  {$EXTERNALSYM psh5}
  psh5 = $0404;
  {$EXTERNALSYM psh6}
  psh6 = $0405;
  {$EXTERNALSYM psh7}
  psh7 = $0406;
  {$EXTERNALSYM psh8}
  psh8 = $0407;
  {$EXTERNALSYM psh9}
  psh9 = $0408;
  {$EXTERNALSYM psh10}
  psh10 = $0409;
  {$EXTERNALSYM psh11}
  psh11 = $040a;
  {$EXTERNALSYM psh12}
  psh12 = $040b;
  {$EXTERNALSYM psh13}
  psh13 = $040c;
  {$EXTERNALSYM psh14}
  psh14 = $040d;
  {$EXTERNALSYM psh15}
  psh15 = $040e;
  {$EXTERNALSYM pshHelp}
  pshHelp = psh15;
  {$EXTERNALSYM psh16}
  psh16 = $040f;

{ Checkboxes }

  {$EXTERNALSYM chx1}
  chx1 = $0410;
  {$EXTERNALSYM chx2}
  chx2 = $0411;
  {$EXTERNALSYM chx3}
  chx3 = $0412;
  {$EXTERNALSYM chx4}
  chx4 = $0413;
  {$EXTERNALSYM chx5}
  chx5 = $0414;
  {$EXTERNALSYM chx6}
  chx6 = $0415;
  {$EXTERNALSYM chx7}
  chx7 = $0416;
  {$EXTERNALSYM chx8}
  chx8 = $0417;
  {$EXTERNALSYM chx9}
  chx9 = $0418;
  {$EXTERNALSYM chx10}
  chx10 = $0419;
  {$EXTERNALSYM chx11}
  chx11 = $041a;
  {$EXTERNALSYM chx12}
  chx12 = $041b;
  {$EXTERNALSYM chx13}
  chx13 = $041c;
  {$EXTERNALSYM chx14}
  chx14 = $041d;
  {$EXTERNALSYM chx15}
  chx15 = $041e;
  {$EXTERNALSYM chx16}
  chx16 = $041f;

{ Radio buttons }

  {$EXTERNALSYM rad1}
  rad1 = $0420;
  {$EXTERNALSYM rad2}
  rad2 = $0421;
  {$EXTERNALSYM rad3}
  rad3 = $0422;
  {$EXTERNALSYM rad4}
  rad4 = $0423;
  {$EXTERNALSYM rad5}
  rad5 = $0424;
  {$EXTERNALSYM rad6}
  rad6 = $0425;
  {$EXTERNALSYM rad7}
  rad7 = $0426;
  {$EXTERNALSYM rad8}
  rad8 = $0427;
  {$EXTERNALSYM rad9}
  rad9 = $0428;
  {$EXTERNALSYM rad10}
  rad10 = $0429;
  {$EXTERNALSYM rad11}
  rad11 = $042a;
  {$EXTERNALSYM rad12}
  rad12 = $042b;
  {$EXTERNALSYM rad13}
  rad13 = $042c;
  {$EXTERNALSYM rad14}
  rad14 = $042d;
  {$EXTERNALSYM rad15}
  rad15 = $042e;
  {$EXTERNALSYM rad16}
  rad16 = $042f;

{ Groups, frames, rectangles, and icons }

  {$EXTERNALSYM grp1}
  grp1 = $0430;
  {$EXTERNALSYM grp2}
  grp2 = $0431;
  {$EXTERNALSYM grp3}
  grp3 = $0432;
  {$EXTERNALSYM grp4}
  grp4 = $0433;
  {$EXTERNALSYM frm1}
  frm1 = $0434;
  {$EXTERNALSYM frm2}
  frm2 = $0435;
  {$EXTERNALSYM frm3}
  frm3 = $0436;
  {$EXTERNALSYM frm4}
  frm4 = $0437;
  {$EXTERNALSYM rct1}
  rct1 = $0438;
  {$EXTERNALSYM rct2}
  rct2 = $0439;
  {$EXTERNALSYM rct3}
  rct3 = $043a;
  {$EXTERNALSYM rct4}
  rct4 = $043b;
  {$EXTERNALSYM ico1}
  ico1 = $043c;
  {$EXTERNALSYM ico2}
  ico2 = $043d;
  {$EXTERNALSYM ico3}
  ico3 = $043e;
  {$EXTERNALSYM ico4}
  ico4 = $043f;

{ Static text }

  {$EXTERNALSYM stc1}
  stc1 = $0440;
  {$EXTERNALSYM stc2}
  stc2 = $0441;
  {$EXTERNALSYM stc3}
  stc3 = $0442;
  {$EXTERNALSYM stc4}
  stc4 = $0443;
  {$EXTERNALSYM stc5}
  stc5 = $0444;
  {$EXTERNALSYM stc6}
  stc6 = $0445;
  {$EXTERNALSYM stc7}
  stc7 = $0446;
  {$EXTERNALSYM stc8}
  stc8 = $0447;
  {$EXTERNALSYM stc9}
  stc9 = $0448;
  {$EXTERNALSYM stc10}
  stc10 = $0449;
  {$EXTERNALSYM stc11}
  stc11 = $044a;
  {$EXTERNALSYM stc12}
  stc12 = $044b;
  {$EXTERNALSYM stc13}
  stc13 = $044c;
  {$EXTERNALSYM stc14}
  stc14 = $044d;
  {$EXTERNALSYM stc15}
  stc15 = $044e;
  {$EXTERNALSYM stc16}
  stc16 = $044f;
  {$EXTERNALSYM stc17}
  stc17 = $0450;
  {$EXTERNALSYM stc18}
  stc18 = $0451;
  {$EXTERNALSYM stc19}
  stc19 = $0452;
  {$EXTERNALSYM stc20}
  stc20 = $0453;
  {$EXTERNALSYM stc21}
  stc21 = $0454;
  {$EXTERNALSYM stc22}
  stc22 = $0455;
  {$EXTERNALSYM stc23}
  stc23 = $0456;
  {$EXTERNALSYM stc24}
  stc24 = $0457;
  {$EXTERNALSYM stc25}
  stc25 = $0458;
  {$EXTERNALSYM stc26}
  stc26 = $0459;
  {$EXTERNALSYM stc27}
  stc27 = $045a;
  {$EXTERNALSYM stc28}
  stc28 = $045b;
  {$EXTERNALSYM stc29}
  stc29 = $045c;
  {$EXTERNALSYM stc30}
  stc30 = $045d;
  {$EXTERNALSYM stc31}
  stc31 = $045e;
  {$EXTERNALSYM stc32}
  stc32 = $045f;

{ Listboxes }

  {$EXTERNALSYM lst1}
  lst1 = $0460;
  {$EXTERNALSYM lst2}
  lst2 = $0461;
  {$EXTERNALSYM lst3}
  lst3 = $0462;
  {$EXTERNALSYM lst4}
  lst4 = $0463;
  {$EXTERNALSYM lst5}
  lst5 = $0464;
  {$EXTERNALSYM lst6}
  lst6 = $0465;
  {$EXTERNALSYM lst7}
  lst7 = $0466;
  {$EXTERNALSYM lst8}
  lst8 = $0467;
  {$EXTERNALSYM lst9}
  lst9 = $0468;
  {$EXTERNALSYM lst10}
  lst10 = $0469;
  {$EXTERNALSYM lst11}
  lst11 = $046a;
  {$EXTERNALSYM lst12}
  lst12 = $046b;
  {$EXTERNALSYM lst13}
  lst13 = $046c;
  {$EXTERNALSYM lst14}
  lst14 = $046d;
  {$EXTERNALSYM lst15}
  lst15 = $046e;
  {$EXTERNALSYM lst16}
  lst16 = $046f;

{ Combo boxes }

  {$EXTERNALSYM cmb1}
  cmb1 = $0470;
  {$EXTERNALSYM cmb2}
  cmb2 = $0471;
  {$EXTERNALSYM cmb3}
  cmb3 = $0472;
  {$EXTERNALSYM cmb4}
  cmb4 = $0473;
  {$EXTERNALSYM cmb5}
  cmb5 = $0474;
  {$EXTERNALSYM cmb6}
  cmb6 = $0475;
  {$EXTERNALSYM cmb7}
  cmb7 = $0476;
  {$EXTERNALSYM cmb8}
  cmb8 = $0477;
  {$EXTERNALSYM cmb9}
  cmb9 = $0478;
  {$EXTERNALSYM cmb10}
  cmb10 = $0479;
  {$EXTERNALSYM cmb11}
  cmb11 = $047a;
  {$EXTERNALSYM cmb12}
  cmb12 = $047b;
  {$EXTERNALSYM cmb13}
  cmb13 = $047c;
  {$EXTERNALSYM cmb14}
  cmb14 = $047d;
  {$EXTERNALSYM cmb15}
  cmb15 = $047e;
  {$EXTERNALSYM cmb16}
  cmb16 = $047f;

{ Edit controls }

  {$EXTERNALSYM edt1}
  edt1 = $0480;
  {$EXTERNALSYM edt2}
  edt2 = $0481;
  {$EXTERNALSYM edt3}
  edt3 = $0482;
  {$EXTERNALSYM edt4}
  edt4 = $0483;
  {$EXTERNALSYM edt5}
  edt5 = $0484;
  {$EXTERNALSYM edt6}
  edt6 = $0485;
  {$EXTERNALSYM edt7}
  edt7 = $0486;
  {$EXTERNALSYM edt8}
  edt8 = $0487;
  {$EXTERNALSYM edt9}
  edt9 = $0488;
  {$EXTERNALSYM edt10}
  edt10 = $0489;
  {$EXTERNALSYM edt11}
  edt11 = $048a;
  {$EXTERNALSYM edt12}
  edt12 = $048b;
  {$EXTERNALSYM edt13}
  edt13 = $048c;
  {$EXTERNALSYM edt14}
  edt14 = $048d;
  {$EXTERNALSYM edt15}
  edt15 = $048e;
  {$EXTERNALSYM edt16}
  edt16 = $048f;

{ Scroll bars }

  {$EXTERNALSYM scr1}
  scr1 = $0490;
  {$EXTERNALSYM scr2}
  scr2 = $0491;
  {$EXTERNALSYM scr3}
  scr3 = $0492;
  {$EXTERNALSYM scr4}
  scr4 = $0493;
  {$EXTERNALSYM scr5}
  scr5 = $0494;
  {$EXTERNALSYM scr6}
  scr6 = $0495;
  {$EXTERNALSYM scr7}
  scr7 = $0496;
  {$EXTERNALSYM scr8}
  scr8 = $0497;

{ Dialog resource ordinals }

  {$EXTERNALSYM FILEOPENORD}
  FILEOPENORD = 1536;
  {$EXTERNALSYM MULTIFILEOPENORD}
  MULTIFILEOPENORD = 1537;
  {$EXTERNALSYM PRINTDLGORD}
  PRINTDLGORD = 1538;
  {$EXTERNALSYM PRNSETUPDLGORD}
  PRNSETUPDLGORD = 1539;
  {$EXTERNALSYM FINDDLGORD}
  FINDDLGORD = 1540;
  {$EXTERNALSYM REPLACEDLGORD}
  REPLACEDLGORD = 1541;
  {$EXTERNALSYM FONTDLGORD}
  FONTDLGORD = 1542;
  {$EXTERNALSYM FORMATDLGORD31}
  FORMATDLGORD31 = 1543;
  {$EXTERNALSYM FORMATDLGORD30}
  FORMATDLGORD30 = 1544;
  {$EXTERNALSYM PAGESETUPDLGORD}
  PAGESETUPDLGORD = 1546;
  {$EXTERNALSYM NEWFILEOPENORD}
  NEWFILEOPENORD = 1547;

type
  {$EXTERNALSYM tagCRGB}
  tagCRGB = record    { RGB Color }
    bRed: BYTE;
    bGreen: BYTE;
    bBlue: BYTE;
    bExtra: BYTE;
  end;
  {$EXTERNALSYM CRGB}
  CRGB = tagCRGB;

implementation

end.

