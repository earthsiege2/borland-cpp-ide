//------------------------------------------------------------------------------
// DBEVENT.H
// Copyrights (C) 1996 Borland International
// All Rights Reserved
//------------------------------------------------------------------------------

#if !defined(DBEVENT_H_)
#define DBEVENT_H_

#include <winsys/geometry.h>  // TRect
#include <vdbt/dbtype.h>
#include <vdbt/bdte.h>


//------------------------------------------------------------------------------
// Macros
//------------------------------------------------------------------------------
#define DECLARE_SOURCE( name, type )                              \
  protected:                                                      \
    void Attach##name( const TBdtEventSourceBase&, bool attach )  \
    {                                                             \
      name = attach ? &ThisDBClss::Fire##name : NULL;             \
    }                                                             \
  public:                                                         \
    type##Source name##Source

#define INIT_SOURCE( name )                                              \
  name##Source( SrcAttach_MFUNCTOR( *this, &ThisDBClss::Attach##name ) ) \


//------------------------------------------------------------------------------
// TDBCheckBox Functors
//------------------------------------------------------------------------------
typedef TBdtEventSourceV1<TDBCheckBox&> TDBCheckBoxNotifySource;
typedef TBdtEventSinkV1<TDBCheckBox&>   TDBCheckBoxNotifySink;
#define TDBCheckBoxNotify_FUNCTOR(func) \
        Functor((TDBCheckBoxNotifySink::TFunctor*)0, func)
#define TDBCheckBoxNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDBCheckBoxNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBCheckBox&, TVbxControl&, SHORT, SHORT>
                                                          TDBCheckBoxDragSource;
typedef TBdtEventSinkV4<TDBCheckBox&, TVbxControl&, SHORT, SHORT>
                                                          TDBCheckBoxDragSink;
#define TDBCheckBoxDrag_FUNCTOR(func) \
        Functor((TDBCheckBoxDragSink::TFunctor*)0, func)
