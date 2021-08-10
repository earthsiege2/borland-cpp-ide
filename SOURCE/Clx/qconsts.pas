{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QConsts;

interface

const
  // Delphi mime types
  SDelphiBitmap = 'image/delphi.bitmap';
  SDelphiComponent = 'application/delphi.component';
  SDelphiPicture = 'image/delphi.picture';
  SDelphiDrawing = 'image/delphi.drawing';

resourcestring
  SInvalidCreateWidget = 'Class %s could not create QT widget';
  STooManyMessageBoxButtons = 'Too many buttons specified for message box';

  SmkcBkSp = 'Backspace';
  SmkcTab = 'Tab';
  SmkcBackTab = 'BackTab';
  SmkcEsc = 'Esc';
  SmkcReturn = 'Return';
  SmkcEnter = 'Enter';
  SmkcSpace = 'Space';
  SmkcPgUp = 'PgUp';
  SmkcPgDn = 'PgDn';
  SmkcEnd = 'End';
  SmkcHome = 'Home';
  SmkcLeft = 'Left';
  SmkcUp = 'Up';
  SmkcRight = 'Right';
  SmkcDown = 'Down';
  SmkcIns = 'Ins';
  SmkcDel = 'Del';
  SmkcShift = 'Shift+';
  SmkcCtrl = 'Ctrl+';
  SmkcAlt = 'Alt+';

  SOpenFileTitle = 'Open';
  SAssignError = 'Cannot assign a %s to a %s';
  SFCreateError = 'Cannot create file %s';
  SFOpenError = 'Cannot open file %s';
  SReadError = 'Stream read error';
  SWriteError = 'Stream write error';
  SMemoryStreamError = 'Out of memory while expanding memory stream';
  SCantWriteResourceStreamError = 'Can''t write to a read-only resource stream';
  SDuplicateReference = 'WriteObject called twice for the same instance';
  SClassNotFound = 'Class %s not found';
  SInvalidImage = 'Invalid stream format';
  SResNotFound = 'Resource %s not found';
  SClassMismatch = 'Resource %s is of incorrect class';
  SListIndexError = 'List index out of bounds (%d)';
  SListCapacityError = 'List capacity out of bounds (%d)';
  SListCountError = 'List count out of bounds (%d)';
  SSortedListError = 'Operation not allowed on sorted string list';
  SDuplicateString = 'String list does not allow duplicates';
  SInvalidTabIndex = 'Tab index out of bounds';
  SInvalidTabPosition = 'Tab position incompatible with current tab style';
  SInvalidTabStyle = 'Tab style incompatible with current tab position';
  SDuplicateName = 'A component named %s already exists';
  SInvalidName = '''''%s'''' is not a valid component name';
  SDuplicateClass = 'A class named %s already exists';
  SInvalidInteger = '''''%s'''' is not a valid integer value';
  SLineTooLong = 'Line too long';
  SInvalidPropertyValue = 'Invalid property value';
  SInvalidPropertyPath = 'Invalid property path';
  SInvalidPropertyType = 'Invalid property type: %s';
  SInvalidPropertyElement = 'Invalid property element: %s';
  SUnknownProperty = 'Property does not exist';
  SReadOnlyProperty = 'Property is read-only';
  SPropertyException = 'Error reading %s%s%s: %s';
  SAncestorNotFound = 'Ancestor for ''%s'' not found';
  SInvalidBitmap = 'Bitmap image is not valid';
  SInvalidIcon = 'Icon image is not valid';
  SInvalidPixelFormat = 'Invalid pixel format';
  SBitmapEmpty = 'Bitmap is empty';
  SScanLine = 'Scan line index out of range';
  SChangeIconSize = 'Cannot change the size of an icon';
  SUnknownExtension = 'Unknown picture file extension (.%s)';
  SUnknownClipboardFormat = 'Unsupported clipboard format';
  SOutOfResources = 'Out of system resources';
  SNoCanvasHandle = 'Canvas does not allow drawing';
  SInvalidCanvasState = 'Invalid canvas state request';
  SInvalidImageSize = 'Invalid image size';
  SInvalidWidgetHandle = 'Invalid widget handle';
  SInvalidColorDepth = 'Color depth must be 1, 8 or 32 bpp';
  STooManyImages = 'Too many images';
  SWidgetCreate = 'Error creating widget';
  SCannotFocus = 'Cannot focus a disabled or invisible window (%s)';
  SParentRequired = 'Control ''%s'' has no parent widget';
  SParentGivenNotAParent = 'Parent given is not a parent of ''%s''';
  SVisibleChanged = 'Cannot change Visible in OnShow or OnHide';
  SCannotShowModal = 'Cannot make a visible window modal';
  SScrollBarRange = 'Scrollbar property out of range';
  SPropertyOutOfRange = '%s property out of range';
  SMenuIndexError = 'Menu index out of range';
  SMenuReinserted = 'Menu inserted twice';
  SNoMenuRecursion = 'Menu insertion recursion not allowed';
  SMenuNotFound = 'Sub-menu is not in menu';
  SMenuSetFormError = 'TMenu.SetForm: argument must be TCustomForm';
  SNoTimers = 'Not enough timers available';
  SNotPrinting = 'Printer is not currently printing';
  SPrinting = 'Printing in progress';
  SNoAdapter = 'No printer adapter available for printing';
  SPrinterIndexError = 'Printer index out of range';
  SInvalidPrinter = 'Printer selected is not valid';
  SDeviceOnPort = '%s on %s';
  SGroupIndexTooLow = 'GroupIndex cannot be less than a previous menu item''s GroupIndex';
  SNoMDIForm = 'Cannot create form. No MDI forms are currently active';
  SNotAnMDIForm = 'Invalid MDIParent for class %s';
  SMDIChildNotVisible = 'Cannot hide an MDI Child Form';
  SRegisterError = 'Invalid component registration';
  SImageCanvasNeedsBitmap = 'Can only modify an image if it contains a bitmap';
  SControlParentSetToSelf = 'A control cannot have itself as its parent';
  SOKButton = 'OK';
  SCancelButton = 'Cancel';
  SYesButton = '&Yes';
  SNoButton = '&No';
  SHelpButton = '&Help';
  SCloseButton = '&Close';
  SIgnoreButton = '&Ignore';
  SRetryButton = '&Retry';
  SAbortButton = 'Abort';
  SAllButton = '&All';

  SCannotDragForm = 'Cannot drag a form';
  SPutObjectError = 'PutObject to undefined item';

  SFB = 'FB';
  SFG = 'FG';
  SBG = 'BG';
  SVIcons = 'Icons';
  SVBitmaps = 'Bitmaps';
  SVPixmaps = 'Pixmaps';
  SVPNGs = 'PNGs';
  SDrawings = 'Drawings';
  SGridTooLarge = 'Grid too large for operation';
  STooManyDeleted = 'Too many rows or columns deleted';
  SIndexOutOfRange = 'Grid index out of range';
  SFixedColTooBig = 'Fixed column count must be less than column count';
  SFixedRowTooBig = 'Fixed row count must be less than row count';
  SInvalidStringGridOp = 'Cannot insert or delete rows from grid';
  SParseError = '%s on line %d';
  SIdentifierExpected = 'Identifier expected';
  SStringExpected = 'String expected';
  SNumberExpected = 'Number expected';
  SCharExpected = '''''%s'''' expected';
  SSymbolExpected = '%s expected';
  SInvalidNumber = 'Invalid numeric value';
  SInvalidString = 'Invalid string constant';
  SInvalidProperty = 'Invalid property value';
  SInvalidBinary = 'Invalid binary value';
  SInvalidCurrentItem = 'Invalid value for current item';
  SMaskErr = 'Invalid input value';
  SMaskEditErr = 'Invalid input value.  Use escape key to abandon changes';

  SMsgDlgWarning = 'Warning';
  SMsgDlgError = 'Error';
  SMsgDlgInformation = 'Information';
  SMsgDlgConfirm = 'Confirm';
  SMsgDlgYes = '&Yes';
  SMsgDlgNo = '&No';
  SMsgDlgOK = 'OK';
  SMsgDlgCancel = 'Cancel';
  SMsgDlgHelp = '&Help';
  SMsgDlgHelpNone = 'No help available';
  SMsgDlgHelpHelp = 'Help';
  SMsgDlgAbort = '&Abort';
  SMsgDlgRetry = '&Retry';
  SMsgDlgIgnore = '&Ignore';
  SMsgDlgAll = '&All';
  SMsgDlgNoToAll = 'N&o to All';
  SMsgDlgYesToAll = 'Yes to &All';

  srUnknown = '(Unknown)';
  srNone = '(None)';
  SOutOfRange = 'Value must be between %d and %d';
  SCannotCreateName = 'Cannot create a default method name for an unnamed component';
  SUnnamed = 'Unnamed';

  SDateEncodeError = 'Invalid argument to date encode';
  STimeEncodeError = 'Invalid argument to time encode';
  SInvalidDate = '''''%s'''' is not a valid date';
  SInvalidTime = '''''%s'''' is not a valid time';
  SInvalidDateTime = '''''%s'''' is not a valid date and time';
  SInvalidFileName = 'Invalid file name - %s';
  SDefaultFilter = 'All files (*.*)|*.*';
  SInsertLineError = 'Unable to insert a line';

  SConfirmCreateDir = 'The specified directory does not exist. Create it?';
  SSelectDirCap = 'Select Directory';
  SCannotCreateDir = 'Unable to create directory';
  SDirNameCap = 'Directory &Name:';
  SDrivesCap = 'D&rives:';
  SDirsCap = '&Directories:';
  SFilesCap = '&Files: (*.*)';
  SNetworkCap = 'Ne&twork...';

  SInvalidClipFmt = 'Invalid clipboard format';
  SIconToClipboard = 'Clipboard does not support Icons';
  SCannotOpenClipboard = 'Cannot open clipboard';

  SInvalidActionRegistration = 'Invalid action registration';
  SInvalidActionUnregistration = 'Invalid action unregistration';
  SInvalidActionEnumeration = 'Invalid action enumeration';
  SInvalidActionCreation = 'Invalid action creation';

  SDefault = 'Default';

  SInvalidMemoSize = 'Text exceeds memo capacity';
  SCustomColors = 'Custom Colors';
  SInvalidPrinterOp = 'Operation not supported on selected printer';
  SNoDefaultPrinter = 'There is no default printer currently selected';

  SIniFileWriteError = 'Unable to write to %s';

  SBitsIndexError = 'Bits index out of range';

  SUntitled = '(Untitled)';

  SDuplicateMenus = 'Menu ''%s'' is already being used by another form';

  SPictureLabel = 'Picture:';
  SPictureDesc = ' (%dx%d)';
  SPreviewLabel = 'Preview';

  SBoldItalicFont = 'Bold Italic';
  SBoldFont = 'Bold';
  SItalicFont = 'Italic';
  SRegularFont = 'Regular';

  SPropertiesVerb = 'Properties';

  sAsyncSocketError = 'Asynchronous socket error %d';
  sNoAddress = 'No address specified';
  sCannotListenOnOpen = 'Can''t listen on an open socket';
  sCannotCreateSocket = 'Can''t create new socket';
  sSocketAlreadyOpen = 'Socket already open';
  sCantChangeWhileActive = 'Can''t change value while socket is active';
  sSocketMustBeBlocking = 'Socket must be in blocking mode';
  sSocketIOError = '%s error %d, %s';
  sSocketRead = 'Read';
  sSocketWrite = 'Write';

  SAllCommands = 'All Commands';

  SDuplicateItem = 'List does not allow duplicates ($0%x)';

  SDuplicatePropertyCategory = 'A property category called %s already exists';
  SUnknownPropertyCategory = 'Property category does not exist (%s)';

  SInvalidMask = '''%s'' is an invalid mask at (%d)';
  SInvalidFilter = 'Property filters may only be name, class or type based (%d:%d)';
  SInvalidCategory = 'Categories must define their own name and description';

  sOperationNotAllowed = 'Operation not allowed while dispatching application events';
  STextNotFound = 'Text not found: "%s"';

  SImageIndexError = 'Invalid ImageList Index';
  SReplaceImage = 'Unable to Replace Image';
  SInvalidImageType = 'Invalid image type';
  SInvalidImageDimensions = 'Image width and heigth must match';
  SInvalidImageDimension = 'Invalid image dimension';
  SErrorResizingImageList = 'Error resizing ImageList';

  SInvalidRangeError = 'Range of %d to %d is invalid';
  SInvalidMimeSourceStream = 'MimeSource format must have an associated data stream';
  SMimeNotSupportedForIcon = 'Mime format not supported for TIcon';

  SOpen = 'Open';
  SSave = 'Save As';
  SFindWhat = 'Fi&nd what:';
  SWholeWord = 'Match &whole word only';
  SMatchCase = 'Match &case';
  SFindNext = '&Find Next';
  SCancel = 'Cancel';
  SHelp = 'Help';
  SFindTitle = 'Find';
  SDirection = 'Direction';
  SUp = '&Up';
  SDown = '&Down';
  SReplaceWith = 'Rep&lace with:';
  SReplace = '&Replace';
  SReplaceTitle = 'Replace';
  SReplaceAll = 'Replace &All';
  SOverwriteCaption = 'Save %s as';
  SOverwriteText = '%s already exists.'#13'Do you want to replace it?';
  SFileMustExist = '%s'#13'File not found.'#13'Please verify the correct '+
    'filename was given.';
  SPathMustExist = '%s'#13'Path not found.'#13'Please verify the correct '+
    'path was given.';

  SUnknownImageFormat = 'Image format not recognized';
  SInvalidHandle = 'Invalid handle value for %s';
  SUnableToWrite = 'Unable to write bitmap';
  sAllFilter = 'All';

  sInvalidSetClipped = 'Cannot set Clipped property while painting';

  sInvalidLCDValue = 'Invalid LCDNumber value';

  sTabFailDelete = 'Failed to delete tab at index %d';
  sPageIndexError = '%d is an invalid PageIndex value.  PageIndex must be ' +
    'between 0 and %d';
  sInvalidLevel = 'Invalid item level assignment';
  sInvalidLevelEx = 'Invalid level (%d) for item "%s"';
  sTabMustBeMultiLine = 'MultiLine must be True when TabPosition is tpLeft or tpRight';
  sStatusBarContainsControl = '%s is already in the StatusBar';
  sListRadioItemBadParent = 'Radio items must have a Controller as a parent';
  sOwnerNotCustomHeaderSections = 'Owner is not a TCustomHeaderSection';
  sHeaderSectionOwnerNotHeaderControl = 'Header Section owner must be a TCustomHeaderControl';

  SUndo = 'Undo';
  SRedo = 'Redo';
  SLine = '-';
  SCut = 'Cut';
  SCopy = 'Copy';
  SPaste = 'Paste';
  SClear = 'Clear';
  SSelectAll = 'Select All';

implementation

end.
 
