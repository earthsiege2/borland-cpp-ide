//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.9  $
//
// Super include for getting all of ObjectWindows. Works well with precompiled
// headers
//----------------------------------------------------------------------------
#if !defined(OWL_OWLALL_H)
#define OWL_OWLALL_H

#if !defined(INC_OLE2)
# define INC_OLE2  // Make sure we get OLE headers
#endif

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_BITMAPGA_H)
# include <owl/bitmapga.h>
#endif
#if !defined(OWL_BITSET_H)
# include <owl/bitset.h>
#endif
#if !defined(OWL_BUTTON_H)
# include <owl/button.h>
#endif
#if !defined(OWL_BUTTONGA_H)
# include <owl/buttonga.h>
#endif
#if !defined(OWL_CELARRAY_H)
# include <owl/celarray.h>
#endif
#if !defined(OWL_CHECKBOX_H)
# include <owl/checkbox.h>
#endif
#if !defined(OWL_CHOOSECO_H)
# include <owl/chooseco.h>
#endif
#if !defined(OWL_CHOOSEFO_H)
# include <owl/choosefo.h>
#endif
#if !defined(OWL_CLIPBOAR_H)
# include <owl/clipboar.h>
#endif
#if !defined(OWL_CLIPVIEW_H)
# include <owl/clipview.h>
#endif
#if !defined(OWL_COMBOBOX_H)
# include <owl/combobox.h>
#endif
#if !defined(OWL_COMMDIAL_H)
# include <owl/commdial.h>
#endif
#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif
#if !defined(OWL_CONTROLB_H)
# include <owl/controlb.h>
#endif
#if !defined(OWL_CONTROLG_H)
# include <owl/controlg.h>
#endif
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif
#if !defined(OWL_DECFRAME_H)
# include <owl/decframe.h>
#endif
#if !defined(OWL_DECMDIFR_H)
# include <owl/decmdifr.h>
#endif
#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(OWL_DIBITMAP_H)
# include <owl/dibitmap.h>
#endif
#if !defined(OWL_PICTWIND_H)
# include <owl/pictwind.h>
#endif
#if !defined(OWL_DISPATCH_H)
# include <owl/dispatch.h>
#endif
#if !defined(OWL_DOCKING_H)
# include <owl/docking.h>
#endif
#if !defined(OWL_DOCMANAG_H)
# include <owl/docmanag.h>
#endif
#if !defined(OWL_DOCVIEW_H)
# include <owl/docview.h>
#endif
#if !defined(OWL_EDIT_H)
# include <owl/edit.h>
#endif
#if !defined(OWL_EDITFILE_H)
# include <owl/editfile.h>
#endif
#if !defined(OWL_EDITSEAR_H)
# include <owl/editsear.h>
#endif
#if !defined(OWL_EDITVIEW_H)
# include <owl/editview.h>
#endif
#if !defined(OWL_EVENTHAN_H)
# include <owl/eventhan.h>
#endif
#if !defined(OWL_EXCEPT_H)
# include <owl/except.h>
#endif
#if !defined(OWL_FILEDOC_H)
# include <owl/filedoc.h>
#endif
#if !defined(OWL_FINDREPL_H)
# include <owl/findrepl.h>
#endif
#if !defined(OWL_FLOATFRA_H)
# include <owl/floatfra.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_GADGET_H)
# include <owl/gadget.h>
#endif
#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif
#if !defined(OWL_GAUGE_H)
# include <owl/gauge.h>
#endif
#if !defined(OWL_GDIBASE_H)
# include <owl/gdibase.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_GROUPBOX_H)
# include <owl/groupbox.h>
#endif
#if !defined(OWL_INPUTDIA_H)
# include <owl/inputdia.h>
#endif
#if !defined(OWL_LAYOUTCO_H)
# include <owl/layoutco.h>
#endif
#if !defined(OWL_LAYOUTWI_H)
# include <owl/layoutwi.h>
#endif
#if !defined(OWL_LISTBOX_H)
# include <owl/listbox.h >
#endif
#if !defined(OWL_LISTVIEW_H)
# include <owl/listview.h>
#endif
#if !defined(OWL_MAILER_H)
# include <owl/mailer.h>
#endif
#if !defined(OWL_MCI_H)
# include <owl/mci.h>
#endif
#if !defined(OWL_MDI_H)
# include <owl/mdi.h>
#endif
#if !defined(OWL_MDICHILD_H)
# include <owl/mdichild.h>
#endif
#if !defined(OWL_MENU_H)
# include <owl/menu.h>
#endif
#if !defined(OWL_MENUGADG_H)
# include <owl/menugadg.h>
#endif
#if !defined(OWL_MESSAGEB_H)
# include <owl/messageb.h>
#endif
#if !defined(OWL_METAFILE_H)
# include <owl/metafile.h>
#endif
#if !defined(OWL_MODEGAD_H)
# include <owl/modegad.h>
#endif
#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif
#if !defined(BI_MODEL_SMALL)
# if !defined(OWL_OLEWINDO_H)
#   include <owl/olewindo.h>
# endif
# if !defined(OWL_OLEDOC_H)
#   include <owl/oledoc.h>
# endif
# if !defined(OWL_OLEMDIFR_H)
#   include <owl/olemdifr.h>
# endif
# if !defined(OWL_OLEVIEW_H)
#   include <owl/oleview.h>
# endif
#endif
#if !defined(OWL_OPENSAVE_H)
# include <owl/opensave.h>
#endif
#if !defined(OWL_PANESPLI_H)
# include <owl/panespli.h>
#endif
#if !defined(OWL_PICKLIST_H)
# include <owl/picklist.h>
#endif
#if !defined(OWL_PREVIEW_H)
# include <owl/preview.h>
#endif
#if !defined(OWL_PREVWIN_H)
# include <owl/prevwin.h>
#endif
#if !defined(OWL_PRINTDIA_H)
# include <owl/printdia.h>
#endif
#if !defined(OWL_PRINTER_H)
# include <owl/printer.h>
#endif
#if !defined(OWL_PROPSHT_H)
# include <owl/propsht.h>
#endif
#if !defined(OWL_RADIOBUT_H)
# include <owl/radiobut.h>
#endif
#if !defined(OWL_RCNTFILE_H)
# include <owl/rcntfile.h>
#endif
#if !defined(OWL_ROLLDIAL_H)
# include <owl/rolldial.h>
#endif
#if !defined(OWL_SCROLLBA_H)
# include <owl/scrollba.h>
#endif
#if !defined(OWL_SCROLLER_H)
# include <owl/scroller.h>
#endif
#if !defined(OWL_SIGNATUR_H)
# include <owl/signatur.h>
#endif
#if !defined(OWL_SLIDER_H)
# include <owl/slider.h>
#endif
#if !defined(OWL_SPLASHWI_H)
# include <owl/splashwi.h>
#endif
#if !defined(OWL_STATIC_H)
# include <owl/static.h>
#endif
#if !defined(OWL_STATUSBA_H)
# include <owl/statusba.h>
#endif
#if !defined(OWL_TABCTRL_H)
# include <owl/tabctrl.h>
#endif
#if !defined(OWL_TEXTGADG_H)
# include <owl/textgadg.h>
#endif
#if !defined(OWL_TIMEGADG_H)
# include <owl/timegadg.h>
#endif
#if !defined(OWL_TINYCAPT_H)
# include <owl/tinycapt.h>
#endif
#if !defined(OWL_TOOLBOX_H)
# include <owl/toolbox.h>
#endif
#if !defined(OWL_TOOLTIP_H)
# include <owl/tooltip.h>
#endif
#if !defined(OWL_UIHELPER_H)
# include <owl/uihelper.h>
#endif
#if !defined(OWL_UPDOWN_H)
# include <owl/updown.h>
#endif
#if !defined(OWL_VALIDATE_H)
# include <owl/validate.h>
#endif
#if !defined(OWL_VBXCTL_H)
# include <owl/vbxctl.h>
#endif
#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_WINDOWEV_H)
# include <owl/windowev.h>
#endif

#if defined(BI_PLAT_WIN32)
# if !defined(OWL_ANIMCTRL_H)
#  include <owl/animctrl.h>
# endif
# if !defined(OWL_COLMNHDR_H)
#  include <owl/colmnhdr.h>
# endif
# if !defined(OWL_DRAGLIST_H)
#  include <owl/draglist.h>
# endif
# if !defined(OWL_HLPMANAG_H)
#  include <owl/hlpmanag.h>
# endif
# if !defined(OWL_HOTKEY_H)
#  include <owl/hotkey.h>
# endif
# if !defined(OWL_IMAGELST_H)
#  include <owl/imagelst.h>
# endif
# if !defined(OWL_LISTWIND_H)
#  include <owl/listwind.h>
# endif
# if !defined(OWL_RICHEDIT_H)
#  include <owl/richedit.h>
# endif
# if !defined(OWL_RICHEDPR_H)
#  include <owl/richedpr.h>
# endif
# if !defined(OWL_TREEWIND_H)
#  include <owl/treewind.h>
# endif
# if !defined(OWL_SHELLITM_H)
#  include <owl/shellitm.h>
# endif
#endif  // BI_PLAT_WIN32

#endif  // OWL_OWLALL_H