#define TDBCheckBoxDrag_MFUNCTOR(object,memberFunc) \
        Functor((TDBCheckBoxDragSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBCheckBox&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBCheckBoxDragOverSource;
typedef TBdtEventSinkV5<TDBCheckBox&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBCheckBoxDragOverSink;
#define TDBCheckBoxDragOver_FUNCTOR(func) \
        Functor((TDBCheckBoxDragOverSink::TFunctor*)0, func)
#define TDBCheckBoxDragOver_MFUNCTOR(object,memberFunc) \
        Functor((TDBCheckBoxDragOverSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV3<TDBCheckBox&, SHORT*, TShiftState>
                                                           TDBCheckBoxKeySource;
typedef TBdtEventSinkV3<TDBCheckBox&, SHORT*, TShiftState> TDBCheckBoxKeySink;
#define TDBCheckBoxKey_FUNCTOR(func) \
        Functor((TDBCheckBoxKeySink::TFunctor*)0, func)
#define TDBCheckBoxKey_MFUNCTOR(object,memberFunc) \
        Functor((TDBCheckBoxKeySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV2<TDBCheckBox&, SHORT> TDBCheckBoxKeyPressSource;
typedef TBdtEventSinkV2<TDBCheckBox&, SHORT>   TDBCheckBoxKeyPressSink;
#define TDBCheckBoxKeyPress_FUNCTOR(func) \
        Functor((TDBCheckBoxKeyPressSink::TFunctor*)0, func)
#define TDBCheckBoxKeyPress_MFUNCTOR(object,memberFunc) \
        Functor((TDBCheckBoxKeyPressSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBCheckBox&, TMouseButton, TShiftState, SHORT, SHORT>
                                                         TDBCheckBoxMouseSource;
typedef TBdtEventSinkV5<TDBCheckBox&, TMouseButton, TShiftState, SHORT, SHORT>
                                                         TDBCheckBoxMouseSink;
#define TDBCheckBoxMouse_FUNCTOR(func) \
        Functor((TDBCheckBoxMouseSink::TFunctor*)0, func)
#define TDBCheckBoxMouse_MFUNCTOR(object,memberFunc) \
        Functor((TDBCheckBoxMouseSink::TFunctor*)0, object, memberFunc)


//------------------------------------------------------------------------------
// TDBComboBox Functors
//------------------------------------------------------------------------------
typedef TBdtEventSourceV1<TDBComboBox&> TDBComboBoxNotifySource;
typedef TBdtEventSinkV1<TDBComboBox&>   TDBComboBoxNotifySink;
#define TDBComboBoxNotify_FUNCTOR(func) \
        Functor((TDBComboBoxNotifySink::TFunctor*)0, func)
#define TDBComboBoxNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDBComboBoxNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBComboBox&, TVbxControl&, SHORT, SHORT>
                                                          TDBComboBoxDragSource;
typedef TBdtEventSinkV4<TDBComboBox&, TVbxControl&, SHORT, SHORT>
                                                          TDBComboBoxDragSink;
#define TDBComboBoxDrag_FUNCTOR(func) \
        Functor((TDBComboBoxDragSink::TFunctor*)0, func)
#define TDBComboBoxDrag_MFUNCTOR(object,memberFunc) \
        Functor((TDBComboBoxDragSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBComboBox&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBComboBoxDragOverSource;
typedef TBdtEventSinkV5<TDBComboBox&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBComboBoxDragOverSink;
#define TDBComboBoxDragOver_FUNCTOR(func) \
        Functor((TDBComboBoxDragOverSink::TFunctor*)0, func)
#define TDBComboBoxDragOver_MFUNCTOR(object,memberFunc) \
        Functor((TDBComboBoxDragOverSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV3<TDBComboBox&, SHORT*, TShiftState>
                                                           TDBComboBoxKeySource;
typedef TBdtEventSinkV3<TDBComboBox&, SHORT*, TShiftState> TDBComboBoxKeySink;
#define TDBComboBoxKey_FUNCTOR(func) \
        Functor((TDBComboBoxKeySink::TFunctor*)0, func)
#define TDBComboBoxKey_MFUNCTOR(object,memberFunc) \
        Functor((TDBComboBoxKeySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV2<TDBComboBox&, SHORT> TDBComboBoxKeyPressSource;
typedef TBdtEventSinkV2<TDBComboBox&, SHORT>   TDBComboBoxKeyPressSink;
#define TDBComboBoxKeyPress_FUNCTOR(func) \
        Functor((TDBComboBoxKeyPressSink::TFunctor*)0, func)
#define TDBComboBoxKeyPress_MFUNCTOR(object,memberFunc) \
        Functor((TDBComboBoxKeyPressSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV3<TDBComboBox&, SHORT, SHORT*>
                                                   TDBComboBoxMeasureItemSource;
typedef TBdtEventSinkV3<TDBComboBox&, SHORT, SHORT*> TDBComboBoxMeasureItemSink;
#define TDBComboBoxMeasureItem_FUNCTOR(func) \
        Functor((TDBComboBoxMeasureItemSink::TFunctor*)0, func)
#define TDBComboBoxMeasureItem_MFUNCTOR(object,memberFunc) \
        Functor((TDBComboBoxMeasureItemSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBComboBox&, SHORT, TRect, TOwnerDrawState>
                                                      TDBComboBoxDrawItemSource;
typedef TBdtEventSinkV4<TDBComboBox&, SHORT, TRect, TOwnerDrawState>
                                                      TDBComboBoxDrawItemSink;
#define TDBComboBoxDrawItem_FUNCTOR(func) \
        Functor((TDBComboBoxDrawItemSink::TFunctor*)0, func)
#define TDBComboBoxDrawItem_MFUNCTOR(object,memberFunc) \
        Functor((TDBComboBoxDrawItemSink::TFunctor*)0, object, memberFunc)


//------------------------------------------------------------------------------
// TDBEdit Functors
//------------------------------------------------------------------------------
typedef TBdtEventSourceV1<TDBEdit&> TDBEditNotifySource;
typedef TBdtEventSinkV1<TDBEdit&>   TDBEditNotifySink;
#define TDBEditNotify_FUNCTOR(func) \
        Functor((TDBEditNotifySink::TFunctor*)0, func)
#define TDBEditNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDBEditNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBEdit&, TVbxControl&, SHORT, SHORT> TDBEditDragSource;
typedef TBdtEventSinkV4<TDBEdit&, TVbxControl&, SHORT, SHORT>   TDBEditDragSink;
#define TDBEditDrag_FUNCTOR(func) Functor((TDBEditDragSink::TFunctor*)0, func)
#define TDBEditDrag_MFUNCTOR(object,memberFunc) \
        Functor((TDBEditDragSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBEdit&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBEditDragOverSource;
typedef TBdtEventSinkV5<TDBEdit&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBEditDragOverSink;
#define TDBEditDragOver_FUNCTOR(func) \
        Functor((TDBEditDragOverSink::TFunctor*)0, func)
#define TDBEditDragOver_MFUNCTOR(object,memberFunc) \
        Functor((TDBEditDragOverSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV3<TDBEdit&, SHORT*, TShiftState> TDBEditKeySource;
typedef TBdtEventSinkV3<TDBEdit&, SHORT*, TShiftState>   TDBEditKeySink;
#define TDBEditKey_FUNCTOR(func) Functor((TDBEditKeySink::TFunctor*)0, func)
#define TDBEditKey_MFUNCTOR(object,memberFunc) \
        Functor((TDBEditKeySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV2<TDBEdit&, SHORT> TDBEditKeyPressSource;
typedef TBdtEventSinkV2<TDBEdit&, SHORT>   TDBEditKeyPressSink;
#define TDBEditKeyPress_FUNCTOR(func) \
        Functor((TDBEditKeyPressSink::TFunctor*)0, func)
#define TDBEditKeyPress_MFUNCTOR(object,memberFunc) \
        Functor((TDBEditKeyPressSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBEdit&, TMouseButton, TShiftState, SHORT, SHORT>
                                                         TDBEditMouseSource;
typedef TBdtEventSinkV5<TDBEdit&, TMouseButton, TShiftState, SHORT, SHORT>
                                                         TDBEditMouseSink;
#define TDBEditMouse_FUNCTOR(func) \
        Functor((TDBEditMouseSink::TFunctor*)0, func)
#define TDBEditMouse_MFUNCTOR(object,memberFunc) \
        Functor((TDBEditMouseSink::TFunctor*)0, object, memberFunc)


//------------------------------------------------------------------------------
// TDBGrid Functors
//------------------------------------------------------------------------------
typedef TBdtEventSourceV1<TDBGrid&> TDBGridNotifySource;
typedef TBdtEventSinkV1<TDBGrid&>   TDBGridNotifySink;
#define TDBGridNotify_FUNCTOR(func) \
        Functor((TDBGridNotifySink::TFunctor*)0, func)
#define TDBGridNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDBGridNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBGrid&, TVbxControl&, SHORT, SHORT> TDBGridDragSource;
typedef TBdtEventSinkV4<TDBGrid&, TVbxControl&, SHORT, SHORT>   TDBGridDragSink;
#define TDBGridDrag_FUNCTOR(func) Functor((TDBGridDragSink::TFunctor*)0, func)
#define TDBGridDrag_MFUNCTOR(object,memberFunc) \
        Functor((TDBGridDragSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBGrid&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBGridDragOverSource;
typedef TBdtEventSinkV5<TDBGrid&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBGridDragOverSink;
#define TDBGridDragOver_FUNCTOR(func) \
        Functor((TDBGridDragOverSink::TFunctor*)0, func)
#define TDBGridDragOver_MFUNCTOR(object,memberFunc) \
        Functor((TDBGridDragOverSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV3<TDBGrid&, SHORT*, TShiftState> TDBGridKeySource;
typedef TBdtEventSinkV3<TDBGrid&, SHORT*, TShiftState>   TDBGridKeySink;
#define TDBGridKey_FUNCTOR(func) Functor((TDBGridKeySink::TFunctor*)0, func)
#define TDBGridKey_MFUNCTOR(object,memberFunc) \
        Functor((TDBGridKeySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV2<TDBGrid&, SHORT> TDBGridKeyPressSource;
typedef TBdtEventSinkV2<TDBGrid&, SHORT>   TDBGridKeyPressSink;
#define TDBGridKeyPress_FUNCTOR(func) \
        Functor((TDBGridKeyPressSink::TFunctor*)0, func)
#define TDBGridKeyPress_MFUNCTOR(object,memberFunc) \
        Functor((TDBGridKeyPressSink::TFunctor*)0, object, memberFunc)


//------------------------------------------------------------------------------
// TDBImage Functors
//------------------------------------------------------------------------------
typedef TBdtEventSourceV1<TDBImage&> TDBImageNotifySource;
typedef TBdtEventSinkV1<TDBImage&>   TDBImageNotifySink;
#define TDBImageNotify_FUNCTOR(func) \
        Functor((TDBImageNotifySink::TFunctor*)0, func)
#define TDBImageNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDBImageNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBImage&, TVbxControl&, SHORT, SHORT> TDBImageDragSource;
typedef TBdtEventSinkV4<TDBImage&, TVbxControl&, SHORT, SHORT>   TDBImageDragSink;
#define TDBImageDrag_FUNCTOR(func) Functor((TDBImageDragSink::TFunctor*)0, func)
#define TDBImageDrag_MFUNCTOR(object,memberFunc) \
        Functor((TDBImageDragSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBImage&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBImageDragOverSource;
typedef TBdtEventSinkV5<TDBImage&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBImageDragOverSink;
#define TDBImageDragOver_FUNCTOR(func) \
        Functor((TDBImageDragOverSink::TFunctor*)0, func)
#define TDBImageDragOver_MFUNCTOR(object,memberFunc) \
        Functor((TDBImageDragOverSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV3<TDBImage&, SHORT*, TShiftState> TDBImageKeySource;
typedef TBdtEventSinkV3<TDBImage&, SHORT*, TShiftState>   TDBImageKeySink;
#define TDBImageKey_FUNCTOR(func) Functor((TDBImageKeySink::TFunctor*)0, func)
#define TDBImageKey_MFUNCTOR(object,memberFunc) \
        Functor((TDBImageKeySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV2<TDBImage&, SHORT> TDBImageKeyPressSource;
typedef TBdtEventSinkV2<TDBImage&, SHORT>   TDBImageKeyPressSink;
#define TDBImageKeyPress_FUNCTOR(func) \
        Functor((TDBImageKeyPressSink::TFunctor*)0, func)
#define TDBImageKeyPress_MFUNCTOR(object,memberFunc) \
        Functor((TDBImageKeyPressSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBImage&, TMouseButton, TShiftState, SHORT, SHORT>
                                                         TDBImageMouseSource;
typedef TBdtEventSinkV5<TDBImage&, TMouseButton, TShiftState, SHORT, SHORT>
                                                         TDBImageMouseSink;
#define TDBImageMouse_FUNCTOR(func) \
        Functor((TDBImageMouseSink::TFunctor*)0, func)
#define TDBImageMouse_MFUNCTOR(object,memberFunc) \
        Functor((TDBImageMouseSink::TFunctor*)0, object, memberFunc)


//------------------------------------------------------------------------------
// TDBListBox Functors
//------------------------------------------------------------------------------
typedef TBdtEventSourceV1<TDBListBox&> TDBListBoxNotifySource;
typedef TBdtEventSinkV1<TDBListBox&>   TDBListBoxNotifySink;
#define TDBListBoxNotify_FUNCTOR(func) \
        Functor((TDBListBoxNotifySink::TFunctor*)0, func)
#define TDBListBoxNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDBListBoxNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBListBox&, TVbxControl&, SHORT, SHORT>
                                                          TDBListBoxDragSource;
typedef TBdtEventSinkV4<TDBListBox&, TVbxControl&, SHORT, SHORT>
                                                          TDBListBoxDragSink;
#define TDBListBoxDrag_FUNCTOR(func) \
        Functor((TDBListBoxDragSink::TFunctor*)0, func)
#define TDBListBoxDrag_MFUNCTOR(object,memberFunc) \
        Functor((TDBListBoxDragSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBListBox&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBListBoxDragOverSource;
typedef TBdtEventSinkV5<TDBListBox&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBListBoxDragOverSink;
#define TDBListBoxDragOver_FUNCTOR(func) \
        Functor((TDBListBoxDragOverSink::TFunctor*)0, func)
#define TDBListBoxDragOver_MFUNCTOR(object,memberFunc) \
        Functor((TDBListBoxDragOverSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV3<TDBListBox&, SHORT*, TShiftState> TDBListBoxKeySource;
typedef TBdtEventSinkV3<TDBListBox&, SHORT*, TShiftState>   TDBListBoxKeySink;
#define TDBListBoxKey_FUNCTOR(func) \
        Functor((TDBListBoxKeySink::TFunctor*)0, func)
#define TDBListBoxKey_MFUNCTOR(object,memberFunc) \
        Functor((TDBListBoxKeySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV2<TDBListBox&, SHORT> TDBListBoxKeyPressSource;
typedef TBdtEventSinkV2<TDBListBox&, SHORT>   TDBListBoxKeyPressSink;
#define TDBListBoxKeyPress_FUNCTOR(func) \
        Functor((TDBListBoxKeyPressSink::TFunctor*)0, func)
#define TDBListBoxKeyPress_MFUNCTOR(object,memberFunc) \
        Functor((TDBListBoxKeyPressSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV3<TDBListBox&, SHORT, SHORT*>
                                                   TDBListBoxMeasureItemSource;
typedef TBdtEventSinkV3<TDBListBox&, SHORT, SHORT*> TDBListBoxMeasureItemSink;
#define TDBListBoxMeasureItem_FUNCTOR(func) \
        Functor((TDBListBoxMeasureItemSink::TFunctor*)0, func)
#define TDBListBoxMeasureItem_MFUNCTOR(object,memberFunc) \
        Functor((TDBListBoxMeasureItemSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBListBox&, SHORT, TRect, TOwnerDrawState>
                                                      TDBListBoxDrawItemSource;
typedef TBdtEventSinkV4<TDBListBox&, SHORT, TRect, TOwnerDrawState>
                                                      TDBListBoxDrawItemSink;
#define TDBListBoxDrawItem_FUNCTOR(func) \
        Functor((TDBListBoxDrawItemSink::TFunctor*)0, func)
#define TDBListBoxDrawItem_MFUNCTOR(object,memberFunc) \
        Functor((TDBListBoxDrawItemSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBListBox&, TMouseButton, TShiftState, SHORT, SHORT>
                                                         TDBListBoxMouseSource;
typedef TBdtEventSinkV5<TDBListBox&, TMouseButton, TShiftState, SHORT, SHORT>
                                                         TDBListBoxMouseSink;
#define TDBListBoxMouse_FUNCTOR(func) \
        Functor((TDBListBoxMouseSink::TFunctor*)0, func)
#define TDBListBoxMouse_MFUNCTOR(object,memberFunc) \
        Functor((TDBListBoxMouseSink::TFunctor*)0, object, memberFunc)


//------------------------------------------------------------------------------
// TDBLookupCombo Functors
//------------------------------------------------------------------------------
typedef TBdtEventSourceV1<TDBLookupCombo&> TDBLookupComboNotifySource;
typedef TBdtEventSinkV1<TDBLookupCombo&>   TDBLookupComboNotifySink;
#define TDBLookupComboNotify_FUNCTOR(func) \
        Functor((TDBLookupComboNotifySink::TFunctor*)0, func)
#define TDBLookupComboNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDBLookupComboNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBLookupCombo&, TVbxControl&, SHORT, SHORT>
                                                       TDBLookupComboDragSource;
typedef TBdtEventSinkV4<TDBLookupCombo&, TVbxControl&, SHORT, SHORT>
                                                       TDBLookupComboDragSink;
#define TDBLookupComboDrag_FUNCTOR(func) \
        Functor((TDBLookupComboDragSink::TFunctor*)0, func)
#define TDBLookupComboDrag_MFUNCTOR(object,memberFunc) \
        Functor((TDBLookupComboDragSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBLookupCombo&, TVbxControl&, SHORT, SHORT, TDragState>
                                                   TDBLookupComboDragOverSource;
typedef TBdtEventSinkV5<TDBLookupCombo&, TVbxControl&, SHORT, SHORT, TDragState>
                                                   TDBLookupComboDragOverSink;
#define TDBLookupComboDragOver_FUNCTOR(func) \
        Functor((TDBLookupComboDragOverSink::TFunctor*)0, func)
#define TDBLookupComboDragOver_MFUNCTOR(object,memberFunc) \
        Functor((TDBLookupComboDragOverSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV3<TDBLookupCombo&, SHORT*, TShiftState>
                                                        TDBLookupComboKeySource;
typedef TBdtEventSinkV3<TDBLookupCombo&, SHORT*, TShiftState>
                                                        TDBLookupComboKeySink;
#define TDBLookupComboKey_FUNCTOR(func) \
        Functor((TDBLookupComboKeySink::TFunctor*)0, func)
#define TDBLookupComboKey_MFUNCTOR(object,memberFunc) \
        Functor((TDBLookupComboKeySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV2<TDBLookupCombo&, SHORT> TDBLookupComboKeyPressSource;
typedef TBdtEventSinkV2<TDBLookupCombo&, SHORT>   TDBLookupComboKeyPressSink;
#define TDBLookupComboKeyPress_FUNCTOR(func) \
        Functor((TDBLookupComboKeyPressSink::TFunctor*)0, func)
#define TDBLookupComboKeyPress_MFUNCTOR(object,memberFunc) \
        Functor((TDBLookupComboKeyPressSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBLookupCombo&, TMouseButton, TShiftState, SHORT, SHORT>
                                                      TDBLookupComboMouseSource;
typedef TBdtEventSinkV5<TDBLookupCombo&, TMouseButton, TShiftState, SHORT, SHORT>
                                                      TDBLookupComboMouseSink;
#define TDBLookupComboMouse_FUNCTOR(func) \
        Functor((TDBLookupComboMouseSink::TFunctor*)0, func)
#define TDBLookupComboMouse_MFUNCTOR(object,memberFunc) \
        Functor((TDBLookupComboMouseSink::TFunctor*)0, object, memberFunc)


//------------------------------------------------------------------------------
// TDBLookupList Functors
//------------------------------------------------------------------------------
typedef TBdtEventSourceV1<TDBLookupList&> TDBLookupListNotifySource;
typedef TBdtEventSinkV1<TDBLookupList&>   TDBLookupListNotifySink;
#define TDBLookupListNotify_FUNCTOR(func) \
        Functor((TDBLookupListNotifySink::TFunctor*)0, func)
#define TDBLookupListNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDBLookupListNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBLookupList&, TVbxControl&, SHORT, SHORT>
                                                       TDBLookupListDragSource;
typedef TBdtEventSinkV4<TDBLookupList&, TVbxControl&, SHORT, SHORT>
                                                       TDBLookupListDragSink;
#define TDBLookupListDrag_FUNCTOR(func) \
        Functor((TDBLookupListDragSink::TFunctor*)0, func)
#define TDBLookupListDrag_MFUNCTOR(object,memberFunc) \
        Functor((TDBLookupListDragSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBLookupList&, TVbxControl&, SHORT, SHORT, TDragState>
                                                   TDBLookupListDragOverSource;
typedef TBdtEventSinkV5<TDBLookupList&, TVbxControl&, SHORT, SHORT, TDragState>
                                                   TDBLookupListDragOverSink;
#define TDBLookupListDragOver_FUNCTOR(func) \
        Functor((TDBLookupListDragOverSink::TFunctor*)0, func)
#define TDBLookupListDragOver_MFUNCTOR(object,memberFunc) \
        Functor((TDBLookupListDragOverSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV3<TDBLookupList&, SHORT*, TShiftState>
                                                        TDBLookupListKeySource;
typedef TBdtEventSinkV3<TDBLookupList&, SHORT*, TShiftState>
                                                        TDBLookupListKeySink;
#define TDBLookupListKey_FUNCTOR(func) \
        Functor((TDBLookupListKeySink::TFunctor*)0, func)
#define TDBLookupListKey_MFUNCTOR(object,memberFunc) \
        Functor((TDBLookupListKeySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV2<TDBLookupList&, SHORT> TDBLookupListKeyPressSource;
typedef TBdtEventSinkV2<TDBLookupList&, SHORT>   TDBLookupListKeyPressSink;
#define TDBLookupListKeyPress_FUNCTOR(func) \
        Functor((TDBLookupListKeyPressSink::TFunctor*)0, func)
#define TDBLookupListKeyPress_MFUNCTOR(object,memberFunc) \
        Functor((TDBLookupListKeyPressSink::TFunctor*)0, object, memberFunc)


//------------------------------------------------------------------------------
// TDBMemo Functors
//------------------------------------------------------------------------------
typedef TBdtEventSourceV1<TDBMemo&> TDBMemoNotifySource;
typedef TBdtEventSinkV1<TDBMemo&>   TDBMemoNotifySink;
#define TDBMemoNotify_FUNCTOR(func) \
        Functor((TDBMemoNotifySink::TFunctor*)0, func)
#define TDBMemoNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDBMemoNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBMemo&, TVbxControl&, SHORT, SHORT> TDBMemoDragSource;
typedef TBdtEventSinkV4<TDBMemo&, TVbxControl&, SHORT, SHORT>   TDBMemoDragSink;
#define TDBMemoDrag_FUNCTOR(func) Functor((TDBMemoDragSink::TFunctor*)0, func)
#define TDBMemoDrag_MFUNCTOR(object,memberFunc) \
        Functor((TDBMemoDragSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBMemo&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBMemoDragOverSource;
typedef TBdtEventSinkV5<TDBMemo&, TVbxControl&, SHORT, SHORT, TDragState>
                                                      TDBMemoDragOverSink;
#define TDBMemoDragOver_FUNCTOR(func) \
        Functor((TDBMemoDragOverSink::TFunctor*)0, func)
#define TDBMemoDragOver_MFUNCTOR(object,memberFunc) \
        Functor((TDBMemoDragOverSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV3<TDBMemo&, SHORT*, TShiftState> TDBMemoKeySource;
typedef TBdtEventSinkV3<TDBMemo&, SHORT*, TShiftState>   TDBMemoKeySink;
#define TDBMemoKey_FUNCTOR(func) Functor((TDBMemoKeySink::TFunctor*)0, func)
#define TDBMemoKey_MFUNCTOR(object,memberFunc) \
        Functor((TDBMemoKeySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV2<TDBMemo&, SHORT> TDBMemoKeyPressSource;
typedef TBdtEventSinkV2<TDBMemo&, SHORT>   TDBMemoKeyPressSink;
#define TDBMemoKeyPress_FUNCTOR(func) \
        Functor((TDBMemoKeyPressSink::TFunctor*)0, func)
#define TDBMemoKeyPress_MFUNCTOR(object,memberFunc) \
        Functor((TDBMemoKeyPressSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBMemo&, TMouseButton, TShiftState, SHORT, SHORT>
                                                         TDBMemoMouseSource;
typedef TBdtEventSinkV5<TDBMemo&, TMouseButton, TShiftState, SHORT, SHORT>
                                                         TDBMemoMouseSink;
#define TDBMemoMouse_FUNCTOR(func) \
        Functor((TDBMemoMouseSink::TFunctor*)0, func)
#define TDBMemoMouse_MFUNCTOR(object,memberFunc) \
        Functor((TDBMemoMouseSink::TFunctor*)0, object, memberFunc)


//------------------------------------------------------------------------------
// TDBNavigator Functors
//------------------------------------------------------------------------------
typedef TBdtEventSourceV2<TDBNavigator&, TNavigateBtn> TDBNavigatorClickSource;
typedef TBdtEventSinkV2<TDBNavigator&, TNavigateBtn>   TDBNavigatorClickSink;
#define TDBNavigatorClick_FUNCTOR(func) \
        Functor((TDBNavigatorClickSink::TFunctor*)0, func)
#define TDBNavigatorClick_MFUNCTOR(object,memberFunc) \
        Functor((TDBNavigatorClickSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV1<TDBNavigator&> TDBNavigatorNotifySource;
typedef TBdtEventSinkV1<TDBNavigator&>   TDBNavigatorNotifySink;
#define TDBNavigatorNotify_FUNCTOR(func) \
        Functor((TDBNavigatorNotifySink::TFunctor*)0, func)
#define TDBNavigatorNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDBNavigatorNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBNavigator&, TVbxControl&, SHORT, SHORT>
                                                         TDBNavigatorDragSource;
typedef TBdtEventSinkV4<TDBNavigator&, TVbxControl&, SHORT, SHORT>
                                                         TDBNavigatorDragSink;
#define TDBNavigatorDrag_FUNCTOR(func) \
        Functor((TDBNavigatorDragSink::TFunctor*)0, func)
#define TDBNavigatorDrag_MFUNCTOR(object,memberFunc) \
        Functor((TDBNavigatorDragSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBNavigator&, TVbxControl&, SHORT, SHORT, TDragState>
                                                     TDBNavigatorDragOverSource;
typedef TBdtEventSinkV5<TDBNavigator&, TVbxControl&, SHORT, SHORT, TDragState>
                                                     TDBNavigatorDragOverSink;
#define TDBNavigatorDragOver_FUNCTOR(func) \
        Functor((TDBNavigatorDragOverSink::TFunctor*)0, func)
#define TDBNavigatorDragOver_MFUNCTOR(object,memberFunc) \
        Functor((TDBNavigatorDragOverSink::TFunctor*)0, object, memberFunc)


//------------------------------------------------------------------------------
// TDBRadioGroup Functors
//------------------------------------------------------------------------------
typedef TBdtEventSourceV1<TDBRadioGroup&> TDBRadioGroupNotifySource;
typedef TBdtEventSinkV1<TDBRadioGroup&>   TDBRadioGroupNotifySink;
#define TDBRadioGroupNotify_FUNCTOR(func) \
        Functor((TDBRadioGroupNotifySink::TFunctor*)0, func)
#define TDBRadioGroupNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDBRadioGroupNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBRadioGroup&, TVbxControl&, SHORT, SHORT>
                                                        TDBRadioGroupDragSource;
typedef TBdtEventSinkV4<TDBRadioGroup&, TVbxControl&, SHORT, SHORT>
                                                        TDBRadioGroupDragSink;
#define TDBRadioGroupDrag_FUNCTOR(func) \
        Functor((TDBRadioGroupDragSink::TFunctor*)0, func)
#define TDBRadioGroupDrag_MFUNCTOR(object,memberFunc) \
        Functor((TDBRadioGroupDragSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBRadioGroup&, TVbxControl&, SHORT, SHORT, TDragState>
                                                    TDBRadioGroupDragOverSource;
typedef TBdtEventSinkV5<TDBRadioGroup&, TVbxControl&, SHORT, SHORT, TDragState>
                                                    TDBRadioGroupDragOverSink;
#define TDBRadioGroupDragOver_FUNCTOR(func) \
        Functor((TDBRadioGroupDragOverSink::TFunctor*)0, func)
#define TDBRadioGroupDragOver_MFUNCTOR(object,memberFunc) \
        Functor((TDBRadioGroupDragOverSink::TFunctor*)0, object, memberFunc)


//------------------------------------------------------------------------------
// TDBText Functors
//------------------------------------------------------------------------------
typedef TBdtEventSourceV1<TDBText&> TDBTextNotifySource;
typedef TBdtEventSinkV1<TDBText&>   TDBTextNotifySink;
#define TDBTextNotify_FUNCTOR(func) \
        Functor((TDBTextNotifySink::TFunctor*)0, func)
#define TDBTextNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDBTextNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV4<TDBText&, TVbxControl&, SHORT, SHORT> TDBTextDragSource;
typedef TBdtEventSinkV4<TDBText&, TVbxControl&, SHORT, SHORT>   TDBTextDragSink;
#define TDBTextDrag_FUNCTOR(func) Functor((TDBTextDragSink::TFunctor*)0, func)
#define TDBTextDrag_MFUNCTOR(object,memberFunc) \
        Functor((TDBTextDragSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBText&, TVbxControl&, SHORT, SHORT, TDragState>
                                                    TDBTextDragOverSource;
typedef TBdtEventSinkV5<TDBText&, TVbxControl&, SHORT, SHORT, TDragState>
                                                    TDBTextDragOverSink;
#define TDBTextDragOver_FUNCTOR(func) \
        Functor((TDBTextDragOverSink::TFunctor*)0, func)
#define TDBTextDragOver_MFUNCTOR(object,memberFunc) \
        Functor((TDBTextDragOverSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV5<TDBText&, TMouseButton, TShiftState, SHORT, SHORT>
                                                             TDBTextMouseSource;
typedef TBdtEventSinkV5<TDBText&, TMouseButton, TShiftState, SHORT, SHORT>
                                                             TDBTextMouseSink;
#define TDBTextMouse_FUNCTOR(func) Functor((TDBTextMouseSink::TFunctor*)0, func)
#define TDBTextMouse_MFUNCTOR(object,memberFunc) \
        Functor((TDBTextMouseSink::TFunctor*)0, object, memberFunc)


#ifdef __OWL_VBXCTL_H
//----------------------------------------------------------------------
// Event Dispatchers
//----------------------------------------------------------------------
int32 _OWLFUNC  // NotifyEvent (OnClick, OnDblClick, OnChange)
NotifyEvent_Dispatch(GENERIC& generic, void (GENERIC::*pmf)(), uint, int32);

int32 _OWLFUNC // DragEvent (OnDragDrop, OnEndDrag)
DragEvent_Dispatch(GENERIC&, void (GENERIC::*)(TVbxControl&, SHORT, SHORT), uint, int32);

int32 _OWLFUNC // DragOverEvent (OnDragOver)
DragOver_Dispatch(GENERIC&, void (GENERIC::*)(TVbxControl&, SHORT, SHORT, TDragState), uint, int32);

int32 _OWLFUNC // KeyEvent (OnKeyDown, OnKeyUp)
KeyEvent_Dispatch(GENERIC&, void (GENERIC::*)(SHORT*, TShiftState), uint, int32);

int32 _OWLFUNC // KeyPress (OnKeyPress)
KeyPress_Dispatch(GENERIC&, void (GENERIC::*)(SHORT), uint, int32);

int32 _OWLFUNC // MouseEvent (OnMouseDown, OnMouseMove, OnMouseDown)
MouseEvent_Dispatch(GENERIC&, void (GENERIC::*)(TMouseButton, TShiftState, SHORT, SHORT), uint, int32);

int32 _OWLFUNC
DrawItem_Dispatch(GENERIC& generic, void (GENERIC::*pmf)(SHORT, TRect, TOwnerDrawState), uint, int32);

int32 _OWLFUNC
MeasureItem_Dispatch(GENERIC& generic, void (GENERIC::*pmf)(SHORT, SHORT*), uint, int32);

int32 _OWLFUNC // NavClick (OnClick)
NavClick_Dispatch(GENERIC&, void (GENERIC::*)(TNavigateBtn), uint, int32);

//----------------------------------------------------------------------
// Event Response Table Macros
//----------------------------------------------------------------------
#define EV_VBXEVENT_NAVCLICK \
 {WM_VBXBASE+Event_TDBControl_Click,0,(TAnyDispatcher)::NavClick_Dispatch}

#define EV_VBXEVENT_NAVRESIZE \
 {WM_VBXBASE+Event_TDBNavigator_ReSize,0,(TAnyDispatcher)::NotifyEvent_Dispatch}

#define EV_VBXEVENT_CLICK \
  {WM_VBXBASE+Event_TDBControl_Click,0,(TAnyDispatcher)::NotifyEvent_Dispatch}

#define EV_VBXEVENT_DRAGDROP \
  {WM_VBXBASE+Event_TDBControl_DragDrop,0,(TAnyDispatcher)::DragEvent_Dispatch}

#define EV_VBXEVENT_DRAGOVER \
  {WM_VBXBASE+Event_TDBControl_DragOver,0,(TAnyDispatcher)::DragOver_Dispatch}

#define EV_VBXEVENT_ENDDRAG \
  {WM_VBXBASE+Event_TDBControl_EndDrag,0,(TAnyDispatcher)::DragEvent_Dispatch}

#define EV_VBXEVENT_CHANGE( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::NotifyEvent_Dispatch}

#define EV_VBXEVENT_DBLCLICK( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::NotifyEvent_Dispatch}

#define EV_VBXEVENT_ENTER( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::NotifyEvent_Dispatch}

#define EV_VBXEVENT_EXIT( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::NotifyEvent_Dispatch}

#define EV_VBXEVENT_KEYDOWN( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::KeyEvent_Dispatch}

#define EV_VBXEVENT_KEYPRESS( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::KeyPress_Dispatch}

#define EV_VBXEVENT_KEYUP( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::KeyEvent_Dispatch}

#define EV_VBXEVENT_KEYUP( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::KeyEvent_Dispatch}

#define EV_VBXEVENT_MOUSEDOWN( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::MouseEvent_Dispatch}

#define EV_VBXEVENT_MOUSEMOVE( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::MouseEvent_Dispatch}

#define EV_VBXEVENT_MOUSEUP( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::MouseEvent_Dispatch}

#define EV_VBXEVENT_DRAWITEM( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::DrawItem_Dispatch}

#define EV_VBXEVENT_MEASUREITEM( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::MeasureItem_Dispatch}

#define EV_VBXEVENT_DROPDOWN( index ) \
  {WM_VBXBASE+index,0,(TAnyDispatcher)::NotifyEvent_Dispatch}
#endif __OWL_VBXCTL_H

#endif DBEVENT_H_
