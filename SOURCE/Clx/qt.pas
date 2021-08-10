{*****************************************************************************} 
{                                                                              
{ Pascal Binding for Qt Library                                                
{                                                                               
{ Copyright (c) 2000, 2001 Borland Software Corporation                        
{                                                                                          
{ This file may be distributed and/or modified under the terms of the GNU    
{ General Public License version 2 as published by the Free Software           
{ Foundation and appearing at http://www.borland.com/kylix/gpl.html.           
{                                                                              
{ Licensees holding a valid Borland No-Nonsense license may use this file       
{ in accordance with the license and appearing in the file license.txt         
{                                                                                          
{*****************************************************************************} 
 
unit Qt; 
 
interface 
 
uses Types, SysUtils; 
 
{$HPPEMIT '#pragma link "QtIntf.lib"'} 
 
{$MINENUMSIZE 4} 
 
type
  PPByte = ^PByte;
  PInteger = ^Integer;
  PCardinal = ^Cardinal;
  uint = Cardinal;
  PMsg = Pointer;//^tagMSG;

  PSizePolicy = ^TSizePolicy;
  TSizePolicy = packed record
    Data: Word;
  end;

  PPointArray = ^TPointArray;
  TPointArray = array of TPoint;

  PIntArray = ^TIntArray;
  TIntArray = array of Integer;
  
  WId = Cardinal;
  PWId = ^WId;
  WFlags = Integer;
  HANDLE = type Integer;
  {$IFDEF MSWINDOWS} {$EXTERNALSYM HANDLE} {$ENDIF}
  HCURSOR = type HANDLE;
  {$IFDEF MSWINDOWS} {$EXTERNALSYM HCURSOR} {$ENDIF}
  HPALETTE = type HANDLE;
  {$IFDEF MSWINDOWS} {$EXTERNALSYM HPALETTE} {$ENDIF}
  HFONT = type HANDLE;
  {$IFDEF MSWINDOWS} {$EXTERNALSYM HFONT} {$ENDIF}
  HDC = type HANDLE;
  {$IFDEF MSWINDOWS} {$EXTERNALSYM HDC} {$ENDIF}
  HBITMAP = type HANDLE;
  {$IFDEF MSWINDOWS} {$EXTERNALSYM HBITMAP} {$ENDIF}
  HRGN = type HANDLE;
  {$IFDEF MSWINDOWS} {$EXTERNALSYM HRGN} {$ENDIF}
  QRgb = type Cardinal;
  QRgbH = ^QRgb;
  QCOORD = type Integer;

  QHookH = TMethod;

const
  NullHook: QHookH = (Code: nil; Data: nil);

type
  QAsyncIOH = class(TObject) end;
        QDataSinkH = class(QAsyncIOH) end;
        QDataSourceH = class(QAsyncIOH) end;
                QIODeviceSourceH = class(QDataSourceH) end;
  QBitValH = class(TObject) end;
  QCharH = class(TObject) end;
  QCollectionH = class(TObject) end;
        QGCacheH = class(QCollectionH) end;
                QAsciiCacheH = class(QGCacheH) end;
                QCacheH = class(QGCacheH) end;
                QIntCacheH = class(QGCacheH) end;
        QGDictH = class(QCollectionH) end;
                QAsciiDict = class(QGDictH) end;
                QDictH = class(QGDictH) end;
                QIntDictH = class(QGDictH) end;
                QPtrDictH = class(QGDictH) end;
        QGListH = class(QCollectionH) end;
                QListH = class(QGListH) end;
                       QWidgetListH = class(QListH) end;
                       QStrListH = class(QListH) end;
                                QStrIListH = class(QStrListH) end;
                QQueueH = class(QGListH) end;
                QStackH = class(QGListH) end;
  QColorH = class(TObject) end;
  QColorGroupH = class(TObject) end;
  QConnectionH = class(TObject) end;
  QCursorH = class(TObject) end;
  QDataStreamH = class(TObject) end;
  QDateH = class(TObject) end;
  QDateTimeH = class(TObject) end;
  QDirH = class(TObject) end;
  QDropSiteH = class(TObject) end;
  QFileInfoH = class(TObject) end;
  QFocusDataH = class(TObject) end;
  QFontH = class(TObject) end;
  QFontDatabaseH = class(TObject) end;
  QFontInfoH = class(TObject) end;
  QFontMetricsH = class(TObject) end;
  QGArrayH = class(TObject) end;
        QArrayH = class(QGArrayH) end;
                QPointArrayH = class(QArrayH) end;
  QGCacheIteratorH = class(TObject) end;
        QAsciiCacheIteratorH = class(QGCacheIteratorH) end;
        QCacheIteratorH = class(QGCacheIteratorH) end;
        QIntCacheIteratorH = class(QGCacheIteratorH) end;
  QGDictIteratorH = class(TObject) end;
        QAsciiDictIteratorH = class(QGDictIteratorH) end;
        QDictIteratorH = class(QGDictIteratorH) end;
        QIntDictIteratorH = class(QGDictIteratorH) end;
        QPtrDictIteratorH = class(QGDictIteratorH) end;
  QGLH = class(TObject) end;
        QGLContextH = class(QGLH) end;
        QGLFormatH = class(QGLH) end;
  QGListIteratorH = class(TObject) end;
        QListIteratorH = class(QGListIteratorH) end;
  QIconDragItemH = class(TObject) end;
  QIconSetH = class(TObject) end;
  QImageH = class(TObject) end;
  QImageConsumerH = class(TObject) end;
  QImageDecoderH = class(TObject) end;
  QImageFormatH = class(TObject) end;
  QImageFormatTypeH = class(TObject) end;
  QImageIOH = class(TObject) end;
  QIODeviceH = class(TObject) end;
        QBufferH = class(QIODeviceH) end;
        QFileH = class(QIODeviceH) end;
        QSocketDeviceH = class(QIODeviceH) end;
        QClxIODeviceH = class(QIODeviceH) end;
  QLayoutItemH = class(TObject) end;
        QSpacerItemH = class(QLayoutItemH) end;
        QWidgetItemH = class(QLayoutItemH) end;
  QLayoutIteratorH = class(TObject) end;
  QListBoxItemH = class(TObject) end;
        QListBoxPixmapH = class(QListBoxItemH) end;
        QListBoxTextH = class(QListBoxItemH) end;
                QClxListBoxItemH = class(QListBoxTextH) end;
  QListViewItemIteratorH = class(TObject) end;
  QLNodeH = class(TObject) end;
  QMapH = class(TObject) end;
  QMapConstIteratorH = class(TObject) end;
  QMapIteratorH = class(TObject) end;
  QMenuDataH = class(TObject) end;
  QMimeSourceH = class(TObject) end;
  	QClxMimeSourceH = class(QMimeSourceH) end;
  QMimeSourceFactoryH = class(TObject) end;
  	QClxMimeSourceFactoryH = class(QMimeSourceFactoryH) end;
  QMovieH = class(TObject) end;
  QNPluginH = class(TObject) end;
  QNPStreamH = class(TObject) end;
  QPaintDeviceH = class(TObject) end;
        QPictureH = class(QPaintDeviceH) end;
        QPixmapH = class(QPaintDeviceH) end;
                QBitmapH = class(QPixmapH) end;
        QPrinterH = class(QPaintDeviceH) end;
  QPaintDeviceMetricsH = class(TObject) end;
  QPaletteH = class(TObject) end;
  QPixmapCacheH = class(TObject) end;
  QPointH = class(TObject) end;
  QRangeControlH = class(TObject) end;
  QRectH = class(TObject) end;
  QRegExpH = class(TObject) end;
  QRegionH = class(TObject) end;
  QSharedH = class(TObject) end;
    QGLayoutIteratorH = class(QSharedH) end;
  QSimpleRichTextH = class(TObject) end;
  QSizeH = class(TObject) end;
  QSizePolicyH = class(TObject) end;
  QSocketAddressH = class(TObject) end;
  QStringH = class(TObject) end;
        QConstStringH = class(QStringH) end;
  QtH = class(TObject) end;
        QBrushH = class(QtH) end;
        QEventH = class(QtH) end;
                QChildEventH = class(QEventH) end;
                QCloseEventH = class(QEventH) end;
                QCustomEventH = class(QEventH) end;
                QDragLeaveEventH = class(QEventH) end;
                QDragResponseEventH = class(QEventH) end;
                QDropEventH = class(QEventH) end;
                        QDragMoveEventH = class(QDropEventH) end;
                                QDragEnterEventH = class(QDragMoveEventH) end;
                QFocusEventH = class(QEventH) end; 
                QHideEventH = class(QEventH) end;
                QKeyEventH = class(QEventH) end;
                QMouseEventH = class(QEventH) end;
                QMoveEventH = class(QEventH) end;
                QPaintEventH = class(QEventH) end;
                QResizeEventH = class(QEventH) end;
                QShowEventH = class(QEventH) end;
                QTimerEventH = class(QEventH) end;
                QWheelEventH = class(QEventH) end;
	QIconViewItemH = class(QtH) end;
                QClxIconViewItemH = class(QIconViewItemH) end;
        QListViewItemH = class(QtH) end;
                QClxListViewItemH = class(QListViewItemH) end;
                QCheckListItemH = class(QListViewItemH) end;
                        QClxCheckListItemH = class(QCheckListItemH) end;                
        QObjectH = class(QtH) end;
                QAccelH = class(QObjectH) end;
                QApplicationH = class(QObjectH) end;
			QClxApplicationH = class(QApplicationH) end;
                        QXtApplicationH = class(QApplicationH) end;
                QClipboardH = class(QObjectH) end;
                QDataPumpH = class(QObjectH) end;
                QDragObjectH = class(QObjectH) end;
                	QClxDragObjectH = class(QDragObjectH) end;
                	QIconDragH = class(QDragObjectH) end;
                        QImageDragH = class(QDragObjectH) end;
                        QStoredDragH = class(QDragObjectH) end;
                                QUriDragH = class(QStoredDragH) end;
                                QColorDragH = class(QStoredDragH) end;
                        QTextDragH = class(QDragObjectH) end;
                QFileIconProviderH = class(QObjectH) end;
                QClxFileIconProviderH = class(QObjectH) end;
                QLayoutH = class(QObjectH) end;
                        QBoxLayoutH = class(QLayoutH) end;
                                QHBoxLayoutH = class(QBoxLayoutH) end;
                                QVBoxLayoutH = class(QBoxLayoutH) end; 
                        QGridLayoutH = class(QLayoutH) end;
                QNPInstanceH = class(QObjectH) end;
                QServerSocketH = class(QObjectH) end;
                QSessionManagerH = class(QObjectH) end;
                QSignalH = class(QObjectH) end;
                QSignalMapperH = class(QObjectH) end;
                QSocketH = class(QObjectH) end;
                QSocketNotifierH = class(QObjectH) end;
                QStyleH = class(QObjectH) end;
                        QCommonStyleH = class(QStyleH) end;
                                QMotifStyleH = class(QCommonStyleH) end;
                                        QCDEStyleH = class(QMotifStyleH) end;
                                QWindowsStyleH = class(QCommonStyleH) end;
                                        QPlatinumStyleH = class(QWindowsStyleH) end;
                                QClxStyleH = class(QStyleH) end;
                QStyleSheetH = class(QObjectH) end;
                QTimerH = class(QObjectH) end;
                QToolTipGroupH = class(QObjectH) end;
                QTranslatorH = class(QObjectH) end;
                        QAppTranslatorH = class(QTranslatorH) end;
                QValidatorH = class(QObjectH) end;
                        QDoubleValidatorH = class(QValidatorH) end;
                        QIntValidatorH = class(QValidatorH) end;
                QWidgetH = class(QObjectH) end;
                        QButtonH = class(QWidgetH) end;
                                QCheckBoxH = class(QButtonH) end;
                                QPushButtonH = class(QButtonH) end;
                                        QClxBitBtnH = class(QPushButtonH) end;
                                QRadioButtonH = class(QButtonH) end;
                                QToolButtonH = class(QButtonH) end;
                        QOpenWidgetH = class(QWidgetH);
                QComboBoxH = class(QWidgetH) end;
			QOpenComboBoxH = class(QComboBoxH) end;
                QDialogH = class(QWidgetH) end;
                        QColorDialogH = class(QDialogH) end;
                        QFileDialogH = class(QDialogH) end;
                        QClxFileDialogH = class(QDialogH) end;
                        QFontDialogH = class(QDialogH) end;
                        QMessageBoxH = class(QDialogH) end;
                        QTabDialogH = class(QDialogH) end;
                        QWizardH = class(QDialogH) end;
                        QPrintDialogH = class(QDialogH) end;
                        QTranslatorDialogH = class(QDialogH) end;
                QFrameH = class(QWidgetH) end;
                        QGridH = class(QFrameH) end;
                        QGroupBoxH = class(QFrameH) end;
				QButtonGroupH = class(QGroupBoxH) end;
					QHButtonGroupH = class(QButtonGroupH) end;
                                        QVButtonGroupH = class(QButtonGroupH) end;
                                QHGroupBoxH = class(QGroupBoxH) end;
                                QVGroupBoxH = class(QGroupBoxH) end;
                        QHBoxH = class(QFrameH) end;
                                QVBoxH = class(QHBoxH) end;
                        QLCDNumberH = class(QFrameH) end;
                        QLabelH = class(QFrameH) end;
                        QMenuBarH = class(QFrameH) end;
                        QPopupMenuH = class(QFrameH) end;
                        QProgressBarH = class(QFrameH) end;
                        QScrollViewH = class(QFrameH) end;
				QOpenScrollViewH = class(QScrollViewH) end;
                		QIconViewH = class(QScrollViewH) end;
                                QListBoxH = class(QScrollViewH) end;
                                QListViewH = class(QScrollViewH) end;
                                QTextViewH = class(QScrollViewH) end;
                                        QTextEditH = class(QTextViewH) end;
                                        QTextBrowserH = class(QTextViewH) end;
                        QSpinBoxH = class(QFrameH) end;
                          QClxSpinBoxH = class(QSpinBoxH) end;
                        QSplitterH = class(QFrameH) end;
                        QTableViewH = class(QFrameH) end;
                                QOpenTableViewH = class(QTableViewH) end;
                                        QMultiLineEditH = class(QOpenTableViewH) end;
                                               QOpenMultiLineEditH = class(QMultiLineEditH) end;
                        QWidgetStackH = class(QFrameH) end;
                QGLWidgetH = class(QWidgetH) end;
                QHeaderH = class(QWidgetH) end;
                QLineEditH = class(QWidgetH) end;
                        QClxLineEditH = class(QLineEditH) end;
                        QRenameEditH = class(QLineEditH) end;
                QMainWindowH = class(QWidgetH) end;
                QNPWidgetH = class(QWidgetH) end;
                QScrollBarH = class(QWidgetH) end;
                QSemiModalH = class(QWidgetH) end;
                        QProgressDialogH = class(QSemiModalH) end;
                QSizeGripH = class(QWidgetH) end;
                QSliderH = class(QWidgetH) end;
                  QClxSliderH = class(QSliderH) end;
                QStatusBarH = class(QWidgetH) end;
                QTabBarH = class(QWidgetH) end;
                QTabWidgetH = class(QWidgetH) end;
                QToolBarH = class(QWidgetH) end;
                QXtWidgetH = class(QWidgetH) end;
                QWorkspaceH = class(QWidgetH) end;
                	QClxWorkspaceH = class(QWorkspaceH) end;
        QPainterH = class(QtH) end;
        QPenH = class(QtH) end;
        QStyleSheetItemH = class(QtH) end;
        QToolTipH = class(QtH) end;
        QWhatsThisH = class(QtH) end;
  QTabH = class(TObject) end;
  QTextCodecH = class(TObject) end;
  QTextDecoderH = class(TObject) end;
  QTextEncoderH = class(TObject) end;
  QTextStreamH = class(TObject) end;
        QTextIStreamH = class(QTextStreamH) end;
        QTextOStreamH = class(QTextStreamH) end;
  QTimeH = class(TObject) end;
  QTranslatorMessageH = class(TObject) end;
  QValueListH = class(TObject) end;
  QValueListConstIteratorH = class(TObject) end;
  QValueListIteratorH = class(TObject) end;
  QWMatrixH = class(TObject) end;
  QWidgetMapperH = class(TObject) end;
  QStringListH = class(TObject) end;
        QOpenStringListH = class(QStringListH) end;
  QFileInfoListH = class(TObject) end;
  QBitArrayH = class(TObject) end;
  QByteArrayH = class(TObject) end;
  QMapPrivateBaseH = class(TObject) end;
  QMapNodeBaseH = class(TObject) end;
  QMenuItemH = class(TObject) end;
  QMetaObjectH = class(TObject) end;
  QObjectListH = class(TObject) end;
  QTextNodeH = class(TObject) end;
  QPNGImageWriterH = class(TObject) end;
        QPNGImagePackerH = class(QPNGImageWriterH) end;
  QFilePreviewH = class(TObject) end;
  QClxFilePreviewH = class(TObject) end;
  QImageTextKeyLangH = class(TObject) end;
  QCustomMenuItemH = class(TObject) end;
  QClxStyleHooksH = class(TObject) end;
  QClxListBoxHooksH = class(TObject) end;
  QClxListViewHooksH = class(TObject) end;
  QClxIconViewHooksH = class(TObject) end;

  QObject_hookH = class(TObject) end;
    QClxWorkspace_hookH = class(QObject_hookH) end;
    QAccel_hookH = class(QObject_hookH) end;
    QToolTip_hookH = class(QObject_hookH) end;
      QWidget_hookH = class(QObject_hookH) end;
	QButton_hookH = class(QWidget_hookH) end;
	  QCheckBox_hookH = class(QButton_hookH) end;
          QPushButton_hookH = class(QButton_hookH) end;
          QRadioButton_hookH = class(QButton_hookH) end;
          QToolButton_hookH = class(QButton_hookH) end;
	QComboBox_hookH = class(QWidget_hookH) end;
	QHeader_hookH = class(QWidget_hookH) end;
	QLineEdit_hookH = class(QWidget_hookH) end;
	  QRenameEdit_hookH = class(QLineEdit_hookH) end;
	QMainWindow_hookH = class(QWidget_hookH) end;
	QSlider_hookH = class(QWidget_hookH) end;
	QTabBar_hookH = class(QWidget_hookH) end;
	QSpinBox_hookH = class(QWidget_hookH) end;
	QTabWidget_hookH = class(QWidget_hookH) end;
	QFrame_hookH = class(QWidget_hookH) end;
	  QGroupBox_hookH = class(QFrame_hookH) end;
	    QButtonGroup_hookH = class(QGroupBox_hookH) end;
	      QHButtonGroup_hookH = class(QButtonGroup_hookH) end;
              QVButtonGroup_hookH = class(QButtonGroup_hookH) end;
	    QHGroupBox_hookH = class(QGroupBox_hookH) end;
            QVGroupBox_hookH = class(QGroupBox_hookH) end;
	  QGrid_hookH = class(QFrame_hookH) end;
	  QLCDNumber_hookH = class(QFrame_hookH) end;
	  QPopupMenu_hookH = class(QFrame_hookH) end;
	  QMenuBar_hookH = class(QFrame_hookH) end;
	  QWidgetStack_hookH = class(QFrame_hookH) end;
	  QTableView_hookH = class(QFrame_hookH) end;
	    QMultiLineEdit_hookH = class(QTableView_hookH) end;
	    QWellArray_hookH = class(QTableView_hookH) end;
	  QScrollView_hookH = class(QFrame_hookH) end;
            QIconView_hookH = class(QScrollView_hookH) end;
	    QListBox_hookH = class(QScrollView_hookH) end;
	      QFileListBox_hookH = class(QListBox_hookH) end;
	    QListView_hookH = class(QScrollView_hookH) end;
	      QFileListView_hookH = class(QListView_hookH) end;
	    QTextView_hookH = class(QScrollView_hookH) end;
	      QTextEdit_hookH = class(QTextView_hookH) end;
	      QTextBrowser_hookH = class(QTextView_hookH) end;
	  QSplitter_hookH = class(QFrame_hookH) end;
	  QHBox_hookH = class(QFrame_hookH) end;
            QVBox_hookH = class(QHBox_hookH) end;
          QLabel_hookH = class(QFrame_hookH) end;
          QProgressBar_hookH = class(QFrame_hookH) end;
	QDialog_hookH = class(QWidget_hookH) end;
	  QFontDialog_hookH = class(QDialog_hookH) end;
	  QFileDialog_hookH = class(QDialog_hookH) end;
	  QClxFileDialog_hookH = class(QDialog_hookH) end;
	  QWizard_hookH = class(QDialog_hookH) end;
	  QMessageBox_hookH = class(QDialog_hookH) end;
	  QColorDialog_hookH = class(QDialog_hookH) end;
	QSemiModal_hookH = class(QWidget_hookH) end;
          QProgressDialog_hookH = class(QSemiModal_hookH) end;
	QScrollBar_hookH = class(QWidget_hookH) end;
        QSizeGrip_hookH = class(QWidget_hookH) end;
        QStatusBar_hookH = class(QWidget_hookH) end;
        QToolBar_hookH = class(QWidget_hookH) end;
        QWorkspace_hookH = class(QWidget_hookH) end;
    QTimer_hookH = class(QObject_hookH) end;
    QSocketNotifier_hookH = class(QObject_hookH) end;
    QIODevice_hookH = class(QObject_hookH);
      QSocket_hookH = class(QIODevice_hookH) end;
    QSignalMapper_hookH = class(QObject_hookH) end;
    QListViewItem_hookH = class(QObject_hookH) end;
      QCheckListItem_hookH = class(QListViewItem_hookH) end;
    QClipboard_hookH = class(QObject_hookH) end;
    QApplication_hookH = class(QObject_hookH) end;
    QToolTipGroup_hookH = class(QObject_hookH) end;
    QSenderObject_hookH = class(QObject_hookH) end;
    QEvent_hookH = class(QObject_hookH) end;
      QTimerEvent_hookH = class(QEvent_hookH) end;
      QMouseEvent_hookH = class(QEvent_hookH) end;
      QWheelEvent_hookH = class(QEvent_hookH) end;
      QKeyEvent_hookH = class(QEvent_hookH) end;
      QFocusEvent_hookH = class(QEvent_hookH) end;
      QPaintEvent_hookH = class(QEvent_hookH) end;
      QMoveEvent_hookH = class(QEvent_hookH) end;
      QResizeEvent_hookH = class(QEvent_hookH) end;
      QCloseEvent_hookH = class(QEvent_hookH) end;
      QShowEvent_hookH = class(QEvent_hookH) end;
      QHideEvent_hookH = class(QEvent_hookH) end;
      QDropEvent_hookH = class(QEvent_hookH) end;
      QDragMoveEvent_hookH = class(QEvent_hookH) end;
      QDragEnterEvent_hookH = class(QEvent_hookH) end;
      QDragResponseEvent_hookH = class(QEvent_hookH) end;
      QDragLeaveEvent_hookH = class(QEvent_hookH) end;
      QChildEvent_hookH = class(QEvent_hookH) end;
      QCustomEvent_hookH = class(QEvent_hookH) end;
  QFileIconProvider_hookH = class(QObject_hookH) end;
  QClxFileIconProvider_hookH = class(QObject_hookH) end;
  QStyle_hookH = class(QObject_hookH) end;
    QCommonStyle_hookH = class(QStyle_hookH) end;
      QMotifStyle_hookH = class(QObject_hookH) end;
        QCDEStyle_hookH = class(QMotifStyle_hookH) end;
      QWindowsStyle_hookH = class(QCommonStyle_hookH) end;
        QPlatinumStyle_hookH = class(QWindowsStyle_hookH) end;
  QStyleSheetItem_hookH = class(QObject_hookH) end;
  QStyleSheet_hookH = class(QObject_hookH) end;
  QTranslator_hookH = class(QObject_hookH) end;
  QValidator_hookH = class(QObject_hookH) end;
    QIntValidator_hookH = class(QValidator_hookH) end;
    QDoubleValidator_hookH = class(QValidator_hookH) end;
  QBrush_hookH = class(QObject_hookH) end;
  QPainter_hookH = class(QObject_hookH) end;
  QPen_hookH = class(QObject_hookH) end;
  QSignal_hookH = class(QObject_hookH) end;
  QWhatsThis_hookH = class(QObject_hookH) end;
  QIconViewItem_hookH = class(QObject_hookH) end;
  QDragObject_hookH = class(QObject_hookH) end;
    QIconDrag_hookH = class(QObject_hookH) end;
    QStoredDrag_hookH = class(QDragObject_hookH) end;
      QColorDrag_hookH = class(QDragObject_hookH) end;
      QUriDrag_hookH = class(QStoredDrag_hookH) end;
    QTextDrag_hookH = class(QDragObject_hookH) end;
    QImageDrag_hookH = class(QDragObject_hookH) end;

  QMapNodeBaseHH = ^QMapNodeBaseH;
  QMenuDataHH = ^QMenuDataH;

  PDisplay = Pointer;
  _NPStream = Pointer;
  _NPStreamP = ^_NPStream;
  QPropertyH = Pointer;
  QSenderObjectH = Pointer;

  QMessageBoxButton = (NoButton = 0,
                       Ok = 1,
                       Cancel = 2,
                       Yes = 3,
                       No = 4,
                       Abort = 5,
                       Retry = 6,
                       Ignore = 7,
                       ButtonMask = $07,
                       Default = $100,
                       Escape = $200,
                       FlagMask = $300);

{$IFDEF LINUX}
type
  TLoadThemeHook = function: Pointer;
var
  LoadThemeHook: TLoadThemeHook = nil;
{$ENDIF}

procedure Qt_hook_hook_events(handle: QObject_hookH; hook: QHookH); cdecl;

type
  QWidgetBackgroundMode = ( QWidgetBackgroundMode_FixedColor, QWidgetBackgroundMode_FixedPixmap, QWidgetBackgroundMode_NoBackground, QWidgetBackgroundMode_PaletteForeground, QWidgetBackgroundMode_PaletteButton, QWidgetBackgroundMode_PaletteLight, QWidgetBackgroundMode_PaletteMidlight, QWidgetBackgroundMode_PaletteDark, QWidgetBackgroundMode_PaletteMid, QWidgetBackgroundMode_PaletteText, QWidgetBackgroundMode_PaletteBrightText, QWidgetBackgroundMode_PaletteBase, QWidgetBackgroundMode_PaletteBackground, QWidgetBackgroundMode_PaletteShadow, QWidgetBackgroundMode_PaletteHighlight, QWidgetBackgroundMode_PaletteHighlightedText, QWidgetBackgroundMode_PaletteButtonText, QWidgetBackgroundMode_X11ParentRelative );

type
  QWidgetBackgroundOrigin = ( QWidgetBackgroundOrigin_WidgetOrigin, QWidgetBackgroundOrigin_ParentOrigin );
type
  QWidgetPropagationMode = (
    QWidgetPropagationMode_NoChildren,
    QWidgetPropagationMode_AllChildren,
    QWidgetPropagationMode_SameFont,
    QWidgetPropagationMode_SamePalette = 2 { $2 });
type
  QWidgetFocusPolicy = (
    QWidgetFocusPolicy_NoFocus = 0 { $0 },
    QWidgetFocusPolicy_TabFocus = 1 { $1 },
    QWidgetFocusPolicy_ClickFocus = 2 { $2 },
    QWidgetFocusPolicy_StrongFocus = 3 { $3 },
    QWidgetFocusPolicy_WheelFocus = 7 { $7 });

type
  QApplicationType = ( QApplicationType_Tty, QApplicationType_GuiClient, QApplicationType_GuiServer );

type
  QApplicationColorMode = ( QApplicationColorMode_NormalColors, QApplicationColorMode_CustomColors );
type
  QApplicationColorSpec = (
    QApplicationColorSpec_NormalColor = 0 { $0 },
    QApplicationColorSpec_CustomColor = 1 { $1 },
    QApplicationColorSpec_ManyColor = 2 { $2 });

type
  QButtonToggleType = ( QButtonToggleType_SingleShot, QButtonToggleType_Toggle, QButtonToggleType_Tristate );

type
  QButtonToggleState = ( QButtonToggleState_Off, QButtonToggleState_NoChange, QButtonToggleState_On );

type
  QComboBoxPolicy = ( QComboBoxPolicy_NoInsertion, QComboBoxPolicy_AtTop, QComboBoxPolicy_AtCurrent, QComboBoxPolicy_AtBottom, QComboBoxPolicy_AfterCurrent, QComboBoxPolicy_BeforeCurrent );

type
  QDialogDialogCode = ( QDialogDialogCode_Rejected, QDialogDialogCode_Accepted );

type
  QDragObjectDragMode = ( QDragObjectDragMode_DragDefault, QDragObjectDragMode_DragCopy, QDragObjectDragMode_DragMove, QDragObjectDragMode_DragCopyOrMove );

type
  QFocusEventReason = ( QFocusEventReason_Mouse, QFocusEventReason_Tab, QFocusEventReason_ActiveWindow, QFocusEventReason_Popup, QFocusEventReason_Shortcut, QFocusEventReason_Other );
type
  QEventType = (
    QEventType_None = 0 { $0 },
    QEventType_Timer = 1 { $1 },
    QEventType_MouseButtonPress = 2 { $2 },
    QEventType_MouseButtonRelease = 3 { $3 },
    QEventType_MouseButtonDblClick = 4 { $4 },
    QEventType_MouseMove = 5 { $5 },
    QEventType_KeyPress = 6 { $6 },
    QEventType_KeyRelease = 7 { $7 },
    QEventType_FocusIn = 8 { $8 },
    QEventType_FocusOut = 9 { $9 },
    QEventType_Enter = 10 { $a },
    QEventType_Leave = 11 { $b },
    QEventType_Paint = 12 { $c },
    QEventType_Move = 13 { $d },
    QEventType_Resize = 14 { $e },
    QEventType_Create = 15 { $f },
    QEventType_Destroy = 16 { $10 },
    QEventType_Show = 17 { $11 },
    QEventType_Hide = 18 { $12 },
    QEventType_Close = 19 { $13 },
    QEventType_Quit = 20 { $14 },
    QEventType_Reparent = 21 { $15 },
    QEventType_ShowMinimized = 22 { $16 },
    QEventType_ShowNormal = 23 { $17 },
    QEventType_WindowActivate = 24 { $18 },
    QEventType_WindowDeactivate = 25 { $19 },
    QEventType_ShowToParent = 26 { $1a },
    QEventType_HideToParent = 27 { $1b },
    QEventType_ShowMaximized = 28 { $1c },
    QEventType_Accel = 30 { $1e },
    QEventType_Wheel = 31 { $1f },
    QEventType_AccelAvailable = 32 { $20 },
    QEventType_CaptionChange = 33 { $21 },
    QEventType_IconChange = 34 { $22 },
    QEventType_ParentFontChange = 35 { $23 },
    QEventType_ApplicationFontChange = 36 { $24 },
    QEventType_ParentPaletteChange = 37 { $25 },
    QEventType_ApplicationPaletteChange = 38 { $26 },
    QEventType_Clipboard = 40 { $28 },
    QEventType_Speech = 42 { $2a },
    QEventType_SockAct = 50 { $32 },
    QEventType_AccelOverride = 51 { $33 },
    QEventType_DragEnter = 60 { $3c },
    QEventType_DragMove = 61 { $3d },
    QEventType_DragLeave = 62 { $3e },
    QEventType_Drop = 63 { $3f },
    QEventType_DragResponse = 64 { $40 },
    QEventType_ChildInserted = 70 { $46 },
    QEventType_ChildRemoved = 71 { $47 },
    QEventType_LayoutHint = 72 { $48 },
    QEventType_ShowWindowRequest = 73 { $49 },
    QEventType_ActivateControl = 80 { $50 },
    QEventType_DeactivateControl = 81 { $51 },
    QEventType_User = 1000 { $3e8 },
    QEventType_ClxBase = 1000,
    QEventType_ClxUser = 2000, 
    QEventType_ClxUserLimit = 4000);
type
  QDropEventAction = (
    QDropEventAction_Copy,
    QDropEventAction_Link,
    QDropEventAction_Move,
    QDropEventAction_Private,
    QDropEventAction_UserAction = 100 { $64 });
type
  QFrameShape = (
    QFrameShape_NoFrame = 0 { $0 },
    QFrameShape_Box = 1 { $1 },
    QFrameShape_Panel = 2 { $2 },
    QFrameShape_WinPanel = 3 { $3 },
    QFrameShape_HLine = 4 { $4 },
    QFrameShape_VLine = 5 { $5 },
    QFrameShape_StyledPanel = 6 { $6 },
    QFrameShape_PopupPanel = 7 { $7 },
    QFrameShape_MShape = 15 { $f });
type
  QFrameShadow = (
    QFrameShadow_Plain = 16 { $10 },
    QFrameShadow_Raised = 32 { $20 },
    QFrameShadow_Sunken = 48 { $30 },
    QFrameShadow_MShadow = 240 { $f0 });
type
  QIconViewSelectionMode = (
    QIconViewSelectionMode_Single = 0 { $0 },
    QIconViewSelectionMode_Multi,
    QIconViewSelectionMode_Extended,
    QIconViewSelectionMode_NoSelection);
type
  QIconViewArrangement = (
    QIconViewArrangement_LeftToRight = 0 { $0 },
    QIconViewArrangement_TopToBottom);
type
  QIconViewResizeMode = (
    QIconViewResizeMode_Fixed = 0 { $0 },
    QIconViewResizeMode_Adjust);
type
  QIconViewItemTextPos = (
    QIconViewItemTextPos_Bottom = 0 { $0 },
    QIconViewItemTextPos_Right);

type
  QLCDNumberSegmentStyle = ( QLCDNumberSegmentStyle_Outline, QLCDNumberSegmentStyle_Filled, QLCDNumberSegmentStyle_Flat );
type
  QLCDNumberMode = (
    QLCDNumberMode_Hex,
    QLCDNumberMode_Dec,
    QLCDNumberMode_Oct,
    QLCDNumberMode_Bin);

type
  QLineEditEchoMode = ( QLineEditEchoMode_Normal, QLineEditEchoMode_NoEcho, QLineEditEchoMode_Password );

type
  QListBoxSelectionMode = ( QListBoxSelectionMode_Single, QListBoxSelectionMode_Multi, QListBoxSelectionMode_Extended, QListBoxSelectionMode_NoSelection );
type
  QListBoxLayoutMode = (
    QListBoxLayoutMode_FixedNumber,
    QListBoxLayoutMode_FitToWidth,
    QListBoxLayoutMode_FitToHeight = 1 { $1 },
    QListBoxLayoutMode_Variable);

type
  QListViewWidthMode = ( QListViewWidthMode_Manual, QListViewWidthMode_Maximum );

type
  QListViewSelectionMode = ( QListViewSelectionMode_Single, QListViewSelectionMode_Multi, QListViewSelectionMode_Extended, QListViewSelectionMode_NoSelection );

type
  QCheckListItemType = ( QCheckListItemType_RadioButton, QCheckListItemType_CheckBox, QCheckListItemType_Controller );
type
  QMenuBarSeparator = (
    QMenuBarSeparator_Never = 0 { $0 },
    QMenuBarSeparator_InWindowsStyle = 1 { $1 });
type
  QMessageBoxIcon = (
    QMessageBoxIcon_NoIcon = 0 { $0 },
    QMessageBoxIcon_Information = 1 { $1 },
    QMessageBoxIcon_Warning = 2 { $2 },
    QMessageBoxIcon_Critical = 3 { $3 });

type
  QMultiLineEditEchoMode = ( QMultiLineEditEchoMode_Normal, QMultiLineEditEchoMode_NoEcho, QMultiLineEditEchoMode_Password );

type
  QMultiLineEditWordWrap = ( QMultiLineEditWordWrap_NoWrap, QMultiLineEditWordWrap_WidgetWidth, QMultiLineEditWordWrap_FixedPixelWidth, QMultiLineEditWordWrap_FixedColumnWidth );

type
  QMultiLineEditWrapPolicy = ( QMultiLineEditWrapPolicy_AtWhiteSpace, QMultiLineEditWrapPolicy_Anywhere );

type
  QScrollViewResizePolicy = ( QScrollViewResizePolicy_Default, QScrollViewResizePolicy_Manual, QScrollViewResizePolicy_AutoOne );

type
  QScrollViewScrollBarMode = ( QScrollViewScrollBarMode_Auto, QScrollViewScrollBarMode_AlwaysOff, QScrollViewScrollBarMode_AlwaysOn );
type
  QSliderTickSetting = (
    QSliderTickSetting_NoMarks = 0 { $0 },
    QSliderTickSetting_Above = 1 { $1 },
    QSliderTickSetting_Left = 1 { $1 },
    QSliderTickSetting_Below = 2 { $2 },
    QSliderTickSetting_Right = 2 { $2 },
    QSliderTickSetting_Both = 3 { $3 });

type
  QSocketNotifierType = ( QSocketNotifierType_Read, QSocketNotifierType_Write, QSocketNotifierType_Exception );

type
  QSpinBoxButtonSymbols = ( QSpinBoxButtonSymbols_UpDownArrows, QSpinBoxButtonSymbols_PlusMinus );
type
  QStyleScrollControl = (
    QStyleScrollControl_AddLine = 1 { $1 },
    QStyleScrollControl_SubLine = 2 { $2 },
    QStyleScrollControl_AddPage = 4 { $4 },
    QStyleScrollControl_SubPage = 8 { $8 },
    QStyleScrollControl_First = 16 { $10 },
    QStyleScrollControl_Last = 32 { $20 },
    QStyleScrollControl_Slider = 64 { $40 },
    QStyleScrollControl_NoScroll = 128 { $80 });

type
  QTranslatorMessagePrefix = ( QTranslatorMessagePrefix_NoPrefix, QTranslatorMessagePrefix_Hash, QTranslatorMessagePrefix_HashContext, QTranslatorMessagePrefix_HashContextSourceText, QTranslatorMessagePrefix_HashContextSourceTextComment );

type
  QTranslatorSaveMode = ( QTranslatorSaveMode_Everything, QTranslatorSaveMode_Stripped );

type
  QColorSpec = ( QColorSpec_Rgb, QColorSpec_Hsv );
type
  QFontCharSet = (
    QFontCharSet_ISO_8859_1,
    QFontCharSet_Latin1 = 0 { $0 },
    QFontCharSet_AnyCharSet,
    QFontCharSet_ISO_8859_2,
    QFontCharSet_Latin2 = 2 { $2 },
    QFontCharSet_ISO_8859_3,
    QFontCharSet_Latin3 = 3 { $3 },
    QFontCharSet_ISO_8859_4,
    QFontCharSet_Latin4 = 4 { $4 },
    QFontCharSet_ISO_8859_5,
    QFontCharSet_ISO_8859_6,
    QFontCharSet_ISO_8859_7,
    QFontCharSet_ISO_8859_8,
    QFontCharSet_ISO_8859_9,
    QFontCharSet_Latin5 = 9 { $9 },
    QFontCharSet_ISO_8859_10,
    QFontCharSet_Latin6 = 10 { $a },
    QFontCharSet_ISO_8859_11,
    QFontCharSet_TIS620 = 11 { $b },
    QFontCharSet_ISO_8859_12,
    QFontCharSet_ISO_8859_13,
    QFontCharSet_Latin7 = 13 { $d },
    QFontCharSet_ISO_8859_14,
    QFontCharSet_Latin8 = 14 { $e },
    QFontCharSet_ISO_8859_15,
    QFontCharSet_Latin9 = 15 { $f },
    QFontCharSet_KOI8R,
    QFontCharSet_Set_Ja,
    QFontCharSet_Set_1 = 17 { $11 },
    QFontCharSet_Set_Ko,
    QFontCharSet_Set_Th_TH,
    QFontCharSet_Set_Zh,
    QFontCharSet_Set_Zh_TW,
    QFontCharSet_Set_N = 21 { $15 },
    QFontCharSet_Unicode,
    QFontCharSet_Set_GBK,
    QFontCharSet_Set_Big5,
    QFontCharSet_TSCII,
    QFontCharSet_KOI8U,
    QFontCharSet_CP1251,
    QFontCharSet_PT154,
    QFontCharSet_JIS_X_0201 = 160 { $a0 },
    QFontCharSet_JIS_X_0208 = 192 { $c0 },
    QFontCharSet_Enc16 = 192 { $c0 },
    QFontCharSet_KSC_5601,
    QFontCharSet_GB_2312,
    QFontCharSet_Big5);
type
  QFontStyleHint = (
    QFontStyleHint_Helvetica,
    QFontStyleHint_Times,
    QFontStyleHint_Courier,
    QFontStyleHint_OldEnglish,
    QFontStyleHint_System,
    QFontStyleHint_AnyStyle,
    QFontStyleHint_SansSerif = 0 { $0 },
    QFontStyleHint_Serif = 1 { $1 },
    QFontStyleHint_TypeWriter = 2 { $2 },
    QFontStyleHint_Decorative = 3 { $3 });
type
  QFontStyleStrategy = (
    QFontStyleStrategy_PreferDefault = 1 { $1 },
    QFontStyleStrategy_PreferBitmap = 2 { $2 },
    QFontStyleStrategy_PreferDevice = 4 { $4 },
    QFontStyleStrategy_PreferOutline = 8 { $8 },
    QFontStyleStrategy_ForceOutline = 16 { $10 },
    QFontStyleStrategy_PreferMatch = 32 { $20 },
    QFontStyleStrategy_PreferQuality = 64 { $40 });
type
  QFontWeight = (
    QFontWeight_Light = 25 { $19 },
    QFontWeight_Normal = 50 { $32 },
    QFontWeight_DemiBold = 63 { $3f },
    QFontWeight_Bold = 75 { $4b },
    QFontWeight_Black = 87 { $57 });

type
  QImageEndian = ( QImageEndian_IgnoreEndian, QImageEndian_BigEndian, QImageEndian_LittleEndian );

type
  QIconSetSize = ( QIconSetSize_Automatic, QIconSetSize_Small, QIconSetSize_Large );

type
  QIconSetMode = ( QIconSetMode_Normal, QIconSetMode_Disabled, QIconSetMode_Active );
type
  QMovieStatus = (
    QMovieStatus_SourceEmpty = -2 { $fffffffe },
    QMovieStatus_UnrecognizedFormat = -1 { $ffffffff },
    QMovieStatus_Paused = 1 { $1 },
    QMovieStatus_EndOfFrame = 2 { $2 },
    QMovieStatus_EndOfLoop = 3 { $3 },
    QMovieStatus_EndOfMovie = 4 { $4 },
    QMovieStatus_SpeedChanged = 5 { $5 });
type
  QPaintDevicePDevCmd = (
    QPaintDevicePDevCmd_PdcNOP = 0 { $0 },
    QPaintDevicePDevCmd_PdcDrawPoint = 1 { $1 },
    QPaintDevicePDevCmd_PdcDrawFirst = 1 { $1 },
    QPaintDevicePDevCmd_PdcMoveTo = 2 { $2 },
    QPaintDevicePDevCmd_PdcLineTo = 3 { $3 },
    QPaintDevicePDevCmd_PdcDrawLine = 4 { $4 },
    QPaintDevicePDevCmd_PdcDrawRect = 5 { $5 },
    QPaintDevicePDevCmd_PdcDrawRoundRect = 6 { $6 },
    QPaintDevicePDevCmd_PdcDrawEllipse = 7 { $7 },
    QPaintDevicePDevCmd_PdcDrawArc = 8 { $8 },
    QPaintDevicePDevCmd_PdcDrawPie = 9 { $9 },
    QPaintDevicePDevCmd_PdcDrawChord = 10 { $a },
    QPaintDevicePDevCmd_PdcDrawLineSegments = 11 { $b },
    QPaintDevicePDevCmd_PdcDrawPolyline = 12 { $c },
    QPaintDevicePDevCmd_PdcDrawPolygon = 13 { $d },
    QPaintDevicePDevCmd_PdcDrawQuadBezier = 14 { $e },
    QPaintDevicePDevCmd_PdcDrawText = 15 { $f },
    QPaintDevicePDevCmd_PdcDrawTextFormatted = 16 { $10 },
    QPaintDevicePDevCmd_PdcDrawPixmap = 17 { $11 },
    QPaintDevicePDevCmd_PdcDrawImage = 18 { $12 },
    QPaintDevicePDevCmd_PdcDrawText2 = 19 { $13 },
    QPaintDevicePDevCmd_PdcDrawText2Formatted = 20 { $14 },
    QPaintDevicePDevCmd_PdcDrawLast = 20 { $14 },
    QPaintDevicePDevCmd_PdcBegin = 30 { $1e },
    QPaintDevicePDevCmd_PdcEnd = 31 { $1f },
    QPaintDevicePDevCmd_PdcSave = 32 { $20 },
    QPaintDevicePDevCmd_PdcRestore = 33 { $21 },
    QPaintDevicePDevCmd_PdcSetdev = 34 { $22 },
    QPaintDevicePDevCmd_PdcSetBkColor = 40 { $28 },
    QPaintDevicePDevCmd_PdcSetBkMode = 41 { $29 },
    QPaintDevicePDevCmd_PdcSetROP = 42 { $2a },
    QPaintDevicePDevCmd_PdcSetBrushOrigin = 43 { $2b },
    QPaintDevicePDevCmd_PdcSetFont = 45 { $2d },
    QPaintDevicePDevCmd_PdcSetPen = 46 { $2e },
    QPaintDevicePDevCmd_PdcSetBrush = 47 { $2f },
    QPaintDevicePDevCmd_PdcSetTabStops = 48 { $30 },
    QPaintDevicePDevCmd_PdcSetTabArray = 49 { $31 },
    QPaintDevicePDevCmd_PdcSetUnit = 50 { $32 },
    QPaintDevicePDevCmd_PdcSetVXform = 51 { $33 },
    QPaintDevicePDevCmd_PdcSetWindow = 52 { $34 },
    QPaintDevicePDevCmd_PdcSetViewport = 53 { $35 },
    QPaintDevicePDevCmd_PdcSetWXform = 54 { $36 },
    QPaintDevicePDevCmd_PdcSetWMatrix = 55 { $37 },
    QPaintDevicePDevCmd_PdcSaveWMatrix = 56 { $38 },
    QPaintDevicePDevCmd_PdcRestoreWMatrix = 57 { $39 },
    QPaintDevicePDevCmd_PdcSetClip = 60 { $3c },
    QPaintDevicePDevCmd_PdcSetClipRegion = 61 { $3d },
    QPaintDevicePDevCmd_PdcReservedStart = 0 { $0 },
    QPaintDevicePDevCmd_PdcReservedStop = 199 { $c7 });

type
  QColorGroupColorRole = ( QColorGroupColorRole_Foreground, QColorGroupColorRole_Button, QColorGroupColorRole_Light, QColorGroupColorRole_Midlight, QColorGroupColorRole_Dark, QColorGroupColorRole_Mid, QColorGroupColorRole_Text, QColorGroupColorRole_BrightText, QColorGroupColorRole_ButtonText, QColorGroupColorRole_Base, QColorGroupColorRole_Background, QColorGroupColorRole_Shadow, QColorGroupColorRole_Highlight, QColorGroupColorRole_HighlightedText, QColorGroupColorRole_NColorRoles );

type
  QPaletteColorGroup = ( QPaletteColorGroup_Normal, QPaletteColorGroup_Disabled, QPaletteColorGroup_Active, QPaletteColorGroup_Inactive, QPaletteColorGroup_NColorGroups );

type
  QPixmapColorMode = ( QPixmapColorMode_Auto, QPixmapColorMode_Color, QPixmapColorMode_Mono );
type
  QPixmapOptimization = (
    QPixmapOptimization_DefaultOptim,
    QPixmapOptimization_NoOptim,
    QPixmapOptimization_MemoryOptim = 1 { $1 },
    QPixmapOptimization_NormalOptim,
    QPixmapOptimization_BestOptim);

type
  QPrinterOrientation = ( QPrinterOrientation_Portrait, QPrinterOrientation_Landscape );

type
  QPrinterPageSize = ( QPrinterPageSize_A4, QPrinterPageSize_B5, QPrinterPageSize_Letter, QPrinterPageSize_Legal, QPrinterPageSize_Executive, QPrinterPageSize_A0, QPrinterPageSize_A1, QPrinterPageSize_A2, QPrinterPageSize_A3, QPrinterPageSize_A5, QPrinterPageSize_A6, QPrinterPageSize_A7, QPrinterPageSize_A8, QPrinterPageSize_A9, QPrinterPageSize_B0, QPrinterPageSize_B1, QPrinterPageSize_B10, QPrinterPageSize_B2, QPrinterPageSize_B3, QPrinterPageSize_B4, QPrinterPageSize_B6, QPrinterPageSize_B7, QPrinterPageSize_B8, QPrinterPageSize_B9, QPrinterPageSize_C5E, QPrinterPageSize_Comm10E, QPrinterPageSize_DLE, QPrinterPageSize_Folio, QPrinterPageSize_Ledger, QPrinterPageSize_Tabloid, QPrinterPageSize_NPageSize );

type
  QPrinterPageOrder = ( QPrinterPageOrder_FirstPageFirst, QPrinterPageOrder_LastPageFirst );

type
  QPrinterColorMode = ( QPrinterColorMode_GrayScale, QPrinterColorMode_Color );

type
  QRegionRegionType = ( QRegionRegionType_Rectangle, QRegionRegionType_Ellipse );

type
  Orientation = ( Orientation_Horizontal, Orientation_Vertical );

type
  BGMode = ( BGMode_TransparentMode, BGMode_OpaqueMode );

type
  PaintUnit = ( PaintUnit_PixelUnit, PaintUnit_LoMetricUnit, PaintUnit_HiMetricUnit, PaintUnit_LoEnglishUnit, PaintUnit_HiEnglishUnit, PaintUnit_TwipsUnit );

type
  GUIStyle = ( GUIStyle_MacStyle, GUIStyle_WindowsStyle, GUIStyle_Win3Style, GUIStyle_PMStyle, GUIStyle_MotifStyle );

type
  ArrowType = ( ArrowType_UpArrow, ArrowType_DownArrow, ArrowType_LeftArrow, ArrowType_RightArrow );

type
  UIEffect = ( UIEffect_UI_General, UIEffect_UI_AnimateMenu, UIEffect_UI_FadeMenu, UIEffect_UI_AnimateCombo, UIEffect_UI_AnimateTooltip, UIEffect_UI_FadeTooltip );

type
  TextFormat = ( TextFormat_PlainText, TextFormat_RichText, TextFormat_AutoText );
type
  ButtonState = (
    ButtonState_NoButton = 0 { $0 },
    ButtonState_LeftButton = 1 { $1 },
    ButtonState_RightButton = 2 { $2 },
    ButtonState_MidButton = 4 { $4 },
    ButtonState_MouseButtonMask = 7 { $7 },
    ButtonState_ShiftButton = 8 { $8 },
    ButtonState_ControlButton = 16 { $10 },
    ButtonState_AltButton = 32 { $20 },
    ButtonState_KeyButtonMask = 56 { $38 },
    ButtonState_Keypad = 16384 { $4000 });
type
  AlignmentFlags = (
    AlignmentFlags_AlignLeft = 1 { $1 },
    AlignmentFlags_AlignRight = 2 { $2 },
    AlignmentFlags_AlignHCenter = 4 { $4 },
    AlignmentFlags_AlignTop = 8 { $8 },
    AlignmentFlags_AlignBottom = 16 { $10 },
    AlignmentFlags_AlignVCenter = 32 { $20 },
    AlignmentFlags_AlignCenter = 36 { $24 },
    AlignmentFlags_SingleLine = 64 { $40 },
    AlignmentFlags_DontClip = 128 { $80 },
    AlignmentFlags_ExpandTabs = 256 { $100 },
    AlignmentFlags_ShowPrefix = 512 { $200 },
    AlignmentFlags_WordBreak = 1024 { $400 },
    AlignmentFlags_DontPrint = 4096 { $1000 });
type
  WidgetState = (
    WidgetState_WState_Created = 1 { $1 },
    WidgetState_WState_Disabled = 2 { $2 },
    WidgetState_WState_Visible = 4 { $4 },
    WidgetState_WState_ForceHide = 8 { $8 },
    WidgetState_WState_OwnCursor = 16 { $10 },
    WidgetState_WState_MouseTracking = 32 { $20 },
    WidgetState_WState_CompressKeys = 64 { $40 },
    WidgetState_WState_BlockUpdates = 128 { $80 },
    WidgetState_WState_InPaintEvent = 256 { $100 },
    WidgetState_WState_Reparented = 512 { $200 },
    WidgetState_WState_ConfigPending = 1024 { $400 },
    WidgetState_WState_Resized = 2048 { $800 },
    WidgetState_WState_AutoMask = 4096 { $1000 },
    WidgetState_WState_Polished = 8192 { $2000 },
    WidgetState_WState_DND = 16384 { $4000 },
    WidgetState_WState_Modal = 32768 { $8000 },
    WidgetState_WState_Reserved1 = 65536 { $10000 },
    WidgetState_WState_Reserved2 = 131072 { $20000 },
    WidgetState_WState_Reserved3 = 262144 { $40000 },
    WidgetState_WState_Maximized = 524288 { $80000 },
    WidgetState_WState_TranslateBackground = 1048576 { $100000 },
    WidgetState_WState_ForceDisabled = 2097152 { $200000 },
    WidgetState_WState_Exposed = 4194304 { $400000 });
type
  WidgetFlags = (
    WidgetFlags_WType_TopLevel = 1 { $1 },
    WidgetFlags_WType_Modal = 2 { $2 },
    WidgetFlags_WType_Popup = 4 { $4 },
    WidgetFlags_WType_Desktop = 8 { $8 },
    WidgetFlags_WType_Mask = 15 { $f },
    WidgetFlags_WStyle_Customize = 16 { $10 },
    WidgetFlags_WStyle_NormalBorder = 32 { $20 },
    WidgetFlags_WStyle_DialogBorder = 64 { $40 },
    WidgetFlags_WStyle_NoBorder = 0 { $0 },
    WidgetFlags_WStyle_Title = 128 { $80 },
    WidgetFlags_WStyle_SysMenu = 256 { $100 },
    WidgetFlags_WStyle_Minimize = 512 { $200 },
    WidgetFlags_WStyle_Maximize = 1024 { $400 },
    WidgetFlags_WStyle_MinMax = 1536 { $600 },
    WidgetFlags_WStyle_Tool = 2048 { $800 },
    WidgetFlags_WStyle_StaysOnTop = 4096 { $1000 },
    WidgetFlags_WStyle_Dialog = 8192 { $2000 },
    WidgetFlags_WStyle_ContextHelp = 16384 { $4000 },
    WidgetFlags_WStyle_NoBorderEx = 32768 { $8000 },
    WidgetFlags_WStyle_Mask = 65520 { $fff0 },
    WidgetFlags_WDestructiveClose = 65536 { $10000 },
    WidgetFlags_WPaintDesktop = 131072 { $20000 },
    WidgetFlags_WPaintUnclipped = 262144 { $40000 },
    WidgetFlags_WPaintClever = 524288 { $80000 },
    WidgetFlags_WResizeNoErase = 1048576 { $100000 },
    WidgetFlags_WMouseNoMask = 2097152 { $200000 },
    WidgetFlags_WNorthWestGravity = 4194304 { $400000 },
    WidgetFlags_WRepaintNoErase = 8388608 { $800000 },
    WidgetFlags_WX11BypassWM = 16777216 { $1000000 },
    WidgetFlags_WGroupLeader = 33554432 { $2000000 });
type
  ImageConversionFlags = (
    ImageConversionFlags_ColorMode_Mask = 3 { $3 },
    ImageConversionFlags_AutoColor = 0 { $0 },
    ImageConversionFlags_ColorOnly = 3 { $3 },
    ImageConversionFlags_MonoOnly = 2 { $2 },
    ImageConversionFlags_AlphaDither_Mask = 12 { $c },
    ImageConversionFlags_ThresholdAlphaDither = 0 { $0 },
    ImageConversionFlags_OrderedAlphaDither = 4 { $4 },
    ImageConversionFlags_DiffuseAlphaDither = 8 { $8 },
    ImageConversionFlags_NoAlpha = 12 { $c },
    ImageConversionFlags_Dither_Mask = 48 { $30 },
    ImageConversionFlags_DiffuseDither = 0 { $0 },
    ImageConversionFlags_OrderedDither = 16 { $10 },
    ImageConversionFlags_ThresholdDither = 32 { $20 },
    ImageConversionFlags_DitherMode_Mask = 192 { $c0 },
    ImageConversionFlags_AutoDither = 0 { $0 },
    ImageConversionFlags_PreferDither = 64 { $40 },
    ImageConversionFlags_AvoidDither = 128 { $80 });
type
  Modifier = (
    Modifier_SHIFT = 2097152 { $200000 },
    Modifier_CTRL = 4194304 { $400000 },
    Modifier_ALT = 8388608 { $800000 },
    Modifier_MODIFIER_MASK = 14680064 { $e00000 },
    Modifier_UNICODE_ACCEL = 268435456 { $10000000 },
    Modifier_ASCII_ACCEL = 268435456 { $10000000 });
type
  QtKey = Integer;
const
    Key_Escape = 4096 { $1000 };
    Key_Tab = 4097 { $1001 };
    Key_Backtab = 4098 { $1002 };
    Key_Backspace = 4099 { $1003 };
    Key_Return = 4100 { $1004 };
    Key_Enter = 4101 { $1005 };
    Key_Insert = 4102 { $1006 };
    Key_Delete = 4103 { $1007 };
    Key_Pause = 4104 { $1008 };
    Key_Print = 4105 { $1009 };
    Key_SysReq = 4106 { $100a };
    Key_Home = 4112 { $1010 };
    Key_End = 4113 { $1011 };
    Key_Left = 4114 { $1012 };
    Key_Up = 4115 { $1013 };
    Key_Right = 4116 { $1014 };
    Key_Down = 4117 { $1015 };
    Key_Prior = 4118 { $1016 };
    Key_PageUp = 4118 { $1016 };
    Key_Next = 4119 { $1017 };
    Key_PageDown = 4119 { $1017 };
    Key_Shift = 4128 { $1020 };
    Key_Control = 4129 { $1021 };
    Key_Meta = 4130 { $1022 };
    Key_Alt = 4131 { $1023 };
    Key_CapsLock = 4132 { $1024 };
    Key_NumLock = 4133 { $1025 };
    Key_ScrollLock = 4134 { $1026 };
    Key_F1 = 4144 { $1030 };
    Key_F2 = 4145 { $1031 };
    Key_F3 = 4146 { $1032 };
    Key_F4 = 4147 { $1033 };
    Key_F5 = 4148 { $1034 };
    Key_F6 = 4149 { $1035 };
    Key_F7 = 4150 { $1036 };
    Key_F8 = 4151 { $1037 };
    Key_F9 = 4152 { $1038 };
    Key_F10 = 4153 { $1039 };
    Key_F11 = 4154 { $103a };
    Key_F12 = 4155 { $103b };
    Key_F13 = 4156 { $103c };
    Key_F14 = 4157 { $103d };
    Key_F15 = 4158 { $103e };
    Key_F16 = 4159 { $103f };
    Key_F17 = 4160 { $1040 };
    Key_F18 = 4161 { $1041 };
    Key_F19 = 4162 { $1042 };
    Key_F20 = 4163 { $1043 };
    Key_F21 = 4164 { $1044 };
    Key_F22 = 4165 { $1045 };
    Key_F23 = 4166 { $1046 };
    Key_F24 = 4167 { $1047 };
    Key_F25 = 4168 { $1048 };
    Key_F26 = 4169 { $1049 };
    Key_F27 = 4170 { $104a };
    Key_F28 = 4171 { $104b };
    Key_F29 = 4172 { $104c };
    Key_F30 = 4173 { $104d };
    Key_F31 = 4174 { $104e };
    Key_F32 = 4175 { $104f };
    Key_F33 = 4176 { $1050 };
    Key_F34 = 4177 { $1051 };
    Key_F35 = 4178 { $1052 };
    Key_Super_L = 4179 { $1053 };
    Key_Super_R = 4180 { $1054 };
    Key_Menu = 4181 { $1055 };
    Key_Hyper_L = 4182 { $1056 };
    Key_Hyper_R = 4183 { $1057 };
    Key_Help = 4184 { $1058 };
    Key_Space = 32 { $20 };
    Key_Any = 32 { $20 };
    Key_Exclam = 33 { $21 };
    Key_QuoteDbl = 34 { $22 };
    Key_NumberSign = 35 { $23 };
    Key_Dollar = 36 { $24 };
    Key_Percent = 37 { $25 };
    Key_Ampersand = 38 { $26 };
    Key_Apostrophe = 39 { $27 };
    Key_ParenLeft = 40 { $28 };
    Key_ParenRight = 41 { $29 };
    Key_Asterisk = 42 { $2a };
    Key_Plus = 43 { $2b };
    Key_Comma = 44 { $2c };
    Key_Minus = 45 { $2d };
    Key_Period = 46 { $2e };
    Key_Slash = 47 { $2f };
    Key_0 = 48 { $30 };
    Key_1 = 49 { $31 };
    Key_2 = 50 { $32 };
    Key_3 = 51 { $33 };
    Key_4 = 52 { $34 };
    Key_5 = 53 { $35 };
    Key_6 = 54 { $36 };
    Key_7 = 55 { $37 };
    Key_8 = 56 { $38 };
    Key_9 = 57 { $39 };
    Key_Colon = 58 { $3a };
    Key_Semicolon = 59 { $3b };
    Key_Less = 60 { $3c };
    Key_Equal = 61 { $3d };
    Key_Greater = 62 { $3e };
    Key_Question = 63 { $3f };
    Key_At = 64 { $40 };
    Key_A = 65 { $41 };
    Key_B = 66 { $42 };
    Key_C = 67 { $43 };
    Key_D = 68 { $44 };
    Key_E = 69 { $45 };
    Key_F = 70 { $46 };
    Key_G = 71 { $47 };
    Key_H = 72 { $48 };
    Key_I = 73 { $49 };
    Key_J = 74 { $4a };
    Key_K = 75 { $4b };
    Key_L = 76 { $4c };
    Key_M = 77 { $4d };
    Key_N = 78 { $4e };
    Key_O = 79 { $4f };
    Key_P = 80 { $50 };
    Key_Q = 81 { $51 };
    Key_R = 82 { $52 };
    Key_S = 83 { $53 };
    Key_T = 84 { $54 };
    Key_U = 85 { $55 };
    Key_V = 86 { $56 };
    Key_W = 87 { $57 };
    Key_X = 88 { $58 };
    Key_Y = 89 { $59 };
    Key_Z = 90 { $5a };
    Key_BracketLeft = 91 { $5b };
    Key_Backslash = 92 { $5c };
    Key_BracketRight = 93 { $5d };
    Key_AsciiCircum = 94 { $5e };
    Key_Underscore = 95 { $5f };
    Key_QuoteLeft = 96 { $60 };
    Key_BraceLeft = 123 { $7b };
    Key_Bar = 124 { $7c };
    Key_BraceRight = 125 { $7d };
    Key_AsciiTilde = 126 { $7e };
    Key_nobreakspace = 160 { $a0 };
    Key_exclamdown = 161 { $a1 };
    Key_cent = 162 { $a2 };
    Key_sterling = 163 { $a3 };
    Key_currency = 164 { $a4 };
    Key_yen = 165 { $a5 };
    Key_brokenbar = 166 { $a6 };
    Key_section = 167 { $a7 };
    Key_diaeresis = 168 { $a8 };
    Key_copyright = 169 { $a9 };
    Key_ordfeminine = 170 { $aa };
    Key_guillemotleft = 171 { $ab };
    Key_notsign = 172 { $ac };
    Key_hyphen = 173 { $ad };
    Key_registered = 174 { $ae };
    Key_macron = 175 { $af };
    Key_degree = 176 { $b0 };
    Key_plusminus = 177 { $b1 };
    Key_twosuperior = 178 { $b2 };
    Key_threesuperior = 179 { $b3 };
    Key_acute = 180 { $b4 };
    Key_mu = 181 { $b5 };
    Key_paragraph = 182 { $b6 };
    Key_periodcentered = 183 { $b7 };
    Key_cedilla = 184 { $b8 };
    Key_onesuperior = 185 { $b9 };
    Key_masculine = 186 { $ba };
    Key_guillemotright = 187 { $bb };
    Key_onequarter = 188 { $bc };
    Key_onehalf = 189 { $bd };
    Key_threequarters = 190 { $be };
    Key_questiondown = 191 { $bf };
    Key_Agrave = 192 { $c0 };
    Key_Aacute = 193 { $c1 };
    Key_Acircumflex = 194 { $c2 };
    Key_Atilde = 195 { $c3 };
    Key_Adiaeresis = 196 { $c4 };
    Key_Aring = 197 { $c5 };
    Key_AE = 198 { $c6 };
    Key_Ccedilla = 199 { $c7 };
    Key_Egrave = 200 { $c8 };
    Key_Eacute = 201 { $c9 };
    Key_Ecircumflex = 202 { $ca };
    Key_Ediaeresis = 203 { $cb };
    Key_Igrave = 204 { $cc };
    Key_Iacute = 205 { $cd };
    Key_Icircumflex = 206 { $ce };
    Key_Idiaeresis = 207 { $cf };
    Key_ETH = 208 { $d0 };
    Key_Ntilde = 209 { $d1 };
    Key_Ograve = 210 { $d2 };
    Key_Oacute = 211 { $d3 };
    Key_Ocircumflex = 212 { $d4 };
    Key_Otilde = 213 { $d5 };
    Key_Odiaeresis = 214 { $d6 };
    Key_multiply = 215 { $d7 };
    Key_Ooblique = 216 { $d8 };
    Key_Ugrave = 217 { $d9 };
    Key_Uacute = 218 { $da };
    Key_Ucircumflex = 219 { $db };
    Key_Udiaeresis = 220 { $dc };
    Key_Yacute = 221 { $dd };
    Key_THORN = 222 { $de };
    Key_ssharp = 223 { $df };
    Key_agrave_lower = 224 { $e0 };
    Key_aacute_lower = 225 { $e1 };
    Key_acircumflex_lower = 226 { $e2 };
    Key_atilde_lower = 227 { $e3 };
    Key_adiaeresis_lower = 228 { $e4 };
    Key_aring_lower = 229 { $e5 };
    Key_ae_lower = 230 { $e6 };
    Key_ccedilla_lower = 231 { $e7 };
    Key_egrave_lower = 232 { $e8 };
    Key_eacute_lower = 233 { $e9 };
    Key_ecircumflex_lower = 234 { $ea };
    Key_ediaeresis_lower = 235 { $eb };
    Key_igrave_lower = 236 { $ec };
    Key_iacute_lower = 237 { $ed };
    Key_icircumflex_lower = 238 { $ee };
    Key_idiaeresis_lower = 239 { $ef };
    Key_eth_lower = 240 { $f0 };
    Key_ntilde_lower = 241 { $f1 };
    Key_ograve_lower = 242 { $f2 };
    Key_oacute_lower = 243 { $f3 };
    Key_ocircumflex_lower = 244 { $f4 };
    Key_otilde_lower = 245 { $f5 };
    Key_odiaeresis_lower = 246 { $f6 };
    Key_division = 247 { $f7 };
    Key_oslash = 248 { $f8 };
    Key_ugrave_lower = 249 { $f9 };
    Key_uacute_lower = 250 { $fa };
    Key_ucircumflex_lower = 251 { $fb };
    Key_udiaeresis_lower = 252 { $fc };
    Key_yacute_lower = 253 { $fd };
    Key_thorn_lower = 254 { $fe };
    Key_ydiaeresis = 255 { $ff };
    Key_unknown = 65535 { $ffff };
type
  RasterOp = (
    RasterOp_CopyROP,
    RasterOp_OrROP,
    RasterOp_XorROP,
    RasterOp_NotAndROP,
    RasterOp_EraseROP = 3 { $3 },
    RasterOp_NotCopyROP,
    RasterOp_NotOrROP,
    RasterOp_NotXorROP,
    RasterOp_AndROP,
    RasterOp_NotEraseROP = 7 { $7 },
    RasterOp_NotROP,
    RasterOp_ClearROP,
    RasterOp_SetROP,
    RasterOp_NopROP,
    RasterOp_AndNotROP,
    RasterOp_OrNotROP,
    RasterOp_NandROP,
    RasterOp_NorROP,
    RasterOp_LastROP = 15 { $f });
type
  PenStyle = (
    PenStyle_NoPen,
    PenStyle_SolidLine,
    PenStyle_DashLine,
    PenStyle_DotLine,
    PenStyle_DashDotLine,
    PenStyle_DashDotDotLine,
    PenStyle_MPenStyle = 15 { $f });
type
  PenCapStyle = (
    PenCapStyle_FlatCap = 0 { $0 },
    PenCapStyle_SquareCap = 16 { $10 },
    PenCapStyle_RoundCap = 32 { $20 },
    PenCapStyle_MPenCapStyle = 48 { $30 });
type
  PenJoinStyle = (
    PenJoinStyle_MiterJoin = 0 { $0 },
    PenJoinStyle_BevelJoin = 64 { $40 },
    PenJoinStyle_RoundJoin = 128 { $80 },
    PenJoinStyle_MPenJoinStyle = 192 { $c0 });
type
  BrushStyle = (
    BrushStyle_NoBrush,
    BrushStyle_SolidPattern,
    BrushStyle_Dense1Pattern,
    BrushStyle_Dense2Pattern,
    BrushStyle_Dense3Pattern,
    BrushStyle_Dense4Pattern,
    BrushStyle_Dense5Pattern,
    BrushStyle_Dense6Pattern,
    BrushStyle_Dense7Pattern,
    BrushStyle_HorPattern,
    BrushStyle_VerPattern,
    BrushStyle_CrossPattern,
    BrushStyle_BDiagPattern,
    BrushStyle_FDiagPattern,
    BrushStyle_DiagCrossPattern,
    BrushStyle_CustomPattern = 24 { $18 });
type
  WindowsVersion = (
    WindowsVersion_WV_32s = 1 { $1 },
    WindowsVersion_WV_95 = 2 { $2 },
    WindowsVersion_WV_98 = 3 { $3 },
    WindowsVersion_WV_DOS_based = 15 { $f },
    WindowsVersion_WV_NT = 16 { $10 },
    WindowsVersion_WV_2000 = 32 { $20 },
    WindowsVersion_WV_NT_based = 240 { $f0 });
type
  QInternalPaintDeviceFlags = (
    QInternalPaintDeviceFlags_UndefinedDevice = 0 { $0 },
    QInternalPaintDeviceFlags_Widget = 1 { $1 },
    QInternalPaintDeviceFlags_Pixmap = 2 { $2 },
    QInternalPaintDeviceFlags_Printer = 3 { $3 },
    QInternalPaintDeviceFlags_Picture = 4 { $4 },
    QInternalPaintDeviceFlags_System = 5 { $5 },
    QInternalPaintDeviceFlags_DeviceTypeMask = 15 { $f },
    QInternalPaintDeviceFlags_ExternalDevice = 16 { $10 });
type
  QTableFlags = (
    QTableFlags_vScrollBar = 1 { $1 },
    QTableFlags_hScrollBar = 2 { $2 },
    QTableFlags_autoVScrollBar = 4 { $4 },
    QTableFlags_autoHScrollBar = 8 { $8 },
    QTableFlags_autoScrollBars = 12 { $c },
    QTableFlags_clipCellPainting = 256 { $100 },
    QTableFlags_cutCellsV = 512 { $200 },
    QTableFlags_cutCellsH = 1024 { $400 },
    QTableFlags_cutCells = 1536 { $600 },
    QTableFlags_scrollLastHCell = 2048 { $800 },
    QTableFlags_scrollLastVCell = 4096 { $1000 },
    QTableFlags_scrollLastCell = 6144 { $1800 },
    QTableFlags_smoothHScrolling = 8192 { $2000 },
    QTableFlags_smoothVScrolling = 16384 { $4000 },
    QTableFlags_smoothScrolling = 24576 { $6000 },
    QTableFlags_snapToHGrid = 32768 { $8000 },
    QTableFlags_snapToVGrid = 65536 { $10000 },
    QTableFlags_snapToGrid = 98304 { $18000 });

type
  QClxFileDialogMode = ( QClxFileDialogMode_AnyFile, QClxFileDialogMode_ExistingFile, QClxFileDialogMode_Directory, QClxFileDialogMode_ExistingFiles, QClxFileDialogMode_DirectoryOnly );

type
  QClxFileDialogViewMode = ( QClxFileDialogViewMode_Detail, QClxFileDialogViewMode_List );

type
  QClxFileDialogPreviewMode = ( QClxFileDialogPreviewMode_NoPreview, QClxFileDialogPreviewMode_Contents, QClxFileDialogPreviewMode_Info );
function QWidget_create(parent: QWidgetH; name: PAnsiChar; f: WFlags): QWidgetH; cdecl;
procedure QWidget_destroy(handle: QWidgetH); cdecl;
function QWidget_winId(handle: QWidgetH): Cardinal; cdecl;
procedure QWidget_setName(handle: QWidgetH; name: PAnsiChar); cdecl;
function QWidget_style(handle: QWidgetH): QStyleH; cdecl;
procedure QWidget_setStyle(handle: QWidgetH; p1: QStyleH); cdecl;
function QWidget_isTopLevel(handle: QWidgetH): Boolean; cdecl;
function QWidget_isModal(handle: QWidgetH): Boolean; cdecl;
function QWidget_isPopup(handle: QWidgetH): Boolean; cdecl;
function QWidget_isDesktop(handle: QWidgetH): Boolean; cdecl;
function QWidget_isEnabled(handle: QWidgetH): Boolean; cdecl;
function QWidget_isEnabledTo(handle: QWidgetH; p1: QWidgetH): Boolean; cdecl;
function QWidget_isEnabledToTLW(handle: QWidgetH): Boolean; cdecl;
procedure QWidget_setEnabled(handle: QWidgetH; p1: Boolean); cdecl;
procedure QWidget_setDisabled(handle: QWidgetH; p1: Boolean); cdecl;
procedure QWidget_frameGeometry(handle: QWidgetH; retval: PRect); cdecl;
procedure QWidget_geometry(handle: QWidgetH; retval: PRect); cdecl;
function QWidget_x(handle: QWidgetH): Integer; cdecl;
function QWidget_y(handle: QWidgetH): Integer; cdecl;
procedure QWidget_pos(handle: QWidgetH; retval: PPoint); cdecl;
procedure QWidget_frameSize(handle: QWidgetH; retval: PSize); cdecl;
procedure QWidget_size(handle: QWidgetH; retval: PSize); cdecl;
function QWidget_width(handle: QWidgetH): Integer; cdecl;
function QWidget_height(handle: QWidgetH): Integer; cdecl;
procedure QWidget_rect(handle: QWidgetH; retval: PRect); cdecl;
procedure QWidget_childrenRect(handle: QWidgetH; retval: PRect); cdecl;
procedure QWidget_childrenRegion(handle: QWidgetH; retval: QRegionH); cdecl;
procedure QWidget_minimumSize(handle: QWidgetH; retval: PSize); cdecl;
procedure QWidget_maximumSize(handle: QWidgetH; retval: PSize); cdecl;
function QWidget_minimumWidth(handle: QWidgetH): Integer; cdecl;
function QWidget_minimumHeight(handle: QWidgetH): Integer; cdecl;
function QWidget_maximumWidth(handle: QWidgetH): Integer; cdecl;
function QWidget_maximumHeight(handle: QWidgetH): Integer; cdecl;
procedure QWidget_setMinimumSize(handle: QWidgetH; p1: PSize); overload; cdecl;
procedure QWidget_setMinimumSize(handle: QWidgetH; minw: Integer; minh: Integer); overload; cdecl;
procedure QWidget_setMaximumSize(handle: QWidgetH; p1: PSize); overload; cdecl;
procedure QWidget_setMaximumSize(handle: QWidgetH; maxw: Integer; maxh: Integer); overload; cdecl;
procedure QWidget_setMinimumWidth(handle: QWidgetH; minw: Integer); cdecl;
procedure QWidget_setMinimumHeight(handle: QWidgetH; minh: Integer); cdecl;
procedure QWidget_setMaximumWidth(handle: QWidgetH; maxw: Integer); cdecl;
procedure QWidget_setMaximumHeight(handle: QWidgetH; maxh: Integer); cdecl;
procedure QWidget_sizeIncrement(handle: QWidgetH; retval: PSize); cdecl;
procedure QWidget_setSizeIncrement(handle: QWidgetH; p1: PSize); overload; cdecl;
procedure QWidget_setSizeIncrement(handle: QWidgetH; w: Integer; h: Integer); overload; cdecl;
procedure QWidget_baseSize(handle: QWidgetH; retval: PSize); cdecl;
procedure QWidget_setBaseSize(handle: QWidgetH; p1: PSize); overload; cdecl;
procedure QWidget_setBaseSize(handle: QWidgetH; basew: Integer; baseh: Integer); overload; cdecl;
procedure QWidget_setFixedSize(handle: QWidgetH; p1: PSize); overload; cdecl;
procedure QWidget_setFixedSize(handle: QWidgetH; w: Integer; h: Integer); overload; cdecl;
procedure QWidget_setFixedWidth(handle: QWidgetH; w: Integer); cdecl;
procedure QWidget_setFixedHeight(handle: QWidgetH; h: Integer); cdecl;
procedure QWidget_mapToGlobal(handle: QWidgetH; retval: PPoint; p1: PPoint); cdecl;
procedure QWidget_mapFromGlobal(handle: QWidgetH; retval: PPoint; p1: PPoint); cdecl;
procedure QWidget_mapToParent(handle: QWidgetH; retval: PPoint; p1: PPoint); cdecl;
procedure QWidget_mapFromParent(handle: QWidgetH; retval: PPoint; p1: PPoint); cdecl;
procedure QWidget_mapTo(handle: QWidgetH; retval: PPoint; p1: QWidgetH; p2: PPoint); cdecl;
procedure QWidget_mapFrom(handle: QWidgetH; retval: PPoint; p1: QWidgetH; p2: PPoint); cdecl;
function QWidget_topLevelWidget(handle: QWidgetH): QWidgetH; cdecl;
function QWidget_backgroundMode(handle: QWidgetH): QWidgetBackgroundMode; cdecl;
procedure QWidget_setBackgroundMode(handle: QWidgetH; p1: QWidgetBackgroundMode); cdecl;
function QWidget_backgroundColor(handle: QWidgetH): QColorH; cdecl;
function QWidget_foregroundColor(handle: QWidgetH): QColorH; cdecl;
procedure QWidget_setBackgroundColor(handle: QWidgetH; p1: QColorH); cdecl;
function QWidget_backgroundPixmap(handle: QWidgetH): QPixmapH; cdecl;
procedure QWidget_setBackgroundPixmap(handle: QWidgetH; p1: QPixmapH); cdecl;
function QWidget_colorGroup(handle: QWidgetH): QColorGroupH; cdecl;
function QWidget_palette(handle: QWidgetH): QPaletteH; cdecl;
function QWidget_ownPalette(handle: QWidgetH): Boolean; cdecl;
procedure QWidget_setPalette(handle: QWidgetH; p1: QPaletteH); overload; cdecl;
procedure QWidget_unsetPalette(handle: QWidgetH); cdecl;
procedure QWidget_font(handle: QWidgetH; retval: QFontH); cdecl;
function QWidget_ownFont(handle: QWidgetH): Boolean; cdecl;
procedure QWidget_setFont(handle: QWidgetH; p1: QFontH); overload; cdecl;
procedure QWidget_unsetFont(handle: QWidgetH); cdecl;
procedure QWidget_fontMetrics(handle: QWidgetH; retval: QFontMetricsH); cdecl;
procedure QWidget_fontInfo(handle: QWidgetH; retval: QFontInfoH); cdecl;
function QWidget_fontPropagation(handle: QWidgetH): QWidgetPropagationMode; cdecl;
procedure QWidget_setFontPropagation(handle: QWidgetH; p1: QWidgetPropagationMode); cdecl;
function QWidget_palettePropagation(handle: QWidgetH): QWidgetPropagationMode; cdecl;
procedure QWidget_setPalettePropagation(handle: QWidgetH; p1: QWidgetPropagationMode); cdecl;
function QWidget_cursor(handle: QWidgetH): QCursorH; cdecl;
function QWidget_ownCursor(handle: QWidgetH): Boolean; cdecl;
procedure QWidget_setCursor(handle: QWidgetH; p1: QCursorH); cdecl;
procedure QWidget_unsetCursor(handle: QWidgetH); cdecl;
procedure QWidget_caption(handle: QWidgetH; retval: PWideString); cdecl;
function QWidget_icon(handle: QWidgetH): QPixmapH; cdecl;
procedure QWidget_iconText(handle: QWidgetH; retval: PWideString); cdecl;
function QWidget_hasMouseTracking(handle: QWidgetH): Boolean; cdecl;
procedure QWidget_setMask(handle: QWidgetH; p1: QBitmapH); overload; cdecl;
procedure QWidget_setMask(handle: QWidgetH; p1: QRegionH); overload; cdecl;
procedure QWidget_clearMask(handle: QWidgetH); cdecl;
procedure QWidget_setCaption(handle: QWidgetH; p1: PWideString); cdecl;
procedure QWidget_setIcon(handle: QWidgetH; p1: QPixmapH); cdecl;
procedure QWidget_setIconText(handle: QWidgetH; p1: PWideString); cdecl;
procedure QWidget_setMouseTracking(handle: QWidgetH; enable: Boolean); cdecl;
procedure QWidget_setFocus(handle: QWidgetH); cdecl;
procedure QWidget_clearFocus(handle: QWidgetH); cdecl;
function QWidget_isActiveWindow(handle: QWidgetH): Boolean; cdecl;
procedure QWidget_setActiveWindow(handle: QWidgetH); cdecl;
function QWidget_isFocusEnabled(handle: QWidgetH): Boolean; cdecl;
function QWidget_focusPolicy(handle: QWidgetH): QWidgetFocusPolicy; cdecl;
procedure QWidget_setFocusPolicy(handle: QWidgetH; p1: QWidgetFocusPolicy); cdecl;
function QWidget_hasFocus(handle: QWidgetH): Boolean; cdecl;
procedure QWidget_setTabOrder(p1: QWidgetH; p2: QWidgetH); cdecl;
procedure QWidget_setFocusProxy(handle: QWidgetH; p1: QWidgetH); cdecl;
function QWidget_focusProxy(handle: QWidgetH): QWidgetH; cdecl;
procedure QWidget_grabMouse(handle: QWidgetH); overload; cdecl;
procedure QWidget_grabMouse(handle: QWidgetH; p1: QCursorH); overload; cdecl;
procedure QWidget_releaseMouse(handle: QWidgetH); cdecl;
procedure QWidget_grabKeyboard(handle: QWidgetH); cdecl;
procedure QWidget_releaseKeyboard(handle: QWidgetH); cdecl;
function QWidget_mouseGrabber(): QWidgetH; cdecl;
function QWidget_keyboardGrabber(): QWidgetH; cdecl;
function QWidget_isUpdatesEnabled(handle: QWidgetH): Boolean; cdecl;
procedure QWidget_repaintUnclipped(handle: QWidgetH; p1: QRegionH; erase: Boolean); cdecl;
procedure QWidget_setUpdatesEnabled(handle: QWidgetH; enable: Boolean); cdecl;
procedure QWidget_update(handle: QWidgetH); overload; cdecl;
procedure QWidget_update(handle: QWidgetH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QWidget_update(handle: QWidgetH; p1: PRect); overload; cdecl;
procedure QWidget_repaint(handle: QWidgetH); overload; cdecl;
procedure QWidget_repaint(handle: QWidgetH; erase: Boolean); overload; cdecl;
procedure QWidget_repaint(handle: QWidgetH; x: Integer; y: Integer; w: Integer; h: Integer; erase: Boolean); overload; cdecl;
procedure QWidget_repaint(handle: QWidgetH; p1: PRect; erase: Boolean); overload; cdecl;
procedure QWidget_repaint(handle: QWidgetH; p1: QRegionH; erase: Boolean); overload; cdecl;
procedure QWidget_show(handle: QWidgetH); cdecl;
procedure QWidget_hide(handle: QWidgetH); cdecl;
procedure QWidget_iconify(handle: QWidgetH); cdecl;
procedure QWidget_showMinimized(handle: QWidgetH); cdecl;
procedure QWidget_showMaximized(handle: QWidgetH); cdecl;
procedure QWidget_showFullScreen(handle: QWidgetH); cdecl;
procedure QWidget_showNormal(handle: QWidgetH); cdecl;
procedure QWidget_polish(handle: QWidgetH); cdecl;
procedure QWidget_constPolish(handle: QWidgetH); cdecl;
function QWidget_close(handle: QWidgetH): Boolean; overload; cdecl;
procedure QWidget_raise(handle: QWidgetH); cdecl;
procedure QWidget_lower(handle: QWidgetH); cdecl;
procedure QWidget_stackUnder(handle: QWidgetH; p1: QWidgetH); cdecl;
procedure QWidget_move(handle: QWidgetH; x: Integer; y: Integer); overload; cdecl;
procedure QWidget_move(handle: QWidgetH; p1: PPoint); overload; cdecl;
procedure QWidget_resize(handle: QWidgetH; w: Integer; h: Integer); overload; cdecl;
procedure QWidget_resize(handle: QWidgetH; p1: PSize); overload; cdecl;
procedure QWidget_setGeometry(handle: QWidgetH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QWidget_setGeometry(handle: QWidgetH; p1: PRect); overload; cdecl;
function QWidget_close(handle: QWidgetH; alsoDelete: Boolean): Boolean; overload; cdecl;
function QWidget_isVisible(handle: QWidgetH): Boolean; cdecl;
function QWidget_isVisibleTo(handle: QWidgetH; p1: QWidgetH): Boolean; cdecl;
function QWidget_isVisibleToTLW(handle: QWidgetH): Boolean; cdecl;
procedure QWidget_visibleRect(handle: QWidgetH; retval: PRect); cdecl;
function QWidget_isHidden(handle: QWidgetH): Boolean; cdecl;
function QWidget_isMinimized(handle: QWidgetH): Boolean; cdecl;
function QWidget_isMaximized(handle: QWidgetH): Boolean; cdecl;
procedure QWidget_sizeHint(handle: QWidgetH; retval: PSize); cdecl;
procedure QWidget_minimumSizeHint(handle: QWidgetH; retval: PSize); cdecl;
procedure QWidget_sizePolicy(handle: QWidgetH; retval: PSizePolicy); cdecl;
procedure QWidget_setSizePolicy(handle: QWidgetH; p1: PSizePolicy); cdecl;
function QWidget_heightForWidth(handle: QWidgetH; p1: Integer): Integer; cdecl;
procedure QWidget_adjustSize(handle: QWidgetH); cdecl;
function QWidget_layout(handle: QWidgetH): QLayoutH; cdecl;
procedure QWidget_updateGeometry(handle: QWidgetH); cdecl;
procedure QWidget_reparent(handle: QWidgetH; parent: QWidgetH; p2: WFlags; p3: PPoint; showIt: Boolean); overload; cdecl;
procedure QWidget_reparent(handle: QWidgetH; parent: QWidgetH; p2: PPoint; showIt: Boolean); overload; cdecl;
procedure QWidget_recreate(handle: QWidgetH; parent: QWidgetH; f: WFlags; p: PPoint; showIt: Boolean); cdecl;
procedure QWidget_erase(handle: QWidgetH); overload; cdecl;
procedure QWidget_erase(handle: QWidgetH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QWidget_erase(handle: QWidgetH; p1: PRect); overload; cdecl;
procedure QWidget_erase(handle: QWidgetH; p1: QRegionH); overload; cdecl;
procedure QWidget_scroll(handle: QWidgetH; dx: Integer; dy: Integer); overload; cdecl;
procedure QWidget_scroll(handle: QWidgetH; dx: Integer; dy: Integer; p3: PRect); overload; cdecl;
procedure QWidget_drawText(handle: QWidgetH; x: Integer; y: Integer; p3: PWideString); overload; cdecl;
procedure QWidget_drawText(handle: QWidgetH; p1: PPoint; p2: PWideString); overload; cdecl;
function QWidget_focusWidget(handle: QWidgetH): QWidgetH; cdecl;
procedure QWidget_microFocusHint(handle: QWidgetH; retval: PRect); cdecl;
function QWidget_acceptDrops(handle: QWidgetH): Boolean; cdecl;
procedure QWidget_setAcceptDrops(handle: QWidgetH; on: Boolean); cdecl;
procedure QWidget_setAutoMask(handle: QWidgetH; p1: Boolean); cdecl;
function QWidget_autoMask(handle: QWidgetH): Boolean; cdecl;
procedure QWidget_setBackgroundOrigin(handle: QWidgetH; p1: QWidgetBackgroundOrigin); cdecl;
function QWidget_backgroundOrigin(handle: QWidgetH): QWidgetBackgroundOrigin; cdecl;
function QWidget_customWhatsThis(handle: QWidgetH): Boolean; cdecl;
function QWidget_parentWidget(handle: QWidgetH): QWidgetH; cdecl;
function QWidget_testWState(handle: QWidgetH; n: Cardinal): Boolean; cdecl;
function QWidget_testWFlags(handle: QWidgetH; f: WFlags): Boolean; cdecl;
function QWidget_find(p1: Cardinal): QWidgetH; cdecl;
function QWidget_wmapper(): QWidgetMapperH; cdecl;

procedure QWidget_setPalette(handle: QWidgetH; p1: QPaletteH; iReallyMeanIt: Boolean); overload; cdecl;
procedure QWidget_setFont(handle: QWidgetH; p1: QFontH; iReallyMeanIt: Boolean); overload; cdecl;
function QWidget_to_QPaintDevice(handle: QWidgetH): QPaintDeviceH; cdecl;

function QApplication_argc(handle: QApplicationH): Integer; cdecl;
function QApplication_argv(handle: QApplicationH): PPAnsiChar; cdecl;
function QApplication_style(): QStyleH; cdecl;
procedure QApplication_setStyle(p1: QStyleH); cdecl;

function QApplication_colorSpec(): Integer; cdecl;
procedure QApplication_setColorSpec(p1: Integer); cdecl;
function QApplication_overrideCursor(): QCursorH; cdecl;
procedure QApplication_setOverrideCursor(p1: QCursorH; replace: Boolean); cdecl;
procedure QApplication_restoreOverrideCursor(); cdecl;
function QApplication_hasGlobalMouseTracking(): Boolean; cdecl;
procedure QApplication_setGlobalMouseTracking(enable: Boolean); cdecl;
procedure QApplication_palette(retval: QPaletteH; p1: QWidgetH); cdecl;
procedure QApplication_setPalette(p1: QPaletteH; informWidgets: Boolean; className: PAnsiChar); cdecl;
procedure QApplication_font(retval: QFontH; p1: QWidgetH); cdecl;
procedure QApplication_setFont(p1: QFontH; informWidgets: Boolean; className: PAnsiChar); cdecl;
procedure QApplication_fontMetrics(retval: QFontMetricsH); cdecl;
function QApplication_mainWidget(handle: QApplicationH): QWidgetH; cdecl;
procedure QApplication_setMainWidget(handle: QApplicationH; p1: QWidgetH); cdecl;
procedure QApplication_polish(handle: QApplicationH; p1: QWidgetH); cdecl;
function QApplication_allWidgets(): QWidgetListH; cdecl;
function QApplication_topLevelWidgets(): QWidgetListH; cdecl;
function QApplication_desktop(): QWidgetH; cdecl;
function QApplication_activePopupWidget(): QWidgetH; cdecl;
function QApplication_activeModalWidget(): QWidgetH; cdecl;
function QApplication_clipboard(): QClipboardH; cdecl;
function QApplication_focusWidget(handle: QApplicationH): QWidgetH; cdecl;
function QApplication_activeWindow(handle: QApplicationH): QWidgetH; cdecl;
function QApplication_widgetAt(x: Integer; y: Integer; child: Boolean): QWidgetH; overload; cdecl;
function QApplication_widgetAt(p1: PPoint; child: Boolean): QWidgetH; overload; cdecl;
function QApplication_exec(handle: QApplicationH): Integer; cdecl;
procedure QApplication_processEvents(handle: QApplicationH); overload; cdecl;
procedure QApplication_processEvents(handle: QApplicationH; maxtime: Integer); overload; cdecl;
procedure QApplication_processOneEvent(handle: QApplicationH); cdecl;
function QApplication_enter_loop(handle: QApplicationH): Integer; cdecl;
procedure QApplication_exit_loop(handle: QApplicationH); cdecl;
function QApplication_loopLevel(handle: QApplicationH): Integer; cdecl;
procedure QApplication_exit(retcode: Integer); cdecl;
function QApplication_sendEvent(receiver: QObjectH; event: QEventH): Boolean; cdecl;
procedure QApplication_postEvent(receiver: QObjectH; event: QEventH); cdecl;
procedure QApplication_sendPostedEvents(receiver: QObjectH; event_type: Integer); overload; cdecl;
procedure QApplication_sendPostedEvents(); overload; cdecl;
procedure QApplication_removePostedEvents(receiver: QObjectH); cdecl;
function QApplication_notify(handle: QApplicationH; p1: QObjectH; p2: QEventH): Boolean; cdecl;
function QApplication_startingUp(): Boolean; cdecl;
function QApplication_closingDown(): Boolean; cdecl;
procedure QApplication_flushX(); cdecl;
procedure QApplication_syncX(); cdecl;
procedure QApplication_beep(); cdecl;
procedure QApplication_setDefaultCodec(handle: QApplicationH; p1: QTextCodecH); cdecl;
function QApplication_defaultCodec(handle: QApplicationH): QTextCodecH; cdecl;
procedure QApplication_installTranslator(handle: QApplicationH; p1: QTranslatorH); cdecl;
procedure QApplication_removeTranslator(handle: QApplicationH; p1: QTranslatorH); cdecl;
procedure QApplication_translate(handle: QApplicationH; retval: PWideString; p1: PAnsiChar; p2: PAnsiChar); overload; cdecl;
procedure QApplication_translate(handle: QApplicationH; retval: PWideString; p1: PAnsiChar; p2: PAnsiChar; p3: PAnsiChar); overload; cdecl;
procedure QApplication_setWinStyleHighlightColor(p1: QColorH); cdecl;
function QApplication_winStyleHighlightColor(): QColorH; cdecl;
procedure QApplication_setDesktopSettingsAware(p1: Boolean); cdecl;
function QApplication_desktopSettingsAware(): Boolean; cdecl;
procedure QApplication_setCursorFlashTime(p1: Integer); cdecl;
function QApplication_cursorFlashTime(): Integer; cdecl;
procedure QApplication_setDoubleClickInterval(p1: Integer); cdecl;
function QApplication_doubleClickInterval(): Integer; cdecl;
procedure QApplication_setWheelScrollLines(p1: Integer); cdecl;
function QApplication_wheelScrollLines(): Integer; cdecl;
procedure QApplication_setGlobalStrut(p1: PSize); cdecl;
procedure QApplication_globalStrut(retval: PSize); cdecl;
procedure QApplication_setStartDragTime(ms: Integer); cdecl;
function QApplication_startDragTime(): Integer; cdecl;
procedure QApplication_setStartDragDistance(l: Integer); cdecl;
function QApplication_startDragDistance(): Integer; cdecl;
function QApplication_isEffectEnabled(p1: UIEffect): Boolean; cdecl;
procedure QApplication_setEffectEnabled(p1: UIEffect; enable: Boolean); cdecl;
procedure QApplication_do_mouse_down(handle: QApplicationH; p1: Pointer); cdecl;

function QApplication_macProcessEvent(handle: QApplicationH; p1: PMsg): Integer; cdecl;
function QApplication_winEventFilter(handle: QApplicationH; p1: PMsg): Boolean; cdecl;

function QApplication_winVersion(): WindowsVersion; cdecl;
procedure QApplication_winFocus(handle: QApplicationH; p1: QWidgetH; p2: Boolean); cdecl;
procedure QApplication_winMouseButtonUp(); cdecl;
function QApplication_isSessionRestored(handle: QApplicationH): Boolean; cdecl;
procedure QApplication_sessionId(handle: QApplicationH; retval: PWideString); cdecl;
procedure QApplication_commitData(handle: QApplicationH; sm: QSessionManagerH); cdecl;
procedure QApplication_saveState(handle: QApplicationH; sm: QSessionManagerH); cdecl;
procedure QApplication_create_xim(); cdecl;
procedure QApplication_close_xim(); cdecl;
procedure QApplication_wakeUpGuiThread(handle: QApplicationH); cdecl;

procedure QApplication_quit(handle: QApplicationH); cdecl;
procedure QApplication_closeAllWindows(handle: QApplicationH); cdecl;

function QButton_create(parent: QWidgetH; name: PAnsiChar; f: WFlags): QButtonH; cdecl;
procedure QButton_destroy(handle: QButtonH); cdecl;
procedure QButton_text(handle: QButtonH; retval: PWideString); cdecl;
procedure QButton_setText(handle: QButtonH; p1: PWideString); cdecl;
function QButton_pixmap(handle: QButtonH): QPixmapH; cdecl;
procedure QButton_setPixmap(handle: QButtonH; p1: QPixmapH); cdecl;
function QButton_accel(handle: QButtonH): Integer; cdecl;
procedure QButton_setAccel(handle: QButtonH; p1: Integer); cdecl;
function QButton_isToggleButton(handle: QButtonH): Boolean; cdecl;
function QButton_toggleType(handle: QButtonH): QButtonToggleType; cdecl;
procedure QButton_setDown(handle: QButtonH; p1: Boolean); cdecl;
function QButton_isDown(handle: QButtonH): Boolean; cdecl;
function QButton_isOn(handle: QButtonH): Boolean; cdecl;
function QButton_state(handle: QButtonH): QButtonToggleState; cdecl;
function QButton_autoResize(handle: QButtonH): Boolean; cdecl;
procedure QButton_setAutoResize(handle: QButtonH; p1: Boolean); cdecl;
function QButton_autoRepeat(handle: QButtonH): Boolean; cdecl;
procedure QButton_setAutoRepeat(handle: QButtonH; p1: Boolean); cdecl;
function QButton_isExclusiveToggle(handle: QButtonH): Boolean; cdecl;
function QButton_focusNextPrevChild(handle: QButtonH; next: Boolean): Boolean; cdecl;
function QButton_group(handle: QButtonH): QButtonGroupH; cdecl;
procedure QButton_animateClick(handle: QButtonH); cdecl;
procedure QButton_toggle(handle: QButtonH); cdecl;

function QComboBox_create(parent: QWidgetH; name: PAnsiChar): QComboBoxH; overload; cdecl;
procedure QComboBox_destroy(handle: QComboBoxH); cdecl;
function QComboBox_create(rw: Boolean; parent: QWidgetH; name: PAnsiChar): QComboBoxH; overload; cdecl;
function QComboBox_count(handle: QComboBoxH): Integer; cdecl;
procedure QComboBox_insertStringList(handle: QComboBoxH; p1: QStringListH; index: Integer); cdecl;
procedure QComboBox_insertStrList(handle: QComboBoxH; p1: QStrListH; index: Integer); overload; cdecl;
procedure QComboBox_insertStrList(handle: QComboBoxH; p1: PPAnsiChar; numStrings: Integer; index: Integer); overload; cdecl;
procedure QComboBox_insertItem(handle: QComboBoxH; text: PWideString; index: Integer); overload; cdecl;
procedure QComboBox_insertItem(handle: QComboBoxH; pixmap: QPixmapH; index: Integer); overload; cdecl;
procedure QComboBox_insertItem(handle: QComboBoxH; pixmap: QPixmapH; text: PWideString; index: Integer); overload; cdecl;
procedure QComboBox_removeItem(handle: QComboBoxH; index: Integer); cdecl;
procedure QComboBox_clear(handle: QComboBoxH); cdecl;
procedure QComboBox_currentText(handle: QComboBoxH; retval: PWideString); cdecl;
procedure QComboBox_text(handle: QComboBoxH; retval: PWideString; index: Integer); cdecl;
function QComboBox_pixmap(handle: QComboBoxH; index: Integer): QPixmapH; cdecl;
procedure QComboBox_changeItem(handle: QComboBoxH; text: PWideString; index: Integer); overload; cdecl;
procedure QComboBox_changeItem(handle: QComboBoxH; pixmap: QPixmapH; index: Integer); overload; cdecl;
procedure QComboBox_changeItem(handle: QComboBoxH; pixmap: QPixmapH; text: PWideString; index: Integer); overload; cdecl;
function QComboBox_currentItem(handle: QComboBoxH): Integer; cdecl;
procedure QComboBox_setCurrentItem(handle: QComboBoxH; index: Integer); cdecl;
function QComboBox_autoResize(handle: QComboBoxH): Boolean; cdecl;
procedure QComboBox_setAutoResize(handle: QComboBoxH; p1: Boolean); cdecl;
procedure QComboBox_sizeHint(handle: QComboBoxH; retval: PSize); cdecl;
procedure QComboBox_sizePolicy(handle: QComboBoxH; retval: PSizePolicy); cdecl;
procedure QComboBox_setBackgroundColor(handle: QComboBoxH; p1: QColorH); cdecl;
procedure QComboBox_setPalette(handle: QComboBoxH; p1: QPaletteH); cdecl;
procedure QComboBox_setFont(handle: QComboBoxH; p1: QFontH); cdecl;
procedure QComboBox_setEnabled(handle: QComboBoxH; p1: Boolean); cdecl;
procedure QComboBox_setSizeLimit(handle: QComboBoxH; p1: Integer); cdecl;
function QComboBox_sizeLimit(handle: QComboBoxH): Integer; cdecl;
procedure QComboBox_setMaxCount(handle: QComboBoxH; p1: Integer); cdecl;
function QComboBox_maxCount(handle: QComboBoxH): Integer; cdecl;
procedure QComboBox_setInsertionPolicy(handle: QComboBoxH; policy: QComboBoxPolicy); cdecl;
function QComboBox_insertionPolicy(handle: QComboBoxH): QComboBoxPolicy; cdecl;
procedure QComboBox_setValidator(handle: QComboBoxH; p1: QValidatorH); cdecl;
function QComboBox_validator(handle: QComboBoxH): QValidatorH; cdecl;
procedure QComboBox_setListBox(handle: QComboBoxH; p1: QListBoxH); cdecl;
function QComboBox_listBox(handle: QComboBoxH): QListBoxH; cdecl;
function QComboBox_lineEdit(handle: QComboBoxH): QLineEditH; cdecl;
procedure QComboBox_setAutoCompletion(handle: QComboBoxH; p1: Boolean); cdecl;
function QComboBox_autoCompletion(handle: QComboBoxH): Boolean; cdecl;
function QComboBox_eventFilter(handle: QComboBoxH; AnObject: QObjectH; event: QEventH): Boolean; cdecl;
procedure QComboBox_setDuplicatesEnabled(handle: QComboBoxH; enable: Boolean); cdecl;
function QComboBox_duplicatesEnabled(handle: QComboBoxH): Boolean; cdecl;
function QComboBox_editable(handle: QComboBoxH): Boolean; cdecl;
procedure QComboBox_setEditable(handle: QComboBoxH; p1: Boolean); cdecl;
procedure QComboBox_clearValidator(handle: QComboBoxH); cdecl;
procedure QComboBox_clearEdit(handle: QComboBoxH); cdecl;
procedure QComboBox_setEditText(handle: QComboBoxH; p1: PWideString); cdecl;

function QDialog_create(parent: QWidgetH; name: PAnsiChar; modal: Boolean; f: WFlags): QDialogH; cdecl;
procedure QDialog_destroy(handle: QDialogH); cdecl;
function QDialog_exec(handle: QDialogH): Integer; cdecl;
function QDialog_result(handle: QDialogH): Integer; cdecl;
procedure QDialog_show(handle: QDialogH); cdecl;
procedure QDialog_hide(handle: QDialogH); cdecl;
procedure QDialog_move(handle: QDialogH; x: Integer; y: Integer); overload; cdecl;
procedure QDialog_move(handle: QDialogH; p: PPoint); overload; cdecl;
procedure QDialog_resize(handle: QDialogH; w: Integer; h: Integer); overload; cdecl;
procedure QDialog_resize(handle: QDialogH; p1: PSize); overload; cdecl;
procedure QDialog_setGeometry(handle: QDialogH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QDialog_setGeometry(handle: QDialogH; p1: PRect); overload; cdecl;
procedure QDialog_setOrientation(handle: QDialogH; orientation: Orientation); cdecl;
function QDialog_orientation(handle: QDialogH): Orientation; cdecl;
procedure QDialog_setExtension(handle: QDialogH; extension: QWidgetH); cdecl;
function QDialog_extension(handle: QDialogH): QWidgetH; cdecl;
procedure QDialog_sizeHint(handle: QDialogH; retval: PSize); cdecl;
procedure QDialog_minimumSizeHint(handle: QDialogH; retval: PSize); cdecl;
procedure QDialog_setSizeGripEnabled(handle: QDialogH; p1: Boolean); cdecl;
function QDialog_isSizeGripEnabled(handle: QDialogH): Boolean; cdecl;

procedure QDragObject_destroy(handle: QDragObjectH); cdecl;
function QDragObject_drag(handle: QDragObjectH): Boolean; cdecl;
function QDragObject_dragMove(handle: QDragObjectH): Boolean; cdecl;
procedure QDragObject_dragCopy(handle: QDragObjectH); cdecl;
procedure QDragObject_setPixmap(handle: QDragObjectH; p1: QPixmapH); overload; cdecl;
procedure QDragObject_setPixmap(handle: QDragObjectH; p1: QPixmapH; hotspot: PPoint); overload; cdecl;
procedure QDragObject_pixmap(handle: QDragObjectH; retval: QPixmapH); cdecl;
procedure QDragObject_pixmapHotSpot(handle: QDragObjectH; retval: PPoint); cdecl;
function QDragObject_source(handle: QDragObjectH): QWidgetH; cdecl;
function QDragObject_target(): QWidgetH; cdecl;
procedure QDragObject_setTarget(p1: QWidgetH); cdecl;
function QDragObject_to_QMimeSource(handle: QDragObjectH): QMimeSourceH; cdecl;
function QStoredDrag_create(mimeType: PAnsiChar; dragSource: QWidgetH; name: PAnsiChar): QStoredDragH; cdecl;
procedure QStoredDrag_destroy(handle: QStoredDragH); cdecl;
procedure QStoredDrag_setEncodedData(handle: QStoredDragH; p1: QByteArrayH); cdecl;
function QStoredDrag_format(handle: QStoredDragH; i: Integer): PAnsiChar; cdecl;
procedure QStoredDrag_encodedData(handle: QStoredDragH; retval: QByteArrayH; p1: PAnsiChar); cdecl;

function QTextDrag_create(p1: PWideString; dragSource: QWidgetH; name: PAnsiChar): QTextDragH; overload; cdecl;
procedure QTextDrag_destroy(handle: QTextDragH); cdecl;
function QTextDrag_create(dragSource: QWidgetH; name: PAnsiChar): QTextDragH; overload; cdecl;
procedure QTextDrag_setText(handle: QTextDragH; p1: PWideString); cdecl;
procedure QTextDrag_setSubtype(handle: QTextDragH; p1: PAnsiString); cdecl;
function QTextDrag_format(handle: QTextDragH; i: Integer): PAnsiChar; cdecl;
procedure QTextDrag_encodedData(handle: QTextDragH; retval: QByteArrayH; p1: PAnsiChar); cdecl;
function QTextDrag_canDecode(e: QMimeSourceH): Boolean; cdecl;
function QTextDrag_decode(e: QMimeSourceH; s: PWideString): Boolean; overload; cdecl;
function QTextDrag_decode(e: QMimeSourceH; s: PWideString; subtype: PAnsiString): Boolean; overload; cdecl;

function QImageDrag_create(image: QImageH; dragSource: QWidgetH; name: PAnsiChar): QImageDragH; overload; cdecl;
procedure QImageDrag_destroy(handle: QImageDragH); cdecl;
function QImageDrag_create(dragSource: QWidgetH; name: PAnsiChar): QImageDragH; overload; cdecl;
procedure QImageDrag_setImage(handle: QImageDragH; image: QImageH); cdecl;
function QImageDrag_format(handle: QImageDragH; i: Integer): PAnsiChar; cdecl;
procedure QImageDrag_encodedData(handle: QImageDragH; retval: QByteArrayH; p1: PAnsiChar); cdecl;
function QImageDrag_canDecode(e: QMimeSourceH): Boolean; cdecl;
function QImageDrag_decode(e: QMimeSourceH; i: QImageH): Boolean; overload; cdecl;
function QImageDrag_decode(e: QMimeSourceH; i: QPixmapH): Boolean; overload; cdecl;

function QUriDrag_create(uris: QStrListH; dragSource: QWidgetH; name: PAnsiChar): QUriDragH; overload; cdecl;
procedure QUriDrag_destroy(handle: QUriDragH); cdecl;
function QUriDrag_create(dragSource: QWidgetH; name: PAnsiChar): QUriDragH; overload; cdecl;
procedure QUriDrag_setFilenames(handle: QUriDragH; fnames: QStringListH); cdecl;
procedure QUriDrag_setUnicodeUris(handle: QUriDragH; uuris: QStringListH); cdecl;
procedure QUriDrag_setUris(handle: QUriDragH; uris: QStrListH); cdecl;
procedure QUriDrag_uriToLocalFile(retval: PWideString; p1: PAnsiChar); cdecl;
procedure QUriDrag_localFileToUri(retval: PAnsiString; p1: PWideString); cdecl;
procedure QUriDrag_uriToUnicodeUri(retval: PWideString; p1: PAnsiChar); cdecl;
procedure QUriDrag_unicodeUriToUri(retval: PAnsiString; p1: PWideString); cdecl;
function QUriDrag_canDecode(e: QMimeSourceH): Boolean; cdecl;
function QUriDrag_decode(e: QMimeSourceH; i: QStrListH): Boolean; cdecl;
function QUriDrag_decodeToUnicodeUris(e: QMimeSourceH; i: QStringListH): Boolean; cdecl;
function QUriDrag_decodeLocalFiles(e: QMimeSourceH; i: QStringListH): Boolean; cdecl;

function QColorDrag_create(col: QColorH; dragsource: QWidgetH; name: PAnsiChar): QColorDragH; overload; cdecl;
procedure QColorDrag_destroy(handle: QColorDragH); cdecl;
function QColorDrag_create(dragSource: QWidgetH; name: PAnsiChar): QColorDragH; overload; cdecl;
procedure QColorDrag_setColor(handle: QColorDragH; col: QColorH); cdecl;
function QColorDrag_canDecode(p1: QMimeSourceH): Boolean; cdecl;
function QColorDrag_decode(p1: QMimeSourceH; col: QColorH): Boolean; cdecl;

function QEvent_create(_type: QEventType): QEventH; cdecl;
procedure QEvent_destroy(handle: QEventH); cdecl;
function QEvent_type(handle: QEventH): QEventType; cdecl;

function QTimerEvent_create(timerId: Integer): QTimerEventH; cdecl;
procedure QTimerEvent_destroy(handle: QTimerEventH); cdecl;
function QTimerEvent_timerId(handle: QTimerEventH): Integer; cdecl;

function QMouseEvent_create(_type: QEventType; pos: PPoint; button: Integer; state: Integer): QMouseEventH; overload; cdecl;
procedure QMouseEvent_destroy(handle: QMouseEventH); cdecl;
function QMouseEvent_create(_type: QEventType; pos: PPoint; globalPos: PPoint; button: Integer; state: Integer): QMouseEventH; overload; cdecl;
function QMouseEvent_pos(handle: QMouseEventH): PPoint; cdecl;
function QMouseEvent_globalPos(handle: QMouseEventH): PPoint; cdecl;
function QMouseEvent_x(handle: QMouseEventH): Integer; cdecl;
function QMouseEvent_y(handle: QMouseEventH): Integer; cdecl;
function QMouseEvent_globalX(handle: QMouseEventH): Integer; cdecl;
function QMouseEvent_globalY(handle: QMouseEventH): Integer; cdecl;
function QMouseEvent_button(handle: QMouseEventH): ButtonState; cdecl;
function QMouseEvent_state(handle: QMouseEventH): ButtonState; cdecl;
function QMouseEvent_stateAfter(handle: QMouseEventH): ButtonState; cdecl;

function QWheelEvent_create(pos: PPoint; delta: Integer; state: Integer): QWheelEventH; overload; cdecl;
procedure QWheelEvent_destroy(handle: QWheelEventH); cdecl;
function QWheelEvent_create(pos: PPoint; globalPos: PPoint; delta: Integer; state: Integer): QWheelEventH; overload; cdecl;
function QWheelEvent_delta(handle: QWheelEventH): Integer; cdecl;
function QWheelEvent_pos(handle: QWheelEventH): PPoint; cdecl;
function QWheelEvent_globalPos(handle: QWheelEventH): PPoint; cdecl;
function QWheelEvent_x(handle: QWheelEventH): Integer; cdecl;
function QWheelEvent_y(handle: QWheelEventH): Integer; cdecl;
function QWheelEvent_globalX(handle: QWheelEventH): Integer; cdecl;
function QWheelEvent_globalY(handle: QWheelEventH): Integer; cdecl;
function QWheelEvent_state(handle: QWheelEventH): ButtonState; cdecl;
function QWheelEvent_isAccepted(handle: QWheelEventH): Boolean; cdecl;
procedure QWheelEvent_accept(handle: QWheelEventH); cdecl;
procedure QWheelEvent_ignore(handle: QWheelEventH); cdecl;

function QKeyEvent_create(_type: QEventType; key: Integer; ascii: Integer; state: Integer; text: PWideString; autorep: Boolean; count: Word): QKeyEventH; cdecl;
procedure QKeyEvent_destroy(handle: QKeyEventH); cdecl;
function QKeyEvent_key(handle: QKeyEventH): Integer; cdecl;
function QKeyEvent_ascii(handle: QKeyEventH): Integer; cdecl;
function QKeyEvent_state(handle: QKeyEventH): ButtonState; cdecl;
function QKeyEvent_stateAfter(handle: QKeyEventH): ButtonState; cdecl;
function QKeyEvent_isAccepted(handle: QKeyEventH): Boolean; cdecl;
procedure QKeyEvent_text(handle: QKeyEventH; retval: PWideString); cdecl;
function QKeyEvent_isAutoRepeat(handle: QKeyEventH): Boolean; cdecl;
function QKeyEvent_count(handle: QKeyEventH): Integer; cdecl;
procedure QKeyEvent_accept(handle: QKeyEventH); cdecl;
procedure QKeyEvent_ignore(handle: QKeyEventH); cdecl;

function QFocusEvent_create(_type: QEventType): QFocusEventH; cdecl;
procedure QFocusEvent_destroy(handle: QFocusEventH); cdecl;
function QFocusEvent_gotFocus(handle: QFocusEventH): Boolean; cdecl;
function QFocusEvent_lostFocus(handle: QFocusEventH): Boolean; cdecl;
function QFocusEvent_reason(): QFocusEventReason; cdecl;
procedure QFocusEvent_setReason(reason: QFocusEventReason); cdecl;
procedure QFocusEvent_resetReason(); cdecl;

function QPaintEvent_create(paintRegion: QRegionH; erased: Boolean): QPaintEventH; overload; cdecl;
procedure QPaintEvent_destroy(handle: QPaintEventH); cdecl;
function QPaintEvent_create(paintRect: PRect; erased: Boolean): QPaintEventH; overload; cdecl;
procedure QPaintEvent_rect(handle: QPaintEventH; retval: PRect); cdecl;
function QPaintEvent_region(handle: QPaintEventH): QRegionH; cdecl;
function QPaintEvent_erased(handle: QPaintEventH): Boolean; cdecl;

function QMoveEvent_create(pos: PPoint; oldPos: PPoint): QMoveEventH; cdecl;
procedure QMoveEvent_destroy(handle: QMoveEventH); cdecl;
function QMoveEvent_pos(handle: QMoveEventH): PPoint; cdecl;
function QMoveEvent_oldPos(handle: QMoveEventH): PPoint; cdecl;

function QResizeEvent_create(size: PSize; oldSize: PSize): QResizeEventH; cdecl;
procedure QResizeEvent_destroy(handle: QResizeEventH); cdecl;
function QResizeEvent_size(handle: QResizeEventH): PSize; cdecl;
function QResizeEvent_oldSize(handle: QResizeEventH): PSize; cdecl;

function QCloseEvent_create(): QCloseEventH; cdecl;
procedure QCloseEvent_destroy(handle: QCloseEventH); cdecl;
function QCloseEvent_isAccepted(handle: QCloseEventH): Boolean; cdecl;
procedure QCloseEvent_accept(handle: QCloseEventH); cdecl;
procedure QCloseEvent_ignore(handle: QCloseEventH); cdecl;

function QShowEvent_create(spontaneous: Boolean): QShowEventH; cdecl;
procedure QShowEvent_destroy(handle: QShowEventH); cdecl;
function QShowEvent_spontaneous(handle: QShowEventH): Boolean; cdecl;

function QHideEvent_create(spontaneous: Boolean): QHideEventH; cdecl;
procedure QHideEvent_destroy(handle: QHideEventH); cdecl;
function QHideEvent_spontaneous(handle: QHideEventH): Boolean; cdecl;

function QDropEvent_create(pos: PPoint; typ: QEventType): QDropEventH; cdecl;
procedure QDropEvent_destroy(handle: QDropEventH); cdecl;
function QDropEvent_pos(handle: QDropEventH): PPoint; cdecl;
function QDropEvent_isAccepted(handle: QDropEventH): Boolean; cdecl;
procedure QDropEvent_accept(handle: QDropEventH; y: Boolean); cdecl;
procedure QDropEvent_ignore(handle: QDropEventH); cdecl;
function QDropEvent_isActionAccepted(handle: QDropEventH): Boolean; cdecl;
procedure QDropEvent_acceptAction(handle: QDropEventH; y: Boolean); cdecl;
procedure QDropEvent_setAction(handle: QDropEventH; a: QDropEventAction); cdecl;
function QDropEvent_action(handle: QDropEventH): QDropEventAction; cdecl;
function QDropEvent_source(handle: QDropEventH): QWidgetH; cdecl;
function QDropEvent_format(handle: QDropEventH; n: Integer): PAnsiChar; cdecl;
procedure QDropEvent_encodedData(handle: QDropEventH; retval: QByteArrayH; p1: PAnsiChar); cdecl;
function QDropEvent_provides(handle: QDropEventH; p1: PAnsiChar): Boolean; cdecl;
procedure QDropEvent_data(handle: QDropEventH; retval: QByteArrayH; f: PAnsiChar); cdecl;
procedure QDropEvent_setPoint(handle: QDropEventH; np: PPoint); cdecl;
function QDropEvent_to_QMimeSource(handle: QDropEventH): QMimeSourceH; cdecl;
function QDragMoveEvent_create(pos: PPoint; typ: QEventType): QDragMoveEventH; cdecl;
procedure QDragMoveEvent_destroy(handle: QDragMoveEventH); cdecl;
procedure QDragMoveEvent_answerRect(handle: QDragMoveEventH; retval: PRect); cdecl;
procedure QDragMoveEvent_accept(handle: QDragMoveEventH; y: Boolean); overload; cdecl;
procedure QDragMoveEvent_accept(handle: QDragMoveEventH; r: PRect); overload; cdecl;
procedure QDragMoveEvent_ignore(handle: QDragMoveEventH; r: PRect); overload; cdecl;
procedure QDragMoveEvent_ignore(handle: QDragMoveEventH); overload; cdecl;

function QDragEnterEvent_create(pos: PPoint): QDragEnterEventH; cdecl;
procedure QDragEnterEvent_destroy(handle: QDragEnterEventH); cdecl;

function QDragResponseEvent_create(accepted: Boolean): QDragResponseEventH; cdecl;
procedure QDragResponseEvent_destroy(handle: QDragResponseEventH); cdecl;
function QDragResponseEvent_dragAccepted(handle: QDragResponseEventH): Boolean; cdecl;

function QDragLeaveEvent_create(): QDragLeaveEventH; cdecl;
procedure QDragLeaveEvent_destroy(handle: QDragLeaveEventH); cdecl;

function QChildEvent_create(_type: QEventType; child: QObjectH): QChildEventH; cdecl;
procedure QChildEvent_destroy(handle: QChildEventH); cdecl;
function QChildEvent_child(handle: QChildEventH): QObjectH; cdecl;
function QChildEvent_inserted(handle: QChildEventH): Boolean; cdecl;
function QChildEvent_removed(handle: QChildEventH): Boolean; cdecl;

function QCustomEvent_create(_type: Integer): QCustomEventH; overload; cdecl;
procedure QCustomEvent_destroy(handle: QCustomEventH); cdecl;
function QCustomEvent_create(_type: QEventType; data: Pointer): QCustomEventH; overload; cdecl;
function QCustomEvent_data(handle: QCustomEventH): Pointer; cdecl;
procedure QCustomEvent_setData(handle: QCustomEventH; data: Pointer); cdecl;

function QFrame_create(parent: QWidgetH; name: PAnsiChar; f: WFlags; p4: Boolean): QFrameH; cdecl;
procedure QFrame_destroy(handle: QFrameH); cdecl;
function QFrame_frameStyle(handle: QFrameH): Integer; cdecl;
procedure QFrame_setFrameStyle(handle: QFrameH; p1: Integer); cdecl;
function QFrame_frameWidth(handle: QFrameH): Integer; cdecl;
procedure QFrame_contentsRect(handle: QFrameH; retval: PRect); cdecl;
function QFrame_lineShapesOk(handle: QFrameH): Boolean; cdecl;
procedure QFrame_sizeHint(handle: QFrameH; retval: PSize); cdecl;
procedure QFrame_sizePolicy(handle: QFrameH; retval: PSizePolicy); cdecl;
function QFrame_frameShape(handle: QFrameH): QFrameShape; cdecl;
procedure QFrame_setFrameShape(handle: QFrameH; p1: QFrameShape); cdecl;
function QFrame_frameShadow(handle: QFrameH): QFrameShadow; cdecl;
procedure QFrame_setFrameShadow(handle: QFrameH; p1: QFrameShadow); cdecl;
function QFrame_lineWidth(handle: QFrameH): Integer; cdecl;
procedure QFrame_setLineWidth(handle: QFrameH; p1: Integer); cdecl;
function QFrame_margin(handle: QFrameH): Integer; cdecl;
procedure QFrame_setMargin(handle: QFrameH; p1: Integer); cdecl;
function QFrame_midLineWidth(handle: QFrameH): Integer; cdecl;
procedure QFrame_setMidLineWidth(handle: QFrameH; p1: Integer); cdecl;
procedure QFrame_frameRect(handle: QFrameH; retval: PRect); cdecl;
procedure QFrame_setFrameRect(handle: QFrameH; p1: PRect); cdecl;

function QIconDragItem_create(): QIconDragItemH; cdecl;
procedure QIconDragItem_destroy(handle: QIconDragItemH); cdecl;
procedure QIconDragItem_data(handle: QIconDragItemH; retval: QByteArrayH); cdecl;
procedure QIconDragItem_setData(handle: QIconDragItemH; d: QByteArrayH); cdecl;

function QIconDrag_create(dragSource: QWidgetH; name: PAnsiChar): QIconDragH; cdecl;
procedure QIconDrag_destroy(handle: QIconDragH); cdecl;
procedure QIconDrag_append(handle: QIconDragH; item: QIconDragItemH; pr: PRect; tr: PRect); cdecl;
function QIconDrag_format(handle: QIconDragH; i: Integer): PAnsiChar; cdecl;
function QIconDrag_canDecode(e: QMimeSourceH): Boolean; cdecl;
procedure QIconDrag_encodedData(handle: QIconDragH; retval: QByteArrayH; mime: PAnsiChar); cdecl;

function QIconViewItem_create(parent: QIconViewH): QIconViewItemH; overload; cdecl;
procedure QIconViewItem_destroy(handle: QIconViewItemH); cdecl;
function QIconViewItem_create(parent: QIconViewH; after: QIconViewItemH): QIconViewItemH; overload; cdecl;
function QIconViewItem_create(parent: QIconViewH; text: PWideString): QIconViewItemH; overload; cdecl;
function QIconViewItem_create(parent: QIconViewH; after: QIconViewItemH; text: PWideString): QIconViewItemH; overload; cdecl;
function QIconViewItem_create(parent: QIconViewH; text: PWideString; icon: QPixmapH): QIconViewItemH; overload; cdecl;
function QIconViewItem_create(parent: QIconViewH; after: QIconViewItemH; text: PWideString; icon: QPixmapH): QIconViewItemH; overload; cdecl;
procedure QIconViewItem_setRenameEnabled(handle: QIconViewItemH; allow: Boolean); cdecl;
procedure QIconViewItem_setDragEnabled(handle: QIconViewItemH; allow: Boolean); cdecl;
procedure QIconViewItem_setDropEnabled(handle: QIconViewItemH; allow: Boolean); cdecl;
procedure QIconViewItem_text(handle: QIconViewItemH; retval: PWideString); cdecl;
function QIconViewItem_pixmap(handle: QIconViewItemH): QPixmapH; cdecl;
procedure QIconViewItem_key(handle: QIconViewItemH; retval: PWideString); cdecl;
function QIconViewItem_renameEnabled(handle: QIconViewItemH): Boolean; cdecl;
function QIconViewItem_dragEnabled(handle: QIconViewItemH): Boolean; cdecl;
function QIconViewItem_dropEnabled(handle: QIconViewItemH): Boolean; cdecl;
function QIconViewItem_iconView(handle: QIconViewItemH): QIconViewH; cdecl;
function QIconViewItem_prevItem(handle: QIconViewItemH): QIconViewItemH; cdecl;
function QIconViewItem_nextItem(handle: QIconViewItemH): QIconViewItemH; cdecl;
function QIconViewItem_index(handle: QIconViewItemH): Integer; cdecl;
procedure QIconViewItem_setSelected(handle: QIconViewItemH; s: Boolean; cb: Boolean); overload; cdecl;
procedure QIconViewItem_setSelected(handle: QIconViewItemH; s: Boolean); overload; cdecl;
procedure QIconViewItem_setSelectable(handle: QIconViewItemH; s: Boolean); cdecl;
function QIconViewItem_isSelected(handle: QIconViewItemH): Boolean; cdecl;
function QIconViewItem_isSelectable(handle: QIconViewItemH): Boolean; cdecl;
procedure QIconViewItem_repaint(handle: QIconViewItemH); cdecl;
procedure QIconViewItem_move(handle: QIconViewItemH; x: Integer; y: Integer); overload; cdecl;
procedure QIconViewItem_moveBy(handle: QIconViewItemH; dx: Integer; dy: Integer); overload; cdecl;
procedure QIconViewItem_move(handle: QIconViewItemH; pnt: PPoint); overload; cdecl;
procedure QIconViewItem_moveBy(handle: QIconViewItemH; pnt: PPoint); overload; cdecl;
procedure QIconViewItem_rect(handle: QIconViewItemH; retval: PRect); cdecl;
function QIconViewItem_x(handle: QIconViewItemH): Integer; cdecl;
function QIconViewItem_y(handle: QIconViewItemH): Integer; cdecl;
function QIconViewItem_width(handle: QIconViewItemH): Integer; cdecl;
function QIconViewItem_height(handle: QIconViewItemH): Integer; cdecl;
procedure QIconViewItem_size(handle: QIconViewItemH; retval: PSize); cdecl;
procedure QIconViewItem_pos(handle: QIconViewItemH; retval: PPoint); cdecl;
procedure QIconViewItem_textRect(handle: QIconViewItemH; retval: PRect; relative: Boolean); cdecl;
procedure QIconViewItem_pixmapRect(handle: QIconViewItemH; retval: PRect; relative: Boolean); cdecl;
function QIconViewItem_contains(handle: QIconViewItemH; pnt: PPoint): Boolean; cdecl;
function QIconViewItem_intersects(handle: QIconViewItemH; r: PRect): Boolean; cdecl;
function QIconViewItem_acceptDrop(handle: QIconViewItemH; mime: QMimeSourceH): Boolean; cdecl;
procedure QIconViewItem_rename(handle: QIconViewItemH); cdecl;
function QIconViewItem_compare(handle: QIconViewItemH; i: QIconViewItemH): Integer; cdecl;
procedure QIconViewItem_setText(handle: QIconViewItemH; text: PWideString); overload; cdecl;
procedure QIconViewItem_setPixmap(handle: QIconViewItemH; icon: QPixmapH); overload; cdecl;
procedure QIconViewItem_setText(handle: QIconViewItemH; text: PWideString; recalc: Boolean; redraw: Boolean); overload; cdecl;
procedure QIconViewItem_setPixmap(handle: QIconViewItemH; icon: QPixmapH; recalc: Boolean; redraw: Boolean); overload; cdecl;
procedure QIconViewItem_setKey(handle: QIconViewItemH; k: PWideString); cdecl;

function QIconView_create(parent: QWidgetH; name: PAnsiChar; f: WFlags): QIconViewH; cdecl;
procedure QIconView_destroy(handle: QIconViewH); cdecl;
procedure QIconView_insertItem(handle: QIconViewH; item: QIconViewItemH; after: QIconViewItemH); cdecl;
procedure QIconView_takeItem(handle: QIconViewH; item: QIconViewItemH); cdecl;
function QIconView_index(handle: QIconViewH; item: QIconViewItemH): Integer; cdecl;
function QIconView_firstItem(handle: QIconViewH): QIconViewItemH; cdecl;
function QIconView_lastItem(handle: QIconViewH): QIconViewItemH; cdecl;
function QIconView_currentItem(handle: QIconViewH): QIconViewItemH; cdecl;
procedure QIconView_setCurrentItem(handle: QIconViewH; item: QIconViewItemH); cdecl;
procedure QIconView_setSelected(handle: QIconViewH; item: QIconViewItemH; s: Boolean; cb: Boolean); cdecl;
function QIconView_count(handle: QIconViewH): Cardinal; cdecl;
procedure QIconView_showEvent(handle: QIconViewH; p1: QShowEventH); cdecl;
procedure QIconView_setSelectionMode(handle: QIconViewH; m: QIconViewSelectionMode); cdecl;
function QIconView_selectionMode(handle: QIconViewH): QIconViewSelectionMode; cdecl;
function QIconView_findItem(handle: QIconViewH; pos: PPoint): QIconViewItemH; overload; cdecl;
function QIconView_findItem(handle: QIconViewH; text: PWideString): QIconViewItemH; overload; cdecl;
procedure QIconView_selectAll(handle: QIconViewH; select: Boolean); cdecl;
procedure QIconView_clearSelection(handle: QIconViewH); cdecl;
procedure QIconView_invertSelection(handle: QIconViewH); cdecl;
procedure QIconView_repaintItem(handle: QIconViewH; item: QIconViewItemH); cdecl;
procedure QIconView_ensureItemVisible(handle: QIconViewH; item: QIconViewItemH); cdecl;
function QIconView_findFirstVisibleItem(handle: QIconViewH; r: PRect): QIconViewItemH; cdecl;
function QIconView_findLastVisibleItem(handle: QIconViewH; r: PRect): QIconViewItemH; cdecl;
procedure QIconView_clear(handle: QIconViewH); cdecl;
procedure QIconView_setGridX(handle: QIconViewH; rx: Integer); cdecl;
procedure QIconView_setGridY(handle: QIconViewH; ry: Integer); cdecl;
function QIconView_gridX(handle: QIconViewH): Integer; cdecl;
function QIconView_gridY(handle: QIconViewH): Integer; cdecl;
procedure QIconView_setSpacing(handle: QIconViewH; sp: Integer); cdecl;
function QIconView_spacing(handle: QIconViewH): Integer; cdecl;
procedure QIconView_setItemTextPos(handle: QIconViewH; pos: QIconViewItemTextPos); cdecl;
function QIconView_itemTextPos(handle: QIconViewH): QIconViewItemTextPos; cdecl;
procedure QIconView_setItemTextBackground(handle: QIconViewH; b: QBrushH); cdecl;
function QIconView_itemTextBackground(handle: QIconViewH): QBrushH; cdecl;
procedure QIconView_setArrangement(handle: QIconViewH; am: QIconViewArrangement); cdecl;
function QIconView_arrangement(handle: QIconViewH): QIconViewArrangement; cdecl;
procedure QIconView_setResizeMode(handle: QIconViewH; am: QIconViewResizeMode); cdecl;
function QIconView_resizeMode(handle: QIconViewH): QIconViewResizeMode; cdecl;
procedure QIconView_setMaxItemWidth(handle: QIconViewH; w: Integer); cdecl;
function QIconView_maxItemWidth(handle: QIconViewH): Integer; cdecl;
procedure QIconView_setMaxItemTextLength(handle: QIconViewH; w: Integer); cdecl;
function QIconView_maxItemTextLength(handle: QIconViewH): Integer; cdecl;
procedure QIconView_setAutoArrange(handle: QIconViewH; b: Boolean); cdecl;
function QIconView_autoArrange(handle: QIconViewH): Boolean; cdecl;
procedure QIconView_setShowToolTips(handle: QIconViewH; b: Boolean); cdecl;
function QIconView_showToolTips(handle: QIconViewH): Boolean; cdecl;
procedure QIconView_setSorting(handle: QIconViewH; sort: Boolean; ascending: Boolean); cdecl;
function QIconView_sorting(handle: QIconViewH): Boolean; cdecl;
function QIconView_sortDirection(handle: QIconViewH): Boolean; cdecl;
procedure QIconView_setItemsMovable(handle: QIconViewH; b: Boolean); cdecl;
function QIconView_itemsMovable(handle: QIconViewH): Boolean; cdecl;
procedure QIconView_setWordWrapIconText(handle: QIconViewH; b: Boolean); cdecl;
function QIconView_wordWrapIconText(handle: QIconViewH): Boolean; cdecl;
function QIconView_eventFilter(handle: QIconViewH; o: QObjectH; p2: QEventH): Boolean; cdecl;
procedure QIconView_minimumSizeHint(handle: QIconViewH; retval: PSize); cdecl;
procedure QIconView_sizePolicy(handle: QIconViewH; retval: PSizePolicy); cdecl;
procedure QIconView_sizeHint(handle: QIconViewH; retval: PSize); cdecl;
procedure QIconView_sort(handle: QIconViewH; ascending: Boolean); cdecl;
procedure QIconView_setFont(handle: QIconViewH; p1: QFontH); cdecl;
procedure QIconView_setPalette(handle: QIconViewH; p1: QPaletteH); cdecl;
procedure QIconView_arrangeItemsInGrid(handle: QIconViewH; grid: PSize; update: Boolean); overload; cdecl;
procedure QIconView_arrangeItemsInGrid(handle: QIconViewH; update: Boolean); overload; cdecl;
procedure QIconView_setContentsPos(handle: QIconViewH; x: Integer; y: Integer); cdecl;
procedure QIconView_updateContents(handle: QIconViewH); cdecl;

function QLCDNumber_create(parent: QWidgetH; name: PAnsiChar): QLCDNumberH; overload; cdecl;
procedure QLCDNumber_destroy(handle: QLCDNumberH); cdecl;
function QLCDNumber_create(numDigits: Cardinal; parent: QWidgetH; name: PAnsiChar): QLCDNumberH; overload; cdecl;
function QLCDNumber_smallDecimalPoint(handle: QLCDNumberH): Boolean; cdecl;
function QLCDNumber_numDigits(handle: QLCDNumberH): Integer; cdecl;
procedure QLCDNumber_setNumDigits(handle: QLCDNumberH; nDigits: Integer); cdecl;
function QLCDNumber_checkOverflow(handle: QLCDNumberH; num: Double): Boolean; overload; cdecl;
function QLCDNumber_checkOverflow(handle: QLCDNumberH; num: Integer): Boolean; overload; cdecl;
function QLCDNumber_mode(handle: QLCDNumberH): QLCDNumberMode; cdecl;
procedure QLCDNumber_setMode(handle: QLCDNumberH; p1: QLCDNumberMode); cdecl;
function QLCDNumber_segmentStyle(handle: QLCDNumberH): QLCDNumberSegmentStyle; cdecl;
procedure QLCDNumber_setSegmentStyle(handle: QLCDNumberH; p1: QLCDNumberSegmentStyle); cdecl;
function QLCDNumber_value(handle: QLCDNumberH): Double; cdecl;
function QLCDNumber_intValue(handle: QLCDNumberH): Integer; cdecl;
procedure QLCDNumber_sizeHint(handle: QLCDNumberH; retval: PSize); cdecl;
procedure QLCDNumber_sizePolicy(handle: QLCDNumberH; retval: PSizePolicy); cdecl;
procedure QLCDNumber_display(handle: QLCDNumberH; num: Integer); overload; cdecl;
procedure QLCDNumber_display(handle: QLCDNumberH; num: Double); overload; cdecl;
procedure QLCDNumber_display(handle: QLCDNumberH; str: PWideString); overload; cdecl;
procedure QLCDNumber_setHexMode(handle: QLCDNumberH); cdecl;
procedure QLCDNumber_setDecMode(handle: QLCDNumberH); cdecl;
procedure QLCDNumber_setOctMode(handle: QLCDNumberH); cdecl;
procedure QLCDNumber_setBinMode(handle: QLCDNumberH); cdecl;
procedure QLCDNumber_setSmallDecimalPoint(handle: QLCDNumberH; p1: Boolean); cdecl;

function QLineEdit_create(parent: QWidgetH; name: PAnsiChar): QLineEditH; overload; cdecl;
procedure QLineEdit_destroy(handle: QLineEditH); cdecl;
function QLineEdit_create(p1: PWideString; parent: QWidgetH; name: PAnsiChar): QLineEditH; overload; cdecl;
procedure QLineEdit_text(handle: QLineEditH; retval: PWideString); cdecl;
procedure QLineEdit_displayText(handle: QLineEditH; retval: PWideString); cdecl;
function QLineEdit_maxLength(handle: QLineEditH): Integer; cdecl;
procedure QLineEdit_setMaxLength(handle: QLineEditH; p1: Integer); cdecl;
procedure QLineEdit_setFrame(handle: QLineEditH; p1: Boolean); cdecl;
function QLineEdit_frame(handle: QLineEditH): Boolean; cdecl;
procedure QLineEdit_setEchoMode(handle: QLineEditH; p1: QLineEditEchoMode); cdecl;
function QLineEdit_echoMode(handle: QLineEditH): QLineEditEchoMode; cdecl;
procedure QLineEdit_setReadOnly(handle: QLineEditH; p1: Boolean); cdecl;
function QLineEdit_isReadOnly(handle: QLineEditH): Boolean; cdecl;
procedure QLineEdit_setValidator(handle: QLineEditH; p1: QValidatorH); cdecl;
function QLineEdit_validator(handle: QLineEditH): QValidatorH; cdecl;
procedure QLineEdit_sizeHint(handle: QLineEditH; retval: PSize); cdecl;
procedure QLineEdit_minimumSizeHint(handle: QLineEditH; retval: PSize); cdecl;
procedure QLineEdit_sizePolicy(handle: QLineEditH; retval: PSizePolicy); cdecl;
procedure QLineEdit_setEnabled(handle: QLineEditH; p1: Boolean); cdecl;
procedure QLineEdit_setFont(handle: QLineEditH; p1: QFontH); cdecl;
procedure QLineEdit_setPalette(handle: QLineEditH; p1: QPaletteH); cdecl;
procedure QLineEdit_setSelection(handle: QLineEditH; p1: Integer; p2: Integer); cdecl;
procedure QLineEdit_setCursorPosition(handle: QLineEditH; p1: Integer); cdecl;
function QLineEdit_cursorPosition(handle: QLineEditH): Integer; cdecl;
function QLineEdit_validateAndSet(handle: QLineEditH; p1: PWideString; p2: Integer; p3: Integer; p4: Integer): Boolean; cdecl;
procedure QLineEdit_cut(handle: QLineEditH); cdecl;
procedure QLineEdit_copy(handle: QLineEditH); cdecl;
procedure QLineEdit_paste(handle: QLineEditH); cdecl;
procedure QLineEdit_setAlignment(handle: QLineEditH; flag: Integer); cdecl;
function QLineEdit_alignment(handle: QLineEditH): Integer; cdecl;
procedure QLineEdit_cursorLeft(handle: QLineEditH; mark: Boolean; steps: Integer); cdecl;
procedure QLineEdit_cursorRight(handle: QLineEditH; mark: Boolean; steps: Integer); cdecl;
procedure QLineEdit_cursorWordForward(handle: QLineEditH; mark: Boolean); cdecl;
procedure QLineEdit_cursorWordBackward(handle: QLineEditH; mark: Boolean); cdecl;
procedure QLineEdit_backspace(handle: QLineEditH); cdecl;
procedure QLineEdit_del(handle: QLineEditH); cdecl;
procedure QLineEdit_home(handle: QLineEditH; mark: Boolean); cdecl;
procedure QLineEdit_end(handle: QLineEditH; mark: Boolean); cdecl;
procedure QLineEdit_setEdited(handle: QLineEditH; p1: Boolean); cdecl;
function QLineEdit_edited(handle: QLineEditH): Boolean; cdecl;
function QLineEdit_hasMarkedText(handle: QLineEditH): Boolean; cdecl;
procedure QLineEdit_markedText(handle: QLineEditH; retval: PWideString); cdecl;
procedure QLineEdit_setText(handle: QLineEditH; p1: PWideString); cdecl;
procedure QLineEdit_selectAll(handle: QLineEditH); cdecl;
procedure QLineEdit_deselect(handle: QLineEditH); cdecl;
procedure QLineEdit_clearValidator(handle: QLineEditH); cdecl;
procedure QLineEdit_insert(handle: QLineEditH; p1: PWideString); cdecl;
procedure QLineEdit_clear(handle: QLineEditH); cdecl;

function QListBox_create(parent: QWidgetH; name: PAnsiChar; f: WFlags): QListBoxH; cdecl;
procedure QListBox_destroy(handle: QListBoxH); cdecl;
procedure QListBox_setFont(handle: QListBoxH; p1: QFontH); cdecl;
function QListBox_count(handle: QListBoxH): Cardinal; cdecl;
procedure QListBox_insertStringList(handle: QListBoxH; p1: QStringListH; index: Integer); cdecl;
procedure QListBox_insertStrList(handle: QListBoxH; p1: QStrListH; index: Integer); overload; cdecl;
procedure QListBox_insertStrList(handle: QListBoxH; p1: PPAnsiChar; numStrings: Integer; index: Integer); overload; cdecl;
procedure QListBox_insertItem(handle: QListBoxH; p1: QListBoxItemH; index: Integer); overload; cdecl;
procedure QListBox_insertItem(handle: QListBoxH; p1: QListBoxItemH; after: QListBoxItemH); overload; cdecl;
procedure QListBox_insertItem(handle: QListBoxH; text: PWideString; index: Integer); overload; cdecl;
procedure QListBox_insertItem(handle: QListBoxH; pixmap: QPixmapH; index: Integer); overload; cdecl;
procedure QListBox_insertItem(handle: QListBoxH; pixmap: QPixmapH; text: PWideString; index: Integer); overload; cdecl;
procedure QListBox_removeItem(handle: QListBoxH; index: Integer); cdecl;
procedure QListBox_clear(handle: QListBoxH); cdecl;
procedure QListBox_text(handle: QListBoxH; retval: PWideString; index: Integer); cdecl;
function QListBox_pixmap(handle: QListBoxH; index: Integer): QPixmapH; cdecl;
procedure QListBox_changeItem(handle: QListBoxH; p1: QListBoxItemH; index: Integer); overload; cdecl;
procedure QListBox_changeItem(handle: QListBoxH; text: PWideString; index: Integer); overload; cdecl;
procedure QListBox_changeItem(handle: QListBoxH; pixmap: QPixmapH; index: Integer); overload; cdecl;
procedure QListBox_changeItem(handle: QListBoxH; pixmap: QPixmapH; text: PWideString; index: Integer); overload; cdecl;
procedure QListBox_takeItem(handle: QListBoxH; p1: QListBoxItemH); cdecl;
function QListBox_numItemsVisible(handle: QListBoxH): Integer; cdecl;
function QListBox_currentItem(handle: QListBoxH): Integer; cdecl;
procedure QListBox_currentText(handle: QListBoxH; retval: PWideString); cdecl;
procedure QListBox_setCurrentItem(handle: QListBoxH; index: Integer); overload; cdecl;
procedure QListBox_setCurrentItem(handle: QListBoxH; p1: QListBoxItemH); overload; cdecl;
procedure QListBox_centerCurrentItem(handle: QListBoxH); cdecl;
function QListBox_topItem(handle: QListBoxH): Integer; cdecl;
procedure QListBox_setTopItem(handle: QListBoxH; index: Integer); cdecl;
procedure QListBox_setBottomItem(handle: QListBoxH; index: Integer); cdecl;
function QListBox_maxItemWidth(handle: QListBoxH): Integer; cdecl;
procedure QListBox_setSelectionMode(handle: QListBoxH; p1: QListBoxSelectionMode); cdecl;
function QListBox_selectionMode(handle: QListBoxH): QListBoxSelectionMode; cdecl;
procedure QListBox_setMultiSelection(handle: QListBoxH; multi: Boolean); cdecl;
function QListBox_isMultiSelection(handle: QListBoxH): Boolean; cdecl;
procedure QListBox_setSelected(handle: QListBoxH; p1: QListBoxItemH; p2: Boolean); overload; cdecl;
procedure QListBox_setSelected(handle: QListBoxH; p1: Integer; p2: Boolean); overload; cdecl;
function QListBox_isSelected(handle: QListBoxH; p1: Integer): Boolean; overload; cdecl;
function QListBox_isSelected(handle: QListBoxH; p1: QListBoxItemH): Boolean; overload; cdecl;
procedure QListBox_sizeHint(handle: QListBoxH; retval: PSize); cdecl;
procedure QListBox_minimumSizeHint(handle: QListBoxH; retval: PSize); cdecl;
function QListBox_item(handle: QListBoxH; index: Integer): QListBoxItemH; cdecl;
function QListBox_index(handle: QListBoxH; p1: QListBoxItemH): Integer; cdecl;
function QListBox_findItem(handle: QListBoxH; text: PWideString): QListBoxItemH; cdecl;
procedure QListBox_triggerUpdate(handle: QListBoxH; doLayout: Boolean); cdecl;
function QListBox_itemVisible(handle: QListBoxH; index: Integer): Boolean; overload; cdecl;
function QListBox_itemVisible(handle: QListBoxH; p1: QListBoxItemH): Boolean; overload; cdecl;
procedure QListBox_setColumnMode(handle: QListBoxH; p1: QListBoxLayoutMode); overload; cdecl;
procedure QListBox_setColumnMode(handle: QListBoxH; p1: Integer); overload; cdecl;
procedure QListBox_setRowMode(handle: QListBoxH; p1: QListBoxLayoutMode); overload; cdecl;
procedure QListBox_setRowMode(handle: QListBoxH; p1: Integer); overload; cdecl;
function QListBox_columnMode(handle: QListBoxH): QListBoxLayoutMode; cdecl;
function QListBox_rowMode(handle: QListBoxH): QListBoxLayoutMode; cdecl;
function QListBox_numColumns(handle: QListBoxH): Integer; cdecl;
function QListBox_numRows(handle: QListBoxH): Integer; cdecl;
function QListBox_variableWidth(handle: QListBoxH): Boolean; cdecl;
procedure QListBox_setVariableWidth(handle: QListBoxH; p1: Boolean); cdecl;
function QListBox_variableHeight(handle: QListBoxH): Boolean; cdecl;
procedure QListBox_setVariableHeight(handle: QListBoxH; p1: Boolean); cdecl;
procedure QListBox_viewportPaintEvent(handle: QListBoxH; p1: QPaintEventH); cdecl;
function QListBox_dragSelect(handle: QListBoxH): Boolean; cdecl;
procedure QListBox_setDragSelect(handle: QListBoxH; p1: Boolean); cdecl;
function QListBox_autoScroll(handle: QListBoxH): Boolean; cdecl;
procedure QListBox_setAutoScroll(handle: QListBoxH; p1: Boolean); cdecl;
function QListBox_autoScrollBar(handle: QListBoxH): Boolean; cdecl;
procedure QListBox_setAutoScrollBar(handle: QListBoxH; enable: Boolean); cdecl;
function QListBox_scrollBar(handle: QListBoxH): Boolean; cdecl;
procedure QListBox_setScrollBar(handle: QListBoxH; enable: Boolean); cdecl;
function QListBox_autoBottomScrollBar(handle: QListBoxH): Boolean; cdecl;
procedure QListBox_setAutoBottomScrollBar(handle: QListBoxH; enable: Boolean); cdecl;
function QListBox_bottomScrollBar(handle: QListBoxH): Boolean; cdecl;
procedure QListBox_setBottomScrollBar(handle: QListBoxH; enable: Boolean); cdecl;
function QListBox_smoothScrolling(handle: QListBoxH): Boolean; cdecl;
procedure QListBox_setSmoothScrolling(handle: QListBoxH; p1: Boolean); cdecl;
function QListBox_autoUpdate(handle: QListBoxH): Boolean; cdecl;
procedure QListBox_setAutoUpdate(handle: QListBoxH; p1: Boolean); cdecl;
procedure QListBox_setFixedVisibleLines(handle: QListBoxH; lines: Integer); cdecl;
procedure QListBox_inSort(handle: QListBoxH; p1: QListBoxItemH); overload; cdecl;
procedure QListBox_inSort(handle: QListBoxH; text: PWideString); overload; cdecl;
function QListBox_cellHeight(handle: QListBoxH; i: Integer): Integer; overload; cdecl;
function QListBox_cellHeight(handle: QListBoxH): Integer; overload; cdecl;
function QListBox_cellWidth(handle: QListBoxH): Integer; overload; cdecl;
function QListBox_cellWidth(handle: QListBoxH; i: Integer): Integer; overload; cdecl;
function QListBox_numCols(handle: QListBoxH): Integer; cdecl;
function QListBox_itemHeight(handle: QListBoxH; index: Integer): Integer; cdecl;
function QListBox_itemAt(handle: QListBoxH; p1: PPoint): QListBoxItemH; cdecl;
procedure QListBox_itemRect(handle: QListBoxH; retval: PRect; item: QListBoxItemH); cdecl;
function QListBox_firstItem(handle: QListBoxH): QListBoxItemH; cdecl;
procedure QListBox_sort(handle: QListBoxH; ascending: Boolean); cdecl;
procedure QListBox_ensureCurrentVisible(handle: QListBoxH); cdecl;
procedure QListBox_clearSelection(handle: QListBoxH); cdecl;
procedure QListBox_selectAll(handle: QListBoxH; select: Boolean); cdecl;
procedure QListBox_invertSelection(handle: QListBoxH); cdecl;

function QListBoxItem_create(listbox: QListBoxH): QListBoxItemH; overload; cdecl;
procedure QListBoxItem_destroy(handle: QListBoxItemH); cdecl;
function QListBoxItem_create(listbox: QListBoxH; after: QListBoxItemH): QListBoxItemH; overload; cdecl;
procedure QListBoxItem_text(handle: QListBoxItemH; retval: PWideString); cdecl;
function QListBoxItem_pixmap(handle: QListBoxItemH): QPixmapH; cdecl;
function QListBoxItem_height(handle: QListBoxItemH; p1: QListBoxH): Integer; cdecl;
function QListBoxItem_width(handle: QListBoxItemH; p1: QListBoxH): Integer; cdecl;
function QListBoxItem_selected(handle: QListBoxItemH): Boolean; cdecl;
function QListBoxItem_current(handle: QListBoxItemH): Boolean; cdecl;
function QListBoxItem_listBox(handle: QListBoxItemH): QListBoxH; cdecl;
procedure QListBoxItem_setSelectable(handle: QListBoxItemH; b: Boolean); cdecl;
function QListBoxItem_isSelectable(handle: QListBoxItemH): Boolean; cdecl;
function QListBoxItem_next(handle: QListBoxItemH): QListBoxItemH; cdecl;
function QListBoxItem_prev(handle: QListBoxItemH): QListBoxItemH; cdecl;

function QListBoxText_create(listbox: QListBoxH; text: PWideString): QListBoxTextH; overload; cdecl;
procedure QListBoxText_destroy(handle: QListBoxTextH); cdecl;
function QListBoxText_create(text: PWideString): QListBoxTextH; overload; cdecl;
function QListBoxText_create(listbox: QListBoxH; text: PWideString; after: QListBoxItemH): QListBoxTextH; overload; cdecl;
function QListBoxText_height(handle: QListBoxTextH; p1: QListBoxH): Integer; cdecl;
function QListBoxText_width(handle: QListBoxTextH; p1: QListBoxH): Integer; cdecl;

function QListBoxPixmap_create(listbox: QListBoxH; p2: QPixmapH): QListBoxPixmapH; overload; cdecl;
procedure QListBoxPixmap_destroy(handle: QListBoxPixmapH); cdecl;
function QListBoxPixmap_create(p1: QPixmapH): QListBoxPixmapH; overload; cdecl;
function QListBoxPixmap_create(listbox: QListBoxH; pix: QPixmapH; after: QListBoxItemH): QListBoxPixmapH; overload; cdecl;
function QListBoxPixmap_create(listbox: QListBoxH; p2: QPixmapH; p3: PWideString): QListBoxPixmapH; overload; cdecl;
function QListBoxPixmap_create(p1: QPixmapH; p2: PWideString): QListBoxPixmapH; overload; cdecl;
function QListBoxPixmap_create(listbox: QListBoxH; pix: QPixmapH; p3: PWideString; after: QListBoxItemH): QListBoxPixmapH; overload; cdecl;
function QListBoxPixmap_pixmap(handle: QListBoxPixmapH): QPixmapH; cdecl;
function QListBoxPixmap_height(handle: QListBoxPixmapH; p1: QListBoxH): Integer; cdecl;
function QListBoxPixmap_width(handle: QListBoxPixmapH; p1: QListBoxH): Integer; cdecl;

function QListViewItem_create(parent: QListViewH): QListViewItemH; overload; cdecl;
procedure QListViewItem_destroy(handle: QListViewItemH); cdecl;
function QListViewItem_create(parent: QListViewItemH): QListViewItemH; overload; cdecl;
function QListViewItem_create(parent: QListViewH; after: QListViewItemH): QListViewItemH; overload; cdecl;
function QListViewItem_create(parent: QListViewItemH; after: QListViewItemH): QListViewItemH; overload; cdecl;
function QListViewItem_create(parent: QListViewH; p2: PWideString; p3: PWideString; p4: PWideString; p5: PWideString; p6: PWideString; p7: PWideString; p8: PWideString; p9: PWideString): QListViewItemH; overload; cdecl;
function QListViewItem_create(parent: QListViewItemH; p2: PWideString; p3: PWideString; p4: PWideString; p5: PWideString; p6: PWideString; p7: PWideString; p8: PWideString; p9: PWideString): QListViewItemH; overload; cdecl;
function QListViewItem_create(parent: QListViewH; after: QListViewItemH; p3: PWideString; p4: PWideString; p5: PWideString; p6: PWideString; p7: PWideString; p8: PWideString; p9: PWideString; p10: PWideString): QListViewItemH; overload; cdecl;
function QListViewItem_create(parent: QListViewItemH; after: QListViewItemH; p3: PWideString; p4: PWideString; p5: PWideString; p6: PWideString; p7: PWideString; p8: PWideString; p9: PWideString; p10: PWideString): QListViewItemH; overload; cdecl;
procedure QListViewItem_insertItem(handle: QListViewItemH; p1: QListViewItemH); cdecl;
procedure QListViewItem_takeItem(handle: QListViewItemH; p1: QListViewItemH); cdecl;
procedure QListViewItem_removeItem(handle: QListViewItemH; p1: QListViewItemH); cdecl;
function QListViewItem_height(handle: QListViewItemH): Integer; cdecl;
procedure QListViewItem_invalidateHeight(handle: QListViewItemH); cdecl;
function QListViewItem_totalHeight(handle: QListViewItemH): Integer; cdecl;
function QListViewItem_width(handle: QListViewItemH; p1: QFontMetricsH; p2: QListViewH; column: Integer): Integer; cdecl;
procedure QListViewItem_widthChanged(handle: QListViewItemH; column: Integer); cdecl;
function QListViewItem_depth(handle: QListViewItemH): Integer; cdecl;
procedure QListViewItem_setText(handle: QListViewItemH; p1: Integer; p2: PWideString); cdecl;
procedure QListViewItem_text(handle: QListViewItemH; retval: PWideString; p1: Integer); cdecl;
procedure QListViewItem_setPixmap(handle: QListViewItemH; p1: Integer; p2: QPixmapH); cdecl;
function QListViewItem_pixmap(handle: QListViewItemH; p1: Integer): QPixmapH; cdecl;
procedure QListViewItem_key(handle: QListViewItemH; retval: PWideString; p1: Integer; p2: Boolean); cdecl;
procedure QListViewItem_sortChildItems(handle: QListViewItemH; p1: Integer; p2: Boolean); cdecl;
function QListViewItem_childCount(handle: QListViewItemH): Integer; cdecl;
function QListViewItem_isOpen(handle: QListViewItemH): Boolean; cdecl;
procedure QListViewItem_setOpen(handle: QListViewItemH; p1: Boolean); cdecl;
procedure QListViewItem_setup(handle: QListViewItemH); cdecl;
procedure QListViewItem_setSelected(handle: QListViewItemH; p1: Boolean); cdecl;
function QListViewItem_isSelected(handle: QListViewItemH): Boolean; cdecl;
procedure QListViewItem_paintCell(handle: QListViewItemH; p1: QPainterH; cg: QColorGroupH; column: Integer; width: Integer; alignment: Integer); cdecl;
procedure QListViewItem_paintBranches(handle: QListViewItemH; p: QPainterH; cg: QColorGroupH; w: Integer; y: Integer; h: Integer; s: GUIStyle); cdecl;
procedure QListViewItem_paintFocus(handle: QListViewItemH; p1: QPainterH; cg: QColorGroupH; r: PRect); cdecl;
function QListViewItem_firstChild(handle: QListViewItemH): QListViewItemH; cdecl;
function QListViewItem_nextSibling(handle: QListViewItemH): QListViewItemH; cdecl;
function QListViewItem_parent(handle: QListViewItemH): QListViewItemH; cdecl;
function QListViewItem_itemAbove(handle: QListViewItemH): QListViewItemH; cdecl;
function QListViewItem_itemBelow(handle: QListViewItemH): QListViewItemH; cdecl;
function QListViewItem_itemPos(handle: QListViewItemH): Integer; cdecl;
function QListViewItem_listView(handle: QListViewItemH): QListViewH; cdecl;
procedure QListViewItem_setSelectable(handle: QListViewItemH; enable: Boolean); cdecl;
function QListViewItem_isSelectable(handle: QListViewItemH): Boolean; cdecl;
procedure QListViewItem_setExpandable(handle: QListViewItemH; p1: Boolean); cdecl;
function QListViewItem_isExpandable(handle: QListViewItemH): Boolean; cdecl;
procedure QListViewItem_repaint(handle: QListViewItemH); cdecl;
procedure QListViewItem_sort(handle: QListViewItemH); cdecl;
procedure QListViewItem_moveItem(handle: QListViewItemH; after: QListViewItemH); cdecl;

function QListView_create(parent: QWidgetH; name: PAnsiChar; f: WFlags): QListViewH; overload; cdecl;
procedure QListView_destroy(handle: QListViewH); cdecl;
function QListView_create(parent: QWidgetH; name: PAnsiChar): QListViewH; overload; cdecl;
function QListView_treeStepSize(handle: QListViewH): Integer; cdecl;
procedure QListView_setTreeStepSize(handle: QListViewH; p1: Integer); cdecl;
procedure QListView_insertItem(handle: QListViewH; p1: QListViewItemH); cdecl;
procedure QListView_takeItem(handle: QListViewH; p1: QListViewItemH); cdecl;
procedure QListView_removeItem(handle: QListViewH; p1: QListViewItemH); cdecl;
procedure QListView_clear(handle: QListViewH); cdecl;
function QListView_header(handle: QListViewH): QHeaderH; cdecl;
function QListView_addColumn(handle: QListViewH; _label: PWideString; size: Integer): Integer; overload; cdecl;
function QListView_addColumn(handle: QListViewH; iconset: QIconSetH; _label: PWideString; size: Integer): Integer; overload; cdecl;
procedure QListView_removeColumn(handle: QListViewH; index: Integer); cdecl;
procedure QListView_setColumnText(handle: QListViewH; column: Integer; _label: PWideString); overload; cdecl;
procedure QListView_setColumnText(handle: QListViewH; column: Integer; iconset: QIconSetH; _label: PWideString); overload; cdecl;
procedure QListView_columnText(handle: QListViewH; retval: PWideString; column: Integer); cdecl;
procedure QListView_setColumnWidth(handle: QListViewH; column: Integer; width: Integer); cdecl;
function QListView_columnWidth(handle: QListViewH; column: Integer): Integer; cdecl;
procedure QListView_setColumnWidthMode(handle: QListViewH; column: Integer; p2: QListViewWidthMode); cdecl;
function QListView_columnWidthMode(handle: QListViewH; column: Integer): QListViewWidthMode; cdecl;
function QListView_columns(handle: QListViewH): Integer; cdecl;
procedure QListView_setColumnAlignment(handle: QListViewH; p1: Integer; p2: Integer); cdecl;
function QListView_columnAlignment(handle: QListViewH; p1: Integer): Integer; cdecl;
procedure QListView_show(handle: QListViewH); cdecl;
function QListView_itemAt(handle: QListViewH; screenPos: PPoint): QListViewItemH; cdecl;
procedure QListView_itemRect(handle: QListViewH; retval: PRect; p1: QListViewItemH); cdecl;
function QListView_itemPos(handle: QListViewH; p1: QListViewItemH): Integer; cdecl;
procedure QListView_ensureItemVisible(handle: QListViewH; p1: QListViewItemH); cdecl;
procedure QListView_repaintItem(handle: QListViewH; p1: QListViewItemH); cdecl;
procedure QListView_setMultiSelection(handle: QListViewH; enable: Boolean); cdecl;
function QListView_isMultiSelection(handle: QListViewH): Boolean; cdecl;
procedure QListView_setSelectionMode(handle: QListViewH; mode: QListViewSelectionMode); cdecl;
function QListView_selectionMode(handle: QListViewH): QListViewSelectionMode; cdecl;
procedure QListView_clearSelection(handle: QListViewH); cdecl;
procedure QListView_setSelected(handle: QListViewH; p1: QListViewItemH; p2: Boolean); cdecl;
function QListView_isSelected(handle: QListViewH; p1: QListViewItemH): Boolean; cdecl;
function QListView_selectedItem(handle: QListViewH): QListViewItemH; cdecl;
procedure QListView_setOpen(handle: QListViewH; p1: QListViewItemH; p2: Boolean); cdecl;
function QListView_isOpen(handle: QListViewH; p1: QListViewItemH): Boolean; cdecl;
procedure QListView_setCurrentItem(handle: QListViewH; p1: QListViewItemH); cdecl;
function QListView_currentItem(handle: QListViewH): QListViewItemH; cdecl;
function QListView_firstChild(handle: QListViewH): QListViewItemH; cdecl;
function QListView_childCount(handle: QListViewH): Integer; cdecl;
procedure QListView_setAllColumnsShowFocus(handle: QListViewH; p1: Boolean); cdecl;
function QListView_allColumnsShowFocus(handle: QListViewH): Boolean; cdecl;
procedure QListView_setItemMargin(handle: QListViewH; p1: Integer); cdecl;
function QListView_itemMargin(handle: QListViewH): Integer; cdecl;
procedure QListView_setRootIsDecorated(handle: QListViewH; p1: Boolean); cdecl;
function QListView_rootIsDecorated(handle: QListViewH): Boolean; cdecl;
procedure QListView_setSorting(handle: QListViewH; column: Integer; increasing: Boolean); cdecl;
procedure QListView_sort(handle: QListViewH); cdecl;
procedure QListView_setFont(handle: QListViewH; p1: QFontH); cdecl;
procedure QListView_setPalette(handle: QListViewH; p1: QPaletteH); cdecl;
function QListView_eventFilter(handle: QListViewH; o: QObjectH; p2: QEventH): Boolean; cdecl;
procedure QListView_sizeHint(handle: QListViewH; retval: PSize); cdecl;
procedure QListView_minimumSizeHint(handle: QListViewH; retval: PSize); cdecl;
procedure QListView_setShowSortIndicator(handle: QListViewH; show: Boolean); cdecl;
function QListView_showSortIndicator(handle: QListViewH): Boolean; cdecl;
procedure QListView_invertSelection(handle: QListViewH); cdecl;
procedure QListView_selectAll(handle: QListViewH; select: Boolean); cdecl;
procedure QListView_triggerUpdate(handle: QListViewH); cdecl;
procedure QListView_setContentsPos(handle: QListViewH; x: Integer; y: Integer); cdecl;

function QCheckListItem_create(parent: QCheckListItemH; text: PWideString; p3: QCheckListItemType): QCheckListItemH; overload; cdecl;
procedure QCheckListItem_destroy(handle: QCheckListItemH); cdecl;
function QCheckListItem_create(parent: QListViewItemH; text: PWideString; p3: QCheckListItemType): QCheckListItemH; overload; cdecl;
function QCheckListItem_create(parent: QListViewH; text: PWideString; p3: QCheckListItemType): QCheckListItemH; overload; cdecl;
function QCheckListItem_create(parent: QListViewItemH; text: PWideString; p3: QPixmapH): QCheckListItemH; overload; cdecl;
function QCheckListItem_create(parent: QListViewH; text: PWideString; p3: QPixmapH): QCheckListItemH; overload; cdecl;
procedure QCheckListItem_paintCell(handle: QCheckListItemH; p1: QPainterH; cg: QColorGroupH; column: Integer; width: Integer; alignment: Integer); cdecl;
procedure QCheckListItem_paintFocus(handle: QCheckListItemH; p1: QPainterH; cg: QColorGroupH; r: PRect); cdecl;
function QCheckListItem_width(handle: QCheckListItemH; p1: QFontMetricsH; p2: QListViewH; column: Integer): Integer; cdecl;
procedure QCheckListItem_setup(handle: QCheckListItemH); cdecl;
procedure QCheckListItem_setOn(handle: QCheckListItemH; p1: Boolean); cdecl;
function QCheckListItem_isOn(handle: QCheckListItemH): Boolean; cdecl;
function QCheckListItem_type(handle: QCheckListItemH): QCheckListItemType; cdecl;
procedure QCheckListItem_text(handle: QCheckListItemH; retval: PWideString); overload; cdecl;
procedure QCheckListItem_text(handle: QCheckListItemH; retval: PWideString; n: Integer); overload; cdecl;
procedure QCheckListItem_setEnabled(handle: QCheckListItemH; b: Boolean); cdecl;
function QCheckListItem_isEnabled(handle: QCheckListItemH): Boolean; cdecl;

function QListViewItemIterator_create(): QListViewItemIteratorH; overload; cdecl;
procedure QListViewItemIterator_destroy(handle: QListViewItemIteratorH); cdecl;
function QListViewItemIterator_create(item: QListViewItemH): QListViewItemIteratorH; overload; cdecl;
function QListViewItemIterator_create(it: QListViewItemIteratorH): QListViewItemIteratorH; overload; cdecl;
function QListViewItemIterator_create(lv: QListViewH): QListViewItemIteratorH; overload; cdecl;
function QListViewItemIterator_current(handle: QListViewItemIteratorH): QListViewItemH; cdecl;

function QMenuBar_create(parent: QWidgetH; name: PAnsiChar): QMenuBarH; cdecl;
procedure QMenuBar_destroy(handle: QMenuBarH); cdecl;
procedure QMenuBar_updateItem(handle: QMenuBarH; id: Integer); cdecl;
procedure QMenuBar_show(handle: QMenuBarH); cdecl;
procedure QMenuBar_hide(handle: QMenuBarH); cdecl;
function QMenuBar_eventFilter(handle: QMenuBarH; p1: QObjectH; p2: QEventH): Boolean; cdecl;
function QMenuBar_heightForWidth(handle: QMenuBarH; p1: Integer): Integer; cdecl;
function QMenuBar_separator(handle: QMenuBarH): QMenuBarSeparator; cdecl;
procedure QMenuBar_setSeparator(handle: QMenuBarH; when: QMenuBarSeparator); cdecl;
procedure QMenuBar_setDefaultUp(handle: QMenuBarH; p1: Boolean); cdecl;
function QMenuBar_isDefaultUp(handle: QMenuBarH): Boolean; cdecl;
function QMenuBar_customWhatsThis(handle: QMenuBarH): Boolean; cdecl;
procedure QMenuBar_sizeHint(handle: QMenuBarH; retval: PSize); cdecl;
procedure QMenuBar_minimumSize(handle: QMenuBarH; retval: PSize); cdecl;
procedure QMenuBar_minimumSizeHint(handle: QMenuBarH; retval: PSize); cdecl;
procedure QMenuBar_activateItemAt(handle: QMenuBarH; index: Integer); cdecl;
function QMenuBar_to_QMenuData(handle: QMenuBarH): QMenuDataH; cdecl;
function QMessageBox_create(parent: QWidgetH; name: PAnsiChar): QMessageBoxH; overload; cdecl;
procedure QMessageBox_destroy(handle: QMessageBoxH); cdecl;
function QMessageBox_create(caption: PWideString; text: PWideString; icon: QMessageBoxIcon; button0: Integer; button1: Integer; button2: Integer; parent: QWidgetH; name: PAnsiChar; modal: Boolean; f: WFlags): QMessageBoxH; overload; cdecl;
function QMessageBox_information(parent: QWidgetH; caption: PWideString; text: PWideString; button0: Integer; button1: Integer; button2: Integer): Integer; overload; cdecl;
function QMessageBox_information(parent: QWidgetH; caption: PWideString; text: PWideString; button0Text: PWideString; button1Text: PWideString; button2Text: PWideString; defaultButtonNumber: Integer; escapeButtonNumber: Integer): Integer; overload; cdecl;
function QMessageBox_warning(parent: QWidgetH; caption: PWideString; text: PWideString; button0: Integer; button1: Integer; button2: Integer): Integer; overload; cdecl;
function QMessageBox_warning(parent: QWidgetH; caption: PWideString; text: PWideString; button0Text: PWideString; button1Text: PWideString; button2Text: PWideString; defaultButtonNumber: Integer; escapeButtonNumber: Integer): Integer; overload; cdecl;
function QMessageBox_critical(parent: QWidgetH; caption: PWideString; text: PWideString; button0: Integer; button1: Integer; button2: Integer): Integer; overload; cdecl;
function QMessageBox_critical(parent: QWidgetH; caption: PWideString; text: PWideString; button0Text: PWideString; button1Text: PWideString; button2Text: PWideString; defaultButtonNumber: Integer; escapeButtonNumber: Integer): Integer; overload; cdecl;
procedure QMessageBox_about(parent: QWidgetH; caption: PWideString; text: PWideString); cdecl;
procedure QMessageBox_aboutQt(parent: QWidgetH; caption: PWideString); cdecl;
function QMessageBox_message(caption: PWideString; text: PWideString; buttonText: PWideString; parent: QWidgetH; name: PAnsiChar): Integer; cdecl;
function QMessageBox_query(caption: PWideString; text: PWideString; yesButtonText: PWideString; noButtonText: PWideString; parent: QWidgetH; name: PAnsiChar): Boolean; cdecl;
procedure QMessageBox_text(handle: QMessageBoxH; retval: PWideString); cdecl;
procedure QMessageBox_setText(handle: QMessageBoxH; p1: PWideString); cdecl;
function QMessageBox_icon(handle: QMessageBoxH): QMessageBoxIcon; cdecl;
procedure QMessageBox_setIcon(handle: QMessageBoxH; p1: QMessageBoxIcon); overload; cdecl;
procedure QMessageBox_setIcon(handle: QMessageBoxH; p1: QPixmapH); overload; cdecl;
function QMessageBox_iconPixmap(handle: QMessageBoxH): QPixmapH; cdecl;
procedure QMessageBox_setIconPixmap(handle: QMessageBoxH; p1: QPixmapH); cdecl;
procedure QMessageBox_buttonText(handle: QMessageBoxH; retval: PWideString; button: Integer); cdecl;
procedure QMessageBox_setButtonText(handle: QMessageBoxH; button: Integer; p2: PWideString); cdecl;
procedure QMessageBox_adjustSize(handle: QMessageBoxH); cdecl;
procedure QMessageBox_standardIcon(retval: QPixmapH; icon: QMessageBoxIcon; style: GUIStyle); cdecl;
function QMessageBox_textFormat(handle: QMessageBoxH): TextFormat; cdecl;
procedure QMessageBox_setTextFormat(handle: QMessageBoxH; p1: TextFormat); cdecl;

function QMultiLineEdit_create(parent: QWidgetH; name: PAnsiChar): QMultiLineEditH; cdecl;
procedure QMultiLineEdit_destroy(handle: QMultiLineEditH); cdecl;
procedure QMultiLineEdit_textLine(handle: QMultiLineEditH; retval: PWideString; line: Integer); cdecl;
function QMultiLineEdit_numLines(handle: QMultiLineEditH): Integer; cdecl;
procedure QMultiLineEdit_sizeHint(handle: QMultiLineEditH; retval: PSize); cdecl;
procedure QMultiLineEdit_minimumSizeHint(handle: QMultiLineEditH; retval: PSize); cdecl;
procedure QMultiLineEdit_sizePolicy(handle: QMultiLineEditH; retval: PSizePolicy); cdecl;
procedure QMultiLineEdit_setFont(handle: QMultiLineEditH; font: QFontH); cdecl;
procedure QMultiLineEdit_insertLine(handle: QMultiLineEditH; s: PWideString; line: Integer); cdecl;
procedure QMultiLineEdit_insertAt(handle: QMultiLineEditH; s: PWideString; line: Integer; col: Integer; mark: Boolean); cdecl;
procedure QMultiLineEdit_removeLine(handle: QMultiLineEditH; line: Integer); cdecl;
procedure QMultiLineEdit_cursorPosition(handle: QMultiLineEditH; line: PInteger; col: PInteger); cdecl;
procedure QMultiLineEdit_setCursorPosition(handle: QMultiLineEditH; line: Integer; col: Integer; mark: Boolean); cdecl;
procedure QMultiLineEdit_getCursorPosition(handle: QMultiLineEditH; line: PInteger; col: PInteger); cdecl;
function QMultiLineEdit_atBeginning(handle: QMultiLineEditH): Boolean; cdecl;
function QMultiLineEdit_atEnd(handle: QMultiLineEditH): Boolean; cdecl;
procedure QMultiLineEdit_setFixedVisibleLines(handle: QMultiLineEditH; lines: Integer); cdecl;
function QMultiLineEdit_maxLineWidth(handle: QMultiLineEditH): Integer; cdecl;
procedure QMultiLineEdit_setAlignment(handle: QMultiLineEditH; flags: Integer); cdecl;
function QMultiLineEdit_alignment(handle: QMultiLineEditH): Integer; cdecl;
procedure QMultiLineEdit_setValidator(handle: QMultiLineEditH; p1: QValidatorH); cdecl;
function QMultiLineEdit_validator(handle: QMultiLineEditH): QValidatorH; cdecl;
procedure QMultiLineEdit_setEdited(handle: QMultiLineEditH; p1: Boolean); cdecl;
function QMultiLineEdit_edited(handle: QMultiLineEditH): Boolean; cdecl;
procedure QMultiLineEdit_cursorWordForward(handle: QMultiLineEditH; mark: Boolean); cdecl;
procedure QMultiLineEdit_cursorWordBackward(handle: QMultiLineEditH; mark: Boolean); cdecl;
procedure QMultiLineEdit_setEchoMode(handle: QMultiLineEditH; p1: QMultiLineEditEchoMode); cdecl;
function QMultiLineEdit_echoMode(handle: QMultiLineEditH): QMultiLineEditEchoMode; cdecl;
procedure QMultiLineEdit_setMaxLength(handle: QMultiLineEditH; p1: Integer); cdecl;
function QMultiLineEdit_maxLength(handle: QMultiLineEditH): Integer; cdecl;
procedure QMultiLineEdit_setMaxLineLength(handle: QMultiLineEditH; p1: Integer); cdecl;
function QMultiLineEdit_maxLineLength(handle: QMultiLineEditH): Integer; cdecl;
procedure QMultiLineEdit_setMaxLines(handle: QMultiLineEditH; p1: Integer); cdecl;
function QMultiLineEdit_maxLines(handle: QMultiLineEditH): Integer; cdecl;
procedure QMultiLineEdit_setHMargin(handle: QMultiLineEditH; p1: Integer); cdecl;
function QMultiLineEdit_hMargin(handle: QMultiLineEditH): Integer; cdecl;
procedure QMultiLineEdit_setSelection(handle: QMultiLineEditH; row_from: Integer; col_from: Integer; row_to: Integer; col_t: Integer); cdecl;
procedure QMultiLineEdit_setWordWrap(handle: QMultiLineEditH; mode: QMultiLineEditWordWrap); cdecl;
function QMultiLineEdit_wordWrap(handle: QMultiLineEditH): QMultiLineEditWordWrap; cdecl;
procedure QMultiLineEdit_setWrapColumnOrWidth(handle: QMultiLineEditH; p1: Integer); cdecl;
function QMultiLineEdit_wrapColumnOrWidth(handle: QMultiLineEditH): Integer; cdecl;
procedure QMultiLineEdit_setWrapPolicy(handle: QMultiLineEditH; policy: QMultiLineEditWrapPolicy); cdecl;
function QMultiLineEdit_wrapPolicy(handle: QMultiLineEditH): QMultiLineEditWrapPolicy; cdecl;
function QMultiLineEdit_autoUpdate(handle: QMultiLineEditH): Boolean; cdecl;
procedure QMultiLineEdit_setAutoUpdate(handle: QMultiLineEditH; p1: Boolean); cdecl;
procedure QMultiLineEdit_setUndoEnabled(handle: QMultiLineEditH; p1: Boolean); cdecl;
function QMultiLineEdit_isUndoEnabled(handle: QMultiLineEditH): Boolean; cdecl;
procedure QMultiLineEdit_setUndoDepth(handle: QMultiLineEditH; p1: Integer); cdecl;
function QMultiLineEdit_undoDepth(handle: QMultiLineEditH): Integer; cdecl;
function QMultiLineEdit_isReadOnly(handle: QMultiLineEditH): Boolean; cdecl;
function QMultiLineEdit_isOverwriteMode(handle: QMultiLineEditH): Boolean; cdecl;
procedure QMultiLineEdit_text(handle: QMultiLineEditH; retval: PWideString); cdecl;
function QMultiLineEdit_length(handle: QMultiLineEditH): Integer; cdecl;
procedure QMultiLineEdit_setDefaultTabStop(ex: Integer); cdecl;
function QMultiLineEdit_defaultTabStop(): Integer; cdecl;
procedure QMultiLineEdit_setText(handle: QMultiLineEditH; p1: PWideString); cdecl;
procedure QMultiLineEdit_setReadOnly(handle: QMultiLineEditH; p1: Boolean); cdecl;
procedure QMultiLineEdit_setOverwriteMode(handle: QMultiLineEditH; p1: Boolean); cdecl;
procedure QMultiLineEdit_clear(handle: QMultiLineEditH); cdecl;
procedure QMultiLineEdit_append(handle: QMultiLineEditH; p1: PWideString); cdecl;
procedure QMultiLineEdit_deselect(handle: QMultiLineEditH); cdecl;
procedure QMultiLineEdit_selectAll(handle: QMultiLineEditH); cdecl;
procedure QMultiLineEdit_paste(handle: QMultiLineEditH); cdecl;
procedure QMultiLineEdit_pasteSubType(handle: QMultiLineEditH; subtype: PAnsiString); cdecl;
procedure QMultiLineEdit_copyText(handle: QMultiLineEditH); cdecl;
procedure QMultiLineEdit_copy(handle: QMultiLineEditH); cdecl;
procedure QMultiLineEdit_cut(handle: QMultiLineEditH); cdecl;
procedure QMultiLineEdit_insert(handle: QMultiLineEditH; p1: PWideString); cdecl;
procedure QMultiLineEdit_undo(handle: QMultiLineEditH); cdecl;
procedure QMultiLineEdit_redo(handle: QMultiLineEditH); cdecl;

function QScrollView_create(parent: QWidgetH; name: PAnsiChar; f: WFlags): QScrollViewH; cdecl;
procedure QScrollView_destroy(handle: QScrollViewH); cdecl;
procedure QScrollView_setResizePolicy(handle: QScrollViewH; p1: QScrollViewResizePolicy); cdecl;
function QScrollView_resizePolicy(handle: QScrollViewH): QScrollViewResizePolicy; cdecl;
procedure QScrollView_styleChange(handle: QScrollViewH; p1: QStyleH); cdecl;
procedure QScrollView_removeChild(handle: QScrollViewH; child: QWidgetH); overload; cdecl;
procedure QScrollView_addChild(handle: QScrollViewH; child: QWidgetH; x: Integer; y: Integer); cdecl;
procedure QScrollView_moveChild(handle: QScrollViewH; child: QWidgetH; x: Integer; y: Integer); cdecl;
function QScrollView_childX(handle: QScrollViewH; child: QWidgetH): Integer; cdecl;
function QScrollView_childY(handle: QScrollViewH; child: QWidgetH): Integer; cdecl;
function QScrollView_childIsVisible(handle: QScrollViewH; child: QWidgetH): Boolean; cdecl;
procedure QScrollView_showChild(handle: QScrollViewH; child: QWidgetH; yes: Boolean); cdecl;
function QScrollView_vScrollBarMode(handle: QScrollViewH): QScrollViewScrollBarMode; cdecl;
procedure QScrollView_setVScrollBarMode(handle: QScrollViewH; p1: QScrollViewScrollBarMode); cdecl;
function QScrollView_hScrollBarMode(handle: QScrollViewH): QScrollViewScrollBarMode; cdecl;
procedure QScrollView_setHScrollBarMode(handle: QScrollViewH; p1: QScrollViewScrollBarMode); cdecl;
function QScrollView_cornerWidget(handle: QScrollViewH): QWidgetH; cdecl;
procedure QScrollView_setCornerWidget(handle: QScrollViewH; p1: QWidgetH); cdecl;
function QScrollView_horizontalScrollBar(handle: QScrollViewH): QScrollBarH; cdecl;
function QScrollView_verticalScrollBar(handle: QScrollViewH): QScrollBarH; cdecl;
function QScrollView_viewport(handle: QScrollViewH): QWidgetH; cdecl;
function QScrollView_clipper(handle: QScrollViewH): QWidgetH; cdecl;
function QScrollView_visibleWidth(handle: QScrollViewH): Integer; cdecl;
function QScrollView_visibleHeight(handle: QScrollViewH): Integer; cdecl;
function QScrollView_contentsWidth(handle: QScrollViewH): Integer; cdecl;
function QScrollView_contentsHeight(handle: QScrollViewH): Integer; cdecl;
function QScrollView_contentsX(handle: QScrollViewH): Integer; cdecl;
function QScrollView_contentsY(handle: QScrollViewH): Integer; cdecl;
procedure QScrollView_resize(handle: QScrollViewH; w: Integer; h: Integer); overload; cdecl;
procedure QScrollView_resize(handle: QScrollViewH; p1: PSize); overload; cdecl;
procedure QScrollView_show(handle: QScrollViewH); cdecl;
procedure QScrollView_updateContents(handle: QScrollViewH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QScrollView_updateContents(handle: QScrollViewH; r: PRect); overload; cdecl;
procedure QScrollView_repaintContents(handle: QScrollViewH; x: Integer; y: Integer; w: Integer; h: Integer; erase: Boolean); overload; cdecl;
procedure QScrollView_repaintContents(handle: QScrollViewH; r: PRect; erase: Boolean); overload; cdecl;
procedure QScrollView_contentsToViewport(handle: QScrollViewH; x: Integer; y: Integer; vx: PInteger; vy: PInteger); overload; cdecl;
procedure QScrollView_viewportToContents(handle: QScrollViewH; vx: Integer; vy: Integer; x: PInteger; y: PInteger); overload; cdecl;
procedure QScrollView_contentsToViewport(handle: QScrollViewH; retval: PPoint; p1: PPoint); overload; cdecl;
procedure QScrollView_viewportToContents(handle: QScrollViewH; retval: PPoint; p1: PPoint); overload; cdecl;
procedure QScrollView_enableClipper(handle: QScrollViewH; y: Boolean); cdecl;
procedure QScrollView_setStaticBackground(handle: QScrollViewH; y: Boolean); cdecl;
function QScrollView_hasStaticBackground(handle: QScrollViewH): Boolean; cdecl;
procedure QScrollView_viewportSize(handle: QScrollViewH; retval: PSize; p1: Integer; p2: Integer); cdecl;
procedure QScrollView_sizePolicy(handle: QScrollViewH; retval: PSizePolicy); cdecl;
procedure QScrollView_sizeHint(handle: QScrollViewH; retval: PSize); cdecl;
procedure QScrollView_minimumSizeHint(handle: QScrollViewH; retval: PSize); cdecl;
procedure QScrollView_removeChild(handle: QScrollViewH; child: QObjectH); overload; cdecl;
procedure QScrollView_setDragAutoScroll(handle: QScrollViewH; b: Boolean); cdecl;
function QScrollView_dragAutoScroll(handle: QScrollViewH): Boolean; cdecl;
procedure QScrollView_resizeContents(handle: QScrollViewH; w: Integer; h: Integer); cdecl;
procedure QScrollView_scrollBy(handle: QScrollViewH; dx: Integer; dy: Integer); cdecl;
procedure QScrollView_setContentsPos(handle: QScrollViewH; x: Integer; y: Integer); cdecl;
procedure QScrollView_ensureVisible(handle: QScrollViewH; x: Integer; y: Integer); overload; cdecl;
procedure QScrollView_ensureVisible(handle: QScrollViewH; x: Integer; y: Integer; xmargin: Integer; ymargin: Integer); overload; cdecl;
procedure QScrollView_center(handle: QScrollViewH; x: Integer; y: Integer); overload; cdecl;
procedure QScrollView_center(handle: QScrollViewH; x: Integer; y: Integer; xmargin: Single; ymargin: Single); overload; cdecl;
procedure QScrollView_updateScrollBars(handle: QScrollViewH); cdecl;
procedure QScrollView_setEnabled(handle: QScrollViewH; enable: Boolean); cdecl;

function QSlider_create(parent: QWidgetH; name: PAnsiChar): QSliderH; overload; cdecl;
procedure QSlider_destroy(handle: QSliderH); cdecl;
function QSlider_create(p1: Orientation; parent: QWidgetH; name: PAnsiChar): QSliderH; overload; cdecl;
function QSlider_create(minValue: Integer; maxValue: Integer; pageStep: Integer; value: Integer; p5: Orientation; parent: QWidgetH; name: PAnsiChar): QSliderH; overload; cdecl;
procedure QSlider_setOrientation(handle: QSliderH; p1: Orientation); cdecl;
function QSlider_orientation(handle: QSliderH): Orientation; cdecl;
procedure QSlider_setTracking(handle: QSliderH; enable: Boolean); cdecl;
function QSlider_tracking(handle: QSliderH): Boolean; cdecl;
procedure QSlider_setPalette(handle: QSliderH; p1: QPaletteH); cdecl;
procedure QSlider_sliderRect(handle: QSliderH; retval: PRect); cdecl;
procedure QSlider_sizeHint(handle: QSliderH; retval: PSize); cdecl;
procedure QSlider_sizePolicy(handle: QSliderH; retval: PSizePolicy); cdecl;
procedure QSlider_minimumSizeHint(handle: QSliderH; retval: PSize); cdecl;
procedure QSlider_setTickmarks(handle: QSliderH; p1: QSliderTickSetting); cdecl;
function QSlider_tickmarks(handle: QSliderH): QSliderTickSetting; cdecl;
procedure QSlider_setTickInterval(handle: QSliderH; p1: Integer); cdecl;
function QSlider_tickInterval(handle: QSliderH): Integer; cdecl;
function QSlider_minValue(handle: QSliderH): Integer; cdecl;
function QSlider_maxValue(handle: QSliderH): Integer; cdecl;
procedure QSlider_setMinValue(handle: QSliderH; p1: Integer); cdecl;
procedure QSlider_setMaxValue(handle: QSliderH; p1: Integer); cdecl;
function QSlider_lineStep(handle: QSliderH): Integer; cdecl;
function QSlider_pageStep(handle: QSliderH): Integer; cdecl;
procedure QSlider_setLineStep(handle: QSliderH; p1: Integer); cdecl;
procedure QSlider_setPageStep(handle: QSliderH; p1: Integer); cdecl;
function QSlider_value(handle: QSliderH): Integer; cdecl;
procedure QSlider_setValue(handle: QSliderH; p1: Integer); cdecl;
procedure QSlider_addStep(handle: QSliderH); cdecl;
procedure QSlider_subtractStep(handle: QSliderH); cdecl;
function QSlider_to_QRangeControl(handle: QSliderH): QRangeControlH; cdecl;
function QSocketNotifier_create(socket: Integer; p2: QSocketNotifierType; parent: QObjectH; name: PAnsiChar): QSocketNotifierH; cdecl;
procedure QSocketNotifier_destroy(handle: QSocketNotifierH); cdecl;
function QSocketNotifier_socket(handle: QSocketNotifierH): Integer; cdecl;
function QSocketNotifier_type(handle: QSocketNotifierH): QSocketNotifierType; cdecl;
function QSocketNotifier_isEnabled(handle: QSocketNotifierH): Boolean; cdecl;
procedure QSocketNotifier_setEnabled(handle: QSocketNotifierH; p1: Boolean); cdecl;

function QSpinBox_create(parent: QWidgetH; name: PAnsiChar): QSpinBoxH; overload; cdecl;
procedure QSpinBox_destroy(handle: QSpinBoxH); cdecl;
function QSpinBox_create(minValue: Integer; maxValue: Integer; step: Integer; parent: QWidgetH; name: PAnsiChar): QSpinBoxH; overload; cdecl;
procedure QSpinBox_text(handle: QSpinBoxH; retval: PWideString); cdecl;
procedure QSpinBox_prefix(handle: QSpinBoxH; retval: PWideString); cdecl;
procedure QSpinBox_suffix(handle: QSpinBoxH; retval: PWideString); cdecl;
procedure QSpinBox_cleanText(handle: QSpinBoxH; retval: PWideString); cdecl;
procedure QSpinBox_setSpecialValueText(handle: QSpinBoxH; text: PWideString); cdecl;
procedure QSpinBox_specialValueText(handle: QSpinBoxH; retval: PWideString); cdecl;
procedure QSpinBox_setWrapping(handle: QSpinBoxH; on: Boolean); cdecl;
function QSpinBox_wrapping(handle: QSpinBoxH): Boolean; cdecl;
procedure QSpinBox_setButtonSymbols(handle: QSpinBoxH; p1: QSpinBoxButtonSymbols); cdecl;
function QSpinBox_buttonSymbols(handle: QSpinBoxH): QSpinBoxButtonSymbols; cdecl;
procedure QSpinBox_setValidator(handle: QSpinBoxH; v: QValidatorH); cdecl;
function QSpinBox_validator(handle: QSpinBoxH): QValidatorH; cdecl;
procedure QSpinBox_sizeHint(handle: QSpinBoxH; retval: PSize); cdecl;
procedure QSpinBox_sizePolicy(handle: QSpinBoxH; retval: PSizePolicy); cdecl;
function QSpinBox_minValue(handle: QSpinBoxH): Integer; cdecl;
function QSpinBox_maxValue(handle: QSpinBoxH): Integer; cdecl;
procedure QSpinBox_setMinValue(handle: QSpinBoxH; p1: Integer); cdecl;
procedure QSpinBox_setMaxValue(handle: QSpinBoxH; p1: Integer); cdecl;
function QSpinBox_lineStep(handle: QSpinBoxH): Integer; cdecl;
procedure QSpinBox_setLineStep(handle: QSpinBoxH; p1: Integer); cdecl;
function QSpinBox_value(handle: QSpinBoxH): Integer; cdecl;
procedure QSpinBox_setValue(handle: QSpinBoxH; value: Integer); cdecl;
procedure QSpinBox_setPrefix(handle: QSpinBoxH; text: PWideString); cdecl;
procedure QSpinBox_setSuffix(handle: QSpinBoxH; text: PWideString); cdecl;
procedure QSpinBox_stepUp(handle: QSpinBoxH); cdecl;
procedure QSpinBox_stepDown(handle: QSpinBoxH); cdecl;
procedure QSpinBox_setEnabled(handle: QSpinBoxH; p1: Boolean); cdecl;
function QSpinBox_to_QRangeControl(handle: QSpinBoxH): QRangeControlH; cdecl;
function QStyle_guiStyle(handle: QStyleH): GUIStyle; cdecl;
procedure QStyle_polish(handle: QStyleH; p1: QWidgetH); overload; cdecl;
procedure QStyle_unPolish(handle: QStyleH; p1: QWidgetH); overload; cdecl;
procedure QStyle_polish(handle: QStyleH; p1: QApplicationH); overload; cdecl;
procedure QStyle_unPolish(handle: QStyleH; p1: QApplicationH); overload; cdecl;
procedure QStyle_polish(handle: QStyleH; p1: QPaletteH); overload; cdecl;
procedure QStyle_itemRect(handle: QStyleH; retval: PRect; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; flags: Integer; enabled: Boolean; pixmap: QPixmapH; text: PWideString; len: Integer); cdecl;
procedure QStyle_drawItem(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; flags: Integer; g: QColorGroupH; enabled: Boolean; pixmap: QPixmapH; text: PWideString; len: Integer; penColor: QColorH); cdecl;
procedure QStyle_drawSeparator(handle: QStyleH; p: QPainterH; x1: Integer; y1: Integer; x2: Integer; y2: Integer; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; midLineWidth: Integer); cdecl;
procedure QStyle_drawRect(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: QColorH; lineWidth: Integer; fill: QBrushH); cdecl;
procedure QStyle_drawRectStrong(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: QColorGroupH; sunken: Boolean; lineWidth: Integer; midLineWidth: Integer; fill: QBrushH); cdecl;
procedure QStyle_drawButton(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH); cdecl;
procedure QStyle_buttonRect(handle: QStyleH; retval: PRect; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QStyle_drawButtonMask(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QStyle_drawBevelButton(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH); cdecl;
procedure QStyle_bevelButtonRect(handle: QStyleH; retval: PRect; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QStyle_drawToolButton(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH); overload; cdecl;
procedure QStyle_drawToolButton(handle: QStyleH; btn: QToolButtonH; p: QPainterH); overload; cdecl;
procedure QStyle_toolButtonRect(handle: QStyleH; retval: PRect; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QStyle_drawPanel(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: QColorGroupH; sunken: Boolean; lineWidth: Integer; fill: QBrushH); cdecl;
procedure QStyle_drawPopupPanel(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: QColorGroupH; lineWidth: Integer; fill: QBrushH); cdecl;
procedure QStyle_drawArrow(handle: QStyleH; p: QPainterH; _type: ArrowType; down: Boolean; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; enabled: Boolean; fill: QBrushH); cdecl;
procedure QStyle_exclusiveIndicatorSize(handle: QStyleH; retval: PSize); cdecl;
procedure QStyle_drawExclusiveIndicator(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; on: Boolean; down: Boolean; enabled: Boolean); cdecl;
procedure QStyle_drawExclusiveIndicatorMask(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; on: Boolean); cdecl;
procedure QStyle_indicatorSize(handle: QStyleH; retval: PSize); cdecl;
procedure QStyle_drawIndicator(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; state: Integer; down: Boolean; enabled: Boolean); cdecl;
procedure QStyle_drawIndicatorMask(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; state: Integer); cdecl;
procedure QStyle_drawFocusRect(handle: QStyleH; p1: QPainterH; p2: PRect; p3: QColorGroupH; bg: QColorH; p5: Boolean); cdecl;
procedure QStyle_drawComboButton(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; editable: Boolean; enabled: Boolean; fill: QBrushH); cdecl;
procedure QStyle_comboButtonRect(handle: QStyleH; retval: PRect; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QStyle_comboButtonFocusRect(handle: QStyleH; retval: PRect; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QStyle_drawComboButtonMask(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QStyle_drawPushButton(handle: QStyleH; btn: QPushButtonH; p: QPainterH); cdecl;
procedure QStyle_drawPushButtonLabel(handle: QStyleH; btn: QPushButtonH; p: QPainterH); cdecl;
procedure QStyle_pushButtonContentsRect(handle: QStyleH; retval: PRect; btn: QPushButtonH); cdecl;
function QStyle_menuButtonIndicatorWidth(handle: QStyleH; h: Integer): Integer; cdecl;
procedure QStyle_getButtonShift(handle: QStyleH; x: PInteger; y: PInteger); cdecl;
function QStyle_defaultFrameWidth(handle: QStyleH): Integer; cdecl;
procedure QStyle_tabbarMetrics(handle: QStyleH; p1: QTabBarH; p2: PInteger; p3: PInteger; p4: PInteger); cdecl;
procedure QStyle_drawTab(handle: QStyleH; p1: QPainterH; p2: QTabBarH; p3: QTabH; selected: Boolean); cdecl;
procedure QStyle_drawTabMask(handle: QStyleH; p1: QPainterH; p2: QTabBarH; p3: QTabH; selected: Boolean); cdecl;
procedure QStyle_scrollBarMetrics(handle: QStyleH; p1: QScrollBarH; p2: PInteger; p3: PInteger; p4: PInteger; p5: PInteger); cdecl;
procedure QStyle_drawScrollBarControls(handle: QStyleH; p1: QPainterH; p2: QScrollBarH; sliderStart: Integer; controls: Cardinal; activeControl: Cardinal); cdecl;
function QStyle_scrollBarPointOver(handle: QStyleH; p1: QScrollBarH; sliderStart: Integer; p3: PPoint): QStyleScrollControl; cdecl;
function QStyle_sliderLength(handle: QStyleH): Integer; cdecl;
procedure QStyle_drawSlider(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; p7: Orientation; tickAbove: Boolean; tickBelow: Boolean); cdecl;
procedure QStyle_drawSliderMask(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: Orientation; tickAbove: Boolean; tickBelow: Boolean); cdecl;
procedure QStyle_drawSliderGroove(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; c: QCOORD; p8: Orientation); cdecl;
procedure QStyle_drawSliderGrooveMask(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; c: QCOORD; p7: Orientation); cdecl;
function QStyle_maximumSliderDragDistance(handle: QStyleH): Integer; cdecl;
function QStyle_splitterWidth(handle: QStyleH): Integer; cdecl;
procedure QStyle_drawSplitter(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; p7: Orientation); cdecl;
procedure QStyle_drawCheckMark(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; act: Boolean; dis: Boolean); cdecl;
procedure QStyle_polishPopupMenu(handle: QStyleH; p1: QPopupMenuH); cdecl;
function QStyle_extraPopupMenuItemWidth(handle: QStyleH; checkable: Boolean; maxpmw: Integer; mi: QMenuItemH; fm: QFontMetricsH): Integer; cdecl;
function QStyle_popupSubmenuIndicatorWidth(handle: QStyleH; fm: QFontMetricsH): Integer; cdecl;
function QStyle_popupMenuItemHeight(handle: QStyleH; checkable: Boolean; mi: QMenuItemH; fm: QFontMetricsH): Integer; cdecl;
procedure QStyle_drawPopupMenuItem(handle: QStyleH; p: QPainterH; checkable: Boolean; maxpmw: Integer; tab: Integer; mi: QMenuItemH; pal: QPaletteH; act: Boolean; enabled: Boolean; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QStyle_drawMenuBarItem(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; mi: QMenuItemH; g: QColorGroupH; enabled: Boolean; active: Boolean); cdecl;
procedure QStyle_scrollBarExtent(handle: QStyleH; retval: PSize); cdecl;
function QStyle_buttonDefaultIndicatorWidth(handle: QStyleH): Integer; cdecl;
function QStyle_buttonMargin(handle: QStyleH): Integer; cdecl;
function QStyle_toolBarHandleExtent(handle: QStyleH): Integer; cdecl;
function QStyle_toolBarHandleExtend(handle: QStyleH): Integer; cdecl;
function QStyle_sliderThickness(handle: QStyleH): Integer; cdecl;
procedure QStyle_drawToolBarHandle(handle: QStyleH; p: QPainterH; r: PRect; orientation: Orientation; highlight: Boolean; cg: QColorGroupH; drawBorder: Boolean); cdecl;

function QTranslatorMessage_create(): QTranslatorMessageH; overload; cdecl;
procedure QTranslatorMessage_destroy(handle: QTranslatorMessageH); cdecl;
function QTranslatorMessage_create(context: PAnsiChar; sourceText: PAnsiChar; comment: PAnsiChar; translation: PWideString): QTranslatorMessageH; overload; cdecl;
function QTranslatorMessage_create(p1: QDataStreamH): QTranslatorMessageH; overload; cdecl;
function QTranslatorMessage_create(m: QTranslatorMessageH): QTranslatorMessageH; overload; cdecl;
function QTranslatorMessage_hash(handle: QTranslatorMessageH): Cardinal; cdecl;
function QTranslatorMessage_context(handle: QTranslatorMessageH): PAnsiChar; cdecl;
function QTranslatorMessage_sourceText(handle: QTranslatorMessageH): PAnsiChar; cdecl;
function QTranslatorMessage_comment(handle: QTranslatorMessageH): PAnsiChar; cdecl;
procedure QTranslatorMessage_setTranslation(handle: QTranslatorMessageH; translation: PWideString); cdecl;
procedure QTranslatorMessage_translation(handle: QTranslatorMessageH; retval: PWideString); cdecl;
procedure QTranslatorMessage_write(handle: QTranslatorMessageH; s: QDataStreamH; strip: Boolean; prefix: QTranslatorMessagePrefix); cdecl;
function QTranslatorMessage_commonPrefix(handle: QTranslatorMessageH; p1: QTranslatorMessageH): QTranslatorMessagePrefix; cdecl;

function QTranslator_create(parent: QObjectH; name: PAnsiChar): QTranslatorH; cdecl;
procedure QTranslator_destroy(handle: QTranslatorH); cdecl;
procedure QTranslator_find(handle: QTranslatorH; retval: PWideString; p1: PAnsiChar; p2: PAnsiChar; p3: PAnsiChar); overload; cdecl;
procedure QTranslator_find(handle: QTranslatorH; retval: PWideString; p1: PAnsiChar; p2: PAnsiChar); overload; cdecl;

function QTranslator_load(handle: QTranslatorH; filename: PWideString; directory: PWideString; search_delimiters: PWideString; suffix: PWideString): Boolean; cdecl;
function QTranslator_save(handle: QTranslatorH; filename: PWideString; mode: QTranslatorSaveMode): Boolean; cdecl;
procedure QTranslator_clear(handle: QTranslatorH); cdecl;
procedure QTranslator_insert(handle: QTranslatorH; p1: QTranslatorMessageH); overload; cdecl;
procedure QTranslator_insert(handle: QTranslatorH; p1: PAnsiChar; p2: PAnsiChar; p3: PWideString); overload; cdecl;
procedure QTranslator_remove(handle: QTranslatorH; p1: QTranslatorMessageH); overload; cdecl;
procedure QTranslator_remove(handle: QTranslatorH; p1: PAnsiChar; p2: PAnsiChar); overload; cdecl;
function QTranslator_contains(handle: QTranslatorH; p1: PAnsiChar; p2: PAnsiChar; p3: PAnsiChar): Boolean; overload; cdecl;
function QTranslator_contains(handle: QTranslatorH; p1: PAnsiChar; p2: PAnsiChar): Boolean; overload; cdecl;
procedure QTranslator_squeeze(handle: QTranslatorH; p1: QTranslatorSaveMode); overload; cdecl;
procedure QTranslator_squeeze(handle: QTranslatorH); overload; cdecl;
procedure QTranslator_unsqueeze(handle: QTranslatorH); cdecl;

function QColor_create(): QColorH; overload; cdecl;
procedure QColor_destroy(handle: QColorH); cdecl;
function QColor_create(r: Integer; g: Integer; b: Integer): QColorH; overload; cdecl;
function QColor_create(x: Integer; y: Integer; z: Integer; p4: QColorSpec): QColorH; overload; cdecl;
function QColor_create(rgb: QRgbH; pixel: Cardinal): QColorH; overload; cdecl;
function QColor_create(name: PWideString): QColorH; overload; cdecl;
function QColor_create(name: PAnsiChar): QColorH; overload; cdecl;
function QColor_create(p1: QColorH): QColorH; overload; cdecl;
function QColor_isValid(handle: QColorH): Boolean; cdecl;
function QColor_isDirty(handle: QColorH): Boolean; cdecl;
procedure QColor_name(handle: QColorH; retval: PWideString); cdecl;
procedure QColor_setNamedColor(handle: QColorH; name: PWideString); cdecl;
procedure QColor_rgb(handle: QColorH; r: PInteger; g: PInteger; b: PInteger); overload; cdecl;
procedure QColor_rgb(handle: QColorH; retval: QRgbH); overload; cdecl;
procedure QColor_setRgb(handle: QColorH; r: Integer; g: Integer; b: Integer); overload; cdecl;
procedure QColor_setRgb(handle: QColorH; rgb: QRgbH); overload; cdecl;
function QColor_red(handle: QColorH): Integer; cdecl;
function QColor_green(handle: QColorH): Integer; cdecl;
function QColor_blue(handle: QColorH): Integer; cdecl;
procedure QColor_hsv(handle: QColorH; h: PInteger; s: PInteger; v: PInteger); cdecl;
procedure QColor_getHsv(handle: QColorH; h: PInteger; s: PInteger; v: PInteger); cdecl;
procedure QColor_setHsv(handle: QColorH; h: Integer; s: Integer; v: Integer); cdecl;
procedure QColor_light(handle: QColorH; retval: QColorH; f: Integer); cdecl;
procedure QColor_dark(handle: QColorH; retval: QColorH; f: Integer); cdecl;
function QColor_lazyAlloc(): Boolean; cdecl;
procedure QColor_setLazyAlloc(p1: Boolean); cdecl;
function QColor_alloc(handle: QColorH): Cardinal; cdecl;
function QColor_pixel(handle: QColorH): Cardinal; cdecl;
function QColor_maxColors(): Integer; cdecl;
function QColor_numBitPlanes(): Integer; cdecl;
function QColor_enterAllocContext(): Integer; cdecl;
procedure QColor_leaveAllocContext(); cdecl;
function QColor_currentAllocContext(): Integer; cdecl;
procedure QColor_destroyAllocContext(p1: Integer); cdecl;
function QColor_hPal(): HPALETTE; cdecl;
function QColor_realizePal(p1: QWidgetH): Cardinal; cdecl;
procedure QColor_initialize(); cdecl;
procedure QColor_cleanup(); cdecl;

function QFont_create(): QFontH; overload; cdecl;
procedure QFont_destroy(handle: QFontH); cdecl;
function QFont_create(family: PWideString; pointSize: Integer; weight: Integer; italic: Boolean): QFontH; overload; cdecl;
function QFont_create(family: PWideString; pointSize: Integer; weight: Integer; italic: Boolean; charSet: QFontCharSet): QFontH; overload; cdecl;
function QFont_create(p1: QFontH): QFontH; overload; cdecl;
procedure QFont_family(handle: QFontH; retval: PWideString); cdecl;
procedure QFont_setFamily(handle: QFontH; p1: PWideString); cdecl;
function QFont_pointSize(handle: QFontH): Integer; cdecl;
function QFont_pointSizeFloat(handle: QFontH): Single; cdecl;
procedure QFont_setPointSize(handle: QFontH; p1: Integer); cdecl;
procedure QFont_setPointSizeFloat(handle: QFontH; p1: Single); cdecl;
function QFont_pixelSize(handle: QFontH): Integer; cdecl;
procedure QFont_setPixelSize(handle: QFontH; p1: Integer); cdecl;
procedure QFont_setPixelSizeFloat(handle: QFontH; p1: Single); cdecl;
function QFont_weight(handle: QFontH): Integer; cdecl;
procedure QFont_setWeight(handle: QFontH; p1: Integer); cdecl;
function QFont_bold(handle: QFontH): Boolean; cdecl;
procedure QFont_setBold(handle: QFontH; p1: Boolean); cdecl;
function QFont_italic(handle: QFontH): Boolean; cdecl;
procedure QFont_setItalic(handle: QFontH; p1: Boolean); cdecl;
function QFont_underline(handle: QFontH): Boolean; cdecl;
procedure QFont_setUnderline(handle: QFontH; p1: Boolean); cdecl;
function QFont_strikeOut(handle: QFontH): Boolean; cdecl;
procedure QFont_setStrikeOut(handle: QFontH; p1: Boolean); cdecl;
function QFont_fixedPitch(handle: QFontH): Boolean; cdecl;
procedure QFont_setFixedPitch(handle: QFontH; p1: Boolean); cdecl;
function QFont_styleHint(handle: QFontH): QFontStyleHint; cdecl;
procedure QFont_setStyleHint(handle: QFontH; p1: QFontStyleHint); overload; cdecl;
function QFont_styleStrategy(handle: QFontH): QFontStyleStrategy; cdecl;
procedure QFont_setStyleHint(handle: QFontH; p1: QFontStyleHint; p2: QFontStyleStrategy); overload; cdecl;
function QFont_charSet(handle: QFontH): QFontCharSet; cdecl;
procedure QFont_setCharSet(handle: QFontH; p1: QFontCharSet); cdecl;
function QFont_charSetForLocale(): QFontCharSet; cdecl;
function QFont_rawMode(handle: QFontH): Boolean; cdecl;
procedure QFont_setRawMode(handle: QFontH; p1: Boolean); cdecl;
function QFont_exactMatch(handle: QFontH): Boolean; cdecl;
function QFont_isCopyOf(handle: QFontH; p1: QFontH): Boolean; cdecl;
function QFont_handle(handle: QFontH): HFONT; overload; cdecl;

procedure QFont_setRawName(handle: QFontH; p1: PWideString); cdecl;
procedure QFont_rawName(handle: QFontH; retval: PWideString); cdecl;
procedure QFont_key(handle: QFontH; retval: PWideString); cdecl;
procedure QFont_encodingName(retval: PWideString; p1: QFontCharSet); cdecl;
procedure QFont_defaultFont(retval: QFontH); cdecl;
procedure QFont_setDefaultFont(p1: QFontH); cdecl;
procedure QFont_substitute(retval: PWideString; familyName: PWideString); cdecl;
procedure QFont_insertSubstitution(p1: PWideString; p2: PWideString); cdecl;
procedure QFont_removeSubstitution(p1: PWideString); cdecl;
procedure QFont_substitutions(retval: QStringListH); cdecl;
procedure QFont_initialize(); cdecl;
procedure QFont_locale_init(); cdecl;
procedure QFont_cleanup(); cdecl;
procedure QFont_cacheStatistics(); cdecl;
procedure QFont_qwsRenderToDisk(handle: QFontH; all: Boolean); cdecl;

function QImageTextKeyLang_create(k: PAnsiChar; l: PAnsiChar): QImageTextKeyLangH; overload; cdecl;
procedure QImageTextKeyLang_destroy(handle: QImageTextKeyLangH); cdecl;
function QImageTextKeyLang_create(): QImageTextKeyLangH; overload; cdecl;

function QImage_create(): QImageH; overload; cdecl;
procedure QImage_destroy(handle: QImageH); cdecl;
function QImage_create(width: Integer; height: Integer; depth: Integer; numColors: Integer; bitOrder: QImageEndian): QImageH; overload; cdecl;
function QImage_create(p1: PSize; depth: Integer; numColors: Integer; bitOrder: QImageEndian): QImageH; overload; cdecl;
function QImage_create(fileName: PWideString; format: PAnsiChar): QImageH; overload; cdecl;

function QImage_create(data: QByteArrayH): QImageH; overload; cdecl;
function QImage_create(data: PByte; w: Integer; h: Integer; depth: Integer; colortable: QRgbH; numColors: Integer; bitOrder: QImageEndian): QImageH; overload; cdecl;

function QImage_create(p1: QImageH): QImageH; overload; cdecl;
procedure QImage_detach(handle: QImageH); cdecl;
procedure QImage_copy(handle: QImageH; retval: QImageH); overload; cdecl;
procedure QImage_copy(handle: QImageH; retval: QImageH; x: Integer; y: Integer; w: Integer; h: Integer; conversion_flags: Integer); overload; cdecl;

procedure QImage_copy(handle: QImageH; retval: QImageH; p1: PRect); overload; cdecl;
function QImage_isNull(handle: QImageH): Boolean; cdecl;
function QImage_width(handle: QImageH): Integer; cdecl;
function QImage_height(handle: QImageH): Integer; cdecl;
procedure QImage_size(handle: QImageH; retval: PSize); cdecl;
procedure QImage_rect(handle: QImageH; retval: PRect); cdecl;
function QImage_depth(handle: QImageH): Integer; cdecl;
function QImage_numColors(handle: QImageH): Integer; cdecl;
function QImage_bitOrder(handle: QImageH): QImageEndian; cdecl;
procedure QImage_color(handle: QImageH; retval: QRgbH; i: Integer); cdecl;
procedure QImage_setColor(handle: QImageH; i: Integer; c: QRgbH); cdecl;
procedure QImage_setNumColors(handle: QImageH; p1: Integer); cdecl;
function QImage_hasAlphaBuffer(handle: QImageH): Boolean; cdecl;
procedure QImage_setAlphaBuffer(handle: QImageH; p1: Boolean); cdecl;
function QImage_allGray(handle: QImageH): Boolean; cdecl;
function QImage_isGrayscale(handle: QImageH): Boolean; cdecl;
function QImage_bits(handle: QImageH): PByte; cdecl;
function QImage_scanLine(handle: QImageH; p1: Integer): PByte; cdecl;
function QImage_jumpTable(handle: QImageH): PPByte; cdecl;
function QImage_colorTable(handle: QImageH): QRgbH; cdecl;
function QImage_numBytes(handle: QImageH): Integer; cdecl;
function QImage_bytesPerLine(handle: QImageH): Integer; cdecl;

function QImage_create(handle: QImageH; width: Integer; height: Integer; depth: Integer; numColors: Integer; bitOrder: QImageEndian): Boolean; overload; cdecl;
function QImage_create(handle: QImageH; p1: PSize; depth: Integer; numColors: Integer; bitOrder: QImageEndian): Boolean; overload; cdecl;
procedure QImage_reset(handle: QImageH); cdecl;
procedure QImage_fill(handle: QImageH; pixel: Cardinal); cdecl;
procedure QImage_invertPixels(handle: QImageH; invertAlpha: Boolean); cdecl;
procedure QImage_convertDepth(handle: QImageH; retval: QImageH; p1: Integer); overload; cdecl;
procedure QImage_convertDepthWithPalette(handle: QImageH; retval: QImageH; p1: Integer; p: QRgbH; pc: Integer; cf: Integer); cdecl;
procedure QImage_convertDepth(handle: QImageH; retval: QImageH; p1: Integer; conversion_flags: Integer); overload; cdecl;
procedure QImage_convertBitOrder(handle: QImageH; retval: QImageH; p1: QImageEndian); cdecl;
procedure QImage_smoothScale(handle: QImageH; retval: QImageH; width: Integer; height: Integer); cdecl;
procedure QImage_createAlphaMask(handle: QImageH; retval: QImageH; conversion_flags: Integer); cdecl;
procedure QImage_createHeuristicMask(handle: QImageH; retval: QImageH; clipTight: Boolean); cdecl;
procedure QImage_mirror(handle: QImageH; retval: QImageH); overload; cdecl;
procedure QImage_mirror(handle: QImageH; retval: QImageH; horizontally: Boolean; vertically: Boolean); overload; cdecl;
procedure QImage_swapRGB(handle: QImageH; retval: QImageH); cdecl;
function QImage_systemBitOrder(): QImageEndian; cdecl;
function QImage_systemByteOrder(): QImageEndian; cdecl;
function QImage_imageFormat(fileName: PWideString): PAnsiChar; cdecl;
procedure QImage_inputFormats(retval: QStrListH); cdecl;
procedure QImage_outputFormats(retval: QStrListH); cdecl;
procedure QImage_inputFormatList(retval: QStringListH); cdecl;
procedure QImage_outputFormatList(retval: QStringListH); cdecl;
function QImage_load(handle: QImageH; fileName: PWideString; format: PAnsiChar): Boolean; cdecl;
function QImage_loadFromData(handle: QImageH; buf: PByte; len: Cardinal; format: PAnsiChar): Boolean; overload; cdecl;
function QImage_loadFromData(handle: QImageH; data: QByteArrayH; format: PAnsiChar): Boolean; overload; cdecl;
function QImage_save(handle: QImageH; fileName: PWideString; format: PAnsiChar): Boolean; overload; cdecl;
function QImage_save(handle: QImageH; fileName: PWideString; format: PAnsiChar; quality: Integer): Boolean; overload; cdecl;
function QImage_valid(handle: QImageH; x: Integer; y: Integer): Boolean; cdecl;
function QImage_pixelIndex(handle: QImageH; x: Integer; y: Integer): Integer; cdecl;
procedure QImage_pixel(handle: QImageH; retval: QRgbH; x: Integer; y: Integer); cdecl;
procedure QImage_setPixel(handle: QImageH; x: Integer; y: Integer; index_or_rgb: Cardinal); cdecl;
function QImage_dotsPerMeterX(handle: QImageH): Integer; cdecl;
function QImage_dotsPerMeterY(handle: QImageH): Integer; cdecl;
procedure QImage_setDotsPerMeterX(handle: QImageH; p1: Integer); cdecl;
procedure QImage_setDotsPerMeterY(handle: QImageH; p1: Integer); cdecl;
procedure QImage_offset(handle: QImageH; retval: PPoint); cdecl;
procedure QImage_setOffset(handle: QImageH; p1: PPoint); cdecl;

procedure QImage_textLanguages(handle: QImageH; retval: QStringListH); cdecl;
procedure QImage_textKeys(handle: QImageH; retval: QStringListH); cdecl;
procedure QImage_text(handle: QImageH; retval: PWideString; key: PAnsiChar; lang: PAnsiChar); overload; cdecl;
procedure QImage_text(handle: QImageH; retval: PWideString; p1: QImageTextKeyLangH); overload; cdecl;
procedure QImage_setText(handle: QImageH; key: PAnsiChar; lang: PAnsiChar; p3: PWideString); cdecl;

function QImageIO_create(): QImageIOH; overload; cdecl;
procedure QImageIO_destroy(handle: QImageIOH); cdecl;
function QImageIO_create(ioDevice: QIODeviceH; format: PAnsiChar): QImageIOH; overload; cdecl;
function QImageIO_create(fileName: PWideString; format: PAnsiChar): QImageIOH; overload; cdecl;
function QImageIO_image(handle: QImageIOH): QImageH; cdecl;
function QImageIO_status(handle: QImageIOH): Integer; cdecl;
function QImageIO_format(handle: QImageIOH): PAnsiChar; cdecl;
function QImageIO_ioDevice(handle: QImageIOH): QIODeviceH; cdecl;
procedure QImageIO_fileName(handle: QImageIOH; retval: PWideString); cdecl;
function QImageIO_parameters(handle: QImageIOH): PAnsiChar; cdecl;
procedure QImageIO_description(handle: QImageIOH; retval: PWideString); cdecl;
procedure QImageIO_setImage(handle: QImageIOH; p1: QImageH); cdecl;
procedure QImageIO_setStatus(handle: QImageIOH; p1: Integer); cdecl;
procedure QImageIO_setFormat(handle: QImageIOH; p1: PAnsiChar); cdecl;
procedure QImageIO_setIODevice(handle: QImageIOH; p1: QIODeviceH); cdecl;
procedure QImageIO_setFileName(handle: QImageIOH; p1: PWideString); cdecl;
procedure QImageIO_setParameters(handle: QImageIOH; p1: PAnsiChar); cdecl;
procedure QImageIO_setDescription(handle: QImageIOH; p1: PWideString); cdecl;
function QImageIO_read(handle: QImageIOH): Boolean; cdecl;
function QImageIO_write(handle: QImageIOH): Boolean; cdecl;
function QImageIO_imageFormat(fileName: PWideString): PAnsiChar; overload; cdecl;
function QImageIO_imageFormat(p1: QIODeviceH): PAnsiChar; overload; cdecl;
procedure QImageIO_inputFormats(retval: QStrListH); cdecl;
procedure QImageIO_outputFormats(retval: QStrListH); cdecl;

function QIconSet_create(): QIconSetH; overload; cdecl;
procedure QIconSet_destroy(handle: QIconSetH); cdecl;
function QIconSet_create(p1: QPixmapH; p2: QIconSetSize): QIconSetH; overload; cdecl;
function QIconSet_create(smallPix: QPixmapH; largePix: QPixmapH): QIconSetH; overload; cdecl;
function QIconSet_create(p1: QIconSetH): QIconSetH; overload; cdecl;
procedure QIconSet_reset(handle: QIconSetH; p1: QPixmapH; p2: QIconSetSize); cdecl;
procedure QIconSet_setPixmap(handle: QIconSetH; p1: QPixmapH; p2: QIconSetSize; p3: QIconSetMode); overload; cdecl;
procedure QIconSet_setPixmap(handle: QIconSetH; p1: PWideString; p2: QIconSetSize; p3: QIconSetMode); overload; cdecl;
procedure QIconSet_pixmap(handle: QIconSetH; retval: QPixmapH; p1: QIconSetSize; p2: QIconSetMode); overload; cdecl;
procedure QIconSet_pixmap(handle: QIconSetH; retval: QPixmapH; s: QIconSetSize; enabled: Boolean); overload; cdecl;
procedure QIconSet_pixmap(handle: QIconSetH; retval: QPixmapH); overload; cdecl;
function QIconSet_isGenerated(handle: QIconSetH; p1: QIconSetSize; p2: QIconSetMode): Boolean; cdecl;
function QIconSet_isNull(handle: QIconSetH): Boolean; cdecl;
procedure QIconSet_detach(handle: QIconSetH); cdecl;

function QMovie_create(): QMovieH; overload; cdecl;
procedure QMovie_destroy(handle: QMovieH); cdecl;
function QMovie_create(bufsize: Integer): QMovieH; overload; cdecl;
function QMovie_create(p1: QDataSourceH; bufsize: Integer): QMovieH; overload; cdecl;
function QMovie_create(fileName: PWideString; bufsize: Integer): QMovieH; overload; cdecl;
function QMovie_create(data: QByteArrayH; bufsize: Integer): QMovieH; overload; cdecl;
function QMovie_create(p1: QMovieH): QMovieH; overload; cdecl;
function QMovie_pushSpace(handle: QMovieH): Integer; cdecl;
procedure QMovie_pushData(handle: QMovieH; data: PByte; length: Integer); cdecl;
function QMovie_backgroundColor(handle: QMovieH): QColorH; cdecl;
procedure QMovie_setBackgroundColor(handle: QMovieH; p1: QColorH); cdecl;
procedure QMovie_getValidRect(handle: QMovieH; retval: PRect); cdecl;
function QMovie_framePixmap(handle: QMovieH): QPixmapH; cdecl;
function QMovie_frameImage(handle: QMovieH): QImageH; cdecl;
function QMovie_isNull(handle: QMovieH): Boolean; cdecl;
function QMovie_frameNumber(handle: QMovieH): Integer; cdecl;
function QMovie_steps(handle: QMovieH): Integer; cdecl;
function QMovie_paused(handle: QMovieH): Boolean; cdecl;
function QMovie_finished(handle: QMovieH): Boolean; cdecl;
function QMovie_running(handle: QMovieH): Boolean; cdecl;
procedure QMovie_unpause(handle: QMovieH); cdecl;
procedure QMovie_pause(handle: QMovieH); cdecl;
procedure QMovie_step(handle: QMovieH); overload; cdecl;
procedure QMovie_step(handle: QMovieH; p1: Integer); overload; cdecl;
procedure QMovie_restart(handle: QMovieH); cdecl;
function QMovie_speed(handle: QMovieH): Integer; cdecl;
procedure QMovie_setSpeed(handle: QMovieH; p1: Integer); cdecl;
procedure QMovie_connectResize(handle: QMovieH; receiver: QObjectH; member: PAnsiChar); cdecl;
procedure QMovie_disconnectResize(handle: QMovieH; receiver: QObjectH; member: PAnsiChar); cdecl;
procedure QMovie_connectUpdate(handle: QMovieH; receiver: QObjectH; member: PAnsiChar); cdecl;
procedure QMovie_disconnectUpdate(handle: QMovieH; receiver: QObjectH; member: PAnsiChar); cdecl;
procedure QMovie_setDisplayWidget(handle: QMovieH; w: QWidgetH); cdecl;
procedure QMovie_connectStatus(handle: QMovieH; receiver: QObjectH; member: PAnsiChar); cdecl;
procedure QMovie_disconnectStatus(handle: QMovieH; receiver: QObjectH; member: PAnsiChar); cdecl;

function QPaintDevice_devType(handle: QPaintDeviceH): Integer; cdecl;
function QPaintDevice_isExtDev(handle: QPaintDeviceH): Boolean; cdecl;
function QPaintDevice_paintingActive(handle: QPaintDeviceH): Boolean; cdecl;
function QPaintDevice_handle(handle: QPaintDeviceH): HDC; overload; cdecl;

function QColorGroup_create(): QColorGroupH; overload; cdecl;
procedure QColorGroup_destroy(handle: QColorGroupH); cdecl;
function QColorGroup_create(foreground: QColorH; button: QColorH; light: QColorH; dark: QColorH; mid: QColorH; text: QColorH; base: QColorH): QColorGroupH; overload; cdecl;
function QColorGroup_create(foreground: QBrushH; button: QBrushH; light: QBrushH; dark: QBrushH; mid: QBrushH; text: QBrushH; bright_text: QBrushH; base: QBrushH; background: QBrushH): QColorGroupH; overload; cdecl;
function QColorGroup_create(p1: QColorGroupH): QColorGroupH; overload; cdecl;
function QColorGroup_color(handle: QColorGroupH; p1: QColorGroupColorRole): QColorH; cdecl;
function QColorGroup_brush(handle: QColorGroupH; p1: QColorGroupColorRole): QBrushH; cdecl;
procedure QColorGroup_setColor(handle: QColorGroupH; p1: QColorGroupColorRole; p2: QColorH); cdecl;
procedure QColorGroup_setBrush(handle: QColorGroupH; p1: QColorGroupColorRole; p2: QBrushH); cdecl;
function QColorGroup_foreground(handle: QColorGroupH): QColorH; cdecl;
function QColorGroup_button(handle: QColorGroupH): QColorH; cdecl;
function QColorGroup_light(handle: QColorGroupH): QColorH; cdecl;
function QColorGroup_dark(handle: QColorGroupH): QColorH; cdecl;
function QColorGroup_mid(handle: QColorGroupH): QColorH; cdecl;
function QColorGroup_text(handle: QColorGroupH): QColorH; cdecl;
function QColorGroup_base(handle: QColorGroupH): QColorH; cdecl;
function QColorGroup_background(handle: QColorGroupH): QColorH; cdecl;
function QColorGroup_midlight(handle: QColorGroupH): QColorH; cdecl;
function QColorGroup_brightText(handle: QColorGroupH): QColorH; cdecl;
function QColorGroup_buttonText(handle: QColorGroupH): QColorH; cdecl;
function QColorGroup_shadow(handle: QColorGroupH): QColorH; cdecl;
function QColorGroup_highlight(handle: QColorGroupH): QColorH; cdecl;
function QColorGroup_highlightedText(handle: QColorGroupH): QColorH; cdecl;

function QPalette_create(): QPaletteH; overload; cdecl;
procedure QPalette_destroy(handle: QPaletteH); cdecl;
function QPalette_create(button: QColorH): QPaletteH; overload; cdecl;
function QPalette_create(button: QColorH; background: QColorH): QPaletteH; overload; cdecl;
function QPalette_create(active: QColorGroupH; disabled: QColorGroupH; inactive: QColorGroupH): QPaletteH; overload; cdecl;
function QPalette_create(p1: QPaletteH): QPaletteH; overload; cdecl;
function QPalette_color(handle: QPaletteH; p1: QPaletteColorGroup; p2: QColorGroupColorRole): QColorH; cdecl;
function QPalette_brush(handle: QPaletteH; p1: QPaletteColorGroup; p2: QColorGroupColorRole): QBrushH; cdecl;
procedure QPalette_setColor(handle: QPaletteH; p1: QPaletteColorGroup; p2: QColorGroupColorRole; p3: QColorH); overload; cdecl;
procedure QPalette_setBrush(handle: QPaletteH; p1: QPaletteColorGroup; p2: QColorGroupColorRole; p3: QBrushH); overload; cdecl;
procedure QPalette_setColor(handle: QPaletteH; p1: QColorGroupColorRole; p2: QColorH); overload; cdecl;
procedure QPalette_setBrush(handle: QPaletteH; p1: QColorGroupColorRole; p2: QBrushH); overload; cdecl;
procedure QPalette_copy(handle: QPaletteH; retval: QPaletteH); cdecl;
function QPalette_active(handle: QPaletteH): QColorGroupH; cdecl;
function QPalette_disabled(handle: QPaletteH): QColorGroupH; cdecl;
function QPalette_inactive(handle: QPaletteH): QColorGroupH; cdecl;
function QPalette_normal(handle: QPaletteH): QColorGroupH; cdecl;
procedure QPalette_setActive(handle: QPaletteH; p1: QColorGroupH); cdecl;
procedure QPalette_setDisabled(handle: QPaletteH; p1: QColorGroupH); cdecl;
procedure QPalette_setInactive(handle: QPaletteH; p1: QColorGroupH); cdecl;
procedure QPalette_setNormal(handle: QPaletteH; p1: QColorGroupH); cdecl;
function QPalette_isCopyOf(handle: QPaletteH; p1: QPaletteH): Boolean; cdecl;
function QPalette_serialNumber(handle: QPaletteH): Integer; cdecl;

function QPixmap_create(): QPixmapH; overload; cdecl;
procedure QPixmap_destroy(handle: QPixmapH); cdecl;
function QPixmap_create(w: Integer; h: Integer; depth: Integer; p4: QPixmapOptimization): QPixmapH; overload; cdecl;
function QPixmap_create(p1: PSize; depth: Integer; p3: QPixmapOptimization): QPixmapH; overload; cdecl;
function QPixmap_create(fileName: PWideString; format: PAnsiChar; mode: QPixmapColorMode): QPixmapH; overload; cdecl;
function QPixmap_create(fileName: PWideString; format: PAnsiChar; conversion_flags: Integer): QPixmapH; overload; cdecl;

function QPixmap_create(data: QByteArrayH): QPixmapH; overload; cdecl;
function QPixmap_create(p1: QPixmapH): QPixmapH; overload; cdecl;
function QPixmap_isNull(handle: QPixmapH): Boolean; cdecl;
function QPixmap_width(handle: QPixmapH): Integer; cdecl;
function QPixmap_height(handle: QPixmapH): Integer; cdecl;
procedure QPixmap_size(handle: QPixmapH; retval: PSize); cdecl;
procedure QPixmap_rect(handle: QPixmapH; retval: PRect); cdecl;
function QPixmap_depth(handle: QPixmapH): Integer; cdecl;
function QPixmap_defaultDepth(): Integer; cdecl;
procedure QPixmap_fill(handle: QPixmapH; fillColor: QColorH); overload; cdecl;
procedure QPixmap_fill(handle: QPixmapH; p1: QWidgetH; xofs: Integer; yofs: Integer); overload; cdecl;
procedure QPixmap_fill(handle: QPixmapH; p1: QWidgetH; ofs: PPoint); overload; cdecl;
procedure QPixmap_resize(handle: QPixmapH; width: Integer; height: Integer); overload; cdecl;
procedure QPixmap_resize(handle: QPixmapH; p1: PSize); overload; cdecl;
function QPixmap_mask(handle: QPixmapH): QBitmapH; cdecl;
procedure QPixmap_setMask(handle: QPixmapH; p1: QBitmapH); cdecl;
function QPixmap_selfMask(handle: QPixmapH): Boolean; cdecl;
procedure QPixmap_createHeuristicMask(handle: QPixmapH; retval: QBitmapH; clipTight: Boolean); cdecl;
procedure QPixmap_grabWindow(retval: QPixmapH; p1: Cardinal; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QPixmap_grabWidget(retval: QPixmapH; widget: QWidgetH; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QPixmap_xForm(handle: QPixmapH; retval: QPixmapH; p1: QWMatrixH); cdecl;
procedure QPixmap_trueMatrix(retval: QWMatrixH; p1: QWMatrixH; w: Integer; h: Integer); cdecl;
procedure QPixmap_convertToImage(handle: QPixmapH; retval: QImageH); cdecl;
function QPixmap_convertFromImage(handle: QPixmapH; p1: QImageH; mode: QPixmapColorMode): Boolean; overload; cdecl;
function QPixmap_convertFromImage(handle: QPixmapH; p1: QImageH; conversion_flags: Integer): Boolean; overload; cdecl;
function QPixmap_imageFormat(fileName: PWideString): PAnsiChar; cdecl;
function QPixmap_load(handle: QPixmapH; fileName: PWideString; format: PAnsiChar; mode: QPixmapColorMode): Boolean; overload; cdecl;
function QPixmap_load(handle: QPixmapH; fileName: PWideString; format: PAnsiChar; conversion_flags: Integer): Boolean; overload; cdecl;
function QPixmap_loadFromData(handle: QPixmapH; buf: PByte; len: Cardinal; format: PAnsiChar; mode: QPixmapColorMode): Boolean; overload; cdecl;
function QPixmap_loadFromData(handle: QPixmapH; buf: PByte; len: Cardinal; format: PAnsiChar; conversion_flags: Integer): Boolean; overload; cdecl;
function QPixmap_loadFromData(handle: QPixmapH; data: QByteArrayH; format: PAnsiChar; conversion_flags: Integer): Boolean; overload; cdecl;
function QPixmap_save(handle: QPixmapH; fileName: PWideString; format: PAnsiChar): Boolean; overload; cdecl;
function QPixmap_save(handle: QPixmapH; fileName: PWideString; format: PAnsiChar; quality: Integer): Boolean; overload; cdecl;
function QPixmap_hbm(handle: QPixmapH): HBITMAP; cdecl;
function QPixmap_serialNumber(handle: QPixmapH): Integer; cdecl;
function QPixmap_optimization(handle: QPixmapH): QPixmapOptimization; cdecl;
procedure QPixmap_setOptimization(handle: QPixmapH; p1: QPixmapOptimization); cdecl;
function QPixmap_defaultOptimization(): QPixmapOptimization; cdecl;
procedure QPixmap_setDefaultOptimization(p1: QPixmapOptimization); cdecl;
procedure QPixmap_detach(handle: QPixmapH); cdecl;
function QPixmap_isQBitmap(handle: QPixmapH): Boolean; cdecl;
function QPixmap_isMultiCellPixmap(handle: QPixmapH): Boolean; cdecl;
function QPixmap_multiCellHandle(handle: QPixmapH): HDC; cdecl;
function QPixmap_multiCellBitmap(handle: QPixmapH): HBITMAP; cdecl;
function QPixmap_multiCellOffset(handle: QPixmapH): Integer; cdecl;
function QPixmap_allocCell(handle: QPixmapH): Integer; cdecl;
procedure QPixmap_freeCell(handle: QPixmapH; p1: Boolean); cdecl;

function QPixmap_clut(handle: QPixmapH): QRgbH; cdecl;
function QPixmap_numCols(handle: QPixmapH): Integer; cdecl;

function QPrinter_create(): QPrinterH; cdecl;
procedure QPrinter_destroy(handle: QPrinterH); cdecl;
procedure QPrinter_printerName(handle: QPrinterH; retval: PWideString); cdecl;
procedure QPrinter_setPrinterName(handle: QPrinterH; p1: PWideString); cdecl;
function QPrinter_outputToFile(handle: QPrinterH): Boolean; cdecl;
procedure QPrinter_setOutputToFile(handle: QPrinterH; p1: Boolean); cdecl;
procedure QPrinter_outputFileName(handle: QPrinterH; retval: PWideString); cdecl;
procedure QPrinter_setOutputFileName(handle: QPrinterH; p1: PWideString); cdecl;
procedure QPrinter_printProgram(handle: QPrinterH; retval: PWideString); cdecl;
procedure QPrinter_setPrintProgram(handle: QPrinterH; p1: PWideString); cdecl;
procedure QPrinter_printerSelectionOption(handle: QPrinterH; retval: PWideString); cdecl;
procedure QPrinter_setPrinterSelectionOption(handle: QPrinterH; p1: PWideString); cdecl;
procedure QPrinter_docName(handle: QPrinterH; retval: PWideString); cdecl;
procedure QPrinter_setDocName(handle: QPrinterH; p1: PWideString); cdecl;
procedure QPrinter_creator(handle: QPrinterH; retval: PWideString); cdecl;
procedure QPrinter_setCreator(handle: QPrinterH; p1: PWideString); cdecl;
function QPrinter_orientation(handle: QPrinterH): QPrinterOrientation; cdecl;
procedure QPrinter_setOrientation(handle: QPrinterH; p1: QPrinterOrientation); cdecl;
function QPrinter_pageSize(handle: QPrinterH): QPrinterPageSize; cdecl;
procedure QPrinter_setPageSize(handle: QPrinterH; p1: QPrinterPageSize); cdecl;
procedure QPrinter_setPageOrder(handle: QPrinterH; p1: QPrinterPageOrder); cdecl;
function QPrinter_pageOrder(handle: QPrinterH): QPrinterPageOrder; cdecl;
procedure QPrinter_setColorMode(handle: QPrinterH; p1: QPrinterColorMode); cdecl;
function QPrinter_colorMode(handle: QPrinterH): QPrinterColorMode; cdecl;
procedure QPrinter_setFullPage(handle: QPrinterH; p1: Boolean); cdecl;
function QPrinter_fullPage(handle: QPrinterH): Boolean; cdecl;
procedure QPrinter_margins(handle: QPrinterH; retval: PSize); cdecl;
function QPrinter_fromPage(handle: QPrinterH): Integer; cdecl;
function QPrinter_toPage(handle: QPrinterH): Integer; cdecl;
procedure QPrinter_setFromTo(handle: QPrinterH; fromPage: Integer; toPage: Integer); cdecl;
function QPrinter_minPage(handle: QPrinterH): Integer; cdecl;
function QPrinter_maxPage(handle: QPrinterH): Integer; cdecl;
procedure QPrinter_setMinMax(handle: QPrinterH; minPage: Integer; maxPage: Integer); cdecl;
function QPrinter_numCopies(handle: QPrinterH): Integer; cdecl;
procedure QPrinter_setNumCopies(handle: QPrinterH; p1: Integer); cdecl;
function QPrinter_newPage(handle: QPrinterH): Boolean; cdecl;
function QPrinter_abort(handle: QPrinterH): Boolean; cdecl;
function QPrinter_aborted(handle: QPrinterH): Boolean; cdecl;
function QPrinter_setup(handle: QPrinterH; parent: QWidgetH): Boolean; cdecl;

function QRegion_create(): QRegionH; overload; cdecl;
procedure QRegion_destroy(handle: QRegionH); cdecl;
function QRegion_create(x: Integer; y: Integer; w: Integer; h: Integer; p5: QRegionRegionType): QRegionH; overload; cdecl;
function QRegion_create(p1: PRect; p2: QRegionRegionType): QRegionH; overload; cdecl;
function QRegion_create(p1: PPointArray; winding: Boolean): QRegionH; overload; cdecl;
function QRegion_create(p1: QRegionH): QRegionH; overload; cdecl;
function QRegion_create(p1: QBitmapH): QRegionH; overload; cdecl;
function QRegion_isNull(handle: QRegionH): Boolean; cdecl;
function QRegion_isEmpty(handle: QRegionH): Boolean; cdecl;
function QRegion_contains(handle: QRegionH; p: PPoint): Boolean; overload; cdecl;
function QRegion_contains(handle: QRegionH; r: PRect): Boolean; overload; cdecl;
procedure QRegion_translate(handle: QRegionH; dx: Integer; dy: Integer); cdecl;
procedure QRegion_unite(handle: QRegionH; retval: QRegionH; p1: QRegionH); cdecl;
procedure QRegion_intersect(handle: QRegionH; retval: QRegionH; p1: QRegionH); cdecl;
procedure QRegion_subtract(handle: QRegionH; retval: QRegionH; p1: QRegionH); cdecl;
procedure QRegion_eor(handle: QRegionH; retval: QRegionH; p1: QRegionH); cdecl;
procedure QRegion_boundingRect(handle: QRegionH; retval: PRect); cdecl;

procedure QRegion_setRects(handle: QRegionH; p1: PRect; p2: Integer); cdecl;
function QRegion_handle(handle: QRegionH): HRGN; overload; cdecl;

function QObject_create(parent: QObjectH; name: PAnsiChar): QObjectH; cdecl;
procedure QObject_destroy(handle: QObjectH); cdecl;
procedure QObject_tr(retval: PWideString; p1: PAnsiChar); overload; cdecl;
procedure QObject_tr(retval: PWideString; p1: PAnsiChar; p2: PAnsiChar); overload; cdecl;
function QObject_event(handle: QObjectH; p1: QEventH): Boolean; cdecl;
function QObject_eventFilter(handle: QObjectH; p1: QObjectH; p2: QEventH): Boolean; cdecl;
function QObject_metaObject(handle: QObjectH): QMetaObjectH; cdecl;
function QObject_className(handle: QObjectH): PAnsiChar; cdecl;
function QObject_isA(handle: QObjectH; p1: PAnsiChar): Boolean; cdecl;
function QObject_inherits(handle: QObjectH; p1: PAnsiChar): Boolean; cdecl;
function QObject_name(handle: QObjectH): PAnsiChar; overload; cdecl;
function QObject_name(handle: QObjectH; defaultName: PAnsiChar): PAnsiChar; overload; cdecl;
procedure QObject_setName(handle: QObjectH; name: PAnsiChar); cdecl;
function QObject_isWidgetType(handle: QObjectH): Boolean; cdecl;
function QObject_highPriority(handle: QObjectH): Boolean; cdecl;
function QObject_signalsBlocked(handle: QObjectH): Boolean; cdecl;
procedure QObject_blockSignals(handle: QObjectH; b: Boolean); cdecl;
function QObject_startTimer(handle: QObjectH; interval: Integer): Integer; cdecl;
procedure QObject_killTimer(handle: QObjectH; id: Integer); cdecl;
procedure QObject_killTimers(handle: QObjectH); cdecl;
function QObject_child(handle: QObjectH; name: PAnsiChar; _type: PAnsiChar): QObjectH; cdecl;
function QObject_children(handle: QObjectH): QObjectListH; cdecl;
function QObject_objectTrees(): QObjectListH; cdecl;
function QObject_queryList(handle: QObjectH; inheritsClass: PAnsiChar; objName: PAnsiChar; regexpMatch: Boolean; recursiveSearch: Boolean): QObjectListH; cdecl;
procedure QObject_insertChild(handle: QObjectH; p1: QObjectH); cdecl;
procedure QObject_removeChild(handle: QObjectH; p1: QObjectH); cdecl;
procedure QObject_installEventFilter(handle: QObjectH; p1: QObjectH); cdecl;
procedure QObject_removeEventFilter(handle: QObjectH; p1: QObjectH); cdecl;
function QObject_connect(sender: QObjectH; signal: PAnsiChar; receiver: QObjectH; member: PAnsiChar): Boolean; overload; cdecl;
function QObject_connect(handle: QObjectH; sender: QObjectH; signal: PAnsiChar; member: PAnsiChar): Boolean; overload; cdecl;
function QObject_disconnect(sender: QObjectH; signal: PAnsiChar; receiver: QObjectH; member: PAnsiChar): Boolean; overload; cdecl;

function QObject_disconnect(handle: QObjectH; receiver: QObjectH; member: PAnsiChar): Boolean; overload; cdecl;
procedure QObject_dumpObjectTree(handle: QObjectH); cdecl;
procedure QObject_dumpObjectInfo(handle: QObjectH); cdecl;

function QObject_parent(handle: QObjectH): QObjectH; cdecl;
procedure QObject_superClasses(handle: QObjectH; retval: QStringListH; includeThis: Boolean); cdecl;

procedure QSenderObject_setSender(handle: QSenderObjectH; s: QObjectH); cdecl;

function QBrush_create(): QBrushH; overload; cdecl;
procedure QBrush_destroy(handle: QBrushH); cdecl;
function QBrush_create(p1: BrushStyle): QBrushH; overload; cdecl;
function QBrush_create(p1: QColorH; p2: BrushStyle): QBrushH; overload; cdecl;
function QBrush_create(p1: QColorH; p2: QPixmapH): QBrushH; overload; cdecl;
function QBrush_create(p1: QBrushH): QBrushH; overload; cdecl;
function QBrush_style(handle: QBrushH): BrushStyle; cdecl;
procedure QBrush_setStyle(handle: QBrushH; p1: BrushStyle); cdecl;
function QBrush_color(handle: QBrushH): QColorH; cdecl;
procedure QBrush_setColor(handle: QBrushH; p1: QColorH); cdecl;
function QBrush_pixmap(handle: QBrushH): QPixmapH; cdecl;
procedure QBrush_setPixmap(handle: QBrushH; p1: QPixmapH); cdecl;

function QButtonGroup_create(parent: QWidgetH; name: PAnsiChar): QButtonGroupH; overload; cdecl;
procedure QButtonGroup_destroy(handle: QButtonGroupH); cdecl;
function QButtonGroup_create(title: PWideString; parent: QWidgetH; name: PAnsiChar): QButtonGroupH; overload; cdecl;
function QButtonGroup_create(columns: Integer; o: Orientation; parent: QWidgetH; name: PAnsiChar): QButtonGroupH; overload; cdecl;
function QButtonGroup_create(columns: Integer; o: Orientation; title: PWideString; parent: QWidgetH; name: PAnsiChar): QButtonGroupH; overload; cdecl;
function QButtonGroup_isExclusive(handle: QButtonGroupH): Boolean; cdecl;
function QButtonGroup_isRadioButtonExclusive(handle: QButtonGroupH): Boolean; cdecl;
procedure QButtonGroup_setExclusive(handle: QButtonGroupH; p1: Boolean); cdecl;
procedure QButtonGroup_setRadioButtonExclusive(handle: QButtonGroupH; p1: Boolean); cdecl;
function QButtonGroup_insert(handle: QButtonGroupH; p1: QButtonH; id: Integer): Integer; cdecl;
procedure QButtonGroup_remove(handle: QButtonGroupH; p1: QButtonH); cdecl;
function QButtonGroup_find(handle: QButtonGroupH; id: Integer): QButtonH; cdecl;
function QButtonGroup_id(handle: QButtonGroupH; p1: QButtonH): Integer; cdecl;
function QButtonGroup_count(handle: QButtonGroupH): Integer; cdecl;
procedure QButtonGroup_setButton(handle: QButtonGroupH; id: Integer); cdecl;
procedure QButtonGroup_moveFocus(handle: QButtonGroupH; p1: Integer); cdecl;
function QButtonGroup_selected(handle: QButtonGroupH): QButtonH; cdecl;

function QCheckBox_create(parent: QWidgetH; name: PAnsiChar): QCheckBoxH; overload; cdecl;
procedure QCheckBox_destroy(handle: QCheckBoxH); cdecl;
function QCheckBox_create(text: PWideString; parent: QWidgetH; name: PAnsiChar): QCheckBoxH; overload; cdecl;
function QCheckBox_isChecked(handle: QCheckBoxH): Boolean; cdecl;
procedure QCheckBox_setChecked(handle: QCheckBoxH; check: Boolean); cdecl;
procedure QCheckBox_setNoChange(handle: QCheckBoxH); cdecl;
procedure QCheckBox_setTristate(handle: QCheckBoxH; y: Boolean); cdecl;
function QCheckBox_isTristate(handle: QCheckBoxH): Boolean; cdecl;
procedure QCheckBox_sizeHint(handle: QCheckBoxH; retval: PSize); cdecl;
procedure QCheckBox_sizePolicy(handle: QCheckBoxH; retval: PSizePolicy); cdecl;

procedure QClipboard_clear(handle: QClipboardH); cdecl;
function QClipboard_ownsSelection(handle: QClipboardH): Boolean; cdecl;
function QClipboard_data(handle: QClipboardH): QMimeSourceH; cdecl;
procedure QClipboard_setData(handle: QClipboardH; p1: QMimeSourceH); cdecl;
procedure QClipboard_text(handle: QClipboardH; retval: PWideString); overload; cdecl;
procedure QClipboard_text(handle: QClipboardH; retval: PWideString; subtype: PAnsiString); overload; cdecl;
procedure QClipboard_setText(handle: QClipboardH; p1: PWideString); cdecl;
procedure QClipboard_image(handle: QClipboardH; retval: QImageH); cdecl;
procedure QClipboard_pixmap(handle: QClipboardH; retval: QPixmapH); cdecl;
procedure QClipboard_setImage(handle: QClipboardH; p1: QImageH); cdecl;
procedure QClipboard_setPixmap(handle: QClipboardH; p1: QPixmapH); cdecl;

procedure QColorDialog_getColor(retval: QColorH; p1: QColorH; parent: QWidgetH; name: PAnsiChar); cdecl;
procedure QColorDialog_getRgba(retval: QRgbH; p1: QRgbH; ok: PBoolean; parent: QWidgetH; name: PAnsiChar); cdecl;
function QColorDialog_customCount(): Integer; cdecl;
procedure QColorDialog_customColor(retval: QRgbH; p1: Integer); cdecl;
procedure QColorDialog_setCustomColor(p1: Integer; p2: QRgbH); cdecl;

procedure QCommonStyle_drawComboButton(handle: QCommonStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; editable: Boolean; enabled: Boolean; fill: QBrushH); cdecl;
procedure QCommonStyle_comboButtonRect(handle: QCommonStyleH; retval: PRect; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QCommonStyle_comboButtonFocusRect(handle: QCommonStyleH; retval: PRect; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QCommonStyle_drawComboButtonMask(handle: QCommonStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QCommonStyle_drawPushButtonLabel(handle: QCommonStyleH; btn: QPushButtonH; p: QPainterH); cdecl;
procedure QCommonStyle_getButtonShift(handle: QCommonStyleH; x: PInteger; y: PInteger); cdecl;
function QCommonStyle_defaultFrameWidth(handle: QCommonStyleH): Integer; cdecl;
procedure QCommonStyle_tabbarMetrics(handle: QCommonStyleH; p1: QTabBarH; p2: PInteger; p3: PInteger; p4: PInteger); cdecl;
procedure QCommonStyle_drawTab(handle: QCommonStyleH; p1: QPainterH; p2: QTabBarH; p3: QTabH; selected: Boolean); cdecl;
procedure QCommonStyle_drawTabMask(handle: QCommonStyleH; p1: QPainterH; p2: QTabBarH; p3: QTabH; selected: Boolean); cdecl;
function QCommonStyle_scrollBarPointOver(handle: QCommonStyleH; sb: QScrollBarH; sliderStart: Integer; p: PPoint): QStyleScrollControl; cdecl;
procedure QCommonStyle_drawSliderMask(handle: QCommonStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: Orientation; tickAbove: Boolean; tickBelow: Boolean); cdecl;
procedure QCommonStyle_drawSliderGrooveMask(handle: QCommonStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; c: QCOORD; p7: Orientation); cdecl;
function QCommonStyle_maximumSliderDragDistance(handle: QCommonStyleH): Integer; cdecl;
function QCommonStyle_popupSubmenuIndicatorWidth(handle: QCommonStyleH; fm: QFontMetricsH): Integer; cdecl;
procedure QCommonStyle_drawMenuBarItem(handle: QCommonStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; mi: QMenuItemH; g: QColorGroupH; enabled: Boolean; active: Boolean); cdecl;

procedure QFontDialog_getFont(retval: QFontH; ok: PBoolean; def: QFontH; parent: QWidgetH; name: PAnsiChar); overload; cdecl;
procedure QFontDialog_getFont(retval: QFontH; ok: PBoolean; parent: QWidgetH; name: PAnsiChar); overload; cdecl;

function QGroupBox_create(parent: QWidgetH; name: PAnsiChar): QGroupBoxH; overload; cdecl;
procedure QGroupBox_destroy(handle: QGroupBoxH); cdecl;
function QGroupBox_create(title: PWideString; parent: QWidgetH; name: PAnsiChar): QGroupBoxH; overload; cdecl;
function QGroupBox_create(columns: Integer; o: Orientation; parent: QWidgetH; name: PAnsiChar): QGroupBoxH; overload; cdecl;
function QGroupBox_create(columns: Integer; o: Orientation; title: PWideString; parent: QWidgetH; name: PAnsiChar): QGroupBoxH; overload; cdecl;
procedure QGroupBox_setColumnLayout(handle: QGroupBoxH; columns: Integer; o: Orientation); cdecl;
procedure QGroupBox_title(handle: QGroupBoxH; retval: PWideString); cdecl;
procedure QGroupBox_setTitle(handle: QGroupBoxH; p1: PWideString); cdecl;
function QGroupBox_alignment(handle: QGroupBoxH): Integer; cdecl;
procedure QGroupBox_setAlignment(handle: QGroupBoxH; p1: Integer); cdecl;
function QGroupBox_columns(handle: QGroupBoxH): Integer; cdecl;
procedure QGroupBox_setColumns(handle: QGroupBoxH; p1: Integer); cdecl;
function QGroupBox_orientation(handle: QGroupBoxH): Orientation; cdecl;
procedure QGroupBox_setOrientation(handle: QGroupBoxH; p1: Orientation); cdecl;
procedure QGroupBox_addSpace(handle: QGroupBoxH; p1: Integer); cdecl;
procedure QGroupBox_sizeHint(handle: QGroupBoxH; retval: PSize); cdecl;

function QHeader_create(parent: QWidgetH; name: PAnsiChar): QHeaderH; overload; cdecl;
procedure QHeader_destroy(handle: QHeaderH); cdecl;
function QHeader_create(p1: Integer; parent: QWidgetH; name: PAnsiChar): QHeaderH; overload; cdecl;
function QHeader_addLabel(handle: QHeaderH; p1: PWideString; size: Integer): Integer; overload; cdecl;
function QHeader_addLabel(handle: QHeaderH; p1: QIconSetH; p2: PWideString; size: Integer): Integer; overload; cdecl;
procedure QHeader_removeLabel(handle: QHeaderH; section: Integer); cdecl;
procedure QHeader_setLabel(handle: QHeaderH; p1: Integer; p2: PWideString; size: Integer); overload; cdecl;
procedure QHeader_setLabel(handle: QHeaderH; p1: Integer; p2: QIconSetH; p3: PWideString; size: Integer); overload; cdecl;
procedure QHeader_label(handle: QHeaderH; retval: PWideString; section: Integer); cdecl;
function QHeader_iconSet(handle: QHeaderH; section: Integer): QIconSetH; cdecl;
procedure QHeader_setOrientation(handle: QHeaderH; p1: Orientation); cdecl;
function QHeader_orientation(handle: QHeaderH): Orientation; cdecl;
procedure QHeader_setTracking(handle: QHeaderH; enable: Boolean); cdecl;
function QHeader_tracking(handle: QHeaderH): Boolean; cdecl;
procedure QHeader_setClickEnabled(handle: QHeaderH; p1: Boolean; section: Integer); cdecl;
procedure QHeader_setResizeEnabled(handle: QHeaderH; p1: Boolean; section: Integer); cdecl;
procedure QHeader_setMovingEnabled(handle: QHeaderH; p1: Boolean); cdecl;
function QHeader_isClickEnabled(handle: QHeaderH; section: Integer): Boolean; cdecl;
function QHeader_isResizeEnabled(handle: QHeaderH; section: Integer): Boolean; cdecl;
function QHeader_isMovingEnabled(handle: QHeaderH): Boolean; cdecl;
procedure QHeader_resizeSection(handle: QHeaderH; section: Integer; s: Integer); cdecl;
function QHeader_sectionSize(handle: QHeaderH; section: Integer): Integer; cdecl;
function QHeader_sectionPos(handle: QHeaderH; section: Integer): Integer; cdecl;
function QHeader_sectionAt(handle: QHeaderH; pos: Integer): Integer; cdecl;
function QHeader_count(handle: QHeaderH): Integer; cdecl;
procedure QHeader_setCellSize(handle: QHeaderH; p1: Integer; p2: Integer); cdecl;
function QHeader_cellSize(handle: QHeaderH; p1: Integer): Integer; cdecl;
function QHeader_cellPos(handle: QHeaderH; p1: Integer): Integer; cdecl;
function QHeader_cellAt(handle: QHeaderH; p1: Integer): Integer; cdecl;
function QHeader_offset(handle: QHeaderH): Integer; cdecl;
procedure QHeader_sizeHint(handle: QHeaderH; retval: PSize); cdecl;
procedure QHeader_sizePolicy(handle: QHeaderH; retval: PSizePolicy); cdecl;
function QHeader_mapToSection(handle: QHeaderH; index: Integer): Integer; cdecl;
function QHeader_mapToIndex(handle: QHeaderH; section: Integer): Integer; cdecl;
function QHeader_mapToLogical(handle: QHeaderH; p1: Integer): Integer; cdecl;
function QHeader_mapToActual(handle: QHeaderH; p1: Integer): Integer; cdecl;
procedure QHeader_moveSection(handle: QHeaderH; section: Integer; toIndex: Integer); cdecl;
procedure QHeader_moveCell(handle: QHeaderH; p1: Integer; p2: Integer); cdecl;
procedure QHeader_setSortIndicator(handle: QHeaderH; section: Integer; increasing: Boolean); cdecl;
procedure QHeader_setUpdatesEnabled(handle: QHeaderH; enable: Boolean); cdecl;
procedure QHeader_setOffset(handle: QHeaderH; pos: Integer); cdecl;

function QLabel_create(parent: QWidgetH; name: PAnsiChar; f: WFlags): QLabelH; overload; cdecl;
procedure QLabel_destroy(handle: QLabelH); cdecl;
function QLabel_create(text: PWideString; parent: QWidgetH; name: PAnsiChar; f: WFlags): QLabelH; overload; cdecl;
function QLabel_create(buddy: QWidgetH; p2: PWideString; parent: QWidgetH; name: PAnsiChar; f: WFlags): QLabelH; overload; cdecl;
procedure QLabel_text(handle: QLabelH; retval: PWideString); cdecl;
function QLabel_pixmap(handle: QLabelH): QPixmapH; cdecl;
function QLabel_movie(handle: QLabelH): QMovieH; cdecl;
function QLabel_textFormat(handle: QLabelH): TextFormat; cdecl;
procedure QLabel_setTextFormat(handle: QLabelH; p1: TextFormat); cdecl;
function QLabel_alignment(handle: QLabelH): Integer; cdecl;
procedure QLabel_setAlignment(handle: QLabelH; p1: Integer); cdecl;
function QLabel_indent(handle: QLabelH): Integer; cdecl;
procedure QLabel_setIndent(handle: QLabelH; p1: Integer); cdecl;
function QLabel_autoResize(handle: QLabelH): Boolean; cdecl;
procedure QLabel_setAutoResize(handle: QLabelH; p1: Boolean); cdecl;
function QLabel_hasScaledContents(handle: QLabelH): Boolean; cdecl;
procedure QLabel_setScaledContents(handle: QLabelH; p1: Boolean); cdecl;
procedure QLabel_sizeHint(handle: QLabelH; retval: PSize); cdecl;
procedure QLabel_minimumSizeHint(handle: QLabelH; retval: PSize); cdecl;
procedure QLabel_sizePolicy(handle: QLabelH; retval: PSizePolicy); cdecl;
procedure QLabel_setBuddy(handle: QLabelH; p1: QWidgetH); cdecl;
function QLabel_buddy(handle: QLabelH): QWidgetH; cdecl;
procedure QLabel_setAutoMask(handle: QLabelH; p1: Boolean); cdecl;
function QLabel_heightForWidth(handle: QLabelH; p1: Integer): Integer; cdecl;
procedure QLabel_setText(handle: QLabelH; p1: PWideString); cdecl;
procedure QLabel_setPixmap(handle: QLabelH; p1: QPixmapH); cdecl;
procedure QLabel_setMovie(handle: QLabelH; p1: QMovieH); cdecl;
procedure QLabel_setNum(handle: QLabelH; p1: Integer); overload; cdecl;
procedure QLabel_setNum(handle: QLabelH; p1: Double); overload; cdecl;
procedure QLabel_clear(handle: QLabelH); cdecl;

function QPainter_create(): QPainterH; overload; cdecl;
procedure QPainter_destroy(handle: QPainterH); cdecl;
function QPainter_create(p1: QPaintDeviceH): QPainterH; overload; cdecl;
function QPainter_create(p1: QPaintDeviceH; p2: QWidgetH): QPainterH; overload; cdecl;
function QPainter_begin(handle: QPainterH; p1: QPaintDeviceH): Boolean; overload; cdecl;
function QPainter_begin(handle: QPainterH; p1: QPaintDeviceH; p2: QWidgetH): Boolean; overload; cdecl;
function QPainter_end(handle: QPainterH): Boolean; cdecl;
function QPainter_device(handle: QPainterH): QPaintDeviceH; cdecl;

procedure QPainter_redirect(pdev: QPaintDeviceH; replacement: QPaintDeviceH); cdecl;
function QPainter_isActive(handle: QPainterH): Boolean; cdecl;
procedure QPainter_flush(handle: QPainterH); cdecl;
procedure QPainter_save(handle: QPainterH); cdecl;
procedure QPainter_restore(handle: QPainterH); cdecl;
procedure QPainter_fontMetrics(handle: QPainterH; retval: QFontMetricsH); cdecl;
procedure QPainter_fontInfo(handle: QPainterH; retval: QFontInfoH); cdecl;
function QPainter_font(handle: QPainterH): QFontH; cdecl;
procedure QPainter_setFont(handle: QPainterH; p1: QFontH); cdecl;
function QPainter_pen(handle: QPainterH): QPenH; cdecl;
procedure QPainter_setPen(handle: QPainterH; p1: QPenH); overload; cdecl;
procedure QPainter_setPen(handle: QPainterH; p1: PenStyle); overload; cdecl;
procedure QPainter_setPen(handle: QPainterH; p1: QColorH); overload; cdecl;
function QPainter_brush(handle: QPainterH): QBrushH; cdecl;
procedure QPainter_setBrush(handle: QPainterH; p1: QBrushH); overload; cdecl;
procedure QPainter_setBrush(handle: QPainterH; p1: BrushStyle); overload; cdecl;
procedure QPainter_setBrush(handle: QPainterH; p1: QColorH); overload; cdecl;
procedure QPainter_pos(handle: QPainterH; retval: PPoint); cdecl;
function QPainter_backgroundColor(handle: QPainterH): QColorH; cdecl;
procedure QPainter_setBackgroundColor(handle: QPainterH; p1: QColorH); cdecl;
function QPainter_backgroundMode(handle: QPainterH): BGMode; cdecl;
procedure QPainter_setBackgroundMode(handle: QPainterH; p1: BGMode); cdecl;
function QPainter_rasterOp(handle: QPainterH): RasterOp; cdecl;
procedure QPainter_setRasterOp(handle: QPainterH; p1: RasterOp); cdecl;
function QPainter_brushOrigin(handle: QPainterH): PPoint; cdecl;
procedure QPainter_setBrushOrigin(handle: QPainterH; x: Integer; y: Integer); overload; cdecl;
procedure QPainter_setBrushOrigin(handle: QPainterH; p1: PPoint); overload; cdecl;
function QPainter_hasViewXForm(handle: QPainterH): Boolean; cdecl;
function QPainter_hasWorldXForm(handle: QPainterH): Boolean; cdecl;
procedure QPainter_setViewXForm(handle: QPainterH; p1: Boolean); cdecl;
procedure QPainter_window(handle: QPainterH; retval: PRect); cdecl;
procedure QPainter_setWindow(handle: QPainterH; p1: PRect); overload; cdecl;
procedure QPainter_setWindow(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QPainter_viewport(handle: QPainterH; retval: PRect); cdecl;
procedure QPainter_setViewport(handle: QPainterH; p1: PRect); overload; cdecl;
procedure QPainter_setViewport(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QPainter_setWorldXForm(handle: QPainterH; p1: Boolean); cdecl;
function QPainter_worldMatrix(handle: QPainterH): QWMatrixH; cdecl;
procedure QPainter_setWorldMatrix(handle: QPainterH; p1: QWMatrixH; combine: Boolean); cdecl;
procedure QPainter_saveWorldMatrix(handle: QPainterH); cdecl;
procedure QPainter_restoreWorldMatrix(handle: QPainterH); cdecl;
procedure QPainter_scale(handle: QPainterH; sx: Double; sy: Double); cdecl;
procedure QPainter_shear(handle: QPainterH; sh: Double; sv: Double); cdecl;
procedure QPainter_rotate(handle: QPainterH; a: Double); cdecl;
procedure QPainter_translate(handle: QPainterH; dx: Double; dy: Double); cdecl;
procedure QPainter_resetXForm(handle: QPainterH); cdecl;
procedure QPainter_xForm(handle: QPainterH; retval: PPoint; p1: PPoint); overload; cdecl;
procedure QPainter_xForm(handle: QPainterH; retval: PRect; p1: PRect); overload; cdecl;
procedure QPainter_xForm(handle: QPainterH; retval: PPointArray; p1: PPointArray); overload; cdecl;
procedure QPainter_xForm(handle: QPainterH; retval: PPointArray; p1: PPointArray; index: Integer; npoints: Integer); overload; cdecl;
procedure QPainter_xFormDev(handle: QPainterH; retval: PPoint; p1: PPoint); overload; cdecl;
procedure QPainter_xFormDev(handle: QPainterH; retval: PRect; p1: PRect); overload; cdecl;
procedure QPainter_xFormDev(handle: QPainterH; retval: PPointArray; p1: PPointArray); overload; cdecl;
procedure QPainter_xFormDev(handle: QPainterH; retval: PPointArray; p1: PPointArray; index: Integer; npoints: Integer); overload; cdecl;
procedure QPainter_setClipping(handle: QPainterH; p1: Boolean); cdecl;
function QPainter_hasClipping(handle: QPainterH): Boolean; cdecl;
function QPainter_clipRegion(handle: QPainterH): QRegionH; cdecl;
procedure QPainter_setClipRect(handle: QPainterH; p1: PRect); overload; cdecl;
procedure QPainter_setClipRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QPainter_setClipRegion(handle: QPainterH; p1: QRegionH); cdecl;
procedure QPainter_drawPoint(handle: QPainterH; x: Integer; y: Integer); overload; cdecl;
procedure QPainter_drawPoint(handle: QPainterH; p1: PPoint); overload; cdecl;
procedure QPainter_drawPoints(handle: QPainterH; a: PPointArray; index: Integer; npoints: Integer); cdecl;
procedure QPainter_moveTo(handle: QPainterH; x: Integer; y: Integer); overload; cdecl;
procedure QPainter_moveTo(handle: QPainterH; p1: PPoint); overload; cdecl;
procedure QPainter_lineTo(handle: QPainterH; x: Integer; y: Integer); overload; cdecl;
procedure QPainter_lineTo(handle: QPainterH; p1: PPoint); overload; cdecl;
procedure QPainter_drawLine(handle: QPainterH; x1: Integer; y1: Integer; x2: Integer; y2: Integer); overload; cdecl;
procedure QPainter_drawLine(handle: QPainterH; p1: PPoint; p2: PPoint); overload; cdecl;
procedure QPainter_drawRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QPainter_drawRect(handle: QPainterH; p1: PRect); overload; cdecl;
procedure QPainter_drawWinFocusRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QPainter_drawWinFocusRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; bgColor: QColorH); overload; cdecl;
procedure QPainter_drawWinFocusRect(handle: QPainterH; p1: PRect); overload; cdecl;
procedure QPainter_drawWinFocusRect(handle: QPainterH; p1: PRect; bgColor: QColorH); overload; cdecl;
procedure QPainter_drawRoundRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p5: Integer; p6: Integer); overload; cdecl;
procedure QPainter_drawRoundRect(handle: QPainterH; p1: PRect; p2: Integer; p3: Integer); overload; cdecl;
procedure QPainter_drawRoundRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QPainter_drawRoundRect(handle: QPainterH; p1: PRect); overload; cdecl;
procedure QPainter_drawEllipse(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QPainter_drawEllipse(handle: QPainterH; p1: PRect); overload; cdecl;
procedure QPainter_drawArc(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; a: Integer; alen: Integer); overload; cdecl;
procedure QPainter_drawArc(handle: QPainterH; p1: PRect; a: Integer; alen: Integer); overload; cdecl;
procedure QPainter_drawPie(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; a: Integer; alen: Integer); overload; cdecl;
procedure QPainter_drawPie(handle: QPainterH; p1: PRect; a: Integer; alen: Integer); overload; cdecl;
procedure QPainter_drawChord(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; a: Integer; alen: Integer); overload; cdecl;
procedure QPainter_drawChord(handle: QPainterH; p1: PRect; a: Integer; alen: Integer); overload; cdecl;
procedure QPainter_drawLineSegments(handle: QPainterH; p1: PPointArray; index: Integer; nlines: Integer); cdecl;
procedure QPainter_drawPolyline(handle: QPainterH; p1: PPointArray; index: Integer; npoints: Integer); cdecl;
procedure QPainter_drawPolygon(handle: QPainterH; p1: PPointArray; winding: Boolean; index: Integer; npoints: Integer); cdecl;
procedure QPainter_drawQuadBezier(handle: QPainterH; p1: PPointArray; index: Integer); cdecl;
procedure QPainter_drawPixmap(handle: QPainterH; x: Integer; y: Integer; p3: QPixmapH; sx: Integer; sy: Integer; sw: Integer; sh: Integer); overload; cdecl;
procedure QPainter_drawPixmap(handle: QPainterH; p1: PPoint; p2: QPixmapH; sr: PRect); overload; cdecl;
procedure QPainter_drawPixmap(handle: QPainterH; p1: PPoint; p2: QPixmapH); overload; cdecl;
procedure QPainter_drawImage(handle: QPainterH; x: Integer; y: Integer; p3: QImageH; sx: Integer; sy: Integer; sw: Integer; sh: Integer); overload; cdecl;
procedure QPainter_drawImage(handle: QPainterH; p1: PPoint; p2: QImageH; sr: PRect); overload; cdecl;
procedure QPainter_drawImage(handle: QPainterH; p1: PPoint; p2: QImageH); overload; cdecl;
procedure QPainter_drawImage(handle: QPainterH; x: Integer; y: Integer; p3: QImageH; sx: Integer; sy: Integer; sw: Integer; sh: Integer; conversion_flags: Integer); overload; cdecl;
procedure QPainter_drawImage(handle: QPainterH; p1: PPoint; p2: QImageH; sr: PRect; conversion_flags: Integer); overload; cdecl;
procedure QPainter_drawImage(handle: QPainterH; p1: PPoint; p2: QImageH; conversion_flags: Integer); overload; cdecl;
procedure QPainter_drawTiledPixmap(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p5: QPixmapH; sx: Integer; sy: Integer); overload; cdecl;
procedure QPainter_drawTiledPixmap(handle: QPainterH; p1: PRect; p2: QPixmapH; p3: PPoint); overload; cdecl;
procedure QPainter_drawTiledPixmap(handle: QPainterH; p1: PRect; p2: QPixmapH); overload; cdecl;
procedure QPainter_drawPicture(handle: QPainterH; p1: QPictureH); cdecl;
procedure QPainter_fillRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p5: QBrushH); overload; cdecl;
procedure QPainter_fillRect(handle: QPainterH; p1: PRect; p2: QBrushH); overload; cdecl;
procedure QPainter_eraseRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QPainter_eraseRect(handle: QPainterH; p1: PRect); overload; cdecl;
procedure QPainter_drawText(handle: QPainterH; x: Integer; y: Integer; p3: PWideString; len: Integer); overload; cdecl;
procedure QPainter_drawText(handle: QPainterH; p1: PPoint; p2: PWideString; len: Integer); overload; cdecl;
procedure QPainter_drawText(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; flags: Integer; p6: PWideString; len: Integer; br: PRect; internal: PPAnsiChar); overload; cdecl;
procedure QPainter_drawText(handle: QPainterH; p1: PRect; flags: Integer; p3: PWideString; len: Integer; br: PRect; internal: PPAnsiChar); overload; cdecl;
procedure QPainter_boundingRect(handle: QPainterH; retval: PRect; x: Integer; y: Integer; w: Integer; h: Integer; flags: Integer; p6: PWideString; len: Integer; intern: PPAnsiChar); overload; cdecl;
procedure QPainter_boundingRect(handle: QPainterH; retval: PRect; p1: PRect; flags: Integer; p3: PWideString; len: Integer; intern: PPAnsiChar); overload; cdecl;
function QPainter_tabStops(handle: QPainterH): Integer; cdecl;
procedure QPainter_setTabStops(handle: QPainterH; p1: Integer); cdecl;
function QPainter_tabArray(handle: QPainterH): PInteger; cdecl;
procedure QPainter_setTabArray(handle: QPainterH; p1: PInteger); cdecl;
function QPainter_handle(handle: QPainterH): HDC; overload; cdecl;

procedure QPainter_initialize(); cdecl;
procedure QPainter_cleanup(); cdecl;

function QPen_create(): QPenH; overload; cdecl;
procedure QPen_destroy(handle: QPenH); cdecl;
function QPen_create(p1: PenStyle): QPenH; overload; cdecl;
function QPen_create(color: QColorH; width: Cardinal; style: PenStyle): QPenH; overload; cdecl;
function QPen_create(cl: QColorH; w: Cardinal; s: PenStyle; c: PenCapStyle; j: PenJoinStyle): QPenH; overload; cdecl;
function QPen_create(p1: QPenH): QPenH; overload; cdecl;
function QPen_style(handle: QPenH): PenStyle; cdecl;
procedure QPen_setStyle(handle: QPenH; p1: PenStyle); cdecl;
function QPen_width(handle: QPenH): Cardinal; cdecl;
procedure QPen_setWidth(handle: QPenH; p1: Cardinal); cdecl;
function QPen_color(handle: QPenH): QColorH; cdecl;
procedure QPen_setColor(handle: QPenH; p1: QColorH); cdecl;
function QPen_capStyle(handle: QPenH): PenCapStyle; cdecl;
procedure QPen_setCapStyle(handle: QPenH; p1: PenCapStyle); cdecl;
function QPen_joinStyle(handle: QPenH): PenJoinStyle; cdecl;
procedure QPen_setJoinStyle(handle: QPenH; p1: PenJoinStyle); cdecl;

function QPopupMenu_create(parent: QWidgetH; name: PAnsiChar): QPopupMenuH; cdecl;
procedure QPopupMenu_destroy(handle: QPopupMenuH); cdecl;
procedure QPopupMenu_popup(handle: QPopupMenuH; pos: PPoint; indexAtPoint: Integer); cdecl;
procedure QPopupMenu_updateItem(handle: QPopupMenuH; id: Integer); cdecl;
procedure QPopupMenu_setCheckable(handle: QPopupMenuH; p1: Boolean); cdecl;
function QPopupMenu_isCheckable(handle: QPopupMenuH): Boolean; cdecl;
procedure QPopupMenu_setFont(handle: QPopupMenuH; p1: QFontH); cdecl;
procedure QPopupMenu_show(handle: QPopupMenuH); cdecl;
procedure QPopupMenu_hide(handle: QPopupMenuH); cdecl;
function QPopupMenu_exec(handle: QPopupMenuH): Integer; overload; cdecl;
function QPopupMenu_exec(handle: QPopupMenuH; pos: PPoint; indexAtPoint: Integer): Integer; overload; cdecl;
procedure QPopupMenu_setActiveItem(handle: QPopupMenuH; p1: Integer); cdecl;
procedure QPopupMenu_sizeHint(handle: QPopupMenuH; retval: PSize); cdecl;
function QPopupMenu_idAt(handle: QPopupMenuH; index: Integer): Integer; overload; cdecl;
function QPopupMenu_idAt(handle: QPopupMenuH; pos: PPoint): Integer; overload; cdecl;
function QPopupMenu_customWhatsThis(handle: QPopupMenuH): Boolean; cdecl;
function QPopupMenu_insertTearOffHandle(handle: QPopupMenuH; id: Integer; index: Integer): Integer; cdecl;
procedure QPopupMenu_activateItemAt(handle: QPopupMenuH; index: Integer); cdecl;
function QPopupMenu_to_QMenuData(handle: QPopupMenuH): QMenuDataH; cdecl;
function QPushButton_create(parent: QWidgetH; name: PAnsiChar): QPushButtonH; overload; cdecl;
procedure QPushButton_destroy(handle: QPushButtonH); cdecl;
function QPushButton_create(text: PWideString; parent: QWidgetH; name: PAnsiChar): QPushButtonH; overload; cdecl;
function QPushButton_create(icon: QIconSetH; text: PWideString; parent: QWidgetH; name: PAnsiChar): QPushButtonH; overload; cdecl;
procedure QPushButton_sizeHint(handle: QPushButtonH; retval: PSize); cdecl;
procedure QPushButton_sizePolicy(handle: QPushButtonH; retval: PSizePolicy); cdecl;
procedure QPushButton_move(handle: QPushButtonH; x: Integer; y: Integer); overload; cdecl;
procedure QPushButton_move(handle: QPushButtonH; p: PPoint); overload; cdecl;
procedure QPushButton_resize(handle: QPushButtonH; w: Integer; h: Integer); overload; cdecl;
procedure QPushButton_resize(handle: QPushButtonH; p1: PSize); overload; cdecl;
procedure QPushButton_setGeometry(handle: QPushButtonH; x: Integer; y: Integer; w: Integer; h: Integer); overload; cdecl;
procedure QPushButton_setGeometry(handle: QPushButtonH; p1: PRect); overload; cdecl;
procedure QPushButton_setToggleButton(handle: QPushButtonH; p1: Boolean); cdecl;
function QPushButton_autoDefault(handle: QPushButtonH): Boolean; cdecl;
procedure QPushButton_setAutoDefault(handle: QPushButtonH; autoDef: Boolean); cdecl;
function QPushButton_isDefault(handle: QPushButtonH): Boolean; cdecl;
procedure QPushButton_setDefault(handle: QPushButtonH; def: Boolean); cdecl;
procedure QPushButton_setIsMenuButton(handle: QPushButtonH; p1: Boolean); cdecl;
function QPushButton_isMenuButton(handle: QPushButtonH): Boolean; cdecl;
procedure QPushButton_setPopup(handle: QPushButtonH; popup: QPopupMenuH); cdecl;
function QPushButton_popup(handle: QPushButtonH): QPopupMenuH; cdecl;
procedure QPushButton_setIconSet(handle: QPushButtonH; p1: QIconSetH); cdecl;
function QPushButton_iconSet(handle: QPushButtonH): QIconSetH; cdecl;
procedure QPushButton_setFlat(handle: QPushButtonH; p1: Boolean); cdecl;
function QPushButton_isFlat(handle: QPushButtonH): Boolean; cdecl;
procedure QPushButton_setOn(handle: QPushButtonH; p1: Boolean); cdecl;
procedure QPushButton_toggle(handle: QPushButtonH); cdecl;

function QRadioButton_create(parent: QWidgetH; name: PAnsiChar): QRadioButtonH; overload; cdecl;
procedure QRadioButton_destroy(handle: QRadioButtonH); cdecl;
function QRadioButton_create(text: PWideString; parent: QWidgetH; name: PAnsiChar): QRadioButtonH; overload; cdecl;
function QRadioButton_isChecked(handle: QRadioButtonH): Boolean; cdecl;
procedure QRadioButton_setChecked(handle: QRadioButtonH; check: Boolean); cdecl;
procedure QRadioButton_sizeHint(handle: QRadioButtonH; retval: PSize); cdecl;
procedure QRadioButton_sizePolicy(handle: QRadioButtonH; retval: PSizePolicy); cdecl;

function QScrollBar_create(parent: QWidgetH; name: PAnsiChar): QScrollBarH; overload; cdecl;
procedure QScrollBar_destroy(handle: QScrollBarH); cdecl;
function QScrollBar_create(p1: Orientation; parent: QWidgetH; name: PAnsiChar): QScrollBarH; overload; cdecl;
function QScrollBar_create(minValue: Integer; maxValue: Integer; LineStep: Integer; PageStep: Integer; value: Integer; p6: Orientation; parent: QWidgetH; name: PAnsiChar): QScrollBarH; overload; cdecl;
procedure QScrollBar_setOrientation(handle: QScrollBarH; p1: Orientation); cdecl;
function QScrollBar_orientation(handle: QScrollBarH): Orientation; cdecl;
procedure QScrollBar_setTracking(handle: QScrollBarH; enable: Boolean); cdecl;
function QScrollBar_tracking(handle: QScrollBarH): Boolean; cdecl;
function QScrollBar_draggingSlider(handle: QScrollBarH): Boolean; cdecl;
procedure QScrollBar_setPalette(handle: QScrollBarH; p1: QPaletteH); cdecl;
procedure QScrollBar_sizeHint(handle: QScrollBarH; retval: PSize); cdecl;
procedure QScrollBar_sizePolicy(handle: QScrollBarH; retval: PSizePolicy); cdecl;
function QScrollBar_minValue(handle: QScrollBarH): Integer; cdecl;
function QScrollBar_maxValue(handle: QScrollBarH): Integer; cdecl;
procedure QScrollBar_setMinValue(handle: QScrollBarH; p1: Integer); cdecl;
procedure QScrollBar_setMaxValue(handle: QScrollBarH; p1: Integer); cdecl;
function QScrollBar_lineStep(handle: QScrollBarH): Integer; cdecl;
function QScrollBar_pageStep(handle: QScrollBarH): Integer; cdecl;
procedure QScrollBar_setLineStep(handle: QScrollBarH; p1: Integer); cdecl;
procedure QScrollBar_setPageStep(handle: QScrollBarH; p1: Integer); cdecl;
function QScrollBar_value(handle: QScrollBarH): Integer; cdecl;
procedure QScrollBar_setValue(handle: QScrollBarH; p1: Integer); cdecl;
function QScrollBar_to_QRangeControl(handle: QScrollBarH): QRangeControlH; cdecl;
function QSizeGrip_create(parent: QWidgetH; name: PAnsiChar): QSizeGripH; cdecl;
procedure QSizeGrip_destroy(handle: QSizeGripH); cdecl;
procedure QSizeGrip_sizeHint(handle: QSizeGripH; retval: PSize); cdecl;
procedure QSizeGrip_sizePolicy(handle: QSizeGripH; retval: PSizePolicy); cdecl;

procedure QTableView_setBackgroundColor(handle: QTableViewH; p1: QColorH); cdecl;
procedure QTableView_setPalette(handle: QTableViewH; p1: QPaletteH); cdecl;
procedure QTableView_show(handle: QTableViewH); cdecl;
procedure QTableView_repaint(handle: QTableViewH; erase: Boolean); overload; cdecl;
procedure QTableView_repaint(handle: QTableViewH; x: Integer; y: Integer; w: Integer; h: Integer; erase: Boolean); overload; cdecl;
procedure QTableView_repaint(handle: QTableViewH; p1: PRect; erase: Boolean); overload; cdecl;

function QTextBrowser_create(parent: QWidgetH; name: PAnsiChar): QTextBrowserH; cdecl;
procedure QTextBrowser_destroy(handle: QTextBrowserH); cdecl;
procedure QTextBrowser_setSource(handle: QTextBrowserH; name: PWideString); cdecl;
procedure QTextBrowser_source(handle: QTextBrowserH; retval: PWideString); cdecl;
procedure QTextBrowser_setText(handle: QTextBrowserH; contents: PWideString; context: PWideString); cdecl;
procedure QTextBrowser_scrollToAnchor(handle: QTextBrowserH; name: PWideString); cdecl;
procedure QTextBrowser_backward(handle: QTextBrowserH); cdecl;
procedure QTextBrowser_forward(handle: QTextBrowserH); cdecl;
procedure QTextBrowser_home(handle: QTextBrowserH); cdecl;

function QTextView_create(parent: QWidgetH; name: PAnsiChar): QTextViewH; overload; cdecl;
procedure QTextView_destroy(handle: QTextViewH); cdecl;
function QTextView_create(text: PWideString; context: PWideString; parent: QWidgetH; name: PAnsiChar): QTextViewH; overload; cdecl;
procedure QTextView_setText(handle: QTextViewH; text: PWideString; context: PWideString); overload; cdecl;
procedure QTextView_setText(handle: QTextViewH; text: PWideString); overload; cdecl;
procedure QTextView_text(handle: QTextViewH; retval: PWideString); cdecl;
procedure QTextView_context(handle: QTextViewH; retval: PWideString); cdecl;
function QTextView_textFormat(handle: QTextViewH): TextFormat; cdecl;
procedure QTextView_setTextFormat(handle: QTextViewH; p1: TextFormat); cdecl;
function QTextView_styleSheet(handle: QTextViewH): QStyleSheetH; cdecl;
procedure QTextView_setStyleSheet(handle: QTextViewH; styleSheet: QStyleSheetH); cdecl;
procedure QTextView_setPaper(handle: QTextViewH; pap: QBrushH); cdecl;
function QTextView_paper(handle: QTextViewH): QBrushH; overload; cdecl;
procedure QTextView_setPaperColorGroup(handle: QTextViewH; colgrp: QColorGroupH); cdecl;
function QTextView_paperColorGroup(handle: QTextViewH): QColorGroupH; cdecl;
procedure QTextView_setLinkColor(handle: QTextViewH; p1: QColorH); cdecl;
function QTextView_linkColor(handle: QTextViewH): QColorH; cdecl;
procedure QTextView_setLinkUnderline(handle: QTextViewH; p1: Boolean); cdecl;
function QTextView_linkUnderline(handle: QTextViewH): Boolean; cdecl;
procedure QTextView_setMimeSourceFactory(handle: QTextViewH; factory: QMimeSourceFactoryH); cdecl;
function QTextView_mimeSourceFactory(handle: QTextViewH): QMimeSourceFactoryH; cdecl;
procedure QTextView_documentTitle(handle: QTextViewH; retval: PWideString); cdecl;
function QTextView_heightForWidth(handle: QTextViewH; w: Integer): Integer; cdecl;
procedure QTextView_append(handle: QTextViewH; text: PWideString); cdecl;
function QTextView_hasSelectedText(handle: QTextViewH): Boolean; cdecl;
procedure QTextView_selectedText(handle: QTextViewH; retval: PWideString); cdecl;
procedure QTextView_copy(handle: QTextViewH); cdecl;
procedure QTextView_selectAll(handle: QTextViewH); cdecl;

function QWhatsThis_create(p1: QWidgetH): QWhatsThisH; cdecl;
procedure QWhatsThis_destroy(handle: QWhatsThisH); cdecl;
procedure QWhatsThis_text(handle: QWhatsThisH; retval: PWideString; p1: PPoint); cdecl;
procedure QWhatsThis_add(p1: QWidgetH; p2: PWideString); cdecl;
procedure QWhatsThis_remove(p1: QWidgetH); cdecl;
procedure QWhatsThis_textFor(retval: PWideString; p1: QWidgetH; pos: PPoint); cdecl;
function QWhatsThis_whatsThisButton(parent: QWidgetH): QToolButtonH; cdecl;
procedure QWhatsThis_enterWhatsThisMode(); cdecl;
function QWhatsThis_inWhatsThisMode(): Boolean; cdecl;
procedure QWhatsThis_leaveWhatsThisMode(p1: PWideString; pos: PPoint); cdecl;

function QWindowsStyle_create(): QWindowsStyleH; cdecl;
procedure QWindowsStyle_destroy(handle: QWindowsStyleH); cdecl;
procedure QWindowsStyle_drawButton(handle: QWindowsStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH); cdecl;
procedure QWindowsStyle_drawBevelButton(handle: QWindowsStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH); cdecl;
procedure QWindowsStyle_drawFocusRect(handle: QWindowsStyleH; p1: QPainterH; p2: PRect; p3: QColorGroupH; p4: QColorH; p5: Boolean); cdecl;
procedure QWindowsStyle_drawPushButton(handle: QWindowsStyleH; btn: QPushButtonH; p: QPainterH); cdecl;
procedure QWindowsStyle_getButtonShift(handle: QWindowsStyleH; x: PInteger; y: PInteger); cdecl;
procedure QWindowsStyle_drawPanel(handle: QWindowsStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: QColorGroupH; sunken: Boolean; lineWidth: Integer; fill: QBrushH); cdecl;
procedure QWindowsStyle_drawPopupPanel(handle: QWindowsStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: QColorGroupH; lineWidth: Integer; fill: QBrushH); cdecl;
procedure QWindowsStyle_drawArrow(handle: QWindowsStyleH; p: QPainterH; _type: ArrowType; down: Boolean; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; enabled: Boolean; fill: QBrushH); cdecl;
procedure QWindowsStyle_indicatorSize(handle: QWindowsStyleH; retval: PSize); cdecl;
procedure QWindowsStyle_drawIndicator(handle: QWindowsStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; s: Integer; down: Boolean; enabled: Boolean); cdecl;
procedure QWindowsStyle_exclusiveIndicatorSize(handle: QWindowsStyleH; retval: PSize); cdecl;
procedure QWindowsStyle_drawExclusiveIndicator(handle: QWindowsStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; on: Boolean; down: Boolean; enabled: Boolean); cdecl;
procedure QWindowsStyle_drawExclusiveIndicatorMask(handle: QWindowsStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; on: Boolean); cdecl;
procedure QWindowsStyle_drawComboButton(handle: QWindowsStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; editable: Boolean; enabled: Boolean; fill: QBrushH); cdecl;
procedure QWindowsStyle_comboButtonRect(handle: QWindowsStyleH; retval: PRect; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QWindowsStyle_comboButtonFocusRect(handle: QWindowsStyleH; retval: PRect; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QWindowsStyle_tabbarMetrics(handle: QWindowsStyleH; p1: QTabBarH; p2: PInteger; p3: PInteger; p4: PInteger); cdecl;
procedure QWindowsStyle_drawTab(handle: QWindowsStyleH; p1: QPainterH; p2: QTabBarH; p3: QTabH; selected: Boolean); cdecl;
procedure QWindowsStyle_drawTabMask(handle: QWindowsStyleH; p1: QPainterH; p2: QTabBarH; p3: QTabH; selected: Boolean); cdecl;
procedure QWindowsStyle_scrollBarMetrics(handle: QWindowsStyleH; p1: QScrollBarH; p2: PInteger; p3: PInteger; p4: PInteger; p5: PInteger); cdecl;
procedure QWindowsStyle_drawScrollBarControls(handle: QWindowsStyleH; p1: QPainterH; p2: QScrollBarH; sliderStart: Integer; controls: Cardinal; activeControl: Cardinal); cdecl;
function QWindowsStyle_sliderLength(handle: QWindowsStyleH): Integer; cdecl;
procedure QWindowsStyle_drawSlider(handle: QWindowsStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; p7: Orientation; tickAbove: Boolean; tickBelow: Boolean); cdecl;
procedure QWindowsStyle_drawSliderMask(handle: QWindowsStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p6: Orientation; tickAbove: Boolean; tickBelow: Boolean); cdecl;
procedure QWindowsStyle_drawSliderGroove(handle: QWindowsStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; c: QCOORD; p8: Orientation); cdecl;
function QWindowsStyle_maximumSliderDragDistance(handle: QWindowsStyleH): Integer; cdecl;
function QWindowsStyle_splitterWidth(handle: QWindowsStyleH): Integer; cdecl;
procedure QWindowsStyle_drawSplitter(handle: QWindowsStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; p7: Orientation); cdecl;
procedure QWindowsStyle_drawCheckMark(handle: QWindowsStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; act: Boolean; dis: Boolean); cdecl;
procedure QWindowsStyle_polishPopupMenu(handle: QWindowsStyleH; p1: QPopupMenuH); cdecl;
function QWindowsStyle_extraPopupMenuItemWidth(handle: QWindowsStyleH; checkable: Boolean; maxpmw: Integer; mi: QMenuItemH; fm: QFontMetricsH): Integer; cdecl;
function QWindowsStyle_popupMenuItemHeight(handle: QWindowsStyleH; checkable: Boolean; mi: QMenuItemH; fm: QFontMetricsH): Integer; cdecl;
procedure QWindowsStyle_drawPopupMenuItem(handle: QWindowsStyleH; p: QPainterH; checkable: Boolean; maxpmw: Integer; tab: Integer; mi: QMenuItemH; pal: QPaletteH; act: Boolean; enabled: Boolean; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;

function QTimer_create(parent: QObjectH; name: PAnsiChar): QTimerH; cdecl;
procedure QTimer_destroy(handle: QTimerH); cdecl;
function QTimer_isActive(handle: QTimerH): Boolean; cdecl;
function QTimer_start(handle: QTimerH; msec: Integer; sshot: Boolean): Integer; cdecl;
procedure QTimer_changeInterval(handle: QTimerH; msec: Integer); cdecl;
procedure QTimer_stop(handle: QTimerH); cdecl;
procedure QTimer_singleShot(msec: Integer; receiver: QObjectH; member: PAnsiChar); cdecl;

function QWorkspace_create(parent: QWidgetH; name: PAnsiChar): QWorkspaceH; cdecl;
procedure QWorkspace_destroy(handle: QWorkspaceH); cdecl;
function QWorkspace_activeWindow(handle: QWorkspaceH): QWidgetH; cdecl;

procedure QWorkspace_sizePolicy(handle: QWorkspaceH; retval: PSizePolicy); cdecl;
procedure QWorkspace_sizeHint(handle: QWorkspaceH; retval: PSize); cdecl;
procedure QWorkspace_cascade(handle: QWorkspaceH); cdecl;
procedure QWorkspace_tile(handle: QWorkspaceH); cdecl;

function QBitmap_create(): QBitmapH; overload; cdecl;
procedure QBitmap_destroy(handle: QBitmapH); cdecl;
function QBitmap_create(w: Integer; h: Integer; clear: Boolean; p4: QPixmapOptimization): QBitmapH; overload; cdecl;
function QBitmap_create(p1: PSize; clear: Boolean; p3: QPixmapOptimization): QBitmapH; overload; cdecl;
function QBitmap_create(w: Integer; h: Integer; bits: PByte; isXbitmap: Boolean): QBitmapH; overload; cdecl;
function QBitmap_create(p1: PSize; bits: PByte; isXbitmap: Boolean): QBitmapH; overload; cdecl;
function QBitmap_create(p1: QBitmapH): QBitmapH; overload; cdecl;
function QBitmap_create(fileName: PWideString; format: PAnsiChar): QBitmapH; overload; cdecl;
procedure QBitmap_xForm(handle: QBitmapH; retval: QBitmapH; p1: QWMatrixH); cdecl;

function QCursor_create(): QCursorH; overload; cdecl;
procedure QCursor_destroy(handle: QCursorH); cdecl;
function QCursor_create(shape: Integer): QCursorH; overload; cdecl;
function QCursor_create(bitmap: QBitmapH; mask: QBitmapH; hotX: Integer; hotY: Integer): QCursorH; overload; cdecl;
function QCursor_create(pixmap: QPixmapH; hotX: Integer; hotY: Integer): QCursorH; overload; cdecl;
function QCursor_create(p1: QCursorH): QCursorH; overload; cdecl;
function QCursor_shape(handle: QCursorH): Integer; cdecl;
procedure QCursor_setShape(handle: QCursorH; p1: Integer); cdecl;
function QCursor_bitmap(handle: QCursorH): QBitmapH; cdecl;
function QCursor_mask(handle: QCursorH): QBitmapH; cdecl;
procedure QCursor_hotSpot(handle: QCursorH; retval: PPoint); cdecl;
function QCursor_handle(handle: QCursorH): HCURSOR; overload; cdecl;

procedure QCursor_initialize(); cdecl;
procedure QCursor_cleanup(); cdecl;

procedure QCursor_pos(retval: PPoint); cdecl;
procedure QCursor_setPos(x: Integer; y: Integer); overload; cdecl;
procedure QCursor_setPos(p1: PPoint); overload; cdecl;

function QFontDatabase_create(): QFontDatabaseH; cdecl;
procedure QFontDatabase_destroy(handle: QFontDatabaseH); cdecl;
procedure QFontDatabase_families(handle: QFontDatabaseH; retval: QStringListH; onlyForLocale: Boolean); cdecl;
procedure QFontDatabase_pointSizes(handle: QFontDatabaseH; retval: PIntArray; family: PWideString; style: PWideString; charSet: PWideString); cdecl;
procedure QFontDatabase_styles(handle: QFontDatabaseH; retval: QStringListH; family: PWideString; charSet: PWideString); cdecl;
procedure QFontDatabase_charSets(handle: QFontDatabaseH; retval: QStringListH; familyName: PWideString; onlyForLocale: Boolean); overload; cdecl;
procedure QFontDatabase_font(handle: QFontDatabaseH; retval: QFontH; familyName: PWideString; style: PWideString; pointSize: Integer; charSetName: PWideString); cdecl;
function QFontDatabase_isBitmapScalable(handle: QFontDatabaseH; family: PWideString; style: PWideString; charSet: PWideString): Boolean; cdecl;
function QFontDatabase_isSmoothlyScalable(handle: QFontDatabaseH; family: PWideString; style: PWideString; charSet: PWideString): Boolean; cdecl;
function QFontDatabase_isScalable(handle: QFontDatabaseH; family: PWideString; style: PWideString; charSet: PWideString): Boolean; cdecl;
procedure QFontDatabase_smoothSizes(handle: QFontDatabaseH; retval: PIntArray; family: PWideString; style: PWideString; charSet: PWideString); cdecl;
procedure QFontDatabase_standardSizes(retval: PIntArray); cdecl;
function QFontDatabase_italic(handle: QFontDatabaseH; family: PWideString; style: PWideString; charSet: PWideString): Boolean; cdecl;
function QFontDatabase_bold(handle: QFontDatabaseH; family: PWideString; style: PWideString; charSet: PWideString): Boolean; cdecl;
function QFontDatabase_weight(handle: QFontDatabaseH; family: PWideString; style: PWideString; charSet: PWideString): Integer; cdecl;

procedure QFontDatabase_styleString(handle: QFontDatabaseH; retval: PWideString; p1: QFontH); cdecl;
procedure QFontDatabase_verboseCharSetName(retval: PWideString; charSetName: PWideString); cdecl;
procedure QFontDatabase_charSetSample(retval: PWideString; charSetName: PWideString); cdecl;

function QFontInfo_create(p1: QFontH): QFontInfoH; overload; cdecl;
procedure QFontInfo_destroy(handle: QFontInfoH); cdecl;
function QFontInfo_create(p1: QFontInfoH): QFontInfoH; overload; cdecl;
procedure QFontInfo_family(handle: QFontInfoH; retval: PWideString); cdecl;
function QFontInfo_pointSize(handle: QFontInfoH): Integer; cdecl;
function QFontInfo_italic(handle: QFontInfoH): Boolean; cdecl;
function QFontInfo_weight(handle: QFontInfoH): Integer; cdecl;
function QFontInfo_bold(handle: QFontInfoH): Boolean; cdecl;
function QFontInfo_underline(handle: QFontInfoH): Boolean; cdecl;
function QFontInfo_strikeOut(handle: QFontInfoH): Boolean; cdecl;
function QFontInfo_fixedPitch(handle: QFontInfoH): Boolean; cdecl;
function QFontInfo_styleHint(handle: QFontInfoH): QFontStyleHint; cdecl;
function QFontInfo_charSet(handle: QFontInfoH): QFontCharSet; cdecl;
function QFontInfo_rawMode(handle: QFontInfoH): Boolean; cdecl;
function QFontInfo_exactMatch(handle: QFontInfoH): Boolean; cdecl;
function QFontInfo_font(handle: QFontInfoH): QFontH; cdecl;

function QFontMetrics_create(p1: QFontH): QFontMetricsH; overload; cdecl;
procedure QFontMetrics_destroy(handle: QFontMetricsH); cdecl;
function QFontMetrics_create(p1: QFontMetricsH): QFontMetricsH; overload; cdecl;
function QFontMetrics_ascent(handle: QFontMetricsH): Integer; cdecl;
function QFontMetrics_descent(handle: QFontMetricsH): Integer; cdecl;
function QFontMetrics_height(handle: QFontMetricsH): Integer; cdecl;
function QFontMetrics_leading(handle: QFontMetricsH): Integer; cdecl;
function QFontMetrics_lineSpacing(handle: QFontMetricsH): Integer; cdecl;
function QFontMetrics_minLeftBearing(handle: QFontMetricsH): Integer; cdecl;
function QFontMetrics_minRightBearing(handle: QFontMetricsH): Integer; cdecl;
function QFontMetrics_maxWidth(handle: QFontMetricsH): Integer; cdecl;
function QFontMetrics_inFont(handle: QFontMetricsH; p1: PWideChar): Boolean; cdecl;
function QFontMetrics_leftBearing(handle: QFontMetricsH; p1: PWideChar): Integer; cdecl;
function QFontMetrics_rightBearing(handle: QFontMetricsH; p1: PWideChar): Integer; cdecl;
function QFontMetrics_width(handle: QFontMetricsH; p1: PWideString; len: Integer): Integer; overload; cdecl;
function QFontMetrics_width(handle: QFontMetricsH; p1: PWideChar): Integer; overload; cdecl;
function QFontMetrics_width(handle: QFontMetricsH; c: char): Integer; overload; cdecl;
procedure QFontMetrics_boundingRect(handle: QFontMetricsH; retval: PRect; p1: PWideString; len: Integer); overload; cdecl;
procedure QFontMetrics_boundingRect(handle: QFontMetricsH; retval: PRect; p1: PWideChar); overload; cdecl;
procedure QFontMetrics_boundingRect(handle: QFontMetricsH; retval: PRect; x: Integer; y: Integer; w: Integer; h: Integer; flags: Integer; str: PWideString; len: Integer; tabstops: Integer; tabarray: PInteger; intern: PPAnsiChar); overload; cdecl;
procedure QFontMetrics_size(handle: QFontMetricsH; retval: PSize; flags: Integer; str: PWideString; len: Integer; tabstops: Integer; tabarray: PInteger; intern: PPAnsiChar); cdecl;
function QFontMetrics_underlinePos(handle: QFontMetricsH): Integer; cdecl;
function QFontMetrics_strikeOutPos(handle: QFontMetricsH): Integer; cdecl;
function QFontMetrics_lineWidth(handle: QFontMetricsH): Integer; cdecl;

procedure QInputDialog_getText(retval: PWideString; caption: PWideString; _label: PWideString; text: PWideString; ok: PBoolean; parent: QWidgetH; name: PAnsiChar); overload; cdecl;
procedure QInputDialog_getText(retval: PWideString; caption: PWideString; _label: PWideString; echo: QLineEditEchoMode; text: PWideString; ok: PBoolean; parent: QWidgetH; name: PAnsiChar); overload; cdecl;
function QInputDialog_getInteger(caption: PWideString; _label: PWideString; num: Integer; from: Integer; _to: Integer; step: Integer; ok: PBoolean; parent: QWidgetH; name: PAnsiChar): Integer; cdecl;
function QInputDialog_getDouble(caption: PWideString; _label: PWideString; num: Double; from: Double; _to: Double; decimals: Integer; ok: PBoolean; parent: QWidgetH; name: PAnsiChar): Double; cdecl;
procedure QInputDialog_getItem(retval: PWideString; caption: PWideString; _label: PWideString; list: QStringListH; current: Integer; editable: Boolean; ok: PBoolean; parent: QWidgetH; name: PAnsiChar); cdecl;

function QIODevice_create(): QIODeviceH; cdecl;
procedure QIODevice_destroy(handle: QIODeviceH); cdecl;
function QIODevice_flags(handle: QIODeviceH): Integer; cdecl;
function QIODevice_mode(handle: QIODeviceH): Integer; cdecl;
function QIODevice_state(handle: QIODeviceH): Integer; cdecl;
function QIODevice_isDirectAccess(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_isSequentialAccess(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_isCombinedAccess(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_isBuffered(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_isRaw(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_isSynchronous(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_isAsynchronous(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_isTranslated(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_isReadable(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_isWritable(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_isReadWrite(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_isInactive(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_isOpen(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_status(handle: QIODeviceH): Integer; cdecl;
procedure QIODevice_resetStatus(handle: QIODeviceH); cdecl;
function QIODevice_open(handle: QIODeviceH; mode: Integer): Boolean; cdecl;
procedure QIODevice_close(handle: QIODeviceH); cdecl;
procedure QIODevice_flush(handle: QIODeviceH); cdecl;
function QIODevice_size(handle: QIODeviceH): Cardinal; cdecl;
function QIODevice_at(handle: QIODeviceH): Integer; overload; cdecl;
function QIODevice_at(handle: QIODeviceH; p1: Integer): Boolean; overload; cdecl;
function QIODevice_atEnd(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_reset(handle: QIODeviceH): Boolean; cdecl;
function QIODevice_readBlock(handle: QIODeviceH; data: PAnsiChar; maxlen: Cardinal): Integer; cdecl;
function QIODevice_writeBlock(handle: QIODeviceH; data: PAnsiChar; len: Cardinal): Integer; overload; cdecl;
function QIODevice_readLine(handle: QIODeviceH; data: PAnsiChar; maxlen: Cardinal): Integer; cdecl;
function QIODevice_writeBlock(handle: QIODeviceH; data: QByteArrayH): Integer; overload; cdecl;
procedure QIODevice_readAll(handle: QIODeviceH; retval: QByteArrayH); cdecl;
function QIODevice_getch(handle: QIODeviceH): Integer; cdecl;
function QIODevice_putch(handle: QIODeviceH; p1: Integer): Integer; cdecl;
function QIODevice_ungetch(handle: QIODeviceH; p1: Integer): Integer; cdecl;

function QMenuItem_create(): QMenuItemH; cdecl;
procedure QMenuItem_destroy(handle: QMenuItemH); cdecl;
function QMenuItem_id(handle: QMenuItemH): Integer; cdecl;
function QMenuItem_iconSet(handle: QMenuItemH): QIconSetH; cdecl;
procedure QMenuItem_text(handle: QMenuItemH; retval: PWideString); cdecl;
procedure QMenuItem_whatsThis(handle: QMenuItemH; retval: PWideString); cdecl;
function QMenuItem_pixmap(handle: QMenuItemH): QPixmapH; cdecl;
function QMenuItem_popup(handle: QMenuItemH): QPopupMenuH; cdecl;
function QMenuItem_widget(handle: QMenuItemH): QWidgetH; cdecl;
function QMenuItem_custom(handle: QMenuItemH): QCustomMenuItemH; cdecl;
function QMenuItem_key(handle: QMenuItemH): Integer; cdecl;
function QMenuItem_signal(handle: QMenuItemH): QSignalH; cdecl;
function QMenuItem_isSeparator(handle: QMenuItemH): Boolean; cdecl;
function QMenuItem_isEnabled(handle: QMenuItemH): Boolean; cdecl;
function QMenuItem_isChecked(handle: QMenuItemH): Boolean; cdecl;
function QMenuItem_isDirty(handle: QMenuItemH): Boolean; cdecl;
procedure QMenuItem_setText(handle: QMenuItemH; text: PWideString); cdecl;
procedure QMenuItem_setDirty(handle: QMenuItemH; dirty: Boolean); cdecl;
procedure QMenuItem_setWhatsThis(handle: QMenuItemH; text: PWideString); cdecl;

function QCustomMenuItem_create(): QCustomMenuItemH; cdecl;
procedure QCustomMenuItem_destroy(handle: QCustomMenuItemH); cdecl;
function QCustomMenuItem_fullSpan(handle: QCustomMenuItemH): Boolean; cdecl;
function QCustomMenuItem_isSeparator(handle: QCustomMenuItemH): Boolean; cdecl;
procedure QCustomMenuItem_setFont(handle: QCustomMenuItemH; font: QFontH); cdecl;
procedure QCustomMenuItem_paint(handle: QCustomMenuItemH; p: QPainterH; cg: QColorGroupH; act: Boolean; enabled: Boolean; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QCustomMenuItem_sizeHint(handle: QCustomMenuItemH; retval: PSize); cdecl;

function QMenuData_create(): QMenuDataH; cdecl;
procedure QMenuData_destroy(handle: QMenuDataH); cdecl;
function QMenuData_count(handle: QMenuDataH): Cardinal; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; text: PWideString; receiver: QObjectH; member: PAnsiChar; accel: Integer; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; text: PWideString; receiver: QObjectH; member: PAnsiChar; accel: Integer; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; pixmap: QPixmapH; receiver: QObjectH; member: PAnsiChar; accel: Integer; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; pixmap: QPixmapH; receiver: QObjectH; member: PAnsiChar; accel: Integer; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; text: PWideString; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; text: PWideString; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; text: PWideString; popup: QPopupMenuH; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; text: PWideString; popup: QPopupMenuH; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; pixmap: QPixmapH; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; pixmap: QPixmapH; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; pixmap: QPixmapH; popup: QPopupMenuH; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; pixmap: QPixmapH; popup: QPopupMenuH; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; widget: QWidgetH; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; custom: QCustomMenuItemH; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertItem(handle: QMenuDataH; custom: QCustomMenuItemH; id: Integer; index: Integer): Integer; overload; cdecl;
function QMenuData_insertSeparator(handle: QMenuDataH; index: Integer): Integer; cdecl;
procedure QMenuData_removeItem(handle: QMenuDataH; id: Integer); cdecl;
procedure QMenuData_removeItemAt(handle: QMenuDataH; index: Integer); cdecl;
procedure QMenuData_clear(handle: QMenuDataH); cdecl;
function QMenuData_accel(handle: QMenuDataH; id: Integer): Integer; cdecl;
procedure QMenuData_setAccel(handle: QMenuDataH; key: Integer; id: Integer); cdecl;
function QMenuData_iconSet(handle: QMenuDataH; id: Integer): QIconSetH; cdecl;
procedure QMenuData_text(handle: QMenuDataH; retval: PWideString; id: Integer); cdecl;
function QMenuData_pixmap(handle: QMenuDataH; id: Integer): QPixmapH; cdecl;
procedure QMenuData_setWhatsThis(handle: QMenuDataH; id: Integer; p2: PWideString); cdecl;
procedure QMenuData_whatsThis(handle: QMenuDataH; retval: PWideString; id: Integer); cdecl;
procedure QMenuData_changeItem(handle: QMenuDataH; id: Integer; text: PWideString); overload; cdecl;
procedure QMenuData_changeItem(handle: QMenuDataH; id: Integer; pixmap: QPixmapH); overload; cdecl;
procedure QMenuData_changeItem(handle: QMenuDataH; id: Integer; icon: QIconSetH; text: PWideString); overload; cdecl;
procedure QMenuData_changeItem(handle: QMenuDataH; id: Integer; icon: QIconSetH; pixmap: QPixmapH); overload; cdecl;
procedure QMenuData_changeItem(handle: QMenuDataH; text: PWideString; id: Integer); overload; cdecl;
procedure QMenuData_changeItem(handle: QMenuDataH; pixmap: QPixmapH; id: Integer); overload; cdecl;
procedure QMenuData_changeItem(handle: QMenuDataH; icon: QIconSetH; text: PWideString; id: Integer); overload; cdecl;
function QMenuData_isItemEnabled(handle: QMenuDataH; id: Integer): Boolean; cdecl;
procedure QMenuData_setItemEnabled(handle: QMenuDataH; id: Integer; enable: Boolean); cdecl;
function QMenuData_isItemChecked(handle: QMenuDataH; id: Integer): Boolean; cdecl;
procedure QMenuData_setItemChecked(handle: QMenuDataH; id: Integer; check: Boolean); cdecl;
procedure QMenuData_updateItem(handle: QMenuDataH; id: Integer); cdecl;
function QMenuData_indexOf(handle: QMenuDataH; id: Integer): Integer; cdecl;
function QMenuData_idAt(handle: QMenuDataH; index: Integer): Integer; cdecl;
procedure QMenuData_setId(handle: QMenuDataH; index: Integer; id: Integer); cdecl;
function QMenuData_connectItem(handle: QMenuDataH; id: Integer; receiver: QObjectH; member: PAnsiChar): Boolean; cdecl;
function QMenuData_disconnectItem(handle: QMenuDataH; id: Integer; receiver: QObjectH; member: PAnsiChar): Boolean; cdecl;
function QMenuData_setItemParameter(handle: QMenuDataH; id: Integer; param: Integer): Boolean; cdecl;
function QMenuData_itemParameter(handle: QMenuDataH; id: Integer): Integer; cdecl;
function QMenuData_findItem(handle: QMenuDataH; id: Integer): QMenuItemH; overload; cdecl;
function QMenuData_findItem(handle: QMenuDataH; id: Integer; parent: QMenuDataHH): QMenuItemH; overload; cdecl;
procedure QMenuData_activateItemAt(handle: QMenuDataH; index: Integer); cdecl;

function QMimeSource_format(handle: QMimeSourceH; n: Integer): PAnsiChar; cdecl;
function QMimeSource_provides(handle: QMimeSourceH; p1: PAnsiChar): Boolean; cdecl;
procedure QMimeSource_encodedData(handle: QMimeSourceH; retval: QByteArrayH; p1: PAnsiChar); cdecl;

function QMimeSourceFactory_create(): QMimeSourceFactoryH; cdecl;
procedure QMimeSourceFactory_destroy(handle: QMimeSourceFactoryH); cdecl;
function QMimeSourceFactory_defaultFactory(): QMimeSourceFactoryH; cdecl;
procedure QMimeSourceFactory_setDefaultFactory(p1: QMimeSourceFactoryH); cdecl;
function QMimeSourceFactory_data(handle: QMimeSourceFactoryH; abs_name: PWideString): QMimeSourceH; overload; cdecl;
procedure QMimeSourceFactory_makeAbsolute(handle: QMimeSourceFactoryH; retval: PWideString; abs_or_rel_name: PWideString; context: PWideString); cdecl;
function QMimeSourceFactory_data(handle: QMimeSourceFactoryH; abs_or_rel_name: PWideString; context: PWideString): QMimeSourceH; overload; cdecl;
procedure QMimeSourceFactory_setText(handle: QMimeSourceFactoryH; abs_name: PWideString; text: PWideString); cdecl;
procedure QMimeSourceFactory_setImage(handle: QMimeSourceFactoryH; abs_name: PWideString; im: QImageH); cdecl;
procedure QMimeSourceFactory_setPixmap(handle: QMimeSourceFactoryH; abs_name: PWideString; pm: QPixmapH); cdecl;
procedure QMimeSourceFactory_setData(handle: QMimeSourceFactoryH; abs_name: PWideString; data: QMimeSourceH); cdecl;
procedure QMimeSourceFactory_setFilePath(handle: QMimeSourceFactoryH; p1: QStringListH); cdecl;
procedure QMimeSourceFactory_filePath(handle: QMimeSourceFactoryH; retval: QStringListH); cdecl;
procedure QMimeSourceFactory_addFilePath(handle: QMimeSourceFactoryH; p1: PWideString); cdecl;
procedure QMimeSourceFactory_setExtensionType(handle: QMimeSourceFactoryH; ext: PWideString; mimetype: PAnsiChar); cdecl;

function QWindowsMime_registerMimeType(mime: PAnsiChar): Integer; cdecl;

function QPaintDeviceMetrics_create(p1: QPaintDeviceH): QPaintDeviceMetricsH; cdecl;
procedure QPaintDeviceMetrics_destroy(handle: QPaintDeviceMetricsH); cdecl;
function QPaintDeviceMetrics_width(handle: QPaintDeviceMetricsH): Integer; cdecl;
function QPaintDeviceMetrics_height(handle: QPaintDeviceMetricsH): Integer; cdecl;
function QPaintDeviceMetrics_widthMM(handle: QPaintDeviceMetricsH): Integer; cdecl;
function QPaintDeviceMetrics_heightMM(handle: QPaintDeviceMetricsH): Integer; cdecl;
function QPaintDeviceMetrics_logicalDpiX(handle: QPaintDeviceMetricsH): Integer; cdecl;
function QPaintDeviceMetrics_logicalDpiY(handle: QPaintDeviceMetricsH): Integer; cdecl;
function QPaintDeviceMetrics_numColors(handle: QPaintDeviceMetricsH): Integer; cdecl;
function QPaintDeviceMetrics_depth(handle: QPaintDeviceMetricsH): Integer; cdecl;

function QPicture_create(formatVersion: Integer): QPictureH; cdecl;
procedure QPicture_destroy(handle: QPictureH); cdecl;
function QPicture_isNull(handle: QPictureH): Boolean; cdecl;
function QPicture_size(handle: QPictureH): Cardinal; cdecl;
function QPicture_data(handle: QPictureH): PAnsiChar; cdecl;
procedure QPicture_setData(handle: QPictureH; data: PAnsiChar; size: Cardinal); cdecl;
function QPicture_play(handle: QPictureH; p1: QPainterH): Boolean; cdecl;
function QPicture_load(handle: QPictureH; fileName: PWideString): Boolean; cdecl;
function QPicture_save(handle: QPictureH; fileName: PWideString): Boolean; cdecl;

function QPixmapCache_cacheLimit(): Integer; cdecl;
procedure QPixmapCache_setCacheLimit(p1: Integer); cdecl;
function QPixmapCache_find(key: PWideString): QPixmapH; overload; cdecl;
function QPixmapCache_find(key: PWideString; p2: QPixmapH): Boolean; overload; cdecl;
function QPixmapCache_insert(key: PWideString; p2: QPixmapH): Boolean; overload; cdecl;

procedure QPixmapCache_clear(); cdecl;

function QPoint_create(): QPointH; overload; cdecl;
procedure QPoint_destroy(handle: QPointH); cdecl;
function QPoint_create(xpos: Integer; ypos: Integer): QPointH; overload; cdecl;
function QPoint_isNull(handle: QPointH): Boolean; cdecl;
function QPoint_x(handle: QPointH): Integer; cdecl;
function QPoint_y(handle: QPointH): Integer; cdecl;
procedure QPoint_setX(handle: QPointH; x: Integer); cdecl;
procedure QPoint_setY(handle: QPointH; y: Integer); cdecl;
function QPoint_manhattanLength(handle: QPointH): Integer; cdecl;
function QPoint_rx(handle: QPointH): QCOORD; cdecl;
function QPoint_ry(handle: QPointH): QCOORD; cdecl;

function QRangeControl_create(): QRangeControlH; overload; cdecl;
procedure QRangeControl_destroy(handle: QRangeControlH); cdecl;
function QRangeControl_create(minValue: Integer; maxValue: Integer; lineStep: Integer; pageStep: Integer; value: Integer): QRangeControlH; overload; cdecl;
function QRangeControl_value(handle: QRangeControlH): Integer; cdecl;
procedure QRangeControl_setValue(handle: QRangeControlH; p1: Integer); cdecl;
procedure QRangeControl_addPage(handle: QRangeControlH); cdecl;
procedure QRangeControl_subtractPage(handle: QRangeControlH); cdecl;
procedure QRangeControl_addLine(handle: QRangeControlH); cdecl;
procedure QRangeControl_subtractLine(handle: QRangeControlH); cdecl;
function QRangeControl_minValue(handle: QRangeControlH): Integer; cdecl;
function QRangeControl_maxValue(handle: QRangeControlH): Integer; cdecl;
procedure QRangeControl_setRange(handle: QRangeControlH; minValue: Integer; maxValue: Integer); cdecl;
function QRangeControl_lineStep(handle: QRangeControlH): Integer; cdecl;
function QRangeControl_pageStep(handle: QRangeControlH): Integer; cdecl;
procedure QRangeControl_setSteps(handle: QRangeControlH; line: Integer; page: Integer); cdecl;
function QRangeControl_bound(handle: QRangeControlH; p1: Integer): Integer; cdecl;

function QRect_create(): QRectH; overload; cdecl;
procedure QRect_destroy(handle: QRectH); cdecl;
function QRect_create(topleft: PPoint; bottomright: PPoint): QRectH; overload; cdecl;
function QRect_create(topleft: PPoint; size: PSize): QRectH; overload; cdecl;
function QRect_create(left: Integer; top: Integer; width: Integer; height: Integer): QRectH; overload; cdecl;
function QRect_isNull(handle: QRectH): Boolean; cdecl;
function QRect_isEmpty(handle: QRectH): Boolean; cdecl;
function QRect_isValid(handle: QRectH): Boolean; cdecl;
procedure QRect_normalize(handle: QRectH; retval: PRect); cdecl;
function QRect_left(handle: QRectH): Integer; cdecl;
function QRect_top(handle: QRectH): Integer; cdecl;
function QRect_right(handle: QRectH): Integer; cdecl;
function QRect_bottom(handle: QRectH): Integer; cdecl;
function QRect_rLeft(handle: QRectH): QCOORD; cdecl;
function QRect_rTop(handle: QRectH): QCOORD; cdecl;
function QRect_rRight(handle: QRectH): QCOORD; cdecl;
function QRect_rBottom(handle: QRectH): QCOORD; cdecl;
function QRect_x(handle: QRectH): Integer; cdecl;
function QRect_y(handle: QRectH): Integer; cdecl;
procedure QRect_setLeft(handle: QRectH; pos: Integer); cdecl;
procedure QRect_setTop(handle: QRectH; pos: Integer); cdecl;
procedure QRect_setRight(handle: QRectH; pos: Integer); cdecl;
procedure QRect_setBottom(handle: QRectH; pos: Integer); cdecl;
procedure QRect_setX(handle: QRectH; x: Integer); cdecl;
procedure QRect_setY(handle: QRectH; y: Integer); cdecl;
procedure QRect_topLeft(handle: QRectH; retval: PPoint); cdecl;
procedure QRect_bottomRight(handle: QRectH; retval: PPoint); cdecl;
procedure QRect_topRight(handle: QRectH; retval: PPoint); cdecl;
procedure QRect_bottomLeft(handle: QRectH; retval: PPoint); cdecl;
procedure QRect_center(handle: QRectH; retval: PPoint); cdecl;
procedure QRect_rect(handle: QRectH; x: PInteger; y: PInteger; w: PInteger; h: PInteger); cdecl;
procedure QRect_coords(handle: QRectH; x1: PInteger; y1: PInteger; x2: PInteger; y2: PInteger); cdecl;
procedure QRect_moveTopLeft(handle: QRectH; p: PPoint); cdecl;
procedure QRect_moveBottomRight(handle: QRectH; p: PPoint); cdecl;
procedure QRect_moveTopRight(handle: QRectH; p: PPoint); cdecl;
procedure QRect_moveBottomLeft(handle: QRectH; p: PPoint); cdecl;
procedure QRect_moveCenter(handle: QRectH; p: PPoint); cdecl;
procedure QRect_moveBy(handle: QRectH; dx: Integer; dy: Integer); cdecl;
procedure QRect_setRect(handle: QRectH; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QRect_setCoords(handle: QRectH; x1: Integer; y1: Integer; x2: Integer; y2: Integer); cdecl;
procedure QRect_size(handle: QRectH; retval: PSize); cdecl;
function QRect_width(handle: QRectH): Integer; cdecl;
function QRect_height(handle: QRectH): Integer; cdecl;
procedure QRect_setWidth(handle: QRectH; w: Integer); cdecl;
procedure QRect_setHeight(handle: QRectH; h: Integer); cdecl;
procedure QRect_setSize(handle: QRectH; s: PSize); cdecl;
function QRect_contains(handle: QRectH; p: PPoint; proper: Boolean): Boolean; overload; cdecl;
function QRect_contains(handle: QRectH; x: Integer; y: Integer; proper: Boolean): Boolean; overload; cdecl;
function QRect_contains(handle: QRectH; r: PRect; proper: Boolean): Boolean; overload; cdecl;
procedure QRect_unite(handle: QRectH; retval: PRect; r: PRect); cdecl;
procedure QRect_intersect(handle: QRectH; retval: PRect; r: PRect); cdecl;
function QRect_intersects(handle: QRectH; r: PRect): Boolean; cdecl;

function QSize_create(): QSizeH; overload; cdecl;
procedure QSize_destroy(handle: QSizeH); cdecl;
function QSize_create(w: Integer; h: Integer): QSizeH; overload; cdecl;
function QSize_isNull(handle: QSizeH): Boolean; cdecl;
function QSize_isEmpty(handle: QSizeH): Boolean; cdecl;
function QSize_isValid(handle: QSizeH): Boolean; cdecl;
function QSize_width(handle: QSizeH): Integer; cdecl;
function QSize_height(handle: QSizeH): Integer; cdecl;
procedure QSize_setWidth(handle: QSizeH; w: Integer); cdecl;
procedure QSize_setHeight(handle: QSizeH; h: Integer); cdecl;
procedure QSize_transpose(handle: QSizeH); cdecl;
procedure QSize_expandedTo(handle: QSizeH; retval: PSize; p1: PSize); cdecl;
procedure QSize_boundedTo(handle: QSizeH; retval: PSize; p1: PSize); cdecl;
function QSize_rwidth(handle: QSizeH): QCOORD; cdecl;
function QSize_rheight(handle: QSizeH): QCOORD; cdecl;

function QStringList_create(): QStringListH; overload; cdecl;
procedure QStringList_destroy(handle: QStringListH); cdecl;
function QStringList_create(l: QStringListH): QStringListH; overload; cdecl;

function QStringList_create(i: PWideString): QStringListH; overload; cdecl;
function QStringList_create(i: PAnsiChar): QStringListH; overload; cdecl;
procedure QStringList_fromStrList(retval: QStringListH; p1: QStrListH); cdecl;
procedure QStringList_sort(handle: QStringListH); cdecl;
procedure QStringList_split(retval: QStringListH; sep: PWideString; str: PWideString; allowEmptyEntries: Boolean); overload; cdecl;
procedure QStringList_split(retval: QStringListH; sep: PWideChar; str: PWideString; allowEmptyEntries: Boolean); overload; cdecl;
procedure QStringList_split(retval: QStringListH; sep: QRegExpH; str: PWideString; allowEmptyEntries: Boolean); overload; cdecl;
procedure QStringList_join(handle: QStringListH; retval: PWideString; sep: PWideString); cdecl;
procedure QStringList_grep(handle: QStringListH; retval: QStringListH; str: PWideString; cs: Boolean); overload; cdecl;
procedure QStringList_grep(handle: QStringListH; retval: QStringListH; expr: QRegExpH); overload; cdecl;

function QWMatrix_create(): QWMatrixH; overload; cdecl;
procedure QWMatrix_destroy(handle: QWMatrixH); cdecl;
function QWMatrix_create(m11: Double; m12: Double; m21: Double; m22: Double; dx: Double; dy: Double): QWMatrixH; overload; cdecl;
procedure QWMatrix_setMatrix(handle: QWMatrixH; m11: Double; m12: Double; m21: Double; m22: Double; dx: Double; dy: Double); cdecl;
function QWMatrix_m11(handle: QWMatrixH): Double; cdecl;
function QWMatrix_m12(handle: QWMatrixH): Double; cdecl;
function QWMatrix_m21(handle: QWMatrixH): Double; cdecl;
function QWMatrix_m22(handle: QWMatrixH): Double; cdecl;
function QWMatrix_dx(handle: QWMatrixH): Double; cdecl;
function QWMatrix_dy(handle: QWMatrixH): Double; cdecl;
procedure QWMatrix_map(handle: QWMatrixH; x: Integer; y: Integer; tx: PInteger; ty: PInteger); overload; cdecl;
procedure QWMatrix_map(handle: QWMatrixH; x: Double; y: Double; tx: PDouble; ty: PDouble); overload; cdecl;
procedure QWMatrix_map(handle: QWMatrixH; retval: PPoint; p1: PPoint); overload; cdecl;
procedure QWMatrix_map(handle: QWMatrixH; retval: PRect; p1: PRect); overload; cdecl;
procedure QWMatrix_map(handle: QWMatrixH; retval: PPointArray; p1: PPointArray); overload; cdecl;
procedure QWMatrix_reset(handle: QWMatrixH); cdecl;
function QWMatrix_translate(handle: QWMatrixH; dx: Double; dy: Double): QWMatrixH; cdecl;
function QWMatrix_scale(handle: QWMatrixH; sx: Double; sy: Double): QWMatrixH; cdecl;
function QWMatrix_shear(handle: QWMatrixH; sh: Double; sv: Double): QWMatrixH; cdecl;
function QWMatrix_rotate(handle: QWMatrixH; a: Double): QWMatrixH; cdecl;
procedure QWMatrix_invert(handle: QWMatrixH; retval: QWMatrixH; p1: PBoolean); cdecl;

procedure QClxObjectMap_setAddCallback(ptr: Pointer); cdecl;
procedure QClxObjectMap_setRemoveCallback(ptr: Pointer); cdecl;
procedure QClxObjectMap_add(obj: Pointer; value: Integer); cdecl;
procedure QClxObjectMap_remove(obj: Pointer); cdecl;
function QClxObjectMap_find(obj: Pointer): Integer; cdecl;
function QClxObjectMap_findClxObject(obj: Pointer): Integer; cdecl;

function QClxIODevice_create(stream: Pointer): QClxIODeviceH; cdecl;
procedure QClxIODevice_destroy(handle: QClxIODeviceH); cdecl;

function QClxLineEdit_create(parent: QWidgetH; name: PAnsiChar): QClxLineEditH; cdecl;
procedure QClxLineEdit_destroy(handle: QClxLineEditH); cdecl;
function QClxLineEdit_autoSelect(handle: QClxLineEditH): Boolean; cdecl;
procedure QClxLineEdit_setAutoSelect(handle: QClxLineEditH; value: Boolean); cdecl;
function QClxLineEdit_hideSelection(handle: QClxLineEditH): Boolean; cdecl;
procedure QClxLineEdit_setHideSelection(handle: QClxLineEditH; value: Boolean); cdecl;
procedure QClxLineEdit_clearSelection(handle: QClxLineEditH); cdecl;
procedure QClxLineEdit_resetSelection(handle: QClxLineEditH); cdecl;
function QClxLineEdit_selStart(handle: QClxLineEditH): Integer; cdecl;
procedure QClxLineEdit_setSelStart(handle: QClxLineEditH; pos: Integer); cdecl;
procedure QClxLineEdit_updateSelection(handle: QClxLineEditH); cdecl;
procedure QClxLineEdit_setSelection(handle: QClxLineEditH; start: Integer; len: Integer); cdecl;
function QClxLineEdit_selLen(handle: QClxLineEditH): Integer; cdecl;
procedure QClxLineEdit_setMarkedText(handle: QClxLineEditH; s: PWideString); cdecl;
function QClxLineEdit_hasMarkedText(handle: QClxLineEditH): Boolean; cdecl;
procedure QClxLineEdit_markedText(handle: QClxLineEditH; retval: PWideString); cdecl;

function QOpenWidget_event(handle: QOpenWidgetH; e: QEventH): Boolean; cdecl;
procedure QOpenWidget_mousePressEvent(handle: QOpenWidgetH; e: QMouseEventH); cdecl;
procedure QOpenWidget_mouseReleaseEvent(handle: QOpenWidgetH; e: QMouseEventH); cdecl;
procedure QOpenWidget_mouseDoubleClickEvent(handle: QOpenWidgetH; e: QMouseEventH); cdecl;
procedure QOpenWidget_mouseMoveEvent(handle: QOpenWidgetH; e: QMouseEventH); cdecl;
procedure QOpenWidget_wheelEvent(handle: QOpenWidgetH; e: QWheelEventH); cdecl;
procedure QOpenWidget_keyPressEvent(handle: QOpenWidgetH; e: QKeyEventH); cdecl;
procedure QOpenWidget_keyReleaseEvent(handle: QOpenWidgetH; e: QKeyEventH); cdecl;
procedure QOpenWidget_focusInEvent(handle: QOpenWidgetH; e: QFocusEventH); cdecl;
procedure QOpenWidget_focusOutEvent(handle: QOpenWidgetH; e: QFocusEventH); cdecl;
procedure QOpenWidget_enterEvent(handle: QOpenWidgetH; e: QEventH); cdecl;
procedure QOpenWidget_leaveEvent(handle: QOpenWidgetH; e: QEventH); cdecl;
procedure QOpenWidget_paintEvent(handle: QOpenWidgetH; e: QPaintEventH); cdecl;
procedure QOpenWidget_moveEvent(handle: QOpenWidgetH; e: QMoveEventH); cdecl;
procedure QOpenWidget_resizeEvent(handle: QOpenWidgetH; e: QResizeEventH); cdecl;
procedure QOpenWidget_closeEvent(handle: QOpenWidgetH; e: QCloseEventH); cdecl;
procedure QOpenWidget_dragEnterEvent(handle: QOpenWidgetH; e: QDragEnterEventH); cdecl;
procedure QOpenWidget_dragMoveEvent(handle: QOpenWidgetH; e: QDragMoveEventH); cdecl;
procedure QOpenWidget_dragLeaveEvent(handle: QOpenWidgetH; e: QDragLeaveEventH); cdecl;
procedure QOpenWidget_dropEvent(handle: QOpenWidgetH; e: QDropEventH); cdecl;
procedure QOpenWidget_showEvent(handle: QOpenWidgetH; e: QShowEventH); cdecl;
procedure QOpenWidget_hideEvent(handle: QOpenWidgetH; e: QHideEventH); cdecl;
procedure QOpenWidget_customEvent(handle: QOpenWidgetH; e: QCustomEventH); cdecl;
function QOpenWidget_getWState(handle: QOpenWidgetH): Cardinal; cdecl;
procedure QOpenWidget_setWState(handle: QOpenWidgetH; n: Cardinal); cdecl;
procedure QOpenWidget_clearWState(handle: QOpenWidgetH; n: Cardinal); cdecl;
function QOpenWidget_getWFlags(handle: QOpenWidgetH): WFlags; cdecl;
procedure QOpenWidget_setWFlags(handle: QOpenWidgetH; n: WFlags); cdecl;
procedure QOpenWidget_clearWFlags(handle: QOpenWidgetH; n: WFlags); cdecl;
function QOpenWidget_focusNextPrevChild(handle: QOpenWidgetH; next: Boolean): Boolean; cdecl;
procedure QOpenWidget_updateMask(handle: QOpenWidgetH); cdecl;

function QOpenStringList_count(handle: QOpenStringListH): Integer; cdecl;
procedure QOpenStringList_value(handle: QOpenStringListH; retval: PWideString; index: Integer); cdecl;
procedure QOpenStringList_append(handle: QOpenStringListH; value: PWideString); cdecl;

procedure QClxDrawUtil_DrawItem(p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; flags: Integer; g: QColorGroupH; enabled: Boolean; pixmap: QPixmapH; text: PWideString; len: Integer; penColor: QColorH); cdecl;
procedure QClxDrawUtil_DrawShadeLine(p: QPainterH; x1: Integer; y1: Integer; x2: Integer; y2: Integer; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; midLineWidth: Integer); overload; cdecl;
procedure QClxDrawUtil_DrawShadeLine(p: QPainterH; p1: PPoint; p2: PPoint; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; midLineWidth: Integer); overload; cdecl;
procedure QClxDrawUtil_DrawShadeRect(p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; midLineWidth: Integer; fill: QBrushH); overload; cdecl;
procedure QClxDrawUtil_DrawShadeRect(p: QPainterH; r: PRect; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; midLineWidth: Integer; fill: QBrushH); overload; cdecl;
procedure QClxDrawUtil_DrawShadePanel(p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; fill: QBrushH); overload; cdecl;
procedure QClxDrawUtil_DrawShadePanel(p: QPainterH; r: PRect; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; fill: QBrushH); overload; cdecl;
procedure QClxDrawUtil_DrawWinButton(p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH); overload; cdecl;
procedure QClxDrawUtil_DrawWinButton(p: QPainterH; r: PRect; g: QColorGroupH; sunken: Boolean; fill: QBrushH); overload; cdecl;
procedure QClxDrawUtil_DrawWinPanel(p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH); overload; cdecl;
procedure QClxDrawUtil_DrawWinPanel(p: QPainterH; r: PRect; g: QColorGroupH; sunken: Boolean; fill: QBrushH); overload; cdecl;
procedure QClxDrawUtil_DrawPlainRect(p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; c: QColorH; lineWidth: Integer; fill: QBrushH); overload; cdecl;
procedure QClxDrawUtil_DrawPlainRect(p: QPainterH; r: PRect; c: QColorH; lineWidth: Integer; fill: QBrushH); overload; cdecl;

function QClxListBoxHooks_create(): QClxListBoxHooksH; cdecl;
procedure QClxListBoxHooks_destroy(handle: QClxListBoxHooksH); cdecl;
procedure QClxListBoxHooks_hook_paint(handle: QClxListBoxHooksH; paintHook: QHookH); cdecl;
procedure QClxListBoxHooks_hook_measure(handle: QClxListBoxHooksH; measureHook: QHookH); cdecl;

function QClxListBoxItem_create(text: PWideString; listBox_hooks: QClxListBoxHooksH; d: Pointer): QClxListBoxItemH; cdecl;
procedure QClxListBoxItem_destroy(handle: QClxListBoxItemH); cdecl;
function QClxListBoxItem_width(handle: QClxListBoxItemH; lb: QListBoxH): Integer; cdecl;
function QClxListBoxItem_height(handle: QClxListBoxItemH; lb: QListBoxH): Integer; cdecl;
function QClxListBoxItem_getData(handle: QClxListBoxItemH): Pointer; cdecl;
procedure QClxListBoxItem_setData(handle: QClxListBoxItemH; d: Pointer); cdecl;
procedure QClxListBoxItem_setCustomHighlighting(handle: QClxListBoxItemH; value: Boolean); cdecl;

function QClxListViewHooks_create(): QClxListViewHooksH; cdecl;
procedure QClxListViewHooks_destroy(handle: QClxListViewHooksH); cdecl;
procedure QClxListViewHooks_hook_PaintCell(handle: QClxListViewHooksH; h: QHookH); cdecl;
procedure QClxListViewHooks_hook_PaintBranches(handle: QClxListViewHooksH; h: QHookH); cdecl;
procedure QClxListViewHooks_hook_setSelected(handle: QClxListViewHooksH; h: QHookH); cdecl;
procedure QClxListViewHooks_hook_change(handle: QClxListViewHooksH; h: QHookH); cdecl;
procedure QClxListViewHooks_hook_changing(handle: QClxListViewHooksH; h: QHookH); cdecl;
procedure QClxListViewHooks_hook_expanding(handle: QClxListViewHooksH; h: QHookH); cdecl;
procedure QClxListViewHooks_hook_expanded(handle: QClxListViewHooksH; h: QHookH); cdecl;
procedure QClxListViewHooks_hook_checked(handle: QClxListViewHooksH; h: QHookH); cdecl;
procedure QClxListViewHooks_hook_destroyed(handle: QClxListViewHooksH; h: QHookH); cdecl;

function QClxListViewItem_create(parent: QListViewH; after: QListViewItemH; h: QClxListViewHooksH): QClxListViewItemH; overload; cdecl;
procedure QClxListViewItem_destroy(handle: QClxListViewItemH); cdecl;
function QClxListViewItem_create(parent: QListViewItemH; after: QListViewItemH; h: QClxListViewHooksH): QClxListViewItemH; overload; cdecl;

function QClxCheckListItem_create(parent: QListViewH; text: PWideString; t: QCheckListItemType; h: QClxListViewHooksH): QClxCheckListItemH; overload; cdecl;
procedure QClxCheckListItem_destroy(handle: QClxCheckListItemH); cdecl;
function QClxCheckListItem_create(parent: QListViewItemH; text: PWideString; t: QCheckListItemType; h: QClxListViewHooksH): QClxCheckListItemH; overload; cdecl;

function QClxIconViewHooks_create(): QClxIconViewHooksH; cdecl;
procedure QClxIconViewHooks_destroy(handle: QClxIconViewHooksH); cdecl;
procedure QClxIconViewHooks_hook_PaintItem(handle: QClxIconViewHooksH; h: QHookH); cdecl;
procedure QClxIconViewHooks_hook_PaintFocus(handle: QClxIconViewHooksH; h: QHookH); cdecl;
procedure QClxIconViewHooks_hook_setSelected(handle: QClxIconViewHooksH; h: QHookH); cdecl;
procedure QClxIconViewHooks_hook_change(handle: QClxIconViewHooksH; h: QHookH); cdecl;
procedure QClxIconViewHooks_hook_changing(handle: QClxIconViewHooksH; h: QHookH); cdecl;
procedure QClxIconViewHooks_hook_destroyed(handle: QClxIconViewHooksH; h: QHookH); cdecl;

function QClxIconViewItem_create(parent: QIconViewH; h: QClxIconViewHooksH): QClxIconViewItemH; overload; cdecl;
procedure QClxIconViewItem_destroy(handle: QClxIconViewItemH); cdecl;
function QClxIconViewItem_create(parent: QIconViewH; after: QIconViewItemH; h: QClxIconViewHooksH): QClxIconViewItemH; overload; cdecl;

function QClxDragObject_create(dragSource: QWidgetH; name: PAnsiChar): QClxDragObjectH; cdecl;
procedure QClxDragObject_destroy(handle: QClxDragObjectH); cdecl;
function QClxDragObject_format(handle: QClxDragObjectH; n: Integer): PAnsiChar; cdecl;
procedure QClxDragObject_encodedData(handle: QClxDragObjectH; retval: QByteArrayH; format: PAnsiChar); cdecl;
function QClxDragObject_provides(handle: QClxDragObjectH; mimeType: PAnsiChar): Boolean; cdecl;
procedure QClxDragObject_addFormat(handle: QClxDragObjectH; format: PAnsiChar; ByteArray: QByteArrayH); cdecl;

function QOpenComboBox_create(parent: QWidgetH; name: PAnsiChar): QOpenComboBoxH; overload; cdecl;
procedure QOpenComboBox_destroy(handle: QOpenComboBoxH); cdecl;
function QOpenComboBox_create(rw: Boolean; parent: QWidgetH; name: PAnsiChar): QOpenComboBoxH; overload; cdecl;
procedure QOpenComboBox_popup(handle: QOpenComboBoxH); cdecl;

function QClxBitBtn_create(parent: QWidgetH; name: PAnsiChar; paintCB: QHookH): QClxBitBtnH; cdecl;
procedure QClxBitBtn_destroy(handle: QClxBitBtnH); cdecl;

function QClxMimeSource_create(): QClxMimeSourceH; overload; cdecl;
procedure QClxMimeSource_destroy(handle: QClxMimeSourceH); cdecl;
function QClxMimeSource_create(source: QMimeSourceH): QClxMimeSourceH; overload; cdecl;
function QClxMimeSource_format(handle: QClxMimeSourceH; n: Integer): PAnsiChar; cdecl;
procedure QClxMimeSource_encodedData(handle: QClxMimeSourceH; retval: QByteArrayH; format: PAnsiChar); cdecl;
function QClxMimeSource_provides(handle: QClxMimeSourceH; mimeType: PAnsiChar): Boolean; cdecl;
procedure QClxMimeSource_addFormat(handle: QClxMimeSourceH; format: PAnsiChar; ByteArray: QByteArrayH); cdecl;

function QClxMimeSourceFactory_create(): QClxMimeSourceFactoryH; cdecl;
procedure QClxMimeSourceFactory_destroy(handle: QClxMimeSourceFactoryH); cdecl;
procedure QClxMimeSourceFactory_setDataCallBack(handle: QClxMimeSourceFactoryH; hook: QHookH); cdecl;
function QClxMimeSourceFactory_data(handle: QClxMimeSourceFactoryH; abs_name: PWideString): QMimeSourceH; cdecl;

function QClxSlider_create(parent: QWidgetH; name: PAnsiChar; drawTickCB: QHookH): QClxSliderH; cdecl;
procedure QClxSlider_destroy(handle: QClxSliderH); cdecl;
procedure QClxSlider_drawTicks(handle: QClxSliderH; p: QPainterH; cg: QColorGroupH; dist: Integer; w: Integer; i: Integer); cdecl;

function QClxStyleHooks_create(): QClxStyleHooksH; cdecl;
procedure QClxStyleHooks_destroy(handle: QClxStyleHooksH); cdecl;
procedure QClxStyleHooks_hook_polish(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_unPolish(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_polish2(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_unPolish2(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_polish3(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_itemRect(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawItem(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawSeparator(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawRect(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawRectStrong(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawButton(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_buttonRect(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawButtonMask(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawBevelButton(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_bevelButtonRect(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawToolButton(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawToolButton2(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_toolButtonRect(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawPanel(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawPopupPanel(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawArrow(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawExclusiveIndicator(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawExclusiveIndicatorMask(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawIndicatorMask(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawIndicator(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawFocusRect(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawComboButton(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_comboButtonRect(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_comboButtonFocusRect(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawComboButtonMask(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawPushButton(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawPushButtonLabel(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_pushButtonContentsRect(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_tabbarMetrics(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawTab(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawTabMask(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_scrollBarMetrics(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawScrollBarControls(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawSlider(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawSliderMask(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawSliderGroove(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawSliderGrooveMask(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawSplitter(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawCheckMark(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_polishPopupMenu(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_extraPopupMenuItemWidth(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_popupSubmenuIndicatorWidth(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_popupMenuItemHeight(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_drawPopupMenuItem(handle: QClxStyleHooksH; hook: QHookH); cdecl;
procedure QClxStyleHooks_hook_StyleDestroyed(handle: QClxStyleHooksH; hook: QHookH); cdecl;

procedure QClxStyle_init(handle: QClxStyleH); cdecl;
function QClxStyle_create(aStyle: QStyleH; h: QClxStyleHooksH): QClxStyleH; overload; cdecl;
procedure QClxStyle_destroy(handle: QClxStyleH); cdecl;
function QClxStyle_create(styleName: PWideString; h: QClxStyleHooksH): QClxStyleH; overload; cdecl;
procedure QClxStyle_refresh(handle: QClxStyleH); cdecl;
function QClxStyle_defaultFrameWidth(handle: QClxStyleH): Integer; cdecl;
procedure QClxStyle_setDefaultFrameWidth(handle: QClxStyleH; Val: Integer); cdecl;
function QClxStyle_sliderLength(handle: QClxStyleH): Integer; cdecl;
procedure QClxStyle_setSliderLength(handle: QClxStyleH; Val: Integer); cdecl;
function QClxStyle_maximumSliderDragDistance(handle: QClxStyleH): Integer; cdecl;
procedure QClxStyle_setMaximumSliderDragDistance(handle: QClxStyleH; Val: Integer); cdecl;
function QClxStyle_splitterWidth(handle: QClxStyleH): Integer; cdecl;
procedure QClxStyle_setSplitterWidth(handle: QClxStyleH; Val: Integer); cdecl;
procedure QClxStyle_scrollBarExtent(handle: QClxStyleH; retval: PSize); cdecl;
procedure QClxStyle_setScrollBarExtent(handle: QClxStyleH; Val: PSize); cdecl;
procedure QClxStyle_indicatorSize(handle: QClxStyleH; retval: PSize); cdecl;
procedure QClxStyle_setIndicatorSize(handle: QClxStyleH; Val: PSize); cdecl;
procedure QClxStyle_exclusiveIndicatorSize(handle: QClxStyleH; retval: PSize); cdecl;
procedure QClxStyle_setExclusiveIndicatorSize(handle: QClxStyleH; Val: PSize); cdecl;
procedure QClxStyle_buttonShift(handle: QClxStyleH; x: PInteger; y: PInteger); cdecl;
procedure QClxStyle_setButtonShift(handle: QClxStyleH; x: Integer; y: Integer); cdecl;
procedure QClxStyle_scrollBarMetrics(handle: QClxStyleH; p1: QScrollBarH; p2: PInteger; p3: PInteger; p4: PInteger; p5: PInteger); cdecl;
procedure QClxStyle_tabbarMetrics(handle: QClxStyleH; p1: QTabBarH; p2: PInteger; p3: PInteger; p4: PInteger); cdecl;

function QClxSpinBox_create(parent: QWidgetH; name: PAnsiChar): QClxSpinBoxH; overload; cdecl;
procedure QClxSpinBox_destroy(handle: QClxSpinBoxH); cdecl;
function QClxSpinBox_create(minValue: Integer; maxValue: Integer; step: Integer; parent: QWidgetH; name: PAnsiChar): QClxSpinBoxH; overload; cdecl;
function QClxSpinBox_upButton(handle: QClxSpinBoxH): QPushButtonH; cdecl;
function QClxSpinBox_downButton(handle: QClxSpinBoxH): QPushButtonH; cdecl;
function QClxSpinBox_editor(handle: QClxSpinBoxH): QLineEditH; cdecl;

function QOpenScrollView_create(scrollBarGeometry_hook: QHookH; parent: QWidgetH; name: PAnsiChar; f: WFlags): QOpenScrollViewH; cdecl;
procedure QOpenScrollView_destroy(handle: QOpenScrollViewH); cdecl;
procedure QOpenScrollView_resizeContents(handle: QOpenScrollViewH; w: Integer; h: Integer); cdecl;
procedure QOpenScrollView_setVBarGeometry(handle: QOpenScrollViewH; vbar: QScrollBarH; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QOpenScrollView_setHBarGeometry(handle: QOpenScrollViewH; hbar: QScrollBarH; x: Integer; y: Integer; w: Integer; h: Integer); cdecl;
procedure QOpenScrollView_getScrollBarGeometry(handle: QOpenScrollViewH; sb: QScrollBarH; x: PInteger; y: PInteger; w: PInteger; h: PInteger); cdecl;
procedure QOpenScrollView_setMargins(handle: QOpenScrollViewH; left: Integer; top: Integer; right: Integer; bottom: Integer); cdecl;
function QOpenScrollView_leftMargin(handle: QOpenScrollViewH): Integer; cdecl;
function QOpenScrollView_topMargin(handle: QOpenScrollViewH): Integer; cdecl;
function QOpenScrollView_rightMargin(handle: QOpenScrollViewH): Integer; cdecl;
function QOpenScrollView_bottomMargin(handle: QOpenScrollViewH): Integer; cdecl;

procedure QClxDesign_setDesignOptions(); cdecl;

function QOpenMultiLineEdit_create(parent: QWidgetH; name: PAnsiChar): QOpenMultiLineEditH; cdecl;
procedure QOpenMultiLineEdit_destroy(handle: QOpenMultiLineEditH); cdecl;
function QOpenMultiLineEdit_hasMarkedText(handle: QOpenMultiLineEditH): Boolean; cdecl;
procedure QOpenMultiLineEdit_markedText(handle: QOpenMultiLineEditH; retval: PWideString); cdecl;
function QOpenMultiLineEdit_textWidth(handle: QOpenMultiLineEditH; i: Integer): Integer; overload; cdecl;
function QOpenMultiLineEdit_textWidth(handle: QOpenMultiLineEditH; text: PWideString): Integer; overload; cdecl;
procedure QOpenMultiLineEdit_cursorPoint(handle: QOpenMultiLineEditH; retval: PPoint); cdecl;
procedure QOpenMultiLineEdit_insert(handle: QOpenMultiLineEditH; text: PWideString; mark: Boolean); cdecl;
procedure QOpenMultiLineEdit_newLine(handle: QOpenMultiLineEditH); cdecl;
procedure QOpenMultiLineEdit_killLine(handle: QOpenMultiLineEditH); cdecl;
procedure QOpenMultiLineEdit_pageUp(handle: QOpenMultiLineEditH; mark: Boolean); cdecl;
procedure QOpenMultiLineEdit_pageDown(handle: QOpenMultiLineEditH; mark: Boolean); cdecl;
procedure QOpenMultiLineEdit_cursorLeft(handle: QOpenMultiLineEditH; mark: Boolean; wrap: Boolean); cdecl;
procedure QOpenMultiLineEdit_cursorRight(handle: QOpenMultiLineEditH; mark: Boolean; wrap: Boolean); cdecl;
procedure QOpenMultiLineEdit_cursorUp(handle: QOpenMultiLineEditH; mark: Boolean); cdecl;
procedure QOpenMultiLineEdit_cursorDown(handle: QOpenMultiLineEditH; mark: Boolean); cdecl;
procedure QOpenMultiLineEdit_backspace(handle: QOpenMultiLineEditH); cdecl;
procedure QOpenMultiLineEdit_del(handle: QOpenMultiLineEditH); cdecl;
procedure QOpenMultiLineEdit_home(handle: QOpenMultiLineEditH; mark: Boolean); cdecl;
procedure QOpenMultiLineEdit_end(handle: QOpenMultiLineEditH; mark: Boolean); cdecl;
function QOpenMultiLineEdit_getMarkedRegion(handle: QOpenMultiLineEditH; line1: PInteger; col1: PInteger; line2: PInteger; col2: PInteger): Boolean; cdecl;
function QOpenMultiLineEdit_lineLength(handle: QOpenMultiLineEditH; row: Integer): Integer; cdecl;
function QOpenMultiLineEdit_getString(handle: QOpenMultiLineEditH; row: Integer): PAnsiChar; cdecl;
procedure QOpenMultiLineEdit_stringShown(handle: QOpenMultiLineEditH; retval: PWideString; row: Integer); cdecl;
function QOpenMultiLineEdit_textLength(handle: QOpenMultiLineEditH): Integer; cdecl;
function QOpenMultiLineEdit_isEndOfParagraph(handle: QOpenMultiLineEditH; row: Integer): Boolean; cdecl;
procedure QOpenMultiLineEdit_getText(handle: QOpenMultiLineEditH; retval: PWideString); cdecl;
function QOpenMultiLineEdit_tableFlags(handle: QOpenMultiLineEditH): Cardinal; cdecl;
function QOpenMultiLineEdit_testTableFlags(handle: QOpenMultiLineEditH; f: Cardinal): Boolean; cdecl;
procedure QOpenMultiLineEdit_setTableFlags(handle: QOpenMultiLineEditH; f: Cardinal); cdecl;
procedure QOpenMultiLineEdit_clearTableFlags(handle: QOpenMultiLineEditH; f: Cardinal); cdecl;

function QClxFileIconProvider_create(parent: QObjectH; name: PAnsiChar): QClxFileIconProviderH; cdecl;
procedure QClxFileIconProvider_destroy(handle: QClxFileIconProviderH); cdecl;
function QClxFileIconProvider_pixmap(handle: QClxFileIconProviderH; p1: QFileInfoH): QPixmapH; cdecl;

procedure QClxFilePreview_destroy(handle: QClxFilePreviewH); cdecl;

function QClxFileDialog_create(dirName: PWideString; filter: PWideString; parent: QWidgetH; name: PAnsiChar; modal: Boolean): QClxFileDialogH; overload; cdecl;
procedure QClxFileDialog_destroy(handle: QClxFileDialogH); cdecl;
function QClxFileDialog_create(parent: QWidgetH; name: PAnsiChar; modal: Boolean): QClxFileDialogH; overload; cdecl;
function QClxFileDialog_create(parent: QWidgetH; modal: Boolean; f: WFlags): QClxFileDialogH; overload; cdecl;
procedure QClxFileDialog_getOpenFileName(retval: PWideString; initially: PWideString; filter: PWideString; parent: QWidgetH; name: PAnsiChar); overload; cdecl;
procedure QClxFileDialog_getOpenFileName(retval: PWideString; initially: PWideString; filter: PWideString; parent: QWidgetH; name: PAnsiChar; caption: PWideString); overload; cdecl;
procedure QClxFileDialog_getSaveFileName(retval: PWideString; initially: PWideString; filter: PWideString; parent: QWidgetH; name: PAnsiChar); overload; cdecl;
procedure QClxFileDialog_getSaveFileName(retval: PWideString; initially: PWideString; filter: PWideString; parent: QWidgetH; name: PAnsiChar; caption: PWideString); overload; cdecl;
procedure QClxFileDialog_getExistingDirectory(retval: PWideString; dir: PWideString; parent: QWidgetH; name: PAnsiChar); overload; cdecl;
procedure QClxFileDialog_getExistingDirectory(retval: PWideString; dir: PWideString; parent: QWidgetH; name: PAnsiChar; caption: PWideString); overload; cdecl;
procedure QClxFileDialog_getExistingDirectory(retval: PWideString; dir: PWideString; parent: QWidgetH; name: PAnsiChar; caption: PWideString; dirOnly: Boolean); overload; cdecl;
procedure QClxFileDialog_getOpenFileNames(retval: QStringListH; filter: PWideString; dir: PWideString; parent: QWidgetH; name: PAnsiChar); overload; cdecl;
procedure QClxFileDialog_getOpenFileNames(retval: QStringListH; filter: PWideString; dir: PWideString; parent: QWidgetH; name: PAnsiChar; caption: PWideString); overload; cdecl;
procedure QClxFileDialog_setIconProvider(p1: QClxFileIconProviderH); cdecl;
function QClxFileDialog_iconProvider(): QClxFileIconProviderH; cdecl;
procedure QClxFileDialog_selectedFile(handle: QClxFileDialogH; retval: PWideString); cdecl;
procedure QClxFileDialog_selectedFilter(handle: QClxFileDialogH; retval: PWideString); cdecl;
procedure QClxFileDialog_setSelection(handle: QClxFileDialogH; p1: PWideString); cdecl;
procedure QClxFileDialog_selectAll(handle: QClxFileDialogH; b: Boolean); cdecl;
procedure QClxFileDialog_selectedFiles(handle: QClxFileDialogH; retval: QStringListH); cdecl;
procedure QClxFileDialog_dirPath(handle: QClxFileDialogH; retval: PWideString); cdecl;
procedure QClxFileDialog_setDir(handle: QClxFileDialogH; p1: QDirH); overload; cdecl;
function QClxFileDialog_dir(handle: QClxFileDialogH): QDirH; cdecl;
procedure QClxFileDialog_setShowHiddenFiles(handle: QClxFileDialogH; s: Boolean); cdecl;
function QClxFileDialog_showHiddenFiles(handle: QClxFileDialogH): Boolean; cdecl;
procedure QClxFileDialog_rereadDir(handle: QClxFileDialogH); cdecl;
procedure QClxFileDialog_resortDir(handle: QClxFileDialogH); cdecl;
procedure QClxFileDialog_setMode(handle: QClxFileDialogH; p1: QClxFileDialogMode); cdecl;
function QClxFileDialog_mode(handle: QClxFileDialogH): QClxFileDialogMode; cdecl;
procedure QClxFileDialog_setViewMode(handle: QClxFileDialogH; m: QClxFileDialogViewMode); cdecl;
function QClxFileDialog_viewMode(handle: QClxFileDialogH): QClxFileDialogViewMode; cdecl;
procedure QClxFileDialog_setPreviewMode(handle: QClxFileDialogH; m: QClxFileDialogPreviewMode); cdecl;
function QClxFileDialog_previewMode(handle: QClxFileDialogH): QClxFileDialogPreviewMode; cdecl;
function QClxFileDialog_eventFilter(handle: QClxFileDialogH; p1: QObjectH; p2: QEventH): Boolean; cdecl;
function QClxFileDialog_isInfoPreviewEnabled(handle: QClxFileDialogH): Boolean; cdecl;
function QClxFileDialog_isContentsPreviewEnabled(handle: QClxFileDialogH): Boolean; cdecl;
procedure QClxFileDialog_setInfoPreviewEnabled(handle: QClxFileDialogH; p1: Boolean); cdecl;
procedure QClxFileDialog_setContentsPreviewEnabled(handle: QClxFileDialogH; p1: Boolean); cdecl;
procedure QClxFileDialog_setInfoPreview(handle: QClxFileDialogH; w: QWidgetH; preview: QClxFilePreviewH); cdecl;
procedure QClxFileDialog_setContentsPreview(handle: QClxFileDialogH; w: QWidgetH; preview: QClxFilePreviewH); cdecl;

procedure QClxFileDialog_setEditText(handle: QClxFileDialogH; s: PWideString); cdecl;
procedure QClxFileDialog_setFilterIndex(handle: QClxFileDialogH; index: Integer); cdecl;
procedure QClxFileDialog_hook_addFile(handle: QClxFileDialogH; hook: QHookH); cdecl;
procedure QClxFileDialog_selectedExt(handle: QClxFileDialogH; retval: PWideString); cdecl;
procedure QClxFileDialog_setDefaultExt(handle: QClxFileDialogH; ext: PWideString); cdecl;
procedure QClxFileDialog_defaultExt(handle: QClxFileDialogH; retval: PWideString); cdecl;
function QClxFileDialog_isRegisteredExtension(handle: QClxFileDialogH; ext: PWideString): Boolean; cdecl;
procedure QClxFileDialog_done(handle: QClxFileDialogH; p1: Integer); cdecl;
procedure QClxFileDialog_setDir(handle: QClxFileDialogH; p1: PWideString); overload; cdecl;

procedure QClxFileDialog_setFilter(handle: QClxFileDialogH; p1: PWideString); cdecl;
procedure QClxFileDialog_setFilters(handle: QClxFileDialogH; p1: PWideString); overload; cdecl;
procedure QClxFileDialog_setFilters(handle: QClxFileDialogH; p1: PPAnsiChar); overload; cdecl;
procedure QClxFileDialog_setFilters(handle: QClxFileDialogH; p1: QStringListH); overload; cdecl;
procedure QClxFileDialog_show(handle: QClxFileDialogH); cdecl;

function QOpenTableView_numRows(handle: QOpenTableViewH): Integer; cdecl;
procedure QOpenTableView_setNumRows(handle: QOpenTableViewH; r: Integer); cdecl;
function QOpenTableView_numCols(handle: QOpenTableViewH): Integer; cdecl;
procedure QOpenTableView_setNumCols(handle: QOpenTableViewH; c: Integer); cdecl;
function QOpenTableView_topCell(handle: QOpenTableViewH): Integer; cdecl;
procedure QOpenTableView_setTopCell(handle: QOpenTableViewH; row: Integer); cdecl;
function QOpenTableView_leftCell(handle: QOpenTableViewH): Integer; cdecl;
procedure QOpenTableView_setLeftCell(handle: QOpenTableViewH; col: Integer); cdecl;
procedure QOpenTableView_setTopLeftCell(handle: QOpenTableViewH; row: Integer; col: Integer); cdecl;
function QOpenTableView_xOffset(handle: QOpenTableViewH): Integer; cdecl;
procedure QOpenTableView_setXOffset(handle: QOpenTableViewH; xofs: Integer); cdecl;
function QOpenTableView_yOffset(handle: QOpenTableViewH): Integer; cdecl;
procedure QOpenTableView_setYOffset(handle: QOpenTableViewH; yofs: Integer); cdecl;
procedure QOpenTableView_setOffset(handle: QOpenTableViewH; x: Integer; y: Integer; updateScrBars: Boolean); cdecl;
function QOpenTableView_cellWidth(handle: QOpenTableViewH; col: Integer): Integer; overload; cdecl;
function QOpenTableView_cellHeight(handle: QOpenTableViewH; row: Integer): Integer; overload; cdecl;
function QOpenTableView_cellWidth(handle: QOpenTableViewH): Integer; overload; cdecl;
function QOpenTableView_cellHeight(handle: QOpenTableViewH): Integer; overload; cdecl;
procedure QOpenTableView_setCellWidth(handle: QOpenTableViewH; w: Integer); cdecl;
procedure QOpenTableView_setCellHeight(handle: QOpenTableViewH; h: Integer); cdecl;
function QOpenTableView_totalWidth(handle: QOpenTableViewH): Integer; cdecl;
function QOpenTableView_totalHeight(handle: QOpenTableViewH): Integer; cdecl;
function QOpenTableView_tableFlags(handle: QOpenTableViewH): Cardinal; cdecl;
function QOpenTableView_testTableFlags(handle: QOpenTableViewH; f: Cardinal): Boolean; cdecl;
procedure QOpenTableView_setTableFlags(handle: QOpenTableViewH; f: Cardinal); cdecl;
procedure QOpenTableView_clearTableFlags(handle: QOpenTableViewH; f: Cardinal); cdecl;
function QOpenTableView_autoUpdate(handle: QOpenTableViewH): Boolean; cdecl;
procedure QOpenTableView_setAutoUpdate(handle: QOpenTableViewH; b: Boolean); cdecl;
procedure QOpenTableView_updateCell(handle: QOpenTableViewH; row: Integer; column: Integer; erase: Boolean); cdecl;
procedure QOpenTableView_cellUpdateRect(handle: QOpenTableViewH; retval: PRect); cdecl;
procedure QOpenTableView_viewRect(handle: QOpenTableViewH; retval: PRect); cdecl;
function QOpenTableView_lastRowVisible(handle: QOpenTableViewH): Integer; cdecl;
function QOpenTableView_lastColVisible(handle: QOpenTableViewH): Integer; cdecl;
function QOpenTableView_rowIsVisible(handle: QOpenTableViewH; row: Integer): Boolean; cdecl;
function QOpenTableView_colIsVisible(handle: QOpenTableViewH; col: Integer): Boolean; cdecl;
function QOpenTableView_verticalScrollBar(handle: QOpenTableViewH): QScrollBarH; cdecl;
function QOpenTableView_horizontalScrollBar(handle: QOpenTableViewH): QScrollBarH; cdecl;
procedure QOpenTableView_scroll(handle: QOpenTableViewH; xPixels: Integer; yPixels: Integer); cdecl;
procedure QOpenTableView_updateScrollBars(handle: QOpenTableViewH); cdecl;
procedure QOpenTableView_updateTableSize(handle: QOpenTableViewH); cdecl;

type
  QObject_destroyed_Event = procedure () of object cdecl;

type
  QApplication_lastWindowClosed_Event = procedure () of object cdecl;
  QApplication_aboutToQuit_Event = procedure () of object cdecl;
  QApplication_guiThreadAwake_Event = procedure () of object cdecl;

type
  QButton_pressed_Event = procedure () of object cdecl;
  QButton_released_Event = procedure () of object cdecl;
  QButton_clicked_Event = procedure () of object cdecl;
  QButton_toggled_Event = procedure (p1: Boolean) of object cdecl;
  QButton_stateChanged_Event = procedure (p1: Integer) of object cdecl;

type
  QComboBox_activated_Event = procedure (index: Integer) of object cdecl;
  QComboBox_highlighted_Event = procedure (index: Integer) of object cdecl;
  QComboBox_activated2_Event = procedure (p1: PWideString) of object cdecl;
  QComboBox_highlighted2_Event = procedure (p1: PWideString) of object cdecl;
  QComboBox_textChanged_Event = procedure (p1: PWideString) of object cdecl;

type
  QIconView_selectionChanged_Event = procedure () of object cdecl;
  QIconView_selectionChanged2_Event = procedure (item: QIconViewItemH) of object cdecl;
  QIconView_currentChanged_Event = procedure (item: QIconViewItemH) of object cdecl;
  QIconView_clicked_Event = procedure (p1: QIconViewItemH) of object cdecl;
  QIconView_clicked2_Event = procedure (p1: QIconViewItemH; p2: PPoint) of object cdecl;
  QIconView_pressed_Event = procedure (p1: QIconViewItemH) of object cdecl;
  QIconView_pressed2_Event = procedure (p1: QIconViewItemH; p2: PPoint) of object cdecl;
  QIconView_doubleClicked_Event = procedure (item: QIconViewItemH) of object cdecl;
  QIconView_returnPressed_Event = procedure (item: QIconViewItemH) of object cdecl;
  QIconView_rightButtonClicked_Event = procedure (item: QIconViewItemH; pos: PPoint) of object cdecl;
  QIconView_rightButtonPressed_Event = procedure (item: QIconViewItemH; pos: PPoint) of object cdecl;
  QIconView_mouseButtonPressed_Event = procedure (button: Integer; item: QIconViewItemH; pos: PPoint) of object cdecl;
  QIconView_mouseButtonClicked_Event = procedure (button: Integer; item: QIconViewItemH; pos: PPoint) of object cdecl;
  QIconView_dropped_Event = procedure (e: QDropEventH; lst: Pointer) of object cdecl;
  QIconView_moved_Event = procedure () of object cdecl;
  QIconView_onItem_Event = procedure (item: QIconViewItemH) of object cdecl;
  QIconView_onViewport_Event = procedure () of object cdecl;
  QIconView_itemRenamed_Event = procedure (item: QIconViewItemH; p2: PWideString) of object cdecl;
  QIconView_itemRenamed2_Event = procedure (item: QIconViewItemH) of object cdecl;

type
  QLCDNumber_overflow_Event = procedure () of object cdecl;

type
  QLineEdit_textChanged_Event = procedure (p1: PWideString) of object cdecl;
  QLineEdit_returnPressed_Event = procedure () of object cdecl;

type
  QListBox_highlighted_Event = procedure (index: Integer) of object cdecl;
  QListBox_selected_Event = procedure (index: Integer) of object cdecl;
  QListBox_highlighted2_Event = procedure (p1: PWideString) of object cdecl;
  QListBox_selected2_Event = procedure (p1: PWideString) of object cdecl;
  QListBox_highlighted3_Event = procedure (p1: QListBoxItemH) of object cdecl;
  QListBox_selected3_Event = procedure (p1: QListBoxItemH) of object cdecl;
  QListBox_selectionChanged_Event = procedure () of object cdecl;
  QListBox_selectionChanged2_Event = procedure (p1: QListBoxItemH) of object cdecl;
  QListBox_currentChanged_Event = procedure (p1: QListBoxItemH) of object cdecl;
  QListBox_clicked_Event = procedure (p1: QListBoxItemH) of object cdecl;
  QListBox_clicked2_Event = procedure (p1: QListBoxItemH; p2: PPoint) of object cdecl;
  QListBox_pressed_Event = procedure (p1: QListBoxItemH) of object cdecl;
  QListBox_pressed2_Event = procedure (p1: QListBoxItemH; p2: PPoint) of object cdecl;
  QListBox_doubleClicked_Event = procedure (p1: QListBoxItemH) of object cdecl;
  QListBox_returnPressed_Event = procedure (p1: QListBoxItemH) of object cdecl;
  QListBox_rightButtonClicked_Event = procedure (p1: QListBoxItemH; p2: PPoint) of object cdecl;
  QListBox_rightButtonPressed_Event = procedure (p1: QListBoxItemH; p2: PPoint) of object cdecl;
  QListBox_mouseButtonPressed_Event = procedure (p1: Integer; p2: QListBoxItemH; p3: PPoint) of object cdecl;
  QListBox_mouseButtonClicked_Event = procedure (p1: Integer; p2: QListBoxItemH; p3: PPoint) of object cdecl;
  QListBox_onItem_Event = procedure (item: QListBoxItemH) of object cdecl;
  QListBox_onViewport_Event = procedure () of object cdecl;

type
  QListView_selectionChanged_Event = procedure () of object cdecl;
  QListView_selectionChanged2_Event = procedure (p1: QListViewItemH) of object cdecl;
  QListView_currentChanged_Event = procedure (p1: QListViewItemH) of object cdecl;
  QListView_clicked_Event = procedure (p1: QListViewItemH) of object cdecl;
  QListView_clicked2_Event = procedure (p1: QListViewItemH; p2: PPoint; p3: Integer) of object cdecl;
  QListView_pressed_Event = procedure (p1: QListViewItemH) of object cdecl;
  QListView_pressed2_Event = procedure (p1: QListViewItemH; p2: PPoint; p3: Integer) of object cdecl;
  QListView_doubleClicked_Event = procedure (p1: QListViewItemH) of object cdecl;
  QListView_returnPressed_Event = procedure (p1: QListViewItemH) of object cdecl;
  QListView_rightButtonClicked_Event = procedure (p1: QListViewItemH; p2: PPoint; p3: Integer) of object cdecl;
  QListView_rightButtonPressed_Event = procedure (p1: QListViewItemH; p2: PPoint; p3: Integer) of object cdecl;
  QListView_mouseButtonPressed_Event = procedure (p1: Integer; p2: QListViewItemH; p3: PPoint; p4: Integer) of object cdecl;
  QListView_mouseButtonClicked_Event = procedure (p1: Integer; p2: QListViewItemH; p3: PPoint; p4: Integer) of object cdecl;
  QListView_onItem_Event = procedure (item: QListViewItemH) of object cdecl;
  QListView_onViewport_Event = procedure () of object cdecl;
  QListView_expanded_Event = procedure (item: QListViewItemH) of object cdecl;
  QListView_collapsed_Event = procedure (item: QListViewItemH) of object cdecl;

type
  QMenuBar_activated_Event = procedure (itemId: Integer) of object cdecl;
  QMenuBar_highlighted_Event = procedure (itemId: Integer) of object cdecl;

type
  QMultiLineEdit_textChanged_Event = procedure () of object cdecl;
  QMultiLineEdit_returnPressed_Event = procedure () of object cdecl;
  QMultiLineEdit_undoAvailable_Event = procedure (p1: Boolean) of object cdecl;
  QMultiLineEdit_redoAvailable_Event = procedure (p1: Boolean) of object cdecl;
  QMultiLineEdit_copyAvailable_Event = procedure (p1: Boolean) of object cdecl;

type
  QScrollView_contentsMoving_Event = procedure (x: Integer; y: Integer) of object cdecl;

type
  QSlider_valueChanged_Event = procedure (value: Integer) of object cdecl;
  QSlider_sliderPressed_Event = procedure () of object cdecl;
  QSlider_sliderMoved_Event = procedure (value: Integer) of object cdecl;
  QSlider_sliderReleased_Event = procedure () of object cdecl;

type
  QSocketNotifier_activated_Event = procedure (socket: Integer) of object cdecl;

type
  QSpinBox_valueChanged_Event = procedure (value: Integer) of object cdecl;
  QSpinBox_valueChanged2_Event = procedure (valueText: PWideString) of object cdecl;

type
  QButtonGroup_pressed_Event = procedure (id: Integer) of object cdecl;
  QButtonGroup_released_Event = procedure (id: Integer) of object cdecl;
  QButtonGroup_clicked_Event = procedure (id: Integer) of object cdecl;

type
  QClipboard_dataChanged_Event = procedure () of object cdecl;

type
  QFontDialog_fontSelected_Event = procedure (font: QFontH) of object cdecl;
  QFontDialog_fontHighlighted_Event = procedure (font: QFontH) of object cdecl;

type
  QHeader_clicked_Event = procedure (section: Integer) of object cdecl;
  QHeader_pressed_Event = procedure (section: Integer) of object cdecl;
  QHeader_released_Event = procedure (section: Integer) of object cdecl;
  QHeader_sizeChange_Event = procedure (section: Integer; oldSize: Integer; newSize: Integer) of object cdecl;
  QHeader_indexChange_Event = procedure (section: Integer; fromIndex: Integer; _toIndex: Integer) of object cdecl;
  QHeader_sectionClicked_Event = procedure (p1: Integer) of object cdecl;
  QHeader_moved_Event = procedure (p1: Integer; p2: Integer) of object cdecl;

type
  QPopupMenu_activated_Event = procedure (itemId: Integer) of object cdecl;
  QPopupMenu_highlighted_Event = procedure (itemId: Integer) of object cdecl;
  QPopupMenu_activatedRedirect_Event = procedure (itemId: Integer) of object cdecl;
  QPopupMenu_highlightedRedirect_Event = procedure (itemId: Integer) of object cdecl;
  QPopupMenu_aboutToShow_Event = procedure () of object cdecl;
  QPopupMenu_aboutToHide_Event = procedure () of object cdecl;

type
  QScrollBar_valueChanged_Event = procedure (value: Integer) of object cdecl;
  QScrollBar_sliderPressed_Event = procedure () of object cdecl;
  QScrollBar_sliderMoved_Event = procedure (value: Integer) of object cdecl;
  QScrollBar_sliderReleased_Event = procedure () of object cdecl;
  QScrollBar_nextLine_Event = procedure () of object cdecl;
  QScrollBar_prevLine_Event = procedure () of object cdecl;
  QScrollBar_nextPage_Event = procedure () of object cdecl;
  QScrollBar_prevPage_Event = procedure () of object cdecl;

type
  QTextBrowser_backwardAvailable_Event = procedure (p1: Boolean) of object cdecl;
  QTextBrowser_forwardAvailable_Event = procedure (p1: Boolean) of object cdecl;
  QTextBrowser_highlighted_Event = procedure (p1: PWideString) of object cdecl;
  QTextBrowser_textChanged_Event = procedure () of object cdecl;

type
  QTimer_timeout_Event = procedure () of object cdecl;

type
  QWorkspace_windowActivated_Event = procedure (w: QWidgetH) of object cdecl;

type
  QClxFileDialog_fileHighlighted_Event = procedure (p1: PWideString) of object cdecl;
  QClxFileDialog_fileSelected_Event = procedure (p1: PWideString) of object cdecl;
  QClxFileDialog_dirEntered_Event = procedure (p1: PWideString) of object cdecl;
  QClxFileDialog_closeRequest_Event = procedure (canClose: PBoolean) of object cdecl;
  QClxFileDialog_filterChanged_Event = procedure (index: Integer) of object cdecl;

function QObject_hook_create(handle: QObjectH): QObject_hookH; cdecl;
procedure QObject_hook_destroy(handle: QObject_hookH); cdecl;
procedure QObject_hook_hook_destroyed(handle: QObject_hookH; hook: QHookH); cdecl;

function QSenderObject_hook_create(handle: QObjectH): QSenderObject_hookH; cdecl;
procedure QSenderObject_hook_destroy(handle: QSenderObject_hookH); cdecl;

function QWidget_hook_create(handle: QObjectH): QWidget_hookH; cdecl;
procedure QWidget_hook_destroy(handle: QWidget_hookH); cdecl;

function QApplication_hook_create(handle: QObjectH): QApplication_hookH; cdecl;
procedure QApplication_hook_destroy(handle: QApplication_hookH); cdecl;
procedure QApplication_hook_hook_lastWindowClosed(handle: QApplication_hookH; hook: QHookH); cdecl;
procedure QApplication_hook_hook_aboutToQuit(handle: QApplication_hookH; hook: QHookH); cdecl;
procedure QApplication_hook_hook_guiThreadAwake(handle: QApplication_hookH; hook: QHookH); cdecl;

function QButton_hook_create(handle: QObjectH): QButton_hookH; cdecl;
procedure QButton_hook_destroy(handle: QButton_hookH); cdecl;
procedure QButton_hook_hook_pressed(handle: QButton_hookH; hook: QHookH); cdecl;
procedure QButton_hook_hook_released(handle: QButton_hookH; hook: QHookH); cdecl;
procedure QButton_hook_hook_clicked(handle: QButton_hookH; hook: QHookH); cdecl;
procedure QButton_hook_hook_toggled(handle: QButton_hookH; hook: QHookH); cdecl;
procedure QButton_hook_hook_stateChanged(handle: QButton_hookH; hook: QHookH); cdecl;

function QComboBox_hook_create(handle: QObjectH): QComboBox_hookH; cdecl;
procedure QComboBox_hook_destroy(handle: QComboBox_hookH); cdecl;
procedure QComboBox_hook_hook_activated(handle: QComboBox_hookH; hook: QHookH); cdecl;
procedure QComboBox_hook_hook_highlighted(handle: QComboBox_hookH; hook: QHookH); cdecl;
procedure QComboBox_hook_hook_activated2(handle: QComboBox_hookH; hook: QHookH); cdecl;
procedure QComboBox_hook_hook_highlighted2(handle: QComboBox_hookH; hook: QHookH); cdecl;
procedure QComboBox_hook_hook_textChanged(handle: QComboBox_hookH; hook: QHookH); cdecl;

function QDialog_hook_create(handle: QObjectH): QDialog_hookH; cdecl;
procedure QDialog_hook_destroy(handle: QDialog_hookH); cdecl;

function QDragObject_hook_create(handle: QObjectH): QDragObject_hookH; cdecl;
procedure QDragObject_hook_destroy(handle: QDragObject_hookH); cdecl;

function QStoredDrag_hook_create(handle: QObjectH): QStoredDrag_hookH; cdecl;
procedure QStoredDrag_hook_destroy(handle: QStoredDrag_hookH); cdecl;

function QTextDrag_hook_create(handle: QObjectH): QTextDrag_hookH; cdecl;
procedure QTextDrag_hook_destroy(handle: QTextDrag_hookH); cdecl;

function QImageDrag_hook_create(handle: QObjectH): QImageDrag_hookH; cdecl;
procedure QImageDrag_hook_destroy(handle: QImageDrag_hookH); cdecl;

function QUriDrag_hook_create(handle: QObjectH): QUriDrag_hookH; cdecl;
procedure QUriDrag_hook_destroy(handle: QUriDrag_hookH); cdecl;

function QColorDrag_hook_create(handle: QObjectH): QColorDrag_hookH; cdecl;
procedure QColorDrag_hook_destroy(handle: QColorDrag_hookH); cdecl;

function QEvent_hook_create(handle: QObjectH): QEvent_hookH; cdecl;
procedure QEvent_hook_destroy(handle: QEvent_hookH); cdecl;

function QTimerEvent_hook_create(handle: QObjectH): QTimerEvent_hookH; cdecl;
procedure QTimerEvent_hook_destroy(handle: QTimerEvent_hookH); cdecl;

function QMouseEvent_hook_create(handle: QObjectH): QMouseEvent_hookH; cdecl;
procedure QMouseEvent_hook_destroy(handle: QMouseEvent_hookH); cdecl;

function QWheelEvent_hook_create(handle: QObjectH): QWheelEvent_hookH; cdecl;
procedure QWheelEvent_hook_destroy(handle: QWheelEvent_hookH); cdecl;

function QKeyEvent_hook_create(handle: QObjectH): QKeyEvent_hookH; cdecl;
procedure QKeyEvent_hook_destroy(handle: QKeyEvent_hookH); cdecl;

function QFocusEvent_hook_create(handle: QObjectH): QFocusEvent_hookH; cdecl;
procedure QFocusEvent_hook_destroy(handle: QFocusEvent_hookH); cdecl;

function QPaintEvent_hook_create(handle: QObjectH): QPaintEvent_hookH; cdecl;
procedure QPaintEvent_hook_destroy(handle: QPaintEvent_hookH); cdecl;

function QMoveEvent_hook_create(handle: QObjectH): QMoveEvent_hookH; cdecl;
procedure QMoveEvent_hook_destroy(handle: QMoveEvent_hookH); cdecl;

function QResizeEvent_hook_create(handle: QObjectH): QResizeEvent_hookH; cdecl;
procedure QResizeEvent_hook_destroy(handle: QResizeEvent_hookH); cdecl;

function QCloseEvent_hook_create(handle: QObjectH): QCloseEvent_hookH; cdecl;
procedure QCloseEvent_hook_destroy(handle: QCloseEvent_hookH); cdecl;

function QShowEvent_hook_create(handle: QObjectH): QShowEvent_hookH; cdecl;
procedure QShowEvent_hook_destroy(handle: QShowEvent_hookH); cdecl;

function QHideEvent_hook_create(handle: QObjectH): QHideEvent_hookH; cdecl;
procedure QHideEvent_hook_destroy(handle: QHideEvent_hookH); cdecl;

function QDropEvent_hook_create(handle: QObjectH): QDropEvent_hookH; cdecl;
procedure QDropEvent_hook_destroy(handle: QDropEvent_hookH); cdecl;

function QDragMoveEvent_hook_create(handle: QObjectH): QDragMoveEvent_hookH; cdecl;
procedure QDragMoveEvent_hook_destroy(handle: QDragMoveEvent_hookH); cdecl;

function QDragEnterEvent_hook_create(handle: QObjectH): QDragEnterEvent_hookH; cdecl;
procedure QDragEnterEvent_hook_destroy(handle: QDragEnterEvent_hookH); cdecl;

function QDragResponseEvent_hook_create(handle: QObjectH): QDragResponseEvent_hookH; cdecl;
procedure QDragResponseEvent_hook_destroy(handle: QDragResponseEvent_hookH); cdecl;

function QDragLeaveEvent_hook_create(handle: QObjectH): QDragLeaveEvent_hookH; cdecl;
procedure QDragLeaveEvent_hook_destroy(handle: QDragLeaveEvent_hookH); cdecl;

function QChildEvent_hook_create(handle: QObjectH): QChildEvent_hookH; cdecl;
procedure QChildEvent_hook_destroy(handle: QChildEvent_hookH); cdecl;

function QCustomEvent_hook_create(handle: QObjectH): QCustomEvent_hookH; cdecl;
procedure QCustomEvent_hook_destroy(handle: QCustomEvent_hookH); cdecl;

function QFrame_hook_create(handle: QObjectH): QFrame_hookH; cdecl;
procedure QFrame_hook_destroy(handle: QFrame_hookH); cdecl;

function QIconView_hook_create(handle: QObjectH): QIconView_hookH; cdecl;
procedure QIconView_hook_destroy(handle: QIconView_hookH); cdecl;
procedure QIconView_hook_hook_selectionChanged(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_selectionChanged2(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_currentChanged(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_clicked(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_clicked2(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_pressed(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_pressed2(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_doubleClicked(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_returnPressed(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_rightButtonClicked(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_rightButtonPressed(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_mouseButtonPressed(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_mouseButtonClicked(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_dropped(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_moved(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_onItem(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_onViewport(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_itemRenamed(handle: QIconView_hookH; hook: QHookH); cdecl;
procedure QIconView_hook_hook_itemRenamed2(handle: QIconView_hookH; hook: QHookH); cdecl;

function QLCDNumber_hook_create(handle: QObjectH): QLCDNumber_hookH; cdecl;
procedure QLCDNumber_hook_destroy(handle: QLCDNumber_hookH); cdecl;
procedure QLCDNumber_hook_hook_overflow(handle: QLCDNumber_hookH; hook: QHookH); cdecl;

function QLineEdit_hook_create(handle: QObjectH): QLineEdit_hookH; cdecl;
procedure QLineEdit_hook_destroy(handle: QLineEdit_hookH); cdecl;
procedure QLineEdit_hook_hook_textChanged(handle: QLineEdit_hookH; hook: QHookH); cdecl;
procedure QLineEdit_hook_hook_returnPressed(handle: QLineEdit_hookH; hook: QHookH); cdecl;

function QListBox_hook_create(handle: QObjectH): QListBox_hookH; cdecl;
procedure QListBox_hook_destroy(handle: QListBox_hookH); cdecl;
procedure QListBox_hook_hook_highlighted(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_selected(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_highlighted2(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_selected2(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_highlighted3(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_selected3(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_selectionChanged(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_selectionChanged2(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_currentChanged(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_clicked(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_clicked2(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_pressed(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_pressed2(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_doubleClicked(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_returnPressed(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_rightButtonClicked(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_rightButtonPressed(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_mouseButtonPressed(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_mouseButtonClicked(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_onItem(handle: QListBox_hookH; hook: QHookH); cdecl;
procedure QListBox_hook_hook_onViewport(handle: QListBox_hookH; hook: QHookH); cdecl;

function QListViewItem_hook_create(handle: QObjectH): QListViewItem_hookH; cdecl;
procedure QListViewItem_hook_destroy(handle: QListViewItem_hookH); cdecl;

function QListView_hook_create(handle: QObjectH): QListView_hookH; cdecl;
procedure QListView_hook_destroy(handle: QListView_hookH); cdecl;
procedure QListView_hook_hook_selectionChanged(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_selectionChanged2(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_currentChanged(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_clicked(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_clicked2(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_pressed(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_pressed2(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_doubleClicked(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_returnPressed(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_rightButtonClicked(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_rightButtonPressed(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_mouseButtonPressed(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_mouseButtonClicked(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_onItem(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_onViewport(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_expanded(handle: QListView_hookH; hook: QHookH); cdecl;
procedure QListView_hook_hook_collapsed(handle: QListView_hookH; hook: QHookH); cdecl;

function QCheckListItem_hook_create(handle: QObjectH): QCheckListItem_hookH; cdecl;
procedure QCheckListItem_hook_destroy(handle: QCheckListItem_hookH); cdecl;

function QMenuBar_hook_create(handle: QObjectH): QMenuBar_hookH; cdecl;
procedure QMenuBar_hook_destroy(handle: QMenuBar_hookH); cdecl;
procedure QMenuBar_hook_hook_activated(handle: QMenuBar_hookH; hook: QHookH); cdecl;
procedure QMenuBar_hook_hook_highlighted(handle: QMenuBar_hookH; hook: QHookH); cdecl;

function QMessageBox_hook_create(handle: QObjectH): QMessageBox_hookH; cdecl;
procedure QMessageBox_hook_destroy(handle: QMessageBox_hookH); cdecl;

function QMultiLineEdit_hook_create(handle: QObjectH): QMultiLineEdit_hookH; cdecl;
procedure QMultiLineEdit_hook_destroy(handle: QMultiLineEdit_hookH); cdecl;
procedure QMultiLineEdit_hook_hook_textChanged(handle: QMultiLineEdit_hookH; hook: QHookH); cdecl;
procedure QMultiLineEdit_hook_hook_returnPressed(handle: QMultiLineEdit_hookH; hook: QHookH); cdecl;
procedure QMultiLineEdit_hook_hook_undoAvailable(handle: QMultiLineEdit_hookH; hook: QHookH); cdecl;
procedure QMultiLineEdit_hook_hook_redoAvailable(handle: QMultiLineEdit_hookH; hook: QHookH); cdecl;
procedure QMultiLineEdit_hook_hook_copyAvailable(handle: QMultiLineEdit_hookH; hook: QHookH); cdecl;

function QScrollView_hook_create(handle: QObjectH): QScrollView_hookH; cdecl;
procedure QScrollView_hook_destroy(handle: QScrollView_hookH); cdecl;
procedure QScrollView_hook_hook_contentsMoving(handle: QScrollView_hookH; hook: QHookH); cdecl;

function QSlider_hook_create(handle: QObjectH): QSlider_hookH; cdecl;
procedure QSlider_hook_destroy(handle: QSlider_hookH); cdecl;
procedure QSlider_hook_hook_valueChanged(handle: QSlider_hookH; hook: QHookH); cdecl;
procedure QSlider_hook_hook_sliderPressed(handle: QSlider_hookH; hook: QHookH); cdecl;
procedure QSlider_hook_hook_sliderMoved(handle: QSlider_hookH; hook: QHookH); cdecl;
procedure QSlider_hook_hook_sliderReleased(handle: QSlider_hookH; hook: QHookH); cdecl;

function QSocketNotifier_hook_create(handle: QObjectH): QSocketNotifier_hookH; cdecl;
procedure QSocketNotifier_hook_destroy(handle: QSocketNotifier_hookH); cdecl;
procedure QSocketNotifier_hook_hook_activated(handle: QSocketNotifier_hookH; hook: QHookH); cdecl;

function QSpinBox_hook_create(handle: QObjectH): QSpinBox_hookH; cdecl;
procedure QSpinBox_hook_destroy(handle: QSpinBox_hookH); cdecl;
procedure QSpinBox_hook_hook_valueChanged(handle: QSpinBox_hookH; hook: QHookH); cdecl;
procedure QSpinBox_hook_hook_valueChanged2(handle: QSpinBox_hookH; hook: QHookH); cdecl;

function QStyle_hook_create(handle: QObjectH): QStyle_hookH; cdecl;
procedure QStyle_hook_destroy(handle: QStyle_hookH); cdecl;

function QTranslator_hook_create(handle: QObjectH): QTranslator_hookH; cdecl;
procedure QTranslator_hook_destroy(handle: QTranslator_hookH); cdecl;

function QBrush_hook_create(handle: QObjectH): QBrush_hookH; cdecl;
procedure QBrush_hook_destroy(handle: QBrush_hookH); cdecl;

function QButtonGroup_hook_create(handle: QObjectH): QButtonGroup_hookH; cdecl;
procedure QButtonGroup_hook_destroy(handle: QButtonGroup_hookH); cdecl;
procedure QButtonGroup_hook_hook_pressed(handle: QButtonGroup_hookH; hook: QHookH); cdecl;
procedure QButtonGroup_hook_hook_released(handle: QButtonGroup_hookH; hook: QHookH); cdecl;
procedure QButtonGroup_hook_hook_clicked(handle: QButtonGroup_hookH; hook: QHookH); cdecl;

function QCheckBox_hook_create(handle: QObjectH): QCheckBox_hookH; cdecl;
procedure QCheckBox_hook_destroy(handle: QCheckBox_hookH); cdecl;

function QClipboard_hook_create(handle: QObjectH): QClipboard_hookH; cdecl;
procedure QClipboard_hook_destroy(handle: QClipboard_hookH); cdecl;
procedure QClipboard_hook_hook_dataChanged(handle: QClipboard_hookH; hook: QHookH); cdecl;

function QColorDialog_hook_create(handle: QObjectH): QColorDialog_hookH; cdecl;
procedure QColorDialog_hook_destroy(handle: QColorDialog_hookH); cdecl;

function QCommonStyle_hook_create(handle: QObjectH): QCommonStyle_hookH; cdecl;
procedure QCommonStyle_hook_destroy(handle: QCommonStyle_hookH); cdecl;

function QFontDialog_hook_create(handle: QObjectH): QFontDialog_hookH; cdecl;
procedure QFontDialog_hook_destroy(handle: QFontDialog_hookH); cdecl;
procedure QFontDialog_hook_hook_fontSelected(handle: QFontDialog_hookH; hook: QHookH); cdecl;
procedure QFontDialog_hook_hook_fontHighlighted(handle: QFontDialog_hookH; hook: QHookH); cdecl;

function QGroupBox_hook_create(handle: QObjectH): QGroupBox_hookH; cdecl;
procedure QGroupBox_hook_destroy(handle: QGroupBox_hookH); cdecl;

function QHeader_hook_create(handle: QObjectH): QHeader_hookH; cdecl;
procedure QHeader_hook_destroy(handle: QHeader_hookH); cdecl;
procedure QHeader_hook_hook_clicked(handle: QHeader_hookH; hook: QHookH); cdecl;
procedure QHeader_hook_hook_pressed(handle: QHeader_hookH; hook: QHookH); cdecl;
procedure QHeader_hook_hook_released(handle: QHeader_hookH; hook: QHookH); cdecl;
procedure QHeader_hook_hook_sizeChange(handle: QHeader_hookH; hook: QHookH); cdecl;
procedure QHeader_hook_hook_indexChange(handle: QHeader_hookH; hook: QHookH); cdecl;
procedure QHeader_hook_hook_sectionClicked(handle: QHeader_hookH; hook: QHookH); cdecl;
procedure QHeader_hook_hook_moved(handle: QHeader_hookH; hook: QHookH); cdecl;

function QLabel_hook_create(handle: QObjectH): QLabel_hookH; cdecl;
procedure QLabel_hook_destroy(handle: QLabel_hookH); cdecl;

function QPainter_hook_create(handle: QObjectH): QPainter_hookH; cdecl;
procedure QPainter_hook_destroy(handle: QPainter_hookH); cdecl;

function QPen_hook_create(handle: QObjectH): QPen_hookH; cdecl;
procedure QPen_hook_destroy(handle: QPen_hookH); cdecl;

function QPopupMenu_hook_create(handle: QObjectH): QPopupMenu_hookH; cdecl;
procedure QPopupMenu_hook_destroy(handle: QPopupMenu_hookH); cdecl;
procedure QPopupMenu_hook_hook_activated(handle: QPopupMenu_hookH; hook: QHookH); cdecl;
procedure QPopupMenu_hook_hook_highlighted(handle: QPopupMenu_hookH; hook: QHookH); cdecl;
procedure QPopupMenu_hook_hook_activatedRedirect(handle: QPopupMenu_hookH; hook: QHookH); cdecl;
procedure QPopupMenu_hook_hook_highlightedRedirect(handle: QPopupMenu_hookH; hook: QHookH); cdecl;
procedure QPopupMenu_hook_hook_aboutToShow(handle: QPopupMenu_hookH; hook: QHookH); cdecl;
procedure QPopupMenu_hook_hook_aboutToHide(handle: QPopupMenu_hookH; hook: QHookH); cdecl;

function QPushButton_hook_create(handle: QObjectH): QPushButton_hookH; cdecl;
procedure QPushButton_hook_destroy(handle: QPushButton_hookH); cdecl;

function QRadioButton_hook_create(handle: QObjectH): QRadioButton_hookH; cdecl;
procedure QRadioButton_hook_destroy(handle: QRadioButton_hookH); cdecl;

function QScrollBar_hook_create(handle: QObjectH): QScrollBar_hookH; cdecl;
procedure QScrollBar_hook_destroy(handle: QScrollBar_hookH); cdecl;
procedure QScrollBar_hook_hook_valueChanged(handle: QScrollBar_hookH; hook: QHookH); cdecl;
procedure QScrollBar_hook_hook_sliderPressed(handle: QScrollBar_hookH; hook: QHookH); cdecl;
procedure QScrollBar_hook_hook_sliderMoved(handle: QScrollBar_hookH; hook: QHookH); cdecl;
procedure QScrollBar_hook_hook_sliderReleased(handle: QScrollBar_hookH; hook: QHookH); cdecl;
procedure QScrollBar_hook_hook_nextLine(handle: QScrollBar_hookH; hook: QHookH); cdecl;
procedure QScrollBar_hook_hook_prevLine(handle: QScrollBar_hookH; hook: QHookH); cdecl;
procedure QScrollBar_hook_hook_nextPage(handle: QScrollBar_hookH; hook: QHookH); cdecl;
procedure QScrollBar_hook_hook_prevPage(handle: QScrollBar_hookH; hook: QHookH); cdecl;

function QSizeGrip_hook_create(handle: QObjectH): QSizeGrip_hookH; cdecl;
procedure QSizeGrip_hook_destroy(handle: QSizeGrip_hookH); cdecl;

function QTableView_hook_create(handle: QObjectH): QTableView_hookH; cdecl;
procedure QTableView_hook_destroy(handle: QTableView_hookH); cdecl;

function QTextBrowser_hook_create(handle: QObjectH): QTextBrowser_hookH; cdecl;
procedure QTextBrowser_hook_destroy(handle: QTextBrowser_hookH); cdecl;
procedure QTextBrowser_hook_hook_backwardAvailable(handle: QTextBrowser_hookH; hook: QHookH); cdecl;
procedure QTextBrowser_hook_hook_forwardAvailable(handle: QTextBrowser_hookH; hook: QHookH); cdecl;
procedure QTextBrowser_hook_hook_highlighted(handle: QTextBrowser_hookH; hook: QHookH); cdecl;
procedure QTextBrowser_hook_hook_textChanged(handle: QTextBrowser_hookH; hook: QHookH); cdecl;

function QTextView_hook_create(handle: QObjectH): QTextView_hookH; cdecl;
procedure QTextView_hook_destroy(handle: QTextView_hookH); cdecl;

function QWhatsThis_hook_create(handle: QObjectH): QWhatsThis_hookH; cdecl;
procedure QWhatsThis_hook_destroy(handle: QWhatsThis_hookH); cdecl;

function QWindowsStyle_hook_create(handle: QObjectH): QWindowsStyle_hookH; cdecl;
procedure QWindowsStyle_hook_destroy(handle: QWindowsStyle_hookH); cdecl;

function QTimer_hook_create(handle: QObjectH): QTimer_hookH; cdecl;
procedure QTimer_hook_destroy(handle: QTimer_hookH); cdecl;
procedure QTimer_hook_hook_timeout(handle: QTimer_hookH; hook: QHookH); cdecl;

function QWorkspace_hook_create(handle: QObjectH): QWorkspace_hookH; cdecl;
procedure QWorkspace_hook_destroy(handle: QWorkspace_hookH); cdecl;
procedure QWorkspace_hook_hook_windowActivated(handle: QWorkspace_hookH; hook: QHookH); cdecl;

function QClxFileIconProvider_hook_create(handle: QObjectH): QClxFileIconProvider_hookH; cdecl;
procedure QClxFileIconProvider_hook_destroy(handle: QClxFileIconProvider_hookH); cdecl;

function QClxFileDialog_hook_create(handle: QObjectH): QClxFileDialog_hookH; cdecl;
procedure QClxFileDialog_hook_destroy(handle: QClxFileDialog_hookH); cdecl;
procedure QClxFileDialog_hook_hook_fileHighlighted(handle: QClxFileDialog_hookH; hook: QHookH); cdecl;
procedure QClxFileDialog_hook_hook_fileSelected(handle: QClxFileDialog_hookH; hook: QHookH); cdecl;
procedure QClxFileDialog_hook_hook_dirEntered(handle: QClxFileDialog_hookH; hook: QHookH); cdecl;
procedure QClxFileDialog_hook_hook_closeRequest(handle: QClxFileDialog_hookH; hook: QHookH); cdecl;
procedure QClxFileDialog_hook_hook_filterChanged(handle: QClxFileDialog_hookH; hook: QHookH); cdecl;

procedure InitializePAnsiString(CCPS, COPS, IPS, FPS: Pointer); cdecl;
procedure InitializePWideString(CUPS, UOPS, LOPS, IPS, FPS: Pointer); cdecl;
procedure InitializePPointArray(GPP, GPL, SPL: Pointer); cdecl;
procedure InitializePIntArray(GPP, GPL, SPL: Pointer); cdecl;

procedure bitBlt(dst: QPaintDeviceH; dp: PPoint; src: QPaintDeviceH; sr: PRect;
  rop: RasterOp); cdecl; overload;
procedure bitBlt(dst: QPaintDeviceH; dx: Integer; dy: Integer;
  src: QPaintDeviceH; sx: Integer; sy: Integer; sw: Integer; sh: Integer;
  rop: RasterOp; IgnoreMask: Boolean); cdecl; overload;

function QByteArray_create(Size: Integer): QByteArrayH; cdecl;
procedure QByteArray_destroy(ba: QByteArrayH); cdecl;

function QClxWidget_MaxWidgetSize: Cardinal; cdecl;
procedure QWorkspace_next(workspace: QWorkspaceH); cdecl;
procedure QWorkspace_previous(workspace: QWorkspaceH); cdecl;

{$IFDEF MSWINDOWS}
procedure setPopupParent(newPopupParent: Cardinal); cdecl;
{$ENDIF}

{$IFDEF LINUX}
function QtDisplay: PDisplay; cdecl;
{$ENDIF}

procedure QMimeSource_destroy(mime: QMimeSourceH); cdecl;
function QMimeSource_is_QClxMimeSource(mime: QMimeSourceH): Boolean; cdecl;

function QEvent_isQCustomEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQShowEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQTimerEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQMouseEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQWheelEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQKeyEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQFocusEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQPaintEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQMoveEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQResizeEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQCloseEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQHideEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQDropEventEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQDragMoveEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQDragEnterEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQDragResponseEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQDragLeaveEvent(e: QEventH): Boolean; cdecl;
function QEvent_isQChildEvent(e: QEventH): Boolean; cdecl;

function QObjectList_create: QObjectListH; cdecl; overload;
function QObjectList_create(list: QObjectListH): QObjectListH; cdecl; overload;
procedure QObjectList_destroy(obj: QObjectListH);
function QObjectList_count(obj: QObjectListH): Cardinal; cdecl;
function QObjectList_isEmpty(obj: QObjectListH): Boolean; cdecl;
function QObjectList_insert(obj: QObjectListH; i: Cardinal; d: QObjectH): Boolean; cdecl;
procedure QObjectList_inSort(obj: QObjectListH; d: QObjectH);
procedure QObjectList_prepend(obj: QObjectListH; d: QObjectH);
procedure QObjectList_append(obj: QObjectListH; d: QObjectH);
function QObjectList_remove(obj: QObjectListH; i: Cardinal): Boolean; cdecl; overload;
function QObjectList_remove(obj: QObjectListH): Boolean; cdecl; overload;
function QObjectList_remove(obj: QObjectListH; d: QObjectH): Boolean; cdecl; overload;
function QObjectList_removeRef(obj: QObjectListH; d: QObjectH): Boolean; cdecl;
function QObjectList_removeFirst(obj: QObjectListH): Boolean; cdecl;
function QObjectList_removeLast(obj: QObjectListH): Boolean; cdecl;
function QObjectList_take(obj: QObjectListH; i: Cardinal): QObjectH; cdecl; overload;
function QObjectList_take(obj: QObjectListH): QObjectH; cdecl; overload;
procedure QObjectList_clear(obj: QObjectListH);
procedure QObjectList_sort(obj: QObjectListH);
function QObjectList_find(obj: QObjectListH; d: QObjectH): Integer; cdecl;
function QObjectList_findNext(obj: QObjectListH; d: QObjectH): Integer; cdecl;
function QObjectList_findRef(obj: QObjectListH; d: QObjectH): Integer; cdecl;
function QObjectList_findNextRef(obj: QObjectListH; d: QObjectH): Integer; cdecl;
function QObjectList_contains(obj: QObjectListH; d: QObjectH): Cardinal; cdecl;
function QObjectList_containsRef(obj: QObjectListH; d: QObjectH): Cardinal; cdecl;
function QObjectList_at(obj: QObjectListH; i: Cardinal): QObjectH; cdecl; overload;
function QObjectList_at(obj: QObjectListH): Integer; cdecl; overload;
function QObjectList_current(obj: QObjectListH): QObjectH; cdecl;
function QObjectList_getFirst(obj: QObjectListH): QObjectH; cdecl;
function QObjectList_getLast(obj: QObjectListH): QObjectH; cdecl;
function QObjectList_first(obj: QObjectListH): QObjectH; cdecl;
function QObjectList_last(obj: QObjectListH): QObjectH; cdecl;
function QObjectList_next(obj: QObjectListH): QObjectH; cdecl;
function QObjectList_prev(obj: QObjectListH): QObjectH; cdecl;

function QBitmap_from_QPixmap(bm: QBitmapH; pm: QPixmapH): QBitmapH; cdecl;

function QWidgetList_create: QWidgetListH; cdecl; overload;
function QWidgetList_create(list: QWidgetListH): QWidgetListH; cdecl; overload;
procedure QWidgetList_destroy(obj: QWidgetListH); cdecl;
function QWidgetList_count(obj: QWidgetListH): Cardinal; cdecl;
function QWidgetList_insert(obj: QWidgetListH; i: Cardinal; d: QWidgetH): Boolean; cdecl;
function QWidgetList_remove(obj: QWidgetListH; i: Cardinal): Boolean; cdecl; overload;
function QWidgetList_remove(obj: QWidgetListH; d: QWidgetH): Boolean; cdecl; overload;
procedure QWidgetList_clear(obj: QWidgetListH); cdecl;
function QWidgetList_find(obj: QWidgetListH; d: QWidgetH): Integer; cdecl;
function QWidgetList_findNext(obj: QWidgetListH; d: QWidgetH): Integer; cdecl;
function QWidgetList_contains(obj: QWidgetListH; d: QWidgetH): Cardinal; cdecl;
function QWidgetList_at(obj: QWidgetListH; i: Cardinal): QWidgetH; cdecl; overload;
function QWidgetList_current(obj: QWidgetListH): QWidgetH; cdecl;
function QWidgetList_first(obj: QWidgetListH): QWidgetH; cdecl;
function QWidgetList_last(obj: QWidgetListH): QWidgetH; cdecl;
function QWidgetList_next(obj: QWidgetListH): QWidgetH; cdecl;
function QWidgetList_prev(obj: QWidgetListH): QWidgetH; cdecl;

 
const 
 
{$IFDEF MSWINDOWS} 
QtShareName = 'qtintf.dll'; 
QtNamePrefix = '_'; 
QtLibName = 'qt.dll'; 
{$ENDIF} 
{$IFDEF LINUX} 
QtShareName = 'libqtintf.so'; 
QtNamePrefix = ''; 
QtLibName = 'libqt.so.2'; 
{$ENDIF} 
 
implementation  
 
uses BindHelp; 
 
procedure QWidget_destroy; external QtShareName name QtNamePrefix + 'QWidget_destroy';
function QWidget_create; external QtShareName name QtNamePrefix + 'QWidget_create';
function QWidget_winId; external QtShareName name QtNamePrefix + 'QWidget_winId';
procedure QWidget_setName; external QtShareName name QtNamePrefix + 'QWidget_setName';
function QWidget_style; external QtShareName name QtNamePrefix + 'QWidget_style';
procedure QWidget_setStyle; external QtShareName name QtNamePrefix + 'QWidget_setStyle';
function QWidget_isTopLevel; external QtShareName name QtNamePrefix + 'QWidget_isTopLevel';
function QWidget_isModal; external QtShareName name QtNamePrefix + 'QWidget_isModal';
function QWidget_isPopup; external QtShareName name QtNamePrefix + 'QWidget_isPopup';
function QWidget_isDesktop; external QtShareName name QtNamePrefix + 'QWidget_isDesktop';
function QWidget_isEnabled; external QtShareName name QtNamePrefix + 'QWidget_isEnabled';
function QWidget_isEnabledTo; external QtShareName name QtNamePrefix + 'QWidget_isEnabledTo';
function QWidget_isEnabledToTLW; external QtShareName name QtNamePrefix + 'QWidget_isEnabledToTLW';
procedure QWidget_setEnabled; external QtShareName name QtNamePrefix + 'QWidget_setEnabled';
procedure QWidget_setDisabled; external QtShareName name QtNamePrefix + 'QWidget_setDisabled';
procedure QWidget_frameGeometry; external QtShareName name QtNamePrefix + 'QWidget_frameGeometry';
procedure QWidget_geometry; external QtShareName name QtNamePrefix + 'QWidget_geometry';
function QWidget_x; external QtShareName name QtNamePrefix + 'QWidget_x';
function QWidget_y; external QtShareName name QtNamePrefix + 'QWidget_y';
procedure QWidget_pos; external QtShareName name QtNamePrefix + 'QWidget_pos';
procedure QWidget_frameSize; external QtShareName name QtNamePrefix + 'QWidget_frameSize';
procedure QWidget_size; external QtShareName name QtNamePrefix + 'QWidget_size';
function QWidget_width; external QtShareName name QtNamePrefix + 'QWidget_width';
function QWidget_height; external QtShareName name QtNamePrefix + 'QWidget_height';
procedure QWidget_rect; external QtShareName name QtNamePrefix + 'QWidget_rect';
procedure QWidget_childrenRect; external QtShareName name QtNamePrefix + 'QWidget_childrenRect';
procedure QWidget_childrenRegion; external QtShareName name QtNamePrefix + 'QWidget_childrenRegion';
procedure QWidget_minimumSize; external QtShareName name QtNamePrefix + 'QWidget_minimumSize';
procedure QWidget_maximumSize; external QtShareName name QtNamePrefix + 'QWidget_maximumSize';
function QWidget_minimumWidth; external QtShareName name QtNamePrefix + 'QWidget_minimumWidth';
function QWidget_minimumHeight; external QtShareName name QtNamePrefix + 'QWidget_minimumHeight';
function QWidget_maximumWidth; external QtShareName name QtNamePrefix + 'QWidget_maximumWidth';
function QWidget_maximumHeight; external QtShareName name QtNamePrefix + 'QWidget_maximumHeight';
procedure QWidget_setMinimumSize(handle: QWidgetH; p1: PSize); external QtShareName name QtNamePrefix + 'QWidget_setMinimumSize';
procedure QWidget_setMinimumSize(handle: QWidgetH; minw: Integer; minh: Integer); external QtShareName name QtNamePrefix + 'QWidget_setMinimumSize2';
procedure QWidget_setMaximumSize(handle: QWidgetH; p1: PSize); external QtShareName name QtNamePrefix + 'QWidget_setMaximumSize';
procedure QWidget_setMaximumSize(handle: QWidgetH; maxw: Integer; maxh: Integer); external QtShareName name QtNamePrefix + 'QWidget_setMaximumSize2';
procedure QWidget_setMinimumWidth; external QtShareName name QtNamePrefix + 'QWidget_setMinimumWidth';
procedure QWidget_setMinimumHeight; external QtShareName name QtNamePrefix + 'QWidget_setMinimumHeight';
procedure QWidget_setMaximumWidth; external QtShareName name QtNamePrefix + 'QWidget_setMaximumWidth';
procedure QWidget_setMaximumHeight; external QtShareName name QtNamePrefix + 'QWidget_setMaximumHeight';
procedure QWidget_sizeIncrement; external QtShareName name QtNamePrefix + 'QWidget_sizeIncrement';
procedure QWidget_setSizeIncrement(handle: QWidgetH; p1: PSize); external QtShareName name QtNamePrefix + 'QWidget_setSizeIncrement';
procedure QWidget_setSizeIncrement(handle: QWidgetH; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QWidget_setSizeIncrement2';
procedure QWidget_baseSize; external QtShareName name QtNamePrefix + 'QWidget_baseSize';
procedure QWidget_setBaseSize(handle: QWidgetH; p1: PSize); external QtShareName name QtNamePrefix + 'QWidget_setBaseSize';
procedure QWidget_setBaseSize(handle: QWidgetH; basew: Integer; baseh: Integer); external QtShareName name QtNamePrefix + 'QWidget_setBaseSize2';
procedure QWidget_setFixedSize(handle: QWidgetH; p1: PSize); external QtShareName name QtNamePrefix + 'QWidget_setFixedSize';
procedure QWidget_setFixedSize(handle: QWidgetH; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QWidget_setFixedSize2';
procedure QWidget_setFixedWidth; external QtShareName name QtNamePrefix + 'QWidget_setFixedWidth';
procedure QWidget_setFixedHeight; external QtShareName name QtNamePrefix + 'QWidget_setFixedHeight';
procedure QWidget_mapToGlobal; external QtShareName name QtNamePrefix + 'QWidget_mapToGlobal';
procedure QWidget_mapFromGlobal; external QtShareName name QtNamePrefix + 'QWidget_mapFromGlobal';
procedure QWidget_mapToParent; external QtShareName name QtNamePrefix + 'QWidget_mapToParent';
procedure QWidget_mapFromParent; external QtShareName name QtNamePrefix + 'QWidget_mapFromParent';
procedure QWidget_mapTo; external QtShareName name QtNamePrefix + 'QWidget_mapTo';
procedure QWidget_mapFrom; external QtShareName name QtNamePrefix + 'QWidget_mapFrom';
function QWidget_topLevelWidget; external QtShareName name QtNamePrefix + 'QWidget_topLevelWidget';
function QWidget_backgroundMode; external QtShareName name QtNamePrefix + 'QWidget_backgroundMode';
procedure QWidget_setBackgroundMode; external QtShareName name QtNamePrefix + 'QWidget_setBackgroundMode';
function QWidget_backgroundColor; external QtShareName name QtNamePrefix + 'QWidget_backgroundColor';
function QWidget_foregroundColor; external QtShareName name QtNamePrefix + 'QWidget_foregroundColor';
procedure QWidget_setBackgroundColor; external QtShareName name QtNamePrefix + 'QWidget_setBackgroundColor';
function QWidget_backgroundPixmap; external QtShareName name QtNamePrefix + 'QWidget_backgroundPixmap';
procedure QWidget_setBackgroundPixmap; external QtShareName name QtNamePrefix + 'QWidget_setBackgroundPixmap';
function QWidget_colorGroup; external QtShareName name QtNamePrefix + 'QWidget_colorGroup';
function QWidget_palette; external QtShareName name QtNamePrefix + 'QWidget_palette';
function QWidget_ownPalette; external QtShareName name QtNamePrefix + 'QWidget_ownPalette';
procedure QWidget_setPalette(handle: QWidgetH; p1: QPaletteH); external QtShareName name QtNamePrefix + 'QWidget_setPalette';
procedure QWidget_unsetPalette; external QtShareName name QtNamePrefix + 'QWidget_unsetPalette';
procedure QWidget_font; external QtShareName name QtNamePrefix + 'QWidget_font';
function QWidget_ownFont; external QtShareName name QtNamePrefix + 'QWidget_ownFont';
procedure QWidget_setFont(handle: QWidgetH; p1: QFontH); external QtShareName name QtNamePrefix + 'QWidget_setFont';
procedure QWidget_unsetFont; external QtShareName name QtNamePrefix + 'QWidget_unsetFont';
procedure QWidget_fontMetrics; external QtShareName name QtNamePrefix + 'QWidget_fontMetrics';
procedure QWidget_fontInfo; external QtShareName name QtNamePrefix + 'QWidget_fontInfo';
function QWidget_fontPropagation; external QtShareName name QtNamePrefix + 'QWidget_fontPropagation';
procedure QWidget_setFontPropagation; external QtShareName name QtNamePrefix + 'QWidget_setFontPropagation';
function QWidget_palettePropagation; external QtShareName name QtNamePrefix + 'QWidget_palettePropagation';
procedure QWidget_setPalettePropagation; external QtShareName name QtNamePrefix + 'QWidget_setPalettePropagation';
function QWidget_cursor; external QtShareName name QtNamePrefix + 'QWidget_cursor';
function QWidget_ownCursor; external QtShareName name QtNamePrefix + 'QWidget_ownCursor';
procedure QWidget_setCursor; external QtShareName name QtNamePrefix + 'QWidget_setCursor';
procedure QWidget_unsetCursor; external QtShareName name QtNamePrefix + 'QWidget_unsetCursor';
procedure QWidget_caption; external QtShareName name QtNamePrefix + 'QWidget_caption';
function QWidget_icon; external QtShareName name QtNamePrefix + 'QWidget_icon';
procedure QWidget_iconText; external QtShareName name QtNamePrefix + 'QWidget_iconText';
function QWidget_hasMouseTracking; external QtShareName name QtNamePrefix + 'QWidget_hasMouseTracking';
procedure QWidget_setMask(handle: QWidgetH; p1: QBitmapH); external QtShareName name QtNamePrefix + 'QWidget_setMask';
procedure QWidget_setMask(handle: QWidgetH; p1: QRegionH); external QtShareName name QtNamePrefix + 'QWidget_setMask2';
procedure QWidget_clearMask; external QtShareName name QtNamePrefix + 'QWidget_clearMask';
procedure QWidget_setCaption; external QtShareName name QtNamePrefix + 'QWidget_setCaption';
procedure QWidget_setIcon; external QtShareName name QtNamePrefix + 'QWidget_setIcon';
procedure QWidget_setIconText; external QtShareName name QtNamePrefix + 'QWidget_setIconText';
procedure QWidget_setMouseTracking; external QtShareName name QtNamePrefix + 'QWidget_setMouseTracking';
procedure QWidget_setFocus; external QtShareName name QtNamePrefix + 'QWidget_setFocus';
procedure QWidget_clearFocus; external QtShareName name QtNamePrefix + 'QWidget_clearFocus';
function QWidget_isActiveWindow; external QtShareName name QtNamePrefix + 'QWidget_isActiveWindow';
procedure QWidget_setActiveWindow; external QtShareName name QtNamePrefix + 'QWidget_setActiveWindow';
function QWidget_isFocusEnabled; external QtShareName name QtNamePrefix + 'QWidget_isFocusEnabled';
function QWidget_focusPolicy; external QtShareName name QtNamePrefix + 'QWidget_focusPolicy';
procedure QWidget_setFocusPolicy; external QtShareName name QtNamePrefix + 'QWidget_setFocusPolicy';
function QWidget_hasFocus; external QtShareName name QtNamePrefix + 'QWidget_hasFocus';
procedure QWidget_setTabOrder; external QtShareName name QtNamePrefix + 'QWidget_setTabOrder';
procedure QWidget_setFocusProxy; external QtShareName name QtNamePrefix + 'QWidget_setFocusProxy';
function QWidget_focusProxy; external QtShareName name QtNamePrefix + 'QWidget_focusProxy';
procedure QWidget_grabMouse(handle: QWidgetH); external QtShareName name QtNamePrefix + 'QWidget_grabMouse';
procedure QWidget_grabMouse(handle: QWidgetH; p1: QCursorH); external QtShareName name QtNamePrefix + 'QWidget_grabMouse2';
procedure QWidget_releaseMouse; external QtShareName name QtNamePrefix + 'QWidget_releaseMouse';
procedure QWidget_grabKeyboard; external QtShareName name QtNamePrefix + 'QWidget_grabKeyboard';
procedure QWidget_releaseKeyboard; external QtShareName name QtNamePrefix + 'QWidget_releaseKeyboard';
function QWidget_mouseGrabber; external QtShareName name QtNamePrefix + 'QWidget_mouseGrabber';
function QWidget_keyboardGrabber; external QtShareName name QtNamePrefix + 'QWidget_keyboardGrabber';
function QWidget_isUpdatesEnabled; external QtShareName name QtNamePrefix + 'QWidget_isUpdatesEnabled';
procedure QWidget_repaintUnclipped; external QtShareName name QtNamePrefix + 'QWidget_repaintUnclipped';
procedure QWidget_setUpdatesEnabled; external QtShareName name QtNamePrefix + 'QWidget_setUpdatesEnabled';
procedure QWidget_update(handle: QWidgetH); external QtShareName name QtNamePrefix + 'QWidget_update';
procedure QWidget_update(handle: QWidgetH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QWidget_update2';
procedure QWidget_update(handle: QWidgetH; p1: PRect); external QtShareName name QtNamePrefix + 'QWidget_update3';
procedure QWidget_repaint(handle: QWidgetH); external QtShareName name QtNamePrefix + 'QWidget_repaint';
procedure QWidget_repaint(handle: QWidgetH; erase: Boolean); external QtShareName name QtNamePrefix + 'QWidget_repaint2';
procedure QWidget_repaint(handle: QWidgetH; x: Integer; y: Integer; w: Integer; h: Integer; erase: Boolean); external QtShareName name QtNamePrefix + 'QWidget_repaint3';
procedure QWidget_repaint(handle: QWidgetH; p1: PRect; erase: Boolean); external QtShareName name QtNamePrefix + 'QWidget_repaint4';
procedure QWidget_repaint(handle: QWidgetH; p1: QRegionH; erase: Boolean); external QtShareName name QtNamePrefix + 'QWidget_repaint5';
procedure QWidget_show; external QtShareName name QtNamePrefix + 'QWidget_show';
procedure QWidget_hide; external QtShareName name QtNamePrefix + 'QWidget_hide';
procedure QWidget_iconify; external QtShareName name QtNamePrefix + 'QWidget_iconify';
procedure QWidget_showMinimized; external QtShareName name QtNamePrefix + 'QWidget_showMinimized';
procedure QWidget_showMaximized; external QtShareName name QtNamePrefix + 'QWidget_showMaximized';
procedure QWidget_showFullScreen; external QtShareName name QtNamePrefix + 'QWidget_showFullScreen';
procedure QWidget_showNormal; external QtShareName name QtNamePrefix + 'QWidget_showNormal';
procedure QWidget_polish; external QtShareName name QtNamePrefix + 'QWidget_polish';
procedure QWidget_constPolish; external QtShareName name QtNamePrefix + 'QWidget_constPolish';
function QWidget_close(handle: QWidgetH): Boolean; external QtShareName name QtNamePrefix + 'QWidget_close';
procedure QWidget_raise; external QtShareName name QtNamePrefix + 'QWidget_raise';
procedure QWidget_lower; external QtShareName name QtNamePrefix + 'QWidget_lower';
procedure QWidget_stackUnder; external QtShareName name QtNamePrefix + 'QWidget_stackUnder';
procedure QWidget_move(handle: QWidgetH; x: Integer; y: Integer); external QtShareName name QtNamePrefix + 'QWidget_move';
procedure QWidget_move(handle: QWidgetH; p1: PPoint); external QtShareName name QtNamePrefix + 'QWidget_move2';
procedure QWidget_resize(handle: QWidgetH; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QWidget_resize';
procedure QWidget_resize(handle: QWidgetH; p1: PSize); external QtShareName name QtNamePrefix + 'QWidget_resize2';
procedure QWidget_setGeometry(handle: QWidgetH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QWidget_setGeometry';
procedure QWidget_setGeometry(handle: QWidgetH; p1: PRect); external QtShareName name QtNamePrefix + 'QWidget_setGeometry2';
function QWidget_close(handle: QWidgetH; alsoDelete: Boolean): Boolean; external QtShareName name QtNamePrefix + 'QWidget_close2';
function QWidget_isVisible; external QtShareName name QtNamePrefix + 'QWidget_isVisible';
function QWidget_isVisibleTo; external QtShareName name QtNamePrefix + 'QWidget_isVisibleTo';
function QWidget_isVisibleToTLW; external QtShareName name QtNamePrefix + 'QWidget_isVisibleToTLW';
procedure QWidget_visibleRect; external QtShareName name QtNamePrefix + 'QWidget_visibleRect';
function QWidget_isHidden; external QtShareName name QtNamePrefix + 'QWidget_isHidden';
function QWidget_isMinimized; external QtShareName name QtNamePrefix + 'QWidget_isMinimized';
function QWidget_isMaximized; external QtShareName name QtNamePrefix + 'QWidget_isMaximized';
procedure QWidget_sizeHint; external QtShareName name QtNamePrefix + 'QWidget_sizeHint';
procedure QWidget_minimumSizeHint; external QtShareName name QtNamePrefix + 'QWidget_minimumSizeHint';
procedure QWidget_sizePolicy; external QtShareName name QtNamePrefix + 'QWidget_sizePolicy';
procedure QWidget_setSizePolicy; external QtShareName name QtNamePrefix + 'QWidget_setSizePolicy';
function QWidget_heightForWidth; external QtShareName name QtNamePrefix + 'QWidget_heightForWidth';
procedure QWidget_adjustSize; external QtShareName name QtNamePrefix + 'QWidget_adjustSize';
function QWidget_layout; external QtShareName name QtNamePrefix + 'QWidget_layout';
procedure QWidget_updateGeometry; external QtShareName name QtNamePrefix + 'QWidget_updateGeometry';
procedure QWidget_reparent(handle: QWidgetH; parent: QWidgetH; p2: WFlags; p3: PPoint; showIt: Boolean); external QtShareName name QtNamePrefix + 'QWidget_reparent';
procedure QWidget_reparent(handle: QWidgetH; parent: QWidgetH; p2: PPoint; showIt: Boolean); external QtShareName name QtNamePrefix + 'QWidget_reparent2';
procedure QWidget_recreate; external QtShareName name QtNamePrefix + 'QWidget_recreate';
procedure QWidget_erase(handle: QWidgetH); external QtShareName name QtNamePrefix + 'QWidget_erase';
procedure QWidget_erase(handle: QWidgetH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QWidget_erase2';
procedure QWidget_erase(handle: QWidgetH; p1: PRect); external QtShareName name QtNamePrefix + 'QWidget_erase3';
procedure QWidget_erase(handle: QWidgetH; p1: QRegionH); external QtShareName name QtNamePrefix + 'QWidget_erase4';
procedure QWidget_scroll(handle: QWidgetH; dx: Integer; dy: Integer); external QtShareName name QtNamePrefix + 'QWidget_scroll';
procedure QWidget_scroll(handle: QWidgetH; dx: Integer; dy: Integer; p3: PRect); external QtShareName name QtNamePrefix + 'QWidget_scroll2';
procedure QWidget_drawText(handle: QWidgetH; x: Integer; y: Integer; p3: PWideString); external QtShareName name QtNamePrefix + 'QWidget_drawText';
procedure QWidget_drawText(handle: QWidgetH; p1: PPoint; p2: PWideString); external QtShareName name QtNamePrefix + 'QWidget_drawText2';
function QWidget_focusWidget; external QtShareName name QtNamePrefix + 'QWidget_focusWidget';
procedure QWidget_microFocusHint; external QtShareName name QtNamePrefix + 'QWidget_microFocusHint';
function QWidget_acceptDrops; external QtShareName name QtNamePrefix + 'QWidget_acceptDrops';
procedure QWidget_setAcceptDrops; external QtShareName name QtNamePrefix + 'QWidget_setAcceptDrops';
procedure QWidget_setAutoMask; external QtShareName name QtNamePrefix + 'QWidget_setAutoMask';
function QWidget_autoMask; external QtShareName name QtNamePrefix + 'QWidget_autoMask';
procedure QWidget_setBackgroundOrigin; external QtShareName name QtNamePrefix + 'QWidget_setBackgroundOrigin';
function QWidget_backgroundOrigin; external QtShareName name QtNamePrefix + 'QWidget_backgroundOrigin';
function QWidget_customWhatsThis; external QtShareName name QtNamePrefix + 'QWidget_customWhatsThis';
function QWidget_parentWidget; external QtShareName name QtNamePrefix + 'QWidget_parentWidget';
function QWidget_testWState; external QtShareName name QtNamePrefix + 'QWidget_testWState';
function QWidget_testWFlags; external QtShareName name QtNamePrefix + 'QWidget_testWFlags';
function QWidget_find; external QtShareName name QtNamePrefix + 'QWidget_find';
function QWidget_wmapper; external QtShareName name QtNamePrefix + 'QWidget_wmapper';

procedure QWidget_setPalette(handle: QWidgetH; p1: QPaletteH; iReallyMeanIt: Boolean); external QtShareName name QtNamePrefix + 'QWidget_setPalette2';
procedure QWidget_setFont(handle: QWidgetH; p1: QFontH; iReallyMeanIt: Boolean); external QtShareName name QtNamePrefix + 'QWidget_setFont2';
function QWidget_to_QPaintDevice; external QtSharename name QtNamePrefix + 'QWidget_to_QPaintDevice';

function QApplication_argc; external QtShareName name QtNamePrefix + 'QApplication_argc';
function QApplication_argv; external QtShareName name QtNamePrefix + 'QApplication_argv';
function QApplication_style; external QtShareName name QtNamePrefix + 'QApplication_style';
procedure QApplication_setStyle; external QtShareName name QtNamePrefix + 'QApplication_setStyle';

function QApplication_colorSpec; external QtShareName name QtNamePrefix + 'QApplication_colorSpec';
procedure QApplication_setColorSpec; external QtShareName name QtNamePrefix + 'QApplication_setColorSpec';
function QApplication_overrideCursor; external QtShareName name QtNamePrefix + 'QApplication_overrideCursor';
procedure QApplication_setOverrideCursor; external QtShareName name QtNamePrefix + 'QApplication_setOverrideCursor';
procedure QApplication_restoreOverrideCursor; external QtShareName name QtNamePrefix + 'QApplication_restoreOverrideCursor';
function QApplication_hasGlobalMouseTracking; external QtShareName name QtNamePrefix + 'QApplication_hasGlobalMouseTracking';
procedure QApplication_setGlobalMouseTracking; external QtShareName name QtNamePrefix + 'QApplication_setGlobalMouseTracking';
procedure QApplication_palette; external QtShareName name QtNamePrefix + 'QApplication_palette';
procedure QApplication_setPalette; external QtShareName name QtNamePrefix + 'QApplication_setPalette';
procedure QApplication_font; external QtShareName name QtNamePrefix + 'QApplication_font';
procedure QApplication_setFont; external QtShareName name QtNamePrefix + 'QApplication_setFont';
procedure QApplication_fontMetrics; external QtShareName name QtNamePrefix + 'QApplication_fontMetrics';
function QApplication_mainWidget; external QtShareName name QtNamePrefix + 'QApplication_mainWidget';
procedure QApplication_setMainWidget; external QtShareName name QtNamePrefix + 'QApplication_setMainWidget';
procedure QApplication_polish; external QtShareName name QtNamePrefix + 'QApplication_polish';
function QApplication_allWidgets; external QtShareName name QtNamePrefix + 'QApplication_allWidgets';
function QApplication_topLevelWidgets; external QtShareName name QtNamePrefix + 'QApplication_topLevelWidgets';
function QApplication_desktop; external QtShareName name QtNamePrefix + 'QApplication_desktop';
function QApplication_activePopupWidget; external QtShareName name QtNamePrefix + 'QApplication_activePopupWidget';
function QApplication_activeModalWidget; external QtShareName name QtNamePrefix + 'QApplication_activeModalWidget';
function QApplication_clipboard; external QtShareName name QtNamePrefix + 'QApplication_clipboard';
function QApplication_focusWidget; external QtShareName name QtNamePrefix + 'QApplication_focusWidget';
function QApplication_activeWindow; external QtShareName name QtNamePrefix + 'QApplication_activeWindow';
function QApplication_widgetAt(x: Integer; y: Integer; child: Boolean): QWidgetH; external QtShareName name QtNamePrefix + 'QApplication_widgetAt';
function QApplication_widgetAt(p1: PPoint; child: Boolean): QWidgetH; external QtShareName name QtNamePrefix + 'QApplication_widgetAt2';
function QApplication_exec; external QtShareName name QtNamePrefix + 'QApplication_exec';
procedure QApplication_processEvents(handle: QApplicationH); external QtShareName name QtNamePrefix + 'QApplication_processEvents';
procedure QApplication_processEvents(handle: QApplicationH; maxtime: Integer); external QtShareName name QtNamePrefix + 'QApplication_processEvents2';
procedure QApplication_processOneEvent; external QtShareName name QtNamePrefix + 'QApplication_processOneEvent';
function QApplication_enter_loop; external QtShareName name QtNamePrefix + 'QApplication_enter_loop';
procedure QApplication_exit_loop; external QtShareName name QtNamePrefix + 'QApplication_exit_loop';
function QApplication_loopLevel; external QtShareName name QtNamePrefix + 'QApplication_loopLevel';
procedure QApplication_exit; external QtShareName name QtNamePrefix + 'QApplication_exit';
function QApplication_sendEvent; external QtShareName name QtNamePrefix + 'QApplication_sendEvent';
procedure QApplication_postEvent; external QtShareName name QtNamePrefix + 'QApplication_postEvent';
procedure QApplication_sendPostedEvents(receiver: QObjectH; event_type: Integer); external QtShareName name QtNamePrefix + 'QApplication_sendPostedEvents';
procedure QApplication_sendPostedEvents(); external QtShareName name QtNamePrefix + 'QApplication_sendPostedEvents2';
procedure QApplication_removePostedEvents; external QtShareName name QtNamePrefix + 'QApplication_removePostedEvents';
function QApplication_notify; external QtShareName name QtNamePrefix + 'QApplication_notify';
function QApplication_startingUp; external QtShareName name QtNamePrefix + 'QApplication_startingUp';
function QApplication_closingDown; external QtShareName name QtNamePrefix + 'QApplication_closingDown';
procedure QApplication_flushX; external QtShareName name QtNamePrefix + 'QApplication_flushX';
procedure QApplication_syncX; external QtShareName name QtNamePrefix + 'QApplication_syncX';
procedure QApplication_beep; external QtShareName name QtNamePrefix + 'QApplication_beep';
procedure QApplication_setDefaultCodec; external QtShareName name QtNamePrefix + 'QApplication_setDefaultCodec';
function QApplication_defaultCodec; external QtShareName name QtNamePrefix + 'QApplication_defaultCodec';
procedure QApplication_installTranslator; external QtShareName name QtNamePrefix + 'QApplication_installTranslator';
procedure QApplication_removeTranslator; external QtShareName name QtNamePrefix + 'QApplication_removeTranslator';
procedure QApplication_translate(handle: QApplicationH; retval: PWideString; p1: PAnsiChar; p2: PAnsiChar); external QtShareName name QtNamePrefix + 'QApplication_translate';
procedure QApplication_translate(handle: QApplicationH; retval: PWideString; p1: PAnsiChar; p2: PAnsiChar; p3: PAnsiChar); external QtShareName name QtNamePrefix + 'QApplication_translate2';
procedure QApplication_setWinStyleHighlightColor; external QtShareName name QtNamePrefix + 'QApplication_setWinStyleHighlightColor';
function QApplication_winStyleHighlightColor; external QtShareName name QtNamePrefix + 'QApplication_winStyleHighlightColor';
procedure QApplication_setDesktopSettingsAware; external QtShareName name QtNamePrefix + 'QApplication_setDesktopSettingsAware';
function QApplication_desktopSettingsAware; external QtShareName name QtNamePrefix + 'QApplication_desktopSettingsAware';
procedure QApplication_setCursorFlashTime; external QtShareName name QtNamePrefix + 'QApplication_setCursorFlashTime';
function QApplication_cursorFlashTime; external QtShareName name QtNamePrefix + 'QApplication_cursorFlashTime';
procedure QApplication_setDoubleClickInterval; external QtShareName name QtNamePrefix + 'QApplication_setDoubleClickInterval';
function QApplication_doubleClickInterval; external QtShareName name QtNamePrefix + 'QApplication_doubleClickInterval';
procedure QApplication_setWheelScrollLines; external QtShareName name QtNamePrefix + 'QApplication_setWheelScrollLines';
function QApplication_wheelScrollLines; external QtShareName name QtNamePrefix + 'QApplication_wheelScrollLines';
procedure QApplication_setGlobalStrut; external QtShareName name QtNamePrefix + 'QApplication_setGlobalStrut';
procedure QApplication_globalStrut; external QtShareName name QtNamePrefix + 'QApplication_globalStrut';
procedure QApplication_setStartDragTime; external QtShareName name QtNamePrefix + 'QApplication_setStartDragTime';
function QApplication_startDragTime; external QtShareName name QtNamePrefix + 'QApplication_startDragTime';
procedure QApplication_setStartDragDistance; external QtShareName name QtNamePrefix + 'QApplication_setStartDragDistance';
function QApplication_startDragDistance; external QtShareName name QtNamePrefix + 'QApplication_startDragDistance';
function QApplication_isEffectEnabled; external QtShareName name QtNamePrefix + 'QApplication_isEffectEnabled';
procedure QApplication_setEffectEnabled; external QtShareName name QtNamePrefix + 'QApplication_setEffectEnabled';
procedure QApplication_do_mouse_down; external QtShareName name QtNamePrefix + 'QApplication_do_mouse_down';

function QApplication_macProcessEvent; external QtShareName name QtNamePrefix + 'QApplication_macProcessEvent';
function QApplication_winEventFilter; external QtShareName name QtNamePrefix + 'QApplication_winEventFilter';

function QApplication_winVersion; external QtShareName name QtNamePrefix + 'QApplication_winVersion';
procedure QApplication_winFocus; external QtShareName name QtNamePrefix + 'QApplication_winFocus';
procedure QApplication_winMouseButtonUp; external QtShareName name QtNamePrefix + 'QApplication_winMouseButtonUp';
function QApplication_isSessionRestored; external QtShareName name QtNamePrefix + 'QApplication_isSessionRestored';
procedure QApplication_sessionId; external QtShareName name QtNamePrefix + 'QApplication_sessionId';
procedure QApplication_commitData; external QtShareName name QtNamePrefix + 'QApplication_commitData';
procedure QApplication_saveState; external QtShareName name QtNamePrefix + 'QApplication_saveState';
procedure QApplication_create_xim; external QtShareName name QtNamePrefix + 'QApplication_create_xim';
procedure QApplication_close_xim; external QtShareName name QtNamePrefix + 'QApplication_close_xim';
procedure QApplication_wakeUpGuiThread; external QtShareName name QtNamePrefix + 'QApplication_wakeUpGuiThread';

procedure QApplication_quit; external QtShareName name QtNamePrefix + 'QApplication_quit';
procedure QApplication_closeAllWindows; external QtShareName name QtNamePrefix + 'QApplication_closeAllWindows';

procedure QButton_destroy; external QtShareName name QtNamePrefix + 'QButton_destroy';
function QButton_create; external QtShareName name QtNamePrefix + 'QButton_create';
procedure QButton_text; external QtShareName name QtNamePrefix + 'QButton_text';
procedure QButton_setText; external QtShareName name QtNamePrefix + 'QButton_setText';
function QButton_pixmap; external QtShareName name QtNamePrefix + 'QButton_pixmap';
procedure QButton_setPixmap; external QtShareName name QtNamePrefix + 'QButton_setPixmap';
function QButton_accel; external QtShareName name QtNamePrefix + 'QButton_accel';
procedure QButton_setAccel; external QtShareName name QtNamePrefix + 'QButton_setAccel';
function QButton_isToggleButton; external QtShareName name QtNamePrefix + 'QButton_isToggleButton';
function QButton_toggleType; external QtShareName name QtNamePrefix + 'QButton_toggleType';
procedure QButton_setDown; external QtShareName name QtNamePrefix + 'QButton_setDown';
function QButton_isDown; external QtShareName name QtNamePrefix + 'QButton_isDown';
function QButton_isOn; external QtShareName name QtNamePrefix + 'QButton_isOn';
function QButton_state; external QtShareName name QtNamePrefix + 'QButton_state';
function QButton_autoResize; external QtShareName name QtNamePrefix + 'QButton_autoResize';
procedure QButton_setAutoResize; external QtShareName name QtNamePrefix + 'QButton_setAutoResize';
function QButton_autoRepeat; external QtShareName name QtNamePrefix + 'QButton_autoRepeat';
procedure QButton_setAutoRepeat; external QtShareName name QtNamePrefix + 'QButton_setAutoRepeat';
function QButton_isExclusiveToggle; external QtShareName name QtNamePrefix + 'QButton_isExclusiveToggle';
function QButton_focusNextPrevChild; external QtShareName name QtNamePrefix + 'QButton_focusNextPrevChild';
function QButton_group; external QtShareName name QtNamePrefix + 'QButton_group';
procedure QButton_animateClick; external QtShareName name QtNamePrefix + 'QButton_animateClick';
procedure QButton_toggle; external QtShareName name QtNamePrefix + 'QButton_toggle';

procedure QComboBox_destroy; external QtShareName name QtNamePrefix + 'QComboBox_destroy';
function QComboBox_create(parent: QWidgetH; name: PAnsiChar): QComboBoxH; external QtShareName name QtNamePrefix + 'QComboBox_create';
function QComboBox_create(rw: Boolean; parent: QWidgetH; name: PAnsiChar): QComboBoxH; external QtShareName name QtNamePrefix + 'QComboBox_create2';
function QComboBox_count; external QtShareName name QtNamePrefix + 'QComboBox_count';
procedure QComboBox_insertStringList; external QtShareName name QtNamePrefix + 'QComboBox_insertStringList';
procedure QComboBox_insertStrList(handle: QComboBoxH; p1: QStrListH; index: Integer); external QtShareName name QtNamePrefix + 'QComboBox_insertStrList';

procedure QComboBox_insertStrList(handle: QComboBoxH; p1: PPAnsiChar; numStrings: Integer; index: Integer); external QtShareName name QtNamePrefix + 'QComboBox_insertStrList3';
procedure QComboBox_insertItem(handle: QComboBoxH; text: PWideString; index: Integer); external QtShareName name QtNamePrefix + 'QComboBox_insertItem';
procedure QComboBox_insertItem(handle: QComboBoxH; pixmap: QPixmapH; index: Integer); external QtShareName name QtNamePrefix + 'QComboBox_insertItem2';
procedure QComboBox_insertItem(handle: QComboBoxH; pixmap: QPixmapH; text: PWideString; index: Integer); external QtShareName name QtNamePrefix + 'QComboBox_insertItem3';
procedure QComboBox_removeItem; external QtShareName name QtNamePrefix + 'QComboBox_removeItem';
procedure QComboBox_clear; external QtShareName name QtNamePrefix + 'QComboBox_clear';
procedure QComboBox_currentText; external QtShareName name QtNamePrefix + 'QComboBox_currentText';
procedure QComboBox_text; external QtShareName name QtNamePrefix + 'QComboBox_text';
function QComboBox_pixmap; external QtShareName name QtNamePrefix + 'QComboBox_pixmap';
procedure QComboBox_changeItem(handle: QComboBoxH; text: PWideString; index: Integer); external QtShareName name QtNamePrefix + 'QComboBox_changeItem';
procedure QComboBox_changeItem(handle: QComboBoxH; pixmap: QPixmapH; index: Integer); external QtShareName name QtNamePrefix + 'QComboBox_changeItem2';
procedure QComboBox_changeItem(handle: QComboBoxH; pixmap: QPixmapH; text: PWideString; index: Integer); external QtShareName name QtNamePrefix + 'QComboBox_changeItem3';
function QComboBox_currentItem; external QtShareName name QtNamePrefix + 'QComboBox_currentItem';
procedure QComboBox_setCurrentItem; external QtShareName name QtNamePrefix + 'QComboBox_setCurrentItem';
function QComboBox_autoResize; external QtShareName name QtNamePrefix + 'QComboBox_autoResize';
procedure QComboBox_setAutoResize; external QtShareName name QtNamePrefix + 'QComboBox_setAutoResize';
procedure QComboBox_sizeHint; external QtShareName name QtNamePrefix + 'QComboBox_sizeHint';
procedure QComboBox_sizePolicy; external QtShareName name QtNamePrefix + 'QComboBox_sizePolicy';
procedure QComboBox_setBackgroundColor; external QtShareName name QtNamePrefix + 'QComboBox_setBackgroundColor';
procedure QComboBox_setPalette; external QtShareName name QtNamePrefix + 'QComboBox_setPalette';
procedure QComboBox_setFont; external QtShareName name QtNamePrefix + 'QComboBox_setFont';
procedure QComboBox_setEnabled; external QtShareName name QtNamePrefix + 'QComboBox_setEnabled';
procedure QComboBox_setSizeLimit; external QtShareName name QtNamePrefix + 'QComboBox_setSizeLimit';
function QComboBox_sizeLimit; external QtShareName name QtNamePrefix + 'QComboBox_sizeLimit';
procedure QComboBox_setMaxCount; external QtShareName name QtNamePrefix + 'QComboBox_setMaxCount';
function QComboBox_maxCount; external QtShareName name QtNamePrefix + 'QComboBox_maxCount';
procedure QComboBox_setInsertionPolicy; external QtShareName name QtNamePrefix + 'QComboBox_setInsertionPolicy';
function QComboBox_insertionPolicy; external QtShareName name QtNamePrefix + 'QComboBox_insertionPolicy';
procedure QComboBox_setValidator; external QtShareName name QtNamePrefix + 'QComboBox_setValidator';
function QComboBox_validator; external QtShareName name QtNamePrefix + 'QComboBox_validator';
procedure QComboBox_setListBox; external QtShareName name QtNamePrefix + 'QComboBox_setListBox';
function QComboBox_listBox; external QtShareName name QtNamePrefix + 'QComboBox_listBox';
function QComboBox_lineEdit; external QtShareName name QtNamePrefix + 'QComboBox_lineEdit';
procedure QComboBox_setAutoCompletion; external QtShareName name QtNamePrefix + 'QComboBox_setAutoCompletion';
function QComboBox_autoCompletion; external QtShareName name QtNamePrefix + 'QComboBox_autoCompletion';
function QComboBox_eventFilter; external QtShareName name QtNamePrefix + 'QComboBox_eventFilter';
procedure QComboBox_setDuplicatesEnabled; external QtShareName name QtNamePrefix + 'QComboBox_setDuplicatesEnabled';
function QComboBox_duplicatesEnabled; external QtShareName name QtNamePrefix + 'QComboBox_duplicatesEnabled';
function QComboBox_editable; external QtShareName name QtNamePrefix + 'QComboBox_editable';
procedure QComboBox_setEditable; external QtShareName name QtNamePrefix + 'QComboBox_setEditable';
procedure QComboBox_clearValidator; external QtShareName name QtNamePrefix + 'QComboBox_clearValidator';
procedure QComboBox_clearEdit; external QtShareName name QtNamePrefix + 'QComboBox_clearEdit';
procedure QComboBox_setEditText; external QtShareName name QtNamePrefix + 'QComboBox_setEditText';

procedure QDialog_destroy; external QtShareName name QtNamePrefix + 'QDialog_destroy';
function QDialog_create; external QtShareName name QtNamePrefix + 'QDialog_create';
function QDialog_exec; external QtShareName name QtNamePrefix + 'QDialog_exec';
function QDialog_result; external QtShareName name QtNamePrefix + 'QDialog_result';
procedure QDialog_show; external QtShareName name QtNamePrefix + 'QDialog_show';
procedure QDialog_hide; external QtShareName name QtNamePrefix + 'QDialog_hide';
procedure QDialog_move(handle: QDialogH; x: Integer; y: Integer); external QtShareName name QtNamePrefix + 'QDialog_move';
procedure QDialog_move(handle: QDialogH; p: PPoint); external QtShareName name QtNamePrefix + 'QDialog_move2';
procedure QDialog_resize(handle: QDialogH; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QDialog_resize';
procedure QDialog_resize(handle: QDialogH; p1: PSize); external QtShareName name QtNamePrefix + 'QDialog_resize2';
procedure QDialog_setGeometry(handle: QDialogH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QDialog_setGeometry';
procedure QDialog_setGeometry(handle: QDialogH; p1: PRect); external QtShareName name QtNamePrefix + 'QDialog_setGeometry2';
procedure QDialog_setOrientation; external QtShareName name QtNamePrefix + 'QDialog_setOrientation';
function QDialog_orientation; external QtShareName name QtNamePrefix + 'QDialog_orientation';
procedure QDialog_setExtension; external QtShareName name QtNamePrefix + 'QDialog_setExtension';
function QDialog_extension; external QtShareName name QtNamePrefix + 'QDialog_extension';
procedure QDialog_sizeHint; external QtShareName name QtNamePrefix + 'QDialog_sizeHint';
procedure QDialog_minimumSizeHint; external QtShareName name QtNamePrefix + 'QDialog_minimumSizeHint';
procedure QDialog_setSizeGripEnabled; external QtShareName name QtNamePrefix + 'QDialog_setSizeGripEnabled';
function QDialog_isSizeGripEnabled; external QtShareName name QtNamePrefix + 'QDialog_isSizeGripEnabled';

procedure QDragObject_destroy; external QtShareName name QtNamePrefix + 'QDragObject_destroy';

function QDragObject_drag; external QtShareName name QtNamePrefix + 'QDragObject_drag';
function QDragObject_dragMove; external QtShareName name QtNamePrefix + 'QDragObject_dragMove';
procedure QDragObject_dragCopy; external QtShareName name QtNamePrefix + 'QDragObject_dragCopy';
procedure QDragObject_setPixmap(handle: QDragObjectH; p1: QPixmapH); external QtShareName name QtNamePrefix + 'QDragObject_setPixmap';
procedure QDragObject_setPixmap(handle: QDragObjectH; p1: QPixmapH; hotspot: PPoint); external QtShareName name QtNamePrefix + 'QDragObject_setPixmap2';
procedure QDragObject_pixmap; external QtShareName name QtNamePrefix + 'QDragObject_pixmap';
procedure QDragObject_pixmapHotSpot; external QtShareName name QtNamePrefix + 'QDragObject_pixmapHotSpot';
function QDragObject_source; external QtShareName name QtNamePrefix + 'QDragObject_source';
function QDragObject_target; external QtShareName name QtNamePrefix + 'QDragObject_target';
procedure QDragObject_setTarget; external QtShareName name QtNamePrefix + 'QDragObject_setTarget';
function QDragObject_to_QMimeSource; external QtSharename name QtNamePrefix + 'QDragObject_to_QMimeSource';

procedure QStoredDrag_destroy; external QtShareName name QtNamePrefix + 'QStoredDrag_destroy';
function QStoredDrag_create; external QtShareName name QtNamePrefix + 'QStoredDrag_create';
procedure QStoredDrag_setEncodedData; external QtShareName name QtNamePrefix + 'QStoredDrag_setEncodedData';
function QStoredDrag_format; external QtShareName name QtNamePrefix + 'QStoredDrag_format';
procedure QStoredDrag_encodedData; external QtShareName name QtNamePrefix + 'QStoredDrag_encodedData';

procedure QTextDrag_destroy; external QtShareName name QtNamePrefix + 'QTextDrag_destroy';
function QTextDrag_create(p1: PWideString; dragSource: QWidgetH; name: PAnsiChar): QTextDragH; external QtShareName name QtNamePrefix + 'QTextDrag_create';
function QTextDrag_create(dragSource: QWidgetH; name: PAnsiChar): QTextDragH; external QtShareName name QtNamePrefix + 'QTextDrag_create2';
procedure QTextDrag_setText; external QtShareName name QtNamePrefix + 'QTextDrag_setText';
procedure QTextDrag_setSubtype; external QtShareName name QtNamePrefix + 'QTextDrag_setSubtype';
function QTextDrag_format; external QtShareName name QtNamePrefix + 'QTextDrag_format';
procedure QTextDrag_encodedData; external QtShareName name QtNamePrefix + 'QTextDrag_encodedData';
function QTextDrag_canDecode; external QtShareName name QtNamePrefix + 'QTextDrag_canDecode';
function QTextDrag_decode(e: QMimeSourceH; s: PWideString): Boolean; external QtShareName name QtNamePrefix + 'QTextDrag_decode';
function QTextDrag_decode(e: QMimeSourceH; s: PWideString; subtype: PAnsiString): Boolean; external QtShareName name QtNamePrefix + 'QTextDrag_decode2';

procedure QImageDrag_destroy; external QtShareName name QtNamePrefix + 'QImageDrag_destroy';
function QImageDrag_create(image: QImageH; dragSource: QWidgetH; name: PAnsiChar): QImageDragH; external QtShareName name QtNamePrefix + 'QImageDrag_create';
function QImageDrag_create(dragSource: QWidgetH; name: PAnsiChar): QImageDragH; external QtShareName name QtNamePrefix + 'QImageDrag_create2';
procedure QImageDrag_setImage; external QtShareName name QtNamePrefix + 'QImageDrag_setImage';
function QImageDrag_format; external QtShareName name QtNamePrefix + 'QImageDrag_format';
procedure QImageDrag_encodedData; external QtShareName name QtNamePrefix + 'QImageDrag_encodedData';
function QImageDrag_canDecode; external QtShareName name QtNamePrefix + 'QImageDrag_canDecode';
function QImageDrag_decode(e: QMimeSourceH; i: QImageH): Boolean; external QtShareName name QtNamePrefix + 'QImageDrag_decode';
function QImageDrag_decode(e: QMimeSourceH; i: QPixmapH): Boolean; external QtShareName name QtNamePrefix + 'QImageDrag_decode2';

procedure QUriDrag_destroy; external QtShareName name QtNamePrefix + 'QUriDrag_destroy';
function QUriDrag_create(uris: QStrListH; dragSource: QWidgetH; name: PAnsiChar): QUriDragH; external QtShareName name QtNamePrefix + 'QUriDrag_create';
function QUriDrag_create(dragSource: QWidgetH; name: PAnsiChar): QUriDragH; external QtShareName name QtNamePrefix + 'QUriDrag_create2';
procedure QUriDrag_setFilenames; external QtShareName name QtNamePrefix + 'QUriDrag_setFilenames';
procedure QUriDrag_setUnicodeUris; external QtShareName name QtNamePrefix + 'QUriDrag_setUnicodeUris';
procedure QUriDrag_setUris; external QtShareName name QtNamePrefix + 'QUriDrag_setUris';
procedure QUriDrag_uriToLocalFile; external QtShareName name QtNamePrefix + 'QUriDrag_uriToLocalFile';
procedure QUriDrag_localFileToUri; external QtShareName name QtNamePrefix + 'QUriDrag_localFileToUri';
procedure QUriDrag_uriToUnicodeUri; external QtShareName name QtNamePrefix + 'QUriDrag_uriToUnicodeUri';
procedure QUriDrag_unicodeUriToUri; external QtShareName name QtNamePrefix + 'QUriDrag_unicodeUriToUri';
function QUriDrag_canDecode; external QtShareName name QtNamePrefix + 'QUriDrag_canDecode';
function QUriDrag_decode; external QtShareName name QtNamePrefix + 'QUriDrag_decode';
function QUriDrag_decodeToUnicodeUris; external QtShareName name QtNamePrefix + 'QUriDrag_decodeToUnicodeUris';
function QUriDrag_decodeLocalFiles; external QtShareName name QtNamePrefix + 'QUriDrag_decodeLocalFiles';

procedure QColorDrag_destroy; external QtShareName name QtNamePrefix + 'QColorDrag_destroy';
function QColorDrag_create(col: QColorH; dragsource: QWidgetH; name: PAnsiChar): QColorDragH; external QtShareName name QtNamePrefix + 'QColorDrag_create';
function QColorDrag_create(dragSource: QWidgetH; name: PAnsiChar): QColorDragH; external QtShareName name QtNamePrefix + 'QColorDrag_create2';
procedure QColorDrag_setColor; external QtShareName name QtNamePrefix + 'QColorDrag_setColor';
function QColorDrag_canDecode; external QtShareName name QtNamePrefix + 'QColorDrag_canDecode';
function QColorDrag_decode; external QtShareName name QtNamePrefix + 'QColorDrag_decode';

procedure QEvent_destroy; external QtShareName name QtNamePrefix + 'QEvent_destroy';
function QEvent_create; external QtShareName name QtNamePrefix + 'QEvent_create';
function QEvent_type; external QtShareName name QtNamePrefix + 'QEvent_type';

procedure QTimerEvent_destroy; external QtShareName name QtNamePrefix + 'QTimerEvent_destroy';
function QTimerEvent_create; external QtShareName name QtNamePrefix + 'QTimerEvent_create';
function QTimerEvent_timerId; external QtShareName name QtNamePrefix + 'QTimerEvent_timerId';

procedure QMouseEvent_destroy; external QtShareName name QtNamePrefix + 'QMouseEvent_destroy';
function QMouseEvent_create(_type: QEventType; pos: PPoint; button: Integer; state: Integer): QMouseEventH; external QtShareName name QtNamePrefix + 'QMouseEvent_create';
function QMouseEvent_create(_type: QEventType; pos: PPoint; globalPos: PPoint; button: Integer; state: Integer): QMouseEventH; external QtShareName name QtNamePrefix + 'QMouseEvent_create2';
function QMouseEvent_pos; external QtShareName name QtNamePrefix + 'QMouseEvent_pos';
function QMouseEvent_globalPos; external QtShareName name QtNamePrefix + 'QMouseEvent_globalPos';
function QMouseEvent_x; external QtShareName name QtNamePrefix + 'QMouseEvent_x';
function QMouseEvent_y; external QtShareName name QtNamePrefix + 'QMouseEvent_y';
function QMouseEvent_globalX; external QtShareName name QtNamePrefix + 'QMouseEvent_globalX';
function QMouseEvent_globalY; external QtShareName name QtNamePrefix + 'QMouseEvent_globalY';
function QMouseEvent_button; external QtShareName name QtNamePrefix + 'QMouseEvent_button';
function QMouseEvent_state; external QtShareName name QtNamePrefix + 'QMouseEvent_state';
function QMouseEvent_stateAfter; external QtShareName name QtNamePrefix + 'QMouseEvent_stateAfter';

procedure QWheelEvent_destroy; external QtShareName name QtNamePrefix + 'QWheelEvent_destroy';
function QWheelEvent_create(pos: PPoint; delta: Integer; state: Integer): QWheelEventH; external QtShareName name QtNamePrefix + 'QWheelEvent_create';
function QWheelEvent_create(pos: PPoint; globalPos: PPoint; delta: Integer; state: Integer): QWheelEventH; external QtShareName name QtNamePrefix + 'QWheelEvent_create2';
function QWheelEvent_delta; external QtShareName name QtNamePrefix + 'QWheelEvent_delta';
function QWheelEvent_pos; external QtShareName name QtNamePrefix + 'QWheelEvent_pos';
function QWheelEvent_globalPos; external QtShareName name QtNamePrefix + 'QWheelEvent_globalPos';
function QWheelEvent_x; external QtShareName name QtNamePrefix + 'QWheelEvent_x';
function QWheelEvent_y; external QtShareName name QtNamePrefix + 'QWheelEvent_y';
function QWheelEvent_globalX; external QtShareName name QtNamePrefix + 'QWheelEvent_globalX';
function QWheelEvent_globalY; external QtShareName name QtNamePrefix + 'QWheelEvent_globalY';
function QWheelEvent_state; external QtShareName name QtNamePrefix + 'QWheelEvent_state';
function QWheelEvent_isAccepted; external QtShareName name QtNamePrefix + 'QWheelEvent_isAccepted';
procedure QWheelEvent_accept; external QtShareName name QtNamePrefix + 'QWheelEvent_accept';
procedure QWheelEvent_ignore; external QtShareName name QtNamePrefix + 'QWheelEvent_ignore';

procedure QKeyEvent_destroy; external QtShareName name QtNamePrefix + 'QKeyEvent_destroy';
function QKeyEvent_create; external QtShareName name QtNamePrefix + 'QKeyEvent_create';
function QKeyEvent_key; external QtShareName name QtNamePrefix + 'QKeyEvent_key';
function QKeyEvent_ascii; external QtShareName name QtNamePrefix + 'QKeyEvent_ascii';
function QKeyEvent_state; external QtShareName name QtNamePrefix + 'QKeyEvent_state';
function QKeyEvent_stateAfter; external QtShareName name QtNamePrefix + 'QKeyEvent_stateAfter';
function QKeyEvent_isAccepted; external QtShareName name QtNamePrefix + 'QKeyEvent_isAccepted';
procedure QKeyEvent_text; external QtShareName name QtNamePrefix + 'QKeyEvent_text';
function QKeyEvent_isAutoRepeat; external QtShareName name QtNamePrefix + 'QKeyEvent_isAutoRepeat';
function QKeyEvent_count; external QtShareName name QtNamePrefix + 'QKeyEvent_count';
procedure QKeyEvent_accept; external QtShareName name QtNamePrefix + 'QKeyEvent_accept';
procedure QKeyEvent_ignore; external QtShareName name QtNamePrefix + 'QKeyEvent_ignore';

procedure QFocusEvent_destroy; external QtShareName name QtNamePrefix + 'QFocusEvent_destroy';
function QFocusEvent_create; external QtShareName name QtNamePrefix + 'QFocusEvent_create';
function QFocusEvent_gotFocus; external QtShareName name QtNamePrefix + 'QFocusEvent_gotFocus';
function QFocusEvent_lostFocus; external QtShareName name QtNamePrefix + 'QFocusEvent_lostFocus';
function QFocusEvent_reason; external QtShareName name QtNamePrefix + 'QFocusEvent_reason';
procedure QFocusEvent_setReason; external QtShareName name QtNamePrefix + 'QFocusEvent_setReason';
procedure QFocusEvent_resetReason; external QtShareName name QtNamePrefix + 'QFocusEvent_resetReason';

procedure QPaintEvent_destroy; external QtShareName name QtNamePrefix + 'QPaintEvent_destroy';
function QPaintEvent_create(paintRegion: QRegionH; erased: Boolean): QPaintEventH; external QtShareName name QtNamePrefix + 'QPaintEvent_create';
function QPaintEvent_create(paintRect: PRect; erased: Boolean): QPaintEventH; external QtShareName name QtNamePrefix + 'QPaintEvent_create2';
procedure QPaintEvent_rect; external QtShareName name QtNamePrefix + 'QPaintEvent_rect';
function QPaintEvent_region; external QtShareName name QtNamePrefix + 'QPaintEvent_region';
function QPaintEvent_erased; external QtShareName name QtNamePrefix + 'QPaintEvent_erased';

procedure QMoveEvent_destroy; external QtShareName name QtNamePrefix + 'QMoveEvent_destroy';
function QMoveEvent_create; external QtShareName name QtNamePrefix + 'QMoveEvent_create';
function QMoveEvent_pos; external QtShareName name QtNamePrefix + 'QMoveEvent_pos';
function QMoveEvent_oldPos; external QtShareName name QtNamePrefix + 'QMoveEvent_oldPos';

procedure QResizeEvent_destroy; external QtShareName name QtNamePrefix + 'QResizeEvent_destroy';
function QResizeEvent_create; external QtShareName name QtNamePrefix + 'QResizeEvent_create';
function QResizeEvent_size; external QtShareName name QtNamePrefix + 'QResizeEvent_size';
function QResizeEvent_oldSize; external QtShareName name QtNamePrefix + 'QResizeEvent_oldSize';

procedure QCloseEvent_destroy; external QtShareName name QtNamePrefix + 'QCloseEvent_destroy';
function QCloseEvent_create; external QtShareName name QtNamePrefix + 'QCloseEvent_create';
function QCloseEvent_isAccepted; external QtShareName name QtNamePrefix + 'QCloseEvent_isAccepted';
procedure QCloseEvent_accept; external QtShareName name QtNamePrefix + 'QCloseEvent_accept';
procedure QCloseEvent_ignore; external QtShareName name QtNamePrefix + 'QCloseEvent_ignore';

procedure QShowEvent_destroy; external QtShareName name QtNamePrefix + 'QShowEvent_destroy';
function QShowEvent_create; external QtShareName name QtNamePrefix + 'QShowEvent_create';
function QShowEvent_spontaneous; external QtShareName name QtNamePrefix + 'QShowEvent_spontaneous';

procedure QHideEvent_destroy; external QtShareName name QtNamePrefix + 'QHideEvent_destroy';
function QHideEvent_create; external QtShareName name QtNamePrefix + 'QHideEvent_create';
function QHideEvent_spontaneous; external QtShareName name QtNamePrefix + 'QHideEvent_spontaneous';

procedure QDropEvent_destroy; external QtShareName name QtNamePrefix + 'QDropEvent_destroy';
function QDropEvent_create; external QtShareName name QtNamePrefix + 'QDropEvent_create';
function QDropEvent_pos; external QtShareName name QtNamePrefix + 'QDropEvent_pos';
function QDropEvent_isAccepted; external QtShareName name QtNamePrefix + 'QDropEvent_isAccepted';
procedure QDropEvent_accept; external QtShareName name QtNamePrefix + 'QDropEvent_accept';
procedure QDropEvent_ignore; external QtShareName name QtNamePrefix + 'QDropEvent_ignore';
function QDropEvent_isActionAccepted; external QtShareName name QtNamePrefix + 'QDropEvent_isActionAccepted';
procedure QDropEvent_acceptAction; external QtShareName name QtNamePrefix + 'QDropEvent_acceptAction';
procedure QDropEvent_setAction; external QtShareName name QtNamePrefix + 'QDropEvent_setAction';
function QDropEvent_action; external QtShareName name QtNamePrefix + 'QDropEvent_action';
function QDropEvent_source; external QtShareName name QtNamePrefix + 'QDropEvent_source';
function QDropEvent_format; external QtShareName name QtNamePrefix + 'QDropEvent_format';
procedure QDropEvent_encodedData; external QtShareName name QtNamePrefix + 'QDropEvent_encodedData';
function QDropEvent_provides; external QtShareName name QtNamePrefix + 'QDropEvent_provides';
procedure QDropEvent_data; external QtShareName name QtNamePrefix + 'QDropEvent_data';
procedure QDropEvent_setPoint; external QtShareName name QtNamePrefix + 'QDropEvent_setPoint';
function QDropEvent_to_QMimeSource; external QtSharename name QtNamePrefix + 'QDropEvent_to_QMimeSource';

procedure QDragMoveEvent_destroy; external QtShareName name QtNamePrefix + 'QDragMoveEvent_destroy';
function QDragMoveEvent_create; external QtShareName name QtNamePrefix + 'QDragMoveEvent_create';
procedure QDragMoveEvent_answerRect; external QtShareName name QtNamePrefix + 'QDragMoveEvent_answerRect';
procedure QDragMoveEvent_accept(handle: QDragMoveEventH; y: Boolean); external QtShareName name QtNamePrefix + 'QDragMoveEvent_accept';
procedure QDragMoveEvent_accept(handle: QDragMoveEventH; r: PRect); external QtShareName name QtNamePrefix + 'QDragMoveEvent_accept2';
procedure QDragMoveEvent_ignore(handle: QDragMoveEventH; r: PRect); external QtShareName name QtNamePrefix + 'QDragMoveEvent_ignore';
procedure QDragMoveEvent_ignore(handle: QDragMoveEventH); external QtShareName name QtNamePrefix + 'QDragMoveEvent_ignore2';

procedure QDragEnterEvent_destroy; external QtShareName name QtNamePrefix + 'QDragEnterEvent_destroy';
function QDragEnterEvent_create; external QtShareName name QtNamePrefix + 'QDragEnterEvent_create';

procedure QDragResponseEvent_destroy; external QtShareName name QtNamePrefix + 'QDragResponseEvent_destroy';
function QDragResponseEvent_create; external QtShareName name QtNamePrefix + 'QDragResponseEvent_create';
function QDragResponseEvent_dragAccepted; external QtShareName name QtNamePrefix + 'QDragResponseEvent_dragAccepted';

procedure QDragLeaveEvent_destroy; external QtShareName name QtNamePrefix + 'QDragLeaveEvent_destroy';
function QDragLeaveEvent_create; external QtShareName name QtNamePrefix + 'QDragLeaveEvent_create';

procedure QChildEvent_destroy; external QtShareName name QtNamePrefix + 'QChildEvent_destroy';
function QChildEvent_create; external QtShareName name QtNamePrefix + 'QChildEvent_create';
function QChildEvent_child; external QtShareName name QtNamePrefix + 'QChildEvent_child';
function QChildEvent_inserted; external QtShareName name QtNamePrefix + 'QChildEvent_inserted';
function QChildEvent_removed; external QtShareName name QtNamePrefix + 'QChildEvent_removed';

procedure QCustomEvent_destroy; external QtShareName name QtNamePrefix + 'QCustomEvent_destroy';
function QCustomEvent_create(_type: Integer): QCustomEventH; external QtShareName name QtNamePrefix + 'QCustomEvent_create';
function QCustomEvent_create(_type: QEventType; data: Pointer): QCustomEventH; external QtShareName name QtNamePrefix + 'QCustomEvent_create2';
function QCustomEvent_data; external QtShareName name QtNamePrefix + 'QCustomEvent_data';
procedure QCustomEvent_setData; external QtShareName name QtNamePrefix + 'QCustomEvent_setData';

procedure QFrame_destroy; external QtShareName name QtNamePrefix + 'QFrame_destroy';
function QFrame_create; external QtShareName name QtNamePrefix + 'QFrame_create';
function QFrame_frameStyle; external QtShareName name QtNamePrefix + 'QFrame_frameStyle';
procedure QFrame_setFrameStyle; external QtShareName name QtNamePrefix + 'QFrame_setFrameStyle';
function QFrame_frameWidth; external QtShareName name QtNamePrefix + 'QFrame_frameWidth';
procedure QFrame_contentsRect; external QtShareName name QtNamePrefix + 'QFrame_contentsRect';
function QFrame_lineShapesOk; external QtShareName name QtNamePrefix + 'QFrame_lineShapesOk';
procedure QFrame_sizeHint; external QtShareName name QtNamePrefix + 'QFrame_sizeHint';
procedure QFrame_sizePolicy; external QtShareName name QtNamePrefix + 'QFrame_sizePolicy';
function QFrame_frameShape; external QtShareName name QtNamePrefix + 'QFrame_frameShape';
procedure QFrame_setFrameShape; external QtShareName name QtNamePrefix + 'QFrame_setFrameShape';
function QFrame_frameShadow; external QtShareName name QtNamePrefix + 'QFrame_frameShadow';
procedure QFrame_setFrameShadow; external QtShareName name QtNamePrefix + 'QFrame_setFrameShadow';
function QFrame_lineWidth; external QtShareName name QtNamePrefix + 'QFrame_lineWidth';
procedure QFrame_setLineWidth; external QtShareName name QtNamePrefix + 'QFrame_setLineWidth';
function QFrame_margin; external QtShareName name QtNamePrefix + 'QFrame_margin';
procedure QFrame_setMargin; external QtShareName name QtNamePrefix + 'QFrame_setMargin';
function QFrame_midLineWidth; external QtShareName name QtNamePrefix + 'QFrame_midLineWidth';
procedure QFrame_setMidLineWidth; external QtShareName name QtNamePrefix + 'QFrame_setMidLineWidth';
procedure QFrame_frameRect; external QtShareName name QtNamePrefix + 'QFrame_frameRect';
procedure QFrame_setFrameRect; external QtShareName name QtNamePrefix + 'QFrame_setFrameRect';

procedure QIconDragItem_destroy; external QtShareName name QtNamePrefix + 'QIconDragItem_destroy';
function QIconDragItem_create; external QtShareName name QtNamePrefix + 'QIconDragItem_create';
procedure QIconDragItem_data; external QtShareName name QtNamePrefix + 'QIconDragItem_data';
procedure QIconDragItem_setData; external QtShareName name QtNamePrefix + 'QIconDragItem_setData';

procedure QIconDrag_destroy; external QtShareName name QtNamePrefix + 'QIconDrag_destroy';
function QIconDrag_create; external QtShareName name QtNamePrefix + 'QIconDrag_create';
procedure QIconDrag_append; external QtShareName name QtNamePrefix + 'QIconDrag_append';
function QIconDrag_format; external QtShareName name QtNamePrefix + 'QIconDrag_format';
function QIconDrag_canDecode; external QtShareName name QtNamePrefix + 'QIconDrag_canDecode';
procedure QIconDrag_encodedData; external QtShareName name QtNamePrefix + 'QIconDrag_encodedData';

procedure QIconViewItem_destroy; external QtShareName name QtNamePrefix + 'QIconViewItem_destroy';
function QIconViewItem_create(parent: QIconViewH): QIconViewItemH; external QtShareName name QtNamePrefix + 'QIconViewItem_create';
function QIconViewItem_create(parent: QIconViewH; after: QIconViewItemH): QIconViewItemH; external QtShareName name QtNamePrefix + 'QIconViewItem_create2';
function QIconViewItem_create(parent: QIconViewH; text: PWideString): QIconViewItemH; external QtShareName name QtNamePrefix + 'QIconViewItem_create3';
function QIconViewItem_create(parent: QIconViewH; after: QIconViewItemH; text: PWideString): QIconViewItemH; external QtShareName name QtNamePrefix + 'QIconViewItem_create4';
function QIconViewItem_create(parent: QIconViewH; text: PWideString; icon: QPixmapH): QIconViewItemH; external QtShareName name QtNamePrefix + 'QIconViewItem_create5';
function QIconViewItem_create(parent: QIconViewH; after: QIconViewItemH; text: PWideString; icon: QPixmapH): QIconViewItemH; external QtShareName name QtNamePrefix + 'QIconViewItem_create6';
procedure QIconViewItem_setRenameEnabled; external QtShareName name QtNamePrefix + 'QIconViewItem_setRenameEnabled';
procedure QIconViewItem_setDragEnabled; external QtShareName name QtNamePrefix + 'QIconViewItem_setDragEnabled';
procedure QIconViewItem_setDropEnabled; external QtShareName name QtNamePrefix + 'QIconViewItem_setDropEnabled';
procedure QIconViewItem_text; external QtShareName name QtNamePrefix + 'QIconViewItem_text';
function QIconViewItem_pixmap; external QtShareName name QtNamePrefix + 'QIconViewItem_pixmap';
procedure QIconViewItem_key; external QtShareName name QtNamePrefix + 'QIconViewItem_key';
function QIconViewItem_renameEnabled; external QtShareName name QtNamePrefix + 'QIconViewItem_renameEnabled';
function QIconViewItem_dragEnabled; external QtShareName name QtNamePrefix + 'QIconViewItem_dragEnabled';
function QIconViewItem_dropEnabled; external QtShareName name QtNamePrefix + 'QIconViewItem_dropEnabled';
function QIconViewItem_iconView; external QtShareName name QtNamePrefix + 'QIconViewItem_iconView';
function QIconViewItem_prevItem; external QtShareName name QtNamePrefix + 'QIconViewItem_prevItem';
function QIconViewItem_nextItem; external QtShareName name QtNamePrefix + 'QIconViewItem_nextItem';
function QIconViewItem_index; external QtShareName name QtNamePrefix + 'QIconViewItem_index';
procedure QIconViewItem_setSelected(handle: QIconViewItemH; s: Boolean; cb: Boolean); external QtShareName name QtNamePrefix + 'QIconViewItem_setSelected';
procedure QIconViewItem_setSelected(handle: QIconViewItemH; s: Boolean); external QtShareName name QtNamePrefix + 'QIconViewItem_setSelected2';
procedure QIconViewItem_setSelectable; external QtShareName name QtNamePrefix + 'QIconViewItem_setSelectable';
function QIconViewItem_isSelected; external QtShareName name QtNamePrefix + 'QIconViewItem_isSelected';
function QIconViewItem_isSelectable; external QtShareName name QtNamePrefix + 'QIconViewItem_isSelectable';
procedure QIconViewItem_repaint; external QtShareName name QtNamePrefix + 'QIconViewItem_repaint';
procedure QIconViewItem_move(handle: QIconViewItemH; x: Integer; y: Integer); external QtShareName name QtNamePrefix + 'QIconViewItem_move';
procedure QIconViewItem_moveBy(handle: QIconViewItemH; dx: Integer; dy: Integer); external QtShareName name QtNamePrefix + 'QIconViewItem_moveBy';
procedure QIconViewItem_move(handle: QIconViewItemH; pnt: PPoint); external QtShareName name QtNamePrefix + 'QIconViewItem_move2';
procedure QIconViewItem_moveBy(handle: QIconViewItemH; pnt: PPoint); external QtShareName name QtNamePrefix + 'QIconViewItem_moveBy2';
procedure QIconViewItem_rect; external QtShareName name QtNamePrefix + 'QIconViewItem_rect';
function QIconViewItem_x; external QtShareName name QtNamePrefix + 'QIconViewItem_x';
function QIconViewItem_y; external QtShareName name QtNamePrefix + 'QIconViewItem_y';
function QIconViewItem_width; external QtShareName name QtNamePrefix + 'QIconViewItem_width';
function QIconViewItem_height; external QtShareName name QtNamePrefix + 'QIconViewItem_height';
procedure QIconViewItem_size; external QtShareName name QtNamePrefix + 'QIconViewItem_size';
procedure QIconViewItem_pos; external QtShareName name QtNamePrefix + 'QIconViewItem_pos';
procedure QIconViewItem_textRect; external QtShareName name QtNamePrefix + 'QIconViewItem_textRect';
procedure QIconViewItem_pixmapRect; external QtShareName name QtNamePrefix + 'QIconViewItem_pixmapRect';
function QIconViewItem_contains; external QtShareName name QtNamePrefix + 'QIconViewItem_contains';
function QIconViewItem_intersects; external QtShareName name QtNamePrefix + 'QIconViewItem_intersects';
function QIconViewItem_acceptDrop; external QtShareName name QtNamePrefix + 'QIconViewItem_acceptDrop';
procedure QIconViewItem_rename; external QtShareName name QtNamePrefix + 'QIconViewItem_rename';
function QIconViewItem_compare; external QtShareName name QtNamePrefix + 'QIconViewItem_compare';
procedure QIconViewItem_setText(handle: QIconViewItemH; text: PWideString); external QtShareName name QtNamePrefix + 'QIconViewItem_setText';
procedure QIconViewItem_setPixmap(handle: QIconViewItemH; icon: QPixmapH); external QtShareName name QtNamePrefix + 'QIconViewItem_setPixmap';
procedure QIconViewItem_setText(handle: QIconViewItemH; text: PWideString; recalc: Boolean; redraw: Boolean); external QtShareName name QtNamePrefix + 'QIconViewItem_setText2';
procedure QIconViewItem_setPixmap(handle: QIconViewItemH; icon: QPixmapH; recalc: Boolean; redraw: Boolean); external QtShareName name QtNamePrefix + 'QIconViewItem_setPixmap2';
procedure QIconViewItem_setKey; external QtShareName name QtNamePrefix + 'QIconViewItem_setKey';

procedure QIconView_destroy; external QtShareName name QtNamePrefix + 'QIconView_destroy';
function QIconView_create; external QtShareName name QtNamePrefix + 'QIconView_create';
procedure QIconView_insertItem; external QtShareName name QtNamePrefix + 'QIconView_insertItem';
procedure QIconView_takeItem; external QtShareName name QtNamePrefix + 'QIconView_takeItem';
function QIconView_index; external QtShareName name QtNamePrefix + 'QIconView_index';
function QIconView_firstItem; external QtShareName name QtNamePrefix + 'QIconView_firstItem';
function QIconView_lastItem; external QtShareName name QtNamePrefix + 'QIconView_lastItem';
function QIconView_currentItem; external QtShareName name QtNamePrefix + 'QIconView_currentItem';
procedure QIconView_setCurrentItem; external QtShareName name QtNamePrefix + 'QIconView_setCurrentItem';
procedure QIconView_setSelected; external QtShareName name QtNamePrefix + 'QIconView_setSelected';
function QIconView_count; external QtShareName name QtNamePrefix + 'QIconView_count';
procedure QIconView_showEvent; external QtShareName name QtNamePrefix + 'QIconView_showEvent';
procedure QIconView_setSelectionMode; external QtShareName name QtNamePrefix + 'QIconView_setSelectionMode';
function QIconView_selectionMode; external QtShareName name QtNamePrefix + 'QIconView_selectionMode';
function QIconView_findItem(handle: QIconViewH; pos: PPoint): QIconViewItemH; external QtShareName name QtNamePrefix + 'QIconView_findItem';
function QIconView_findItem(handle: QIconViewH; text: PWideString): QIconViewItemH; external QtShareName name QtNamePrefix + 'QIconView_findItem2';
procedure QIconView_selectAll; external QtShareName name QtNamePrefix + 'QIconView_selectAll';
procedure QIconView_clearSelection; external QtShareName name QtNamePrefix + 'QIconView_clearSelection';
procedure QIconView_invertSelection; external QtShareName name QtNamePrefix + 'QIconView_invertSelection';
procedure QIconView_repaintItem; external QtShareName name QtNamePrefix + 'QIconView_repaintItem';
procedure QIconView_ensureItemVisible; external QtShareName name QtNamePrefix + 'QIconView_ensureItemVisible';
function QIconView_findFirstVisibleItem; external QtShareName name QtNamePrefix + 'QIconView_findFirstVisibleItem';
function QIconView_findLastVisibleItem; external QtShareName name QtNamePrefix + 'QIconView_findLastVisibleItem';
procedure QIconView_clear; external QtShareName name QtNamePrefix + 'QIconView_clear';
procedure QIconView_setGridX; external QtShareName name QtNamePrefix + 'QIconView_setGridX';
procedure QIconView_setGridY; external QtShareName name QtNamePrefix + 'QIconView_setGridY';
function QIconView_gridX; external QtShareName name QtNamePrefix + 'QIconView_gridX';
function QIconView_gridY; external QtShareName name QtNamePrefix + 'QIconView_gridY';
procedure QIconView_setSpacing; external QtShareName name QtNamePrefix + 'QIconView_setSpacing';
function QIconView_spacing; external QtShareName name QtNamePrefix + 'QIconView_spacing';
procedure QIconView_setItemTextPos; external QtShareName name QtNamePrefix + 'QIconView_setItemTextPos';
function QIconView_itemTextPos; external QtShareName name QtNamePrefix + 'QIconView_itemTextPos';
procedure QIconView_setItemTextBackground; external QtShareName name QtNamePrefix + 'QIconView_setItemTextBackground';
function QIconView_itemTextBackground; external QtShareName name QtNamePrefix + 'QIconView_itemTextBackground';
procedure QIconView_setArrangement; external QtShareName name QtNamePrefix + 'QIconView_setArrangement';
function QIconView_arrangement; external QtShareName name QtNamePrefix + 'QIconView_arrangement';
procedure QIconView_setResizeMode; external QtShareName name QtNamePrefix + 'QIconView_setResizeMode';
function QIconView_resizeMode; external QtShareName name QtNamePrefix + 'QIconView_resizeMode';
procedure QIconView_setMaxItemWidth; external QtShareName name QtNamePrefix + 'QIconView_setMaxItemWidth';
function QIconView_maxItemWidth; external QtShareName name QtNamePrefix + 'QIconView_maxItemWidth';
procedure QIconView_setMaxItemTextLength; external QtShareName name QtNamePrefix + 'QIconView_setMaxItemTextLength';
function QIconView_maxItemTextLength; external QtShareName name QtNamePrefix + 'QIconView_maxItemTextLength';
procedure QIconView_setAutoArrange; external QtShareName name QtNamePrefix + 'QIconView_setAutoArrange';
function QIconView_autoArrange; external QtShareName name QtNamePrefix + 'QIconView_autoArrange';
procedure QIconView_setShowToolTips; external QtShareName name QtNamePrefix + 'QIconView_setShowToolTips';
function QIconView_showToolTips; external QtShareName name QtNamePrefix + 'QIconView_showToolTips';
procedure QIconView_setSorting; external QtShareName name QtNamePrefix + 'QIconView_setSorting';
function QIconView_sorting; external QtShareName name QtNamePrefix + 'QIconView_sorting';
function QIconView_sortDirection; external QtShareName name QtNamePrefix + 'QIconView_sortDirection';
procedure QIconView_setItemsMovable; external QtShareName name QtNamePrefix + 'QIconView_setItemsMovable';
function QIconView_itemsMovable; external QtShareName name QtNamePrefix + 'QIconView_itemsMovable';
procedure QIconView_setWordWrapIconText; external QtShareName name QtNamePrefix + 'QIconView_setWordWrapIconText';
function QIconView_wordWrapIconText; external QtShareName name QtNamePrefix + 'QIconView_wordWrapIconText';
function QIconView_eventFilter; external QtShareName name QtNamePrefix + 'QIconView_eventFilter';
procedure QIconView_minimumSizeHint; external QtShareName name QtNamePrefix + 'QIconView_minimumSizeHint';
procedure QIconView_sizePolicy; external QtShareName name QtNamePrefix + 'QIconView_sizePolicy';
procedure QIconView_sizeHint; external QtShareName name QtNamePrefix + 'QIconView_sizeHint';
procedure QIconView_sort; external QtShareName name QtNamePrefix + 'QIconView_sort';
procedure QIconView_setFont; external QtShareName name QtNamePrefix + 'QIconView_setFont';
procedure QIconView_setPalette; external QtShareName name QtNamePrefix + 'QIconView_setPalette';
procedure QIconView_arrangeItemsInGrid(handle: QIconViewH; grid: PSize; update: Boolean); external QtShareName name QtNamePrefix + 'QIconView_arrangeItemsInGrid';
procedure QIconView_arrangeItemsInGrid(handle: QIconViewH; update: Boolean); external QtShareName name QtNamePrefix + 'QIconView_arrangeItemsInGrid2';
procedure QIconView_setContentsPos; external QtShareName name QtNamePrefix + 'QIconView_setContentsPos';
procedure QIconView_updateContents; external QtShareName name QtNamePrefix + 'QIconView_updateContents';

procedure QLCDNumber_destroy; external QtShareName name QtNamePrefix + 'QLCDNumber_destroy';
function QLCDNumber_create(parent: QWidgetH; name: PAnsiChar): QLCDNumberH; external QtShareName name QtNamePrefix + 'QLCDNumber_create';
function QLCDNumber_create(numDigits: Cardinal; parent: QWidgetH; name: PAnsiChar): QLCDNumberH; external QtShareName name QtNamePrefix + 'QLCDNumber_create2';
function QLCDNumber_smallDecimalPoint; external QtShareName name QtNamePrefix + 'QLCDNumber_smallDecimalPoint';
function QLCDNumber_numDigits; external QtShareName name QtNamePrefix + 'QLCDNumber_numDigits';
procedure QLCDNumber_setNumDigits; external QtShareName name QtNamePrefix + 'QLCDNumber_setNumDigits';
function QLCDNumber_checkOverflow(handle: QLCDNumberH; num: Double): Boolean; external QtShareName name QtNamePrefix + 'QLCDNumber_checkOverflow';
function QLCDNumber_checkOverflow(handle: QLCDNumberH; num: Integer): Boolean; external QtShareName name QtNamePrefix + 'QLCDNumber_checkOverflow2';
function QLCDNumber_mode; external QtShareName name QtNamePrefix + 'QLCDNumber_mode';
procedure QLCDNumber_setMode; external QtShareName name QtNamePrefix + 'QLCDNumber_setMode';
function QLCDNumber_segmentStyle; external QtShareName name QtNamePrefix + 'QLCDNumber_segmentStyle';
procedure QLCDNumber_setSegmentStyle; external QtShareName name QtNamePrefix + 'QLCDNumber_setSegmentStyle';
function QLCDNumber_value; external QtShareName name QtNamePrefix + 'QLCDNumber_value';
function QLCDNumber_intValue; external QtShareName name QtNamePrefix + 'QLCDNumber_intValue';
procedure QLCDNumber_sizeHint; external QtShareName name QtNamePrefix + 'QLCDNumber_sizeHint';
procedure QLCDNumber_sizePolicy; external QtShareName name QtNamePrefix + 'QLCDNumber_sizePolicy';
procedure QLCDNumber_display(handle: QLCDNumberH; num: Integer); external QtShareName name QtNamePrefix + 'QLCDNumber_display';
procedure QLCDNumber_display(handle: QLCDNumberH; num: Double); external QtShareName name QtNamePrefix + 'QLCDNumber_display2';
procedure QLCDNumber_display(handle: QLCDNumberH; str: PWideString); external QtShareName name QtNamePrefix + 'QLCDNumber_display3';
procedure QLCDNumber_setHexMode; external QtShareName name QtNamePrefix + 'QLCDNumber_setHexMode';
procedure QLCDNumber_setDecMode; external QtShareName name QtNamePrefix + 'QLCDNumber_setDecMode';
procedure QLCDNumber_setOctMode; external QtShareName name QtNamePrefix + 'QLCDNumber_setOctMode';
procedure QLCDNumber_setBinMode; external QtShareName name QtNamePrefix + 'QLCDNumber_setBinMode';
procedure QLCDNumber_setSmallDecimalPoint; external QtShareName name QtNamePrefix + 'QLCDNumber_setSmallDecimalPoint';

procedure QLineEdit_destroy; external QtShareName name QtNamePrefix + 'QLineEdit_destroy';
function QLineEdit_create(parent: QWidgetH; name: PAnsiChar): QLineEditH; external QtShareName name QtNamePrefix + 'QLineEdit_create';
function QLineEdit_create(p1: PWideString; parent: QWidgetH; name: PAnsiChar): QLineEditH; external QtShareName name QtNamePrefix + 'QLineEdit_create2';
procedure QLineEdit_text; external QtShareName name QtNamePrefix + 'QLineEdit_text';
procedure QLineEdit_displayText; external QtShareName name QtNamePrefix + 'QLineEdit_displayText';
function QLineEdit_maxLength; external QtShareName name QtNamePrefix + 'QLineEdit_maxLength';
procedure QLineEdit_setMaxLength; external QtShareName name QtNamePrefix + 'QLineEdit_setMaxLength';
procedure QLineEdit_setFrame; external QtShareName name QtNamePrefix + 'QLineEdit_setFrame';
function QLineEdit_frame; external QtShareName name QtNamePrefix + 'QLineEdit_frame';
procedure QLineEdit_setEchoMode; external QtShareName name QtNamePrefix + 'QLineEdit_setEchoMode';
function QLineEdit_echoMode; external QtShareName name QtNamePrefix + 'QLineEdit_echoMode';
procedure QLineEdit_setReadOnly; external QtShareName name QtNamePrefix + 'QLineEdit_setReadOnly';
function QLineEdit_isReadOnly; external QtShareName name QtNamePrefix + 'QLineEdit_isReadOnly';
procedure QLineEdit_setValidator; external QtShareName name QtNamePrefix + 'QLineEdit_setValidator';
function QLineEdit_validator; external QtShareName name QtNamePrefix + 'QLineEdit_validator';
procedure QLineEdit_sizeHint; external QtShareName name QtNamePrefix + 'QLineEdit_sizeHint';
procedure QLineEdit_minimumSizeHint; external QtShareName name QtNamePrefix + 'QLineEdit_minimumSizeHint';
procedure QLineEdit_sizePolicy; external QtShareName name QtNamePrefix + 'QLineEdit_sizePolicy';
procedure QLineEdit_setEnabled; external QtShareName name QtNamePrefix + 'QLineEdit_setEnabled';
procedure QLineEdit_setFont; external QtShareName name QtNamePrefix + 'QLineEdit_setFont';
procedure QLineEdit_setPalette; external QtShareName name QtNamePrefix + 'QLineEdit_setPalette';
procedure QLineEdit_setSelection; external QtShareName name QtNamePrefix + 'QLineEdit_setSelection';
procedure QLineEdit_setCursorPosition; external QtShareName name QtNamePrefix + 'QLineEdit_setCursorPosition';
function QLineEdit_cursorPosition; external QtShareName name QtNamePrefix + 'QLineEdit_cursorPosition';
function QLineEdit_validateAndSet; external QtShareName name QtNamePrefix + 'QLineEdit_validateAndSet';
procedure QLineEdit_cut; external QtShareName name QtNamePrefix + 'QLineEdit_cut';
procedure QLineEdit_copy; external QtShareName name QtNamePrefix + 'QLineEdit_copy';
procedure QLineEdit_paste; external QtShareName name QtNamePrefix + 'QLineEdit_paste';
procedure QLineEdit_setAlignment; external QtShareName name QtNamePrefix + 'QLineEdit_setAlignment';
function QLineEdit_alignment; external QtShareName name QtNamePrefix + 'QLineEdit_alignment';
procedure QLineEdit_cursorLeft; external QtShareName name QtNamePrefix + 'QLineEdit_cursorLeft';
procedure QLineEdit_cursorRight; external QtShareName name QtNamePrefix + 'QLineEdit_cursorRight';
procedure QLineEdit_cursorWordForward; external QtShareName name QtNamePrefix + 'QLineEdit_cursorWordForward';
procedure QLineEdit_cursorWordBackward; external QtShareName name QtNamePrefix + 'QLineEdit_cursorWordBackward';
procedure QLineEdit_backspace; external QtShareName name QtNamePrefix + 'QLineEdit_backspace';
procedure QLineEdit_del; external QtShareName name QtNamePrefix + 'QLineEdit_del';
procedure QLineEdit_home; external QtShareName name QtNamePrefix + 'QLineEdit_home';
procedure QLineEdit_end; external QtShareName name QtNamePrefix + 'QLineEdit_end';
procedure QLineEdit_setEdited; external QtShareName name QtNamePrefix + 'QLineEdit_setEdited';
function QLineEdit_edited; external QtShareName name QtNamePrefix + 'QLineEdit_edited';
function QLineEdit_hasMarkedText; external QtShareName name QtNamePrefix + 'QLineEdit_hasMarkedText';
procedure QLineEdit_markedText; external QtShareName name QtNamePrefix + 'QLineEdit_markedText';
procedure QLineEdit_setText; external QtShareName name QtNamePrefix + 'QLineEdit_setText';
procedure QLineEdit_selectAll; external QtShareName name QtNamePrefix + 'QLineEdit_selectAll';
procedure QLineEdit_deselect; external QtShareName name QtNamePrefix + 'QLineEdit_deselect';
procedure QLineEdit_clearValidator; external QtShareName name QtNamePrefix + 'QLineEdit_clearValidator';
procedure QLineEdit_insert; external QtShareName name QtNamePrefix + 'QLineEdit_insert';
procedure QLineEdit_clear; external QtShareName name QtNamePrefix + 'QLineEdit_clear';

procedure QListBox_destroy; external QtShareName name QtNamePrefix + 'QListBox_destroy';
function QListBox_create; external QtShareName name QtNamePrefix + 'QListBox_create';
procedure QListBox_setFont; external QtShareName name QtNamePrefix + 'QListBox_setFont';
function QListBox_count; external QtShareName name QtNamePrefix + 'QListBox_count';
procedure QListBox_insertStringList; external QtShareName name QtNamePrefix + 'QListBox_insertStringList';
procedure QListBox_insertStrList(handle: QListBoxH; p1: QStrListH; index: Integer); external QtShareName name QtNamePrefix + 'QListBox_insertStrList';

procedure QListBox_insertStrList(handle: QListBoxH; p1: PPAnsiChar; numStrings: Integer; index: Integer); external QtShareName name QtNamePrefix + 'QListBox_insertStrList3';
procedure QListBox_insertItem(handle: QListBoxH; p1: QListBoxItemH; index: Integer); external QtShareName name QtNamePrefix + 'QListBox_insertItem';
procedure QListBox_insertItem(handle: QListBoxH; p1: QListBoxItemH; after: QListBoxItemH); external QtShareName name QtNamePrefix + 'QListBox_insertItem2';
procedure QListBox_insertItem(handle: QListBoxH; text: PWideString; index: Integer); external QtShareName name QtNamePrefix + 'QListBox_insertItem3';
procedure QListBox_insertItem(handle: QListBoxH; pixmap: QPixmapH; index: Integer); external QtShareName name QtNamePrefix + 'QListBox_insertItem4';
procedure QListBox_insertItem(handle: QListBoxH; pixmap: QPixmapH; text: PWideString; index: Integer); external QtShareName name QtNamePrefix + 'QListBox_insertItem5';
procedure QListBox_removeItem; external QtShareName name QtNamePrefix + 'QListBox_removeItem';
procedure QListBox_clear; external QtShareName name QtNamePrefix + 'QListBox_clear';
procedure QListBox_text; external QtShareName name QtNamePrefix + 'QListBox_text';
function QListBox_pixmap; external QtShareName name QtNamePrefix + 'QListBox_pixmap';
procedure QListBox_changeItem(handle: QListBoxH; p1: QListBoxItemH; index: Integer); external QtShareName name QtNamePrefix + 'QListBox_changeItem';
procedure QListBox_changeItem(handle: QListBoxH; text: PWideString; index: Integer); external QtShareName name QtNamePrefix + 'QListBox_changeItem2';
procedure QListBox_changeItem(handle: QListBoxH; pixmap: QPixmapH; index: Integer); external QtShareName name QtNamePrefix + 'QListBox_changeItem3';
procedure QListBox_changeItem(handle: QListBoxH; pixmap: QPixmapH; text: PWideString; index: Integer); external QtShareName name QtNamePrefix + 'QListBox_changeItem4';
procedure QListBox_takeItem; external QtShareName name QtNamePrefix + 'QListBox_takeItem';
function QListBox_numItemsVisible; external QtShareName name QtNamePrefix + 'QListBox_numItemsVisible';
function QListBox_currentItem; external QtShareName name QtNamePrefix + 'QListBox_currentItem';
procedure QListBox_currentText; external QtShareName name QtNamePrefix + 'QListBox_currentText';
procedure QListBox_setCurrentItem(handle: QListBoxH; index: Integer); external QtShareName name QtNamePrefix + 'QListBox_setCurrentItem';
procedure QListBox_setCurrentItem(handle: QListBoxH; p1: QListBoxItemH); external QtShareName name QtNamePrefix + 'QListBox_setCurrentItem2';
procedure QListBox_centerCurrentItem; external QtShareName name QtNamePrefix + 'QListBox_centerCurrentItem';
function QListBox_topItem; external QtShareName name QtNamePrefix + 'QListBox_topItem';
procedure QListBox_setTopItem; external QtShareName name QtNamePrefix + 'QListBox_setTopItem';
procedure QListBox_setBottomItem; external QtShareName name QtNamePrefix + 'QListBox_setBottomItem';
function QListBox_maxItemWidth; external QtShareName name QtNamePrefix + 'QListBox_maxItemWidth';
procedure QListBox_setSelectionMode; external QtShareName name QtNamePrefix + 'QListBox_setSelectionMode';
function QListBox_selectionMode; external QtShareName name QtNamePrefix + 'QListBox_selectionMode';
procedure QListBox_setMultiSelection; external QtShareName name QtNamePrefix + 'QListBox_setMultiSelection';
function QListBox_isMultiSelection; external QtShareName name QtNamePrefix + 'QListBox_isMultiSelection';
procedure QListBox_setSelected(handle: QListBoxH; p1: QListBoxItemH; p2: Boolean); external QtShareName name QtNamePrefix + 'QListBox_setSelected';
procedure QListBox_setSelected(handle: QListBoxH; p1: Integer; p2: Boolean); external QtShareName name QtNamePrefix + 'QListBox_setSelected2';
function QListBox_isSelected(handle: QListBoxH; p1: Integer): Boolean; external QtShareName name QtNamePrefix + 'QListBox_isSelected';
function QListBox_isSelected(handle: QListBoxH; p1: QListBoxItemH): Boolean; external QtShareName name QtNamePrefix + 'QListBox_isSelected2';
procedure QListBox_sizeHint; external QtShareName name QtNamePrefix + 'QListBox_sizeHint';
procedure QListBox_minimumSizeHint; external QtShareName name QtNamePrefix + 'QListBox_minimumSizeHint';
function QListBox_item; external QtShareName name QtNamePrefix + 'QListBox_item';
function QListBox_index; external QtShareName name QtNamePrefix + 'QListBox_index';
function QListBox_findItem; external QtShareName name QtNamePrefix + 'QListBox_findItem';
procedure QListBox_triggerUpdate; external QtShareName name QtNamePrefix + 'QListBox_triggerUpdate';
function QListBox_itemVisible(handle: QListBoxH; index: Integer): Boolean; external QtShareName name QtNamePrefix + 'QListBox_itemVisible';
function QListBox_itemVisible(handle: QListBoxH; p1: QListBoxItemH): Boolean; external QtShareName name QtNamePrefix + 'QListBox_itemVisible2';
procedure QListBox_setColumnMode(handle: QListBoxH; p1: QListBoxLayoutMode); external QtShareName name QtNamePrefix + 'QListBox_setColumnMode';
procedure QListBox_setColumnMode(handle: QListBoxH; p1: Integer); external QtShareName name QtNamePrefix + 'QListBox_setColumnMode2';
procedure QListBox_setRowMode(handle: QListBoxH; p1: QListBoxLayoutMode); external QtShareName name QtNamePrefix + 'QListBox_setRowMode';
procedure QListBox_setRowMode(handle: QListBoxH; p1: Integer); external QtShareName name QtNamePrefix + 'QListBox_setRowMode2';
function QListBox_columnMode; external QtShareName name QtNamePrefix + 'QListBox_columnMode';
function QListBox_rowMode; external QtShareName name QtNamePrefix + 'QListBox_rowMode';
function QListBox_numColumns; external QtShareName name QtNamePrefix + 'QListBox_numColumns';
function QListBox_numRows; external QtShareName name QtNamePrefix + 'QListBox_numRows';
function QListBox_variableWidth; external QtShareName name QtNamePrefix + 'QListBox_variableWidth';
procedure QListBox_setVariableWidth; external QtShareName name QtNamePrefix + 'QListBox_setVariableWidth';
function QListBox_variableHeight; external QtShareName name QtNamePrefix + 'QListBox_variableHeight';
procedure QListBox_setVariableHeight; external QtShareName name QtNamePrefix + 'QListBox_setVariableHeight';
procedure QListBox_viewportPaintEvent; external QtShareName name QtNamePrefix + 'QListBox_viewportPaintEvent';
function QListBox_dragSelect; external QtShareName name QtNamePrefix + 'QListBox_dragSelect';
procedure QListBox_setDragSelect; external QtShareName name QtNamePrefix + 'QListBox_setDragSelect';
function QListBox_autoScroll; external QtShareName name QtNamePrefix + 'QListBox_autoScroll';
procedure QListBox_setAutoScroll; external QtShareName name QtNamePrefix + 'QListBox_setAutoScroll';
function QListBox_autoScrollBar; external QtShareName name QtNamePrefix + 'QListBox_autoScrollBar';
procedure QListBox_setAutoScrollBar; external QtShareName name QtNamePrefix + 'QListBox_setAutoScrollBar';
function QListBox_scrollBar; external QtShareName name QtNamePrefix + 'QListBox_scrollBar';
procedure QListBox_setScrollBar; external QtShareName name QtNamePrefix + 'QListBox_setScrollBar';
function QListBox_autoBottomScrollBar; external QtShareName name QtNamePrefix + 'QListBox_autoBottomScrollBar';
procedure QListBox_setAutoBottomScrollBar; external QtShareName name QtNamePrefix + 'QListBox_setAutoBottomScrollBar';
function QListBox_bottomScrollBar; external QtShareName name QtNamePrefix + 'QListBox_bottomScrollBar';
procedure QListBox_setBottomScrollBar; external QtShareName name QtNamePrefix + 'QListBox_setBottomScrollBar';
function QListBox_smoothScrolling; external QtShareName name QtNamePrefix + 'QListBox_smoothScrolling';
procedure QListBox_setSmoothScrolling; external QtShareName name QtNamePrefix + 'QListBox_setSmoothScrolling';
function QListBox_autoUpdate; external QtShareName name QtNamePrefix + 'QListBox_autoUpdate';
procedure QListBox_setAutoUpdate; external QtShareName name QtNamePrefix + 'QListBox_setAutoUpdate';
procedure QListBox_setFixedVisibleLines; external QtShareName name QtNamePrefix + 'QListBox_setFixedVisibleLines';
procedure QListBox_inSort(handle: QListBoxH; p1: QListBoxItemH); external QtShareName name QtNamePrefix + 'QListBox_inSort';
procedure QListBox_inSort(handle: QListBoxH; text: PWideString); external QtShareName name QtNamePrefix + 'QListBox_inSort2';
function QListBox_cellHeight(handle: QListBoxH; i: Integer): Integer; external QtShareName name QtNamePrefix + 'QListBox_cellHeight';
function QListBox_cellHeight(handle: QListBoxH): Integer; external QtShareName name QtNamePrefix + 'QListBox_cellHeight2';
function QListBox_cellWidth(handle: QListBoxH): Integer; external QtShareName name QtNamePrefix + 'QListBox_cellWidth';
function QListBox_cellWidth(handle: QListBoxH; i: Integer): Integer; external QtShareName name QtNamePrefix + 'QListBox_cellWidth2';
function QListBox_numCols; external QtShareName name QtNamePrefix + 'QListBox_numCols';
function QListBox_itemHeight; external QtShareName name QtNamePrefix + 'QListBox_itemHeight';
function QListBox_itemAt; external QtShareName name QtNamePrefix + 'QListBox_itemAt';
procedure QListBox_itemRect; external QtShareName name QtNamePrefix + 'QListBox_itemRect';
function QListBox_firstItem; external QtShareName name QtNamePrefix + 'QListBox_firstItem';
procedure QListBox_sort; external QtShareName name QtNamePrefix + 'QListBox_sort';
procedure QListBox_ensureCurrentVisible; external QtShareName name QtNamePrefix + 'QListBox_ensureCurrentVisible';
procedure QListBox_clearSelection; external QtShareName name QtNamePrefix + 'QListBox_clearSelection';
procedure QListBox_selectAll; external QtShareName name QtNamePrefix + 'QListBox_selectAll';
procedure QListBox_invertSelection; external QtShareName name QtNamePrefix + 'QListBox_invertSelection';

procedure QListBoxItem_destroy; external QtShareName name QtNamePrefix + 'QListBoxItem_destroy';
function QListBoxItem_create(listbox: QListBoxH): QListBoxItemH; external QtShareName name QtNamePrefix + 'QListBoxItem_create';
function QListBoxItem_create(listbox: QListBoxH; after: QListBoxItemH): QListBoxItemH; external QtShareName name QtNamePrefix + 'QListBoxItem_create2';
procedure QListBoxItem_text; external QtShareName name QtNamePrefix + 'QListBoxItem_text';
function QListBoxItem_pixmap; external QtShareName name QtNamePrefix + 'QListBoxItem_pixmap';
function QListBoxItem_height; external QtShareName name QtNamePrefix + 'QListBoxItem_height';
function QListBoxItem_width; external QtShareName name QtNamePrefix + 'QListBoxItem_width';
function QListBoxItem_selected; external QtShareName name QtNamePrefix + 'QListBoxItem_selected';
function QListBoxItem_current; external QtShareName name QtNamePrefix + 'QListBoxItem_current';
function QListBoxItem_listBox; external QtShareName name QtNamePrefix + 'QListBoxItem_listBox';
procedure QListBoxItem_setSelectable; external QtShareName name QtNamePrefix + 'QListBoxItem_setSelectable';
function QListBoxItem_isSelectable; external QtShareName name QtNamePrefix + 'QListBoxItem_isSelectable';
function QListBoxItem_next; external QtShareName name QtNamePrefix + 'QListBoxItem_next';
function QListBoxItem_prev; external QtShareName name QtNamePrefix + 'QListBoxItem_prev';

procedure QListBoxText_destroy; external QtShareName name QtNamePrefix + 'QListBoxText_destroy';
function QListBoxText_create(listbox: QListBoxH; text: PWideString): QListBoxTextH; external QtShareName name QtNamePrefix + 'QListBoxText_create';
function QListBoxText_create(text: PWideString): QListBoxTextH; external QtShareName name QtNamePrefix + 'QListBoxText_create2';
function QListBoxText_create(listbox: QListBoxH; text: PWideString; after: QListBoxItemH): QListBoxTextH; external QtShareName name QtNamePrefix + 'QListBoxText_create3';
function QListBoxText_height; external QtShareName name QtNamePrefix + 'QListBoxText_height';
function QListBoxText_width; external QtShareName name QtNamePrefix + 'QListBoxText_width';

procedure QListBoxPixmap_destroy; external QtShareName name QtNamePrefix + 'QListBoxPixmap_destroy';
function QListBoxPixmap_create(listbox: QListBoxH; p2: QPixmapH): QListBoxPixmapH; external QtShareName name QtNamePrefix + 'QListBoxPixmap_create';
function QListBoxPixmap_create(p1: QPixmapH): QListBoxPixmapH; external QtShareName name QtNamePrefix + 'QListBoxPixmap_create2';
function QListBoxPixmap_create(listbox: QListBoxH; pix: QPixmapH; after: QListBoxItemH): QListBoxPixmapH; external QtShareName name QtNamePrefix + 'QListBoxPixmap_create3';
function QListBoxPixmap_create(listbox: QListBoxH; p2: QPixmapH; p3: PWideString): QListBoxPixmapH; external QtShareName name QtNamePrefix + 'QListBoxPixmap_create4';
function QListBoxPixmap_create(p1: QPixmapH; p2: PWideString): QListBoxPixmapH; external QtShareName name QtNamePrefix + 'QListBoxPixmap_create5';
function QListBoxPixmap_create(listbox: QListBoxH; pix: QPixmapH; p3: PWideString; after: QListBoxItemH): QListBoxPixmapH; external QtShareName name QtNamePrefix + 'QListBoxPixmap_create6';
function QListBoxPixmap_pixmap; external QtShareName name QtNamePrefix + 'QListBoxPixmap_pixmap';
function QListBoxPixmap_height; external QtShareName name QtNamePrefix + 'QListBoxPixmap_height';
function QListBoxPixmap_width; external QtShareName name QtNamePrefix + 'QListBoxPixmap_width';

procedure QListViewItem_destroy; external QtShareName name QtNamePrefix + 'QListViewItem_destroy';
function QListViewItem_create(parent: QListViewH): QListViewItemH; external QtShareName name QtNamePrefix + 'QListViewItem_create';
function QListViewItem_create(parent: QListViewItemH): QListViewItemH; external QtShareName name QtNamePrefix + 'QListViewItem_create2';
function QListViewItem_create(parent: QListViewH; after: QListViewItemH): QListViewItemH; external QtShareName name QtNamePrefix + 'QListViewItem_create3';
function QListViewItem_create(parent: QListViewItemH; after: QListViewItemH): QListViewItemH; external QtShareName name QtNamePrefix + 'QListViewItem_create4';
function QListViewItem_create(parent: QListViewH; p2: PWideString; p3: PWideString; p4: PWideString; p5: PWideString; p6: PWideString; p7: PWideString; p8: PWideString; p9: PWideString): QListViewItemH; external QtShareName name QtNamePrefix + 'QListViewItem_create5';
function QListViewItem_create(parent: QListViewItemH; p2: PWideString; p3: PWideString; p4: PWideString; p5: PWideString; p6: PWideString; p7: PWideString; p8: PWideString; p9: PWideString): QListViewItemH; external QtShareName name QtNamePrefix + 'QListViewItem_create6';
function QListViewItem_create(parent: QListViewH; after: QListViewItemH; p3: PWideString; p4: PWideString; p5: PWideString; p6: PWideString; p7: PWideString; p8: PWideString; p9: PWideString; p10: PWideString): QListViewItemH; external QtShareName name QtNamePrefix + 'QListViewItem_create7';
function QListViewItem_create(parent: QListViewItemH; after: QListViewItemH; p3: PWideString; p4: PWideString; p5: PWideString; p6: PWideString; p7: PWideString; p8: PWideString; p9: PWideString; p10: PWideString): QListViewItemH; external QtShareName name QtNamePrefix + 'QListViewItem_create8';
procedure QListViewItem_insertItem; external QtShareName name QtNamePrefix + 'QListViewItem_insertItem';
procedure QListViewItem_takeItem; external QtShareName name QtNamePrefix + 'QListViewItem_takeItem';
procedure QListViewItem_removeItem; external QtShareName name QtNamePrefix + 'QListViewItem_removeItem';
function QListViewItem_height; external QtShareName name QtNamePrefix + 'QListViewItem_height';
procedure QListViewItem_invalidateHeight; external QtShareName name QtNamePrefix + 'QListViewItem_invalidateHeight';
function QListViewItem_totalHeight; external QtShareName name QtNamePrefix + 'QListViewItem_totalHeight';
function QListViewItem_width; external QtShareName name QtNamePrefix + 'QListViewItem_width';
procedure QListViewItem_widthChanged; external QtShareName name QtNamePrefix + 'QListViewItem_widthChanged';
function QListViewItem_depth; external QtShareName name QtNamePrefix + 'QListViewItem_depth';
procedure QListViewItem_setText; external QtShareName name QtNamePrefix + 'QListViewItem_setText';
procedure QListViewItem_text; external QtShareName name QtNamePrefix + 'QListViewItem_text';
procedure QListViewItem_setPixmap; external QtShareName name QtNamePrefix + 'QListViewItem_setPixmap';
function QListViewItem_pixmap; external QtShareName name QtNamePrefix + 'QListViewItem_pixmap';
procedure QListViewItem_key; external QtShareName name QtNamePrefix + 'QListViewItem_key';
procedure QListViewItem_sortChildItems; external QtShareName name QtNamePrefix + 'QListViewItem_sortChildItems';
function QListViewItem_childCount; external QtShareName name QtNamePrefix + 'QListViewItem_childCount';
function QListViewItem_isOpen; external QtShareName name QtNamePrefix + 'QListViewItem_isOpen';
procedure QListViewItem_setOpen; external QtShareName name QtNamePrefix + 'QListViewItem_setOpen';
procedure QListViewItem_setup; external QtShareName name QtNamePrefix + 'QListViewItem_setup';
procedure QListViewItem_setSelected; external QtShareName name QtNamePrefix + 'QListViewItem_setSelected';
function QListViewItem_isSelected; external QtShareName name QtNamePrefix + 'QListViewItem_isSelected';
procedure QListViewItem_paintCell; external QtShareName name QtNamePrefix + 'QListViewItem_paintCell';
procedure QListViewItem_paintBranches; external QtShareName name QtNamePrefix + 'QListViewItem_paintBranches';
procedure QListViewItem_paintFocus; external QtShareName name QtNamePrefix + 'QListViewItem_paintFocus';
function QListViewItem_firstChild; external QtShareName name QtNamePrefix + 'QListViewItem_firstChild';
function QListViewItem_nextSibling; external QtShareName name QtNamePrefix + 'QListViewItem_nextSibling';
function QListViewItem_parent; external QtShareName name QtNamePrefix + 'QListViewItem_parent';
function QListViewItem_itemAbove; external QtShareName name QtNamePrefix + 'QListViewItem_itemAbove';
function QListViewItem_itemBelow; external QtShareName name QtNamePrefix + 'QListViewItem_itemBelow';
function QListViewItem_itemPos; external QtShareName name QtNamePrefix + 'QListViewItem_itemPos';
function QListViewItem_listView; external QtShareName name QtNamePrefix + 'QListViewItem_listView';
procedure QListViewItem_setSelectable; external QtShareName name QtNamePrefix + 'QListViewItem_setSelectable';
function QListViewItem_isSelectable; external QtShareName name QtNamePrefix + 'QListViewItem_isSelectable';
procedure QListViewItem_setExpandable; external QtShareName name QtNamePrefix + 'QListViewItem_setExpandable';
function QListViewItem_isExpandable; external QtShareName name QtNamePrefix + 'QListViewItem_isExpandable';
procedure QListViewItem_repaint; external QtShareName name QtNamePrefix + 'QListViewItem_repaint';
procedure QListViewItem_sort; external QtShareName name QtNamePrefix + 'QListViewItem_sort';
procedure QListViewItem_moveItem; external QtShareName name QtNamePrefix + 'QListViewItem_moveItem';

procedure QListView_destroy; external QtShareName name QtNamePrefix + 'QListView_destroy';
function QListView_create(parent: QWidgetH; name: PAnsiChar; f: WFlags): QListViewH; external QtShareName name QtNamePrefix + 'QListView_create';
function QListView_create(parent: QWidgetH; name: PAnsiChar): QListViewH; external QtShareName name QtNamePrefix + 'QListView_create2';
function QListView_treeStepSize; external QtShareName name QtNamePrefix + 'QListView_treeStepSize';
procedure QListView_setTreeStepSize; external QtShareName name QtNamePrefix + 'QListView_setTreeStepSize';
procedure QListView_insertItem; external QtShareName name QtNamePrefix + 'QListView_insertItem';
procedure QListView_takeItem; external QtShareName name QtNamePrefix + 'QListView_takeItem';
procedure QListView_removeItem; external QtShareName name QtNamePrefix + 'QListView_removeItem';
procedure QListView_clear; external QtShareName name QtNamePrefix + 'QListView_clear';
function QListView_header; external QtShareName name QtNamePrefix + 'QListView_header';
function QListView_addColumn(handle: QListViewH; _label: PWideString; size: Integer): Integer; external QtShareName name QtNamePrefix + 'QListView_addColumn';
function QListView_addColumn(handle: QListViewH; iconset: QIconSetH; _label: PWideString; size: Integer): Integer; external QtShareName name QtNamePrefix + 'QListView_addColumn2';
procedure QListView_removeColumn; external QtShareName name QtNamePrefix + 'QListView_removeColumn';
procedure QListView_setColumnText(handle: QListViewH; column: Integer; _label: PWideString); external QtShareName name QtNamePrefix + 'QListView_setColumnText';
procedure QListView_setColumnText(handle: QListViewH; column: Integer; iconset: QIconSetH; _label: PWideString); external QtShareName name QtNamePrefix + 'QListView_setColumnText2';
procedure QListView_columnText; external QtShareName name QtNamePrefix + 'QListView_columnText';
procedure QListView_setColumnWidth; external QtShareName name QtNamePrefix + 'QListView_setColumnWidth';
function QListView_columnWidth; external QtShareName name QtNamePrefix + 'QListView_columnWidth';
procedure QListView_setColumnWidthMode; external QtShareName name QtNamePrefix + 'QListView_setColumnWidthMode';
function QListView_columnWidthMode; external QtShareName name QtNamePrefix + 'QListView_columnWidthMode';
function QListView_columns; external QtShareName name QtNamePrefix + 'QListView_columns';
procedure QListView_setColumnAlignment; external QtShareName name QtNamePrefix + 'QListView_setColumnAlignment';
function QListView_columnAlignment; external QtShareName name QtNamePrefix + 'QListView_columnAlignment';
procedure QListView_show; external QtShareName name QtNamePrefix + 'QListView_show';
function QListView_itemAt; external QtShareName name QtNamePrefix + 'QListView_itemAt';
procedure QListView_itemRect; external QtShareName name QtNamePrefix + 'QListView_itemRect';
function QListView_itemPos; external QtShareName name QtNamePrefix + 'QListView_itemPos';
procedure QListView_ensureItemVisible; external QtShareName name QtNamePrefix + 'QListView_ensureItemVisible';
procedure QListView_repaintItem; external QtShareName name QtNamePrefix + 'QListView_repaintItem';
procedure QListView_setMultiSelection; external QtShareName name QtNamePrefix + 'QListView_setMultiSelection';
function QListView_isMultiSelection; external QtShareName name QtNamePrefix + 'QListView_isMultiSelection';
procedure QListView_setSelectionMode; external QtShareName name QtNamePrefix + 'QListView_setSelectionMode';
function QListView_selectionMode; external QtShareName name QtNamePrefix + 'QListView_selectionMode';
procedure QListView_clearSelection; external QtShareName name QtNamePrefix + 'QListView_clearSelection';
procedure QListView_setSelected; external QtShareName name QtNamePrefix + 'QListView_setSelected';
function QListView_isSelected; external QtShareName name QtNamePrefix + 'QListView_isSelected';
function QListView_selectedItem; external QtShareName name QtNamePrefix + 'QListView_selectedItem';
procedure QListView_setOpen; external QtShareName name QtNamePrefix + 'QListView_setOpen';
function QListView_isOpen; external QtShareName name QtNamePrefix + 'QListView_isOpen';
procedure QListView_setCurrentItem; external QtShareName name QtNamePrefix + 'QListView_setCurrentItem';
function QListView_currentItem; external QtShareName name QtNamePrefix + 'QListView_currentItem';
function QListView_firstChild; external QtShareName name QtNamePrefix + 'QListView_firstChild';
function QListView_childCount; external QtShareName name QtNamePrefix + 'QListView_childCount';
procedure QListView_setAllColumnsShowFocus; external QtShareName name QtNamePrefix + 'QListView_setAllColumnsShowFocus';
function QListView_allColumnsShowFocus; external QtShareName name QtNamePrefix + 'QListView_allColumnsShowFocus';
procedure QListView_setItemMargin; external QtShareName name QtNamePrefix + 'QListView_setItemMargin';
function QListView_itemMargin; external QtShareName name QtNamePrefix + 'QListView_itemMargin';
procedure QListView_setRootIsDecorated; external QtShareName name QtNamePrefix + 'QListView_setRootIsDecorated';
function QListView_rootIsDecorated; external QtShareName name QtNamePrefix + 'QListView_rootIsDecorated';
procedure QListView_setSorting; external QtShareName name QtNamePrefix + 'QListView_setSorting';
procedure QListView_sort; external QtShareName name QtNamePrefix + 'QListView_sort';
procedure QListView_setFont; external QtShareName name QtNamePrefix + 'QListView_setFont';
procedure QListView_setPalette; external QtShareName name QtNamePrefix + 'QListView_setPalette';
function QListView_eventFilter; external QtShareName name QtNamePrefix + 'QListView_eventFilter';
procedure QListView_sizeHint; external QtShareName name QtNamePrefix + 'QListView_sizeHint';
procedure QListView_minimumSizeHint; external QtShareName name QtNamePrefix + 'QListView_minimumSizeHint';
procedure QListView_setShowSortIndicator; external QtShareName name QtNamePrefix + 'QListView_setShowSortIndicator';
function QListView_showSortIndicator; external QtShareName name QtNamePrefix + 'QListView_showSortIndicator';
procedure QListView_invertSelection; external QtShareName name QtNamePrefix + 'QListView_invertSelection';
procedure QListView_selectAll; external QtShareName name QtNamePrefix + 'QListView_selectAll';
procedure QListView_triggerUpdate; external QtShareName name QtNamePrefix + 'QListView_triggerUpdate';
procedure QListView_setContentsPos; external QtShareName name QtNamePrefix + 'QListView_setContentsPos';

procedure QCheckListItem_destroy; external QtShareName name QtNamePrefix + 'QCheckListItem_destroy';
function QCheckListItem_create(parent: QCheckListItemH; text: PWideString; p3: QCheckListItemType): QCheckListItemH; external QtShareName name QtNamePrefix + 'QCheckListItem_create';
function QCheckListItem_create(parent: QListViewItemH; text: PWideString; p3: QCheckListItemType): QCheckListItemH; external QtShareName name QtNamePrefix + 'QCheckListItem_create2';
function QCheckListItem_create(parent: QListViewH; text: PWideString; p3: QCheckListItemType): QCheckListItemH; external QtShareName name QtNamePrefix + 'QCheckListItem_create3';
function QCheckListItem_create(parent: QListViewItemH; text: PWideString; p3: QPixmapH): QCheckListItemH; external QtShareName name QtNamePrefix + 'QCheckListItem_create4';
function QCheckListItem_create(parent: QListViewH; text: PWideString; p3: QPixmapH): QCheckListItemH; external QtShareName name QtNamePrefix + 'QCheckListItem_create5';
procedure QCheckListItem_paintCell; external QtShareName name QtNamePrefix + 'QCheckListItem_paintCell';
procedure QCheckListItem_paintFocus; external QtShareName name QtNamePrefix + 'QCheckListItem_paintFocus';
function QCheckListItem_width; external QtShareName name QtNamePrefix + 'QCheckListItem_width';
procedure QCheckListItem_setup; external QtShareName name QtNamePrefix + 'QCheckListItem_setup';
procedure QCheckListItem_setOn; external QtShareName name QtNamePrefix + 'QCheckListItem_setOn';
function QCheckListItem_isOn; external QtShareName name QtNamePrefix + 'QCheckListItem_isOn';
function QCheckListItem_type; external QtShareName name QtNamePrefix + 'QCheckListItem_type';
procedure QCheckListItem_text(handle: QCheckListItemH; retval: PWideString); external QtShareName name QtNamePrefix + 'QCheckListItem_text';
procedure QCheckListItem_text(handle: QCheckListItemH; retval: PWideString; n: Integer); external QtShareName name QtNamePrefix + 'QCheckListItem_text2';
procedure QCheckListItem_setEnabled; external QtShareName name QtNamePrefix + 'QCheckListItem_setEnabled';
function QCheckListItem_isEnabled; external QtShareName name QtNamePrefix + 'QCheckListItem_isEnabled';

procedure QListViewItemIterator_destroy; external QtShareName name QtNamePrefix + 'QListViewItemIterator_destroy';
function QListViewItemIterator_create(): QListViewItemIteratorH; external QtShareName name QtNamePrefix + 'QListViewItemIterator_create';
function QListViewItemIterator_create(item: QListViewItemH): QListViewItemIteratorH; external QtShareName name QtNamePrefix + 'QListViewItemIterator_create2';
function QListViewItemIterator_create(it: QListViewItemIteratorH): QListViewItemIteratorH; external QtShareName name QtNamePrefix + 'QListViewItemIterator_create3';
function QListViewItemIterator_create(lv: QListViewH): QListViewItemIteratorH; external QtShareName name QtNamePrefix + 'QListViewItemIterator_create4';
function QListViewItemIterator_current; external QtShareName name QtNamePrefix + 'QListViewItemIterator_current';

procedure QMenuBar_destroy; external QtShareName name QtNamePrefix + 'QMenuBar_destroy';
function QMenuBar_create; external QtShareName name QtNamePrefix + 'QMenuBar_create';
procedure QMenuBar_updateItem; external QtShareName name QtNamePrefix + 'QMenuBar_updateItem';
procedure QMenuBar_show; external QtShareName name QtNamePrefix + 'QMenuBar_show';
procedure QMenuBar_hide; external QtShareName name QtNamePrefix + 'QMenuBar_hide';
function QMenuBar_eventFilter; external QtShareName name QtNamePrefix + 'QMenuBar_eventFilter';
function QMenuBar_heightForWidth; external QtShareName name QtNamePrefix + 'QMenuBar_heightForWidth';
function QMenuBar_separator; external QtShareName name QtNamePrefix + 'QMenuBar_separator';
procedure QMenuBar_setSeparator; external QtShareName name QtNamePrefix + 'QMenuBar_setSeparator';
procedure QMenuBar_setDefaultUp; external QtShareName name QtNamePrefix + 'QMenuBar_setDefaultUp';
function QMenuBar_isDefaultUp; external QtShareName name QtNamePrefix + 'QMenuBar_isDefaultUp';
function QMenuBar_customWhatsThis; external QtShareName name QtNamePrefix + 'QMenuBar_customWhatsThis';
procedure QMenuBar_sizeHint; external QtShareName name QtNamePrefix + 'QMenuBar_sizeHint';
procedure QMenuBar_minimumSize; external QtShareName name QtNamePrefix + 'QMenuBar_minimumSize';
procedure QMenuBar_minimumSizeHint; external QtShareName name QtNamePrefix + 'QMenuBar_minimumSizeHint';
procedure QMenuBar_activateItemAt; external QtShareName name QtNamePrefix + 'QMenuBar_activateItemAt';
function QMenuBar_to_QMenuData; external QtSharename name QtNamePrefix + 'QMenuBar_to_QMenuData';

procedure QMessageBox_destroy; external QtShareName name QtNamePrefix + 'QMessageBox_destroy';
function QMessageBox_create(parent: QWidgetH; name: PAnsiChar): QMessageBoxH; external QtShareName name QtNamePrefix + 'QMessageBox_create';
function QMessageBox_create(caption: PWideString; text: PWideString; icon: QMessageBoxIcon; button0: Integer; button1: Integer; button2: Integer; parent: QWidgetH; name: PAnsiChar; modal: Boolean; f: WFlags): QMessageBoxH; external QtShareName name QtNamePrefix + 'QMessageBox_create2';
function QMessageBox_information(parent: QWidgetH; caption: PWideString; text: PWideString; button0: Integer; button1: Integer; button2: Integer): Integer; external QtShareName name QtNamePrefix + 'QMessageBox_information';
function QMessageBox_information(parent: QWidgetH; caption: PWideString; text: PWideString; button0Text: PWideString; button1Text: PWideString; button2Text: PWideString; defaultButtonNumber: Integer; escapeButtonNumber: Integer): Integer; external QtShareName name QtNamePrefix + 'QMessageBox_information2';
function QMessageBox_warning(parent: QWidgetH; caption: PWideString; text: PWideString; button0: Integer; button1: Integer; button2: Integer): Integer; external QtShareName name QtNamePrefix + 'QMessageBox_warning';
function QMessageBox_warning(parent: QWidgetH; caption: PWideString; text: PWideString; button0Text: PWideString; button1Text: PWideString; button2Text: PWideString; defaultButtonNumber: Integer; escapeButtonNumber: Integer): Integer; external QtShareName name QtNamePrefix + 'QMessageBox_warning2';
function QMessageBox_critical(parent: QWidgetH; caption: PWideString; text: PWideString; button0: Integer; button1: Integer; button2: Integer): Integer; external QtShareName name QtNamePrefix + 'QMessageBox_critical';
function QMessageBox_critical(parent: QWidgetH; caption: PWideString; text: PWideString; button0Text: PWideString; button1Text: PWideString; button2Text: PWideString; defaultButtonNumber: Integer; escapeButtonNumber: Integer): Integer; external QtShareName name QtNamePrefix + 'QMessageBox_critical2';
procedure QMessageBox_about; external QtShareName name QtNamePrefix + 'QMessageBox_about';
procedure QMessageBox_aboutQt; external QtShareName name QtNamePrefix + 'QMessageBox_aboutQt';
function QMessageBox_message; external QtShareName name QtNamePrefix + 'QMessageBox_message';
function QMessageBox_query; external QtShareName name QtNamePrefix + 'QMessageBox_query';
procedure QMessageBox_text; external QtShareName name QtNamePrefix + 'QMessageBox_text';
procedure QMessageBox_setText; external QtShareName name QtNamePrefix + 'QMessageBox_setText';
function QMessageBox_icon; external QtShareName name QtNamePrefix + 'QMessageBox_icon';
procedure QMessageBox_setIcon(handle: QMessageBoxH; p1: QMessageBoxIcon); external QtShareName name QtNamePrefix + 'QMessageBox_setIcon';
procedure QMessageBox_setIcon(handle: QMessageBoxH; p1: QPixmapH); external QtShareName name QtNamePrefix + 'QMessageBox_setIcon2';
function QMessageBox_iconPixmap; external QtShareName name QtNamePrefix + 'QMessageBox_iconPixmap';
procedure QMessageBox_setIconPixmap; external QtShareName name QtNamePrefix + 'QMessageBox_setIconPixmap';
procedure QMessageBox_buttonText; external QtShareName name QtNamePrefix + 'QMessageBox_buttonText';
procedure QMessageBox_setButtonText; external QtShareName name QtNamePrefix + 'QMessageBox_setButtonText';
procedure QMessageBox_adjustSize; external QtShareName name QtNamePrefix + 'QMessageBox_adjustSize';
procedure QMessageBox_standardIcon; external QtShareName name QtNamePrefix + 'QMessageBox_standardIcon';
function QMessageBox_textFormat; external QtShareName name QtNamePrefix + 'QMessageBox_textFormat';
procedure QMessageBox_setTextFormat; external QtShareName name QtNamePrefix + 'QMessageBox_setTextFormat';

procedure QMultiLineEdit_destroy; external QtShareName name QtNamePrefix + 'QMultiLineEdit_destroy';
function QMultiLineEdit_create; external QtShareName name QtNamePrefix + 'QMultiLineEdit_create';
procedure QMultiLineEdit_textLine; external QtShareName name QtNamePrefix + 'QMultiLineEdit_textLine';
function QMultiLineEdit_numLines; external QtShareName name QtNamePrefix + 'QMultiLineEdit_numLines';
procedure QMultiLineEdit_sizeHint; external QtShareName name QtNamePrefix + 'QMultiLineEdit_sizeHint';
procedure QMultiLineEdit_minimumSizeHint; external QtShareName name QtNamePrefix + 'QMultiLineEdit_minimumSizeHint';
procedure QMultiLineEdit_sizePolicy; external QtShareName name QtNamePrefix + 'QMultiLineEdit_sizePolicy';
procedure QMultiLineEdit_setFont; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setFont';
procedure QMultiLineEdit_insertLine; external QtShareName name QtNamePrefix + 'QMultiLineEdit_insertLine';
procedure QMultiLineEdit_insertAt; external QtShareName name QtNamePrefix + 'QMultiLineEdit_insertAt';
procedure QMultiLineEdit_removeLine; external QtShareName name QtNamePrefix + 'QMultiLineEdit_removeLine';
procedure QMultiLineEdit_cursorPosition; external QtShareName name QtNamePrefix + 'QMultiLineEdit_cursorPosition';
procedure QMultiLineEdit_setCursorPosition; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setCursorPosition';
procedure QMultiLineEdit_getCursorPosition; external QtShareName name QtNamePrefix + 'QMultiLineEdit_getCursorPosition';
function QMultiLineEdit_atBeginning; external QtShareName name QtNamePrefix + 'QMultiLineEdit_atBeginning';
function QMultiLineEdit_atEnd; external QtShareName name QtNamePrefix + 'QMultiLineEdit_atEnd';
procedure QMultiLineEdit_setFixedVisibleLines; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setFixedVisibleLines';
function QMultiLineEdit_maxLineWidth; external QtShareName name QtNamePrefix + 'QMultiLineEdit_maxLineWidth';
procedure QMultiLineEdit_setAlignment; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setAlignment';
function QMultiLineEdit_alignment; external QtShareName name QtNamePrefix + 'QMultiLineEdit_alignment';
procedure QMultiLineEdit_setValidator; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setValidator';
function QMultiLineEdit_validator; external QtShareName name QtNamePrefix + 'QMultiLineEdit_validator';
procedure QMultiLineEdit_setEdited; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setEdited';
function QMultiLineEdit_edited; external QtShareName name QtNamePrefix + 'QMultiLineEdit_edited';
procedure QMultiLineEdit_cursorWordForward; external QtShareName name QtNamePrefix + 'QMultiLineEdit_cursorWordForward';
procedure QMultiLineEdit_cursorWordBackward; external QtShareName name QtNamePrefix + 'QMultiLineEdit_cursorWordBackward';
procedure QMultiLineEdit_setEchoMode; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setEchoMode';
function QMultiLineEdit_echoMode; external QtShareName name QtNamePrefix + 'QMultiLineEdit_echoMode';
procedure QMultiLineEdit_setMaxLength; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setMaxLength';
function QMultiLineEdit_maxLength; external QtShareName name QtNamePrefix + 'QMultiLineEdit_maxLength';
procedure QMultiLineEdit_setMaxLineLength; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setMaxLineLength';
function QMultiLineEdit_maxLineLength; external QtShareName name QtNamePrefix + 'QMultiLineEdit_maxLineLength';
procedure QMultiLineEdit_setMaxLines; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setMaxLines';
function QMultiLineEdit_maxLines; external QtShareName name QtNamePrefix + 'QMultiLineEdit_maxLines';
procedure QMultiLineEdit_setHMargin; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setHMargin';
function QMultiLineEdit_hMargin; external QtShareName name QtNamePrefix + 'QMultiLineEdit_hMargin';
procedure QMultiLineEdit_setSelection; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setSelection';
procedure QMultiLineEdit_setWordWrap; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setWordWrap';
function QMultiLineEdit_wordWrap; external QtShareName name QtNamePrefix + 'QMultiLineEdit_wordWrap';
procedure QMultiLineEdit_setWrapColumnOrWidth; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setWrapColumnOrWidth';
function QMultiLineEdit_wrapColumnOrWidth; external QtShareName name QtNamePrefix + 'QMultiLineEdit_wrapColumnOrWidth';
procedure QMultiLineEdit_setWrapPolicy; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setWrapPolicy';
function QMultiLineEdit_wrapPolicy; external QtShareName name QtNamePrefix + 'QMultiLineEdit_wrapPolicy';
function QMultiLineEdit_autoUpdate; external QtShareName name QtNamePrefix + 'QMultiLineEdit_autoUpdate';
procedure QMultiLineEdit_setAutoUpdate; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setAutoUpdate';
procedure QMultiLineEdit_setUndoEnabled; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setUndoEnabled';
function QMultiLineEdit_isUndoEnabled; external QtShareName name QtNamePrefix + 'QMultiLineEdit_isUndoEnabled';
procedure QMultiLineEdit_setUndoDepth; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setUndoDepth';
function QMultiLineEdit_undoDepth; external QtShareName name QtNamePrefix + 'QMultiLineEdit_undoDepth';
function QMultiLineEdit_isReadOnly; external QtShareName name QtNamePrefix + 'QMultiLineEdit_isReadOnly';
function QMultiLineEdit_isOverwriteMode; external QtShareName name QtNamePrefix + 'QMultiLineEdit_isOverwriteMode';
procedure QMultiLineEdit_text; external QtShareName name QtNamePrefix + 'QMultiLineEdit_text';
function QMultiLineEdit_length; external QtShareName name QtNamePrefix + 'QMultiLineEdit_length';
procedure QMultiLineEdit_setDefaultTabStop; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setDefaultTabStop';
function QMultiLineEdit_defaultTabStop; external QtShareName name QtNamePrefix + 'QMultiLineEdit_defaultTabStop';
procedure QMultiLineEdit_setText; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setText';
procedure QMultiLineEdit_setReadOnly; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setReadOnly';
procedure QMultiLineEdit_setOverwriteMode; external QtShareName name QtNamePrefix + 'QMultiLineEdit_setOverwriteMode';
procedure QMultiLineEdit_clear; external QtShareName name QtNamePrefix + 'QMultiLineEdit_clear';
procedure QMultiLineEdit_append; external QtShareName name QtNamePrefix + 'QMultiLineEdit_append';
procedure QMultiLineEdit_deselect; external QtShareName name QtNamePrefix + 'QMultiLineEdit_deselect';
procedure QMultiLineEdit_selectAll; external QtShareName name QtNamePrefix + 'QMultiLineEdit_selectAll';
procedure QMultiLineEdit_paste; external QtShareName name QtNamePrefix + 'QMultiLineEdit_paste';
procedure QMultiLineEdit_pasteSubType; external QtShareName name QtNamePrefix + 'QMultiLineEdit_pasteSubType';
procedure QMultiLineEdit_copyText; external QtShareName name QtNamePrefix + 'QMultiLineEdit_copyText';
procedure QMultiLineEdit_copy; external QtShareName name QtNamePrefix + 'QMultiLineEdit_copy';
procedure QMultiLineEdit_cut; external QtShareName name QtNamePrefix + 'QMultiLineEdit_cut';
procedure QMultiLineEdit_insert; external QtShareName name QtNamePrefix + 'QMultiLineEdit_insert';
procedure QMultiLineEdit_undo; external QtShareName name QtNamePrefix + 'QMultiLineEdit_undo';
procedure QMultiLineEdit_redo; external QtShareName name QtNamePrefix + 'QMultiLineEdit_redo';

procedure QScrollView_destroy; external QtShareName name QtNamePrefix + 'QScrollView_destroy';
function QScrollView_create; external QtShareName name QtNamePrefix + 'QScrollView_create';
procedure QScrollView_setResizePolicy; external QtShareName name QtNamePrefix + 'QScrollView_setResizePolicy';
function QScrollView_resizePolicy; external QtShareName name QtNamePrefix + 'QScrollView_resizePolicy';
procedure QScrollView_styleChange; external QtShareName name QtNamePrefix + 'QScrollView_styleChange';
procedure QScrollView_removeChild(handle: QScrollViewH; child: QWidgetH); external QtShareName name QtNamePrefix + 'QScrollView_removeChild';
procedure QScrollView_addChild; external QtShareName name QtNamePrefix + 'QScrollView_addChild';
procedure QScrollView_moveChild; external QtShareName name QtNamePrefix + 'QScrollView_moveChild';
function QScrollView_childX; external QtShareName name QtNamePrefix + 'QScrollView_childX';
function QScrollView_childY; external QtShareName name QtNamePrefix + 'QScrollView_childY';
function QScrollView_childIsVisible; external QtShareName name QtNamePrefix + 'QScrollView_childIsVisible';
procedure QScrollView_showChild; external QtShareName name QtNamePrefix + 'QScrollView_showChild';
function QScrollView_vScrollBarMode; external QtShareName name QtNamePrefix + 'QScrollView_vScrollBarMode';
procedure QScrollView_setVScrollBarMode; external QtShareName name QtNamePrefix + 'QScrollView_setVScrollBarMode';
function QScrollView_hScrollBarMode; external QtShareName name QtNamePrefix + 'QScrollView_hScrollBarMode';
procedure QScrollView_setHScrollBarMode; external QtShareName name QtNamePrefix + 'QScrollView_setHScrollBarMode';
function QScrollView_cornerWidget; external QtShareName name QtNamePrefix + 'QScrollView_cornerWidget';
procedure QScrollView_setCornerWidget; external QtShareName name QtNamePrefix + 'QScrollView_setCornerWidget';
function QScrollView_horizontalScrollBar; external QtShareName name QtNamePrefix + 'QScrollView_horizontalScrollBar';
function QScrollView_verticalScrollBar; external QtShareName name QtNamePrefix + 'QScrollView_verticalScrollBar';
function QScrollView_viewport; external QtShareName name QtNamePrefix + 'QScrollView_viewport';
function QScrollView_clipper; external QtShareName name QtNamePrefix + 'QScrollView_clipper';
function QScrollView_visibleWidth; external QtShareName name QtNamePrefix + 'QScrollView_visibleWidth';
function QScrollView_visibleHeight; external QtShareName name QtNamePrefix + 'QScrollView_visibleHeight';
function QScrollView_contentsWidth; external QtShareName name QtNamePrefix + 'QScrollView_contentsWidth';
function QScrollView_contentsHeight; external QtShareName name QtNamePrefix + 'QScrollView_contentsHeight';
function QScrollView_contentsX; external QtShareName name QtNamePrefix + 'QScrollView_contentsX';
function QScrollView_contentsY; external QtShareName name QtNamePrefix + 'QScrollView_contentsY';
procedure QScrollView_resize(handle: QScrollViewH; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QScrollView_resize';
procedure QScrollView_resize(handle: QScrollViewH; p1: PSize); external QtShareName name QtNamePrefix + 'QScrollView_resize2';
procedure QScrollView_show; external QtShareName name QtNamePrefix + 'QScrollView_show';
procedure QScrollView_updateContents(handle: QScrollViewH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QScrollView_updateContents';
procedure QScrollView_updateContents(handle: QScrollViewH; r: PRect); external QtShareName name QtNamePrefix + 'QScrollView_updateContents2';
procedure QScrollView_repaintContents(handle: QScrollViewH; x: Integer; y: Integer; w: Integer; h: Integer; erase: Boolean); external QtShareName name QtNamePrefix + 'QScrollView_repaintContents';
procedure QScrollView_repaintContents(handle: QScrollViewH; r: PRect; erase: Boolean); external QtShareName name QtNamePrefix + 'QScrollView_repaintContents2';
procedure QScrollView_contentsToViewport(handle: QScrollViewH; x: Integer; y: Integer; vx: PInteger; vy: PInteger); external QtShareName name QtNamePrefix + 'QScrollView_contentsToViewport';
procedure QScrollView_viewportToContents(handle: QScrollViewH; vx: Integer; vy: Integer; x: PInteger; y: PInteger); external QtShareName name QtNamePrefix + 'QScrollView_viewportToContents';
procedure QScrollView_contentsToViewport(handle: QScrollViewH; retval: PPoint; p1: PPoint); external QtShareName name QtNamePrefix + 'QScrollView_contentsToViewport2';
procedure QScrollView_viewportToContents(handle: QScrollViewH; retval: PPoint; p1: PPoint); external QtShareName name QtNamePrefix + 'QScrollView_viewportToContents2';
procedure QScrollView_enableClipper; external QtShareName name QtNamePrefix + 'QScrollView_enableClipper';
procedure QScrollView_setStaticBackground; external QtShareName name QtNamePrefix + 'QScrollView_setStaticBackground';
function QScrollView_hasStaticBackground; external QtShareName name QtNamePrefix + 'QScrollView_hasStaticBackground';
procedure QScrollView_viewportSize; external QtShareName name QtNamePrefix + 'QScrollView_viewportSize';
procedure QScrollView_sizePolicy; external QtShareName name QtNamePrefix + 'QScrollView_sizePolicy';
procedure QScrollView_sizeHint; external QtShareName name QtNamePrefix + 'QScrollView_sizeHint';
procedure QScrollView_minimumSizeHint; external QtShareName name QtNamePrefix + 'QScrollView_minimumSizeHint';
procedure QScrollView_removeChild(handle: QScrollViewH; child: QObjectH); external QtShareName name QtNamePrefix + 'QScrollView_removeChild2';
procedure QScrollView_setDragAutoScroll; external QtShareName name QtNamePrefix + 'QScrollView_setDragAutoScroll';
function QScrollView_dragAutoScroll; external QtShareName name QtNamePrefix + 'QScrollView_dragAutoScroll';
procedure QScrollView_resizeContents; external QtShareName name QtNamePrefix + 'QScrollView_resizeContents';
procedure QScrollView_scrollBy; external QtShareName name QtNamePrefix + 'QScrollView_scrollBy';
procedure QScrollView_setContentsPos; external QtShareName name QtNamePrefix + 'QScrollView_setContentsPos';
procedure QScrollView_ensureVisible(handle: QScrollViewH; x: Integer; y: Integer); external QtShareName name QtNamePrefix + 'QScrollView_ensureVisible';
procedure QScrollView_ensureVisible(handle: QScrollViewH; x: Integer; y: Integer; xmargin: Integer; ymargin: Integer); external QtShareName name QtNamePrefix + 'QScrollView_ensureVisible2';
procedure QScrollView_center(handle: QScrollViewH; x: Integer; y: Integer); external QtShareName name QtNamePrefix + 'QScrollView_center';
procedure QScrollView_center(handle: QScrollViewH; x: Integer; y: Integer; xmargin: Single; ymargin: Single); external QtShareName name QtNamePrefix + 'QScrollView_center2';
procedure QScrollView_updateScrollBars; external QtShareName name QtNamePrefix + 'QScrollView_updateScrollBars';
procedure QScrollView_setEnabled; external QtShareName name QtNamePrefix + 'QScrollView_setEnabled';

procedure QSlider_destroy; external QtShareName name QtNamePrefix + 'QSlider_destroy';
function QSlider_create(parent: QWidgetH; name: PAnsiChar): QSliderH; external QtShareName name QtNamePrefix + 'QSlider_create';
function QSlider_create(p1: Orientation; parent: QWidgetH; name: PAnsiChar): QSliderH; external QtShareName name QtNamePrefix + 'QSlider_create2';
function QSlider_create(minValue: Integer; maxValue: Integer; pageStep: Integer; value: Integer; p5: Orientation; parent: QWidgetH; name: PAnsiChar): QSliderH; external QtShareName name QtNamePrefix + 'QSlider_create3';
procedure QSlider_setOrientation; external QtShareName name QtNamePrefix + 'QSlider_setOrientation';
function QSlider_orientation; external QtShareName name QtNamePrefix + 'QSlider_orientation';
procedure QSlider_setTracking; external QtShareName name QtNamePrefix + 'QSlider_setTracking';
function QSlider_tracking; external QtShareName name QtNamePrefix + 'QSlider_tracking';
procedure QSlider_setPalette; external QtShareName name QtNamePrefix + 'QSlider_setPalette';
procedure QSlider_sliderRect; external QtShareName name QtNamePrefix + 'QSlider_sliderRect';
procedure QSlider_sizeHint; external QtShareName name QtNamePrefix + 'QSlider_sizeHint';
procedure QSlider_sizePolicy; external QtShareName name QtNamePrefix + 'QSlider_sizePolicy';
procedure QSlider_minimumSizeHint; external QtShareName name QtNamePrefix + 'QSlider_minimumSizeHint';
procedure QSlider_setTickmarks; external QtShareName name QtNamePrefix + 'QSlider_setTickmarks';
function QSlider_tickmarks; external QtShareName name QtNamePrefix + 'QSlider_tickmarks';
procedure QSlider_setTickInterval; external QtShareName name QtNamePrefix + 'QSlider_setTickInterval';
function QSlider_tickInterval; external QtShareName name QtNamePrefix + 'QSlider_tickInterval';
function QSlider_minValue; external QtShareName name QtNamePrefix + 'QSlider_minValue';
function QSlider_maxValue; external QtShareName name QtNamePrefix + 'QSlider_maxValue';
procedure QSlider_setMinValue; external QtShareName name QtNamePrefix + 'QSlider_setMinValue';
procedure QSlider_setMaxValue; external QtShareName name QtNamePrefix + 'QSlider_setMaxValue';
function QSlider_lineStep; external QtShareName name QtNamePrefix + 'QSlider_lineStep';
function QSlider_pageStep; external QtShareName name QtNamePrefix + 'QSlider_pageStep';
procedure QSlider_setLineStep; external QtShareName name QtNamePrefix + 'QSlider_setLineStep';
procedure QSlider_setPageStep; external QtShareName name QtNamePrefix + 'QSlider_setPageStep';
function QSlider_value; external QtShareName name QtNamePrefix + 'QSlider_value';
procedure QSlider_setValue; external QtShareName name QtNamePrefix + 'QSlider_setValue';
procedure QSlider_addStep; external QtShareName name QtNamePrefix + 'QSlider_addStep';
procedure QSlider_subtractStep; external QtShareName name QtNamePrefix + 'QSlider_subtractStep';
function QSlider_to_QRangeControl; external QtSharename name QtNamePrefix + 'QSlider_to_QRangeControl';

procedure QSocketNotifier_destroy; external QtShareName name QtNamePrefix + 'QSocketNotifier_destroy';
function QSocketNotifier_create; external QtShareName name QtNamePrefix + 'QSocketNotifier_create';
function QSocketNotifier_socket; external QtShareName name QtNamePrefix + 'QSocketNotifier_socket';
function QSocketNotifier_type; external QtShareName name QtNamePrefix + 'QSocketNotifier_type';
function QSocketNotifier_isEnabled; external QtShareName name QtNamePrefix + 'QSocketNotifier_isEnabled';
procedure QSocketNotifier_setEnabled; external QtShareName name QtNamePrefix + 'QSocketNotifier_setEnabled';

procedure QSpinBox_destroy; external QtShareName name QtNamePrefix + 'QSpinBox_destroy';
function QSpinBox_create(parent: QWidgetH; name: PAnsiChar): QSpinBoxH; external QtShareName name QtNamePrefix + 'QSpinBox_create';
function QSpinBox_create(minValue: Integer; maxValue: Integer; step: Integer; parent: QWidgetH; name: PAnsiChar): QSpinBoxH; external QtShareName name QtNamePrefix + 'QSpinBox_create2';
procedure QSpinBox_text; external QtShareName name QtNamePrefix + 'QSpinBox_text';
procedure QSpinBox_prefix; external QtShareName name QtNamePrefix + 'QSpinBox_prefix';
procedure QSpinBox_suffix; external QtShareName name QtNamePrefix + 'QSpinBox_suffix';
procedure QSpinBox_cleanText; external QtShareName name QtNamePrefix + 'QSpinBox_cleanText';
procedure QSpinBox_setSpecialValueText; external QtShareName name QtNamePrefix + 'QSpinBox_setSpecialValueText';
procedure QSpinBox_specialValueText; external QtShareName name QtNamePrefix + 'QSpinBox_specialValueText';
procedure QSpinBox_setWrapping; external QtShareName name QtNamePrefix + 'QSpinBox_setWrapping';
function QSpinBox_wrapping; external QtShareName name QtNamePrefix + 'QSpinBox_wrapping';
procedure QSpinBox_setButtonSymbols; external QtShareName name QtNamePrefix + 'QSpinBox_setButtonSymbols';
function QSpinBox_buttonSymbols; external QtShareName name QtNamePrefix + 'QSpinBox_buttonSymbols';
procedure QSpinBox_setValidator; external QtShareName name QtNamePrefix + 'QSpinBox_setValidator';
function QSpinBox_validator; external QtShareName name QtNamePrefix + 'QSpinBox_validator';
procedure QSpinBox_sizeHint; external QtShareName name QtNamePrefix + 'QSpinBox_sizeHint';
procedure QSpinBox_sizePolicy; external QtShareName name QtNamePrefix + 'QSpinBox_sizePolicy';
function QSpinBox_minValue; external QtShareName name QtNamePrefix + 'QSpinBox_minValue';
function QSpinBox_maxValue; external QtShareName name QtNamePrefix + 'QSpinBox_maxValue';
procedure QSpinBox_setMinValue; external QtShareName name QtNamePrefix + 'QSpinBox_setMinValue';
procedure QSpinBox_setMaxValue; external QtShareName name QtNamePrefix + 'QSpinBox_setMaxValue';
function QSpinBox_lineStep; external QtShareName name QtNamePrefix + 'QSpinBox_lineStep';
procedure QSpinBox_setLineStep; external QtShareName name QtNamePrefix + 'QSpinBox_setLineStep';
function QSpinBox_value; external QtShareName name QtNamePrefix + 'QSpinBox_value';
procedure QSpinBox_setValue; external QtShareName name QtNamePrefix + 'QSpinBox_setValue';
procedure QSpinBox_setPrefix; external QtShareName name QtNamePrefix + 'QSpinBox_setPrefix';
procedure QSpinBox_setSuffix; external QtShareName name QtNamePrefix + 'QSpinBox_setSuffix';
procedure QSpinBox_stepUp; external QtShareName name QtNamePrefix + 'QSpinBox_stepUp';
procedure QSpinBox_stepDown; external QtShareName name QtNamePrefix + 'QSpinBox_stepDown';
procedure QSpinBox_setEnabled; external QtShareName name QtNamePrefix + 'QSpinBox_setEnabled';
function QSpinBox_to_QRangeControl; external QtSharename name QtNamePrefix + 'QSpinBox_to_QRangeControl';

procedure QStyle_destroy; external QtShareName name QtNamePrefix + 'QStyle_destroy';
function QStyle_guiStyle; external QtShareName name QtNamePrefix + 'QStyle_guiStyle';
procedure QStyle_polish(handle: QStyleH; p1: QWidgetH); external QtShareName name QtNamePrefix + 'QStyle_polish';
procedure QStyle_unPolish(handle: QStyleH; p1: QWidgetH); external QtShareName name QtNamePrefix + 'QStyle_unPolish';
procedure QStyle_polish(handle: QStyleH; p1: QApplicationH); external QtShareName name QtNamePrefix + 'QStyle_polish2';
procedure QStyle_unPolish(handle: QStyleH; p1: QApplicationH); external QtShareName name QtNamePrefix + 'QStyle_unPolish2';
procedure QStyle_polish(handle: QStyleH; p1: QPaletteH); external QtShareName name QtNamePrefix + 'QStyle_polish3';
procedure QStyle_itemRect; external QtShareName name QtNamePrefix + 'QStyle_itemRect';
procedure QStyle_drawItem; external QtShareName name QtNamePrefix + 'QStyle_drawItem';
procedure QStyle_drawSeparator; external QtShareName name QtNamePrefix + 'QStyle_drawSeparator';
procedure QStyle_drawRect; external QtShareName name QtNamePrefix + 'QStyle_drawRect';
procedure QStyle_drawRectStrong; external QtShareName name QtNamePrefix + 'QStyle_drawRectStrong';
procedure QStyle_drawButton; external QtShareName name QtNamePrefix + 'QStyle_drawButton';
procedure QStyle_buttonRect; external QtShareName name QtNamePrefix + 'QStyle_buttonRect';
procedure QStyle_drawButtonMask; external QtShareName name QtNamePrefix + 'QStyle_drawButtonMask';
procedure QStyle_drawBevelButton; external QtShareName name QtNamePrefix + 'QStyle_drawBevelButton';
procedure QStyle_bevelButtonRect; external QtShareName name QtNamePrefix + 'QStyle_bevelButtonRect';
procedure QStyle_drawToolButton(handle: QStyleH; p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH); external QtShareName name QtNamePrefix + 'QStyle_drawToolButton';
procedure QStyle_drawToolButton(handle: QStyleH; btn: QToolButtonH; p: QPainterH); external QtShareName name QtNamePrefix + 'QStyle_drawToolButton2';
procedure QStyle_toolButtonRect; external QtShareName name QtNamePrefix + 'QStyle_toolButtonRect';
procedure QStyle_drawPanel; external QtShareName name QtNamePrefix + 'QStyle_drawPanel';
procedure QStyle_drawPopupPanel; external QtShareName name QtNamePrefix + 'QStyle_drawPopupPanel';
procedure QStyle_drawArrow; external QtShareName name QtNamePrefix + 'QStyle_drawArrow';
procedure QStyle_exclusiveIndicatorSize; external QtShareName name QtNamePrefix + 'QStyle_exclusiveIndicatorSize';
procedure QStyle_drawExclusiveIndicator; external QtShareName name QtNamePrefix + 'QStyle_drawExclusiveIndicator';
procedure QStyle_drawExclusiveIndicatorMask; external QtShareName name QtNamePrefix + 'QStyle_drawExclusiveIndicatorMask';
procedure QStyle_indicatorSize; external QtShareName name QtNamePrefix + 'QStyle_indicatorSize';
procedure QStyle_drawIndicator; external QtShareName name QtNamePrefix + 'QStyle_drawIndicator';
procedure QStyle_drawIndicatorMask; external QtShareName name QtNamePrefix + 'QStyle_drawIndicatorMask';
procedure QStyle_drawFocusRect; external QtShareName name QtNamePrefix + 'QStyle_drawFocusRect';
procedure QStyle_drawComboButton; external QtShareName name QtNamePrefix + 'QStyle_drawComboButton';
procedure QStyle_comboButtonRect; external QtShareName name QtNamePrefix + 'QStyle_comboButtonRect';
procedure QStyle_comboButtonFocusRect; external QtShareName name QtNamePrefix + 'QStyle_comboButtonFocusRect';
procedure QStyle_drawComboButtonMask; external QtShareName name QtNamePrefix + 'QStyle_drawComboButtonMask';
procedure QStyle_drawPushButton; external QtShareName name QtNamePrefix + 'QStyle_drawPushButton';
procedure QStyle_drawPushButtonLabel; external QtShareName name QtNamePrefix + 'QStyle_drawPushButtonLabel';
procedure QStyle_pushButtonContentsRect; external QtShareName name QtNamePrefix + 'QStyle_pushButtonContentsRect';
function QStyle_menuButtonIndicatorWidth; external QtShareName name QtNamePrefix + 'QStyle_menuButtonIndicatorWidth';
procedure QStyle_getButtonShift; external QtShareName name QtNamePrefix + 'QStyle_getButtonShift';
function QStyle_defaultFrameWidth; external QtShareName name QtNamePrefix + 'QStyle_defaultFrameWidth';
procedure QStyle_tabbarMetrics; external QtShareName name QtNamePrefix + 'QStyle_tabbarMetrics';
procedure QStyle_drawTab; external QtShareName name QtNamePrefix + 'QStyle_drawTab';
procedure QStyle_drawTabMask; external QtShareName name QtNamePrefix + 'QStyle_drawTabMask';
procedure QStyle_scrollBarMetrics; external QtShareName name QtNamePrefix + 'QStyle_scrollBarMetrics';
procedure QStyle_drawScrollBarControls; external QtShareName name QtNamePrefix + 'QStyle_drawScrollBarControls';
function QStyle_scrollBarPointOver; external QtShareName name QtNamePrefix + 'QStyle_scrollBarPointOver';
function QStyle_sliderLength; external QtShareName name QtNamePrefix + 'QStyle_sliderLength';
procedure QStyle_drawSlider; external QtShareName name QtNamePrefix + 'QStyle_drawSlider';
procedure QStyle_drawSliderMask; external QtShareName name QtNamePrefix + 'QStyle_drawSliderMask';
procedure QStyle_drawSliderGroove; external QtShareName name QtNamePrefix + 'QStyle_drawSliderGroove';
procedure QStyle_drawSliderGrooveMask; external QtShareName name QtNamePrefix + 'QStyle_drawSliderGrooveMask';
function QStyle_maximumSliderDragDistance; external QtShareName name QtNamePrefix + 'QStyle_maximumSliderDragDistance';
function QStyle_splitterWidth; external QtShareName name QtNamePrefix + 'QStyle_splitterWidth';
procedure QStyle_drawSplitter; external QtShareName name QtNamePrefix + 'QStyle_drawSplitter';
procedure QStyle_drawCheckMark; external QtShareName name QtNamePrefix + 'QStyle_drawCheckMark';
procedure QStyle_polishPopupMenu; external QtShareName name QtNamePrefix + 'QStyle_polishPopupMenu';
function QStyle_extraPopupMenuItemWidth; external QtShareName name QtNamePrefix + 'QStyle_extraPopupMenuItemWidth';
function QStyle_popupSubmenuIndicatorWidth; external QtShareName name QtNamePrefix + 'QStyle_popupSubmenuIndicatorWidth';
function QStyle_popupMenuItemHeight; external QtShareName name QtNamePrefix + 'QStyle_popupMenuItemHeight';
procedure QStyle_drawPopupMenuItem; external QtShareName name QtNamePrefix + 'QStyle_drawPopupMenuItem';
procedure QStyle_drawMenuBarItem; external QtShareName name QtNamePrefix + 'QStyle_drawMenuBarItem';
procedure QStyle_scrollBarExtent; external QtShareName name QtNamePrefix + 'QStyle_scrollBarExtent';
function QStyle_buttonDefaultIndicatorWidth; external QtShareName name QtNamePrefix + 'QStyle_buttonDefaultIndicatorWidth';
function QStyle_buttonMargin; external QtShareName name QtNamePrefix + 'QStyle_buttonMargin';
function QStyle_toolBarHandleExtent; external QtShareName name QtNamePrefix + 'QStyle_toolBarHandleExtent';
function QStyle_toolBarHandleExtend; external QtShareName name QtNamePrefix + 'QStyle_toolBarHandleExtend';
function QStyle_sliderThickness; external QtShareName name QtNamePrefix + 'QStyle_sliderThickness';
procedure QStyle_drawToolBarHandle; external QtShareName name QtNamePrefix + 'QStyle_drawToolBarHandle';

procedure QTranslatorMessage_destroy; external QtShareName name QtNamePrefix + 'QTranslatorMessage_destroy';
function QTranslatorMessage_create(): QTranslatorMessageH; external QtShareName name QtNamePrefix + 'QTranslatorMessage_create';
function QTranslatorMessage_create(context: PAnsiChar; sourceText: PAnsiChar; comment: PAnsiChar; translation: PWideString): QTranslatorMessageH; external QtShareName name QtNamePrefix + 'QTranslatorMessage_create2';
function QTranslatorMessage_create(p1: QDataStreamH): QTranslatorMessageH; external QtShareName name QtNamePrefix + 'QTranslatorMessage_create3';
function QTranslatorMessage_create(m: QTranslatorMessageH): QTranslatorMessageH; external QtShareName name QtNamePrefix + 'QTranslatorMessage_create4';
function QTranslatorMessage_hash; external QtShareName name QtNamePrefix + 'QTranslatorMessage_hash';
function QTranslatorMessage_context; external QtShareName name QtNamePrefix + 'QTranslatorMessage_context';
function QTranslatorMessage_sourceText; external QtShareName name QtNamePrefix + 'QTranslatorMessage_sourceText';
function QTranslatorMessage_comment; external QtShareName name QtNamePrefix + 'QTranslatorMessage_comment';
procedure QTranslatorMessage_setTranslation; external QtShareName name QtNamePrefix + 'QTranslatorMessage_setTranslation';
procedure QTranslatorMessage_translation; external QtShareName name QtNamePrefix + 'QTranslatorMessage_translation';
procedure QTranslatorMessage_write; external QtShareName name QtNamePrefix + 'QTranslatorMessage_write';
function QTranslatorMessage_commonPrefix; external QtShareName name QtNamePrefix + 'QTranslatorMessage_commonPrefix';

procedure QTranslator_destroy; external QtShareName name QtNamePrefix + 'QTranslator_destroy';
function QTranslator_create; external QtShareName name QtNamePrefix + 'QTranslator_create';
procedure QTranslator_find(handle: QTranslatorH; retval: PWideString; p1: PAnsiChar; p2: PAnsiChar; p3: PAnsiChar); external QtShareName name QtNamePrefix + 'QTranslator_find';
procedure QTranslator_find(handle: QTranslatorH; retval: PWideString; p1: PAnsiChar; p2: PAnsiChar); external QtShareName name QtNamePrefix + 'QTranslator_find2';

function QTranslator_load; external QtShareName name QtNamePrefix + 'QTranslator_load';
function QTranslator_save; external QtShareName name QtNamePrefix + 'QTranslator_save';
procedure QTranslator_clear; external QtShareName name QtNamePrefix + 'QTranslator_clear';
procedure QTranslator_insert(handle: QTranslatorH; p1: QTranslatorMessageH); external QtShareName name QtNamePrefix + 'QTranslator_insert';
procedure QTranslator_insert(handle: QTranslatorH; p1: PAnsiChar; p2: PAnsiChar; p3: PWideString); external QtShareName name QtNamePrefix + 'QTranslator_insert2';
procedure QTranslator_remove(handle: QTranslatorH; p1: QTranslatorMessageH); external QtShareName name QtNamePrefix + 'QTranslator_remove';
procedure QTranslator_remove(handle: QTranslatorH; p1: PAnsiChar; p2: PAnsiChar); external QtShareName name QtNamePrefix + 'QTranslator_remove2';
function QTranslator_contains(handle: QTranslatorH; p1: PAnsiChar; p2: PAnsiChar; p3: PAnsiChar): Boolean; external QtShareName name QtNamePrefix + 'QTranslator_contains';
function QTranslator_contains(handle: QTranslatorH; p1: PAnsiChar; p2: PAnsiChar): Boolean; external QtShareName name QtNamePrefix + 'QTranslator_contains2';
procedure QTranslator_squeeze(handle: QTranslatorH; p1: QTranslatorSaveMode); external QtShareName name QtNamePrefix + 'QTranslator_squeeze';
procedure QTranslator_squeeze(handle: QTranslatorH); external QtShareName name QtNamePrefix + 'QTranslator_squeeze2';
procedure QTranslator_unsqueeze; external QtShareName name QtNamePrefix + 'QTranslator_unsqueeze';

procedure QColor_destroy; external QtShareName name QtNamePrefix + 'QColor_destroy';
function QColor_create(): QColorH; external QtShareName name QtNamePrefix + 'QColor_create';
function QColor_create(r: Integer; g: Integer; b: Integer): QColorH; external QtShareName name QtNamePrefix + 'QColor_create2';
function QColor_create(x: Integer; y: Integer; z: Integer; p4: QColorSpec): QColorH; external QtShareName name QtNamePrefix + 'QColor_create3';
function QColor_create(rgb: QRgbH; pixel: Cardinal): QColorH; external QtShareName name QtNamePrefix + 'QColor_create4';
function QColor_create(name: PWideString): QColorH; external QtShareName name QtNamePrefix + 'QColor_create5';
function QColor_create(name: PAnsiChar): QColorH; external QtShareName name QtNamePrefix + 'QColor_create6';
function QColor_create(p1: QColorH): QColorH; external QtShareName name QtNamePrefix + 'QColor_create7';
function QColor_isValid; external QtShareName name QtNamePrefix + 'QColor_isValid';
function QColor_isDirty; external QtShareName name QtNamePrefix + 'QColor_isDirty';
procedure QColor_name; external QtShareName name QtNamePrefix + 'QColor_name';
procedure QColor_setNamedColor; external QtShareName name QtNamePrefix + 'QColor_setNamedColor';
procedure QColor_rgb(handle: QColorH; r: PInteger; g: PInteger; b: PInteger); external QtShareName name QtNamePrefix + 'QColor_rgb';
procedure QColor_rgb(handle: QColorH; retval: QRgbH); external QtShareName name QtNamePrefix + 'QColor_rgb2';
procedure QColor_setRgb(handle: QColorH; r: Integer; g: Integer; b: Integer); external QtShareName name QtNamePrefix + 'QColor_setRgb';
procedure QColor_setRgb(handle: QColorH; rgb: QRgbH); external QtShareName name QtNamePrefix + 'QColor_setRgb2';
function QColor_red; external QtShareName name QtNamePrefix + 'QColor_red';
function QColor_green; external QtShareName name QtNamePrefix + 'QColor_green';
function QColor_blue; external QtShareName name QtNamePrefix + 'QColor_blue';
procedure QColor_hsv; external QtShareName name QtNamePrefix + 'QColor_hsv';
procedure QColor_getHsv; external QtShareName name QtNamePrefix + 'QColor_getHsv';
procedure QColor_setHsv; external QtShareName name QtNamePrefix + 'QColor_setHsv';
procedure QColor_light; external QtShareName name QtNamePrefix + 'QColor_light';
procedure QColor_dark; external QtShareName name QtNamePrefix + 'QColor_dark';
function QColor_lazyAlloc; external QtShareName name QtNamePrefix + 'QColor_lazyAlloc';
procedure QColor_setLazyAlloc; external QtShareName name QtNamePrefix + 'QColor_setLazyAlloc';
function QColor_alloc; external QtShareName name QtNamePrefix + 'QColor_alloc';
function QColor_pixel; external QtShareName name QtNamePrefix + 'QColor_pixel';
function QColor_maxColors; external QtShareName name QtNamePrefix + 'QColor_maxColors';
function QColor_numBitPlanes; external QtShareName name QtNamePrefix + 'QColor_numBitPlanes';
function QColor_enterAllocContext; external QtShareName name QtNamePrefix + 'QColor_enterAllocContext';
procedure QColor_leaveAllocContext; external QtShareName name QtNamePrefix + 'QColor_leaveAllocContext';
function QColor_currentAllocContext; external QtShareName name QtNamePrefix + 'QColor_currentAllocContext';
procedure QColor_destroyAllocContext; external QtShareName name QtNamePrefix + 'QColor_destroyAllocContext';
function QColor_hPal; external QtShareName name QtNamePrefix + 'QColor_hPal';
function QColor_realizePal; external QtShareName name QtNamePrefix + 'QColor_realizePal';
procedure QColor_initialize; external QtShareName name QtNamePrefix + 'QColor_initialize';
procedure QColor_cleanup; external QtShareName name QtNamePrefix + 'QColor_cleanup';

procedure QFont_destroy; external QtShareName name QtNamePrefix + 'QFont_destroy';
function QFont_create(): QFontH; external QtShareName name QtNamePrefix + 'QFont_create';
function QFont_create(family: PWideString; pointSize: Integer; weight: Integer; italic: Boolean): QFontH; external QtShareName name QtNamePrefix + 'QFont_create2';
function QFont_create(family: PWideString; pointSize: Integer; weight: Integer; italic: Boolean; charSet: QFontCharSet): QFontH; external QtShareName name QtNamePrefix + 'QFont_create3';
function QFont_create(p1: QFontH): QFontH; external QtShareName name QtNamePrefix + 'QFont_create4';
procedure QFont_family; external QtShareName name QtNamePrefix + 'QFont_family';
procedure QFont_setFamily; external QtShareName name QtNamePrefix + 'QFont_setFamily';
function QFont_pointSize; external QtShareName name QtNamePrefix + 'QFont_pointSize';
function QFont_pointSizeFloat; external QtShareName name QtNamePrefix + 'QFont_pointSizeFloat';
procedure QFont_setPointSize; external QtShareName name QtNamePrefix + 'QFont_setPointSize';
procedure QFont_setPointSizeFloat; external QtShareName name QtNamePrefix + 'QFont_setPointSizeFloat';
function QFont_pixelSize; external QtShareName name QtNamePrefix + 'QFont_pixelSize';
procedure QFont_setPixelSize; external QtShareName name QtNamePrefix + 'QFont_setPixelSize';
procedure QFont_setPixelSizeFloat; external QtShareName name QtNamePrefix + 'QFont_setPixelSizeFloat';
function QFont_weight; external QtShareName name QtNamePrefix + 'QFont_weight';
procedure QFont_setWeight; external QtShareName name QtNamePrefix + 'QFont_setWeight';
function QFont_bold; external QtShareName name QtNamePrefix + 'QFont_bold';
procedure QFont_setBold; external QtShareName name QtNamePrefix + 'QFont_setBold';
function QFont_italic; external QtShareName name QtNamePrefix + 'QFont_italic';
procedure QFont_setItalic; external QtShareName name QtNamePrefix + 'QFont_setItalic';
function QFont_underline; external QtShareName name QtNamePrefix + 'QFont_underline';
procedure QFont_setUnderline; external QtShareName name QtNamePrefix + 'QFont_setUnderline';
function QFont_strikeOut; external QtShareName name QtNamePrefix + 'QFont_strikeOut';
procedure QFont_setStrikeOut; external QtShareName name QtNamePrefix + 'QFont_setStrikeOut';
function QFont_fixedPitch; external QtShareName name QtNamePrefix + 'QFont_fixedPitch';
procedure QFont_setFixedPitch; external QtShareName name QtNamePrefix + 'QFont_setFixedPitch';
function QFont_styleHint; external QtShareName name QtNamePrefix + 'QFont_styleHint';
procedure QFont_setStyleHint(handle: QFontH; p1: QFontStyleHint); external QtShareName name QtNamePrefix + 'QFont_setStyleHint';
function QFont_styleStrategy; external QtShareName name QtNamePrefix + 'QFont_styleStrategy';
procedure QFont_setStyleHint(handle: QFontH; p1: QFontStyleHint; p2: QFontStyleStrategy); external QtShareName name QtNamePrefix + 'QFont_setStyleHint2';
function QFont_charSet; external QtShareName name QtNamePrefix + 'QFont_charSet';
procedure QFont_setCharSet; external QtShareName name QtNamePrefix + 'QFont_setCharSet';
function QFont_charSetForLocale; external QtShareName name QtNamePrefix + 'QFont_charSetForLocale';
function QFont_rawMode; external QtShareName name QtNamePrefix + 'QFont_rawMode';
procedure QFont_setRawMode; external QtShareName name QtNamePrefix + 'QFont_setRawMode';
function QFont_exactMatch; external QtShareName name QtNamePrefix + 'QFont_exactMatch';
function QFont_isCopyOf; external QtShareName name QtNamePrefix + 'QFont_isCopyOf';
function QFont_handle(handle: QFontH): HFONT; external QtShareName name QtNamePrefix + 'QFont_handle';

procedure QFont_setRawName; external QtShareName name QtNamePrefix + 'QFont_setRawName';
procedure QFont_rawName; external QtShareName name QtNamePrefix + 'QFont_rawName';
procedure QFont_key; external QtShareName name QtNamePrefix + 'QFont_key';
procedure QFont_encodingName; external QtShareName name QtNamePrefix + 'QFont_encodingName';
procedure QFont_defaultFont; external QtShareName name QtNamePrefix + 'QFont_defaultFont';
procedure QFont_setDefaultFont; external QtShareName name QtNamePrefix + 'QFont_setDefaultFont';
procedure QFont_substitute; external QtShareName name QtNamePrefix + 'QFont_substitute';
procedure QFont_insertSubstitution; external QtShareName name QtNamePrefix + 'QFont_insertSubstitution';
procedure QFont_removeSubstitution; external QtShareName name QtNamePrefix + 'QFont_removeSubstitution';
procedure QFont_substitutions; external QtShareName name QtNamePrefix + 'QFont_substitutions';
procedure QFont_initialize; external QtShareName name QtNamePrefix + 'QFont_initialize';
procedure QFont_locale_init; external QtShareName name QtNamePrefix + 'QFont_locale_init';
procedure QFont_cleanup; external QtShareName name QtNamePrefix + 'QFont_cleanup';
procedure QFont_cacheStatistics; external QtShareName name QtNamePrefix + 'QFont_cacheStatistics';
procedure QFont_qwsRenderToDisk; external QtShareName name QtNamePrefix + 'QFont_qwsRenderToDisk';

procedure QImageTextKeyLang_destroy; external QtShareName name QtNamePrefix + 'QImageTextKeyLang_destroy';
function QImageTextKeyLang_create(k: PAnsiChar; l: PAnsiChar): QImageTextKeyLangH; external QtShareName name QtNamePrefix + 'QImageTextKeyLang_create';
function QImageTextKeyLang_create(): QImageTextKeyLangH; external QtShareName name QtNamePrefix + 'QImageTextKeyLang_create2';

procedure QImage_destroy; external QtShareName name QtNamePrefix + 'QImage_destroy';
function QImage_create(): QImageH; external QtShareName name QtNamePrefix + 'QImage_create';
function QImage_create(width: Integer; height: Integer; depth: Integer; numColors: Integer; bitOrder: QImageEndian): QImageH; external QtShareName name QtNamePrefix + 'QImage_create2';
function QImage_create(p1: PSize; depth: Integer; numColors: Integer; bitOrder: QImageEndian): QImageH; external QtShareName name QtNamePrefix + 'QImage_create3';
function QImage_create(fileName: PWideString; format: PAnsiChar): QImageH; external QtShareName name QtNamePrefix + 'QImage_create4';

function QImage_create(data: QByteArrayH): QImageH; external QtShareName name QtNamePrefix + 'QImage_create6';
function QImage_create(data: PByte; w: Integer; h: Integer; depth: Integer; colortable: QRgbH; numColors: Integer; bitOrder: QImageEndian): QImageH; external QtShareName name QtNamePrefix + 'QImage_create7';

function QImage_create(p1: QImageH): QImageH; external QtShareName name QtNamePrefix + 'QImage_create9';
procedure QImage_detach; external QtShareName name QtNamePrefix + 'QImage_detach';
procedure QImage_copy(handle: QImageH; retval: QImageH); external QtShareName name QtNamePrefix + 'QImage_copy';
procedure QImage_copy(handle: QImageH; retval: QImageH; x: Integer; y: Integer; w: Integer; h: Integer; conversion_flags: Integer); external QtShareName name QtNamePrefix + 'QImage_copy2';

procedure QImage_copy(handle: QImageH; retval: QImageH; p1: PRect); external QtShareName name QtNamePrefix + 'QImage_copy4';
function QImage_isNull; external QtShareName name QtNamePrefix + 'QImage_isNull';
function QImage_width; external QtShareName name QtNamePrefix + 'QImage_width';
function QImage_height; external QtShareName name QtNamePrefix + 'QImage_height';
procedure QImage_size; external QtShareName name QtNamePrefix + 'QImage_size';
procedure QImage_rect; external QtShareName name QtNamePrefix + 'QImage_rect';
function QImage_depth; external QtShareName name QtNamePrefix + 'QImage_depth';
function QImage_numColors; external QtShareName name QtNamePrefix + 'QImage_numColors';
function QImage_bitOrder; external QtShareName name QtNamePrefix + 'QImage_bitOrder';
procedure QImage_color; external QtShareName name QtNamePrefix + 'QImage_color';
procedure QImage_setColor; external QtShareName name QtNamePrefix + 'QImage_setColor';
procedure QImage_setNumColors; external QtShareName name QtNamePrefix + 'QImage_setNumColors';
function QImage_hasAlphaBuffer; external QtShareName name QtNamePrefix + 'QImage_hasAlphaBuffer';
procedure QImage_setAlphaBuffer; external QtShareName name QtNamePrefix + 'QImage_setAlphaBuffer';
function QImage_allGray; external QtShareName name QtNamePrefix + 'QImage_allGray';
function QImage_isGrayscale; external QtShareName name QtNamePrefix + 'QImage_isGrayscale';
function QImage_bits; external QtShareName name QtNamePrefix + 'QImage_bits';
function QImage_scanLine; external QtShareName name QtNamePrefix + 'QImage_scanLine';
function QImage_jumpTable; external QtShareName name QtNamePrefix + 'QImage_jumpTable';
function QImage_colorTable; external QtShareName name QtNamePrefix + 'QImage_colorTable';
function QImage_numBytes; external QtShareName name QtNamePrefix + 'QImage_numBytes';
function QImage_bytesPerLine; external QtShareName name QtNamePrefix + 'QImage_bytesPerLine';

function QImage_create(handle: QImageH; width: Integer; height: Integer; depth: Integer; numColors: Integer; bitOrder: QImageEndian): Boolean; external QtShareName name QtNamePrefix + 'QImage_create';
function QImage_create(handle: QImageH; p1: PSize; depth: Integer; numColors: Integer; bitOrder: QImageEndian): Boolean; external QtShareName name QtNamePrefix + 'QImage_create2';
procedure QImage_reset; external QtShareName name QtNamePrefix + 'QImage_reset';
procedure QImage_fill; external QtShareName name QtNamePrefix + 'QImage_fill';
procedure QImage_invertPixels; external QtShareName name QtNamePrefix + 'QImage_invertPixels';
procedure QImage_convertDepth(handle: QImageH; retval: QImageH; p1: Integer); external QtShareName name QtNamePrefix + 'QImage_convertDepth';
procedure QImage_convertDepthWithPalette; external QtShareName name QtNamePrefix + 'QImage_convertDepthWithPalette';
procedure QImage_convertDepth(handle: QImageH; retval: QImageH; p1: Integer; conversion_flags: Integer); external QtShareName name QtNamePrefix + 'QImage_convertDepth2';
procedure QImage_convertBitOrder; external QtShareName name QtNamePrefix + 'QImage_convertBitOrder';
procedure QImage_smoothScale; external QtShareName name QtNamePrefix + 'QImage_smoothScale';
procedure QImage_createAlphaMask; external QtShareName name QtNamePrefix + 'QImage_createAlphaMask';
procedure QImage_createHeuristicMask; external QtShareName name QtNamePrefix + 'QImage_createHeuristicMask';
procedure QImage_mirror(handle: QImageH; retval: QImageH); external QtShareName name QtNamePrefix + 'QImage_mirror';
procedure QImage_mirror(handle: QImageH; retval: QImageH; horizontally: Boolean; vertically: Boolean); external QtShareName name QtNamePrefix + 'QImage_mirror2';
procedure QImage_swapRGB; external QtShareName name QtNamePrefix + 'QImage_swapRGB';
function QImage_systemBitOrder; external QtShareName name QtNamePrefix + 'QImage_systemBitOrder';
function QImage_systemByteOrder; external QtShareName name QtNamePrefix + 'QImage_systemByteOrder';
function QImage_imageFormat; external QtShareName name QtNamePrefix + 'QImage_imageFormat';
procedure QImage_inputFormats; external QtShareName name QtNamePrefix + 'QImage_inputFormats';
procedure QImage_outputFormats; external QtShareName name QtNamePrefix + 'QImage_outputFormats';
procedure QImage_inputFormatList; external QtShareName name QtNamePrefix + 'QImage_inputFormatList';
procedure QImage_outputFormatList; external QtShareName name QtNamePrefix + 'QImage_outputFormatList';
function QImage_load; external QtShareName name QtNamePrefix + 'QImage_load';
function QImage_loadFromData(handle: QImageH; buf: PByte; len: Cardinal; format: PAnsiChar): Boolean; external QtShareName name QtNamePrefix + 'QImage_loadFromData';
function QImage_loadFromData(handle: QImageH; data: QByteArrayH; format: PAnsiChar): Boolean; external QtShareName name QtNamePrefix + 'QImage_loadFromData2';
function QImage_save(handle: QImageH; fileName: PWideString; format: PAnsiChar): Boolean; external QtShareName name QtNamePrefix + 'QImage_save';
function QImage_save(handle: QImageH; fileName: PWideString; format: PAnsiChar; quality: Integer): Boolean; external QtShareName name QtNamePrefix + 'QImage_save2';
function QImage_valid; external QtShareName name QtNamePrefix + 'QImage_valid';
function QImage_pixelIndex; external QtShareName name QtNamePrefix + 'QImage_pixelIndex';
procedure QImage_pixel; external QtShareName name QtNamePrefix + 'QImage_pixel';
procedure QImage_setPixel; external QtShareName name QtNamePrefix + 'QImage_setPixel';
function QImage_dotsPerMeterX; external QtShareName name QtNamePrefix + 'QImage_dotsPerMeterX';
function QImage_dotsPerMeterY; external QtShareName name QtNamePrefix + 'QImage_dotsPerMeterY';
procedure QImage_setDotsPerMeterX; external QtShareName name QtNamePrefix + 'QImage_setDotsPerMeterX';
procedure QImage_setDotsPerMeterY; external QtShareName name QtNamePrefix + 'QImage_setDotsPerMeterY';
procedure QImage_offset; external QtShareName name QtNamePrefix + 'QImage_offset';
procedure QImage_setOffset; external QtShareName name QtNamePrefix + 'QImage_setOffset';

procedure QImage_textLanguages; external QtShareName name QtNamePrefix + 'QImage_textLanguages';
procedure QImage_textKeys; external QtShareName name QtNamePrefix + 'QImage_textKeys';
procedure QImage_text(handle: QImageH; retval: PWideString; key: PAnsiChar; lang: PAnsiChar); external QtShareName name QtNamePrefix + 'QImage_text';
procedure QImage_text(handle: QImageH; retval: PWideString; p1: QImageTextKeyLangH); external QtShareName name QtNamePrefix + 'QImage_text2';
procedure QImage_setText; external QtShareName name QtNamePrefix + 'QImage_setText';

procedure QImageIO_destroy; external QtShareName name QtNamePrefix + 'QImageIO_destroy';
function QImageIO_create(): QImageIOH; external QtShareName name QtNamePrefix + 'QImageIO_create';
function QImageIO_create(ioDevice: QIODeviceH; format: PAnsiChar): QImageIOH; external QtShareName name QtNamePrefix + 'QImageIO_create2';
function QImageIO_create(fileName: PWideString; format: PAnsiChar): QImageIOH; external QtShareName name QtNamePrefix + 'QImageIO_create3';
function QImageIO_image; external QtShareName name QtNamePrefix + 'QImageIO_image';
function QImageIO_status; external QtShareName name QtNamePrefix + 'QImageIO_status';
function QImageIO_format; external QtShareName name QtNamePrefix + 'QImageIO_format';
function QImageIO_ioDevice; external QtShareName name QtNamePrefix + 'QImageIO_ioDevice';
procedure QImageIO_fileName; external QtShareName name QtNamePrefix + 'QImageIO_fileName';
function QImageIO_parameters; external QtShareName name QtNamePrefix + 'QImageIO_parameters';
procedure QImageIO_description; external QtShareName name QtNamePrefix + 'QImageIO_description';
procedure QImageIO_setImage; external QtShareName name QtNamePrefix + 'QImageIO_setImage';
procedure QImageIO_setStatus; external QtShareName name QtNamePrefix + 'QImageIO_setStatus';
procedure QImageIO_setFormat; external QtShareName name QtNamePrefix + 'QImageIO_setFormat';
procedure QImageIO_setIODevice; external QtShareName name QtNamePrefix + 'QImageIO_setIODevice';
procedure QImageIO_setFileName; external QtShareName name QtNamePrefix + 'QImageIO_setFileName';
procedure QImageIO_setParameters; external QtShareName name QtNamePrefix + 'QImageIO_setParameters';
procedure QImageIO_setDescription; external QtShareName name QtNamePrefix + 'QImageIO_setDescription';
function QImageIO_read; external QtShareName name QtNamePrefix + 'QImageIO_read';
function QImageIO_write; external QtShareName name QtNamePrefix + 'QImageIO_write';
function QImageIO_imageFormat(fileName: PWideString): PAnsiChar; external QtShareName name QtNamePrefix + 'QImageIO_imageFormat';
function QImageIO_imageFormat(p1: QIODeviceH): PAnsiChar; external QtShareName name QtNamePrefix + 'QImageIO_imageFormat2';
procedure QImageIO_inputFormats; external QtShareName name QtNamePrefix + 'QImageIO_inputFormats';
procedure QImageIO_outputFormats; external QtShareName name QtNamePrefix + 'QImageIO_outputFormats';

procedure QIconSet_destroy; external QtShareName name QtNamePrefix + 'QIconSet_destroy';
function QIconSet_create(): QIconSetH; external QtShareName name QtNamePrefix + 'QIconSet_create';
function QIconSet_create(p1: QPixmapH; p2: QIconSetSize): QIconSetH; external QtShareName name QtNamePrefix + 'QIconSet_create2';
function QIconSet_create(smallPix: QPixmapH; largePix: QPixmapH): QIconSetH; external QtShareName name QtNamePrefix + 'QIconSet_create3';
function QIconSet_create(p1: QIconSetH): QIconSetH; external QtShareName name QtNamePrefix + 'QIconSet_create4';
procedure QIconSet_reset; external QtShareName name QtNamePrefix + 'QIconSet_reset';
procedure QIconSet_setPixmap(handle: QIconSetH; p1: QPixmapH; p2: QIconSetSize; p3: QIconSetMode); external QtShareName name QtNamePrefix + 'QIconSet_setPixmap';
procedure QIconSet_setPixmap(handle: QIconSetH; p1: PWideString; p2: QIconSetSize; p3: QIconSetMode); external QtShareName name QtNamePrefix + 'QIconSet_setPixmap2';
procedure QIconSet_pixmap(handle: QIconSetH; retval: QPixmapH; p1: QIconSetSize; p2: QIconSetMode); external QtShareName name QtNamePrefix + 'QIconSet_pixmap';
procedure QIconSet_pixmap(handle: QIconSetH; retval: QPixmapH; s: QIconSetSize; enabled: Boolean); external QtShareName name QtNamePrefix + 'QIconSet_pixmap2';
procedure QIconSet_pixmap(handle: QIconSetH; retval: QPixmapH); external QtShareName name QtNamePrefix + 'QIconSet_pixmap3';
function QIconSet_isGenerated; external QtShareName name QtNamePrefix + 'QIconSet_isGenerated';
function QIconSet_isNull; external QtShareName name QtNamePrefix + 'QIconSet_isNull';
procedure QIconSet_detach; external QtShareName name QtNamePrefix + 'QIconSet_detach';

procedure QMovie_destroy; external QtShareName name QtNamePrefix + 'QMovie_destroy';
function QMovie_create(): QMovieH; external QtShareName name QtNamePrefix + 'QMovie_create';
function QMovie_create(bufsize: Integer): QMovieH; external QtShareName name QtNamePrefix + 'QMovie_create2';
function QMovie_create(p1: QDataSourceH; bufsize: Integer): QMovieH; external QtShareName name QtNamePrefix + 'QMovie_create3';
function QMovie_create(fileName: PWideString; bufsize: Integer): QMovieH; external QtShareName name QtNamePrefix + 'QMovie_create4';
function QMovie_create(data: QByteArrayH; bufsize: Integer): QMovieH; external QtShareName name QtNamePrefix + 'QMovie_create5';
function QMovie_create(p1: QMovieH): QMovieH; external QtShareName name QtNamePrefix + 'QMovie_create6';
function QMovie_pushSpace; external QtShareName name QtNamePrefix + 'QMovie_pushSpace';
procedure QMovie_pushData; external QtShareName name QtNamePrefix + 'QMovie_pushData';
function QMovie_backgroundColor; external QtShareName name QtNamePrefix + 'QMovie_backgroundColor';
procedure QMovie_setBackgroundColor; external QtShareName name QtNamePrefix + 'QMovie_setBackgroundColor';
procedure QMovie_getValidRect; external QtShareName name QtNamePrefix + 'QMovie_getValidRect';
function QMovie_framePixmap; external QtShareName name QtNamePrefix + 'QMovie_framePixmap';
function QMovie_frameImage; external QtShareName name QtNamePrefix + 'QMovie_frameImage';
function QMovie_isNull; external QtShareName name QtNamePrefix + 'QMovie_isNull';
function QMovie_frameNumber; external QtShareName name QtNamePrefix + 'QMovie_frameNumber';
function QMovie_steps; external QtShareName name QtNamePrefix + 'QMovie_steps';
function QMovie_paused; external QtShareName name QtNamePrefix + 'QMovie_paused';
function QMovie_finished; external QtShareName name QtNamePrefix + 'QMovie_finished';
function QMovie_running; external QtShareName name QtNamePrefix + 'QMovie_running';
procedure QMovie_unpause; external QtShareName name QtNamePrefix + 'QMovie_unpause';
procedure QMovie_pause; external QtShareName name QtNamePrefix + 'QMovie_pause';
procedure QMovie_step(handle: QMovieH); external QtShareName name QtNamePrefix + 'QMovie_step';
procedure QMovie_step(handle: QMovieH; p1: Integer); external QtShareName name QtNamePrefix + 'QMovie_step2';
procedure QMovie_restart; external QtShareName name QtNamePrefix + 'QMovie_restart';
function QMovie_speed; external QtShareName name QtNamePrefix + 'QMovie_speed';
procedure QMovie_setSpeed; external QtShareName name QtNamePrefix + 'QMovie_setSpeed';
procedure QMovie_connectResize; external QtShareName name QtNamePrefix + 'QMovie_connectResize';
procedure QMovie_disconnectResize; external QtShareName name QtNamePrefix + 'QMovie_disconnectResize';
procedure QMovie_connectUpdate; external QtShareName name QtNamePrefix + 'QMovie_connectUpdate';
procedure QMovie_disconnectUpdate; external QtShareName name QtNamePrefix + 'QMovie_disconnectUpdate';
procedure QMovie_setDisplayWidget; external QtShareName name QtNamePrefix + 'QMovie_setDisplayWidget';
procedure QMovie_connectStatus; external QtShareName name QtNamePrefix + 'QMovie_connectStatus';
procedure QMovie_disconnectStatus; external QtShareName name QtNamePrefix + 'QMovie_disconnectStatus';

procedure QPaintDevice_destroy; external QtShareName name QtNamePrefix + 'QPaintDevice_destroy';
function QPaintDevice_devType; external QtShareName name QtNamePrefix + 'QPaintDevice_devType';
function QPaintDevice_isExtDev; external QtShareName name QtNamePrefix + 'QPaintDevice_isExtDev';
function QPaintDevice_paintingActive; external QtShareName name QtNamePrefix + 'QPaintDevice_paintingActive';
function QPaintDevice_handle(handle: QPaintDeviceH): HDC; external QtShareName name QtNamePrefix + 'QPaintDevice_handle';

procedure QColorGroup_destroy; external QtShareName name QtNamePrefix + 'QColorGroup_destroy';
function QColorGroup_create(): QColorGroupH; external QtShareName name QtNamePrefix + 'QColorGroup_create';
function QColorGroup_create(foreground: QColorH; button: QColorH; light: QColorH; dark: QColorH; mid: QColorH; text: QColorH; base: QColorH): QColorGroupH; external QtShareName name QtNamePrefix + 'QColorGroup_create2';
function QColorGroup_create(foreground: QBrushH; button: QBrushH; light: QBrushH; dark: QBrushH; mid: QBrushH; text: QBrushH; bright_text: QBrushH; base: QBrushH; background: QBrushH): QColorGroupH; external QtShareName name QtNamePrefix + 'QColorGroup_create3';
function QColorGroup_create(p1: QColorGroupH): QColorGroupH; external QtShareName name QtNamePrefix + 'QColorGroup_create4';
function QColorGroup_color; external QtShareName name QtNamePrefix + 'QColorGroup_color';
function QColorGroup_brush; external QtShareName name QtNamePrefix + 'QColorGroup_brush';
procedure QColorGroup_setColor; external QtShareName name QtNamePrefix + 'QColorGroup_setColor';
procedure QColorGroup_setBrush; external QtShareName name QtNamePrefix + 'QColorGroup_setBrush';
function QColorGroup_foreground; external QtShareName name QtNamePrefix + 'QColorGroup_foreground';
function QColorGroup_button; external QtShareName name QtNamePrefix + 'QColorGroup_button';
function QColorGroup_light; external QtShareName name QtNamePrefix + 'QColorGroup_light';
function QColorGroup_dark; external QtShareName name QtNamePrefix + 'QColorGroup_dark';
function QColorGroup_mid; external QtShareName name QtNamePrefix + 'QColorGroup_mid';
function QColorGroup_text; external QtShareName name QtNamePrefix + 'QColorGroup_text';
function QColorGroup_base; external QtShareName name QtNamePrefix + 'QColorGroup_base';
function QColorGroup_background; external QtShareName name QtNamePrefix + 'QColorGroup_background';
function QColorGroup_midlight; external QtShareName name QtNamePrefix + 'QColorGroup_midlight';
function QColorGroup_brightText; external QtShareName name QtNamePrefix + 'QColorGroup_brightText';
function QColorGroup_buttonText; external QtShareName name QtNamePrefix + 'QColorGroup_buttonText';
function QColorGroup_shadow; external QtShareName name QtNamePrefix + 'QColorGroup_shadow';
function QColorGroup_highlight; external QtShareName name QtNamePrefix + 'QColorGroup_highlight';
function QColorGroup_highlightedText; external QtShareName name QtNamePrefix + 'QColorGroup_highlightedText';

procedure QPalette_destroy; external QtShareName name QtNamePrefix + 'QPalette_destroy';
function QPalette_create(): QPaletteH; external QtShareName name QtNamePrefix + 'QPalette_create';
function QPalette_create(button: QColorH): QPaletteH; external QtShareName name QtNamePrefix + 'QPalette_create2';
function QPalette_create(button: QColorH; background: QColorH): QPaletteH; external QtShareName name QtNamePrefix + 'QPalette_create3';
function QPalette_create(active: QColorGroupH; disabled: QColorGroupH; inactive: QColorGroupH): QPaletteH; external QtShareName name QtNamePrefix + 'QPalette_create4';
function QPalette_create(p1: QPaletteH): QPaletteH; external QtShareName name QtNamePrefix + 'QPalette_create5';
function QPalette_color; external QtShareName name QtNamePrefix + 'QPalette_color';
function QPalette_brush; external QtShareName name QtNamePrefix + 'QPalette_brush';
procedure QPalette_setColor(handle: QPaletteH; p1: QPaletteColorGroup; p2: QColorGroupColorRole; p3: QColorH); external QtShareName name QtNamePrefix + 'QPalette_setColor';
procedure QPalette_setBrush(handle: QPaletteH; p1: QPaletteColorGroup; p2: QColorGroupColorRole; p3: QBrushH); external QtShareName name QtNamePrefix + 'QPalette_setBrush';
procedure QPalette_setColor(handle: QPaletteH; p1: QColorGroupColorRole; p2: QColorH); external QtShareName name QtNamePrefix + 'QPalette_setColor2';
procedure QPalette_setBrush(handle: QPaletteH; p1: QColorGroupColorRole; p2: QBrushH); external QtShareName name QtNamePrefix + 'QPalette_setBrush2';
procedure QPalette_copy; external QtShareName name QtNamePrefix + 'QPalette_copy';
function QPalette_active; external QtShareName name QtNamePrefix + 'QPalette_active';
function QPalette_disabled; external QtShareName name QtNamePrefix + 'QPalette_disabled';
function QPalette_inactive; external QtShareName name QtNamePrefix + 'QPalette_inactive';
function QPalette_normal; external QtShareName name QtNamePrefix + 'QPalette_normal';
procedure QPalette_setActive; external QtShareName name QtNamePrefix + 'QPalette_setActive';
procedure QPalette_setDisabled; external QtShareName name QtNamePrefix + 'QPalette_setDisabled';
procedure QPalette_setInactive; external QtShareName name QtNamePrefix + 'QPalette_setInactive';
procedure QPalette_setNormal; external QtShareName name QtNamePrefix + 'QPalette_setNormal';
function QPalette_isCopyOf; external QtShareName name QtNamePrefix + 'QPalette_isCopyOf';
function QPalette_serialNumber; external QtShareName name QtNamePrefix + 'QPalette_serialNumber';

procedure QPixmap_destroy; external QtShareName name QtNamePrefix + 'QPixmap_destroy';
function QPixmap_create(): QPixmapH; external QtShareName name QtNamePrefix + 'QPixmap_create';
function QPixmap_create(w: Integer; h: Integer; depth: Integer; p4: QPixmapOptimization): QPixmapH; external QtShareName name QtNamePrefix + 'QPixmap_create2';
function QPixmap_create(p1: PSize; depth: Integer; p3: QPixmapOptimization): QPixmapH; external QtShareName name QtNamePrefix + 'QPixmap_create3';
function QPixmap_create(fileName: PWideString; format: PAnsiChar; mode: QPixmapColorMode): QPixmapH; external QtShareName name QtNamePrefix + 'QPixmap_create4';
function QPixmap_create(fileName: PWideString; format: PAnsiChar; conversion_flags: Integer): QPixmapH; external QtShareName name QtNamePrefix + 'QPixmap_create5';

function QPixmap_create(data: QByteArrayH): QPixmapH; external QtShareName name QtNamePrefix + 'QPixmap_create7';
function QPixmap_create(p1: QPixmapH): QPixmapH; external QtShareName name QtNamePrefix + 'QPixmap_create8';
function QPixmap_isNull; external QtShareName name QtNamePrefix + 'QPixmap_isNull';
function QPixmap_width; external QtShareName name QtNamePrefix + 'QPixmap_width';
function QPixmap_height; external QtShareName name QtNamePrefix + 'QPixmap_height';
procedure QPixmap_size; external QtShareName name QtNamePrefix + 'QPixmap_size';
procedure QPixmap_rect; external QtShareName name QtNamePrefix + 'QPixmap_rect';
function QPixmap_depth; external QtShareName name QtNamePrefix + 'QPixmap_depth';
function QPixmap_defaultDepth; external QtShareName name QtNamePrefix + 'QPixmap_defaultDepth';
procedure QPixmap_fill(handle: QPixmapH; fillColor: QColorH); external QtShareName name QtNamePrefix + 'QPixmap_fill';
procedure QPixmap_fill(handle: QPixmapH; p1: QWidgetH; xofs: Integer; yofs: Integer); external QtShareName name QtNamePrefix + 'QPixmap_fill2';
procedure QPixmap_fill(handle: QPixmapH; p1: QWidgetH; ofs: PPoint); external QtShareName name QtNamePrefix + 'QPixmap_fill3';
procedure QPixmap_resize(handle: QPixmapH; width: Integer; height: Integer); external QtShareName name QtNamePrefix + 'QPixmap_resize';
procedure QPixmap_resize(handle: QPixmapH; p1: PSize); external QtShareName name QtNamePrefix + 'QPixmap_resize2';
function QPixmap_mask; external QtShareName name QtNamePrefix + 'QPixmap_mask';
procedure QPixmap_setMask; external QtShareName name QtNamePrefix + 'QPixmap_setMask';
function QPixmap_selfMask; external QtShareName name QtNamePrefix + 'QPixmap_selfMask';
procedure QPixmap_createHeuristicMask; external QtShareName name QtNamePrefix + 'QPixmap_createHeuristicMask';
procedure QPixmap_grabWindow; external QtShareName name QtNamePrefix + 'QPixmap_grabWindow';
procedure QPixmap_grabWidget; external QtShareName name QtNamePrefix + 'QPixmap_grabWidget';
procedure QPixmap_xForm; external QtShareName name QtNamePrefix + 'QPixmap_xForm';
procedure QPixmap_trueMatrix; external QtShareName name QtNamePrefix + 'QPixmap_trueMatrix';
procedure QPixmap_convertToImage; external QtShareName name QtNamePrefix + 'QPixmap_convertToImage';
function QPixmap_convertFromImage(handle: QPixmapH; p1: QImageH; mode: QPixmapColorMode): Boolean; external QtShareName name QtNamePrefix + 'QPixmap_convertFromImage';
function QPixmap_convertFromImage(handle: QPixmapH; p1: QImageH; conversion_flags: Integer): Boolean; external QtShareName name QtNamePrefix + 'QPixmap_convertFromImage2';
function QPixmap_imageFormat; external QtShareName name QtNamePrefix + 'QPixmap_imageFormat';
function QPixmap_load(handle: QPixmapH; fileName: PWideString; format: PAnsiChar; mode: QPixmapColorMode): Boolean; external QtShareName name QtNamePrefix + 'QPixmap_load';
function QPixmap_load(handle: QPixmapH; fileName: PWideString; format: PAnsiChar; conversion_flags: Integer): Boolean; external QtShareName name QtNamePrefix + 'QPixmap_load2';
function QPixmap_loadFromData(handle: QPixmapH; buf: PByte; len: Cardinal; format: PAnsiChar; mode: QPixmapColorMode): Boolean; external QtShareName name QtNamePrefix + 'QPixmap_loadFromData';
function QPixmap_loadFromData(handle: QPixmapH; buf: PByte; len: Cardinal; format: PAnsiChar; conversion_flags: Integer): Boolean; external QtShareName name QtNamePrefix + 'QPixmap_loadFromData2';
function QPixmap_loadFromData(handle: QPixmapH; data: QByteArrayH; format: PAnsiChar; conversion_flags: Integer): Boolean; external QtShareName name QtNamePrefix + 'QPixmap_loadFromData3';
function QPixmap_save(handle: QPixmapH; fileName: PWideString; format: PAnsiChar): Boolean; external QtShareName name QtNamePrefix + 'QPixmap_save';
function QPixmap_save(handle: QPixmapH; fileName: PWideString; format: PAnsiChar; quality: Integer): Boolean; external QtShareName name QtNamePrefix + 'QPixmap_save2';
function QPixmap_hbm; external QtShareName name QtNamePrefix + 'QPixmap_hbm';
function QPixmap_serialNumber; external QtShareName name QtNamePrefix + 'QPixmap_serialNumber';
function QPixmap_optimization; external QtShareName name QtNamePrefix + 'QPixmap_optimization';
procedure QPixmap_setOptimization; external QtShareName name QtNamePrefix + 'QPixmap_setOptimization';
function QPixmap_defaultOptimization; external QtShareName name QtNamePrefix + 'QPixmap_defaultOptimization';
procedure QPixmap_setDefaultOptimization; external QtShareName name QtNamePrefix + 'QPixmap_setDefaultOptimization';
procedure QPixmap_detach; external QtShareName name QtNamePrefix + 'QPixmap_detach';
function QPixmap_isQBitmap; external QtShareName name QtNamePrefix + 'QPixmap_isQBitmap';
function QPixmap_isMultiCellPixmap; external QtShareName name QtNamePrefix + 'QPixmap_isMultiCellPixmap';
function QPixmap_multiCellHandle; external QtShareName name QtNamePrefix + 'QPixmap_multiCellHandle';
function QPixmap_multiCellBitmap; external QtShareName name QtNamePrefix + 'QPixmap_multiCellBitmap';
function QPixmap_multiCellOffset; external QtShareName name QtNamePrefix + 'QPixmap_multiCellOffset';
function QPixmap_allocCell; external QtShareName name QtNamePrefix + 'QPixmap_allocCell';
procedure QPixmap_freeCell; external QtShareName name QtNamePrefix + 'QPixmap_freeCell';

function QPixmap_clut; external QtShareName name QtNamePrefix + 'QPixmap_clut';
function QPixmap_numCols; external QtShareName name QtNamePrefix + 'QPixmap_numCols';

procedure QPrinter_destroy; external QtShareName name QtNamePrefix + 'QPrinter_destroy';
function QPrinter_create; external QtShareName name QtNamePrefix + 'QPrinter_create';
procedure QPrinter_printerName; external QtShareName name QtNamePrefix + 'QPrinter_printerName';
procedure QPrinter_setPrinterName; external QtShareName name QtNamePrefix + 'QPrinter_setPrinterName';
function QPrinter_outputToFile; external QtShareName name QtNamePrefix + 'QPrinter_outputToFile';
procedure QPrinter_setOutputToFile; external QtShareName name QtNamePrefix + 'QPrinter_setOutputToFile';
procedure QPrinter_outputFileName; external QtShareName name QtNamePrefix + 'QPrinter_outputFileName';
procedure QPrinter_setOutputFileName; external QtShareName name QtNamePrefix + 'QPrinter_setOutputFileName';
procedure QPrinter_printProgram; external QtShareName name QtNamePrefix + 'QPrinter_printProgram';
procedure QPrinter_setPrintProgram; external QtShareName name QtNamePrefix + 'QPrinter_setPrintProgram';
procedure QPrinter_printerSelectionOption; external QtShareName name QtNamePrefix + 'QPrinter_printerSelectionOption';
procedure QPrinter_setPrinterSelectionOption; external QtShareName name QtNamePrefix + 'QPrinter_setPrinterSelectionOption';
procedure QPrinter_docName; external QtShareName name QtNamePrefix + 'QPrinter_docName';
procedure QPrinter_setDocName; external QtShareName name QtNamePrefix + 'QPrinter_setDocName';
procedure QPrinter_creator; external QtShareName name QtNamePrefix + 'QPrinter_creator';
procedure QPrinter_setCreator; external QtShareName name QtNamePrefix + 'QPrinter_setCreator';
function QPrinter_orientation; external QtShareName name QtNamePrefix + 'QPrinter_orientation';
procedure QPrinter_setOrientation; external QtShareName name QtNamePrefix + 'QPrinter_setOrientation';
function QPrinter_pageSize; external QtShareName name QtNamePrefix + 'QPrinter_pageSize';
procedure QPrinter_setPageSize; external QtShareName name QtNamePrefix + 'QPrinter_setPageSize';
procedure QPrinter_setPageOrder; external QtShareName name QtNamePrefix + 'QPrinter_setPageOrder';
function QPrinter_pageOrder; external QtShareName name QtNamePrefix + 'QPrinter_pageOrder';
procedure QPrinter_setColorMode; external QtShareName name QtNamePrefix + 'QPrinter_setColorMode';
function QPrinter_colorMode; external QtShareName name QtNamePrefix + 'QPrinter_colorMode';
procedure QPrinter_setFullPage; external QtShareName name QtNamePrefix + 'QPrinter_setFullPage';
function QPrinter_fullPage; external QtShareName name QtNamePrefix + 'QPrinter_fullPage';
procedure QPrinter_margins; external QtShareName name QtNamePrefix + 'QPrinter_margins';
function QPrinter_fromPage; external QtShareName name QtNamePrefix + 'QPrinter_fromPage';
function QPrinter_toPage; external QtShareName name QtNamePrefix + 'QPrinter_toPage';
procedure QPrinter_setFromTo; external QtShareName name QtNamePrefix + 'QPrinter_setFromTo';
function QPrinter_minPage; external QtShareName name QtNamePrefix + 'QPrinter_minPage';
function QPrinter_maxPage; external QtShareName name QtNamePrefix + 'QPrinter_maxPage';
procedure QPrinter_setMinMax; external QtShareName name QtNamePrefix + 'QPrinter_setMinMax';
function QPrinter_numCopies; external QtShareName name QtNamePrefix + 'QPrinter_numCopies';
procedure QPrinter_setNumCopies; external QtShareName name QtNamePrefix + 'QPrinter_setNumCopies';
function QPrinter_newPage; external QtShareName name QtNamePrefix + 'QPrinter_newPage';
function QPrinter_abort; external QtShareName name QtNamePrefix + 'QPrinter_abort';
function QPrinter_aborted; external QtShareName name QtNamePrefix + 'QPrinter_aborted';
function QPrinter_setup; external QtShareName name QtNamePrefix + 'QPrinter_setup';

procedure QRegion_destroy; external QtShareName name QtNamePrefix + 'QRegion_destroy';
function QRegion_create(): QRegionH; external QtShareName name QtNamePrefix + 'QRegion_create';
function QRegion_create(x: Integer; y: Integer; w: Integer; h: Integer; p5: QRegionRegionType): QRegionH; external QtShareName name QtNamePrefix + 'QRegion_create2';
function QRegion_create(p1: PRect; p2: QRegionRegionType): QRegionH; external QtShareName name QtNamePrefix + 'QRegion_create3';
function QRegion_create(p1: PPointArray; winding: Boolean): QRegionH; external QtShareName name QtNamePrefix + 'QRegion_create4';
function QRegion_create(p1: QRegionH): QRegionH; external QtShareName name QtNamePrefix + 'QRegion_create5';
function QRegion_create(p1: QBitmapH): QRegionH; external QtShareName name QtNamePrefix + 'QRegion_create6';
function QRegion_isNull; external QtShareName name QtNamePrefix + 'QRegion_isNull';
function QRegion_isEmpty; external QtShareName name QtNamePrefix + 'QRegion_isEmpty';
function QRegion_contains(handle: QRegionH; p: PPoint): Boolean; external QtShareName name QtNamePrefix + 'QRegion_contains';
function QRegion_contains(handle: QRegionH; r: PRect): Boolean; external QtShareName name QtNamePrefix + 'QRegion_contains2';
procedure QRegion_translate; external QtShareName name QtNamePrefix + 'QRegion_translate';
procedure QRegion_unite; external QtShareName name QtNamePrefix + 'QRegion_unite';
procedure QRegion_intersect; external QtShareName name QtNamePrefix + 'QRegion_intersect';
procedure QRegion_subtract; external QtShareName name QtNamePrefix + 'QRegion_subtract';
procedure QRegion_eor; external QtShareName name QtNamePrefix + 'QRegion_eor';
procedure QRegion_boundingRect; external QtShareName name QtNamePrefix + 'QRegion_boundingRect';

procedure QRegion_setRects; external QtShareName name QtNamePrefix + 'QRegion_setRects';
function QRegion_handle(handle: QRegionH): HRGN; external QtShareName name QtNamePrefix + 'QRegion_handle';

procedure QObject_destroy; external QtShareName name QtNamePrefix + 'QObject_destroy';
function QObject_create; external QtShareName name QtNamePrefix + 'QObject_create';
procedure QObject_tr(retval: PWideString; p1: PAnsiChar); external QtShareName name QtNamePrefix + 'QObject_tr';
procedure QObject_tr(retval: PWideString; p1: PAnsiChar; p2: PAnsiChar); external QtShareName name QtNamePrefix + 'QObject_tr2';
function QObject_event; external QtShareName name QtNamePrefix + 'QObject_event';
function QObject_eventFilter; external QtShareName name QtNamePrefix + 'QObject_eventFilter';
function QObject_metaObject; external QtShareName name QtNamePrefix + 'QObject_metaObject';
function QObject_className; external QtShareName name QtNamePrefix + 'QObject_className';
function QObject_isA; external QtShareName name QtNamePrefix + 'QObject_isA';
function QObject_inherits; external QtShareName name QtNamePrefix + 'QObject_inherits';
function QObject_name(handle: QObjectH): PAnsiChar; external QtShareName name QtNamePrefix + 'QObject_name';
function QObject_name(handle: QObjectH; defaultName: PAnsiChar): PAnsiChar; external QtShareName name QtNamePrefix + 'QObject_name2';
procedure QObject_setName; external QtShareName name QtNamePrefix + 'QObject_setName';
function QObject_isWidgetType; external QtShareName name QtNamePrefix + 'QObject_isWidgetType';
function QObject_highPriority; external QtShareName name QtNamePrefix + 'QObject_highPriority';
function QObject_signalsBlocked; external QtShareName name QtNamePrefix + 'QObject_signalsBlocked';
procedure QObject_blockSignals; external QtShareName name QtNamePrefix + 'QObject_blockSignals';
function QObject_startTimer; external QtShareName name QtNamePrefix + 'QObject_startTimer';
procedure QObject_killTimer; external QtShareName name QtNamePrefix + 'QObject_killTimer';
procedure QObject_killTimers; external QtShareName name QtNamePrefix + 'QObject_killTimers';
function QObject_child; external QtShareName name QtNamePrefix + 'QObject_child';
function QObject_children; external QtShareName name QtNamePrefix + 'QObject_children';
function QObject_objectTrees; external QtShareName name QtNamePrefix + 'QObject_objectTrees';
function QObject_queryList; external QtShareName name QtNamePrefix + 'QObject_queryList';
procedure QObject_insertChild; external QtShareName name QtNamePrefix + 'QObject_insertChild';
procedure QObject_removeChild; external QtShareName name QtNamePrefix + 'QObject_removeChild';
procedure QObject_installEventFilter; external QtShareName name QtNamePrefix + 'QObject_installEventFilter';
procedure QObject_removeEventFilter; external QtShareName name QtNamePrefix + 'QObject_removeEventFilter';
function QObject_connect(sender: QObjectH; signal: PAnsiChar; receiver: QObjectH; member: PAnsiChar): Boolean; external QtShareName name QtNamePrefix + 'QObject_connect';
function QObject_connect(handle: QObjectH; sender: QObjectH; signal: PAnsiChar; member: PAnsiChar): Boolean; external QtShareName name QtNamePrefix + 'QObject_connect2';
function QObject_disconnect(sender: QObjectH; signal: PAnsiChar; receiver: QObjectH; member: PAnsiChar): Boolean; external QtShareName name QtNamePrefix + 'QObject_disconnect';

function QObject_disconnect(handle: QObjectH; receiver: QObjectH; member: PAnsiChar): Boolean; external QtShareName name QtNamePrefix + 'QObject_disconnect3';
procedure QObject_dumpObjectTree; external QtShareName name QtNamePrefix + 'QObject_dumpObjectTree';
procedure QObject_dumpObjectInfo; external QtShareName name QtNamePrefix + 'QObject_dumpObjectInfo';

function QObject_parent; external QtShareName name QtNamePrefix + 'QObject_parent';
procedure QObject_superClasses; external QtShareName name QtNamePrefix + 'QObject_superClasses';

procedure QSenderObject_destroy; external QtShareName name QtNamePrefix + 'QSenderObject_destroy';
procedure QSenderObject_setSender; external QtShareName name QtNamePrefix + 'QSenderObject_setSender';

procedure QBrush_destroy; external QtShareName name QtNamePrefix + 'QBrush_destroy';
function QBrush_create(): QBrushH; external QtShareName name QtNamePrefix + 'QBrush_create';
function QBrush_create(p1: BrushStyle): QBrushH; external QtShareName name QtNamePrefix + 'QBrush_create2';
function QBrush_create(p1: QColorH; p2: BrushStyle): QBrushH; external QtShareName name QtNamePrefix + 'QBrush_create3';
function QBrush_create(p1: QColorH; p2: QPixmapH): QBrushH; external QtShareName name QtNamePrefix + 'QBrush_create4';
function QBrush_create(p1: QBrushH): QBrushH; external QtShareName name QtNamePrefix + 'QBrush_create5';
function QBrush_style; external QtShareName name QtNamePrefix + 'QBrush_style';
procedure QBrush_setStyle; external QtShareName name QtNamePrefix + 'QBrush_setStyle';
function QBrush_color; external QtShareName name QtNamePrefix + 'QBrush_color';
procedure QBrush_setColor; external QtShareName name QtNamePrefix + 'QBrush_setColor';
function QBrush_pixmap; external QtShareName name QtNamePrefix + 'QBrush_pixmap';
procedure QBrush_setPixmap; external QtShareName name QtNamePrefix + 'QBrush_setPixmap';

procedure QButtonGroup_destroy; external QtShareName name QtNamePrefix + 'QButtonGroup_destroy';
function QButtonGroup_create(parent: QWidgetH; name: PAnsiChar): QButtonGroupH; external QtShareName name QtNamePrefix + 'QButtonGroup_create';
function QButtonGroup_create(title: PWideString; parent: QWidgetH; name: PAnsiChar): QButtonGroupH; external QtShareName name QtNamePrefix + 'QButtonGroup_create2';
function QButtonGroup_create(columns: Integer; o: Orientation; parent: QWidgetH; name: PAnsiChar): QButtonGroupH; external QtShareName name QtNamePrefix + 'QButtonGroup_create3';
function QButtonGroup_create(columns: Integer; o: Orientation; title: PWideString; parent: QWidgetH; name: PAnsiChar): QButtonGroupH; external QtShareName name QtNamePrefix + 'QButtonGroup_create4';
function QButtonGroup_isExclusive; external QtShareName name QtNamePrefix + 'QButtonGroup_isExclusive';
function QButtonGroup_isRadioButtonExclusive; external QtShareName name QtNamePrefix + 'QButtonGroup_isRadioButtonExclusive';
procedure QButtonGroup_setExclusive; external QtShareName name QtNamePrefix + 'QButtonGroup_setExclusive';
procedure QButtonGroup_setRadioButtonExclusive; external QtShareName name QtNamePrefix + 'QButtonGroup_setRadioButtonExclusive';
function QButtonGroup_insert; external QtShareName name QtNamePrefix + 'QButtonGroup_insert';
procedure QButtonGroup_remove; external QtShareName name QtNamePrefix + 'QButtonGroup_remove';
function QButtonGroup_find; external QtShareName name QtNamePrefix + 'QButtonGroup_find';
function QButtonGroup_id; external QtShareName name QtNamePrefix + 'QButtonGroup_id';
function QButtonGroup_count; external QtShareName name QtNamePrefix + 'QButtonGroup_count';
procedure QButtonGroup_setButton; external QtShareName name QtNamePrefix + 'QButtonGroup_setButton';
procedure QButtonGroup_moveFocus; external QtShareName name QtNamePrefix + 'QButtonGroup_moveFocus';
function QButtonGroup_selected; external QtShareName name QtNamePrefix + 'QButtonGroup_selected';

procedure QCheckBox_destroy; external QtShareName name QtNamePrefix + 'QCheckBox_destroy';
function QCheckBox_create(parent: QWidgetH; name: PAnsiChar): QCheckBoxH; external QtShareName name QtNamePrefix + 'QCheckBox_create';
function QCheckBox_create(text: PWideString; parent: QWidgetH; name: PAnsiChar): QCheckBoxH; external QtShareName name QtNamePrefix + 'QCheckBox_create2';
function QCheckBox_isChecked; external QtShareName name QtNamePrefix + 'QCheckBox_isChecked';
procedure QCheckBox_setChecked; external QtShareName name QtNamePrefix + 'QCheckBox_setChecked';
procedure QCheckBox_setNoChange; external QtShareName name QtNamePrefix + 'QCheckBox_setNoChange';
procedure QCheckBox_setTristate; external QtShareName name QtNamePrefix + 'QCheckBox_setTristate';
function QCheckBox_isTristate; external QtShareName name QtNamePrefix + 'QCheckBox_isTristate';
procedure QCheckBox_sizeHint; external QtShareName name QtNamePrefix + 'QCheckBox_sizeHint';
procedure QCheckBox_sizePolicy; external QtShareName name QtNamePrefix + 'QCheckBox_sizePolicy';

procedure QClipboard_destroy; external QtShareName name QtNamePrefix + 'QClipboard_destroy';
procedure QClipboard_clear; external QtShareName name QtNamePrefix + 'QClipboard_clear';
function QClipboard_ownsSelection; external QtShareName name QtNamePrefix + 'QClipboard_ownsSelection';
function QClipboard_data; external QtShareName name QtNamePrefix + 'QClipboard_data';
procedure QClipboard_setData; external QtShareName name QtNamePrefix + 'QClipboard_setData';
procedure QClipboard_text(handle: QClipboardH; retval: PWideString); external QtShareName name QtNamePrefix + 'QClipboard_text';
procedure QClipboard_text(handle: QClipboardH; retval: PWideString; subtype: PAnsiString); external QtShareName name QtNamePrefix + 'QClipboard_text2';
procedure QClipboard_setText; external QtShareName name QtNamePrefix + 'QClipboard_setText';
procedure QClipboard_image; external QtShareName name QtNamePrefix + 'QClipboard_image';
procedure QClipboard_pixmap; external QtShareName name QtNamePrefix + 'QClipboard_pixmap';
procedure QClipboard_setImage; external QtShareName name QtNamePrefix + 'QClipboard_setImage';
procedure QClipboard_setPixmap; external QtShareName name QtNamePrefix + 'QClipboard_setPixmap';

procedure QColorDialog_destroy; external QtShareName name QtNamePrefix + 'QColorDialog_destroy';
procedure QColorDialog_getColor; external QtShareName name QtNamePrefix + 'QColorDialog_getColor';
procedure QColorDialog_getRgba; external QtShareName name QtNamePrefix + 'QColorDialog_getRgba';
function QColorDialog_customCount; external QtShareName name QtNamePrefix + 'QColorDialog_customCount';
procedure QColorDialog_customColor; external QtShareName name QtNamePrefix + 'QColorDialog_customColor';
procedure QColorDialog_setCustomColor; external QtShareName name QtNamePrefix + 'QColorDialog_setCustomColor';

procedure QCommonStyle_destroy; external QtShareName name QtNamePrefix + 'QCommonStyle_destroy';
procedure QCommonStyle_drawComboButton; external QtShareName name QtNamePrefix + 'QCommonStyle_drawComboButton';
procedure QCommonStyle_comboButtonRect; external QtShareName name QtNamePrefix + 'QCommonStyle_comboButtonRect';
procedure QCommonStyle_comboButtonFocusRect; external QtShareName name QtNamePrefix + 'QCommonStyle_comboButtonFocusRect';
procedure QCommonStyle_drawComboButtonMask; external QtShareName name QtNamePrefix + 'QCommonStyle_drawComboButtonMask';
procedure QCommonStyle_drawPushButtonLabel; external QtShareName name QtNamePrefix + 'QCommonStyle_drawPushButtonLabel';
procedure QCommonStyle_getButtonShift; external QtShareName name QtNamePrefix + 'QCommonStyle_getButtonShift';
function QCommonStyle_defaultFrameWidth; external QtShareName name QtNamePrefix + 'QCommonStyle_defaultFrameWidth';
procedure QCommonStyle_tabbarMetrics; external QtShareName name QtNamePrefix + 'QCommonStyle_tabbarMetrics';
procedure QCommonStyle_drawTab; external QtShareName name QtNamePrefix + 'QCommonStyle_drawTab';
procedure QCommonStyle_drawTabMask; external QtShareName name QtNamePrefix + 'QCommonStyle_drawTabMask';
function QCommonStyle_scrollBarPointOver; external QtShareName name QtNamePrefix + 'QCommonStyle_scrollBarPointOver';
procedure QCommonStyle_drawSliderMask; external QtShareName name QtNamePrefix + 'QCommonStyle_drawSliderMask';
procedure QCommonStyle_drawSliderGrooveMask; external QtShareName name QtNamePrefix + 'QCommonStyle_drawSliderGrooveMask';
function QCommonStyle_maximumSliderDragDistance; external QtShareName name QtNamePrefix + 'QCommonStyle_maximumSliderDragDistance';
function QCommonStyle_popupSubmenuIndicatorWidth; external QtShareName name QtNamePrefix + 'QCommonStyle_popupSubmenuIndicatorWidth';
procedure QCommonStyle_drawMenuBarItem; external QtShareName name QtNamePrefix + 'QCommonStyle_drawMenuBarItem';

procedure QFontDialog_destroy; external QtShareName name QtNamePrefix + 'QFontDialog_destroy';
procedure QFontDialog_getFont(retval: QFontH; ok: PBoolean; def: QFontH; parent: QWidgetH; name: PAnsiChar); external QtShareName name QtNamePrefix + 'QFontDialog_getFont';
procedure QFontDialog_getFont(retval: QFontH; ok: PBoolean; parent: QWidgetH; name: PAnsiChar); external QtShareName name QtNamePrefix + 'QFontDialog_getFont2';

procedure QGroupBox_destroy; external QtShareName name QtNamePrefix + 'QGroupBox_destroy';
function QGroupBox_create(parent: QWidgetH; name: PAnsiChar): QGroupBoxH; external QtShareName name QtNamePrefix + 'QGroupBox_create';
function QGroupBox_create(title: PWideString; parent: QWidgetH; name: PAnsiChar): QGroupBoxH; external QtShareName name QtNamePrefix + 'QGroupBox_create2';
function QGroupBox_create(columns: Integer; o: Orientation; parent: QWidgetH; name: PAnsiChar): QGroupBoxH; external QtShareName name QtNamePrefix + 'QGroupBox_create3';
function QGroupBox_create(columns: Integer; o: Orientation; title: PWideString; parent: QWidgetH; name: PAnsiChar): QGroupBoxH; external QtShareName name QtNamePrefix + 'QGroupBox_create4';
procedure QGroupBox_setColumnLayout; external QtShareName name QtNamePrefix + 'QGroupBox_setColumnLayout';
procedure QGroupBox_title; external QtShareName name QtNamePrefix + 'QGroupBox_title';
procedure QGroupBox_setTitle; external QtShareName name QtNamePrefix + 'QGroupBox_setTitle';
function QGroupBox_alignment; external QtShareName name QtNamePrefix + 'QGroupBox_alignment';
procedure QGroupBox_setAlignment; external QtShareName name QtNamePrefix + 'QGroupBox_setAlignment';
function QGroupBox_columns; external QtShareName name QtNamePrefix + 'QGroupBox_columns';
procedure QGroupBox_setColumns; external QtShareName name QtNamePrefix + 'QGroupBox_setColumns';
function QGroupBox_orientation; external QtShareName name QtNamePrefix + 'QGroupBox_orientation';
procedure QGroupBox_setOrientation; external QtShareName name QtNamePrefix + 'QGroupBox_setOrientation';
procedure QGroupBox_addSpace; external QtShareName name QtNamePrefix + 'QGroupBox_addSpace';
procedure QGroupBox_sizeHint; external QtShareName name QtNamePrefix + 'QGroupBox_sizeHint';

procedure QHeader_destroy; external QtShareName name QtNamePrefix + 'QHeader_destroy';
function QHeader_create(parent: QWidgetH; name: PAnsiChar): QHeaderH; external QtShareName name QtNamePrefix + 'QHeader_create';
function QHeader_create(p1: Integer; parent: QWidgetH; name: PAnsiChar): QHeaderH; external QtShareName name QtNamePrefix + 'QHeader_create2';
function QHeader_addLabel(handle: QHeaderH; p1: PWideString; size: Integer): Integer; external QtShareName name QtNamePrefix + 'QHeader_addLabel';
function QHeader_addLabel(handle: QHeaderH; p1: QIconSetH; p2: PWideString; size: Integer): Integer; external QtShareName name QtNamePrefix + 'QHeader_addLabel2';
procedure QHeader_removeLabel; external QtShareName name QtNamePrefix + 'QHeader_removeLabel';
procedure QHeader_setLabel(handle: QHeaderH; p1: Integer; p2: PWideString; size: Integer); external QtShareName name QtNamePrefix + 'QHeader_setLabel';
procedure QHeader_setLabel(handle: QHeaderH; p1: Integer; p2: QIconSetH; p3: PWideString; size: Integer); external QtShareName name QtNamePrefix + 'QHeader_setLabel2';
procedure QHeader_label; external QtShareName name QtNamePrefix + 'QHeader_label';
function QHeader_iconSet; external QtShareName name QtNamePrefix + 'QHeader_iconSet';
procedure QHeader_setOrientation; external QtShareName name QtNamePrefix + 'QHeader_setOrientation';
function QHeader_orientation; external QtShareName name QtNamePrefix + 'QHeader_orientation';
procedure QHeader_setTracking; external QtShareName name QtNamePrefix + 'QHeader_setTracking';
function QHeader_tracking; external QtShareName name QtNamePrefix + 'QHeader_tracking';
procedure QHeader_setClickEnabled; external QtShareName name QtNamePrefix + 'QHeader_setClickEnabled';
procedure QHeader_setResizeEnabled; external QtShareName name QtNamePrefix + 'QHeader_setResizeEnabled';
procedure QHeader_setMovingEnabled; external QtShareName name QtNamePrefix + 'QHeader_setMovingEnabled';
function QHeader_isClickEnabled; external QtShareName name QtNamePrefix + 'QHeader_isClickEnabled';
function QHeader_isResizeEnabled; external QtShareName name QtNamePrefix + 'QHeader_isResizeEnabled';
function QHeader_isMovingEnabled; external QtShareName name QtNamePrefix + 'QHeader_isMovingEnabled';
procedure QHeader_resizeSection; external QtShareName name QtNamePrefix + 'QHeader_resizeSection';
function QHeader_sectionSize; external QtShareName name QtNamePrefix + 'QHeader_sectionSize';
function QHeader_sectionPos; external QtShareName name QtNamePrefix + 'QHeader_sectionPos';
function QHeader_sectionAt; external QtShareName name QtNamePrefix + 'QHeader_sectionAt';
function QHeader_count; external QtShareName name QtNamePrefix + 'QHeader_count';
procedure QHeader_setCellSize; external QtShareName name QtNamePrefix + 'QHeader_setCellSize';
function QHeader_cellSize; external QtShareName name QtNamePrefix + 'QHeader_cellSize';
function QHeader_cellPos; external QtShareName name QtNamePrefix + 'QHeader_cellPos';
function QHeader_cellAt; external QtShareName name QtNamePrefix + 'QHeader_cellAt';
function QHeader_offset; external QtShareName name QtNamePrefix + 'QHeader_offset';
procedure QHeader_sizeHint; external QtShareName name QtNamePrefix + 'QHeader_sizeHint';
procedure QHeader_sizePolicy; external QtShareName name QtNamePrefix + 'QHeader_sizePolicy';
function QHeader_mapToSection; external QtShareName name QtNamePrefix + 'QHeader_mapToSection';
function QHeader_mapToIndex; external QtShareName name QtNamePrefix + 'QHeader_mapToIndex';
function QHeader_mapToLogical; external QtShareName name QtNamePrefix + 'QHeader_mapToLogical';
function QHeader_mapToActual; external QtShareName name QtNamePrefix + 'QHeader_mapToActual';
procedure QHeader_moveSection; external QtShareName name QtNamePrefix + 'QHeader_moveSection';
procedure QHeader_moveCell; external QtShareName name QtNamePrefix + 'QHeader_moveCell';
procedure QHeader_setSortIndicator; external QtShareName name QtNamePrefix + 'QHeader_setSortIndicator';
procedure QHeader_setUpdatesEnabled; external QtShareName name QtNamePrefix + 'QHeader_setUpdatesEnabled';
procedure QHeader_setOffset; external QtShareName name QtNamePrefix + 'QHeader_setOffset';

procedure QLabel_destroy; external QtShareName name QtNamePrefix + 'QLabel_destroy';
function QLabel_create(parent: QWidgetH; name: PAnsiChar; f: WFlags): QLabelH; external QtShareName name QtNamePrefix + 'QLabel_create';
function QLabel_create(text: PWideString; parent: QWidgetH; name: PAnsiChar; f: WFlags): QLabelH; external QtShareName name QtNamePrefix + 'QLabel_create2';
function QLabel_create(buddy: QWidgetH; p2: PWideString; parent: QWidgetH; name: PAnsiChar; f: WFlags): QLabelH; external QtShareName name QtNamePrefix + 'QLabel_create3';
procedure QLabel_text; external QtShareName name QtNamePrefix + 'QLabel_text';
function QLabel_pixmap; external QtShareName name QtNamePrefix + 'QLabel_pixmap';
function QLabel_movie; external QtShareName name QtNamePrefix + 'QLabel_movie';
function QLabel_textFormat; external QtShareName name QtNamePrefix + 'QLabel_textFormat';
procedure QLabel_setTextFormat; external QtShareName name QtNamePrefix + 'QLabel_setTextFormat';
function QLabel_alignment; external QtShareName name QtNamePrefix + 'QLabel_alignment';
procedure QLabel_setAlignment; external QtShareName name QtNamePrefix + 'QLabel_setAlignment';
function QLabel_indent; external QtShareName name QtNamePrefix + 'QLabel_indent';
procedure QLabel_setIndent; external QtShareName name QtNamePrefix + 'QLabel_setIndent';
function QLabel_autoResize; external QtShareName name QtNamePrefix + 'QLabel_autoResize';
procedure QLabel_setAutoResize; external QtShareName name QtNamePrefix + 'QLabel_setAutoResize';
function QLabel_hasScaledContents; external QtShareName name QtNamePrefix + 'QLabel_hasScaledContents';
procedure QLabel_setScaledContents; external QtShareName name QtNamePrefix + 'QLabel_setScaledContents';
procedure QLabel_sizeHint; external QtShareName name QtNamePrefix + 'QLabel_sizeHint';
procedure QLabel_minimumSizeHint; external QtShareName name QtNamePrefix + 'QLabel_minimumSizeHint';
procedure QLabel_sizePolicy; external QtShareName name QtNamePrefix + 'QLabel_sizePolicy';
procedure QLabel_setBuddy; external QtShareName name QtNamePrefix + 'QLabel_setBuddy';
function QLabel_buddy; external QtShareName name QtNamePrefix + 'QLabel_buddy';
procedure QLabel_setAutoMask; external QtShareName name QtNamePrefix + 'QLabel_setAutoMask';
function QLabel_heightForWidth; external QtShareName name QtNamePrefix + 'QLabel_heightForWidth';
procedure QLabel_setText; external QtShareName name QtNamePrefix + 'QLabel_setText';
procedure QLabel_setPixmap; external QtShareName name QtNamePrefix + 'QLabel_setPixmap';
procedure QLabel_setMovie; external QtShareName name QtNamePrefix + 'QLabel_setMovie';
procedure QLabel_setNum(handle: QLabelH; p1: Integer); external QtShareName name QtNamePrefix + 'QLabel_setNum';
procedure QLabel_setNum(handle: QLabelH; p1: Double); external QtShareName name QtNamePrefix + 'QLabel_setNum2';
procedure QLabel_clear; external QtShareName name QtNamePrefix + 'QLabel_clear';

procedure QPainter_destroy; external QtShareName name QtNamePrefix + 'QPainter_destroy';
function QPainter_create(): QPainterH; external QtShareName name QtNamePrefix + 'QPainter_create';
function QPainter_create(p1: QPaintDeviceH): QPainterH; external QtShareName name QtNamePrefix + 'QPainter_create2';
function QPainter_create(p1: QPaintDeviceH; p2: QWidgetH): QPainterH; external QtShareName name QtNamePrefix + 'QPainter_create3';
function QPainter_begin(handle: QPainterH; p1: QPaintDeviceH): Boolean; external QtShareName name QtNamePrefix + 'QPainter_begin';
function QPainter_begin(handle: QPainterH; p1: QPaintDeviceH; p2: QWidgetH): Boolean; external QtShareName name QtNamePrefix + 'QPainter_begin2';
function QPainter_end; external QtShareName name QtNamePrefix + 'QPainter_end';
function QPainter_device; external QtShareName name QtNamePrefix + 'QPainter_device';

procedure QPainter_redirect; external QtShareName name QtNamePrefix + 'QPainter_redirect';
function QPainter_isActive; external QtShareName name QtNamePrefix + 'QPainter_isActive';
procedure QPainter_flush; external QtShareName name QtNamePrefix + 'QPainter_flush';
procedure QPainter_save; external QtShareName name QtNamePrefix + 'QPainter_save';
procedure QPainter_restore; external QtShareName name QtNamePrefix + 'QPainter_restore';
procedure QPainter_fontMetrics; external QtShareName name QtNamePrefix + 'QPainter_fontMetrics';
procedure QPainter_fontInfo; external QtShareName name QtNamePrefix + 'QPainter_fontInfo';
function QPainter_font; external QtShareName name QtNamePrefix + 'QPainter_font';
procedure QPainter_setFont; external QtShareName name QtNamePrefix + 'QPainter_setFont';
function QPainter_pen; external QtShareName name QtNamePrefix + 'QPainter_pen';
procedure QPainter_setPen(handle: QPainterH; p1: QPenH); external QtShareName name QtNamePrefix + 'QPainter_setPen';
procedure QPainter_setPen(handle: QPainterH; p1: PenStyle); external QtShareName name QtNamePrefix + 'QPainter_setPen2';
procedure QPainter_setPen(handle: QPainterH; p1: QColorH); external QtShareName name QtNamePrefix + 'QPainter_setPen3';
function QPainter_brush; external QtShareName name QtNamePrefix + 'QPainter_brush';
procedure QPainter_setBrush(handle: QPainterH; p1: QBrushH); external QtShareName name QtNamePrefix + 'QPainter_setBrush';
procedure QPainter_setBrush(handle: QPainterH; p1: BrushStyle); external QtShareName name QtNamePrefix + 'QPainter_setBrush2';
procedure QPainter_setBrush(handle: QPainterH; p1: QColorH); external QtShareName name QtNamePrefix + 'QPainter_setBrush3';
procedure QPainter_pos; external QtShareName name QtNamePrefix + 'QPainter_pos';
function QPainter_backgroundColor; external QtShareName name QtNamePrefix + 'QPainter_backgroundColor';
procedure QPainter_setBackgroundColor; external QtShareName name QtNamePrefix + 'QPainter_setBackgroundColor';
function QPainter_backgroundMode; external QtShareName name QtNamePrefix + 'QPainter_backgroundMode';
procedure QPainter_setBackgroundMode; external QtShareName name QtNamePrefix + 'QPainter_setBackgroundMode';
function QPainter_rasterOp; external QtShareName name QtNamePrefix + 'QPainter_rasterOp';
procedure QPainter_setRasterOp; external QtShareName name QtNamePrefix + 'QPainter_setRasterOp';
function QPainter_brushOrigin; external QtShareName name QtNamePrefix + 'QPainter_brushOrigin';
procedure QPainter_setBrushOrigin(handle: QPainterH; x: Integer; y: Integer); external QtShareName name QtNamePrefix + 'QPainter_setBrushOrigin';
procedure QPainter_setBrushOrigin(handle: QPainterH; p1: PPoint); external QtShareName name QtNamePrefix + 'QPainter_setBrushOrigin2';
function QPainter_hasViewXForm; external QtShareName name QtNamePrefix + 'QPainter_hasViewXForm';
function QPainter_hasWorldXForm; external QtShareName name QtNamePrefix + 'QPainter_hasWorldXForm';
procedure QPainter_setViewXForm; external QtShareName name QtNamePrefix + 'QPainter_setViewXForm';
procedure QPainter_window; external QtShareName name QtNamePrefix + 'QPainter_window';
procedure QPainter_setWindow(handle: QPainterH; p1: PRect); external QtShareName name QtNamePrefix + 'QPainter_setWindow';
procedure QPainter_setWindow(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QPainter_setWindow2';
procedure QPainter_viewport; external QtShareName name QtNamePrefix + 'QPainter_viewport';
procedure QPainter_setViewport(handle: QPainterH; p1: PRect); external QtShareName name QtNamePrefix + 'QPainter_setViewport';
procedure QPainter_setViewport(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QPainter_setViewport2';
procedure QPainter_setWorldXForm; external QtShareName name QtNamePrefix + 'QPainter_setWorldXForm';
function QPainter_worldMatrix; external QtShareName name QtNamePrefix + 'QPainter_worldMatrix';
procedure QPainter_setWorldMatrix; external QtShareName name QtNamePrefix + 'QPainter_setWorldMatrix';
procedure QPainter_saveWorldMatrix; external QtShareName name QtNamePrefix + 'QPainter_saveWorldMatrix';
procedure QPainter_restoreWorldMatrix; external QtShareName name QtNamePrefix + 'QPainter_restoreWorldMatrix';
procedure QPainter_scale; external QtShareName name QtNamePrefix + 'QPainter_scale';
procedure QPainter_shear; external QtShareName name QtNamePrefix + 'QPainter_shear';
procedure QPainter_rotate; external QtShareName name QtNamePrefix + 'QPainter_rotate';
procedure QPainter_translate; external QtShareName name QtNamePrefix + 'QPainter_translate';
procedure QPainter_resetXForm; external QtShareName name QtNamePrefix + 'QPainter_resetXForm';
procedure QPainter_xForm(handle: QPainterH; retval: PPoint; p1: PPoint); external QtShareName name QtNamePrefix + 'QPainter_xForm';
procedure QPainter_xForm(handle: QPainterH; retval: PRect; p1: PRect); external QtShareName name QtNamePrefix + 'QPainter_xForm2';
procedure QPainter_xForm(handle: QPainterH; retval: PPointArray; p1: PPointArray); external QtShareName name QtNamePrefix + 'QPainter_xForm3';
procedure QPainter_xForm(handle: QPainterH; retval: PPointArray; p1: PPointArray; index: Integer; npoints: Integer); external QtShareName name QtNamePrefix + 'QPainter_xForm4';
procedure QPainter_xFormDev(handle: QPainterH; retval: PPoint; p1: PPoint); external QtShareName name QtNamePrefix + 'QPainter_xFormDev';
procedure QPainter_xFormDev(handle: QPainterH; retval: PRect; p1: PRect); external QtShareName name QtNamePrefix + 'QPainter_xFormDev2';
procedure QPainter_xFormDev(handle: QPainterH; retval: PPointArray; p1: PPointArray); external QtShareName name QtNamePrefix + 'QPainter_xFormDev3';
procedure QPainter_xFormDev(handle: QPainterH; retval: PPointArray; p1: PPointArray; index: Integer; npoints: Integer); external QtShareName name QtNamePrefix + 'QPainter_xFormDev4';
procedure QPainter_setClipping; external QtShareName name QtNamePrefix + 'QPainter_setClipping';
function QPainter_hasClipping; external QtShareName name QtNamePrefix + 'QPainter_hasClipping';
function QPainter_clipRegion; external QtShareName name QtNamePrefix + 'QPainter_clipRegion';
procedure QPainter_setClipRect(handle: QPainterH; p1: PRect); external QtShareName name QtNamePrefix + 'QPainter_setClipRect';
procedure QPainter_setClipRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QPainter_setClipRect2';
procedure QPainter_setClipRegion; external QtShareName name QtNamePrefix + 'QPainter_setClipRegion';
procedure QPainter_drawPoint(handle: QPainterH; x: Integer; y: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawPoint';
procedure QPainter_drawPoint(handle: QPainterH; p1: PPoint); external QtShareName name QtNamePrefix + 'QPainter_drawPoint2';
procedure QPainter_drawPoints; external QtShareName name QtNamePrefix + 'QPainter_drawPoints';
procedure QPainter_moveTo(handle: QPainterH; x: Integer; y: Integer); external QtShareName name QtNamePrefix + 'QPainter_moveTo';
procedure QPainter_moveTo(handle: QPainterH; p1: PPoint); external QtShareName name QtNamePrefix + 'QPainter_moveTo2';
procedure QPainter_lineTo(handle: QPainterH; x: Integer; y: Integer); external QtShareName name QtNamePrefix + 'QPainter_lineTo';
procedure QPainter_lineTo(handle: QPainterH; p1: PPoint); external QtShareName name QtNamePrefix + 'QPainter_lineTo2';
procedure QPainter_drawLine(handle: QPainterH; x1: Integer; y1: Integer; x2: Integer; y2: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawLine';
procedure QPainter_drawLine(handle: QPainterH; p1: PPoint; p2: PPoint); external QtShareName name QtNamePrefix + 'QPainter_drawLine2';
procedure QPainter_drawRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawRect';
procedure QPainter_drawRect(handle: QPainterH; p1: PRect); external QtShareName name QtNamePrefix + 'QPainter_drawRect2';
procedure QPainter_drawWinFocusRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawWinFocusRect';
procedure QPainter_drawWinFocusRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; bgColor: QColorH); external QtShareName name QtNamePrefix + 'QPainter_drawWinFocusRect2';
procedure QPainter_drawWinFocusRect(handle: QPainterH; p1: PRect); external QtShareName name QtNamePrefix + 'QPainter_drawWinFocusRect3';
procedure QPainter_drawWinFocusRect(handle: QPainterH; p1: PRect; bgColor: QColorH); external QtShareName name QtNamePrefix + 'QPainter_drawWinFocusRect4';
procedure QPainter_drawRoundRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p5: Integer; p6: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawRoundRect';
procedure QPainter_drawRoundRect(handle: QPainterH; p1: PRect; p2: Integer; p3: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawRoundRect2';
procedure QPainter_drawRoundRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawRoundRect3';
procedure QPainter_drawRoundRect(handle: QPainterH; p1: PRect); external QtShareName name QtNamePrefix + 'QPainter_drawRoundRect4';
procedure QPainter_drawEllipse(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawEllipse';
procedure QPainter_drawEllipse(handle: QPainterH; p1: PRect); external QtShareName name QtNamePrefix + 'QPainter_drawEllipse2';
procedure QPainter_drawArc(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; a: Integer; alen: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawArc';
procedure QPainter_drawArc(handle: QPainterH; p1: PRect; a: Integer; alen: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawArc2';
procedure QPainter_drawPie(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; a: Integer; alen: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawPie';
procedure QPainter_drawPie(handle: QPainterH; p1: PRect; a: Integer; alen: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawPie2';
procedure QPainter_drawChord(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; a: Integer; alen: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawChord';
procedure QPainter_drawChord(handle: QPainterH; p1: PRect; a: Integer; alen: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawChord2';
procedure QPainter_drawLineSegments; external QtShareName name QtNamePrefix + 'QPainter_drawLineSegments';
procedure QPainter_drawPolyline; external QtShareName name QtNamePrefix + 'QPainter_drawPolyline';
procedure QPainter_drawPolygon; external QtShareName name QtNamePrefix + 'QPainter_drawPolygon';
procedure QPainter_drawQuadBezier; external QtShareName name QtNamePrefix + 'QPainter_drawQuadBezier';
procedure QPainter_drawPixmap(handle: QPainterH; x: Integer; y: Integer; p3: QPixmapH; sx: Integer; sy: Integer; sw: Integer; sh: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawPixmap';
procedure QPainter_drawPixmap(handle: QPainterH; p1: PPoint; p2: QPixmapH; sr: PRect); external QtShareName name QtNamePrefix + 'QPainter_drawPixmap2';
procedure QPainter_drawPixmap(handle: QPainterH; p1: PPoint; p2: QPixmapH); external QtShareName name QtNamePrefix + 'QPainter_drawPixmap3';
procedure QPainter_drawImage(handle: QPainterH; x: Integer; y: Integer; p3: QImageH; sx: Integer; sy: Integer; sw: Integer; sh: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawImage';
procedure QPainter_drawImage(handle: QPainterH; p1: PPoint; p2: QImageH; sr: PRect); external QtShareName name QtNamePrefix + 'QPainter_drawImage2';
procedure QPainter_drawImage(handle: QPainterH; p1: PPoint; p2: QImageH); external QtShareName name QtNamePrefix + 'QPainter_drawImage3';
procedure QPainter_drawImage(handle: QPainterH; x: Integer; y: Integer; p3: QImageH; sx: Integer; sy: Integer; sw: Integer; sh: Integer; conversion_flags: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawImage4';
procedure QPainter_drawImage(handle: QPainterH; p1: PPoint; p2: QImageH; sr: PRect; conversion_flags: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawImage5';
procedure QPainter_drawImage(handle: QPainterH; p1: PPoint; p2: QImageH; conversion_flags: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawImage6';
procedure QPainter_drawTiledPixmap(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p5: QPixmapH; sx: Integer; sy: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawTiledPixmap';
procedure QPainter_drawTiledPixmap(handle: QPainterH; p1: PRect; p2: QPixmapH; p3: PPoint); external QtShareName name QtNamePrefix + 'QPainter_drawTiledPixmap2';
procedure QPainter_drawTiledPixmap(handle: QPainterH; p1: PRect; p2: QPixmapH); external QtShareName name QtNamePrefix + 'QPainter_drawTiledPixmap3';
procedure QPainter_drawPicture; external QtShareName name QtNamePrefix + 'QPainter_drawPicture';
procedure QPainter_fillRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; p5: QBrushH); external QtShareName name QtNamePrefix + 'QPainter_fillRect';
procedure QPainter_fillRect(handle: QPainterH; p1: PRect; p2: QBrushH); external QtShareName name QtNamePrefix + 'QPainter_fillRect2';
procedure QPainter_eraseRect(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QPainter_eraseRect';
procedure QPainter_eraseRect(handle: QPainterH; p1: PRect); external QtShareName name QtNamePrefix + 'QPainter_eraseRect2';
procedure QPainter_drawText(handle: QPainterH; x: Integer; y: Integer; p3: PWideString; len: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawText';
procedure QPainter_drawText(handle: QPainterH; p1: PPoint; p2: PWideString; len: Integer); external QtShareName name QtNamePrefix + 'QPainter_drawText2';
procedure QPainter_drawText(handle: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; flags: Integer; p6: PWideString; len: Integer; br: PRect; internal: PPAnsiChar); external QtShareName name QtNamePrefix + 'QPainter_drawText3';
procedure QPainter_drawText(handle: QPainterH; p1: PRect; flags: Integer; p3: PWideString; len: Integer; br: PRect; internal: PPAnsiChar); external QtShareName name QtNamePrefix + 'QPainter_drawText4';
procedure QPainter_boundingRect(handle: QPainterH; retval: PRect; x: Integer; y: Integer; w: Integer; h: Integer; flags: Integer; p6: PWideString; len: Integer; intern: PPAnsiChar); external QtShareName name QtNamePrefix + 'QPainter_boundingRect';
procedure QPainter_boundingRect(handle: QPainterH; retval: PRect; p1: PRect; flags: Integer; p3: PWideString; len: Integer; intern: PPAnsiChar); external QtShareName name QtNamePrefix + 'QPainter_boundingRect2';
function QPainter_tabStops; external QtShareName name QtNamePrefix + 'QPainter_tabStops';
procedure QPainter_setTabStops; external QtShareName name QtNamePrefix + 'QPainter_setTabStops';
function QPainter_tabArray; external QtShareName name QtNamePrefix + 'QPainter_tabArray';
procedure QPainter_setTabArray; external QtShareName name QtNamePrefix + 'QPainter_setTabArray';
function QPainter_handle(handle: QPainterH): HDC; external QtShareName name QtNamePrefix + 'QPainter_handle';

procedure QPainter_initialize; external QtShareName name QtNamePrefix + 'QPainter_initialize';
procedure QPainter_cleanup; external QtShareName name QtNamePrefix + 'QPainter_cleanup';

procedure QPen_destroy; external QtShareName name QtNamePrefix + 'QPen_destroy';
function QPen_create(): QPenH; external QtShareName name QtNamePrefix + 'QPen_create';
function QPen_create(p1: PenStyle): QPenH; external QtShareName name QtNamePrefix + 'QPen_create2';
function QPen_create(color: QColorH; width: Cardinal; style: PenStyle): QPenH; external QtShareName name QtNamePrefix + 'QPen_create3';
function QPen_create(cl: QColorH; w: Cardinal; s: PenStyle; c: PenCapStyle; j: PenJoinStyle): QPenH; external QtShareName name QtNamePrefix + 'QPen_create4';
function QPen_create(p1: QPenH): QPenH; external QtShareName name QtNamePrefix + 'QPen_create5';
function QPen_style; external QtShareName name QtNamePrefix + 'QPen_style';
procedure QPen_setStyle; external QtShareName name QtNamePrefix + 'QPen_setStyle';
function QPen_width; external QtShareName name QtNamePrefix + 'QPen_width';
procedure QPen_setWidth; external QtShareName name QtNamePrefix + 'QPen_setWidth';
function QPen_color; external QtShareName name QtNamePrefix + 'QPen_color';
procedure QPen_setColor; external QtShareName name QtNamePrefix + 'QPen_setColor';
function QPen_capStyle; external QtShareName name QtNamePrefix + 'QPen_capStyle';
procedure QPen_setCapStyle; external QtShareName name QtNamePrefix + 'QPen_setCapStyle';
function QPen_joinStyle; external QtShareName name QtNamePrefix + 'QPen_joinStyle';
procedure QPen_setJoinStyle; external QtShareName name QtNamePrefix + 'QPen_setJoinStyle';

procedure QPopupMenu_destroy; external QtShareName name QtNamePrefix + 'QPopupMenu_destroy';
function QPopupMenu_create; external QtShareName name QtNamePrefix + 'QPopupMenu_create';
procedure QPopupMenu_popup; external QtShareName name QtNamePrefix + 'QPopupMenu_popup';
procedure QPopupMenu_updateItem; external QtShareName name QtNamePrefix + 'QPopupMenu_updateItem';
procedure QPopupMenu_setCheckable; external QtShareName name QtNamePrefix + 'QPopupMenu_setCheckable';
function QPopupMenu_isCheckable; external QtShareName name QtNamePrefix + 'QPopupMenu_isCheckable';
procedure QPopupMenu_setFont; external QtShareName name QtNamePrefix + 'QPopupMenu_setFont';
procedure QPopupMenu_show; external QtShareName name QtNamePrefix + 'QPopupMenu_show';
procedure QPopupMenu_hide; external QtShareName name QtNamePrefix + 'QPopupMenu_hide';
function QPopupMenu_exec(handle: QPopupMenuH): Integer; external QtShareName name QtNamePrefix + 'QPopupMenu_exec';
function QPopupMenu_exec(handle: QPopupMenuH; pos: PPoint; indexAtPoint: Integer): Integer; external QtShareName name QtNamePrefix + 'QPopupMenu_exec2';
procedure QPopupMenu_setActiveItem; external QtShareName name QtNamePrefix + 'QPopupMenu_setActiveItem';
procedure QPopupMenu_sizeHint; external QtShareName name QtNamePrefix + 'QPopupMenu_sizeHint';
function QPopupMenu_idAt(handle: QPopupMenuH; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QPopupMenu_idAt';
function QPopupMenu_idAt(handle: QPopupMenuH; pos: PPoint): Integer; external QtShareName name QtNamePrefix + 'QPopupMenu_idAt2';
function QPopupMenu_customWhatsThis; external QtShareName name QtNamePrefix + 'QPopupMenu_customWhatsThis';
function QPopupMenu_insertTearOffHandle; external QtShareName name QtNamePrefix + 'QPopupMenu_insertTearOffHandle';
procedure QPopupMenu_activateItemAt; external QtShareName name QtNamePrefix + 'QPopupMenu_activateItemAt';
function QPopupMenu_to_QMenuData; external QtSharename name QtNamePrefix + 'QPopupMenu_to_QMenuData';

procedure QPushButton_destroy; external QtShareName name QtNamePrefix + 'QPushButton_destroy';
function QPushButton_create(parent: QWidgetH; name: PAnsiChar): QPushButtonH; external QtShareName name QtNamePrefix + 'QPushButton_create';
function QPushButton_create(text: PWideString; parent: QWidgetH; name: PAnsiChar): QPushButtonH; external QtShareName name QtNamePrefix + 'QPushButton_create2';
function QPushButton_create(icon: QIconSetH; text: PWideString; parent: QWidgetH; name: PAnsiChar): QPushButtonH; external QtShareName name QtNamePrefix + 'QPushButton_create3';
procedure QPushButton_sizeHint; external QtShareName name QtNamePrefix + 'QPushButton_sizeHint';
procedure QPushButton_sizePolicy; external QtShareName name QtNamePrefix + 'QPushButton_sizePolicy';
procedure QPushButton_move(handle: QPushButtonH; x: Integer; y: Integer); external QtShareName name QtNamePrefix + 'QPushButton_move';
procedure QPushButton_move(handle: QPushButtonH; p: PPoint); external QtShareName name QtNamePrefix + 'QPushButton_move2';
procedure QPushButton_resize(handle: QPushButtonH; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QPushButton_resize';
procedure QPushButton_resize(handle: QPushButtonH; p1: PSize); external QtShareName name QtNamePrefix + 'QPushButton_resize2';
procedure QPushButton_setGeometry(handle: QPushButtonH; x: Integer; y: Integer; w: Integer; h: Integer); external QtShareName name QtNamePrefix + 'QPushButton_setGeometry';
procedure QPushButton_setGeometry(handle: QPushButtonH; p1: PRect); external QtShareName name QtNamePrefix + 'QPushButton_setGeometry2';
procedure QPushButton_setToggleButton; external QtShareName name QtNamePrefix + 'QPushButton_setToggleButton';
function QPushButton_autoDefault; external QtShareName name QtNamePrefix + 'QPushButton_autoDefault';
procedure QPushButton_setAutoDefault; external QtShareName name QtNamePrefix + 'QPushButton_setAutoDefault';
function QPushButton_isDefault; external QtShareName name QtNamePrefix + 'QPushButton_isDefault';
procedure QPushButton_setDefault; external QtShareName name QtNamePrefix + 'QPushButton_setDefault';
procedure QPushButton_setIsMenuButton; external QtShareName name QtNamePrefix + 'QPushButton_setIsMenuButton';
function QPushButton_isMenuButton; external QtShareName name QtNamePrefix + 'QPushButton_isMenuButton';
procedure QPushButton_setPopup; external QtShareName name QtNamePrefix + 'QPushButton_setPopup';
function QPushButton_popup; external QtShareName name QtNamePrefix + 'QPushButton_popup';
procedure QPushButton_setIconSet; external QtShareName name QtNamePrefix + 'QPushButton_setIconSet';
function QPushButton_iconSet; external QtShareName name QtNamePrefix + 'QPushButton_iconSet';
procedure QPushButton_setFlat; external QtShareName name QtNamePrefix + 'QPushButton_setFlat';
function QPushButton_isFlat; external QtShareName name QtNamePrefix + 'QPushButton_isFlat';
procedure QPushButton_setOn; external QtShareName name QtNamePrefix + 'QPushButton_setOn';
procedure QPushButton_toggle; external QtShareName name QtNamePrefix + 'QPushButton_toggle';

procedure QRadioButton_destroy; external QtShareName name QtNamePrefix + 'QRadioButton_destroy';
function QRadioButton_create(parent: QWidgetH; name: PAnsiChar): QRadioButtonH; external QtShareName name QtNamePrefix + 'QRadioButton_create';
function QRadioButton_create(text: PWideString; parent: QWidgetH; name: PAnsiChar): QRadioButtonH; external QtShareName name QtNamePrefix + 'QRadioButton_create2';
function QRadioButton_isChecked; external QtShareName name QtNamePrefix + 'QRadioButton_isChecked';
procedure QRadioButton_setChecked; external QtShareName name QtNamePrefix + 'QRadioButton_setChecked';
procedure QRadioButton_sizeHint; external QtShareName name QtNamePrefix + 'QRadioButton_sizeHint';
procedure QRadioButton_sizePolicy; external QtShareName name QtNamePrefix + 'QRadioButton_sizePolicy';

procedure QScrollBar_destroy; external QtShareName name QtNamePrefix + 'QScrollBar_destroy';
function QScrollBar_create(parent: QWidgetH; name: PAnsiChar): QScrollBarH; external QtShareName name QtNamePrefix + 'QScrollBar_create';
function QScrollBar_create(p1: Orientation; parent: QWidgetH; name: PAnsiChar): QScrollBarH; external QtShareName name QtNamePrefix + 'QScrollBar_create2';
function QScrollBar_create(minValue: Integer; maxValue: Integer; LineStep: Integer; PageStep: Integer; value: Integer; p6: Orientation; parent: QWidgetH; name: PAnsiChar): QScrollBarH; external QtShareName name QtNamePrefix + 'QScrollBar_create3';
procedure QScrollBar_setOrientation; external QtShareName name QtNamePrefix + 'QScrollBar_setOrientation';
function QScrollBar_orientation; external QtShareName name QtNamePrefix + 'QScrollBar_orientation';
procedure QScrollBar_setTracking; external QtShareName name QtNamePrefix + 'QScrollBar_setTracking';
function QScrollBar_tracking; external QtShareName name QtNamePrefix + 'QScrollBar_tracking';
function QScrollBar_draggingSlider; external QtShareName name QtNamePrefix + 'QScrollBar_draggingSlider';
procedure QScrollBar_setPalette; external QtShareName name QtNamePrefix + 'QScrollBar_setPalette';
procedure QScrollBar_sizeHint; external QtShareName name QtNamePrefix + 'QScrollBar_sizeHint';
procedure QScrollBar_sizePolicy; external QtShareName name QtNamePrefix + 'QScrollBar_sizePolicy';
function QScrollBar_minValue; external QtShareName name QtNamePrefix + 'QScrollBar_minValue';
function QScrollBar_maxValue; external QtShareName name QtNamePrefix + 'QScrollBar_maxValue';
procedure QScrollBar_setMinValue; external QtShareName name QtNamePrefix + 'QScrollBar_setMinValue';
procedure QScrollBar_setMaxValue; external QtShareName name QtNamePrefix + 'QScrollBar_setMaxValue';
function QScrollBar_lineStep; external QtShareName name QtNamePrefix + 'QScrollBar_lineStep';
function QScrollBar_pageStep; external QtShareName name QtNamePrefix + 'QScrollBar_pageStep';
procedure QScrollBar_setLineStep; external QtShareName name QtNamePrefix + 'QScrollBar_setLineStep';
procedure QScrollBar_setPageStep; external QtShareName name QtNamePrefix + 'QScrollBar_setPageStep';
function QScrollBar_value; external QtShareName name QtNamePrefix + 'QScrollBar_value';
procedure QScrollBar_setValue; external QtShareName name QtNamePrefix + 'QScrollBar_setValue';
function QScrollBar_to_QRangeControl; external QtSharename name QtNamePrefix + 'QScrollBar_to_QRangeControl';

procedure QSizeGrip_destroy; external QtShareName name QtNamePrefix + 'QSizeGrip_destroy';
function QSizeGrip_create; external QtShareName name QtNamePrefix + 'QSizeGrip_create';
procedure QSizeGrip_sizeHint; external QtShareName name QtNamePrefix + 'QSizeGrip_sizeHint';
procedure QSizeGrip_sizePolicy; external QtShareName name QtNamePrefix + 'QSizeGrip_sizePolicy';

procedure QTableView_destroy; external QtShareName name QtNamePrefix + 'QTableView_destroy';
procedure QTableView_setBackgroundColor; external QtShareName name QtNamePrefix + 'QTableView_setBackgroundColor';
procedure QTableView_setPalette; external QtShareName name QtNamePrefix + 'QTableView_setPalette';
procedure QTableView_show; external QtShareName name QtNamePrefix + 'QTableView_show';
procedure QTableView_repaint(handle: QTableViewH; erase: Boolean); external QtShareName name QtNamePrefix + 'QTableView_repaint';
procedure QTableView_repaint(handle: QTableViewH; x: Integer; y: Integer; w: Integer; h: Integer; erase: Boolean); external QtShareName name QtNamePrefix + 'QTableView_repaint2';
procedure QTableView_repaint(handle: QTableViewH; p1: PRect; erase: Boolean); external QtShareName name QtNamePrefix + 'QTableView_repaint3';

procedure QTextBrowser_destroy; external QtShareName name QtNamePrefix + 'QTextBrowser_destroy';
function QTextBrowser_create; external QtShareName name QtNamePrefix + 'QTextBrowser_create';
procedure QTextBrowser_setSource; external QtShareName name QtNamePrefix + 'QTextBrowser_setSource';
procedure QTextBrowser_source; external QtShareName name QtNamePrefix + 'QTextBrowser_source';
procedure QTextBrowser_setText; external QtShareName name QtNamePrefix + 'QTextBrowser_setText';
procedure QTextBrowser_scrollToAnchor; external QtShareName name QtNamePrefix + 'QTextBrowser_scrollToAnchor';
procedure QTextBrowser_backward; external QtShareName name QtNamePrefix + 'QTextBrowser_backward';
procedure QTextBrowser_forward; external QtShareName name QtNamePrefix + 'QTextBrowser_forward';
procedure QTextBrowser_home; external QtShareName name QtNamePrefix + 'QTextBrowser_home';

procedure QTextView_destroy; external QtShareName name QtNamePrefix + 'QTextView_destroy';
function QTextView_create(parent: QWidgetH; name: PAnsiChar): QTextViewH; external QtShareName name QtNamePrefix + 'QTextView_create';
function QTextView_create(text: PWideString; context: PWideString; parent: QWidgetH; name: PAnsiChar): QTextViewH; external QtShareName name QtNamePrefix + 'QTextView_create2';
procedure QTextView_setText(handle: QTextViewH; text: PWideString; context: PWideString); external QtShareName name QtNamePrefix + 'QTextView_setText';
procedure QTextView_setText(handle: QTextViewH; text: PWideString); external QtShareName name QtNamePrefix + 'QTextView_setText2';
procedure QTextView_text; external QtShareName name QtNamePrefix + 'QTextView_text';
procedure QTextView_context; external QtShareName name QtNamePrefix + 'QTextView_context';
function QTextView_textFormat; external QtShareName name QtNamePrefix + 'QTextView_textFormat';
procedure QTextView_setTextFormat; external QtShareName name QtNamePrefix + 'QTextView_setTextFormat';
function QTextView_styleSheet; external QtShareName name QtNamePrefix + 'QTextView_styleSheet';
procedure QTextView_setStyleSheet; external QtShareName name QtNamePrefix + 'QTextView_setStyleSheet';
procedure QTextView_setPaper; external QtShareName name QtNamePrefix + 'QTextView_setPaper';
function QTextView_paper(handle: QTextViewH): QBrushH; external QtShareName name QtNamePrefix + 'QTextView_paper';

procedure QTextView_setPaperColorGroup; external QtShareName name QtNamePrefix + 'QTextView_setPaperColorGroup';
function QTextView_paperColorGroup; external QtShareName name QtNamePrefix + 'QTextView_paperColorGroup';
procedure QTextView_setLinkColor; external QtShareName name QtNamePrefix + 'QTextView_setLinkColor';
function QTextView_linkColor; external QtShareName name QtNamePrefix + 'QTextView_linkColor';
procedure QTextView_setLinkUnderline; external QtShareName name QtNamePrefix + 'QTextView_setLinkUnderline';
function QTextView_linkUnderline; external QtShareName name QtNamePrefix + 'QTextView_linkUnderline';
procedure QTextView_setMimeSourceFactory; external QtShareName name QtNamePrefix + 'QTextView_setMimeSourceFactory';
function QTextView_mimeSourceFactory; external QtShareName name QtNamePrefix + 'QTextView_mimeSourceFactory';
procedure QTextView_documentTitle; external QtShareName name QtNamePrefix + 'QTextView_documentTitle';
function QTextView_heightForWidth; external QtShareName name QtNamePrefix + 'QTextView_heightForWidth';
procedure QTextView_append; external QtShareName name QtNamePrefix + 'QTextView_append';
function QTextView_hasSelectedText; external QtShareName name QtNamePrefix + 'QTextView_hasSelectedText';
procedure QTextView_selectedText; external QtShareName name QtNamePrefix + 'QTextView_selectedText';
procedure QTextView_copy; external QtShareName name QtNamePrefix + 'QTextView_copy';
procedure QTextView_selectAll; external QtShareName name QtNamePrefix + 'QTextView_selectAll';

procedure QWhatsThis_destroy; external QtShareName name QtNamePrefix + 'QWhatsThis_destroy';
function QWhatsThis_create; external QtShareName name QtNamePrefix + 'QWhatsThis_create';
procedure QWhatsThis_text; external QtShareName name QtNamePrefix + 'QWhatsThis_text';
procedure QWhatsThis_add; external QtShareName name QtNamePrefix + 'QWhatsThis_add';
procedure QWhatsThis_remove; external QtShareName name QtNamePrefix + 'QWhatsThis_remove';
procedure QWhatsThis_textFor; external QtShareName name QtNamePrefix + 'QWhatsThis_textFor';
function QWhatsThis_whatsThisButton; external QtShareName name QtNamePrefix + 'QWhatsThis_whatsThisButton';
procedure QWhatsThis_enterWhatsThisMode; external QtShareName name QtNamePrefix + 'QWhatsThis_enterWhatsThisMode';
function QWhatsThis_inWhatsThisMode; external QtShareName name QtNamePrefix + 'QWhatsThis_inWhatsThisMode';
procedure QWhatsThis_leaveWhatsThisMode; external QtShareName name QtNamePrefix + 'QWhatsThis_leaveWhatsThisMode';

procedure QWindowsStyle_destroy; external QtShareName name QtNamePrefix + 'QWindowsStyle_destroy';
function QWindowsStyle_create; external QtShareName name QtNamePrefix + 'QWindowsStyle_create';
procedure QWindowsStyle_drawButton; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawButton';
procedure QWindowsStyle_drawBevelButton; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawBevelButton';
procedure QWindowsStyle_drawFocusRect; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawFocusRect';
procedure QWindowsStyle_drawPushButton; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawPushButton';
procedure QWindowsStyle_getButtonShift; external QtShareName name QtNamePrefix + 'QWindowsStyle_getButtonShift';
procedure QWindowsStyle_drawPanel; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawPanel';
procedure QWindowsStyle_drawPopupPanel; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawPopupPanel';
procedure QWindowsStyle_drawArrow; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawArrow';
procedure QWindowsStyle_indicatorSize; external QtShareName name QtNamePrefix + 'QWindowsStyle_indicatorSize';
procedure QWindowsStyle_drawIndicator; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawIndicator';
procedure QWindowsStyle_exclusiveIndicatorSize; external QtShareName name QtNamePrefix + 'QWindowsStyle_exclusiveIndicatorSize';
procedure QWindowsStyle_drawExclusiveIndicator; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawExclusiveIndicator';
procedure QWindowsStyle_drawExclusiveIndicatorMask; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawExclusiveIndicatorMask';
procedure QWindowsStyle_drawComboButton; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawComboButton';
procedure QWindowsStyle_comboButtonRect; external QtShareName name QtNamePrefix + 'QWindowsStyle_comboButtonRect';
procedure QWindowsStyle_comboButtonFocusRect; external QtShareName name QtNamePrefix + 'QWindowsStyle_comboButtonFocusRect';
procedure QWindowsStyle_tabbarMetrics; external QtShareName name QtNamePrefix + 'QWindowsStyle_tabbarMetrics';
procedure QWindowsStyle_drawTab; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawTab';
procedure QWindowsStyle_drawTabMask; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawTabMask';
procedure QWindowsStyle_scrollBarMetrics; external QtShareName name QtNamePrefix + 'QWindowsStyle_scrollBarMetrics';
procedure QWindowsStyle_drawScrollBarControls; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawScrollBarControls';
function QWindowsStyle_sliderLength; external QtShareName name QtNamePrefix + 'QWindowsStyle_sliderLength';
procedure QWindowsStyle_drawSlider; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawSlider';
procedure QWindowsStyle_drawSliderMask; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawSliderMask';
procedure QWindowsStyle_drawSliderGroove; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawSliderGroove';
function QWindowsStyle_maximumSliderDragDistance; external QtShareName name QtNamePrefix + 'QWindowsStyle_maximumSliderDragDistance';
function QWindowsStyle_splitterWidth; external QtShareName name QtNamePrefix + 'QWindowsStyle_splitterWidth';
procedure QWindowsStyle_drawSplitter; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawSplitter';
procedure QWindowsStyle_drawCheckMark; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawCheckMark';
procedure QWindowsStyle_polishPopupMenu; external QtShareName name QtNamePrefix + 'QWindowsStyle_polishPopupMenu';
function QWindowsStyle_extraPopupMenuItemWidth; external QtShareName name QtNamePrefix + 'QWindowsStyle_extraPopupMenuItemWidth';
function QWindowsStyle_popupMenuItemHeight; external QtShareName name QtNamePrefix + 'QWindowsStyle_popupMenuItemHeight';
procedure QWindowsStyle_drawPopupMenuItem; external QtShareName name QtNamePrefix + 'QWindowsStyle_drawPopupMenuItem';

procedure QTimer_destroy; external QtShareName name QtNamePrefix + 'QTimer_destroy';
function QTimer_create; external QtShareName name QtNamePrefix + 'QTimer_create';
function QTimer_isActive; external QtShareName name QtNamePrefix + 'QTimer_isActive';
function QTimer_start; external QtShareName name QtNamePrefix + 'QTimer_start';
procedure QTimer_changeInterval; external QtShareName name QtNamePrefix + 'QTimer_changeInterval';
procedure QTimer_stop; external QtShareName name QtNamePrefix + 'QTimer_stop';
procedure QTimer_singleShot; external QtShareName name QtNamePrefix + 'QTimer_singleShot';

procedure QWorkspace_destroy; external QtShareName name QtNamePrefix + 'QWorkspace_destroy';
function QWorkspace_create; external QtShareName name QtNamePrefix + 'QWorkspace_create';
function QWorkspace_activeWindow; external QtShareName name QtNamePrefix + 'QWorkspace_activeWindow';

procedure QWorkspace_sizePolicy; external QtShareName name QtNamePrefix + 'QWorkspace_sizePolicy';
procedure QWorkspace_sizeHint; external QtShareName name QtNamePrefix + 'QWorkspace_sizeHint';
procedure QWorkspace_cascade; external QtShareName name QtNamePrefix + 'QWorkspace_cascade';
procedure QWorkspace_tile; external QtShareName name QtNamePrefix + 'QWorkspace_tile';

procedure QBitmap_destroy; external QtShareName name QtNamePrefix + 'QBitmap_destroy';
function QBitmap_create(): QBitmapH; external QtShareName name QtNamePrefix + 'QBitmap_create';
function QBitmap_create(w: Integer; h: Integer; clear: Boolean; p4: QPixmapOptimization): QBitmapH; external QtShareName name QtNamePrefix + 'QBitmap_create2';
function QBitmap_create(p1: PSize; clear: Boolean; p3: QPixmapOptimization): QBitmapH; external QtShareName name QtNamePrefix + 'QBitmap_create3';
function QBitmap_create(w: Integer; h: Integer; bits: PByte; isXbitmap: Boolean): QBitmapH; external QtShareName name QtNamePrefix + 'QBitmap_create4';
function QBitmap_create(p1: PSize; bits: PByte; isXbitmap: Boolean): QBitmapH; external QtShareName name QtNamePrefix + 'QBitmap_create5';
function QBitmap_create(p1: QBitmapH): QBitmapH; external QtShareName name QtNamePrefix + 'QBitmap_create6';
function QBitmap_create(fileName: PWideString; format: PAnsiChar): QBitmapH; external QtShareName name QtNamePrefix + 'QBitmap_create7';
procedure QBitmap_xForm; external QtShareName name QtNamePrefix + 'QBitmap_xForm';

function QCursor_create(): QCursorH; external QtShareName name QtNamePrefix + 'QCursor_create';
function QCursor_create(shape: Integer): QCursorH; external QtShareName name QtNamePrefix + 'QCursor_create2';
function QCursor_create(bitmap: QBitmapH; mask: QBitmapH; hotX: Integer; hotY: Integer): QCursorH; external QtShareName name QtNamePrefix + 'QCursor_create3';
function QCursor_create(pixmap: QPixmapH; hotX: Integer; hotY: Integer): QCursorH; external QtShareName name QtNamePrefix + 'QCursor_create4';
function QCursor_create(p1: QCursorH): QCursorH; external QtShareName name QtNamePrefix + 'QCursor_create5';
function QCursor_shape; external QtShareName name QtNamePrefix + 'QCursor_shape';
procedure QCursor_setShape; external QtShareName name QtNamePrefix + 'QCursor_setShape';
function QCursor_bitmap; external QtShareName name QtNamePrefix + 'QCursor_bitmap';
function QCursor_mask; external QtShareName name QtNamePrefix + 'QCursor_mask';
procedure QCursor_hotSpot; external QtShareName name QtNamePrefix + 'QCursor_hotSpot';
function QCursor_handle(handle: QCursorH): HCURSOR; external QtShareName name QtNamePrefix + 'QCursor_handle';

procedure QCursor_initialize; external QtShareName name QtNamePrefix + 'QCursor_initialize';
procedure QCursor_cleanup; external QtShareName name QtNamePrefix + 'QCursor_cleanup';

procedure QCursor_destroy; external QtShareName name QtNamePrefix + 'QCursor_destroy';
procedure QCursor_pos; external QtShareName name QtNamePrefix + 'QCursor_pos';
procedure QCursor_setPos(x: Integer; y: Integer); external QtShareName name QtNamePrefix + 'QCursor_setPos';
procedure QCursor_setPos(p1: PPoint); external QtShareName name QtNamePrefix + 'QCursor_setPos2';

procedure QFontDatabase_destroy; external QtShareName name QtNamePrefix + 'QFontDatabase_destroy';
function QFontDatabase_create; external QtShareName name QtNamePrefix + 'QFontDatabase_create';
procedure QFontDatabase_families; external QtShareName name QtNamePrefix + 'QFontDatabase_families';
procedure QFontDatabase_pointSizes; external QtShareName name QtNamePrefix + 'QFontDatabase_pointSizes';
procedure QFontDatabase_styles; external QtShareName name QtNamePrefix + 'QFontDatabase_styles';
procedure QFontDatabase_charSets(handle: QFontDatabaseH; retval: QStringListH; familyName: PWideString; onlyForLocale: Boolean); external QtShareName name QtNamePrefix + 'QFontDatabase_charSets';
procedure QFontDatabase_font; external QtShareName name QtNamePrefix + 'QFontDatabase_font';
function QFontDatabase_isBitmapScalable; external QtShareName name QtNamePrefix + 'QFontDatabase_isBitmapScalable';
function QFontDatabase_isSmoothlyScalable; external QtShareName name QtNamePrefix + 'QFontDatabase_isSmoothlyScalable';
function QFontDatabase_isScalable; external QtShareName name QtNamePrefix + 'QFontDatabase_isScalable';
procedure QFontDatabase_smoothSizes; external QtShareName name QtNamePrefix + 'QFontDatabase_smoothSizes';
procedure QFontDatabase_standardSizes; external QtShareName name QtNamePrefix + 'QFontDatabase_standardSizes';
function QFontDatabase_italic; external QtShareName name QtNamePrefix + 'QFontDatabase_italic';
function QFontDatabase_bold; external QtShareName name QtNamePrefix + 'QFontDatabase_bold';
function QFontDatabase_weight; external QtShareName name QtNamePrefix + 'QFontDatabase_weight';

procedure QFontDatabase_styleString; external QtShareName name QtNamePrefix + 'QFontDatabase_styleString';
procedure QFontDatabase_verboseCharSetName; external QtShareName name QtNamePrefix + 'QFontDatabase_verboseCharSetName';
procedure QFontDatabase_charSetSample; external QtShareName name QtNamePrefix + 'QFontDatabase_charSetSample';

procedure QFontInfo_destroy; external QtShareName name QtNamePrefix + 'QFontInfo_destroy';
function QFontInfo_create(p1: QFontH): QFontInfoH; external QtShareName name QtNamePrefix + 'QFontInfo_create';
function QFontInfo_create(p1: QFontInfoH): QFontInfoH; external QtShareName name QtNamePrefix + 'QFontInfo_create2';
procedure QFontInfo_family; external QtShareName name QtNamePrefix + 'QFontInfo_family';
function QFontInfo_pointSize; external QtShareName name QtNamePrefix + 'QFontInfo_pointSize';
function QFontInfo_italic; external QtShareName name QtNamePrefix + 'QFontInfo_italic';
function QFontInfo_weight; external QtShareName name QtNamePrefix + 'QFontInfo_weight';
function QFontInfo_bold; external QtShareName name QtNamePrefix + 'QFontInfo_bold';
function QFontInfo_underline; external QtShareName name QtNamePrefix + 'QFontInfo_underline';
function QFontInfo_strikeOut; external QtShareName name QtNamePrefix + 'QFontInfo_strikeOut';
function QFontInfo_fixedPitch; external QtShareName name QtNamePrefix + 'QFontInfo_fixedPitch';
function QFontInfo_styleHint; external QtShareName name QtNamePrefix + 'QFontInfo_styleHint';
function QFontInfo_charSet; external QtShareName name QtNamePrefix + 'QFontInfo_charSet';
function QFontInfo_rawMode; external QtShareName name QtNamePrefix + 'QFontInfo_rawMode';
function QFontInfo_exactMatch; external QtShareName name QtNamePrefix + 'QFontInfo_exactMatch';
function QFontInfo_font; external QtShareName name QtNamePrefix + 'QFontInfo_font';

procedure QFontMetrics_destroy; external QtShareName name QtNamePrefix + 'QFontMetrics_destroy';
function QFontMetrics_create(p1: QFontH): QFontMetricsH; external QtShareName name QtNamePrefix + 'QFontMetrics_create';
function QFontMetrics_create(p1: QFontMetricsH): QFontMetricsH; external QtShareName name QtNamePrefix + 'QFontMetrics_create2';
function QFontMetrics_ascent; external QtShareName name QtNamePrefix + 'QFontMetrics_ascent';
function QFontMetrics_descent; external QtShareName name QtNamePrefix + 'QFontMetrics_descent';
function QFontMetrics_height; external QtShareName name QtNamePrefix + 'QFontMetrics_height';
function QFontMetrics_leading; external QtShareName name QtNamePrefix + 'QFontMetrics_leading';
function QFontMetrics_lineSpacing; external QtShareName name QtNamePrefix + 'QFontMetrics_lineSpacing';
function QFontMetrics_minLeftBearing; external QtShareName name QtNamePrefix + 'QFontMetrics_minLeftBearing';
function QFontMetrics_minRightBearing; external QtShareName name QtNamePrefix + 'QFontMetrics_minRightBearing';
function QFontMetrics_maxWidth; external QtShareName name QtNamePrefix + 'QFontMetrics_maxWidth';
function QFontMetrics_inFont; external QtShareName name QtNamePrefix + 'QFontMetrics_inFont';
function QFontMetrics_leftBearing; external QtShareName name QtNamePrefix + 'QFontMetrics_leftBearing';
function QFontMetrics_rightBearing; external QtShareName name QtNamePrefix + 'QFontMetrics_rightBearing';
function QFontMetrics_width(handle: QFontMetricsH; p1: PWideString; len: Integer): Integer; external QtShareName name QtNamePrefix + 'QFontMetrics_width';
function QFontMetrics_width(handle: QFontMetricsH; p1: PWideChar): Integer; external QtShareName name QtNamePrefix + 'QFontMetrics_width2';
function QFontMetrics_width(handle: QFontMetricsH; c: char): Integer; external QtShareName name QtNamePrefix + 'QFontMetrics_width3';
procedure QFontMetrics_boundingRect(handle: QFontMetricsH; retval: PRect; p1: PWideString; len: Integer); external QtShareName name QtNamePrefix + 'QFontMetrics_boundingRect';
procedure QFontMetrics_boundingRect(handle: QFontMetricsH; retval: PRect; p1: PWideChar); external QtShareName name QtNamePrefix + 'QFontMetrics_boundingRect2';
procedure QFontMetrics_boundingRect(handle: QFontMetricsH; retval: PRect; x: Integer; y: Integer; w: Integer; h: Integer; flags: Integer; str: PWideString; len: Integer; tabstops: Integer; tabarray: PInteger; intern: PPAnsiChar); external QtShareName name QtNamePrefix + 'QFontMetrics_boundingRect3';
procedure QFontMetrics_size; external QtShareName name QtNamePrefix + 'QFontMetrics_size';
function QFontMetrics_underlinePos; external QtShareName name QtNamePrefix + 'QFontMetrics_underlinePos';
function QFontMetrics_strikeOutPos; external QtShareName name QtNamePrefix + 'QFontMetrics_strikeOutPos';
function QFontMetrics_lineWidth; external QtShareName name QtNamePrefix + 'QFontMetrics_lineWidth';

procedure QInputDialog_destroy; external QtShareName name QtNamePrefix + 'QInputDialog_destroy';
procedure QInputDialog_getText(retval: PWideString; caption: PWideString; _label: PWideString; text: PWideString; ok: PBoolean; parent: QWidgetH; name: PAnsiChar); external QtShareName name QtNamePrefix + 'QInputDialog_getText';
procedure QInputDialog_getText(retval: PWideString; caption: PWideString; _label: PWideString; echo: QLineEditEchoMode; text: PWideString; ok: PBoolean; parent: QWidgetH; name: PAnsiChar); external QtShareName name QtNamePrefix + 'QInputDialog_getText2';
function QInputDialog_getInteger; external QtShareName name QtNamePrefix + 'QInputDialog_getInteger';
function QInputDialog_getDouble; external QtShareName name QtNamePrefix + 'QInputDialog_getDouble';
procedure QInputDialog_getItem; external QtShareName name QtNamePrefix + 'QInputDialog_getItem';

procedure QIODevice_destroy; external QtShareName name QtNamePrefix + 'QIODevice_destroy';
function QIODevice_create; external QtShareName name QtNamePrefix + 'QIODevice_create';
function QIODevice_flags; external QtShareName name QtNamePrefix + 'QIODevice_flags';
function QIODevice_mode; external QtShareName name QtNamePrefix + 'QIODevice_mode';
function QIODevice_state; external QtShareName name QtNamePrefix + 'QIODevice_state';
function QIODevice_isDirectAccess; external QtShareName name QtNamePrefix + 'QIODevice_isDirectAccess';
function QIODevice_isSequentialAccess; external QtShareName name QtNamePrefix + 'QIODevice_isSequentialAccess';
function QIODevice_isCombinedAccess; external QtShareName name QtNamePrefix + 'QIODevice_isCombinedAccess';
function QIODevice_isBuffered; external QtShareName name QtNamePrefix + 'QIODevice_isBuffered';
function QIODevice_isRaw; external QtShareName name QtNamePrefix + 'QIODevice_isRaw';
function QIODevice_isSynchronous; external QtShareName name QtNamePrefix + 'QIODevice_isSynchronous';
function QIODevice_isAsynchronous; external QtShareName name QtNamePrefix + 'QIODevice_isAsynchronous';
function QIODevice_isTranslated; external QtShareName name QtNamePrefix + 'QIODevice_isTranslated';
function QIODevice_isReadable; external QtShareName name QtNamePrefix + 'QIODevice_isReadable';
function QIODevice_isWritable; external QtShareName name QtNamePrefix + 'QIODevice_isWritable';
function QIODevice_isReadWrite; external QtShareName name QtNamePrefix + 'QIODevice_isReadWrite';
function QIODevice_isInactive; external QtShareName name QtNamePrefix + 'QIODevice_isInactive';
function QIODevice_isOpen; external QtShareName name QtNamePrefix + 'QIODevice_isOpen';
function QIODevice_status; external QtShareName name QtNamePrefix + 'QIODevice_status';
procedure QIODevice_resetStatus; external QtShareName name QtNamePrefix + 'QIODevice_resetStatus';
function QIODevice_open; external QtShareName name QtNamePrefix + 'QIODevice_open';
procedure QIODevice_close; external QtShareName name QtNamePrefix + 'QIODevice_close';
procedure QIODevice_flush; external QtShareName name QtNamePrefix + 'QIODevice_flush';
function QIODevice_size; external QtShareName name QtNamePrefix + 'QIODevice_size';
function QIODevice_at(handle: QIODeviceH): Integer; external QtShareName name QtNamePrefix + 'QIODevice_at';
function QIODevice_at(handle: QIODeviceH; p1: Integer): Boolean; external QtShareName name QtNamePrefix + 'QIODevice_at2';
function QIODevice_atEnd; external QtShareName name QtNamePrefix + 'QIODevice_atEnd';
function QIODevice_reset; external QtShareName name QtNamePrefix + 'QIODevice_reset';
function QIODevice_readBlock; external QtShareName name QtNamePrefix + 'QIODevice_readBlock';
function QIODevice_writeBlock(handle: QIODeviceH; data: PAnsiChar; len: Cardinal): Integer; external QtShareName name QtNamePrefix + 'QIODevice_writeBlock';
function QIODevice_readLine; external QtShareName name QtNamePrefix + 'QIODevice_readLine';
function QIODevice_writeBlock(handle: QIODeviceH; data: QByteArrayH): Integer; external QtShareName name QtNamePrefix + 'QIODevice_writeBlock2';
procedure QIODevice_readAll; external QtShareName name QtNamePrefix + 'QIODevice_readAll';
function QIODevice_getch; external QtShareName name QtNamePrefix + 'QIODevice_getch';
function QIODevice_putch; external QtShareName name QtNamePrefix + 'QIODevice_putch';
function QIODevice_ungetch; external QtShareName name QtNamePrefix + 'QIODevice_ungetch';

procedure QMenuItem_destroy; external QtShareName name QtNamePrefix + 'QMenuItem_destroy';
function QMenuItem_create; external QtShareName name QtNamePrefix + 'QMenuItem_create';
function QMenuItem_id; external QtShareName name QtNamePrefix + 'QMenuItem_id';
function QMenuItem_iconSet; external QtShareName name QtNamePrefix + 'QMenuItem_iconSet';
procedure QMenuItem_text; external QtShareName name QtNamePrefix + 'QMenuItem_text';
procedure QMenuItem_whatsThis; external QtShareName name QtNamePrefix + 'QMenuItem_whatsThis';
function QMenuItem_pixmap; external QtShareName name QtNamePrefix + 'QMenuItem_pixmap';
function QMenuItem_popup; external QtShareName name QtNamePrefix + 'QMenuItem_popup';
function QMenuItem_widget; external QtShareName name QtNamePrefix + 'QMenuItem_widget';
function QMenuItem_custom; external QtShareName name QtNamePrefix + 'QMenuItem_custom';
function QMenuItem_key; external QtShareName name QtNamePrefix + 'QMenuItem_key';
function QMenuItem_signal; external QtShareName name QtNamePrefix + 'QMenuItem_signal';
function QMenuItem_isSeparator; external QtShareName name QtNamePrefix + 'QMenuItem_isSeparator';
function QMenuItem_isEnabled; external QtShareName name QtNamePrefix + 'QMenuItem_isEnabled';
function QMenuItem_isChecked; external QtShareName name QtNamePrefix + 'QMenuItem_isChecked';
function QMenuItem_isDirty; external QtShareName name QtNamePrefix + 'QMenuItem_isDirty';
procedure QMenuItem_setText; external QtShareName name QtNamePrefix + 'QMenuItem_setText';
procedure QMenuItem_setDirty; external QtShareName name QtNamePrefix + 'QMenuItem_setDirty';
procedure QMenuItem_setWhatsThis; external QtShareName name QtNamePrefix + 'QMenuItem_setWhatsThis';

procedure QCustomMenuItem_destroy; external QtShareName name QtNamePrefix + 'QCustomMenuItem_destroy';
function QCustomMenuItem_create; external QtShareName name QtNamePrefix + 'QCustomMenuItem_create';
function QCustomMenuItem_fullSpan; external QtShareName name QtNamePrefix + 'QCustomMenuItem_fullSpan';
function QCustomMenuItem_isSeparator; external QtShareName name QtNamePrefix + 'QCustomMenuItem_isSeparator';
procedure QCustomMenuItem_setFont; external QtShareName name QtNamePrefix + 'QCustomMenuItem_setFont';
procedure QCustomMenuItem_paint; external QtShareName name QtNamePrefix + 'QCustomMenuItem_paint';
procedure QCustomMenuItem_sizeHint; external QtShareName name QtNamePrefix + 'QCustomMenuItem_sizeHint';

procedure QMenuData_destroy; external QtShareName name QtNamePrefix + 'QMenuData_destroy';
function QMenuData_create; external QtShareName name QtNamePrefix + 'QMenuData_create';
function QMenuData_count; external QtShareName name QtNamePrefix + 'QMenuData_count';
function QMenuData_insertItem(handle: QMenuDataH; text: PWideString; receiver: QObjectH; member: PAnsiChar; accel: Integer; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem';
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; text: PWideString; receiver: QObjectH; member: PAnsiChar; accel: Integer; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem2';
function QMenuData_insertItem(handle: QMenuDataH; pixmap: QPixmapH; receiver: QObjectH; member: PAnsiChar; accel: Integer; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem3';
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; pixmap: QPixmapH; receiver: QObjectH; member: PAnsiChar; accel: Integer; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem4';
function QMenuData_insertItem(handle: QMenuDataH; text: PWideString; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem5';
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; text: PWideString; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem6';
function QMenuData_insertItem(handle: QMenuDataH; text: PWideString; popup: QPopupMenuH; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem7';
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; text: PWideString; popup: QPopupMenuH; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem8';
function QMenuData_insertItem(handle: QMenuDataH; pixmap: QPixmapH; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem9';
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; pixmap: QPixmapH; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem10';
function QMenuData_insertItem(handle: QMenuDataH; pixmap: QPixmapH; popup: QPopupMenuH; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem11';
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; pixmap: QPixmapH; popup: QPopupMenuH; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem12';
function QMenuData_insertItem(handle: QMenuDataH; widget: QWidgetH; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem13';
function QMenuData_insertItem(handle: QMenuDataH; icon: QIconSetH; custom: QCustomMenuItemH; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem14';
function QMenuData_insertItem(handle: QMenuDataH; custom: QCustomMenuItemH; id: Integer; index: Integer): Integer; external QtShareName name QtNamePrefix + 'QMenuData_insertItem15';
function QMenuData_insertSeparator; external QtShareName name QtNamePrefix + 'QMenuData_insertSeparator';
procedure QMenuData_removeItem; external QtShareName name QtNamePrefix + 'QMenuData_removeItem';
procedure QMenuData_removeItemAt; external QtShareName name QtNamePrefix + 'QMenuData_removeItemAt';
procedure QMenuData_clear; external QtShareName name QtNamePrefix + 'QMenuData_clear';
function QMenuData_accel; external QtShareName name QtNamePrefix + 'QMenuData_accel';
procedure QMenuData_setAccel; external QtShareName name QtNamePrefix + 'QMenuData_setAccel';
function QMenuData_iconSet; external QtShareName name QtNamePrefix + 'QMenuData_iconSet';
procedure QMenuData_text; external QtShareName name QtNamePrefix + 'QMenuData_text';
function QMenuData_pixmap; external QtShareName name QtNamePrefix + 'QMenuData_pixmap';
procedure QMenuData_setWhatsThis; external QtShareName name QtNamePrefix + 'QMenuData_setWhatsThis';
procedure QMenuData_whatsThis; external QtShareName name QtNamePrefix + 'QMenuData_whatsThis';
procedure QMenuData_changeItem(handle: QMenuDataH; id: Integer; text: PWideString); external QtShareName name QtNamePrefix + 'QMenuData_changeItem';
procedure QMenuData_changeItem(handle: QMenuDataH; id: Integer; pixmap: QPixmapH); external QtShareName name QtNamePrefix + 'QMenuData_changeItem2';
procedure QMenuData_changeItem(handle: QMenuDataH; id: Integer; icon: QIconSetH; text: PWideString); external QtShareName name QtNamePrefix + 'QMenuData_changeItem3';
procedure QMenuData_changeItem(handle: QMenuDataH; id: Integer; icon: QIconSetH; pixmap: QPixmapH); external QtShareName name QtNamePrefix + 'QMenuData_changeItem4';
procedure QMenuData_changeItem(handle: QMenuDataH; text: PWideString; id: Integer); external QtShareName name QtNamePrefix + 'QMenuData_changeItem5';
procedure QMenuData_changeItem(handle: QMenuDataH; pixmap: QPixmapH; id: Integer); external QtShareName name QtNamePrefix + 'QMenuData_changeItem6';
procedure QMenuData_changeItem(handle: QMenuDataH; icon: QIconSetH; text: PWideString; id: Integer); external QtShareName name QtNamePrefix + 'QMenuData_changeItem7';
function QMenuData_isItemEnabled; external QtShareName name QtNamePrefix + 'QMenuData_isItemEnabled';
procedure QMenuData_setItemEnabled; external QtShareName name QtNamePrefix + 'QMenuData_setItemEnabled';
function QMenuData_isItemChecked; external QtShareName name QtNamePrefix + 'QMenuData_isItemChecked';
procedure QMenuData_setItemChecked; external QtShareName name QtNamePrefix + 'QMenuData_setItemChecked';
procedure QMenuData_updateItem; external QtShareName name QtNamePrefix + 'QMenuData_updateItem';
function QMenuData_indexOf; external QtShareName name QtNamePrefix + 'QMenuData_indexOf';
function QMenuData_idAt; external QtShareName name QtNamePrefix + 'QMenuData_idAt';
procedure QMenuData_setId; external QtShareName name QtNamePrefix + 'QMenuData_setId';
function QMenuData_connectItem; external QtShareName name QtNamePrefix + 'QMenuData_connectItem';
function QMenuData_disconnectItem; external QtShareName name QtNamePrefix + 'QMenuData_disconnectItem';
function QMenuData_setItemParameter; external QtShareName name QtNamePrefix + 'QMenuData_setItemParameter';
function QMenuData_itemParameter; external QtShareName name QtNamePrefix + 'QMenuData_itemParameter';
function QMenuData_findItem(handle: QMenuDataH; id: Integer): QMenuItemH; external QtShareName name QtNamePrefix + 'QMenuData_findItem';
function QMenuData_findItem(handle: QMenuDataH; id: Integer; parent: QMenuDataHH): QMenuItemH; external QtShareName name QtNamePrefix + 'QMenuData_findItem2';
procedure QMenuData_activateItemAt; external QtShareName name QtNamePrefix + 'QMenuData_activateItemAt';

procedure QMimeSource_destroy; external QtShareName name QtNamePrefix + 'QMimeSource_destroy';
function QMimeSource_format; external QtShareName name QtNamePrefix + 'QMimeSource_format';
function QMimeSource_provides; external QtShareName name QtNamePrefix + 'QMimeSource_provides';
procedure QMimeSource_encodedData; external QtShareName name QtNamePrefix + 'QMimeSource_encodedData';

procedure QMimeSourceFactory_destroy; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_destroy';
function QMimeSourceFactory_create; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_create';
function QMimeSourceFactory_defaultFactory; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_defaultFactory';
procedure QMimeSourceFactory_setDefaultFactory; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_setDefaultFactory';
function QMimeSourceFactory_data(handle: QMimeSourceFactoryH; abs_name: PWideString): QMimeSourceH; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_data';
procedure QMimeSourceFactory_makeAbsolute; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_makeAbsolute';
function QMimeSourceFactory_data(handle: QMimeSourceFactoryH; abs_or_rel_name: PWideString; context: PWideString): QMimeSourceH; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_data2';
procedure QMimeSourceFactory_setText; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_setText';
procedure QMimeSourceFactory_setImage; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_setImage';
procedure QMimeSourceFactory_setPixmap; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_setPixmap';
procedure QMimeSourceFactory_setData; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_setData';
procedure QMimeSourceFactory_setFilePath; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_setFilePath';
procedure QMimeSourceFactory_filePath; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_filePath';
procedure QMimeSourceFactory_addFilePath; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_addFilePath';
procedure QMimeSourceFactory_setExtensionType; external QtShareName name QtNamePrefix + 'QMimeSourceFactory_setExtensionType';

function QWindowsMime_registerMimeType; external QtShareName name QtNamePrefix + 'QWindowsMime_registerMimeType';

procedure QPaintDeviceMetrics_destroy; external QtShareName name QtNamePrefix + 'QPaintDeviceMetrics_destroy';
function QPaintDeviceMetrics_create; external QtShareName name QtNamePrefix + 'QPaintDeviceMetrics_create';
function QPaintDeviceMetrics_width; external QtShareName name QtNamePrefix + 'QPaintDeviceMetrics_width';
function QPaintDeviceMetrics_height; external QtShareName name QtNamePrefix + 'QPaintDeviceMetrics_height';
function QPaintDeviceMetrics_widthMM; external QtShareName name QtNamePrefix + 'QPaintDeviceMetrics_widthMM';
function QPaintDeviceMetrics_heightMM; external QtShareName name QtNamePrefix + 'QPaintDeviceMetrics_heightMM';
function QPaintDeviceMetrics_logicalDpiX; external QtShareName name QtNamePrefix + 'QPaintDeviceMetrics_logicalDpiX';
function QPaintDeviceMetrics_logicalDpiY; external QtShareName name QtNamePrefix + 'QPaintDeviceMetrics_logicalDpiY';
function QPaintDeviceMetrics_numColors; external QtShareName name QtNamePrefix + 'QPaintDeviceMetrics_numColors';
function QPaintDeviceMetrics_depth; external QtShareName name QtNamePrefix + 'QPaintDeviceMetrics_depth';

procedure QPicture_destroy; external QtShareName name QtNamePrefix + 'QPicture_destroy';
function QPicture_create; external QtShareName name QtNamePrefix + 'QPicture_create';
function QPicture_isNull; external QtShareName name QtNamePrefix + 'QPicture_isNull';
function QPicture_size; external QtShareName name QtNamePrefix + 'QPicture_size';
function QPicture_data; external QtShareName name QtNamePrefix + 'QPicture_data';
procedure QPicture_setData; external QtShareName name QtNamePrefix + 'QPicture_setData';
function QPicture_play; external QtShareName name QtNamePrefix + 'QPicture_play';
function QPicture_load; external QtShareName name QtNamePrefix + 'QPicture_load';
function QPicture_save; external QtShareName name QtNamePrefix + 'QPicture_save';

procedure QPixmapCache_destroy; external QtShareName name QtNamePrefix + 'QPixmapCache_destroy';
function QPixmapCache_cacheLimit; external QtShareName name QtNamePrefix + 'QPixmapCache_cacheLimit';
procedure QPixmapCache_setCacheLimit; external QtShareName name QtNamePrefix + 'QPixmapCache_setCacheLimit';
function QPixmapCache_find(key: PWideString): QPixmapH; external QtShareName name QtNamePrefix + 'QPixmapCache_find';
function QPixmapCache_find(key: PWideString; p2: QPixmapH): Boolean; external QtShareName name QtNamePrefix + 'QPixmapCache_find2';
function QPixmapCache_insert(key: PWideString; p2: QPixmapH): Boolean; external QtShareName name QtNamePrefix + 'QPixmapCache_insert';

procedure QPixmapCache_clear; external QtShareName name QtNamePrefix + 'QPixmapCache_clear';

procedure QPoint_destroy; external QtShareName name QtNamePrefix + 'QPoint_destroy';
function QPoint_create(): QPointH; external QtShareName name QtNamePrefix + 'QPoint_create';
function QPoint_create(xpos: Integer; ypos: Integer): QPointH; external QtShareName name QtNamePrefix + 'QPoint_create2';
function QPoint_isNull; external QtShareName name QtNamePrefix + 'QPoint_isNull';
function QPoint_x; external QtShareName name QtNamePrefix + 'QPoint_x';
function QPoint_y; external QtShareName name QtNamePrefix + 'QPoint_y';
procedure QPoint_setX; external QtShareName name QtNamePrefix + 'QPoint_setX';
procedure QPoint_setY; external QtShareName name QtNamePrefix + 'QPoint_setY';
function QPoint_manhattanLength; external QtShareName name QtNamePrefix + 'QPoint_manhattanLength';
function QPoint_rx; external QtShareName name QtNamePrefix + 'QPoint_rx';
function QPoint_ry; external QtShareName name QtNamePrefix + 'QPoint_ry';

procedure QRangeControl_destroy; external QtShareName name QtNamePrefix + 'QRangeControl_destroy';
function QRangeControl_create(): QRangeControlH; external QtShareName name QtNamePrefix + 'QRangeControl_create';
function QRangeControl_create(minValue: Integer; maxValue: Integer; lineStep: Integer; pageStep: Integer; value: Integer): QRangeControlH; external QtShareName name QtNamePrefix + 'QRangeControl_create2';
function QRangeControl_value; external QtShareName name QtNamePrefix + 'QRangeControl_value';
procedure QRangeControl_setValue; external QtShareName name QtNamePrefix + 'QRangeControl_setValue';
procedure QRangeControl_addPage; external QtShareName name QtNamePrefix + 'QRangeControl_addPage';
procedure QRangeControl_subtractPage; external QtShareName name QtNamePrefix + 'QRangeControl_subtractPage';
procedure QRangeControl_addLine; external QtShareName name QtNamePrefix + 'QRangeControl_addLine';
procedure QRangeControl_subtractLine; external QtShareName name QtNamePrefix + 'QRangeControl_subtractLine';
function QRangeControl_minValue; external QtShareName name QtNamePrefix + 'QRangeControl_minValue';
function QRangeControl_maxValue; external QtShareName name QtNamePrefix + 'QRangeControl_maxValue';
procedure QRangeControl_setRange; external QtShareName name QtNamePrefix + 'QRangeControl_setRange';
function QRangeControl_lineStep; external QtShareName name QtNamePrefix + 'QRangeControl_lineStep';
function QRangeControl_pageStep; external QtShareName name QtNamePrefix + 'QRangeControl_pageStep';
procedure QRangeControl_setSteps; external QtShareName name QtNamePrefix + 'QRangeControl_setSteps';
function QRangeControl_bound; external QtShareName name QtNamePrefix + 'QRangeControl_bound';

procedure QRect_destroy; external QtShareName name QtNamePrefix + 'QRect_destroy';
function QRect_create(): QRectH; external QtShareName name QtNamePrefix + 'QRect_create';
function QRect_create(topleft: PPoint; bottomright: PPoint): QRectH; external QtShareName name QtNamePrefix + 'QRect_create2';
function QRect_create(topleft: PPoint; size: PSize): QRectH; external QtShareName name QtNamePrefix + 'QRect_create3';
function QRect_create(left: Integer; top: Integer; width: Integer; height: Integer): QRectH; external QtShareName name QtNamePrefix + 'QRect_create4';
function QRect_isNull; external QtShareName name QtNamePrefix + 'QRect_isNull';
function QRect_isEmpty; external QtShareName name QtNamePrefix + 'QRect_isEmpty';
function QRect_isValid; external QtShareName name QtNamePrefix + 'QRect_isValid';
procedure QRect_normalize; external QtShareName name QtNamePrefix + 'QRect_normalize';
function QRect_left; external QtShareName name QtNamePrefix + 'QRect_left';
function QRect_top; external QtShareName name QtNamePrefix + 'QRect_top';
function QRect_right; external QtShareName name QtNamePrefix + 'QRect_right';
function QRect_bottom; external QtShareName name QtNamePrefix + 'QRect_bottom';
function QRect_rLeft; external QtShareName name QtNamePrefix + 'QRect_rLeft';
function QRect_rTop; external QtShareName name QtNamePrefix + 'QRect_rTop';
function QRect_rRight; external QtShareName name QtNamePrefix + 'QRect_rRight';
function QRect_rBottom; external QtShareName name QtNamePrefix + 'QRect_rBottom';
function QRect_x; external QtShareName name QtNamePrefix + 'QRect_x';
function QRect_y; external QtShareName name QtNamePrefix + 'QRect_y';
procedure QRect_setLeft; external QtShareName name QtNamePrefix + 'QRect_setLeft';
procedure QRect_setTop; external QtShareName name QtNamePrefix + 'QRect_setTop';
procedure QRect_setRight; external QtShareName name QtNamePrefix + 'QRect_setRight';
procedure QRect_setBottom; external QtShareName name QtNamePrefix + 'QRect_setBottom';
procedure QRect_setX; external QtShareName name QtNamePrefix + 'QRect_setX';
procedure QRect_setY; external QtShareName name QtNamePrefix + 'QRect_setY';
procedure QRect_topLeft; external QtShareName name QtNamePrefix + 'QRect_topLeft';
procedure QRect_bottomRight; external QtShareName name QtNamePrefix + 'QRect_bottomRight';
procedure QRect_topRight; external QtShareName name QtNamePrefix + 'QRect_topRight';
procedure QRect_bottomLeft; external QtShareName name QtNamePrefix + 'QRect_bottomLeft';
procedure QRect_center; external QtShareName name QtNamePrefix + 'QRect_center';
procedure QRect_rect; external QtShareName name QtNamePrefix + 'QRect_rect';
procedure QRect_coords; external QtShareName name QtNamePrefix + 'QRect_coords';
procedure QRect_moveTopLeft; external QtShareName name QtNamePrefix + 'QRect_moveTopLeft';
procedure QRect_moveBottomRight; external QtShareName name QtNamePrefix + 'QRect_moveBottomRight';
procedure QRect_moveTopRight; external QtShareName name QtNamePrefix + 'QRect_moveTopRight';
procedure QRect_moveBottomLeft; external QtShareName name QtNamePrefix + 'QRect_moveBottomLeft';
procedure QRect_moveCenter; external QtShareName name QtNamePrefix + 'QRect_moveCenter';
procedure QRect_moveBy; external QtShareName name QtNamePrefix + 'QRect_moveBy';
procedure QRect_setRect; external QtShareName name QtNamePrefix + 'QRect_setRect';
procedure QRect_setCoords; external QtShareName name QtNamePrefix + 'QRect_setCoords';
procedure QRect_size; external QtShareName name QtNamePrefix + 'QRect_size';
function QRect_width; external QtShareName name QtNamePrefix + 'QRect_width';
function QRect_height; external QtShareName name QtNamePrefix + 'QRect_height';
procedure QRect_setWidth; external QtShareName name QtNamePrefix + 'QRect_setWidth';
procedure QRect_setHeight; external QtShareName name QtNamePrefix + 'QRect_setHeight';
procedure QRect_setSize; external QtShareName name QtNamePrefix + 'QRect_setSize';
function QRect_contains(handle: QRectH; p: PPoint; proper: Boolean): Boolean; external QtShareName name QtNamePrefix + 'QRect_contains';
function QRect_contains(handle: QRectH; x: Integer; y: Integer; proper: Boolean): Boolean; external QtShareName name QtNamePrefix + 'QRect_contains2';
function QRect_contains(handle: QRectH; r: PRect; proper: Boolean): Boolean; external QtShareName name QtNamePrefix + 'QRect_contains3';
procedure QRect_unite; external QtShareName name QtNamePrefix + 'QRect_unite';
procedure QRect_intersect; external QtShareName name QtNamePrefix + 'QRect_intersect';
function QRect_intersects; external QtShareName name QtNamePrefix + 'QRect_intersects';

procedure QSize_destroy; external QtShareName name QtNamePrefix + 'QSize_destroy';
function QSize_create(): QSizeH; external QtShareName name QtNamePrefix + 'QSize_create';
function QSize_create(w: Integer; h: Integer): QSizeH; external QtShareName name QtNamePrefix + 'QSize_create2';
function QSize_isNull; external QtShareName name QtNamePrefix + 'QSize_isNull';
function QSize_isEmpty; external QtShareName name QtNamePrefix + 'QSize_isEmpty';
function QSize_isValid; external QtShareName name QtNamePrefix + 'QSize_isValid';
function QSize_width; external QtShareName name QtNamePrefix + 'QSize_width';
function QSize_height; external QtShareName name QtNamePrefix + 'QSize_height';
procedure QSize_setWidth; external QtShareName name QtNamePrefix + 'QSize_setWidth';
procedure QSize_setHeight; external QtShareName name QtNamePrefix + 'QSize_setHeight';
procedure QSize_transpose; external QtShareName name QtNamePrefix + 'QSize_transpose';
procedure QSize_expandedTo; external QtShareName name QtNamePrefix + 'QSize_expandedTo';
procedure QSize_boundedTo; external QtShareName name QtNamePrefix + 'QSize_boundedTo';
function QSize_rwidth; external QtShareName name QtNamePrefix + 'QSize_rwidth';
function QSize_rheight; external QtShareName name QtNamePrefix + 'QSize_rheight';

procedure QStringList_destroy; external QtShareName name QtNamePrefix + 'QStringList_destroy';
function QStringList_create(): QStringListH; external QtShareName name QtNamePrefix + 'QStringList_create';
function QStringList_create(l: QStringListH): QStringListH; external QtShareName name QtNamePrefix + 'QStringList_create2';

function QStringList_create(i: PWideString): QStringListH; external QtShareName name QtNamePrefix + 'QStringList_create4';
function QStringList_create(i: PAnsiChar): QStringListH; external QtShareName name QtNamePrefix + 'QStringList_create5';
procedure QStringList_fromStrList; external QtShareName name QtNamePrefix + 'QStringList_fromStrList';
procedure QStringList_sort; external QtShareName name QtNamePrefix + 'QStringList_sort';
procedure QStringList_split(retval: QStringListH; sep: PWideString; str: PWideString; allowEmptyEntries: Boolean); external QtShareName name QtNamePrefix + 'QStringList_split';
procedure QStringList_split(retval: QStringListH; sep: PWideChar; str: PWideString; allowEmptyEntries: Boolean); external QtShareName name QtNamePrefix + 'QStringList_split2';
procedure QStringList_split(retval: QStringListH; sep: QRegExpH; str: PWideString; allowEmptyEntries: Boolean); external QtShareName name QtNamePrefix + 'QStringList_split3';
procedure QStringList_join; external QtShareName name QtNamePrefix + 'QStringList_join';
procedure QStringList_grep(handle: QStringListH; retval: QStringListH; str: PWideString; cs: Boolean); external QtShareName name QtNamePrefix + 'QStringList_grep';
procedure QStringList_grep(handle: QStringListH; retval: QStringListH; expr: QRegExpH); external QtShareName name QtNamePrefix + 'QStringList_grep2';

procedure QWMatrix_destroy; external QtShareName name QtNamePrefix + 'QWMatrix_destroy';
function QWMatrix_create(): QWMatrixH; external QtShareName name QtNamePrefix + 'QWMatrix_create';
function QWMatrix_create(m11: Double; m12: Double; m21: Double; m22: Double; dx: Double; dy: Double): QWMatrixH; external QtShareName name QtNamePrefix + 'QWMatrix_create2';
procedure QWMatrix_setMatrix; external QtShareName name QtNamePrefix + 'QWMatrix_setMatrix';
function QWMatrix_m11; external QtShareName name QtNamePrefix + 'QWMatrix_m11';
function QWMatrix_m12; external QtShareName name QtNamePrefix + 'QWMatrix_m12';
function QWMatrix_m21; external QtShareName name QtNamePrefix + 'QWMatrix_m21';
function QWMatrix_m22; external QtShareName name QtNamePrefix + 'QWMatrix_m22';
function QWMatrix_dx; external QtShareName name QtNamePrefix + 'QWMatrix_dx';
function QWMatrix_dy; external QtShareName name QtNamePrefix + 'QWMatrix_dy';
procedure QWMatrix_map(handle: QWMatrixH; x: Integer; y: Integer; tx: PInteger; ty: PInteger); external QtShareName name QtNamePrefix + 'QWMatrix_map';
procedure QWMatrix_map(handle: QWMatrixH; x: Double; y: Double; tx: PDouble; ty: PDouble); external QtShareName name QtNamePrefix + 'QWMatrix_map2';
procedure QWMatrix_map(handle: QWMatrixH; retval: PPoint; p1: PPoint); external QtShareName name QtNamePrefix + 'QWMatrix_map3';
procedure QWMatrix_map(handle: QWMatrixH; retval: PRect; p1: PRect); external QtShareName name QtNamePrefix + 'QWMatrix_map4';
procedure QWMatrix_map(handle: QWMatrixH; retval: PPointArray; p1: PPointArray); external QtShareName name QtNamePrefix + 'QWMatrix_map5';
procedure QWMatrix_reset; external QtShareName name QtNamePrefix + 'QWMatrix_reset';
function QWMatrix_translate; external QtShareName name QtNamePrefix + 'QWMatrix_translate';
function QWMatrix_scale; external QtShareName name QtNamePrefix + 'QWMatrix_scale';
function QWMatrix_shear; external QtShareName name QtNamePrefix + 'QWMatrix_shear';
function QWMatrix_rotate; external QtShareName name QtNamePrefix + 'QWMatrix_rotate';
procedure QWMatrix_invert; external QtShareName name QtNamePrefix + 'QWMatrix_invert';

procedure QClxObjectMap_destroy; external QtShareName name QtNamePrefix + 'QClxObjectMap_destroy';
procedure QClxObjectMap_setAddCallback; external QtShareName name QtNamePrefix + 'QClxObjectMap_setAddCallback';
procedure QClxObjectMap_setRemoveCallback; external QtShareName name QtNamePrefix + 'QClxObjectMap_setRemoveCallback';
procedure QClxObjectMap_add; external QtShareName name QtNamePrefix + 'QClxObjectMap_add';
procedure QClxObjectMap_remove; external QtShareName name QtNamePrefix + 'QClxObjectMap_remove';
function QClxObjectMap_find; external QtShareName name QtNamePrefix + 'QClxObjectMap_find';
function QClxObjectMap_findClxObject; external QtShareName name QtNamePrefix + 'QClxObjectMap_findClxObject';

procedure QClxIODevice_destroy; external QtShareName name QtNamePrefix + 'QClxIODevice_destroy';
function QClxIODevice_create; external QtShareName name QtNamePrefix + 'QClxIODevice_create';

procedure QClxLineEdit_destroy; external QtShareName name QtNamePrefix + 'QClxLineEdit_destroy';
function QClxLineEdit_create; external QtShareName name QtNamePrefix + 'QClxLineEdit_create';
function QClxLineEdit_autoSelect; external QtShareName name QtNamePrefix + 'QClxLineEdit_autoSelect';
procedure QClxLineEdit_setAutoSelect; external QtShareName name QtNamePrefix + 'QClxLineEdit_setAutoSelect';
function QClxLineEdit_hideSelection; external QtShareName name QtNamePrefix + 'QClxLineEdit_hideSelection';
procedure QClxLineEdit_setHideSelection; external QtShareName name QtNamePrefix + 'QClxLineEdit_setHideSelection';
procedure QClxLineEdit_clearSelection; external QtShareName name QtNamePrefix + 'QClxLineEdit_clearSelection';
procedure QClxLineEdit_resetSelection; external QtShareName name QtNamePrefix + 'QClxLineEdit_resetSelection';
function QClxLineEdit_selStart; external QtShareName name QtNamePrefix + 'QClxLineEdit_selStart';
procedure QClxLineEdit_setSelStart; external QtShareName name QtNamePrefix + 'QClxLineEdit_setSelStart';
procedure QClxLineEdit_updateSelection; external QtShareName name QtNamePrefix + 'QClxLineEdit_updateSelection';
procedure QClxLineEdit_setSelection; external QtShareName name QtNamePrefix + 'QClxLineEdit_setSelection';
function QClxLineEdit_selLen; external QtShareName name QtNamePrefix + 'QClxLineEdit_selLen';
procedure QClxLineEdit_setMarkedText; external QtShareName name QtNamePrefix + 'QClxLineEdit_setMarkedText';
function QClxLineEdit_hasMarkedText; external QtShareName name QtNamePrefix + 'QClxLineEdit_hasMarkedText';
procedure QClxLineEdit_markedText; external QtShareName name QtNamePrefix + 'QClxLineEdit_markedText';

procedure QOpenWidget_destroy; external QtShareName name QtNamePrefix + 'QOpenWidget_destroy';
function QOpenWidget_event; external QtShareName name QtNamePrefix + 'QOpenWidget_event';
procedure QOpenWidget_mousePressEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_mousePressEvent';
procedure QOpenWidget_mouseReleaseEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_mouseReleaseEvent';
procedure QOpenWidget_mouseDoubleClickEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_mouseDoubleClickEvent';
procedure QOpenWidget_mouseMoveEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_mouseMoveEvent';
procedure QOpenWidget_wheelEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_wheelEvent';
procedure QOpenWidget_keyPressEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_keyPressEvent';
procedure QOpenWidget_keyReleaseEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_keyReleaseEvent';
procedure QOpenWidget_focusInEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_focusInEvent';
procedure QOpenWidget_focusOutEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_focusOutEvent';
procedure QOpenWidget_enterEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_enterEvent';
procedure QOpenWidget_leaveEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_leaveEvent';
procedure QOpenWidget_paintEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_paintEvent';
procedure QOpenWidget_moveEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_moveEvent';
procedure QOpenWidget_resizeEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_resizeEvent';
procedure QOpenWidget_closeEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_closeEvent';
procedure QOpenWidget_dragEnterEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_dragEnterEvent';
procedure QOpenWidget_dragMoveEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_dragMoveEvent';
procedure QOpenWidget_dragLeaveEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_dragLeaveEvent';
procedure QOpenWidget_dropEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_dropEvent';
procedure QOpenWidget_showEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_showEvent';
procedure QOpenWidget_hideEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_hideEvent';
procedure QOpenWidget_customEvent; external QtShareName name QtNamePrefix + 'QOpenWidget_customEvent';
function QOpenWidget_getWState; external QtShareName name QtNamePrefix + 'QOpenWidget_getWState';
procedure QOpenWidget_setWState; external QtShareName name QtNamePrefix + 'QOpenWidget_setWState';
procedure QOpenWidget_clearWState; external QtShareName name QtNamePrefix + 'QOpenWidget_clearWState';
function QOpenWidget_getWFlags; external QtShareName name QtNamePrefix + 'QOpenWidget_getWFlags';
procedure QOpenWidget_setWFlags; external QtShareName name QtNamePrefix + 'QOpenWidget_setWFlags';
procedure QOpenWidget_clearWFlags; external QtShareName name QtNamePrefix + 'QOpenWidget_clearWFlags';
function QOpenWidget_focusNextPrevChild; external QtShareName name QtNamePrefix + 'QOpenWidget_focusNextPrevChild';
procedure QOpenWidget_updateMask; external QtShareName name QtNamePrefix + 'QOpenWidget_updateMask';

procedure QOpenStringList_destroy; external QtShareName name QtNamePrefix + 'QOpenStringList_destroy';
function QOpenStringList_count; external QtShareName name QtNamePrefix + 'QOpenStringList_count';
procedure QOpenStringList_value; external QtShareName name QtNamePrefix + 'QOpenStringList_value';
procedure QOpenStringList_append; external QtShareName name QtNamePrefix + 'QOpenStringList_append';

procedure QClxDrawUtil_destroy; external QtShareName name QtNamePrefix + 'QClxDrawUtil_destroy';
procedure QClxDrawUtil_DrawItem; external QtShareName name QtNamePrefix + 'QClxDrawUtil_DrawItem';
procedure QClxDrawUtil_DrawShadeLine(p: QPainterH; x1: Integer; y1: Integer; x2: Integer; y2: Integer; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; midLineWidth: Integer); external QtShareName name QtNamePrefix + 'QClxDrawUtil_DrawShadeLine';
procedure QClxDrawUtil_DrawShadeLine(p: QPainterH; p1: PPoint; p2: PPoint; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; midLineWidth: Integer); external QtShareName name QtNamePrefix + 'QClxDrawUtil_DrawShadeLine2';
procedure QClxDrawUtil_DrawShadeRect(p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; midLineWidth: Integer; fill: QBrushH); external QtShareName name QtNamePrefix + 'QClxDrawUtil_DrawShadeRect';
procedure QClxDrawUtil_DrawShadeRect(p: QPainterH; r: PRect; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; midLineWidth: Integer; fill: QBrushH); external QtShareName name QtNamePrefix + 'QClxDrawUtil_DrawShadeRect2';
procedure QClxDrawUtil_DrawShadePanel(p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; fill: QBrushH); external QtShareName name QtNamePrefix + 'QClxDrawUtil_DrawShadePanel';
procedure QClxDrawUtil_DrawShadePanel(p: QPainterH; r: PRect; g: QColorGroupH; sunken: Boolean; lineWidth: Integer; fill: QBrushH); external QtShareName name QtNamePrefix + 'QClxDrawUtil_DrawShadePanel2';
procedure QClxDrawUtil_DrawWinButton(p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH); external QtShareName name QtNamePrefix + 'QClxDrawUtil_DrawWinButton';
procedure QClxDrawUtil_DrawWinButton(p: QPainterH; r: PRect; g: QColorGroupH; sunken: Boolean; fill: QBrushH); external QtShareName name QtNamePrefix + 'QClxDrawUtil_DrawWinButton2';
procedure QClxDrawUtil_DrawWinPanel(p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; g: QColorGroupH; sunken: Boolean; fill: QBrushH); external QtShareName name QtNamePrefix + 'QClxDrawUtil_DrawWinPanel';
procedure QClxDrawUtil_DrawWinPanel(p: QPainterH; r: PRect; g: QColorGroupH; sunken: Boolean; fill: QBrushH); external QtShareName name QtNamePrefix + 'QClxDrawUtil_DrawWinPanel2';
procedure QClxDrawUtil_DrawPlainRect(p: QPainterH; x: Integer; y: Integer; w: Integer; h: Integer; c: QColorH; lineWidth: Integer; fill: QBrushH); external QtShareName name QtNamePrefix + 'QClxDrawUtil_DrawPlainRect';
procedure QClxDrawUtil_DrawPlainRect(p: QPainterH; r: PRect; c: QColorH; lineWidth: Integer; fill: QBrushH); external QtShareName name QtNamePrefix + 'QClxDrawUtil_DrawPlainRect2';

procedure QClxListBoxHooks_destroy; external QtShareName name QtNamePrefix + 'QClxListBoxHooks_destroy';
function QClxListBoxHooks_create; external QtShareName name QtNamePrefix + 'QClxListBoxHooks_create';
procedure QClxListBoxHooks_hook_paint; external QtShareName name QtNamePrefix + 'QClxListBoxHooks_hook_paint';
procedure QClxListBoxHooks_hook_measure; external QtShareName name QtNamePrefix + 'QClxListBoxHooks_hook_measure';

procedure QClxListBoxItem_destroy; external QtShareName name QtNamePrefix + 'QClxListBoxItem_destroy';
function QClxListBoxItem_create; external QtShareName name QtNamePrefix + 'QClxListBoxItem_create';
function QClxListBoxItem_width; external QtShareName name QtNamePrefix + 'QClxListBoxItem_width';
function QClxListBoxItem_height; external QtShareName name QtNamePrefix + 'QClxListBoxItem_height';
function QClxListBoxItem_getData; external QtShareName name QtNamePrefix + 'QClxListBoxItem_getData';
procedure QClxListBoxItem_setData; external QtShareName name QtNamePrefix + 'QClxListBoxItem_setData';
procedure QClxListBoxItem_setCustomHighlighting; external QtShareName name QtNamePrefix + 'QClxListBoxItem_setCustomHighlighting';

procedure QClxListViewHooks_destroy; external QtShareName name QtNamePrefix + 'QClxListViewHooks_destroy';
function QClxListViewHooks_create; external QtShareName name QtNamePrefix + 'QClxListViewHooks_create';
procedure QClxListViewHooks_hook_PaintCell; external QtShareName name QtNamePrefix + 'QClxListViewHooks_hook_PaintCell';
procedure QClxListViewHooks_hook_PaintBranches; external QtShareName name QtNamePrefix + 'QClxListViewHooks_hook_PaintBranches';
procedure QClxListViewHooks_hook_setSelected; external QtShareName name QtNamePrefix + 'QClxListViewHooks_hook_setSelected';
procedure QClxListViewHooks_hook_change; external QtShareName name QtNamePrefix + 'QClxListViewHooks_hook_change';
procedure QClxListViewHooks_hook_changing; external QtShareName name QtNamePrefix + 'QClxListViewHooks_hook_changing';
procedure QClxListViewHooks_hook_expanding; external QtShareName name QtNamePrefix + 'QClxListViewHooks_hook_expanding';
procedure QClxListViewHooks_hook_expanded; external QtShareName name QtNamePrefix + 'QClxListViewHooks_hook_expanded';
procedure QClxListViewHooks_hook_checked; external QtShareName name QtNamePrefix + 'QClxListViewHooks_hook_checked';
procedure QClxListViewHooks_hook_destroyed; external QtShareName name QtNamePrefix + 'QClxListViewHooks_hook_destroyed';

procedure QClxListViewItem_destroy; external QtShareName name QtNamePrefix + 'QClxListViewItem_destroy';
function QClxListViewItem_create(parent: QListViewH; after: QListViewItemH; h: QClxListViewHooksH): QClxListViewItemH; external QtShareName name QtNamePrefix + 'QClxListViewItem_create';
function QClxListViewItem_create(parent: QListViewItemH; after: QListViewItemH; h: QClxListViewHooksH): QClxListViewItemH; external QtShareName name QtNamePrefix + 'QClxListViewItem_create2';

procedure QClxCheckListItem_destroy; external QtShareName name QtNamePrefix + 'QClxCheckListItem_destroy';
function QClxCheckListItem_create(parent: QListViewH; text: PWideString; t: QCheckListItemType; h: QClxListViewHooksH): QClxCheckListItemH; external QtShareName name QtNamePrefix + 'QClxCheckListItem_create';
function QClxCheckListItem_create(parent: QListViewItemH; text: PWideString; t: QCheckListItemType; h: QClxListViewHooksH): QClxCheckListItemH; external QtShareName name QtNamePrefix + 'QClxCheckListItem_create2';

procedure QClxIconViewHooks_destroy; external QtShareName name QtNamePrefix + 'QClxIconViewHooks_destroy';
function QClxIconViewHooks_create; external QtShareName name QtNamePrefix + 'QClxIconViewHooks_create';
procedure QClxIconViewHooks_hook_PaintItem; external QtShareName name QtNamePrefix + 'QClxIconViewHooks_hook_PaintItem';
procedure QClxIconViewHooks_hook_PaintFocus; external QtShareName name QtNamePrefix + 'QClxIconViewHooks_hook_PaintFocus';
procedure QClxIconViewHooks_hook_setSelected; external QtShareName name QtNamePrefix + 'QClxIconViewHooks_hook_setSelected';
procedure QClxIconViewHooks_hook_change; external QtShareName name QtNamePrefix + 'QClxIconViewHooks_hook_change';
procedure QClxIconViewHooks_hook_changing; external QtShareName name QtNamePrefix + 'QClxIconViewHooks_hook_changing';
procedure QClxIconViewHooks_hook_destroyed; external QtShareName name QtNamePrefix + 'QClxIconViewHooks_hook_destroyed';

procedure QClxIconViewItem_destroy; external QtShareName name QtNamePrefix + 'QClxIconViewItem_destroy';
function QClxIconViewItem_create(parent: QIconViewH; h: QClxIconViewHooksH): QClxIconViewItemH; external QtShareName name QtNamePrefix + 'QClxIconViewItem_create';
function QClxIconViewItem_create(parent: QIconViewH; after: QIconViewItemH; h: QClxIconViewHooksH): QClxIconViewItemH; external QtShareName name QtNamePrefix + 'QClxIconViewItem_create2';

procedure QClxDragObject_destroy; external QtShareName name QtNamePrefix + 'QClxDragObject_destroy';
function QClxDragObject_create; external QtShareName name QtNamePrefix + 'QClxDragObject_create';
function QClxDragObject_format; external QtShareName name QtNamePrefix + 'QClxDragObject_format';
procedure QClxDragObject_encodedData; external QtShareName name QtNamePrefix + 'QClxDragObject_encodedData';
function QClxDragObject_provides; external QtShareName name QtNamePrefix + 'QClxDragObject_provides';
procedure QClxDragObject_addFormat; external QtShareName name QtNamePrefix + 'QClxDragObject_addFormat';

procedure QOpenComboBox_destroy; external QtShareName name QtNamePrefix + 'QOpenComboBox_destroy';
function QOpenComboBox_create(parent: QWidgetH; name: PAnsiChar): QOpenComboBoxH; external QtShareName name QtNamePrefix + 'QOpenComboBox_create';
function QOpenComboBox_create(rw: Boolean; parent: QWidgetH; name: PAnsiChar): QOpenComboBoxH; external QtShareName name QtNamePrefix + 'QOpenComboBox_create2';
procedure QOpenComboBox_popup; external QtShareName name QtNamePrefix + 'QOpenComboBox_popup';

procedure QClxBitBtn_destroy; external QtShareName name QtNamePrefix + 'QClxBitBtn_destroy';
function QClxBitBtn_create; external QtShareName name QtNamePrefix + 'QClxBitBtn_create';

procedure QClxMimeSource_destroy; external QtShareName name QtNamePrefix + 'QClxMimeSource_destroy';
function QClxMimeSource_create(): QClxMimeSourceH; external QtShareName name QtNamePrefix + 'QClxMimeSource_create';
function QClxMimeSource_create(source: QMimeSourceH): QClxMimeSourceH; external QtShareName name QtNamePrefix + 'QClxMimeSource_create2';
function QClxMimeSource_format; external QtShareName name QtNamePrefix + 'QClxMimeSource_format';
procedure QClxMimeSource_encodedData; external QtShareName name QtNamePrefix + 'QClxMimeSource_encodedData';
function QClxMimeSource_provides; external QtShareName name QtNamePrefix + 'QClxMimeSource_provides';
procedure QClxMimeSource_addFormat; external QtShareName name QtNamePrefix + 'QClxMimeSource_addFormat';

procedure QClxMimeSourceFactory_destroy; external QtShareName name QtNamePrefix + 'QClxMimeSourceFactory_destroy';
function QClxMimeSourceFactory_create; external QtShareName name QtNamePrefix + 'QClxMimeSourceFactory_create';
procedure QClxMimeSourceFactory_setDataCallBack; external QtShareName name QtNamePrefix + 'QClxMimeSourceFactory_setDataCallBack';
function QClxMimeSourceFactory_data; external QtShareName name QtNamePrefix + 'QClxMimeSourceFactory_data';

procedure QClxSlider_destroy; external QtShareName name QtNamePrefix + 'QClxSlider_destroy';
function QClxSlider_create; external QtShareName name QtNamePrefix + 'QClxSlider_create';
procedure QClxSlider_drawTicks; external QtShareName name QtNamePrefix + 'QClxSlider_drawTicks';

procedure QClxStyleHooks_destroy; external QtShareName name QtNamePrefix + 'QClxStyleHooks_destroy';
function QClxStyleHooks_create; external QtShareName name QtNamePrefix + 'QClxStyleHooks_create';
procedure QClxStyleHooks_hook_polish; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_polish';
procedure QClxStyleHooks_hook_unPolish; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_unPolish';
procedure QClxStyleHooks_hook_polish2; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_polish2';
procedure QClxStyleHooks_hook_unPolish2; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_unPolish2';
procedure QClxStyleHooks_hook_polish3; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_polish3';
procedure QClxStyleHooks_hook_itemRect; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_itemRect';
procedure QClxStyleHooks_hook_drawItem; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawItem';
procedure QClxStyleHooks_hook_drawSeparator; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawSeparator';
procedure QClxStyleHooks_hook_drawRect; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawRect';
procedure QClxStyleHooks_hook_drawRectStrong; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawRectStrong';
procedure QClxStyleHooks_hook_drawButton; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawButton';
procedure QClxStyleHooks_hook_buttonRect; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_buttonRect';
procedure QClxStyleHooks_hook_drawButtonMask; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawButtonMask';
procedure QClxStyleHooks_hook_drawBevelButton; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawBevelButton';
procedure QClxStyleHooks_hook_bevelButtonRect; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_bevelButtonRect';
procedure QClxStyleHooks_hook_drawToolButton; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawToolButton';
procedure QClxStyleHooks_hook_drawToolButton2; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawToolButton2';
procedure QClxStyleHooks_hook_toolButtonRect; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_toolButtonRect';
procedure QClxStyleHooks_hook_drawPanel; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawPanel';
procedure QClxStyleHooks_hook_drawPopupPanel; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawPopupPanel';
procedure QClxStyleHooks_hook_drawArrow; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawArrow';
procedure QClxStyleHooks_hook_drawExclusiveIndicator; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawExclusiveIndicator';
procedure QClxStyleHooks_hook_drawExclusiveIndicatorMask; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawExclusiveIndicatorMask';
procedure QClxStyleHooks_hook_drawIndicatorMask; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawIndicatorMask';
procedure QClxStyleHooks_hook_drawIndicator; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawIndicator';
procedure QClxStyleHooks_hook_drawFocusRect; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawFocusRect';
procedure QClxStyleHooks_hook_drawComboButton; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawComboButton';
procedure QClxStyleHooks_hook_comboButtonRect; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_comboButtonRect';
procedure QClxStyleHooks_hook_comboButtonFocusRect; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_comboButtonFocusRect';
procedure QClxStyleHooks_hook_drawComboButtonMask; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawComboButtonMask';
procedure QClxStyleHooks_hook_drawPushButton; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawPushButton';
procedure QClxStyleHooks_hook_drawPushButtonLabel; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawPushButtonLabel';
procedure QClxStyleHooks_hook_pushButtonContentsRect; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_pushButtonContentsRect';
procedure QClxStyleHooks_hook_tabbarMetrics; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_tabbarMetrics';
procedure QClxStyleHooks_hook_drawTab; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawTab';
procedure QClxStyleHooks_hook_drawTabMask; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawTabMask';
procedure QClxStyleHooks_hook_scrollBarMetrics; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_scrollBarMetrics';
procedure QClxStyleHooks_hook_drawScrollBarControls; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawScrollBarControls';
procedure QClxStyleHooks_hook_drawSlider; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawSlider';
procedure QClxStyleHooks_hook_drawSliderMask; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawSliderMask';
procedure QClxStyleHooks_hook_drawSliderGroove; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawSliderGroove';
procedure QClxStyleHooks_hook_drawSliderGrooveMask; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawSliderGrooveMask';
procedure QClxStyleHooks_hook_drawSplitter; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawSplitter';
procedure QClxStyleHooks_hook_drawCheckMark; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawCheckMark';
procedure QClxStyleHooks_hook_polishPopupMenu; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_polishPopupMenu';
procedure QClxStyleHooks_hook_extraPopupMenuItemWidth; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_extraPopupMenuItemWidth';
procedure QClxStyleHooks_hook_popupSubmenuIndicatorWidth; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_popupSubmenuIndicatorWidth';
procedure QClxStyleHooks_hook_popupMenuItemHeight; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_popupMenuItemHeight';
procedure QClxStyleHooks_hook_drawPopupMenuItem; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_drawPopupMenuItem';
procedure QClxStyleHooks_hook_StyleDestroyed; external QtShareName name QtNamePrefix + 'QClxStyleHooks_hook_StyleDestroyed';

procedure QClxStyle_destroy; external QtShareName name QtNamePrefix + 'QClxStyle_destroy';
procedure QClxStyle_init; external QtShareName name QtNamePrefix + 'QClxStyle_init';
function QClxStyle_create(aStyle: QStyleH; h: QClxStyleHooksH): QClxStyleH; external QtShareName name QtNamePrefix + 'QClxStyle_create';
function QClxStyle_create(styleName: PWideString; h: QClxStyleHooksH): QClxStyleH; external QtShareName name QtNamePrefix + 'QClxStyle_create2';
procedure QClxStyle_refresh; external QtShareName name QtNamePrefix + 'QClxStyle_refresh';
function QClxStyle_defaultFrameWidth; external QtShareName name QtNamePrefix + 'QClxStyle_defaultFrameWidth';
procedure QClxStyle_setDefaultFrameWidth; external QtShareName name QtNamePrefix + 'QClxStyle_setDefaultFrameWidth';
function QClxStyle_sliderLength; external QtShareName name QtNamePrefix + 'QClxStyle_sliderLength';
procedure QClxStyle_setSliderLength; external QtShareName name QtNamePrefix + 'QClxStyle_setSliderLength';
function QClxStyle_maximumSliderDragDistance; external QtShareName name QtNamePrefix + 'QClxStyle_maximumSliderDragDistance';
procedure QClxStyle_setMaximumSliderDragDistance; external QtShareName name QtNamePrefix + 'QClxStyle_setMaximumSliderDragDistance';
function QClxStyle_splitterWidth; external QtShareName name QtNamePrefix + 'QClxStyle_splitterWidth';
procedure QClxStyle_setSplitterWidth; external QtShareName name QtNamePrefix + 'QClxStyle_setSplitterWidth';
procedure QClxStyle_scrollBarExtent; external QtShareName name QtNamePrefix + 'QClxStyle_scrollBarExtent';
procedure QClxStyle_setScrollBarExtent; external QtShareName name QtNamePrefix + 'QClxStyle_setScrollBarExtent';
procedure QClxStyle_indicatorSize; external QtShareName name QtNamePrefix + 'QClxStyle_indicatorSize';
procedure QClxStyle_setIndicatorSize; external QtShareName name QtNamePrefix + 'QClxStyle_setIndicatorSize';
procedure QClxStyle_exclusiveIndicatorSize; external QtShareName name QtNamePrefix + 'QClxStyle_exclusiveIndicatorSize';
procedure QClxStyle_setExclusiveIndicatorSize; external QtShareName name QtNamePrefix + 'QClxStyle_setExclusiveIndicatorSize';
procedure QClxStyle_buttonShift; external QtShareName name QtNamePrefix + 'QClxStyle_buttonShift';
procedure QClxStyle_setButtonShift; external QtShareName name QtNamePrefix + 'QClxStyle_setButtonShift';
procedure QClxStyle_scrollBarMetrics; external QtShareName name QtNamePrefix + 'QClxStyle_scrollBarMetrics';
procedure QClxStyle_tabbarMetrics; external QtShareName name QtNamePrefix + 'QClxStyle_tabbarMetrics';

procedure QClxSpinBox_destroy; external QtShareName name QtNamePrefix + 'QClxSpinBox_destroy';
function QClxSpinBox_create(parent: QWidgetH; name: PAnsiChar): QClxSpinBoxH; external QtShareName name QtNamePrefix + 'QClxSpinBox_create';
function QClxSpinBox_create(minValue: Integer; maxValue: Integer; step: Integer; parent: QWidgetH; name: PAnsiChar): QClxSpinBoxH; external QtShareName name QtNamePrefix + 'QClxSpinBox_create2';
function QClxSpinBox_upButton; external QtShareName name QtNamePrefix + 'QClxSpinBox_upButton';
function QClxSpinBox_downButton; external QtShareName name QtNamePrefix + 'QClxSpinBox_downButton';
function QClxSpinBox_editor; external QtShareName name QtNamePrefix + 'QClxSpinBox_editor';

procedure QOpenScrollView_destroy; external QtShareName name QtNamePrefix + 'QOpenScrollView_destroy';
function QOpenScrollView_create; external QtShareName name QtNamePrefix + 'QOpenScrollView_create';
procedure QOpenScrollView_resizeContents; external QtShareName name QtNamePrefix + 'QOpenScrollView_resizeContents';
procedure QOpenScrollView_setVBarGeometry; external QtShareName name QtNamePrefix + 'QOpenScrollView_setVBarGeometry';
procedure QOpenScrollView_setHBarGeometry; external QtShareName name QtNamePrefix + 'QOpenScrollView_setHBarGeometry';
procedure QOpenScrollView_getScrollBarGeometry; external QtShareName name QtNamePrefix + 'QOpenScrollView_getScrollBarGeometry';
procedure QOpenScrollView_setMargins; external QtShareName name QtNamePrefix + 'QOpenScrollView_setMargins';
function QOpenScrollView_leftMargin; external QtShareName name QtNamePrefix + 'QOpenScrollView_leftMargin';
function QOpenScrollView_topMargin; external QtShareName name QtNamePrefix + 'QOpenScrollView_topMargin';
function QOpenScrollView_rightMargin; external QtShareName name QtNamePrefix + 'QOpenScrollView_rightMargin';
function QOpenScrollView_bottomMargin; external QtShareName name QtNamePrefix + 'QOpenScrollView_bottomMargin';

procedure QClxDesign_destroy; external QtShareName name QtNamePrefix + 'QClxDesign_destroy';
procedure QClxDesign_setDesignOptions; external QtShareName name QtNamePrefix + 'QClxDesign_setDesignOptions';

procedure QOpenMultiLineEdit_destroy; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_destroy';
function QOpenMultiLineEdit_create; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_create';
function QOpenMultiLineEdit_hasMarkedText; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_hasMarkedText';
procedure QOpenMultiLineEdit_markedText; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_markedText';
function QOpenMultiLineEdit_textWidth(handle: QOpenMultiLineEditH; i: Integer): Integer; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_textWidth';
function QOpenMultiLineEdit_textWidth(handle: QOpenMultiLineEditH; text: PWideString): Integer; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_textWidth2';
procedure QOpenMultiLineEdit_cursorPoint; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_cursorPoint';
procedure QOpenMultiLineEdit_insert; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_insert';
procedure QOpenMultiLineEdit_newLine; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_newLine';
procedure QOpenMultiLineEdit_killLine; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_killLine';
procedure QOpenMultiLineEdit_pageUp; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_pageUp';
procedure QOpenMultiLineEdit_pageDown; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_pageDown';
procedure QOpenMultiLineEdit_cursorLeft; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_cursorLeft';
procedure QOpenMultiLineEdit_cursorRight; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_cursorRight';
procedure QOpenMultiLineEdit_cursorUp; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_cursorUp';
procedure QOpenMultiLineEdit_cursorDown; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_cursorDown';
procedure QOpenMultiLineEdit_backspace; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_backspace';
procedure QOpenMultiLineEdit_del; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_del';
procedure QOpenMultiLineEdit_home; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_home';
procedure QOpenMultiLineEdit_end; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_end';
function QOpenMultiLineEdit_getMarkedRegion; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_getMarkedRegion';
function QOpenMultiLineEdit_lineLength; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_lineLength';
function QOpenMultiLineEdit_getString; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_getString';
procedure QOpenMultiLineEdit_stringShown; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_stringShown';
function QOpenMultiLineEdit_textLength; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_textLength';
function QOpenMultiLineEdit_isEndOfParagraph; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_isEndOfParagraph';
procedure QOpenMultiLineEdit_getText; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_getText';
function QOpenMultiLineEdit_tableFlags; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_tableFlags';
function QOpenMultiLineEdit_testTableFlags; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_testTableFlags';
procedure QOpenMultiLineEdit_setTableFlags; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_setTableFlags';
procedure QOpenMultiLineEdit_clearTableFlags; external QtShareName name QtNamePrefix + 'QOpenMultiLineEdit_clearTableFlags';

procedure QClxFileIconProvider_destroy; external QtShareName name QtNamePrefix + 'QClxFileIconProvider_destroy';
function QClxFileIconProvider_create; external QtShareName name QtNamePrefix + 'QClxFileIconProvider_create';
function QClxFileIconProvider_pixmap; external QtShareName name QtNamePrefix + 'QClxFileIconProvider_pixmap';

procedure QClxFilePreview_destroy; external QtShareName name QtNamePrefix + 'QClxFilePreview_destroy';

procedure QClxFileDialog_destroy; external QtShareName name QtNamePrefix + 'QClxFileDialog_destroy';
function QClxFileDialog_create(dirName: PWideString; filter: PWideString; parent: QWidgetH; name: PAnsiChar; modal: Boolean): QClxFileDialogH; external QtShareName name QtNamePrefix + 'QClxFileDialog_create';
function QClxFileDialog_create(parent: QWidgetH; name: PAnsiChar; modal: Boolean): QClxFileDialogH; external QtShareName name QtNamePrefix + 'QClxFileDialog_create2';
function QClxFileDialog_create(parent: QWidgetH; modal: Boolean; f: WFlags): QClxFileDialogH; external QtShareName name QtNamePrefix + 'QClxFileDialog_create3';
procedure QClxFileDialog_getOpenFileName(retval: PWideString; initially: PWideString; filter: PWideString; parent: QWidgetH; name: PAnsiChar); external QtShareName name QtNamePrefix + 'QClxFileDialog_getOpenFileName';
procedure QClxFileDialog_getOpenFileName(retval: PWideString; initially: PWideString; filter: PWideString; parent: QWidgetH; name: PAnsiChar; caption: PWideString); external QtShareName name QtNamePrefix + 'QClxFileDialog_getOpenFileName2';
procedure QClxFileDialog_getSaveFileName(retval: PWideString; initially: PWideString; filter: PWideString; parent: QWidgetH; name: PAnsiChar); external QtShareName name QtNamePrefix + 'QClxFileDialog_getSaveFileName';
procedure QClxFileDialog_getSaveFileName(retval: PWideString; initially: PWideString; filter: PWideString; parent: QWidgetH; name: PAnsiChar; caption: PWideString); external QtShareName name QtNamePrefix + 'QClxFileDialog_getSaveFileName2';
procedure QClxFileDialog_getExistingDirectory(retval: PWideString; dir: PWideString; parent: QWidgetH; name: PAnsiChar); external QtShareName name QtNamePrefix + 'QClxFileDialog_getExistingDirectory';
procedure QClxFileDialog_getExistingDirectory(retval: PWideString; dir: PWideString; parent: QWidgetH; name: PAnsiChar; caption: PWideString); external QtShareName name QtNamePrefix + 'QClxFileDialog_getExistingDirectory2';
procedure QClxFileDialog_getExistingDirectory(retval: PWideString; dir: PWideString; parent: QWidgetH; name: PAnsiChar; caption: PWideString; dirOnly: Boolean); external QtShareName name QtNamePrefix + 'QClxFileDialog_getExistingDirectory3';
procedure QClxFileDialog_getOpenFileNames(retval: QStringListH; filter: PWideString; dir: PWideString; parent: QWidgetH; name: PAnsiChar); external QtShareName name QtNamePrefix + 'QClxFileDialog_getOpenFileNames';
procedure QClxFileDialog_getOpenFileNames(retval: QStringListH; filter: PWideString; dir: PWideString; parent: QWidgetH; name: PAnsiChar; caption: PWideString); external QtShareName name QtNamePrefix + 'QClxFileDialog_getOpenFileNames2';
procedure QClxFileDialog_setIconProvider; external QtShareName name QtNamePrefix + 'QClxFileDialog_setIconProvider';
function QClxFileDialog_iconProvider; external QtShareName name QtNamePrefix + 'QClxFileDialog_iconProvider';
procedure QClxFileDialog_selectedFile; external QtShareName name QtNamePrefix + 'QClxFileDialog_selectedFile';
procedure QClxFileDialog_selectedFilter; external QtShareName name QtNamePrefix + 'QClxFileDialog_selectedFilter';
procedure QClxFileDialog_setSelection; external QtShareName name QtNamePrefix + 'QClxFileDialog_setSelection';
procedure QClxFileDialog_selectAll; external QtShareName name QtNamePrefix + 'QClxFileDialog_selectAll';
procedure QClxFileDialog_selectedFiles; external QtShareName name QtNamePrefix + 'QClxFileDialog_selectedFiles';
procedure QClxFileDialog_dirPath; external QtShareName name QtNamePrefix + 'QClxFileDialog_dirPath';
procedure QClxFileDialog_setDir(handle: QClxFileDialogH; p1: QDirH); external QtShareName name QtNamePrefix + 'QClxFileDialog_setDir';
function QClxFileDialog_dir; external QtShareName name QtNamePrefix + 'QClxFileDialog_dir';
procedure QClxFileDialog_setShowHiddenFiles; external QtShareName name QtNamePrefix + 'QClxFileDialog_setShowHiddenFiles';
function QClxFileDialog_showHiddenFiles; external QtShareName name QtNamePrefix + 'QClxFileDialog_showHiddenFiles';
procedure QClxFileDialog_rereadDir; external QtShareName name QtNamePrefix + 'QClxFileDialog_rereadDir';
procedure QClxFileDialog_resortDir; external QtShareName name QtNamePrefix + 'QClxFileDialog_resortDir';
procedure QClxFileDialog_setMode; external QtShareName name QtNamePrefix + 'QClxFileDialog_setMode';
function QClxFileDialog_mode; external QtShareName name QtNamePrefix + 'QClxFileDialog_mode';
procedure QClxFileDialog_setViewMode; external QtShareName name QtNamePrefix + 'QClxFileDialog_setViewMode';
function QClxFileDialog_viewMode; external QtShareName name QtNamePrefix + 'QClxFileDialog_viewMode';
procedure QClxFileDialog_setPreviewMode; external QtShareName name QtNamePrefix + 'QClxFileDialog_setPreviewMode';
function QClxFileDialog_previewMode; external QtShareName name QtNamePrefix + 'QClxFileDialog_previewMode';
function QClxFileDialog_eventFilter; external QtShareName name QtNamePrefix + 'QClxFileDialog_eventFilter';
function QClxFileDialog_isInfoPreviewEnabled; external QtShareName name QtNamePrefix + 'QClxFileDialog_isInfoPreviewEnabled';
function QClxFileDialog_isContentsPreviewEnabled; external QtShareName name QtNamePrefix + 'QClxFileDialog_isContentsPreviewEnabled';
procedure QClxFileDialog_setInfoPreviewEnabled; external QtShareName name QtNamePrefix + 'QClxFileDialog_setInfoPreviewEnabled';
procedure QClxFileDialog_setContentsPreviewEnabled; external QtShareName name QtNamePrefix + 'QClxFileDialog_setContentsPreviewEnabled';
procedure QClxFileDialog_setInfoPreview; external QtShareName name QtNamePrefix + 'QClxFileDialog_setInfoPreview';
procedure QClxFileDialog_setContentsPreview; external QtShareName name QtNamePrefix + 'QClxFileDialog_setContentsPreview';

procedure QClxFileDialog_setEditText; external QtShareName name QtNamePrefix + 'QClxFileDialog_setEditText';
procedure QClxFileDialog_setFilterIndex; external QtShareName name QtNamePrefix + 'QClxFileDialog_setFilterIndex';
procedure QClxFileDialog_hook_addFile; external QtShareName name QtNamePrefix + 'QClxFileDialog_hook_addFile';
procedure QClxFileDialog_selectedExt; external QtShareName name QtNamePrefix + 'QClxFileDialog_selectedExt';
procedure QClxFileDialog_setDefaultExt; external QtShareName name QtNamePrefix + 'QClxFileDialog_setDefaultExt';
procedure QClxFileDialog_defaultExt; external QtShareName name QtNamePrefix + 'QClxFileDialog_defaultExt';
function QClxFileDialog_isRegisteredExtension; external QtShareName name QtNamePrefix + 'QClxFileDialog_isRegisteredExtension';
procedure QClxFileDialog_done; external QtShareName name QtNamePrefix + 'QClxFileDialog_done';
procedure QClxFileDialog_setDir(handle: QClxFileDialogH; p1: PWideString); external QtShareName name QtNamePrefix + 'QClxFileDialog_setDir2';

procedure QClxFileDialog_setFilter; external QtShareName name QtNamePrefix + 'QClxFileDialog_setFilter';
procedure QClxFileDialog_setFilters(handle: QClxFileDialogH; p1: PWideString); external QtShareName name QtNamePrefix + 'QClxFileDialog_setFilters';
procedure QClxFileDialog_setFilters(handle: QClxFileDialogH; p1: PPAnsiChar); external QtShareName name QtNamePrefix + 'QClxFileDialog_setFilters2';
procedure QClxFileDialog_setFilters(handle: QClxFileDialogH; p1: QStringListH); external QtShareName name QtNamePrefix + 'QClxFileDialog_setFilters3';
procedure QClxFileDialog_show; external QtShareName name QtNamePrefix + 'QClxFileDialog_show';

procedure QOpenTableView_destroy; external QtShareName name QtNamePrefix + 'QOpenTableView_destroy';
function QOpenTableView_numRows; external QtShareName name QtNamePrefix + 'QOpenTableView_numRows';
procedure QOpenTableView_setNumRows; external QtShareName name QtNamePrefix + 'QOpenTableView_setNumRows';
function QOpenTableView_numCols; external QtShareName name QtNamePrefix + 'QOpenTableView_numCols';
procedure QOpenTableView_setNumCols; external QtShareName name QtNamePrefix + 'QOpenTableView_setNumCols';
function QOpenTableView_topCell; external QtShareName name QtNamePrefix + 'QOpenTableView_topCell';
procedure QOpenTableView_setTopCell; external QtShareName name QtNamePrefix + 'QOpenTableView_setTopCell';
function QOpenTableView_leftCell; external QtShareName name QtNamePrefix + 'QOpenTableView_leftCell';
procedure QOpenTableView_setLeftCell; external QtShareName name QtNamePrefix + 'QOpenTableView_setLeftCell';
procedure QOpenTableView_setTopLeftCell; external QtShareName name QtNamePrefix + 'QOpenTableView_setTopLeftCell';
function QOpenTableView_xOffset; external QtShareName name QtNamePrefix + 'QOpenTableView_xOffset';
procedure QOpenTableView_setXOffset; external QtShareName name QtNamePrefix + 'QOpenTableView_setXOffset';
function QOpenTableView_yOffset; external QtShareName name QtNamePrefix + 'QOpenTableView_yOffset';
procedure QOpenTableView_setYOffset; external QtShareName name QtNamePrefix + 'QOpenTableView_setYOffset';
procedure QOpenTableView_setOffset; external QtShareName name QtNamePrefix + 'QOpenTableView_setOffset';
function QOpenTableView_cellWidth(handle: QOpenTableViewH; col: Integer): Integer; external QtShareName name QtNamePrefix + 'QOpenTableView_cellWidth';
function QOpenTableView_cellHeight(handle: QOpenTableViewH; row: Integer): Integer; external QtShareName name QtNamePrefix + 'QOpenTableView_cellHeight';
function QOpenTableView_cellWidth(handle: QOpenTableViewH): Integer; external QtShareName name QtNamePrefix + 'QOpenTableView_cellWidth2';
function QOpenTableView_cellHeight(handle: QOpenTableViewH): Integer; external QtShareName name QtNamePrefix + 'QOpenTableView_cellHeight2';
procedure QOpenTableView_setCellWidth; external QtShareName name QtNamePrefix + 'QOpenTableView_setCellWidth';
procedure QOpenTableView_setCellHeight; external QtShareName name QtNamePrefix + 'QOpenTableView_setCellHeight';
function QOpenTableView_totalWidth; external QtShareName name QtNamePrefix + 'QOpenTableView_totalWidth';
function QOpenTableView_totalHeight; external QtShareName name QtNamePrefix + 'QOpenTableView_totalHeight';
function QOpenTableView_tableFlags; external QtShareName name QtNamePrefix + 'QOpenTableView_tableFlags';
function QOpenTableView_testTableFlags; external QtShareName name QtNamePrefix + 'QOpenTableView_testTableFlags';
procedure QOpenTableView_setTableFlags; external QtShareName name QtNamePrefix + 'QOpenTableView_setTableFlags';
procedure QOpenTableView_clearTableFlags; external QtShareName name QtNamePrefix + 'QOpenTableView_clearTableFlags';
function QOpenTableView_autoUpdate; external QtShareName name QtNamePrefix + 'QOpenTableView_autoUpdate';
procedure QOpenTableView_setAutoUpdate; external QtShareName name QtNamePrefix + 'QOpenTableView_setAutoUpdate';
procedure QOpenTableView_updateCell; external QtShareName name QtNamePrefix + 'QOpenTableView_updateCell';
procedure QOpenTableView_cellUpdateRect; external QtShareName name QtNamePrefix + 'QOpenTableView_cellUpdateRect';
procedure QOpenTableView_viewRect; external QtShareName name QtNamePrefix + 'QOpenTableView_viewRect';
function QOpenTableView_lastRowVisible; external QtShareName name QtNamePrefix + 'QOpenTableView_lastRowVisible';
function QOpenTableView_lastColVisible; external QtShareName name QtNamePrefix + 'QOpenTableView_lastColVisible';
function QOpenTableView_rowIsVisible; external QtShareName name QtNamePrefix + 'QOpenTableView_rowIsVisible';
function QOpenTableView_colIsVisible; external QtShareName name QtNamePrefix + 'QOpenTableView_colIsVisible';
function QOpenTableView_verticalScrollBar; external QtShareName name QtNamePrefix + 'QOpenTableView_verticalScrollBar';
function QOpenTableView_horizontalScrollBar; external QtShareName name QtNamePrefix + 'QOpenTableView_horizontalScrollBar';
procedure QOpenTableView_scroll; external QtShareName name QtNamePrefix + 'QOpenTableView_scroll';
procedure QOpenTableView_updateScrollBars; external QtShareName name QtNamePrefix + 'QOpenTableView_updateScrollBars';
procedure QOpenTableView_updateTableSize; external QtShareName name QtNamePrefix + 'QOpenTableView_updateTableSize';

procedure QObject_hook_destroy; external QtShareName name QtNamePrefix + 'QObject_hook_destroy';
function QObject_hook_create; external QtShareName name QtNamePrefix + 'QObject_hook_create';
procedure QObject_hook_hook_destroyed; external QtShareName name QtNamePrefix + 'QObject_hook_hook_destroyed';

procedure QSenderObject_hook_destroy; external QtShareName name QtNamePrefix + 'QSenderObject_hook_destroy';
function QSenderObject_hook_create; external QtShareName name QtNamePrefix + 'QSenderObject_hook_create';

procedure QWidget_hook_destroy; external QtShareName name QtNamePrefix + 'QWidget_hook_destroy';
function QWidget_hook_create; external QtShareName name QtNamePrefix + 'QWidget_hook_create';

procedure QApplication_hook_destroy; external QtShareName name QtNamePrefix + 'QApplication_hook_destroy';
function QApplication_hook_create; external QtShareName name QtNamePrefix + 'QApplication_hook_create';
procedure QApplication_hook_hook_lastWindowClosed; external QtShareName name QtNamePrefix + 'QApplication_hook_hook_lastWindowClosed';
procedure QApplication_hook_hook_aboutToQuit; external QtShareName name QtNamePrefix + 'QApplication_hook_hook_aboutToQuit';
procedure QApplication_hook_hook_guiThreadAwake; external QtShareName name QtNamePrefix + 'QApplication_hook_hook_guiThreadAwake';

procedure QButton_hook_destroy; external QtShareName name QtNamePrefix + 'QButton_hook_destroy';
function QButton_hook_create; external QtShareName name QtNamePrefix + 'QButton_hook_create';
procedure QButton_hook_hook_pressed; external QtShareName name QtNamePrefix + 'QButton_hook_hook_pressed';
procedure QButton_hook_hook_released; external QtShareName name QtNamePrefix + 'QButton_hook_hook_released';
procedure QButton_hook_hook_clicked; external QtShareName name QtNamePrefix + 'QButton_hook_hook_clicked';
procedure QButton_hook_hook_toggled; external QtShareName name QtNamePrefix + 'QButton_hook_hook_toggled';
procedure QButton_hook_hook_stateChanged; external QtShareName name QtNamePrefix + 'QButton_hook_hook_stateChanged';

procedure QComboBox_hook_destroy; external QtShareName name QtNamePrefix + 'QComboBox_hook_destroy';
function QComboBox_hook_create; external QtShareName name QtNamePrefix + 'QComboBox_hook_create';
procedure QComboBox_hook_hook_activated; external QtShareName name QtNamePrefix + 'QComboBox_hook_hook_activated';
procedure QComboBox_hook_hook_highlighted; external QtShareName name QtNamePrefix + 'QComboBox_hook_hook_highlighted';
procedure QComboBox_hook_hook_activated2; external QtShareName name QtNamePrefix + 'QComboBox_hook_hook_activated2';
procedure QComboBox_hook_hook_highlighted2; external QtShareName name QtNamePrefix + 'QComboBox_hook_hook_highlighted2';
procedure QComboBox_hook_hook_textChanged; external QtShareName name QtNamePrefix + 'QComboBox_hook_hook_textChanged';

procedure QDialog_hook_destroy; external QtShareName name QtNamePrefix + 'QDialog_hook_destroy';
function QDialog_hook_create; external QtShareName name QtNamePrefix + 'QDialog_hook_create';

procedure QDragObject_hook_destroy; external QtShareName name QtNamePrefix + 'QDragObject_hook_destroy';
function QDragObject_hook_create; external QtShareName name QtNamePrefix + 'QDragObject_hook_create';

procedure QStoredDrag_hook_destroy; external QtShareName name QtNamePrefix + 'QStoredDrag_hook_destroy';
function QStoredDrag_hook_create; external QtShareName name QtNamePrefix + 'QStoredDrag_hook_create';

procedure QTextDrag_hook_destroy; external QtShareName name QtNamePrefix + 'QTextDrag_hook_destroy';
function QTextDrag_hook_create; external QtShareName name QtNamePrefix + 'QTextDrag_hook_create';

procedure QImageDrag_hook_destroy; external QtShareName name QtNamePrefix + 'QImageDrag_hook_destroy';
function QImageDrag_hook_create; external QtShareName name QtNamePrefix + 'QImageDrag_hook_create';

procedure QUriDrag_hook_destroy; external QtShareName name QtNamePrefix + 'QUriDrag_hook_destroy';
function QUriDrag_hook_create; external QtShareName name QtNamePrefix + 'QUriDrag_hook_create';

procedure QColorDrag_hook_destroy; external QtShareName name QtNamePrefix + 'QColorDrag_hook_destroy';
function QColorDrag_hook_create; external QtShareName name QtNamePrefix + 'QColorDrag_hook_create';

procedure QEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QEvent_hook_destroy';
function QEvent_hook_create; external QtShareName name QtNamePrefix + 'QEvent_hook_create';

procedure QTimerEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QTimerEvent_hook_destroy';
function QTimerEvent_hook_create; external QtShareName name QtNamePrefix + 'QTimerEvent_hook_create';

procedure QMouseEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QMouseEvent_hook_destroy';
function QMouseEvent_hook_create; external QtShareName name QtNamePrefix + 'QMouseEvent_hook_create';

procedure QWheelEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QWheelEvent_hook_destroy';
function QWheelEvent_hook_create; external QtShareName name QtNamePrefix + 'QWheelEvent_hook_create';

procedure QKeyEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QKeyEvent_hook_destroy';
function QKeyEvent_hook_create; external QtShareName name QtNamePrefix + 'QKeyEvent_hook_create';

procedure QFocusEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QFocusEvent_hook_destroy';
function QFocusEvent_hook_create; external QtShareName name QtNamePrefix + 'QFocusEvent_hook_create';

procedure QPaintEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QPaintEvent_hook_destroy';
function QPaintEvent_hook_create; external QtShareName name QtNamePrefix + 'QPaintEvent_hook_create';

procedure QMoveEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QMoveEvent_hook_destroy';
function QMoveEvent_hook_create; external QtShareName name QtNamePrefix + 'QMoveEvent_hook_create';

procedure QResizeEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QResizeEvent_hook_destroy';
function QResizeEvent_hook_create; external QtShareName name QtNamePrefix + 'QResizeEvent_hook_create';

procedure QCloseEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QCloseEvent_hook_destroy';
function QCloseEvent_hook_create; external QtShareName name QtNamePrefix + 'QCloseEvent_hook_create';

procedure QShowEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QShowEvent_hook_destroy';
function QShowEvent_hook_create; external QtShareName name QtNamePrefix + 'QShowEvent_hook_create';

procedure QHideEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QHideEvent_hook_destroy';
function QHideEvent_hook_create; external QtShareName name QtNamePrefix + 'QHideEvent_hook_create';

procedure QDropEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QDropEvent_hook_destroy';
function QDropEvent_hook_create; external QtShareName name QtNamePrefix + 'QDropEvent_hook_create';

procedure QDragMoveEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QDragMoveEvent_hook_destroy';
function QDragMoveEvent_hook_create; external QtShareName name QtNamePrefix + 'QDragMoveEvent_hook_create';

procedure QDragEnterEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QDragEnterEvent_hook_destroy';
function QDragEnterEvent_hook_create; external QtShareName name QtNamePrefix + 'QDragEnterEvent_hook_create';

procedure QDragResponseEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QDragResponseEvent_hook_destroy';
function QDragResponseEvent_hook_create; external QtShareName name QtNamePrefix + 'QDragResponseEvent_hook_create';

procedure QDragLeaveEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QDragLeaveEvent_hook_destroy';
function QDragLeaveEvent_hook_create; external QtShareName name QtNamePrefix + 'QDragLeaveEvent_hook_create';

procedure QChildEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QChildEvent_hook_destroy';
function QChildEvent_hook_create; external QtShareName name QtNamePrefix + 'QChildEvent_hook_create';

procedure QCustomEvent_hook_destroy; external QtShareName name QtNamePrefix + 'QCustomEvent_hook_destroy';
function QCustomEvent_hook_create; external QtShareName name QtNamePrefix + 'QCustomEvent_hook_create';

procedure QFrame_hook_destroy; external QtShareName name QtNamePrefix + 'QFrame_hook_destroy';
function QFrame_hook_create; external QtShareName name QtNamePrefix + 'QFrame_hook_create';

procedure QIconView_hook_destroy; external QtShareName name QtNamePrefix + 'QIconView_hook_destroy';
function QIconView_hook_create; external QtShareName name QtNamePrefix + 'QIconView_hook_create';
procedure QIconView_hook_hook_selectionChanged; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_selectionChanged';
procedure QIconView_hook_hook_selectionChanged2; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_selectionChanged2';
procedure QIconView_hook_hook_currentChanged; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_currentChanged';
procedure QIconView_hook_hook_clicked; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_clicked';
procedure QIconView_hook_hook_clicked2; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_clicked2';
procedure QIconView_hook_hook_pressed; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_pressed';
procedure QIconView_hook_hook_pressed2; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_pressed2';
procedure QIconView_hook_hook_doubleClicked; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_doubleClicked';
procedure QIconView_hook_hook_returnPressed; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_returnPressed';
procedure QIconView_hook_hook_rightButtonClicked; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_rightButtonClicked';
procedure QIconView_hook_hook_rightButtonPressed; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_rightButtonPressed';
procedure QIconView_hook_hook_mouseButtonPressed; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_mouseButtonPressed';
procedure QIconView_hook_hook_mouseButtonClicked; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_mouseButtonClicked';
procedure QIconView_hook_hook_dropped; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_dropped';
procedure QIconView_hook_hook_moved; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_moved';
procedure QIconView_hook_hook_onItem; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_onItem';
procedure QIconView_hook_hook_onViewport; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_onViewport';
procedure QIconView_hook_hook_itemRenamed; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_itemRenamed';
procedure QIconView_hook_hook_itemRenamed2; external QtShareName name QtNamePrefix + 'QIconView_hook_hook_itemRenamed2';

procedure QLCDNumber_hook_destroy; external QtShareName name QtNamePrefix + 'QLCDNumber_hook_destroy';
function QLCDNumber_hook_create; external QtShareName name QtNamePrefix + 'QLCDNumber_hook_create';
procedure QLCDNumber_hook_hook_overflow; external QtShareName name QtNamePrefix + 'QLCDNumber_hook_hook_overflow';

procedure QLineEdit_hook_destroy; external QtShareName name QtNamePrefix + 'QLineEdit_hook_destroy';
function QLineEdit_hook_create; external QtShareName name QtNamePrefix + 'QLineEdit_hook_create';
procedure QLineEdit_hook_hook_textChanged; external QtShareName name QtNamePrefix + 'QLineEdit_hook_hook_textChanged';
procedure QLineEdit_hook_hook_returnPressed; external QtShareName name QtNamePrefix + 'QLineEdit_hook_hook_returnPressed';

procedure QListBox_hook_destroy; external QtShareName name QtNamePrefix + 'QListBox_hook_destroy';
function QListBox_hook_create; external QtShareName name QtNamePrefix + 'QListBox_hook_create';
procedure QListBox_hook_hook_highlighted; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_highlighted';
procedure QListBox_hook_hook_selected; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_selected';
procedure QListBox_hook_hook_highlighted2; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_highlighted2';
procedure QListBox_hook_hook_selected2; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_selected2';
procedure QListBox_hook_hook_highlighted3; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_highlighted3';
procedure QListBox_hook_hook_selected3; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_selected3';
procedure QListBox_hook_hook_selectionChanged; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_selectionChanged';
procedure QListBox_hook_hook_selectionChanged2; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_selectionChanged2';
procedure QListBox_hook_hook_currentChanged; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_currentChanged';
procedure QListBox_hook_hook_clicked; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_clicked';
procedure QListBox_hook_hook_clicked2; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_clicked2';
procedure QListBox_hook_hook_pressed; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_pressed';
procedure QListBox_hook_hook_pressed2; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_pressed2';
procedure QListBox_hook_hook_doubleClicked; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_doubleClicked';
procedure QListBox_hook_hook_returnPressed; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_returnPressed';
procedure QListBox_hook_hook_rightButtonClicked; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_rightButtonClicked';
procedure QListBox_hook_hook_rightButtonPressed; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_rightButtonPressed';
procedure QListBox_hook_hook_mouseButtonPressed; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_mouseButtonPressed';
procedure QListBox_hook_hook_mouseButtonClicked; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_mouseButtonClicked';
procedure QListBox_hook_hook_onItem; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_onItem';
procedure QListBox_hook_hook_onViewport; external QtShareName name QtNamePrefix + 'QListBox_hook_hook_onViewport';

procedure QListViewItem_hook_destroy; external QtShareName name QtNamePrefix + 'QListViewItem_hook_destroy';
function QListViewItem_hook_create; external QtShareName name QtNamePrefix + 'QListViewItem_hook_create';

procedure QListView_hook_destroy; external QtShareName name QtNamePrefix + 'QListView_hook_destroy';
function QListView_hook_create; external QtShareName name QtNamePrefix + 'QListView_hook_create';
procedure QListView_hook_hook_selectionChanged; external QtShareName name QtNamePrefix + 'QListView_hook_hook_selectionChanged';
procedure QListView_hook_hook_selectionChanged2; external QtShareName name QtNamePrefix + 'QListView_hook_hook_selectionChanged2';
procedure QListView_hook_hook_currentChanged; external QtShareName name QtNamePrefix + 'QListView_hook_hook_currentChanged';
procedure QListView_hook_hook_clicked; external QtShareName name QtNamePrefix + 'QListView_hook_hook_clicked';
procedure QListView_hook_hook_clicked2; external QtShareName name QtNamePrefix + 'QListView_hook_hook_clicked2';
procedure QListView_hook_hook_pressed; external QtShareName name QtNamePrefix + 'QListView_hook_hook_pressed';
procedure QListView_hook_hook_pressed2; external QtShareName name QtNamePrefix + 'QListView_hook_hook_pressed2';
procedure QListView_hook_hook_doubleClicked; external QtShareName name QtNamePrefix + 'QListView_hook_hook_doubleClicked';
procedure QListView_hook_hook_returnPressed; external QtShareName name QtNamePrefix + 'QListView_hook_hook_returnPressed';
procedure QListView_hook_hook_rightButtonClicked; external QtShareName name QtNamePrefix + 'QListView_hook_hook_rightButtonClicked';
procedure QListView_hook_hook_rightButtonPressed; external QtShareName name QtNamePrefix + 'QListView_hook_hook_rightButtonPressed';
procedure QListView_hook_hook_mouseButtonPressed; external QtShareName name QtNamePrefix + 'QListView_hook_hook_mouseButtonPressed';
procedure QListView_hook_hook_mouseButtonClicked; external QtShareName name QtNamePrefix + 'QListView_hook_hook_mouseButtonClicked';
procedure QListView_hook_hook_onItem; external QtShareName name QtNamePrefix + 'QListView_hook_hook_onItem';
procedure QListView_hook_hook_onViewport; external QtShareName name QtNamePrefix + 'QListView_hook_hook_onViewport';
procedure QListView_hook_hook_expanded; external QtShareName name QtNamePrefix + 'QListView_hook_hook_expanded';
procedure QListView_hook_hook_collapsed; external QtShareName name QtNamePrefix + 'QListView_hook_hook_collapsed';

procedure QCheckListItem_hook_destroy; external QtShareName name QtNamePrefix + 'QCheckListItem_hook_destroy';
function QCheckListItem_hook_create; external QtShareName name QtNamePrefix + 'QCheckListItem_hook_create';

procedure QMenuBar_hook_destroy; external QtShareName name QtNamePrefix + 'QMenuBar_hook_destroy';
function QMenuBar_hook_create; external QtShareName name QtNamePrefix + 'QMenuBar_hook_create';
procedure QMenuBar_hook_hook_activated; external QtShareName name QtNamePrefix + 'QMenuBar_hook_hook_activated';
procedure QMenuBar_hook_hook_highlighted; external QtShareName name QtNamePrefix + 'QMenuBar_hook_hook_highlighted';

procedure QMessageBox_hook_destroy; external QtShareName name QtNamePrefix + 'QMessageBox_hook_destroy';
function QMessageBox_hook_create; external QtShareName name QtNamePrefix + 'QMessageBox_hook_create';

procedure QMultiLineEdit_hook_destroy; external QtShareName name QtNamePrefix + 'QMultiLineEdit_hook_destroy';
function QMultiLineEdit_hook_create; external QtShareName name QtNamePrefix + 'QMultiLineEdit_hook_create';
procedure QMultiLineEdit_hook_hook_textChanged; external QtShareName name QtNamePrefix + 'QMultiLineEdit_hook_hook_textChanged';
procedure QMultiLineEdit_hook_hook_returnPressed; external QtShareName name QtNamePrefix + 'QMultiLineEdit_hook_hook_returnPressed';
procedure QMultiLineEdit_hook_hook_undoAvailable; external QtShareName name QtNamePrefix + 'QMultiLineEdit_hook_hook_undoAvailable';
procedure QMultiLineEdit_hook_hook_redoAvailable; external QtShareName name QtNamePrefix + 'QMultiLineEdit_hook_hook_redoAvailable';
procedure QMultiLineEdit_hook_hook_copyAvailable; external QtShareName name QtNamePrefix + 'QMultiLineEdit_hook_hook_copyAvailable';

procedure QScrollView_hook_destroy; external QtShareName name QtNamePrefix + 'QScrollView_hook_destroy';
function QScrollView_hook_create; external QtShareName name QtNamePrefix + 'QScrollView_hook_create';
procedure QScrollView_hook_hook_contentsMoving; external QtShareName name QtNamePrefix + 'QScrollView_hook_hook_contentsMoving';

procedure QSlider_hook_destroy; external QtShareName name QtNamePrefix + 'QSlider_hook_destroy';
function QSlider_hook_create; external QtShareName name QtNamePrefix + 'QSlider_hook_create';
procedure QSlider_hook_hook_valueChanged; external QtShareName name QtNamePrefix + 'QSlider_hook_hook_valueChanged';
procedure QSlider_hook_hook_sliderPressed; external QtShareName name QtNamePrefix + 'QSlider_hook_hook_sliderPressed';
procedure QSlider_hook_hook_sliderMoved; external QtShareName name QtNamePrefix + 'QSlider_hook_hook_sliderMoved';
procedure QSlider_hook_hook_sliderReleased; external QtShareName name QtNamePrefix + 'QSlider_hook_hook_sliderReleased';

procedure QSocketNotifier_hook_destroy; external QtShareName name QtNamePrefix + 'QSocketNotifier_hook_destroy';
function QSocketNotifier_hook_create; external QtShareName name QtNamePrefix + 'QSocketNotifier_hook_create';
procedure QSocketNotifier_hook_hook_activated; external QtShareName name QtNamePrefix + 'QSocketNotifier_hook_hook_activated';

procedure QSpinBox_hook_destroy; external QtShareName name QtNamePrefix + 'QSpinBox_hook_destroy';
function QSpinBox_hook_create; external QtShareName name QtNamePrefix + 'QSpinBox_hook_create';
procedure QSpinBox_hook_hook_valueChanged; external QtShareName name QtNamePrefix + 'QSpinBox_hook_hook_valueChanged';
procedure QSpinBox_hook_hook_valueChanged2; external QtShareName name QtNamePrefix + 'QSpinBox_hook_hook_valueChanged2';

procedure QStyle_hook_destroy; external QtShareName name QtNamePrefix + 'QStyle_hook_destroy';
function QStyle_hook_create; external QtShareName name QtNamePrefix + 'QStyle_hook_create';

procedure QTranslator_hook_destroy; external QtShareName name QtNamePrefix + 'QTranslator_hook_destroy';
function QTranslator_hook_create; external QtShareName name QtNamePrefix + 'QTranslator_hook_create';

procedure QBrush_hook_destroy; external QtShareName name QtNamePrefix + 'QBrush_hook_destroy';
function QBrush_hook_create; external QtShareName name QtNamePrefix + 'QBrush_hook_create';

procedure QButtonGroup_hook_destroy; external QtShareName name QtNamePrefix + 'QButtonGroup_hook_destroy';
function QButtonGroup_hook_create; external QtShareName name QtNamePrefix + 'QButtonGroup_hook_create';
procedure QButtonGroup_hook_hook_pressed; external QtShareName name QtNamePrefix + 'QButtonGroup_hook_hook_pressed';
procedure QButtonGroup_hook_hook_released; external QtShareName name QtNamePrefix + 'QButtonGroup_hook_hook_released';
procedure QButtonGroup_hook_hook_clicked; external QtShareName name QtNamePrefix + 'QButtonGroup_hook_hook_clicked';

procedure QCheckBox_hook_destroy; external QtShareName name QtNamePrefix + 'QCheckBox_hook_destroy';
function QCheckBox_hook_create; external QtShareName name QtNamePrefix + 'QCheckBox_hook_create';

procedure QClipboard_hook_destroy; external QtShareName name QtNamePrefix + 'QClipboard_hook_destroy';
function QClipboard_hook_create; external QtShareName name QtNamePrefix + 'QClipboard_hook_create';
procedure QClipboard_hook_hook_dataChanged; external QtShareName name QtNamePrefix + 'QClipboard_hook_hook_dataChanged';

procedure QColorDialog_hook_destroy; external QtShareName name QtNamePrefix + 'QColorDialog_hook_destroy';
function QColorDialog_hook_create; external QtShareName name QtNamePrefix + 'QColorDialog_hook_create';

procedure QCommonStyle_hook_destroy; external QtShareName name QtNamePrefix + 'QCommonStyle_hook_destroy';
function QCommonStyle_hook_create; external QtShareName name QtNamePrefix + 'QCommonStyle_hook_create';

procedure QFontDialog_hook_destroy; external QtShareName name QtNamePrefix + 'QFontDialog_hook_destroy';
function QFontDialog_hook_create; external QtShareName name QtNamePrefix + 'QFontDialog_hook_create';
procedure QFontDialog_hook_hook_fontSelected; external QtShareName name QtNamePrefix + 'QFontDialog_hook_hook_fontSelected';
procedure QFontDialog_hook_hook_fontHighlighted; external QtShareName name QtNamePrefix + 'QFontDialog_hook_hook_fontHighlighted';

procedure QGroupBox_hook_destroy; external QtShareName name QtNamePrefix + 'QGroupBox_hook_destroy';
function QGroupBox_hook_create; external QtShareName name QtNamePrefix + 'QGroupBox_hook_create';

procedure QHeader_hook_destroy; external QtShareName name QtNamePrefix + 'QHeader_hook_destroy';
function QHeader_hook_create; external QtShareName name QtNamePrefix + 'QHeader_hook_create';
procedure QHeader_hook_hook_clicked; external QtShareName name QtNamePrefix + 'QHeader_hook_hook_clicked';
procedure QHeader_hook_hook_pressed; external QtShareName name QtNamePrefix + 'QHeader_hook_hook_pressed';
procedure QHeader_hook_hook_released; external QtShareName name QtNamePrefix + 'QHeader_hook_hook_released';
procedure QHeader_hook_hook_sizeChange; external QtShareName name QtNamePrefix + 'QHeader_hook_hook_sizeChange';
procedure QHeader_hook_hook_indexChange; external QtShareName name QtNamePrefix + 'QHeader_hook_hook_indexChange';
procedure QHeader_hook_hook_sectionClicked; external QtShareName name QtNamePrefix + 'QHeader_hook_hook_sectionClicked';
procedure QHeader_hook_hook_moved; external QtShareName name QtNamePrefix + 'QHeader_hook_hook_moved';

procedure QLabel_hook_destroy; external QtShareName name QtNamePrefix + 'QLabel_hook_destroy';
function QLabel_hook_create; external QtShareName name QtNamePrefix + 'QLabel_hook_create';

procedure QPainter_hook_destroy; external QtShareName name QtNamePrefix + 'QPainter_hook_destroy';
function QPainter_hook_create; external QtShareName name QtNamePrefix + 'QPainter_hook_create';

procedure QPen_hook_destroy; external QtShareName name QtNamePrefix + 'QPen_hook_destroy';
function QPen_hook_create; external QtShareName name QtNamePrefix + 'QPen_hook_create';

procedure QPopupMenu_hook_destroy; external QtShareName name QtNamePrefix + 'QPopupMenu_hook_destroy';
function QPopupMenu_hook_create; external QtShareName name QtNamePrefix + 'QPopupMenu_hook_create';
procedure QPopupMenu_hook_hook_activated; external QtShareName name QtNamePrefix + 'QPopupMenu_hook_hook_activated';
procedure QPopupMenu_hook_hook_highlighted; external QtShareName name QtNamePrefix + 'QPopupMenu_hook_hook_highlighted';
procedure QPopupMenu_hook_hook_activatedRedirect; external QtShareName name QtNamePrefix + 'QPopupMenu_hook_hook_activatedRedirect';
procedure QPopupMenu_hook_hook_highlightedRedirect; external QtShareName name QtNamePrefix + 'QPopupMenu_hook_hook_highlightedRedirect';
procedure QPopupMenu_hook_hook_aboutToShow; external QtShareName name QtNamePrefix + 'QPopupMenu_hook_hook_aboutToShow';
procedure QPopupMenu_hook_hook_aboutToHide; external QtShareName name QtNamePrefix + 'QPopupMenu_hook_hook_aboutToHide';

procedure QPushButton_hook_destroy; external QtShareName name QtNamePrefix + 'QPushButton_hook_destroy';
function QPushButton_hook_create; external QtShareName name QtNamePrefix + 'QPushButton_hook_create';

procedure QRadioButton_hook_destroy; external QtShareName name QtNamePrefix + 'QRadioButton_hook_destroy';
function QRadioButton_hook_create; external QtShareName name QtNamePrefix + 'QRadioButton_hook_create';

procedure QScrollBar_hook_destroy; external QtShareName name QtNamePrefix + 'QScrollBar_hook_destroy';
function QScrollBar_hook_create; external QtShareName name QtNamePrefix + 'QScrollBar_hook_create';
procedure QScrollBar_hook_hook_valueChanged; external QtShareName name QtNamePrefix + 'QScrollBar_hook_hook_valueChanged';
procedure QScrollBar_hook_hook_sliderPressed; external QtShareName name QtNamePrefix + 'QScrollBar_hook_hook_sliderPressed';
procedure QScrollBar_hook_hook_sliderMoved; external QtShareName name QtNamePrefix + 'QScrollBar_hook_hook_sliderMoved';
procedure QScrollBar_hook_hook_sliderReleased; external QtShareName name QtNamePrefix + 'QScrollBar_hook_hook_sliderReleased';
procedure QScrollBar_hook_hook_nextLine; external QtShareName name QtNamePrefix + 'QScrollBar_hook_hook_nextLine';
procedure QScrollBar_hook_hook_prevLine; external QtShareName name QtNamePrefix + 'QScrollBar_hook_hook_prevLine';
procedure QScrollBar_hook_hook_nextPage; external QtShareName name QtNamePrefix + 'QScrollBar_hook_hook_nextPage';
procedure QScrollBar_hook_hook_prevPage; external QtShareName name QtNamePrefix + 'QScrollBar_hook_hook_prevPage';

procedure QSizeGrip_hook_destroy; external QtShareName name QtNamePrefix + 'QSizeGrip_hook_destroy';
function QSizeGrip_hook_create; external QtShareName name QtNamePrefix + 'QSizeGrip_hook_create';

procedure QTableView_hook_destroy; external QtShareName name QtNamePrefix + 'QTableView_hook_destroy';
function QTableView_hook_create; external QtShareName name QtNamePrefix + 'QTableView_hook_create';

procedure QTextBrowser_hook_destroy; external QtShareName name QtNamePrefix + 'QTextBrowser_hook_destroy';
function QTextBrowser_hook_create; external QtShareName name QtNamePrefix + 'QTextBrowser_hook_create';
procedure QTextBrowser_hook_hook_backwardAvailable; external QtShareName name QtNamePrefix + 'QTextBrowser_hook_hook_backwardAvailable';
procedure QTextBrowser_hook_hook_forwardAvailable; external QtShareName name QtNamePrefix + 'QTextBrowser_hook_hook_forwardAvailable';
procedure QTextBrowser_hook_hook_highlighted; external QtShareName name QtNamePrefix + 'QTextBrowser_hook_hook_highlighted';
procedure QTextBrowser_hook_hook_textChanged; external QtShareName name QtNamePrefix + 'QTextBrowser_hook_hook_textChanged';

procedure QTextView_hook_destroy; external QtShareName name QtNamePrefix + 'QTextView_hook_destroy';
function QTextView_hook_create; external QtShareName name QtNamePrefix + 'QTextView_hook_create';

procedure QWhatsThis_hook_destroy; external QtShareName name QtNamePrefix + 'QWhatsThis_hook_destroy';
function QWhatsThis_hook_create; external QtShareName name QtNamePrefix + 'QWhatsThis_hook_create';

procedure QWindowsStyle_hook_destroy; external QtShareName name QtNamePrefix + 'QWindowsStyle_hook_destroy';
function QWindowsStyle_hook_create; external QtShareName name QtNamePrefix + 'QWindowsStyle_hook_create';

procedure QTimer_hook_destroy; external QtShareName name QtNamePrefix + 'QTimer_hook_destroy';
function QTimer_hook_create; external QtShareName name QtNamePrefix + 'QTimer_hook_create';
procedure QTimer_hook_hook_timeout; external QtShareName name QtNamePrefix + 'QTimer_hook_hook_timeout';

procedure QWorkspace_hook_destroy; external QtShareName name QtNamePrefix + 'QWorkspace_hook_destroy';
function QWorkspace_hook_create; external QtShareName name QtNamePrefix + 'QWorkspace_hook_create';
procedure QWorkspace_hook_hook_windowActivated; external QtShareName name QtNamePrefix + 'QWorkspace_hook_hook_windowActivated';

procedure QClxFileIconProvider_hook_destroy; external QtShareName name QtNamePrefix + 'QClxFileIconProvider_hook_destroy';
function QClxFileIconProvider_hook_create; external QtShareName name QtNamePrefix + 'QClxFileIconProvider_hook_create';

procedure QClxFileDialog_hook_destroy; external QtShareName name QtNamePrefix + 'QClxFileDialog_hook_destroy';
function QClxFileDialog_hook_create; external QtShareName name QtNamePrefix + 'QClxFileDialog_hook_create';
procedure QClxFileDialog_hook_hook_fileHighlighted; external QtShareName name QtNamePrefix + 'QClxFileDialog_hook_hook_fileHighlighted';
procedure QClxFileDialog_hook_hook_fileSelected; external QtShareName name QtNamePrefix + 'QClxFileDialog_hook_hook_fileSelected';
procedure QClxFileDialog_hook_hook_dirEntered; external QtShareName name QtNamePrefix + 'QClxFileDialog_hook_hook_dirEntered';
procedure QClxFileDialog_hook_hook_closeRequest; external QtShareName name QtNamePrefix + 'QClxFileDialog_hook_hook_closeRequest';
procedure QClxFileDialog_hook_hook_filterChanged; external QtShareName name QtNamePrefix + 'QClxFileDialog_hook_hook_filterChanged';

procedure Qt_hook_hook_events; external QtShareName name QtNamePrefix + 'Qt_hook_hook_events';

procedure InitializePAnsiString; external QtShareName name QtNamePrefix + 'initPAnsiStrings';
procedure InitializePWideString; external QtShareName name QtNamePrefix + 'initPWideStrings';
procedure InitializePPointArray; external QtShareName name QtNamePrefix + 'initializePPointArray';
procedure InitializePIntArray; external QtShareName name QtNamePrefix + 'initializePIntArray';

procedure bitBlt(dst: QPaintDeviceH; dp: PPoint; src: QPaintDeviceH; sr: PRect;
  rop: RasterOp);
  external QtShareName name QtNamePrefix + 'bitBlt_1';
procedure bitBlt(dst: QPaintDeviceH; dx: Integer; dy: Integer;
  src: QPaintDeviceH; sx: Integer; sy: Integer; sw: Integer; sh: Integer;
  rop: RasterOp; IgnoreMask: Boolean);
  external QtShareName name QtNamePrefix + 'bitBlt_2';

function QClxWidget_MaxWidgetSize; external QtShareName name QtNamePrefix + 'QClxWidget_MaxWidgetSize';

procedure QWorkspace_next; external QtShareName name QtNamePrefix + 'QWorkspace_next';
procedure QWorkspace_previous; external QtShareName name QtNamePrefix + 'QWorkspace_previous';

{$IFDEF MSWINDOWS}
procedure setPopupParent; external QtShareName name QtNamePrefix + 'setPopupParent';
{$ENDIF}
{$IFDEF LINUX}
function QtDisplay; external QtShareName name QtNamePrefix + 'QtDisplay';
{$ENDIF}

function QMimeSource_is_QClxMimeSource; external QtShareName name QtNamePrefix + 'QMimeSource_is_QClxMimeSource';

function QByteArray_create; external QtShareName name QtNamePrefix + 'QByteArray_create';
procedure QByteArray_destroy; external QtShareName name QtNamePrefix + 'QByteArray_destroy';

function QEvent_isQCustomEvent; external QtShareName name QtNamePrefix + 'QEvent_isQCustomEvent';

function QEvent_isQShowEvent; external QtShareName name QtNamePrefix + 'QEvent_isQShowEvent';
function QEvent_isQTimerEvent; external QtShareName name QtNamePrefix + 'QEvent_isQTimerEvent';
function QEvent_isQMouseEvent; external QtShareName name QtNamePrefix + 'QEvent_isQMouseEvent';
function QEvent_isQWheelEvent; external QtShareName name QtNamePrefix + 'QEvent_isQWheelEvent';
function QEvent_isQKeyEvent; external QtShareName name QtNamePrefix + 'QEvent_isQKeyEvent';
function QEvent_isQFocusEvent; external QtShareName name QtNamePrefix + 'QEvent_isQFocusEvent';
function QEvent_isQPaintEvent; external QtShareName name QtNamePrefix + 'QEvent_isQPaintEvent';
function QEvent_isQMoveEvent; external QtShareName name QtNamePrefix + 'QEvent_isQMoveEvent';
function QEvent_isQResizeEvent; external QtShareName name QtNamePrefix + 'QEvent_isQResizeEvent';
function QEvent_isQCloseEvent; external QtShareName name QtNamePrefix + 'QEvent_isQCloseEvent';
function QEvent_isQHideEvent; external QtShareName name QtNamePrefix + 'QEvent_isQHideEvent';
function QEvent_isQDropEventEvent; external QtShareName name QtNamePrefix + 'QEvent_isQDropEventEvent';
function QEvent_isQDragMoveEvent; external QtShareName name QtNamePrefix + 'QEvent_isQDragMoveEvent';
function QEvent_isQDragEnterEvent; external QtShareName name QtNamePrefix + 'QEvent_isQDragEnterEvent';
function QEvent_isQDragResponseEvent; external QtShareName name QtNamePrefix + 'QEvent_isQDragResponseEvent';
function QEvent_isQDragLeaveEvent; external QtShareName name QtNamePrefix + 'QEvent_isQDragLeaveEvent';
function QEvent_isQChildEvent; external QtShareName name QtNamePrefix + 'QEvent_isQChildEvent';

function QObjectList_create: QObjectListH; cdecl; external QtShareName name QtNamePrefix + 'QObjectList_create';
function QObjectList_create(list: QObjectListH): QObjectListH; cdecl; external QtShareName name QtNamePrefix + 'QObjectList_create2';
procedure QObjectList_destroy; external QtShareName name QtNamePrefix + 'QObjectList_destroy';
function QObjectList_count; external QtShareName name QtNamePrefix + 'QObjectList_count';
function QObjectList_isEmpty; external QtShareName name QtNamePrefix + 'QObjectList_isEmpty';
function QObjectList_insert; external QtShareName name QtNamePrefix + 'QObjectList_insert';
procedure QObjectList_inSort; external QtShareName name QtNamePrefix + 'QObjectList_inSort';
procedure QObjectList_prepend; external QtShareName name QtNamePrefix + 'QObjectList_prepend';
procedure QObjectList_append; external QtShareName name QtNamePrefix + 'QObjectList_append';
function QObjectList_remove(obj: QObjectListH; i: Cardinal): Boolean; cdecl; external QtShareName name QtNamePrefix + 'QObjectList_remove';
function QObjectList_remove(obj: QObjectListH): Boolean; cdecl; external QtShareName name QtNamePrefix + 'QObjectList_remove2';
function QObjectList_remove(obj: QObjectListH; d: QObjectH): Boolean; cdecl; external QtShareName name QtNamePrefix + 'QObjectList_remove3';
function QObjectList_removeRef; external QtShareName name QtNamePrefix + 'QObjectList_removeRef';
function QObjectList_removeFirst; external QtShareName name QtNamePrefix + 'QObjectList_removeFirst';
function QObjectList_removeLast; external QtShareName name QtNamePrefix + 'QObjectList_removeLast';
function QObjectList_take(obj: QObjectListH; i: Cardinal): QObjectH; cdecl; external QtShareName name QtNamePrefix + 'QObjectList_take';
function QObjectList_take(obj: QObjectListH): QObjectH; cdecl; external QtShareName name QtNamePrefix + 'QObjectList_take2';
procedure QObjectList_clear; external QtShareName name QtNamePrefix + 'QObjectList_clear';
procedure QObjectList_sort; external QtShareName name QtNamePrefix + 'QObjectList_sort';
function QObjectList_find; external QtShareName name QtNamePrefix + 'QObjectList_find';
function QObjectList_findNext; external QtShareName name QtNamePrefix + 'QObjectList_findNext';
function QObjectList_findRef; external QtShareName name QtNamePrefix + 'QObjectList_findRef';
function QObjectList_findNextRef; external QtShareName name QtNamePrefix + 'QObjectList_findRef';
function QObjectList_contains; external QtShareName name QtNamePrefix + 'QObjectList_contains';
function QObjectList_containsRef; external QtShareName name QtNamePrefix + 'QObjectList_containsRef';
function QObjectList_at(obj: QObjectListH; i: Cardinal): QObjectH; cdecl; external QtShareName name QtNamePrefix + 'QObjectList_at';
function QObjectList_at(obj: QObjectListH): Integer; cdecl; external QtShareName name QtNamePrefix + 'QObjectList_at2';
function QObjectList_current; external QtShareName name QtNamePrefix + 'QObjectList_current';
function QObjectList_getFirst; external QtShareName name QtNamePrefix + 'QObjectList_current';
function QObjectList_getLast; external QtShareName name QtNamePrefix + 'QObjectList_getLast';
function QObjectList_first; external QtShareName name QtNamePrefix + 'QObjectList_first';
function QObjectList_last; external QtShareName name QtNamePrefix + 'QObjectList_last';
function QObjectList_next; external QtShareName name QtNamePrefix + 'QObjectList_next';
function QObjectList_prev; external QtShareName name QtNamePrefix + 'QObjectList_prev';

function QWidgetList_create: QWidgetListH; cdecl; external QtShareName name QtNamePrefix + 'QWidgetList_create';
function QWidgetList_create(list: QWidgetListH): QWidgetListH; cdecl; external QtShareName name QtNamePrefix + 'QWidgetList_create2';
procedure QWidgetList_destroy; external QtShareName name QtNamePrefix + 'QWidgetList_destroy';
function QWidgetList_count; external QtShareName name QtNamePrefix + 'QWidgetList_count';
function QWidgetList_insert; external QtShareName name QtNamePrefix + 'QWidgetList_insert';
function QWidgetList_remove(obj: QWidgetListH; i: Cardinal): Boolean; cdecl; external QtShareName name QtNamePrefix + 'QWidgetList_remove';
function QWidgetList_remove(obj: QWidgetListH; d: QWidgetH): Boolean; cdecl; external QtShareName name QtNamePrefix + 'QWidgetList_remove3';
procedure QWidgetList_clear; external QtShareName name QtNamePrefix + 'QWidgetList_clear';
function QWidgetList_find; external QtShareName name QtNamePrefix + 'QWidgetList_find';
function QWidgetList_findNext; external QtShareName name QtNamePrefix + 'QWidgetList_findNext';
function QWidgetList_contains; external QtShareName name QtNamePrefix + 'QWidgetList_contains';
function QWidgetList_at(obj: QWidgetListH; i: Cardinal): QWidgetH; cdecl; external QtShareName name QtNamePrefix + 'QWidgetList_at';
function QWidgetList_current; external QtShareName name QtNamePrefix + 'QWidgetList_current';
function QWidgetList_first; external QtShareName name QtNamePrefix + 'QWidgetList_first';
function QWidgetList_last; external QtShareName name QtNamePrefix + 'QWidgetList_last';
function QWidgetList_next; external QtShareName name QtNamePrefix + 'QWidgetList_next';
function QWidgetList_prev; external QtShareName name QtNamePrefix + 'QWidgetList_prev';

function QBitmap_from_QPixmap; external QtShareName name QtNamePrefix + 'QBitmap_from_QPixmap';
 
end. 
