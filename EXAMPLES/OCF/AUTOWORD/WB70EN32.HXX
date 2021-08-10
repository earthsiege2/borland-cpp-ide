// Type Library: WB70EN32.TLB  Microsoft WordBasic 95 Type Library
// Word 7.0 {5ECD1920-D1CA-11CE-AA2F-00AA006156DA}\9

#include <ocf/automacr.h>

class WordBasic;

// TKIND_DISPATCH: WordBasic 7.0 {00020400-0000-0000-C000-000000000046}\9

class WordBasic : public TAutoProxy {
  public:
    WordBasic() : TAutoProxy(0x9) {}
    // (Macintosh only)
    void AOCEAddRecipient(TAutoString Recipient, short AddressType, TAutoString Mailslot); // [id(0x81e4), method]
    // (Macintosh only)
    short AOCEAuthenticateUser(short AllowPrompt); // [id(0x81ec), method]
    // (Macintosh only)
    void AOCEClearMailerField(short FieldNumber); // [id(0x81ed), method]
    // (Macintosh only)
    short AOCECountRecipients(short AddressType); // [id(0x81e5), method]
    // (Macintosh only)
    TAutoString AOCEGetRecipient(short RecipientNumber, short AddressType); // [id(0x81e6), method]
    // (Macintosh only)
    TAutoString AOCEGetSender(); // [id(0x81e7), method]
    // (Macintosh only)
    TAutoString AOCEGetSubject(); // [id(0x81e9), method]
    // (Macintosh only)
    void AOCESendMail(short SignLetter, short Priority, short SendAppleMail, short SendImage, short SendWordDoc, TAutoString Format); // [id(0x81eb), method]
    // (Macintosh only)
    void AOCESetSubject(TAutoString Subject); // [id(0x81ea), method]
    // (Macintosh only)
    void EditCopyAsPicture(); // [id(751), method]
    // (Macintosh only)
    void EditCreatePublisher(TAutoString FileName, short Apperance, short RTF, short Pict); // [id(732), method]
    // (Macintosh only)
    void EditFindBorder(short ApplyTo, short Shadow, short TopBorder, short LeftBorder, short BottomBorder, short RightBorder, short HorizBorder, short VertBorder, short TopColor, short LeftColor, short BottomColor, short RightColor, short HorizColor, short VertColor, TAutoVal& FromText, short Shading, short Foreground, short Background, short Tab, short FineShading); // [id(447), method]
    // (Macintosh only)
    void EditFindFrame(short Wrap, short WidthRule, TAutoVal& FixedWidth, short HeightRule, TAutoVal& FixedHeight, TAutoVal& PositionHorz, short PositionHorzRel, TAutoVal& DistFromText, TAutoVal& PositionVert, short PositionVertRel, TAutoVal& DistVertFromText, short MoveWithText, short LockAnchor, TAutoVal& RemoveFrame); // [id(448), method]
    // (Macintosh only)
    void EditFindTabs(TAutoString Position, TAutoString DefTabs, short Align, short Leader, TAutoVal& Set, TAutoVal& Clear, TAutoVal& ClearAll); // [id(446), method]
    // (Macintosh only)
    void EditPublishOptions(short SendManually, short SendEditionNow, short SendEditionWhenEdited, TAutoVal& Delete, short Apperance, short RTF, short Pict); // [id(735), method]
    // (Macintosh only)
    void EditReplaceBorder(short ApplyTo, short Shadow, short TopBorder, short LeftBorder, short BottomBorder, short RightBorder, short HorizBorder, short VertBorder, short TopColor, short LeftColor, short BottomColor, short RightColor, short HorizColor, short VertColor, TAutoVal& FromText, short Shading, short Foreground, short Background, short Tab, short FineShading); // [id(457), method]
    // (Macintosh only)
    void EditReplaceFrame(short Wrap, short WidthRule, TAutoVal& FixedWidth, short HeightRule, TAutoVal& FixedHeight, TAutoVal& PositionHorz, short PositionHorzRel, TAutoVal& DistFromText, TAutoVal& PositionVert, short PositionVertRel, TAutoVal& DistVertFromText, short MoveWithText, short LockAnchor, TAutoVal& RemoveFrame); // [id(458), method]
    // (Macintosh only)
    void EditReplaceTabs(TAutoString Position, TAutoString DefTabs, short Align, short Leader, TAutoVal& Set, TAutoVal& Clear, TAutoVal& ClearAll); // [id(456), method]
    // (Macintosh only)
    void EditSubscribeOptions(short GetManually, short GetEditionNow, short Format, short KeepFormatting); // [id(736), method]
    // (Macintosh only)
    void EditSubscribeTo(TAutoString FileName, short Format, short GetManually); // [id(733), method]
    // (Macintosh only)
    void FileAOCEAddMailer(); // [id(312), method]
    // (Macintosh only)
    void FileAOCEDeleteMailer(); // [id(313), method]
    // (Macintosh only)
    void FileAOCEExpandMailer(); // [id(314), method]
    // (Macintosh only)
    void FileAOCEForwardMail(); // [id(318), method]
    // (Macintosh only)
    void FileAOCENextLetter(); // [id(319), method]
    // (Macintosh only)
    void FileAOCEReplyAllMail(); // [id(317), method]
    // (Macintosh only)
    void FileAOCEReplyMail(); // [id(316), method]
    // (Macintosh only)
    void FileAOCESendMail(); // [id(315), method]
    // (Macintosh only)
    TAutoString FileCreator(TAutoString File); // [id(0x81f5), method]
    void FileMacCustomPageSetupGX(TAutoVal& PageWidth, TAutoVal& PageHeight, short Orientation, short ApplyPropsTo); // [id(737), method]
    // (Macintosh only)
    void FileMacPageSetup(TAutoVal& PageWidth, TAutoVal& PageHeight, short Orientation, short ApplyPropsTo, TAutoVal& Default); // [id(685), method]
    // (Macintosh only)
    void FileMacPageSetupGX(TAutoVal& PageWidth, TAutoVal& PageHeight, short Orientation); // [id(444), method]
    // (Macintosh only)
    void FilePrintOneCopy(); // [id(738), method]
    // (Macintosh only)
    TAutoString FileType(TAutoString File); // [id(0x81f4), method]
    // (Not in Word 6.0)
    void ListCommands(TAutoVal& ListType); // [id(723), method]
    // (Macintosh only)
    TAutoString MacID(TAutoString Identifier); // [id(0x816e), method]
    // (Macintosh only) Runs an existing AppleScript(TM) resource, or passes the specified string to the defualt scripting language to compile and run
    void MacScript(); // [id(0x816c), method]
    // (Macintosh only) Runs an existing AppleScript(TM) resource, or passes the specified string to the defualt scripting language to compile and run and returns a string with the return value of the script
    TAutoString MacScriptStr(TAutoString Script); // [id(0x816d), method]
    // (Macintosh only)
    short MountVolume(TAutoString Zone, TAutoString Server, TAutoString Volume, TAutoString User, TAutoString UserPassword, TAutoString VolumePassword); // [id(0x815e), method]
    // (Macintosh only)
    void Outline(short On); // [id(0x81f3), method]
    // (Macintosh only)
    void SetFileCreatorAndType(TAutoString File, TAutoString Creator, TAutoString Type); // [id(0x81f6), method]
    // (Macintosh only)
    void Shadow(short On); // [id(0x81f2), method]
    // (Macintosh only)
    void ShowClipboard(); // [id(459), method]
    // Displays Help for the current task or command
    void Help(); // [id(1), method]
    // Connects to a desired forum on The Microsoft Network
    void HelpMSN(); // [id(795), method]
    // Lets you get help on a command or screen region or examine text properties
    void HelpTool(); // [id(2), method]
    // Displays the instructions for how to use Help
    void HelpUsingHelp(); // [id(3), method]
    // Displays the information about the active pane or document view
    void HelpActiveWindow(); // [id(4), method]
    // Lists the keys and their actions
    void HelpKeyboard(); // [id(5), method]
    // Displays Help index
    void HelpIndex(); // [id(6), method]
    // Word 6.0 only: Lists the lessons for getting started with Word
    void HelpQuickPreview(); // [id(7), method]
    // Word 6.0 only: Lists the lessons for learning Word
    void HelpExamplesAndDemos(); // [id(8), method]
    // Displays the program information, Word version number, and the copyright
    void HelpAbout(TAutoVal& Appname, TAutoVal& AppCopyright, TAutoVal& AppUserName, TAutoVal& AppOrganization, TAutoVal& AppSerialNumber); // [id(9), method]
    // Not in all languages: Shows the equivalent for a WordPerfect command
    void HelpWordPerfectHelp(TAutoVal& WPCommand, TAutoVal& HelpText, TAutoVal& DemoGuidance); // [id(10), method]
    // Increases the font size of the selection
    void GrowFont(); // [id(11), method]
    // Decreases the font size of the selection
    void ShrinkFont(); // [id(12), method]
    // Deletes the selection and adds it to the special AutoText entry
    void Spike(); // [id(15), method]
    // Empties the spike AutoText entry and inserts all of its contents into the document
    void InsertSpike(); // [id(16), method]
    // Moves the selection to a specified location
    void MoveText(); // [id(18), method]
    // Makes a copy of the selection at a specified location
    void CopyText(); // [id(19), method]
    // Replaces the name of the AutoText entry with its contents
    void InsertAutoText(); // [id(20), method]
    // Switches to the other window pane
    void OtherPane(); // [id(21), method]
    // Switches to the next document window
    void NextWindow(); // [id(22), method]
    // Switches back to the previous document window
    void PrevWindow(); // [id(23), method]
    // Repeats Go To or Find to find the next occurrence
    void RepeatFind(); // [id(24), method]
    // Deletes the next word without putting it on the Clipboard
    void DeleteWord(); // [id(28), method]
    // Deletes the previous word without putting it on the Clipboard
    void DeleteBackWord(); // [id(29), method]
    // Inserts a field with the enclosing field characters
    void InsertFieldChars(); // [id(31), method]
    // Updates and displays the results of the selected fields
    void UpdateFields(); // [id(32), method]
    // Permanently replaces the field codes with the results
    void UnlinkFields(); // [id(33), method]
    // Shows the field codes or the results for the selection (toggle)
    void ToggleFieldDisplay(); // [id(34), method]
    // Locks the selected fields to prevent updating
    void LockFields(); // [id(35), method]
    // Unlocks the selected fields for updating
    void UnlockFields(); // [id(36), method]
    // Copies the modified text of a linked file back to its source
    void UpdateSource(); // [id(37), method]
    // Moves the left indent to the next tab stop
    void Indent(); // [id(38), method]
    // Moves the left indent to the previous tab stop
    void UnIndent(); // [id(39), method]
    // Increases the hanging indent
    void HangingIndent(); // [id(40), method]
    // Decreases the hanging indent
    void UnHang(); // [id(41), method]
    // Changes the font size of the selection
    void FontSizeSelect(); // [id(43), method]
    // Repeats the last action
    void EditRepeat(); // [id(68), method]
    // Returns to the previous insertion point
    void GoBack(); // [id(69), method]
    // Saves the document template of the active document
    void SaveTemplate(); // [id(70), method]
    // Confirms a location for copying or moving the selection
    void OK(); // [id(71), method]
    // Terminates an action
    void Cancel(); // [id(72), method]
    // Copies the formatting of the selection to a specified location
    void CopyFormat(); // [id(73), method]
    // Displays the statistics of the active document
    void DocumentStatistics(TAutoVal& FileName, TAutoVal& Directory, TAutoVal& Template, TAutoVal& Title, TAutoVal& Created, TAutoVal& LastSaved, TAutoVal& LastSavedBy, TAutoVal& Revision, TAutoVal& Time, TAutoVal& Printed, TAutoVal& Pages, TAutoVal& Words, TAutoVal& Characters, TAutoVal& Paragraphs, TAutoVal& Lines, TAutoVal& FileSize); // [id(78), method]
    // Creates a new document or template
    void FileNew(TAutoVal& Template, TAutoVal& NewTemplate); // [id(79), method]
    // Opens an existing document or template
    void FileOpen(TAutoVal& Name, TAutoVal& ConfirmConversions, TAutoVal& ReadOnly, TAutoVal& LinkToSource, TAutoVal& AddToMru, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& Revert, TAutoVal& WritePasswordDoc, TAutoVal& WritePasswordDot, TAutoVal& Connection, TAutoVal& SQLStatement, TAutoVal& SQLStatement1); // [id(80), method]
    // Opens a data source for mail merge or insert database
    void MailMergeOpenDataSource(TAutoVal& Name, TAutoVal& ConfirmConversions, TAutoVal& ReadOnly, TAutoVal& LinkToSource, TAutoVal& AddToMru, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& Revert, TAutoVal& WritePasswordDoc, TAutoVal& WritePasswordDot, TAutoVal& Connection, TAutoVal& SQLStatement, TAutoVal& SQLStatement1); // [id(81), method]
    // Opens a header source for mail merge
    void MailMergeOpenHeaderSource(TAutoVal& Name, TAutoVal& ConfirmConversions, TAutoVal& ReadOnly, TAutoVal& LinkToSource, TAutoVal& AddToMru, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& Revert, TAutoVal& WritePasswordDoc, TAutoVal& WritePasswordDot, TAutoVal& Connection, TAutoVal& SQLStatement, TAutoVal& SQLStatement1); // [id(82), method]
    // Saves the active document or template
    void FileSave(); // [id(83), method]
    // Saves a copy of the document in a separate file (SaveAsAOCELetter is not valid in Word 6.0 and Word 6.0a
    void FileSaveAs(TAutoVal& Name, TAutoVal& Format, TAutoVal& LockAnnot, TAutoVal& Password, TAutoVal& AddToMru, TAutoVal& WritePassword, TAutoVal& RecommendReadOnly, TAutoVal& EmbedFonts, TAutoVal& NativePictureFormat, TAutoVal& FormsData, TAutoVal& SaveAsAOCELetter); // [id(84), method]
    // Shows the summary information about the active document
    void FileSummaryInfo(TAutoVal& Title, TAutoVal& Subject, TAutoVal& Author, TAutoVal& Keywords, TAutoVal& Comments, TAutoVal& FileName, TAutoVal& Directory, TAutoVal& Template, TAutoVal& CreateDate, TAutoVal& LastSavedDate, TAutoVal& LastSavedBy, TAutoVal& RevisionNumber, TAutoVal& EditTime, TAutoVal& LastPrintedDate, TAutoVal& NumPages, TAutoVal& NumWords, TAutoVal& NumChars, TAutoVal& NumParas, TAutoVal& NumLines, TAutoVal& Update, TAutoVal& FileSize); // [id(86), method]
    // Changes the active template and the template options
    void FileTemplates(TAutoVal& Store, TAutoVal& Template, TAutoVal& LinkStyles); // [id(87), method]
    // Prints the active document (the parameters Printer and OutputPrinter are only valid in Word 95)
    void FilePrint(TAutoVal& Background, TAutoVal& Printer, TAutoVal& OutputPrinter, TAutoVal& AppendPrFile, TAutoVal& Range, TAutoVal& PrToFileName, TAutoVal& From, TAutoVal& To, TAutoVal& Type, TAutoVal& NumCopies, TAutoVal& Pages, TAutoVal& Order, TAutoVal& PrintToFile, TAutoVal& Collate, TAutoVal& FileName); // [id(88), method]
    // Resets a mail merge main document to a normal document
    void MailMergeReset(); // [id(96), method]
    // Changes the printer and the printing options (DoNotSetAsSysDefault is only valid in Word 95, Network is not valid in Word 95)
    void FilePrintSetup(TAutoVal& Printer, TAutoVal& Options, TAutoVal& Network, TAutoVal& DoNotSetAsSysDefault); // [id(97), method]
    // Locates the documents in any directory, drive, or folder (ShowFolders is not valid in Word 6.0)
    void FileFind(TAutoVal& SearchName, TAutoVal& SearchPath, TAutoVal& Name, TAutoVal& SubDir, TAutoVal& Title, TAutoVal& Author, TAutoVal& Keywords, TAutoVal& Subject, TAutoVal& Options, TAutoVal& MatchCase, TAutoVal& Text, TAutoVal& PatternMatch, TAutoVal& DateSavedFrom, TAutoVal& DateSavedTo, TAutoVal& SavedBy, TAutoVal& DateCreatedFrom, TAutoVal& DateCreatedTo, TAutoVal& View, TAutoVal& SortBy, TAutoVal& ListBy, TAutoVal& SelectedFile, TAutoVal& Add, TAutoVal& Delete, TAutoVal& ShowFolders); // [id(99), method]
    // Formats the delivery address font for envelopes   (Shadow is only valid on the Macintosh)
    void FormatAddrFonts(TAutoVal& Points, TAutoVal& Underline, TAutoVal& Color, TAutoVal& Strikethrough, TAutoVal& Superscript, TAutoVal& Subscript, TAutoVal& Hidden, TAutoVal& SmallCaps, TAutoVal& AllCaps, TAutoVal& Spacing, TAutoVal& Position, TAutoVal& Kerning, TAutoVal& KerningMin, TAutoVal& Default, TAutoVal& Tab, TAutoVal& Font, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Outline, TAutoVal& Shadow); // [id(103), method]
    // Opens a mail merge data source
    void MailMergeEditDataSource(); // [id(104), method]
    // Cuts the selection and puts it on the Clipboard
    void EditCut(); // [id(108), method]
    // Copies the selection and puts it on the Clipboard
    void EditCopy(); // [id(109), method]
    // Inserts the Clipboard contents at the insertion point
    void EditPaste(); // [id(110), method]
    // Inserts the Clipboard contents as a linked object, embedded object, or other format
    void EditPasteSpecial(TAutoVal& IconNumber, TAutoVal& Link, TAutoVal& DisplayIcon, TAutoVal& Class, TAutoVal& DataType, TAutoVal& IconFilename, TAutoVal& Caption); // [id(111), method]
    // Finds the specified text or the specified formatting (FindAllWordFors is only valid for some languages and only in Word 95)
    void EditFind(TAutoVal& Find, TAutoVal& Replace, TAutoVal& Direction, TAutoVal& MatchCase, TAutoVal& WholeWord, TAutoVal& PatternMatch, TAutoVal& SoundsLike, TAutoVal& FindNext, TAutoVal& ReplaceOne, TAutoVal& ReplaceAll, TAutoVal& Format, TAutoVal& Wrap, TAutoVal& FindAllWordForms); // [id(112), method]
    // (Outline and Shadow are only valid on Macintosh)
    void EditFindFont(TAutoVal& Points, TAutoVal& Underline, TAutoVal& Color, TAutoVal& Strikethrough, TAutoVal& Superscript, TAutoVal& Subscript, TAutoVal& Hidden, TAutoVal& SmallCaps, TAutoVal& AllCaps, TAutoVal& Spacing, TAutoVal& Position, TAutoVal& Kerning, TAutoVal& KerningMin, TAutoVal& Default, TAutoVal& Tab, TAutoVal& Font, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Outline, TAutoVal& Shadow); // [id(113), method]
    void EditFindPara(TAutoVal& LeftIndent, TAutoVal& RightIndent, TAutoVal& Before, TAutoVal& After, TAutoVal& LineSpacingRule, TAutoVal& LineSpacing, TAutoVal& Alignment, TAutoVal& WidowControl, TAutoVal& KeepWithNext, TAutoVal& KeepTogether, TAutoVal& PageBreak, TAutoVal& NoLineNum, TAutoVal& DontHyphen, TAutoVal& Tab, TAutoVal& FirstIndent); // [id(114), method]
    void EditFindStyle(TAutoVal& Style); // [id(115), method]
    void EditFindClearFormatting(); // [id(116), method]
    // Finds the specified text or the specified formatting and replaces it (FindAllWordFors is only valid for some languages and only in Word 95)
    void EditReplace(TAutoVal& Find, TAutoVal& Replace, TAutoVal& Direction, TAutoVal& MatchCase, TAutoVal& WholeWord, TAutoVal& PatternMatch, TAutoVal& SoundsLike, TAutoVal& FindNext, TAutoVal& ReplaceOne, TAutoVal& ReplaceAll, TAutoVal& Format, TAutoVal& Wrap, TAutoVal& FindAllWordForms); // [id(117), method]
    // (Outline and Shadow are only valid on Macintosh)
    void EditReplaceFont(TAutoVal& Points, TAutoVal& Underline, TAutoVal& Color, TAutoVal& Strikethrough, TAutoVal& Superscript, TAutoVal& Subscript, TAutoVal& Hidden, TAutoVal& SmallCaps, TAutoVal& AllCaps, TAutoVal& Spacing, TAutoVal& Position, TAutoVal& Kerning, TAutoVal& KerningMin, TAutoVal& Default, TAutoVal& Tab, TAutoVal& Font, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Outline, TAutoVal& Shadow); // [id(118), method]
    void EditReplacePara(TAutoVal& LeftIndent, TAutoVal& RightIndent, TAutoVal& Before, TAutoVal& After, TAutoVal& LineSpacingRule, TAutoVal& LineSpacing, TAutoVal& Alignment, TAutoVal& WidowControl, TAutoVal& KeepWithNext, TAutoVal& KeepTogether, TAutoVal& PageBreak, TAutoVal& NoLineNum, TAutoVal& DontHyphen, TAutoVal& Tab, TAutoVal& FirstIndent); // [id(119), method]
    void EditReplaceStyle(TAutoVal& Style); // [id(120), method]
    void EditReplaceClearFormatting(); // [id(121), method]
    // Jumps to a specified place in the active document
    void EditGoTo(TAutoVal& Destination); // [id(122), method]
    // Inserts or defines AutoText entries
    void EditAutoText(TAutoVal& Name, TAutoVal& Context, TAutoVal& InsertAs, TAutoVal& Insert, TAutoVal& Add, TAutoVal& Define, TAutoVal& InsertAsText, TAutoVal& Delete); // [id(123), method]
    // Allows links to be viewed, updated, opened, or removed
    void EditLinks(TAutoVal& UpdateMode, TAutoVal& Locked, TAutoVal& SavePictureInDoc, TAutoVal& UpdateNow, TAutoVal& OpenSource, TAutoVal& KillLink, TAutoVal& Link, TAutoVal& Application, TAutoVal& Item, TAutoVal& FileName); // [id(124), method]
    // Opens the selected object for editing
    void EditObject(TAutoVal& Verb); // [id(125), method]
    // Activates an object
    void ActivateObject(); // [id(126), method]
    // Converts the text to table form
    void TextToTable(TAutoVal& ConvertFrom, TAutoVal& NumColumns, TAutoVal& NumRows, TAutoVal& InitialColWidth, TAutoVal& Wizard, TAutoVal& Format, TAutoVal& Apply); // [id(127), method]
    // Converts a table to text
    void TableToText(TAutoVal& ConvertTo); // [id(128), method]
    // Inserts a table
    void TableInsertTable(TAutoVal& ConvertFrom, TAutoVal& NumColumns, TAutoVal& NumRows, TAutoVal& InitialColWidth, TAutoVal& Wizard, TAutoVal& Format, TAutoVal& Apply); // [id(129), method]
    // Inserts one or more cells into the table
    void TableInsertCells(TAutoVal& ShiftCells); // [id(130), method]
    // Inserts one or more rows into the table
    void TableInsertRow(TAutoVal& NumRows); // [id(131), method]
    // Inserts one or more columns into the table
    void TableInsertColumn(); // [id(132), method]
    // Deletes the selected cells from the table
    void TableDeleteCells(TAutoVal& ShiftCells); // [id(133), method]
    // Deletes the selected rows from the table
    void TableDeleteRow(); // [id(134), method]
    // Deletes the selected columns from the table
    void TableDeleteColumn(); // [id(135), method]
    // Merges the selected table cells into a single cell
    void TableMergeCells(); // [id(136), method]
    // Splits the selected table cells
    void TableSplitCells(TAutoVal& NumColumns); // [id(137), method]
    // Inserts a paragraph mark above the current row in the table
    void TableSplit(); // [id(138), method]
    // Selects an entire table
    void TableSelectTable(); // [id(139), method]
    // Selects the current row in a table
    void TableSelectRow(); // [id(140), method]
    // Selects the current column in a table
    void TableSelectColumn(); // [id(141), method]
    // Changes the height of the rows in a table
    void TableRowHeight(TAutoVal& RulerStyle, TAutoVal& LineSpacingRule, TAutoVal& LineSpacing, TAutoVal& LeftIndent, TAutoVal& Alignment, TAutoVal& AllowRowSplit, TAutoVal& PrevRow, TAutoVal& NextRow); // [id(142), method]
    // Changes the width of the columns in a table
    void TableColumnWidth(TAutoVal& ColumnWidth, TAutoVal& SpaceBetweenCols, TAutoVal& PrevColumn, TAutoVal& NextColumn, TAutoVal& AutoFit, TAutoVal& RulerStyle); // [id(143), method]
    // Customizes the Word user interface (menus, keyboard and toolbars)
    void ToolsCustomize(TAutoVal& KeyCode, TAutoVal& KeyCode2, TAutoVal& MenuType, TAutoVal& Position, TAutoVal& AddAll, TAutoVal& Category, TAutoVal& Name, TAutoVal& Menu, TAutoVal& AddBelow, TAutoVal& MenuText, TAutoVal& Rename, TAutoVal& Add, TAutoVal& Remove, TAutoVal& ResetAll, TAutoVal& CommandValue, TAutoVal& Context, TAutoVal& Tab); // [id(152), method]
    // Shows a list of headers and footers for editing
    void NormalViewHeaderArea(TAutoVal& Type, TAutoVal& FirstPage, TAutoVal& OddAndEvenPages, TAutoVal& HeaderDistance, TAutoVal& FooterDistance); // [id(155), method]
    // Inserts an empty frame or encloses the selected item in a frame
    void InsertFrame(); // [id(158), method]
    // Ends a page, column, or section at the insertion point
    void InsertBreak(TAutoVal& Type); // [id(159), method]
    // Inserts a comment and opens the annotation pane
    void InsertAnnotation(); // [id(161), method]
    // Inserts a special character
    void InsertSymbol(TAutoVal& Font, TAutoVal& Tab, TAutoVal& CharNum); // [id(162), method]
    // Inserts a picture from a graphic file
    void InsertPicture(TAutoVal& Name, TAutoVal& LinkToFile, TAutoVal& New); // [id(163), method]
    // Inserts the text of another file into the active document
    void InsertFile(TAutoVal& Name, TAutoVal& Range, TAutoVal& ConfirmConversions, TAutoVal& Link); // [id(164), method]
    // Inserts the current date and/or time into the active document
    void InsertDateTime(TAutoVal& DateTimePic, TAutoVal& InsertAsField); // [id(165), method]
    // Inserts a field in the active document
    void InsertField(TAutoVal& Field); // [id(166), method]
    // Inserts a mail merge field at the insertion point
    void InsertMergeField(TAutoVal& MergeField, TAutoVal& WordField); // [id(167), method]
    // Assigns a name to the selection
    void EditBookmark(TAutoVal& Name, TAutoVal& SortBy, TAutoVal& Add, TAutoVal& Delete, TAutoVal& Goto); // [id(168), method]
    // Marks the text you want to include in the index
    void MarkIndexEntry(TAutoVal& MarkAll, TAutoVal& Entry, TAutoVal& Range, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& CrossReference, TAutoVal& EntryAutoText, TAutoVal& CrossReferenceAutoText); // [id(169), method]
    // Collects the index entries into an index
    void InsertIndex(TAutoVal& Outline, TAutoVal& Fields, TAutoVal& From, TAutoVal& To, TAutoVal& TableId, TAutoVal& AddedStyles, TAutoVal& Caption, TAutoVal& HeadingSeparator, TAutoVal& Replace, TAutoVal& MarkEntry, TAutoVal& AutoMark, TAutoVal& MarkCitation, TAutoVal& Type, TAutoVal& RightAlignPageNumbers, TAutoVal& Passim, TAutoVal& KeepFormatting, TAutoVal& Columns, TAutoVal& Category, TAutoVal& Label); // [id(170), method]
    // Collects the headings or the table of contents entries into a table of contents
    void InsertTableOfContents(TAutoVal& Outline, TAutoVal& Fields, TAutoVal& From, TAutoVal& To, TAutoVal& TableId, TAutoVal& AddedStyles, TAutoVal& Caption, TAutoVal& HeadingSeparator, TAutoVal& Replace, TAutoVal& MarkEntry, TAutoVal& AutoMark, TAutoVal& MarkCitation, TAutoVal& Type, TAutoVal& RightAlignPageNumbers, TAutoVal& Passim, TAutoVal& KeepFormatting, TAutoVal& Columns, TAutoVal& Category, TAutoVal& Label); // [id(171), method]
    // Inserts an equation, chart, drawing, or some other object
    void InsertObject(TAutoVal& IconNumber, TAutoVal& FileName, TAutoVal& Link, TAutoVal& DisplayIcon, TAutoVal& Tab, TAutoVal& Class, TAutoVal& IconFilename, TAutoVal& Caption); // [id(172), method]
    // Creates or prints an envelope
    void ToolsCreateEnvelope(TAutoVal& ExtractAddress, TAutoVal& LabelListIndex, TAutoVal& LabelIndex, TAutoVal& LabelDotMatrix, TAutoVal& LabelTray, TAutoVal& LabelAcross, TAutoVal& LabelDown, TAutoVal& EnvAddress, TAutoVal& EnvOmitReturn, TAutoVal& EnvReturn, TAutoVal& PrintBarCode, TAutoVal& SingleLabel, TAutoVal& LabelRow, TAutoVal& LabelColumn, TAutoVal& PrintEnvLabel, TAutoVal& AddToDocument, TAutoVal& EnvWidth, TAutoVal& EnvHeight, TAutoVal& EnvPaperSize, TAutoVal& PrintFIMA, TAutoVal& UseEnvFeeder, TAutoVal& Tab, TAutoVal& LabelAutoText, TAutoVal& LabelText, TAutoVal& AddrFromLeft, TAutoVal& AddrFromTop, TAutoVal& RetAddrFromLeft, TAutoVal& RetAddrFromTop, TAutoVal& LabelTopMargin, TAutoVal& LabelSideMargin, TAutoVal& LabelVertPitch, TAutoVal& LabelHorPitch, TAutoVal& LabelHeight, TAutoVal& LabelWidth); // [id(173), method]
    // Changes the appearance of the selected characters  (Outline and Shadow are only valid on Macintosh)
    void FormatFont(TAutoVal& Points, TAutoVal& Underline, TAutoVal& Color, TAutoVal& Strikethrough, TAutoVal& Superscript, TAutoVal& Subscript, TAutoVal& Hidden, TAutoVal& SmallCaps, TAutoVal& AllCaps, TAutoVal& Spacing, TAutoVal& Position, TAutoVal& Kerning, TAutoVal& KerningMin, TAutoVal& Default, TAutoVal& Tab, TAutoVal& Font, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Outline, TAutoVal& Shadow); // [id(174), method]
    // Changes the appearance and line numbering of the selected paragraphs
    void FormatParagraph(TAutoVal& LeftIndent, TAutoVal& RightIndent, TAutoVal& Before, TAutoVal& After, TAutoVal& LineSpacingRule, TAutoVal& LineSpacing, TAutoVal& Alignment, TAutoVal& WidowControl, TAutoVal& KeepWithNext, TAutoVal& KeepTogether, TAutoVal& PageBreak, TAutoVal& NoLineNum, TAutoVal& DontHyphen, TAutoVal& Tab, TAutoVal& FirstIndent); // [id(175), method]
    // Changes the page format of the selected sections
    void FormatSectionLayout(TAutoVal& SectionStart, TAutoVal& VertAlign, TAutoVal& Endnotes, TAutoVal& LineNum, TAutoVal& StartingNum, TAutoVal& FromText, TAutoVal& CountBy, TAutoVal& NumMode); // [id(176), method]
    // Changes the column format of the selected sections
    void FormatColumns(TAutoVal& Columns, TAutoVal& ColumnNo, TAutoVal& ColumnWidth, TAutoVal& ColumnSpacing, TAutoVal& EvenlySpaced, TAutoVal& ApplyColsTo, TAutoVal& ColLine, TAutoVal& StartNewCol); // [id(177), method]
    // Changes the page setup of the selected sections
    void FilePageSetup(TAutoVal& Tab, TAutoVal& PaperSize, TAutoVal& TopMargin, TAutoVal& BottomMargin, TAutoVal& LeftMargin, TAutoVal& RightMargin, TAutoVal& Gutter, TAutoVal& PageWidth, TAutoVal& PageHeight, TAutoVal& Orientation, TAutoVal& FirstPage, TAutoVal& OtherPages, TAutoVal& VertAlign, TAutoVal& ApplyPropsTo, TAutoVal& Default, TAutoVal& FacingPages, TAutoVal& HeaderDistance, TAutoVal& FooterDistance, TAutoVal& SectionStart, TAutoVal& OddAndEvenPages, TAutoVal& DifferentFirstPage, TAutoVal& Endnotes, TAutoVal& LineNum, TAutoVal& StartingNum, TAutoVal& FromText, TAutoVal& CountBy, TAutoVal& NumMode); // [id(178), method]
    // Sets and clears the tab stops for the selected paragraphs
    void FormatTabs(TAutoVal& Position, TAutoVal& DefTabs, TAutoVal& Align, TAutoVal& Leader, TAutoVal& Set, TAutoVal& Clear, TAutoVal& ClearAll); // [id(179), method]
    // Applies, creates, or modifies styles
    void FormatStyle(TAutoVal& Name, TAutoVal& Delete, TAutoVal& Merge, TAutoVal& NewName, TAutoVal& BasedOn, TAutoVal& NextStyle, TAutoVal& Type, TAutoVal& FileName, TAutoVal& Source, TAutoVal& AddToTemplate, TAutoVal& Define, TAutoVal& Rename, TAutoVal& Apply); // [id(180), method]
    // (Outline and Shadow are only valid on Macintosh)
    void FormatDefineStyleFont(TAutoVal& Points, TAutoVal& Underline, TAutoVal& Color, TAutoVal& Strikethrough, TAutoVal& Superscript, TAutoVal& Subscript, TAutoVal& Hidden, TAutoVal& SmallCaps, TAutoVal& AllCaps, TAutoVal& Spacing, TAutoVal& Position, TAutoVal& Kerning, TAutoVal& KerningMin, TAutoVal& Default, TAutoVal& Tab, TAutoVal& Font, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Outline, TAutoVal& Shadow); // [id(181), method]
    void FormatDefineStylePara(TAutoVal& LeftIndent, TAutoVal& RightIndent, TAutoVal& Before, TAutoVal& After, TAutoVal& LineSpacingRule, TAutoVal& LineSpacing, TAutoVal& Alignment, TAutoVal& WidowControl, TAutoVal& KeepWithNext, TAutoVal& KeepTogether, TAutoVal& PageBreak, TAutoVal& NoLineNum, TAutoVal& DontHyphen, TAutoVal& Tab, TAutoVal& FirstIndent); // [id(182), method]
    void FormatDefineStyleTabs(TAutoVal& Position, TAutoVal& DefTabs, TAutoVal& Align, TAutoVal& Leader, TAutoVal& Set, TAutoVal& Clear, TAutoVal& ClearAll); // [id(183), method]
    void FormatDefineStyleFrame(TAutoVal& Wrap, TAutoVal& WidthRule, TAutoVal& FixedWidth, TAutoVal& HeightRule, TAutoVal& FixedHeight, TAutoVal& PositionHorz, TAutoVal& PositionHorzRel, TAutoVal& DistFromText, TAutoVal& PositionVert, TAutoVal& PositionVertRel, TAutoVal& DistVertFromText, TAutoVal& MoveWithText, TAutoVal& LockAnchor, TAutoVal& RemoveFrame); // [id(184), method]
    void FormatDefineStyleBorders(TAutoVal& ApplyTo, TAutoVal& Shadow, TAutoVal& TopBorder, TAutoVal& LeftBorder, TAutoVal& BottomBorder, TAutoVal& RightBorder, TAutoVal& HorizBorder, TAutoVal& VertBorder, TAutoVal& TopColor, TAutoVal& LeftColor, TAutoVal& BottomColor, TAutoVal& RightColor, TAutoVal& HorizColor, TAutoVal& VertColor, TAutoVal& FromText, TAutoVal& Shading, TAutoVal& Foreground, TAutoVal& Background, TAutoVal& Tab, TAutoVal& FineShading); // [id(185), method]
    void FormatDefineStyleLang(TAutoVal& Language, TAutoVal& Default); // [id(186), method]
    // Changes the picture scaling, size, and cropping information
    void FormatPicture(TAutoVal& SetSize, TAutoVal& CropLeft, TAutoVal& CropRight, TAutoVal& CropTop, TAutoVal& CropBottom, TAutoVal& ScaleX, TAutoVal& ScaleY, TAutoVal& SizeX, TAutoVal& SizeY); // [id(187), method]
    // Changes the language formatting of the selected characters
    void ToolsLanguage(TAutoVal& Language, TAutoVal& Default); // [id(188), method]
    // Changes the borders and shading of the selected paragraphs, table cells, and pictures
    void FormatBordersAndShading(TAutoVal& ApplyTo, TAutoVal& Shadow, TAutoVal& TopBorder, TAutoVal& LeftBorder, TAutoVal& BottomBorder, TAutoVal& RightBorder, TAutoVal& HorizBorder, TAutoVal& VertBorder, TAutoVal& TopColor, TAutoVal& LeftColor, TAutoVal& BottomColor, TAutoVal& RightColor, TAutoVal& HorizColor, TAutoVal& VertColor, TAutoVal& FromText, TAutoVal& Shading, TAutoVal& Foreground, TAutoVal& Background, TAutoVal& Tab, TAutoVal& FineShading); // [id(189), method]
    // Changes the options for frame formatting
    void FormatFrame(TAutoVal& Wrap, TAutoVal& WidthRule, TAutoVal& FixedWidth, TAutoVal& HeightRule, TAutoVal& FixedHeight, TAutoVal& PositionHorz, TAutoVal& PositionHorzRel, TAutoVal& DistFromText, TAutoVal& PositionVert, TAutoVal& PositionVertRel, TAutoVal& DistVertFromText, TAutoVal& MoveWithText, TAutoVal& LockAnchor, TAutoVal& RemoveFrame); // [id(190), method]
    // Checks the spelling in the active document
    void ToolsSpelling(); // [id(191), method]
    // Checks the spelling of the selected text
    void ToolsSpellSelection(); // [id(192), method]
    // Checks the grammar in the active document
    void ToolsGrammar(); // [id(193), method]
    // Finds a synonym for the selected word
    void ToolsThesaurus(); // [id(194), method]
    // Changes the hyphenation settings for the active document
    void ToolsHyphenation(TAutoVal& AutoHyphenation, TAutoVal& HyphenateCaps, TAutoVal& HyphenationZone, TAutoVal& LimitConsecutiveHyphens); // [id(195), method]
    // Changes the numbered and bulleted paragraphs
    void ToolsBulletsNumbers(TAutoVal& Replace, TAutoVal& Font, TAutoVal& CharNum, TAutoVal& Type, TAutoVal& FormatOutline, TAutoVal& AutoUpdate, TAutoVal& FormatNumber, TAutoVal& Punctuation, TAutoVal& StartAt, TAutoVal& Points, TAutoVal& Hang, TAutoVal& Indent, TAutoVal& Remove); // [id(196), method]
    // Sets revision marking for the active document
    void ToolsRevisions(TAutoVal& MarkRevisions, TAutoVal& ViewRevisions, TAutoVal& PrintRevisions, TAutoVal& AcceptAll, TAutoVal& RejectAll); // [id(197), method]
    // Compares the active document with an earlier version
    void ToolsCompareVersions(TAutoVal& Name); // [id(198), method]
    // Rearranges the selection into a specified order
    void TableSort(TAutoVal& DontSortHdr, TAutoVal& FieldNum, TAutoVal& Type, TAutoVal& Order, TAutoVal& FieldNum2, TAutoVal& Type2, TAutoVal& Order2, TAutoVal& FieldNum3, TAutoVal& Type3, TAutoVal& Order3, TAutoVal& Separator, TAutoVal& SortColumn, TAutoVal& CaseSensitive); // [id(199), method]
    // Recalculates the page breaks
    void ToolsRepaginate(); // [id(201), method]
    // Changes various categories of Word for Windows options
    void ToolsOptions(TAutoVal& Tab); // [id(202), method]
    // Changes the general options (MenuName, RTFInClipboard and ConfirmConversion are not valid in Word 6.0)
    void ToolsOptionsGeneral(TAutoVal& Pagination, TAutoVal& WPHelp, TAutoVal& WPDocNavKeys, TAutoVal& BlueScreen, TAutoVal& ErrorBeeps, TAutoVal& Effects3d, TAutoVal& UpdateLinks, TAutoVal& SendMailAttach, TAutoVal& RecentFiles, TAutoVal& RecentFileCount, TAutoVal& Units, TAutoVal& ButtonFieldClicks, TAutoVal& ShortMenuNames, TAutoVal& RTFInClipboard, TAutoVal& ConfirmConversions, TAutoVal& TipWizardActive); // [id(203), method]
    // Set specific view mode options (Highlight is only valid in Word 95)
    void ToolsOptionsView(TAutoVal& DraftFont, TAutoVal& WrapToWindow, TAutoVal& PicturePlaceHolders, TAutoVal& FieldCodes, TAutoVal& BookMarks, TAutoVal& FieldShading, TAutoVal& StatusBar, TAutoVal& HScroll, TAutoVal& VScroll, TAutoVal& StyleAreaWidth, TAutoVal& Tabs, TAutoVal& Spaces, TAutoVal& Paras, TAutoVal& Hyphens, TAutoVal& Hidden, TAutoVal& ShowAll, TAutoVal& Drawings, TAutoVal& Anchors, TAutoVal& TextBoundaries, TAutoVal& VRuler, TAutoVal& Highlight); // [id(204), method]
    // Changes advanced options in the initialization (WINWORD6.INI and WIN.INI) files
    void ToolsAdvancedSettings(TAutoVal& Application, TAutoVal& Option, TAutoVal& Setting, TAutoVal& Delete, TAutoVal& Set); // [id(206), method]
    // Changes the printing options (FractionalWidths and PSOverText are valid only on Macinthosh)
    void ToolsOptionsPrint(TAutoVal& Draft, TAutoVal& Reverse, TAutoVal& UpdateFields, TAutoVal& Summary, TAutoVal& ShowCodes, TAutoVal& Annotations, TAutoVal& ShowHidden, TAutoVal& EnvFeederInstalled, TAutoVal& FractionalWidths, TAutoVal& PSOverText, TAutoVal& WidowControl, TAutoVal& DfltTrueType, TAutoVal& UpdateLinks, TAutoVal& Background, TAutoVal& DrawingObjects, TAutoVal& FormsData, TAutoVal& DefaultTray); // [id(208), method]
    // Changes the save settings
    void ToolsOptionsSave(TAutoVal& CreateBackup, TAutoVal& FastSaves, TAutoVal& SummaryPrompt, TAutoVal& GlobalDotPrompt, TAutoVal& NativePictureFormat, TAutoVal& EmbedFonts, TAutoVal& FormsData, TAutoVal& AutoSave, TAutoVal& SaveInterval, TAutoVal& Password, TAutoVal& WritePassword, TAutoVal& RecommendReadOnly); // [id(209), method]
    // Changes the spelling options (AutomaticSpellChecking, HideSpellingErrors and RecheckDocument are valid only in Word 95)
    void ToolsOptionsSpelling(TAutoVal& AlwaysSuggest, TAutoVal& SuggestFromMainDictOnly, TAutoVal& IgnoreAllCaps, TAutoVal& IgnoreMixedDigits, TAutoVal& ResetIgnoreAll, TAutoVal& Type, TAutoVal& CustomDict1, TAutoVal& CustomDict2, TAutoVal& CustomDict3, TAutoVal& CustomDict4, TAutoVal& CustomDict5, TAutoVal& CustomDict6, TAutoVal& CustomDict7, TAutoVal& CustomDict8, TAutoVal& CustomDict9, TAutoVal& CustomDict10, TAutoVal& AutomaticSpelling, TAutoVal& HideSpellingErrors, TAutoVal& RecheckDocument); // [id(211), method]
    // Changes the grammar options
    void ToolsOptionsGrammar(TAutoVal& Options, TAutoVal& CheckSpelling, TAutoVal& ShowStatistics); // [id(212), method]
    // Changes the user information options
    void ToolsOptionsUserInfo(TAutoVal& Name, TAutoVal& Initials, TAutoVal& Address); // [id(213), method]
    // Runs, creates, deletes, or revises a macro
    void ToolsMacro(TAutoVal& Name, TAutoVal& Run, TAutoVal& Edit, TAutoVal& Show, TAutoVal& Delete, TAutoVal& Rename, TAutoVal& Description, TAutoVal& NewName, TAutoVal& SetDesc); // [id(215), method]
    // Pauses the macro recorder (toggle)
    void PauseRecorder(); // [id(216), method]
    // Opens another window for the active document
    void WindowNewWindow(); // [id(217), method]
    // Arranges windows as non-overlapping tiles
    void WindowArrangeAll(); // [id(218), method]
    // Switches to a mail merge main document
    void MailMergeEditMainDocument(); // [id(219), method]
    // Formats the return address font for envelopes  (Outline and Shadow are valid only on Macintosh)
    void FormatRetAddrFonts(TAutoVal& Points, TAutoVal& Underline, TAutoVal& Color, TAutoVal& Strikethrough, TAutoVal& Superscript, TAutoVal& Subscript, TAutoVal& Hidden, TAutoVal& SmallCaps, TAutoVal& AllCaps, TAutoVal& Spacing, TAutoVal& Position, TAutoVal& Kerning, TAutoVal& KerningMin, TAutoVal& Default, TAutoVal& Tab, TAutoVal& Font, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Outline, TAutoVal& Shadow); // [id(221), method]
    // Manages AutoText entries, styles, macros, and toolbars
    void Organizer(TAutoVal& Copy, TAutoVal& Delete, TAutoVal& Rename, TAutoVal& Source, TAutoVal& Destination, TAutoVal& Name, TAutoVal& NewName, TAutoVal& Tab); // [id(222), method]
    // Changes the editing options (TabIntent is only valid in Word 95)
    void ToolsOptionsEdit(TAutoVal& ReplaceSelection, TAutoVal& DragAndDrop, TAutoVal& AutoWordSelection, TAutoVal& InsForPaste, TAutoVal& Overtype, TAutoVal& SmartCutPaste, TAutoVal& AllowAccentedUppercase, TAutoVal& PictureEditor, TAutoVal& TabIndent); // [id(224), method]
    // Changes the default locations Word uses to find files
    void ToolsOptionsFileLocations(TAutoVal& Path, TAutoVal& Setting); // [id(225), method]
    // Displays the word count statistics of the active document
    void ToolsWordCount(TAutoVal& CountFootnotes, TAutoVal& Pages, TAutoVal& Words, TAutoVal& Characters, TAutoVal& Paragraphs, TAutoVal& Lines); // [id(228), method]
    // Restores the window to normal size
    void DocRestore(); // [id(233), method]
    // Displays the Control Panel or the Clipboard
    void ControlRun(TAutoVal& Application); // [id(235), method]
    // Shrinks the selection to the next smaller unit
    void ShrinkSelection(); // [id(236), method]
    // Selects the entire document
    void EditSelectAll(); // [id(237), method]
    // Inserts a page number field
    void InsertPageField(); // [id(239), method]
    // Inserts a date field
    void InsertDateField(); // [id(240), method]
    // Inserts a time field
    void InsertTimeField(); // [id(241), method]
    // Links this header/footer to the previous section
    void FormatHeaderFooterLink(); // [id(242), method]
    // Closes the active window pane
    void ClosePane(); // [id(243), method]
    // Promotes the selected paragraphs one heading level
    void OutlinePromote(); // [id(244), method]
    // Demotes the selected paragraphs one heading level
    void OutlineDemote(); // [id(245), method]
    // Moves the selection above the previous item in the outline
    void OutlineMoveUp(); // [id(246), method]
    // Moves the selection below the next item in the outline
    void OutlineMoveDown(); // [id(247), method]
    // Applies the Normal style
    void NormalStyle(); // [id(248), method]
    // Displays the next level of subtext of the selection
    void OutlineExpand(); // [id(249), method]
    // Hides the lowest subtext of the selection
    void OutlineCollapse(); // [id(250), method]
    // Displays the level 1 headings only
    void ShowHeading1(); // [id(251), method]
    // Displays the level 1 and 2 headings
    void ShowHeading2(); // [id(252), method]
    // Displays the level 1 through 3 headings
    void ShowHeading3(); // [id(253), method]
    // Displays the level 1 through 4 headings
    void ShowHeading4(); // [id(254), method]
    // Displays the level 1 through 5 headings
    void ShowHeading5(); // [id(255), method]
    // Displays the level 1 through 6 headings
    void ShowHeading6(); // [id(256), method]
    // Displays the level 1 through 7 headings
    void ShowHeading7(); // [id(257), method]
    // Displays the level 1 through 8 headings
    void ShowHeading8(); // [id(258), method]
    // Displays the level 1 through 9 headings
    void ShowHeading9(); // [id(259), method]
    // Displays all of the heading levels and the body text
    void ShowAllHeadings(); // [id(260), method]
    // Toggles the display of character formatting in outline view
    void OutlineShowFormat(); // [id(262), method]
    // Lists the active macro's variables
    void ShowVars(); // [id(263), method]
    // Inserts a page break at the insertion point
    void InsertPageBreak(); // [id(277), method]
    // Inserts a column break at the insertion point
    void InsertColumnBreak(); // [id(278), method]
    // Executes the action associated with the button fields
    void DoFieldClick(); // [id(282), method]
    // Inserts a Microsoft Draw object
    void InsertDrawing(); // [id(284), method]
    // Inserts a Microsoft Graph object
    void InsertChart(); // [id(285), method]
    // Selects all characters with the same font name and point size
    void SelectCurFont(); // [id(286), method]
    // Selects all paragraphs with the same alignment
    void SelectCurAlignment(); // [id(287), method]
    // Selects all paragraphs with the same line spacing
    void SelectCurSpacing(); // [id(288), method]
    // Selects all paragraphs with the same indentation
    void SelectCurIndent(); // [id(289), method]
    // Selects all paragraphs with the same tabs
    void SelectCurTabs(); // [id(290), method]
    // Selects all characters with the same color
    void SelectCurColor(); // [id(291), method]
    // Removes frame formatting from the selection
    void RemoveFrames(); // [id(292), method]
    // Makes the menu bar active
    void MenuMode(); // [id(293), method]
    // Adds page numbers to the top or the bottom of the pages
    void InsertPageNumbers(TAutoVal& Type, TAutoVal& Position, TAutoVal& FirstPage); // [id(294), method]
    // Uses the specified drawing application to edit the selected picture
    void EditPicture(); // [id(296), method]
    // Changes the appearance of page numbers
    void FormatPageNumber(TAutoVal& ChapterNumber, TAutoVal& NumRestart, TAutoVal& NumFormat, TAutoVal& StartingNum, TAutoVal& Level, TAutoVal& Separator); // [id(298), method]
    void CopyFile(TAutoVal& FileName, TAutoVal& Directory); // [id(300), method]
    // Creates a new document based on the NORMAL template
    void FileNewDefault(); // [id(301), method]
    // Prints the active document using the current defaults
    void FilePrintDefault(); // [id(302), method]
    // Scales the editing view to see the whole page in page layout view
    void ViewZoomWholePage(); // [id(303), method]
    // Scales the editing view to see the width of the page
    void ViewZoomPageWidth(); // [id(304), method]
    // Scales the editing view to 100% in normal view
    void ViewZoom100(); // [id(305), method]
    // Toggles between portrait and landscape mode
    void TogglePortrait(TAutoVal& Tab, TAutoVal& PaperSize, TAutoVal& TopMargin, TAutoVal& BottomMargin, TAutoVal& LeftMargin, TAutoVal& RightMargin, TAutoVal& Gutter, TAutoVal& PageWidth, TAutoVal& PageHeight, TAutoVal& Orientation, TAutoVal& FirstPage, TAutoVal& OtherPages, TAutoVal& VertAlign, TAutoVal& ApplyPropsTo, TAutoVal& Default, TAutoVal& FacingPages, TAutoVal& HeaderDistance, TAutoVal& FooterDistance, TAutoVal& SectionStart, TAutoVal& OddAndEvenPages, TAutoVal& DifferentFirstPage, TAutoVal& Endnotes, TAutoVal& LineNum, TAutoVal& StartingNum, TAutoVal& FromText, TAutoVal& CountBy, TAutoVal& NumMode); // [id(306), method]
    // Creates a bulleted list based on the current defaults
    void ToolsBulletListDefault(); // [id(307), method]
    // Inserts a pen annotation at the location of the insertion point
    void ToggleScribbleMode(); // [id(308), method]
    // Creates a numbered list based on the current defaults
    void ToolsNumberListDefault(); // [id(309), method]
    // Changes the case of the letters in the selection
    void FormatChangeCase(TAutoVal& Type); // [id(322), method]
    // Shows or hides the Word toolbars (ToolTipsKeys is valid only in Word 95)
    void ViewToolbars(TAutoVal& Toolbar, TAutoVal& Context, TAutoVal& ColorButtons, TAutoVal& LargeButtons, TAutoVal& ToolTips, TAutoVal& ToolTipsKey, TAutoVal& Reset, TAutoVal& Delete, TAutoVal& Show, TAutoVal& Hide); // [id(323), method]
    // Edits a list or table in a form
    void MailMergeDataForm(); // [id(340), method]
    // Inserts information from an external data source into the active document
    void InsertDatabase(TAutoVal& Format, TAutoVal& Style, TAutoVal& LinkToSource, TAutoVal& Connection, TAutoVal& SQLStatement, TAutoVal& SQLStatement1, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& DataSource, TAutoVal& From, TAutoVal& To, TAutoVal& IncludeFields); // [id(341), method]
    // Inserts a formula field into a table cell
    void TableFormula(TAutoVal& Formula, TAutoVal& NumFormat); // [id(348), method]
    // Inserts a text form field
    void TextFormField(); // [id(349), method]
    // Inserts a check box form field
    void CheckBoxFormField(); // [id(350), method]
    // Inserts a drop-down form field
    void DropDownFormField(); // [id(351), method]
    // Changes the options for a form field
    void FormFieldOptions(TAutoVal& Entry, TAutoVal& Exit, TAutoVal& Name, TAutoVal& Enable, TAutoVal& TextType, TAutoVal& TextWidth, TAutoVal& TextDefault, TAutoVal& TextFormat, TAutoVal& CheckSize, TAutoVal& CheckWidth, TAutoVal& CheckDefault, TAutoVal& Type, TAutoVal& OwnHelp, TAutoVal& HelpText, TAutoVal& OwnStat, TAutoVal& StatText); // [id(353), method]
    // Inserts a caption above or below a selected object
    void InsertCaption(TAutoVal& Label, TAutoVal& TitleAutoText, TAutoVal& Title, TAutoVal& Delete, TAutoVal& Position, TAutoVal& AutoCaption); // [id(357), method]
    // Sets the number for a caption type
    void InsertCaptionNumbering(TAutoVal& Label, TAutoVal& FormatNumber, TAutoVal& ChapterNumber, TAutoVal& Level, TAutoVal& Separator); // [id(358), method]
    // Defines which objects are inserted with a caption
    void InsertAutoCaption(TAutoVal& Clear, TAutoVal& ClearAll, TAutoVal& Object, TAutoVal& Label, TAutoVal& Position); // [id(359), method]
    // Displays information about the support available for Microsoft Word
    void HelpPSSHelp(); // [id(360), method]
    // Inserts a text box drawing object
    void DrawTextbox(); // [id(363), method]
    // Changes the AutoFormat options (ApplyBulletedLists, ReplaceOrdinals, ReplaceFractions ApplyBorders, ApplyNumberedLists and ShowOptionsFor are only valid in Word 95)
    void ToolsOptionsAutoFormat(TAutoVal& PreserveStyles, TAutoVal& ApplyStylesHeadings, TAutoVal& ApplyStylesLists, TAutoVal& ApplyStylesOtherParas, TAutoVal& AdjustParaMarks, TAutoVal& AdjustTabsSpaces, TAutoVal& AdjustEmptyParas, TAutoVal& ReplaceQuotes, TAutoVal& ReplaceSymbols, TAutoVal& ReplaceBullets, TAutoVal& ApplyBulletedLists, TAutoVal& ReplaceOrdinals, TAutoVal& ReplaceFractions, TAutoVal& ApplyBorders, TAutoVal& ApplyNumberedLists, TAutoVal& ShowOptionsFor); // [id(365), method]
    // Applies the Normal style and converts the selected headings to body text
    void DemoteToBodyText(); // [id(366), method]
    // Inserts a cross-reference
    void InsertCrossReference(TAutoVal& ReferenceType, TAutoVal& ReferenceKind, TAutoVal& ReferenceItem); // [id(367), method]
    // Inserts a footnote or endnote reference at the insertion point
    void InsertFootnote(TAutoVal& Reference, TAutoVal& NoteType, TAutoVal& Symbol); // [id(370), method]
    // Changes the options for footnotes or endnotes
    void NoteOptions(TAutoVal& FootnotesAt, TAutoVal& FootNumberAs, TAutoVal& FootStartingNum, TAutoVal& FootRestartNum, TAutoVal& EndnotesAt, TAutoVal& EndNumberAs, TAutoVal& EndStartingNum, TAutoVal& EndRestartNum); // [id(373), method]
    // Inserts a line drawing object
    void DrawLine(); // [id(376), method]
    // Inserts a rectangle drawing object
    void DrawRectangle(); // [id(377), method]
    // Adds or deletes AutoCorrect entries (SmartQuotes is in Word 95 the last parameter, CapsLock is only valid in Word 95
    void ToolsAutoCorrect(TAutoVal& InitialCaps, TAutoVal& SentenceCaps, TAutoVal& Days, TAutoVal& CapsLock, TAutoVal& ReplaceText, TAutoVal& Formatting, TAutoVal& Replace, TAutoVal& With, TAutoVal& Add, TAutoVal& Delete, TAutoVal& SmartQuotes); // [id(378), method]
    // Automatically formats a document
    void FormatAutoFormat(); // [id(385), method]
    // Changes revision marking options (Highlight Color is only valid in Word 95)
    void ToolsOptionsRevisions(TAutoVal& InsertedTextMark, TAutoVal& InsertedTextColor, TAutoVal& DeletedTextMark, TAutoVal& DeletedTextColor, TAutoVal& RevisedLinesMark, TAutoVal& RevisedLinesColor, TAutoVal& HighlightColor); // [id(386), method]
    // Resets a separator, continuation separator, or continuation notice to the Word default
    void ResetNoteSepOrNotice(); // [id(388), method]
    // Creates a bulleted list
    void FormatBullet(TAutoVal& Points, TAutoVal& Color, TAutoVal& Before, TAutoVal& Type, TAutoVal& After, TAutoVal& StartAt, TAutoVal& Include, TAutoVal& Alignment, TAutoVal& Indent, TAutoVal& Space, TAutoVal& Hang, TAutoVal& RestartNum, TAutoVal& Level, TAutoVal& CharNum, TAutoVal& Font, TAutoVal& Strikethrough, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Underline, TAutoVal& Remove); // [id(389), method]
    // Creates a numbered list
    void FormatNumber(TAutoVal& Points, TAutoVal& Color, TAutoVal& Before, TAutoVal& Type, TAutoVal& After, TAutoVal& StartAt, TAutoVal& Include, TAutoVal& Alignment, TAutoVal& Indent, TAutoVal& Space, TAutoVal& Hang, TAutoVal& RestartNum, TAutoVal& Level, TAutoVal& CharNum, TAutoVal& Font, TAutoVal& Strikethrough, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Underline, TAutoVal& Remove); // [id(390), method]
    // Creates a multilevel list
    void FormatMultilevel(TAutoVal& Points, TAutoVal& Color, TAutoVal& Before, TAutoVal& Type, TAutoVal& After, TAutoVal& StartAt, TAutoVal& Include, TAutoVal& Alignment, TAutoVal& Indent, TAutoVal& Space, TAutoVal& Hang, TAutoVal& RestartNum, TAutoVal& Level, TAutoVal& CharNum, TAutoVal& Font, TAutoVal& Strikethrough, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Underline, TAutoVal& Remove); // [id(391), method]
    // Converts or activates an object as another type
    void ConvertObject(TAutoVal& IconNumber, TAutoVal& ActivateAs, TAutoVal& IconFilename, TAutoVal& Caption, TAutoVal& Class, TAutoVal& DisplayIcon); // [id(392), method]
    // Sorts records in ascending order (A to Z)
    void TableSortAToZ(); // [id(393), method]
    // Sorts records in descending order (Z to A)
    void TableSortZToA(); // [id(394), method]
    // Creates a numbered or bulleted list
    void FormatBulletsAndNumbering(TAutoVal& Remove, TAutoVal& Hang, TAutoVal& Tab, TAutoVal& Preset); // [id(397), method]
    // Adds a new caption type
    void InsertAddCaption(TAutoVal& Name); // [id(402), method]
    // Jumps to the next page in the active document
    void GoToNextPage(); // [id(404), method]
    // Jumps to the previous page in the active document
    void GoToPreviousPage(); // [id(405), method]
    // Jumps to the next section in the active document
    void GoToNextSection(); // [id(406), method]
    // Jumps to the previous section in the active document
    void GoToPreviousSection(); // [id(407), method]
    // Jumps to the next footnote in the active document
    void GoToNextFootnote(); // [id(408), method]
    // Jumps to the previous footnote in the active document
    void GoToPreviousFootnote(); // [id(409), method]
    // Jumps to the next endnote in the active document
    void GoToNextEndnote(); // [id(410), method]
    // Jumps to the previous endnote in the active document
    void GoToPreviousEndnote(); // [id(411), method]
    // Jumps to the next annotation in the active document
    void GoToNextAnnotation(); // [id(412), method]
    // Jumps to the previous annotation in the active document
    void GoToPreviousAnnotation(); // [id(413), method]
    // Connects to a network drive
    void Connect(TAutoVal& Drive, TAutoVal& Path, TAutoVal& Password); // [id(420), method]
    void EditFindLang(TAutoVal& Language, TAutoVal& Default); // [id(428), method]
    void EditReplaceLang(TAutoVal& Language, TAutoVal& Default); // [id(429), method]
    // Customizes the Word key assignments
    void ToolsCustomizeKeyboard(TAutoVal& KeyCode, TAutoVal& KeyCode2, TAutoVal& MenuType, TAutoVal& Position, TAutoVal& AddAll, TAutoVal& Category, TAutoVal& Name, TAutoVal& Menu, TAutoVal& AddBelow, TAutoVal& MenuText, TAutoVal& Rename, TAutoVal& Add, TAutoVal& Remove, TAutoVal& ResetAll, TAutoVal& CommandValue, TAutoVal& Context, TAutoVal& Tab); // [id(432), method]
    // Customizes the Word menu assignments
    void ToolsCustomizeMenus(TAutoVal& KeyCode, TAutoVal& KeyCode2, TAutoVal& MenuType, TAutoVal& Position, TAutoVal& AddAll, TAutoVal& Category, TAutoVal& Name, TAutoVal& Menu, TAutoVal& AddBelow, TAutoVal& MenuText, TAutoVal& Rename, TAutoVal& Add, TAutoVal& Remove, TAutoVal& ResetAll, TAutoVal& CommandValue, TAutoVal& Context, TAutoVal& Tab); // [id(433), method]
    // Merges revisions from the active document to an earlier version
    void ToolsMergeRevisions(TAutoVal& Name); // [id(435), method]
    // Exits print preview
    void ClosePreview(); // [id(437), method]
    // Converts all footnotes into endnotes
    void EditConvertAllFootnotes(); // [id(439), method]
    // Converts all endnotes into footnotes
    void EditConvertAllEndnotes(); // [id(440), method]
    // Changes all footnotes to endnotes and all endnotes to footnotes
    void EditSwapAllNotes(); // [id(441), method]
    // Marks the text you want to include in the table of contents
    void MarkTableOfContentsEntry(TAutoVal& Entry, TAutoVal& EntryAutoText, TAutoVal& TableId, TAutoVal& Level); // [id(442), method]
    // Inserts an ellipse drawing object
    void DrawEllipse(); // [id(454), method]
    // Inserts an arc drawing object
    void DrawArc(); // [id(455), method]
    // Converts selected footnotes into endnotes, or converts selected endnotes into footnotes
    void EditConvertNotes(); // [id(462), method]
    // Marks the text you want to include in the table of authorities
    void MarkCitation(TAutoVal& LongCitation, TAutoVal& LongCitationAutoText, TAutoVal& Category, TAutoVal& ShortCitation, TAutoVal& NextCitation, TAutoVal& Mark, TAutoVal& MarkAll); // [id(463), method]
    // Groups the selected drawing objects
    void DrawGroup(); // [id(465), method]
    // Brings the selected drawing objects to the front
    void DrawBringToFront(); // [id(466), method]
    // Sends the selected drawing objects to the back
    void DrawSendToBack(); // [id(467), method]
    // Sends the selected drawing objects back one layer
    void DrawSendBehindText(); // [id(468), method]
    // Brings the selected drawing objects forward one layer
    void DrawBringInFrontOfText(); // [id(469), method]
    // Collects the table of authorities entries into a table of authorities
    void InsertTableOfAuthorities(TAutoVal& Outline, TAutoVal& Fields, TAutoVal& From, TAutoVal& To, TAutoVal& TableId, TAutoVal& AddedStyles, TAutoVal& Caption, TAutoVal& HeadingSeparator, TAutoVal& Replace, TAutoVal& MarkEntry, TAutoVal& AutoMark, TAutoVal& MarkCitation, TAutoVal& Type, TAutoVal& RightAlignPageNumbers, TAutoVal& Passim, TAutoVal& KeepFormatting, TAutoVal& Columns, TAutoVal& Category, TAutoVal& Label); // [id(471), method]
    // Collects captions into a table of figures
    void InsertTableOfFigures(TAutoVal& Outline, TAutoVal& Fields, TAutoVal& From, TAutoVal& To, TAutoVal& TableId, TAutoVal& AddedStyles, TAutoVal& Caption, TAutoVal& HeadingSeparator, TAutoVal& Replace, TAutoVal& MarkEntry, TAutoVal& AutoMark, TAutoVal& MarkCitation, TAutoVal& Type, TAutoVal& RightAlignPageNumbers, TAutoVal& Passim, TAutoVal& KeepFormatting, TAutoVal& Columns, TAutoVal& Category, TAutoVal& Label); // [id(472), method]
    // Displays the next record in the active mail merge data source
    void MailMergeNextRecord(); // [id(478), method]
    // Displays the previous record in the active mail merge data source
    void MailMergePrevRecord(); // [id(479), method]
    // Displays the first record in the active mail merge data source
    void MailMergeFirstRecord(); // [id(480), method]
    // Displays the last record in the active mail merge data source
    void MailMergeLastRecord(); // [id(481), method]
    // Inserts a new form field
    void InsertFormField(TAutoVal& Entry, TAutoVal& Exit, TAutoVal& Name, TAutoVal& Enable, TAutoVal& TextType, TAutoVal& TextWidth, TAutoVal& TextDefault, TAutoVal& TextFormat, TAutoVal& CheckSize, TAutoVal& CheckWidth, TAutoVal& CheckDefault, TAutoVal& Type, TAutoVal& OwnHelp, TAutoVal& HelpText, TAutoVal& OwnStat, TAutoVal& StatText); // [id(483), method]
    // Ungroups the selected group of drawing objects
    void DrawUngroup(); // [id(485), method]
    // Applies the previously copied formatting to selection
    void PasteFormat(); // [id(486), method]
    // Formats the first character of current paragraph as a dropped capital
    void FormatDropCap(TAutoVal& Position, TAutoVal& Font, TAutoVal& DropHeight, TAutoVal& DistFromText); // [id(488), method]
    // Creates or prints a label or a sheet of labels
    void ToolsCreateLabels(TAutoVal& ExtractAddress, TAutoVal& LabelListIndex, TAutoVal& LabelIndex, TAutoVal& LabelDotMatrix, TAutoVal& LabelTray, TAutoVal& LabelAcross, TAutoVal& LabelDown, TAutoVal& EnvAddress, TAutoVal& EnvOmitReturn, TAutoVal& EnvReturn, TAutoVal& PrintBarCode, TAutoVal& SingleLabel, TAutoVal& LabelRow, TAutoVal& LabelColumn, TAutoVal& PrintEnvLabel, TAutoVal& AddToDocument, TAutoVal& EnvWidth, TAutoVal& EnvHeight, TAutoVal& EnvPaperSize, TAutoVal& PrintFIMA, TAutoVal& UseEnvFeeder, TAutoVal& Tab, TAutoVal& LabelAutoText, TAutoVal& LabelText, TAutoVal& AddrFromLeft, TAutoVal& AddrFromTop, TAutoVal& RetAddrFromLeft, TAutoVal& RetAddrFromTop, TAutoVal& LabelTopMargin, TAutoVal& LabelSideMargin, TAutoVal& LabelVertPitch, TAutoVal& LabelHorPitch, TAutoVal& LabelHeight, TAutoVal& LabelWidth); // [id(489), method]
    // Transforms the selected outline items into subdocuments
    void CreateSubdocument(); // [id(491), method]
    // Opens a pane for viewing and editing the footnote separator
    void ViewFootnoteSeparator(); // [id(493), method]
    // Opens a pane for viewing and editing the footnote continuation separator
    void ViewFootnoteContSeparator(); // [id(494), method]
    // Opens a pane for viewing and editing the footnote continuation notice
    void ViewFootnoteContNotice(); // [id(495), method]
    // Opens a pane for viewing and editing the endnote separator
    void ViewEndnoteSeparator(); // [id(496), method]
    // Opens a pane for viewing and editing the endnote continuation separator
    void ViewEndnoteContSeparator(); // [id(497), method]
    // Opens a pane for viewing and editing the endnote continuation notice
    void ViewEndnoteContNotice(); // [id(498), method]
    // Brings the selected drawing objects forward
    void DrawBringForward(); // [id(500), method]
    // Sends the selected drawing objects backward
    void DrawSendBackward(); // [id(501), method]
    // Sets protection for the active document
    void ToolsProtectDocument(TAutoVal& DocumentPassword, TAutoVal& NoReset, TAutoVal& Type); // [id(503), method]
    // Attempts to make the document fit on one less page
    void ToolsShrinkToFit(); // [id(504), method]
    // Browse or apply styles from templates
    void FormatStyleGallery(TAutoVal& Template, TAutoVal& Preview); // [id(505), method]
    // Reviews revisions to the active document
    void ToolsReviewRevisions(TAutoVal& ShowMarks, TAutoVal& HideMarks, TAutoVal& Wrap, TAutoVal& FindPrevious, TAutoVal& FindNext, TAutoVal& AcceptRevisions, TAutoVal& RejectRevisions); // [id(506), method]
    // Searches for a Help topic by typing or selecting a keyword
    void HelpSearch(); // [id(510), method]
    // Customizes WordPerfect Help
    void HelpWordPerfectHelpOptions(TAutoVal& CommandKeyHelp, TAutoVal& DocNavKeys, TAutoVal& MouseSimulation, TAutoVal& DemoGuidance, TAutoVal& DemoSpeed, TAutoVal& HelpType); // [id(511), method]
    // Increases the font size of the selection by one point
    void GrowFontOnePoint(); // [id(513), method]
    // Decreases the font size of the selection by one point
    void ShrinkFontOnePoint(); // [id(514), method]
    // Toggles full screen
    void FilePrintPreviewFullScreen(); // [id(516), method]
    // Inserts a sound object into the document
    void InsertSound(); // [id(519), method]
    // Removes protection from the active document
    void ToolsUnprotectDocument(TAutoVal& DocumentPassword); // [id(521), method]
    // Removes numbers and bullets from the selection
    void RemoveBulletsNumbers(); // [id(522), method]
    // Changes the document compatibility options
    void ToolsOptionsCompatibility(TAutoVal& Product, TAutoVal& Default, TAutoVal& NoTabHangIndent, TAutoVal& NoSpaceRaiseLower, TAutoVal& PrintColBlack, TAutoVal& WrapTrailSpaces, TAutoVal& NoColumnBalance, TAutoVal& ConvMailMergeEsc, TAutoVal& SuppressSpBfAfterPgBrk, TAutoVal& SuppressTopSpacing, TAutoVal& OrigWordTableRules, TAutoVal& TransparentMetafiles, TAutoVal& ShowBreaksInFrames, TAutoVal& SwapBordersFacingPages, TAutoVal& LeaveBackslashAlone, TAutoVal& ExpandShiftReturn, TAutoVal& DontULTrailSpace, TAutoVal& DontBalanceSbDbWidth, TAutoVal& SuppressTopSpacingMac5, TAutoVal& SpacingInWholePoints, TAutoVal& PrintBodyTextBeforeHeader, TAutoVal& NoLeading, TAutoVal& NoSpaceForUL, TAutoVal& MWSmallCaps, TAutoVal& NoExtraLineSpacing, TAutoVal& TruncateFontHeight, TAutoVal& SubFontBySize); // [id(525), method]
    // Inserts a rounded rectangle drawing object
    void DrawRoundRectangle(); // [id(537), method]
    // Inserts a freeform drawing object
    void DrawFreeformPolygon(); // [id(538), method]
    // Use to select drawing objects -- drag to create a rectangle enclosing the objects
    void SelectDrawingObjects(); // [id(545), method]
    // Opens the macro dialog editor
    void DialogEditor(); // [id(552), method]
    // Flips the selected drawing objects from left to right
    void DrawFlipHorizontal(); // [id(559), method]
    // Flips the selected drawing objects from top to bottom
    void DrawFlipVertical(); // [id(560), method]
    // Rotates the selected drawing objects 90 degrees to the right
    void DrawRotateRight(); // [id(561), method]
    // Rotates the selected drawing objects 90 degrees to the left
    void DrawRotateLeft(); // [id(562), method]
    // Applies a set of formatting to a table
    void TableAutoFormat(TAutoVal& HideAutoFit, TAutoVal& Preview, TAutoVal& Format, TAutoVal& Borders, TAutoVal& Shading, TAutoVal& Font, TAutoVal& Color, TAutoVal& AutoFit, TAutoVal& HeadingRows, TAutoVal& FirstColumn, TAutoVal& LastRow, TAutoVal& LastColumn); // [id(563), method]
    // Changes the fill, line, size, and position attributes of the selected drawing objects
    void FormatDrawingObject(TAutoVal& Tab, TAutoVal& FillColor, TAutoVal& LineColor, TAutoVal& FillPatternColor, TAutoVal& FillPattern, TAutoVal& LineType, TAutoVal& LineStyle, TAutoVal& LineWeight, TAutoVal& ArrowStyle, TAutoVal& ArrowWidth, TAutoVal& ArrowLength, TAutoVal& Shadow, TAutoVal& RoundCorners, TAutoVal& HorizontalPos, TAutoVal& HorizontalFrom, TAutoVal& VerticalPos, TAutoVal& VerticalFrom, TAutoVal& LockAnchor, TAutoVal& Height, TAutoVal& Width, TAutoVal& InternalMargin); // [id(565), method]
    // Inserts a Microsoft Excel worksheet object
    void InsertExcelTable(); // [id(567), method]
    // Finds a specified record in a mail merge data source
    void MailMergeFindRecord(TAutoVal& Find, TAutoVal& Field); // [id(569), method]
    // Removes the expanded or condensed font attribute
    void NormalFontSpacing(); // [id(571), method]
    // Removes the raised or lowered font attribute
    void NormalFontPosition(); // [id(572), method]
    // Scales the editing view to 200% in normal view
    void ViewZoom200(); // [id(573), method]
    // Scales the editing view to 75% in normal view
    void ViewZoom75(); // [id(574), method]
    // Disassembles the selected metafile picture into drawing objects
    void DrawDisassemblePicture(); // [id(575), method]
    // Scales the editing view
    void ViewZoom(TAutoVal& AutoFit, TAutoVal& TwoPages, TAutoVal& FullPage, TAutoVal& NumColumns, TAutoVal& NumRows, TAutoVal& ZoomPercent); // [id(577), method]
    // Sets protection for sections of the active document
    void ToolsProtectSection(TAutoVal& Protect, TAutoVal& Section); // [id(578), method]
    // Changes the document's font mapping
    void FontSubstitution(TAutoVal& UnavailableFont, TAutoVal& SubstituteFont); // [id(581), method]
    // Toggles full screen mode on/off
    void ToggleFull(); // [id(582), method]
    // Opens a file and inserts it as a subdocument in a master document
    void InsertSubdocument(TAutoVal& Name, TAutoVal& ConfirmConversions, TAutoVal& ReadOnly, TAutoVal& LinkToSource, TAutoVal& AddToMru, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& Revert, TAutoVal& WritePasswordDoc, TAutoVal& WritePasswordDot, TAutoVal& Connection, TAutoVal& SQLStatement, TAutoVal& SQLStatement1); // [id(583), method]
    // Merges two adjacent subdocuments into one subdocument
    void MergeSubdocument(); // [id(584), method]
    // Splits the selected part of a subdocument into another subdocument at the same level
    void SplitSubdocument(); // [id(585), method]
    // Creates a new toolbar
    void NewToolbar(TAutoVal& Name, TAutoVal& Context); // [id(586), method]
    // Toggles showing the main text layer in page layout view
    void ToggleMainTextLayer(); // [id(587), method]
    // Shows previous section's header/footer in page layout view
    void ShowPrevHeaderFooter(); // [id(588), method]
    // Shows next section's header/footer in page layout view
    void ShowNextHeaderFooter(); // [id(589), method]
    // Jump between Header and Footer
    void GoToHeaderFooter(); // [id(590), method]
    // Promotes the selection one level
    void PromoteList(); // [id(591), method]
    // Demotes the selection one level
    void DemoteList(); // [id(592), method]
    // Highlights the text associated with an annotation reference mark
    void GotoAnnotationScope(); // [id(597), method]
    // Opens a subdocument in a new window
    void OpenSubdocument(); // [id(599), method]
    void FormatDefineStyleNumbers(TAutoVal& Points, TAutoVal& Color, TAutoVal& Before, TAutoVal& Type, TAutoVal& After, TAutoVal& StartAt, TAutoVal& Include, TAutoVal& Alignment, TAutoVal& Indent, TAutoVal& Space, TAutoVal& Hang, TAutoVal& RestartNum, TAutoVal& Level, TAutoVal& CharNum, TAutoVal& Font, TAutoVal& Strikethrough, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Underline, TAutoVal& Remove); // [id(602), method]
    // Changes numbering options for heading level styles
    void FormatHeadingNumbering(TAutoVal& Remove, TAutoVal& Preset); // [id(603), method]
    // Shows or hides the Borders toolbar
    void ViewBorderToolbar(); // [id(604), method]
    // Shows or hides the Drawing toolbar
    void ViewDrawingToolbar(); // [id(605), method]
    // Modifies Heading Numbering styles
    void FormatHeadingNumber(TAutoVal& Points, TAutoVal& Color, TAutoVal& Before, TAutoVal& Type, TAutoVal& After, TAutoVal& StartAt, TAutoVal& Include, TAutoVal& Alignment, TAutoVal& Indent, TAutoVal& Space, TAutoVal& Hang, TAutoVal& RestartNum, TAutoVal& Level, TAutoVal& CharNum, TAutoVal& Font, TAutoVal& Strikethrough, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Underline, TAutoVal& Remove); // [id(606), method]
    // Displays resizing handles on selected freeform drawing objects -- drag a handle to reshape
    void DrawReshape(); // [id(608), method]
    // Formats the selected callouts or sets callout defaults
    void FormatCallout(TAutoVal& Type, TAutoVal& Gap, TAutoVal& Angle, TAutoVal& Drop, TAutoVal& Length, TAutoVal& Border, TAutoVal& AutoAttach, TAutoVal& Accent); // [id(610), method]
    // Inserts a callout drawing object
    void DrawCallout(); // [id(611), method]
    // Sends the active document through electronic mail
    void FileSendMail(); // [id(613), method]
    void ToolsCustomizeMenuBar(TAutoVal& Context, TAutoVal& Position, TAutoVal& MenuType, TAutoVal& MenuText, TAutoVal& Menu, TAutoVal& Add, TAutoVal& Remove, TAutoVal& Rename); // [id(615), method]
    // Adds or changes the electronic mail routing slip of the active document
    void FileRoutingSlip(TAutoVal& Subject, TAutoVal& Message, TAutoVal& AllAtOnce, TAutoVal& ReturnWhenDone, TAutoVal& TrackStatus, TAutoVal& Protect, TAutoVal& AddSlip, TAutoVal& RouteDocument, TAutoVal& AddRecipient, TAutoVal& OldRecipient, TAutoVal& ResetSlip, TAutoVal& ClearSlip, TAutoVal& ClearRecipients, TAutoVal& Address); // [id(624), method]
    // Modifies the category names for the table of authorities
    void EditTOACategory(TAutoVal& Category, TAutoVal& CategoryName); // [id(625), method]
    // Updates the table formatting to match the applied formatting set
    void TableUpdateAutoFormat(); // [id(626), method]
    // Attach an image or text to the selected button
    void ChooseButtonImage(TAutoVal& Face, TAutoVal& Button, TAutoVal& Context, TAutoVal& Text, TAutoVal& Toolbar); // [id(627), method]
    // Adds a record to a database
    void ToolsAddRecordDefault(); // [id(629), method]
    // Removes a record from a database
    void ToolsRemoveRecordDefault(); // [id(630), method]
    // Adds or deletes a field from a database
    void ToolsManageFields(TAutoVal& FieldName, TAutoVal& Add, TAutoVal& Remove, TAutoVal& Rename, TAutoVal& NewName); // [id(631), method]
    // Switches between outline and master document views
    void ViewToggleMasterDocument(); // [id(632), method]
    // Sets up a grid for aligning drawing objects
    void DrawSnapToGrid(TAutoVal& SnapToGrid, TAutoVal& XGrid, TAutoVal& YGrid, TAutoVal& XOrigin, TAutoVal& YOrigin); // [id(633), method]
    // Aligns the selected drawing objects with one another or the page
    void DrawAlign(TAutoVal& Horizontal, TAutoVal& Vertical, TAutoVal& RelativeTo); // [id(634), method]
    // Displays a Word Tip of the Day
    void HelpTipOfTheDay(TAutoVal& StartupTips); // [id(635), method]
    // Merges the selected subdocuments into their containing master document
    void RemoveSubdocument(); // [id(639), method]
    // Return to document text
    void CloseViewHeaderFooter(); // [id(640), method]
    // Inserts an expression field that automatically sums a table row or column
    void TableAutoSum(TAutoVal& Formula, TAutoVal& NumFormat); // [id(641), method]
    // Creates a new mail merge data source
    void MailMergeCreateDataSource(TAutoVal& FileName, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& HeaderRecord, TAutoVal& MSQuery, TAutoVal& SQLStatement, TAutoVal& SQLStatement1, TAutoVal& Connection, TAutoVal& LinkToSource); // [id(642), method]
    // Creates a new mail merge header source
    void MailMergeCreateHeaderSource(TAutoVal& FileName, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& HeaderRecord, TAutoVal& MSQuery, TAutoVal& SQLStatement, TAutoVal& SQLStatement1, TAutoVal& Connection, TAutoVal& LinkToSource); // [id(643), method]
    // Opens a separate window for creating a picture object or inserts the selected drawing objects into a picture
    void DrawInsertWordPicture(); // [id(648), method]
    // Links or unlinks this header/footer to or from the previous section
    void ToggleHeaderFooterLink(); // [id(652), method]
    // Creates or Inserts an AutoText entry depending on the selection
    void AutoText(); // [id(653), method]
    // Starts or switches to Microsoft Mail
    void MicrosoftMail(); // [id(656), method]
    // Starts or switches to Microsoft Excel
    void MicrosoftExcel(); // [id(657), method]
    // Starts or switches to Microsoft Access
    void MicrosoftAccess(); // [id(658), method]
    // Starts or switches to Microsoft Schedule+
    void MicrosoftSchedule(); // [id(659), method]
    // Starts or switches to Microsoft FoxPro
    void MicrosoftFoxPro(); // [id(660), method]
    // Starts or switches to Microsoft PowerPoint
    void MicrosoftPowerPoint(); // [id(661), method]
    // Starts or switches to Microsoft Publisher
    void MicrosoftPublisher(); // [id(662), method]
    // Starts or switches to Microsoft Project
    void MicrosoftProject(); // [id(663), method]
    // Refreshes the display
    void ScreenRefresh(); // [id(665), method]
    // Moves the selected drawing objects up
    void DrawNudgeUp(); // [id(670), method]
    // Moves the selected drawing objects down
    void DrawNudgeDown(); // [id(671), method]
    // Moves the selected drawing objects to the left
    void DrawNudgeLeft(); // [id(672), method]
    // Moves the selected drawing objects to the right
    void DrawNudgeRight(); // [id(673), method]
    // Opens a mail merge header source
    void MailMergeEditHeaderSource(); // [id(675), method]
    // Combines files to produce form letters, mailing labels, envelopes, and catalogs
    void MailMerge(TAutoVal& CheckErrors, TAutoVal& Destination, TAutoVal& MergeRecords, TAutoVal& From, TAutoVal& To, TAutoVal& Suppression, TAutoVal& MailMerge, TAutoVal& QueryOptions, TAutoVal& MailSubject, TAutoVal& MailAsAttachment, TAutoVal& MailAddress); // [id(676), method]
    // Checks for errors in a mail merge
    void MailMergeCheck(TAutoVal& CheckErrors); // [id(677), method]
    // Collects the results of the mail merge in a document
    void MailMergeToDoc(); // [id(678), method]
    // Sends the results of the mail merge to the printer
    void MailMergeToPrinter(); // [id(679), method]
    // Prepares a main document for a mail merge
    void MailMergeHelper(TAutoVal& Merge, TAutoVal& Options); // [id(680), method]
    // Sets the query options for a mail merge
    void MailMergeQueryOptions(TAutoVal& SQLStatement, TAutoVal& SQLStatement1); // [id(681), method]
    // Inserts a Microsoft WordArt object
    void InsertWordArt(); // [id(682), method]
    // Inserts a Microsoft Equation object
    void InsertEquation(); // [id(683), method]
    // Displays the Print Manager
    void RunPrintManager(); // [id(684), method]
    // Displays Help contents
    void HelpContents(); // [id(688), method]
    // Closes the active picture document
    void FileClosePicture(); // [id(694), method]
    // Sets document margins to enclose all drawing objects on the page
    void DrawResetWordPicture(); // [id(696), method]
    // Moves the selected drawing objects up one pixel
    void DrawNudgeUpPixel(); // [id(700), method]
    // Moves the selected drawing objects down one pixel
    void DrawNudgeDownPixel(); // [id(701), method]
    // Moves the selected drawing objects to the left one pixel
    void DrawNudgeLeftPixel(); // [id(702), method]
    // Moves the selected drawing objects to the right one pixel
    void DrawNudgeRightPixel(); // [id(703), method]
    // Hyphenates the selection or the entire document
    void ToolsHyphenationManual(); // [id(704), method]
    void ClearFormField(); // [id(706), method]
    // Ends a section at the insertion point
    void InsertSectionBreak(); // [id(707), method]
    // Unselects a drawn object
    void DrawUnselect(); // [id(708), method]
    // Selects the next drawn object
    void DrawSelectNext(); // [id(709), method]
    // Selects the previous drawn object
    void DrawSelectPrevious(); // [id(710), method]
    // Execute the Microsoft System Info application
    void MicrosoftSystemInfo(); // [id(711), method]
    // Inserts a Word ask field at the insertion point
    void MailMergeInsertAsk(TAutoVal& Name, TAutoVal& Prompt, TAutoVal& DefaultBookmarkText, TAutoVal& AskOnce); // [id(4047), method]
    // Inserts a Word fillin field at the insertion point
    void MailMergeInsertFillIn(TAutoVal& Prompt, TAutoVal& DefaultFillInText, TAutoVal& AskOnce); // [id(4048), method]
    // Inserts a Word field at the insertion point
    void MailMergeInsertIf(TAutoVal& MergeField, TAutoVal& Comparison, TAutoVal& CompareTo, TAutoVal& TrueAutoText, TAutoVal& TrueText, TAutoVal& FalseAutoText, TAutoVal& FalseText); // [id(4049), method]
    // Inserts a Word record field at the insertion point
    void MailMergeInsertMergeRec(); // [id(4050), method]
    // Inserts a Word sequence field at the insertion point
    void MailMergeInsertMergeSeq(); // [id(4051), method]
    // Inserts a Word next field at the insertion point
    void MailMergeInsertNext(); // [id(4052), method]
    // Inserts a Word next if field at the insertion point
    void MailMergeInsertNextIf(TAutoVal& MergeField, TAutoVal& Comparison, TAutoVal& CompareTo); // [id(4053), method]
    // Inserts a Word set field at the insertion point
    void MailMergeInsertSet(TAutoVal& Name, TAutoVal& ValueText, TAutoVal& ValueAutoText); // [id(4054), method]
    // Inserts a Word skip if field at the insertion point
    void MailMergeInsertSkipIf(TAutoVal& MergeField, TAutoVal& Comparison, TAutoVal& CompareTo); // [id(4055), method]
    double Rnd(); // [id(0x800e), method]
    long Instr(TAutoVal& Index, TAutoString Source, TAutoString Search); // [id(0x800f), method]
    double Abs(double n); // [id(0x8000), method]
    short Sgn(double n); // [id(0x8001), method]
    short Int(short n); // [id(0x8002), method]
    long Len(TAutoString Source); // [id(0x8003), method]
    short Asc(TAutoString a); // [id(0x8004), method]
    TAutoString Chr(short CharCode); // [id(0x8005), method]
    double Val(TAutoString a); // [id(0x8006), method]
    TAutoString Str(double n); // [id(0x8007), method]
    TAutoString Left(TAutoString Source, long Count); // [id(0x8008), method]
    TAutoString Right(TAutoString Source, long Count); // [id(0x8009), method]
    TAutoString Mid(TAutoString Source, long Start, TAutoVal& Count); // [id(0x800a), method]
    TAutoString String(long Count, TAutoString Source); // [id(0x800b), method]
    TAutoString Date(TAutoVal& SerialNumber); // [id(0x800c), method]
    TAutoString Time(TAutoVal& SerialNumber); // [id(0x800d), method]
    // Shows/hides all nonprinting characters
    short ShowAll(TAutoVal& On); // [id(0x8010), method]
    // Selects a columnar block of text
    void ColumnSelect(); // [id(0x8011), method]
    void Insert(TAutoString Text); // [id(0x8012), method]
    void InsertPara(); // [id(0x8013), method]
    TAutoString Selection(); // [id(0x8015), method]
    TAutoString GetBookmark(TAutoString Name); // [id(0x8016), method]
    short CmpBookmarks(TAutoString Bookmark1, TAutoString Bookmark2); // [id(0x8017), method]
    void CopyBookmark(TAutoString Bookmark1, TAutoString Bookmark2); // [id(0x8018), method]
    void SetStartOfBookmark(TAutoString Bookmark1, TAutoVal& Bookmark2); // [id(0x8019), method]
    void SetEndOfBookmark(TAutoString Bookmark1, TAutoVal& Bookmark2); // [id(0x801a), method]
    short ExistingBookmark(TAutoString Name); // [id(0x801b), method]
    short EmptyBookmark(TAutoString Name); // [id(0x801c), method]
    short CountBookmarks(); // [id(0x801d), method]
    short CountMergeFields(); // [id(0x801e), method]
    TAutoString BookmarkName(short Count); // [id(0x801f), method]
    TAutoString MergeFieldName(short Count); // [id(0x8020), method]
    short CountStyles(TAutoVal& Context, TAutoVal& All); // [id(0x8021), method]
    TAutoString StyleName(TAutoVal& Count, TAutoVal& Context, TAutoVal& All); // [id(0x8022), method]
    short IsDocumentDirty(); // [id(0x8023), method]
    void SetDocumentDirty(TAutoVal& Dirty); // [id(0x8024), method]
    TAutoString FileName(TAutoVal& Number); // [id(0x8025), method]
    short CountFiles(); // [id(0x8026), method]
    TAutoString GetAutoText(TAutoString Name, TAutoVal& Context); // [id(0x8027), method]
    short CountAutoTextEntries(TAutoVal& Context); // [id(0x8028), method]
    TAutoString AutoTextName(short Count, TAutoVal& Context); // [id(0x8029), method]
    void SetAutoText(TAutoString Name, TAutoString Text, TAutoVal& Context); // [id(0x802a), method]
    short MsgBox(TAutoString Message, TAutoVal& Title, TAutoVal& Type); // [id(0x802b), method]
    void Beep(TAutoVal& BeepType); // [id(0x802c), method]
    void Shell(TAutoString Application, TAutoVal& WindowStyle); // [id(0x802d), method]
    // Makes the selection the default character format of the applied style
    short ResetChar(); // [id(0x802e), method]
    // Makes the selection the default paragraph format of the applied style
    short ResetPara(); // [id(0x802f), method]
    short TabType(double Pos); // [id(0x8030), method]
    TAutoString TabLeader(double Pos); // [id(0x8031), method]
    // Changes the position of the active window
    void DocMove(short HorizPos, short VertPos); // [id(0x8032), method]
    // Changes the size of the active window
    void DocSize(short Width, short Height); // [id(0x8033), method]
    void VLine(TAutoVal& Count); // [id(0x8034), method]
    void HLine(TAutoVal& Count); // [id(0x8035), method]
    void VPage(TAutoVal& Count); // [id(0x8036), method]
    void HPage(TAutoVal& Count); // [id(0x8037), method]
    double VScroll(TAutoVal& Percentage); // [id(0x8038), method]
    double HScroll(TAutoVal& Percentage); // [id(0x8039), method]
    short CountWindows(); // [id(0x803a), method]
    TAutoString WindowName(TAutoVal& Number); // [id(0x803b), method]
    short WindowPane(); // [id(0x803c), method]
    // Splits the active window horizontally and then adjusts the split
    short DocSplit(TAutoVal& Percentage); // [id(0x803d), method]
    short Window(); // [id(0x803e), method]
    // Changes the size of the application window
    void AppSize(TAutoString WindowName, short Width, TAutoVal& Heigth); // [id(0x803f), method]
    // Changes the position of the application window
    void AppMove(TAutoString WindowName, short HorizPos, TAutoVal& VertPos); // [id(0x8040), method]
    // Minimizes the application window to an icon
    short AppMinimize(TAutoVal& WindowName, TAutoVal& State); // [id(0x8041), method]
    // Enlarges the application window to full size
    short AppMaximize(TAutoVal& WindowName, TAutoVal& State); // [id(0x8042), method]
    // Restores the application window to normal size
    short AppRestore(TAutoVal& WindowName); // [id(0x8043), method]
    // Enlarges the active window to full size
    short DocMaximize(TAutoVal& State); // [id(0x8044), method]
    TAutoString GetProfileString(TAutoString Section, TAutoVal& KeyName); // [id(0x8045), method]
    short SetProfileString(TAutoString Section, TAutoString KeyName, TAutoVal& Setting); // [id(0x8046), method]
    // Changes the color of the selected text
    short CharColor(TAutoVal& Color); // [id(0x8047), method]
    // Makes the selection bold (toggle)
    short Bold(TAutoVal& On); // [id(0x8048), method]
    // Makes the selection italic (toggle)
    short Italic(TAutoVal& On); // [id(0x8049), method]
    // Makes the selection small capitals (toggle)
    short SmallCaps(TAutoVal& On); // [id(0x804a), method]
    // Makes the selection all capitals (toggle)
    short AllCaps(TAutoVal& On); // [id(0x804b), method]
    // Makes the selection strikethrough (toggle)
    short Strikethrough(TAutoVal& On); // [id(0x804c), method]
    // Makes the selection hidden text (toggle)
    short Hidden(TAutoVal& On); // [id(0x804d), method]
    // Formats the selection with a continuous underline (toggle)
    short Underline(TAutoVal& On); // [id(0x804e), method]
    // Double underlines the selection (toggle)
    short DoubleUnderline(TAutoVal& On); // [id(0x804f), method]
    // Underlines the words but not the spaces in the selection (toggle)
    short WordUnderline(TAutoVal& On); // [id(0x8050), method]
    // Makes the selection superscript (toggle)
    short Superscript(TAutoVal& On); // [id(0x8051), method]
    // Makes the selection subscript (toggle)
    short Subscript(TAutoVal& On); // [id(0x8052), method]
    // Centers the paragraph between the indents
    short CenterPara(); // [id(0x8053), method]
    // Aligns the paragraph at the left indent
    short LeftPara(); // [id(0x8054), method]
    // Aligns the paragraph at the right indent
    short RightPara(); // [id(0x8055), method]
    // Aligns the paragraph at both the left and the right indent
    short JustifyPara(); // [id(0x8056), method]
    // Sets the line spacing to single space
    short SpacePara1(); // [id(0x8057), method]
    // Sets the line spacing to one-and-one-half space
    short SpacePara15(); // [id(0x8058), method]
    // Sets the line spacing to double space
    short SpacePara2(); // [id(0x8059), method]
    // Sets extra spacing above the selected paragraph
    void OpenUpPara(); // [id(0x805a), method]
    // Removes extra spacing above the selected paragraph
    void CloseUpPara(); // [id(0x805b), method]
    short DDEInitiate(TAutoString Application, TAutoString Topic); // [id(0x805c), method]
    void DDETerminate(short ChanNum); // [id(0x805d), method]
    void DDETerminateAll(); // [id(0x805e), method]
    void DDEExecute(short ChanNum, TAutoString Command); // [id(0x805f), method]
    void DDEPoke(short ChanNum, TAutoString Item, TAutoString Data); // [id(0x8060), method]
    TAutoString DDERequest(short ChanNum, TAutoString Item); // [id(0x8061), method]
    void Activate(TAutoString WindowTitle, TAutoVal& PaneNum); // [id(0x8062), method]
    void AppActivate(TAutoString WindowName, TAutoVal& Immediate); // [id(0x8063), method]
    void SendKeys(TAutoString Keys, TAutoVal& Wait); // [id(0x8064), method]
    TAutoString StyleDesc(TAutoString StyleName); // [id(0x8065), method]
    // Prevents a paragraph from splitting across page boundaries
    short ParaKeepLinesTogether(TAutoVal& On); // [id(0x8066), method]
    // Keeps a paragraph and the following paragraph on the same page
    short ParaKeepWithNext(TAutoVal& On); // [id(0x8067), method]
    // Makes the current paragraph start on a new page
    short ParaPageBreakBefore(TAutoVal& On); // [id(0x8069), method]
    // Prevents a page break from leaving a single line of a paragraph on one page
    short ParaWidowOrphanControl(TAutoVal& On); // [id(0x806a), method]
    // Opens a pane for viewing and editing the notes (toggle)
    short ViewFootnotes(); // [id(0x806b), method]
    // Opens the annotation pane for reading annotations (toggle)
    short ViewAnnotations(TAutoVal& On); // [id(0x806c), method]
    // Shows the field codes or results for all fields (toggle)
    short ViewFieldCodes(TAutoVal& On); // [id(0x806d), method]
    // Displays the document without formatting and pictures for faster editing (toggle)
    short ViewDraft(TAutoVal& On); // [id(0x806e), method]
    // Shows or hides the status bar
    short ViewStatusBar(TAutoVal& On); // [id(0x806f), method]
    // Shows or hides the ruler
    short ViewRuler(TAutoVal& On); // [id(0x8070), method]
    short ViewRibbon(TAutoVal& On); // [id(0x8071), method]
    // Displays the page as it will be printed and allows editing
    short ViewPage(); // [id(0x8073), method]
    // Displays a document's outline
    short ViewOutline(); // [id(0x8074), method]
    // Changes the editing view to normal view
    short ViewNormal(); // [id(0x8075), method]
    short ViewMenus(); // [id(0x8076), method]
    // Toggles table gridlines on and off
    short TableGridlines(TAutoVal& On); // [id(0x8077), method]
    // Toggles between showing the first line only or showing all of the body text in the outline
    short OutlineShowFirstLine(TAutoVal& On); // [id(0x8078), method]
    // Toggles the typing mode between replacing and inserting
    short Overtype(TAutoVal& On); // [id(0x8079), method]
    short CountFonts(); // [id(0x807b), method]
    // Changes the font of the selection
    void Font(TAutoString Name, TAutoVal& Size); // [id(0x807c), method]
    // Returns the font name of the selection, or the font name at position Count in the current font list
    TAutoString FontStr(TAutoVal& Count); // [id(0x807a), method]
    // Changes the font size of the selection
    double FontSize(TAutoVal& Size); // [id(0x807d), method]
    short CountLanguages(); // [id(0x807f), method]
    // Identifies the selected text as being in the specified language
    void Language(TAutoString Language); // [id(0x8080), method]
    // Returns the language format of the selected text, or an internal language name
    TAutoString LanguageStr(TAutoVal& Language); // [id(0x807e), method]
    // Removes the selection without putting it on the Clipboard
    void EditClear(TAutoVal& Count); // [id(0xc012), method]
    void FileList(short Number); // [id(0x8082), method]
    // Opens this document
    void File1(); // [id(0x8083), method]
    // Opens this document
    void File2(); // [id(0x8084), method]
    // Opens this document
    void File3(); // [id(0x8085), method]
    // Opens this document
    void File4(); // [id(0x8086), method]
    // Opens this document
    void File5(); // [id(0x8087), method]
    // Opens this document
    void File6(); // [id(0x8088), method]
    // Opens this document
    void File7(); // [id(0x8089), method]
    // Opens this document
    void File8(); // [id(0x808a), method]
    // Opens this document
    void File9(); // [id(0x808b), method]
    // Moves to the next page
    short NextPage(); // [id(0x8094), method]
    // Moves to the previous page
    short PrevPage(); // [id(0x8095), method]
    // Moves to the next object on the page
    short NextObject(); // [id(0x8096), method]
    // Moves to the previous object on the page
    short PrevObject(); // [id(0x8097), method]
    // Turns on extend selection mode and then expands the selection with the direction keys
    void ExtendSelection(TAutoVal& Character); // [id(0x8098), method]
    short ExtendMode(); // [id(0x8099), method]
    short SelType(TAutoVal& Type); // [id(0x809a), method]
    short OutlineLevel(); // [id(0x809b), method]
    double NextTab(double Position); // [id(0x809c), method]
    double PrevTab(double Position); // [id(0x809d), method]
    void DisableInput(TAutoVal& Disable); // [id(0x809e), method]
    // Prompts to save the document and then closes the active window
    void DocClose(TAutoVal& Save); // [id(0x809f), method]
    // Closes all of the windows of the active document
    void FileClose(TAutoVal& Save, TAutoVal& SaveAll); // [id(0x80a0), method]
    TAutoString Files(TAutoVal& FileSpec); // [id(0x80a1), method]
    // Saves all open files, macros, and AutoText entries, prompting for each one separately
    void FileSaveAll(TAutoVal& Save, TAutoVal& OriginalFormat); // [id(0x80a3), method]
    // Displays full pages as they will be printed
    short FilePrintPreview(TAutoVal& On); // [id(0x80a4), method]
    short FilePrintPreviewPages(TAutoVal& PagesAcross); // [id(0x80a6), method]
    void Kill(TAutoString FileName); // [id(0x80ab), method]
    void ChDir(TAutoString Path); // [id(0x80ac), method]
    void MkDir(TAutoString Name); // [id(0x80ad), method]
    void RmDir(TAutoString Name); // [id(0x80ae), method]
    TAutoString UCase(TAutoString Source); // [id(0x80af), method]
    TAutoString LCase(TAutoString Source); // [id(0x80b0), method]
    TAutoString InputBox(TAutoString Prompt, TAutoVal& Title, TAutoVal& Default); // [id(0x80b1), method]
    void OnTime(TAutoString When, TAutoString Name, TAutoVal& Tolerance); // [id(0x80b3), method]
    // Changes the case of the letters in the selection
    short ChangeCase(TAutoVal& Type); // [id(0x80b4), method]
    TAutoString AppInfo(short Type); // [id(0x80b5), method]
    short SelInfo(short Type); // [id(0x80b6), method]
    short CountMacros(TAutoVal& Context, TAutoVal& All, TAutoVal& Global); // [id(0x80b7), method]
    TAutoString MacroName(short Count, TAutoVal& Context, TAutoVal& All, TAutoVal& Global); // [id(0x80b8), method]
    short CountFoundFiles(); // [id(0x80b9), method]
    TAutoString FoundFileName(short Number); // [id(0x80ba), method]
    TAutoString MacroDesc(TAutoString Name); // [id(0x80be), method]
    short CountKeys(TAutoVal& Context); // [id(0x80bf), method]
    short KeyCode(short Coount, TAutoVal& Context, TAutoVal& FirstOrSecond); // [id(0x80c0), method]
    TAutoString KeyMacro(short Count, TAutoVal& Context); // [id(0x80c1), method]
    void MacroCopy(TAutoString Macro1, TAutoString Macro2, TAutoVal& ExecuteOnly); // [id(0x80c2), method]
    short IsExecuteOnly(TAutoVal& Macro); // [id(0x80c3), method]
    short CommandValid(TAutoString CommandName); // [id(0x80c4), method]
    // Moves to the next field
    short NextField(); // [id(0x80cd), method]
    // Moves to the previous field
    short PrevField(); // [id(0x80ce), method]
    // Moves to the next table cell
    short NextCell(); // [id(0x80cf), method]
    // Moves to the previous table cell
    short PrevCell(); // [id(0x80d0), method]
    // Moves to the first cell in the current row
    short StartOfRow(TAutoVal& Select); // [id(0x80d1), method]
    // Moves to the last cell in the current row
    short EndOfRow(TAutoVal& Select); // [id(0x80d2), method]
    // Moves to the first cell in the current column
    short StartOfColumn(TAutoVal& Select); // [id(0x80d3), method]
    // Moves to the last cell in the current column
    short EndOfColumn(TAutoVal& Select); // [id(0x80d4), method]
//  void ExitWindows(); // [id(0x80d5), method]
    void DisableAutoMacros(TAutoVal& Disable); // [id(0x80d6), method]
    short EditFindFound(); // [id(0x80d7), method]
    // Calculates expressions in the selection
    double ToolsCalculate(TAutoVal& Expression); // [id(0x80dd), method]
    // Switches to the window containing the specified document
    void WindowList(short Number); // [id(0x80de), method]
    void Window1(); // [id(0x80df), method]
    void Window2(); // [id(0x80e0), method]
    void Window3(); // [id(0x80e1), method]
    void Window4(); // [id(0x80e2), method]
    void Window5(); // [id(0x80e3), method]
    void Window6(); // [id(0x80e4), method]
    void Window7(); // [id(0x80e5), method]
    void Window8(); // [id(0x80e6), method]
    void Window9(); // [id(0x80e7), method]
    short CountDirectories(TAutoVal& Directory); // [id(0x80e8), method]
    TAutoString GetDirectory(TAutoString Directory, TAutoVal& Count); // [id(0x80e9), method]
    TAutoString LTrim(TAutoString Source); // [id(0x80ea), method]
    TAutoString RTrim(TAutoString Source); // [id(0x80eb), method]
    TAutoString Environ(TAutoString EnvironmentVariable); // [id(0x80ee), method]
    void WaitCursor(short Wait); // [id(0x80ef), method]
    double DateSerial(short Year, short Month, short Day); // [id(0x80f0), method]
    double DateValue(TAutoString DateText); // [id(0x80f1), method]
    short Day(double SerialNumber); // [id(0x80f2), method]
    long Days360(TAutoString StartDate, TAutoString EndDate); // [id(0x80f3), method]
    short Hour(double SerialNumber); // [id(0x80f4), method]
    short Minute(double SerialNumber); // [id(0x80f5), method]
    short Month(double SerialNumber); // [id(0x80f6), method]
    double Now(); // [id(0x80f7), method]
    short Weekday(double SerialNumber); // [id(0x80f8), method]
    short Year(double SerialNumber); // [id(0x80f9), method]
    short DocWindowHeight(TAutoVal& Height); // [id(0x80fa), method]
    short DocWindowWidth(TAutoVal& Width); // [id(0x80fb), method]
    TAutoString DOSToWin(TAutoString StringToTranslate); // [id(0x80fc), method]
    TAutoString WinToDOS(TAutoString StringToTranslate); // [id(0x80fd), method]
    double TimeSerial(short Hour, short Minute, short Second); // [id(0x80fe), method]
    short Second(double SerialNumber); // [id(0x80ff), method]
    double TimeValue(TAutoString TimeText); // [id(0x8100), method]
    double Today(); // [id(0x8101), method]
    void ShowAnnotationBy(TAutoString ReviewerName); // [id(0x8102), method]
    void SetAttr(TAutoString FileName, short Attribute); // [id(0x8103), method]
    // Minimizes the active window to an icon
    short DocMinimize(); // [id(0x8105), method]
    TAutoString GetSystemInfo(short Type); // [id(0x810c), method]
    void AppClose(TAutoVal& WindowName); // [id(0x8107), method]
    short AppCount(); // [id(0x8108), method]
    void AppHide(TAutoVal& WindowName); // [id(0x810a), method]
    short AppIsRunning(TAutoString WindowName); // [id(0x810b), method]
    TAutoString GetPrivateProfileString(TAutoString Section, TAutoString KeyName, TAutoString FileName); // [id(0x810d), method]
    short SetPrivateProfileString(TAutoString Section, TAutoString KeyName, TAutoString Setting, TAutoString FileName); // [id(0x810e), method]
    short GetAttr(TAutoString FileName); // [id(0x810f), method]
    void AppSendMessage(TAutoString WindowName, double Message, double Wparam, TAutoVal& Lparam); // [id(0x8110), method]
    short ScreenUpdating(TAutoVal& On); // [id(0x8111), method]
    short AppWindowPosTop(TAutoVal& WindowName, TAutoVal& VertPos); // [id(0x8112), method]
    // Applies an existing style or records a style by example
    void Style(TAutoString StyleName); // [id(0x8113), method]
    TAutoString MailMergeDataSource(short Type); // [id(0x8114), method]
    short MailMergeState(short Type); // [id(0x8115), method]
    void SelectCurWord(); // [id(0x8116), method]
    void SelectCurSentence(); // [id(0x8117), method]
    short IsTemplateDirty(); // [id(0x8118), method]
    void SetTemplateDirty(TAutoVal& Dirty); // [id(0x8119), method]
    // Selects or clears the AutoCorrect SmartQuotes check box
    short ToolsAutoCorrectSmartQuotes(TAutoVal& On); // [id(0x811a), method]
    void AppShow(TAutoVal& WindowName); // [id(0x8121), method]
    // Opens a pane for viewing and editing the endnotes (toggle)
    short ViewEndnoteArea(TAutoVal& On); // [id(0x8124), method]
    short MailMergeMainDocumentType(TAutoVal& Type); // [id(0x8128), method]
    short CountToolsGrammarStatistics(); // [id(0x8132), method]
    // Underlines the selection with dots (toggle)
    short DottedUnderline(TAutoVal& On); // [id(0x8133), method]
    // Displays the specified record in the active mail merge data source
    long MailMergeGoToRecord(TAutoVal& RecordNumber); // [id(0x8139), method]
    // Changes border line styles of the selected paragraphs, table cells, and pictures
    short BorderLineStyle(TAutoVal& Style); // [id(0x813b), method]
    // Changes shading pattern of the selected paragraphs, table cells, and pictures
    short ShadingPattern(TAutoVal& Type); // [id(0x813c), method]
    TAutoString MenuItemText(TAutoString Menu, short Type, short Item, TAutoVal& Context); // [id(0x813d), method]
    TAutoString MenuItemMacro(TAutoString Menu, short Type, short Item, TAutoVal& Context); // [id(0x813e), method]
    short CountMenus(short Type, TAutoVal& Context); // [id(0x813f), method]
    TAutoString MenuText(short Type, short MenuNumber, TAutoVal& Context); // [id(0x8140), method]
    short CountMenuItems(TAutoString Menu, short Type, TAutoVal& Context); // [id(0x8141), method]
    short AppWindowPosLeft(TAutoVal& WindowName, TAutoVal& HorizPos); // [id(0x8142), method]
    short AppWindowHeight(TAutoVal& WindowName, TAutoVal& Height); // [id(0x8143), method]
    short AppWindowWidth(TAutoVal& WindowName, TAutoVal& Width); // [id(0x8144), method]
    short DocWindowPosTop(TAutoVal& Position); // [id(0x8145), method]
    short DocWindowPosLeft(TAutoVal& Position); // [id(0x8146), method]
    void RenameMenu(TAutoString Menu, TAutoString NewName, short Type, TAutoVal& Context); // [id(0x8149), method]
    // Closes all of the windows of all documents
    void FileCloseAll(TAutoVal& Save, TAutoVal& SaveAll); // [id(0x814a), method]
    short SetDocumentVar(TAutoString VariableName, TAutoString VariableText); // [id(0x814c), method]
    TAutoString GetDocumentVar(TAutoString VariableName); // [id(0x814d), method]
    TAutoString AnnotationRefFromSel(); // [id(0x814e), method]
    void SetFormResult(TAutoString BookmarkName, TAutoVal& Result, TAutoVal& DefaultResult); // [id(0x8150), method]
    void EnableFormField(TAutoString BookmarkName, short Enable); // [id(0x8151), method]
    short IsMacro(TAutoVal& WindowName); // [id(0x8152), method]
    TAutoString FileNameFromWindow(TAutoVal& WindowNumber); // [id(0x8153), method]
    TAutoString MacroNameFromWindow(TAutoVal& WindowNumber); // [id(0x8154), method]
    TAutoString GetFieldData(); // [id(0x8155), method]
    short PutFieldData(TAutoString FeildData); // [id(0x8156), method]
    // Toggles converting Word for the Macintosh mail merge chevrons
    short MailMergeConvertChevrons(TAutoVal& Convert); // [id(0x8157), method]
    // Toggles asking the user about converting Word for the Macintosh mail merge chevrons
    short MailMergeAskToConvertChevrons(TAutoVal& Prompt); // [id(0x8158), method]
    // Inserts index entries using an automark file
    short AutoMarkIndexEntries(TAutoVal& ConcordanceFilename); // [id(0x815a), method]
    void MoveToolbar(TAutoString Toolbar, short Dock, short HorizPos, short VertPos); // [id(0x815b), method]
    void SizeToolbar(TAutoString Toolbar, short Width); // [id(0x815c), method]
    short DrawSetRange(TAutoString Bookmark); // [id(0x815d), method]
    void DrawClearRange(); // [id(0x815f), method]
    short DrawCount(); // [id(0x8160), method]
    short DrawSelect(short Object); // [id(0x8161), method]
    short DrawExtendSelect(short Count); // [id(0x8162), method]
    void DrawSetInsertToTextbox(TAutoVal& Object); // [id(0x8163), method]
    void DrawSetInsertToAnchor(TAutoVal& Object); // [id(0x8164), method]
    short DrawGetType(TAutoVal& Count); // [id(0x8165), method]
    short DrawCountPolyPoints(TAutoVal& Object); // [id(0x8166), method]
    // Toggle zoom-in zoom-out mode
    short Magnifier(TAutoVal& On); // [id(0x816b), method]
    long GetSelStartPos(); // [id(0x816f), method]
    long GetSelEndPos(); // [id(0x8170), method]
    void SetSelRange(long Pos1, long Pos2); // [id(0x8171), method]
    TAutoString GetText(long Pos1, long Pos2); // [id(0x8172), method]
    void MoveButton(TAutoString SourceToolbar, short SourcePosition, TAutoString TargetToolbar, short TargetpPosition, TAutoVal& Copy, TAutoVal& Context); // [id(0x8173), method]
    void DeleteButton(TAutoString Toolbar, short Position, TAutoVal& Context); // [id(0x8174), method]
    void AddButton(TAutoString Toolbar, short Position, short Category, TAutoString Name, TAutoVal& ButtonTxtOrImageNum, TAutoVal& Context, TAutoVal& CommandValue); // [id(0x8175), method]
    void DeleteAddIn(TAutoString AddIn); // [id(0x8177), method]
    short AddAddIn(TAutoString AddIn, TAutoVal& Load); // [id(0x8178), method]
    TAutoString GetAddInName(short AddInID); // [id(0x8179), method]
    // Creates a bulleted list based on the current defaults
    short FormatBulletDefault(TAutoVal& Add); // [id(0x817a), method]
    // Creates a numbered list based on the current defaults
    short FormatNumberDefault(TAutoVal& On); // [id(0x817b), method]
    // Reset the image on the selected button to the built-in image
    void ResetButtonImage(TAutoString Toolbar, short Tool, TAutoVal& Context); // [id(0x817c), method]
    // Makes the selected paragraphs skip numbering
    short SkipNumbering(); // [id(0x817e), method]
    short GetAddInId(TAutoString AddIn); // [id(0x8180), method]
    short CountAddIns(); // [id(0x8181), method]
    void ClearAddIns(short RemoveFromList); // [id(0x8182), method]
    short AddInState(TAutoString AddIn, TAutoVal& Load); // [id(0x8183), method]
    short ToolsRevisionType(); // [id(0x8184), method]
    TAutoString ToolsRevisionAuthor(); // [id(0x8185), method]
    // Returns the Date and Time the selected revision was made as number
    double ToolsRevisionDate(); // [id(0x8186), method]
    // Returns the Date and Time the selected revision was made as string
    TAutoString ToolsRevisionDateStr(); // [id(0x818a), method]
    // Toggles between viewing merge fields and actual data
    short MailMergeViewData(TAutoVal& DisplayResults); // [id(0x8187), method]
    void AddDropDownItem(TAutoString BookmarkName, TAutoString ItemText); // [id(0x8188), method]
    void RemoveDropDownItem(TAutoString BookmarkName, TAutoString ItemText); // [id(0x8189), method]
    // Toggles table headings attribute on and off
    short TableHeadings(TAutoVal& On); // [id(0x818b), method]
    TAutoString DefaultDir(short Type); // [id(0x818c), method]
    TAutoString FileNameInfo(TAutoString FileName, short InfoType); // [id(0x818d), method]
    TAutoString MacroFileName(TAutoVal& MacroName); // [id(0x818e), method]
    // Displays header in page layout view
    short ViewHeader(); // [id(0x818f), method]
    // Displays footer in page layout view
    short ViewFooter(); // [id(0x8190), method]
    // Paste the image on the Clipboard onto the selected button
    void PasteButtonImage(TAutoString Toolbar, short Tool, TAutoVal& Context); // [id(0x8191), method]
    // Copy the image of the selected button to the Clipboard
    void CopyButtonImage(TAutoString Toolbar, short Tool, TAutoVal& Context); // [id(0x8192), method]
    // Edit the image on the selected button
    void EditButtonImage(TAutoString Toolbar, short Position, TAutoVal& Context); // [id(0x8194), method]
    short CountToolbars(TAutoVal& Context); // [id(0x8195), method]
    TAutoString ToolbarName(short Toolbar, TAutoVal& Context); // [id(0x8196), method]
    void ChDefaultDir(TAutoString Path, short Type); // [id(0x8198), method]
    // Reverses the last action
    void EditUndo(); // [id(0x8199), method]
    // Redoes the last action that was undone
    void EditRedo(); // [id(0x819a), method]
    // Switches to master document view
    short ViewMasterDocument(); // [id(0x819b), method]
    // Selects or clears the AutoCorrect ReplaceText check box
    short ToolsAutoCorrectReplaceText(TAutoVal& On); // [id(0x819c), method]
    // Selects or clears the AutoCorrect InitialCaps check box
    short ToolsAutoCorrectInitialCaps(TAutoVal& On); // [id(0x819d), method]
    // Selects or clears the AutoCorrect SentenceCaps check box
    short ToolsAutoCorrectSentenceCaps(TAutoVal& On); // [id(0x819e), method]
    // Selects or clears the AutoCorrect Days check box
    short ToolsAutoCorrectDays(TAutoVal& On); // [id(0x819f), method]
    TAutoString GetAutoCorrect(TAutoString AutoCorrectEntry); // [id(0x81a0), method]
    // Opens a pane for viewing and editing the footnotes (toggle)
    short ViewFootnoteArea(TAutoVal& On); // [id(0x81a1), method]
    short ConverterLookup(TAutoString FormatName); // [id(0x81a3), method]
    // Toggles asking the user to confirm the conversion when opening a file.
    short FileConfirmConversions(TAutoVal& On); // [id(0x81a4), method]
    TAutoString GetMergeField(TAutoString FieldName); // [id(0x81a5), method]
    TAutoString Converter(short FormatNumber); // [id(0x81a6), method]
    short MailMergeFoundRecord(); // [id(0x81a7), method]
    short CountDocumentVars(); // [id(0x81a8), method]
    TAutoString GetDocumentVarName(short VariableNumber); // [id(0x81a9), method]
    TAutoString CleanString(TAutoString Source); // [id(0x81ab), method]
    TAutoString PathFromWinPath(TAutoString Path); // [id(0x81ac), method]
    TAutoString PathFromMacPath(TAutoString Path); // [id(0x81ad), method]
    // Toggles the file lock state of a document
    short LockDocument(TAutoVal& Lock); // [id(0x81d0), method]
    void GoToNextSubdocument(); // [id(0x81d1), method]
    void GoToPreviousSubdocument(); // [id(0x81d2), method]
    TAutoString SelectionFileName(); // [id(0x81d3), method]
    // Applies the Symbol font to the selection
    void SymbolFont(TAutoVal& TextToInsert); // [id(0x81d4), method]
    void RemoveAllDropDownItems(TAutoString BookmarkName); // [id(0x81d5), method]
    // Changes shading options for the current form
    short FormShading(TAutoVal& On); // [id(0x81d6), method]
    // Returns a number corresponding to the setting of a checkbox form filed or drop-down form field marked by the specified bookmark name
    short GetFormResult(TAutoString BookmarkName); // [id(0x81d7), method]
    // Returns a string corresponding to the setting form field marked by the specified bookmark name
    TAutoVal GetFormResultStr(TAutoString BookmarkName); // [id(0x814f), method]
    short ToolbarState(TAutoString Toolbar); // [id(0x81d8), method]
    short CountToolbarButtons(TAutoString Toolbar, TAutoVal& Context); // [id(0x81d9), method]
    TAutoString ToolbarButtonMacro(TAutoString Toolbar, short Position, TAutoVal& Context); // [id(0x81da), method]
    short AtEndOfDocument(); // [id(0x81dc), method]
    short AtStartOfDocument(); // [id(0x81dd), method]
    TAutoString FieldSeparator(TAutoVal& Separator); // [id(0x81e0), method]
    // Moves the insertion point to the left one character
    short CharLeft(TAutoVal& Count, TAutoVal& Select); // [id(0xc000), method]
    // Moves the insertion point to the right one character
    short CharRight(TAutoVal& Count, TAutoVal& Select); // [id(0xc001), method]
    // Moves the insertion point to the left one word
    short WordLeft(TAutoVal& Count, TAutoVal& Select); // [id(0xc002), method]
    // Moves the insertion point to the right one word
    short WordRight(TAutoVal& Count, TAutoVal& Select); // [id(0xc003), method]
    // Moves the insertion point to the beginning of the previous sentence
    short SentLeft(TAutoVal& Count, TAutoVal& Select); // [id(0xc004), method]
    // Moves the insertion point to beginning of the next sentence
    short SentRight(TAutoVal& Count, TAutoVal& Select); // [id(0xc005), method]
    // Moves the insertion point to the beginning of the previous paragraph
    short ParaUp(TAutoVal& Count, TAutoVal& Select); // [id(0xc006), method]
    // Moves the insertion point to the beginning of the next paragraph
    short ParaDown(TAutoVal& Count, TAutoVal& Select); // [id(0xc007), method]
    // Moves the insertion point up one line
    short LineUp(TAutoVal& Count, TAutoVal& Select); // [id(0xc008), method]
    // Moves the insertion point down one line
    short LineDown(TAutoVal& Count, TAutoVal& Select); // [id(0xc009), method]
    // Moves the insertion point and document display to the previous screen of text
    short PageUp(TAutoVal& Count, TAutoVal& Select); // [id(0xc00a), method]
    // Moves the insertion point and document display to the next screen of text
    short PageDown(TAutoVal& Count, TAutoVal& Select); // [id(0xc00b), method]
    // Moves the insertion point to the beginning of the current line
    short StartOfLine(TAutoVal& Select); // [id(0xc00c), method]
    // Moves the insertion point to the end of the current line
    short EndOfLine(TAutoVal& Select); // [id(0xc00d), method]
    // Moves the insertion point to the beginning of the first visible line on the screen
    short StartOfWindow(TAutoVal& Select); // [id(0xc00e), method]
    // Moves the insertion point to the end of the last visible line on the screen
    short EndOfWindow(TAutoVal& Select); // [id(0xc00f), method]
    // Moves the insertion point to the beginning of the first line of the document
    short StartOfDocument(TAutoVal& Select); // [id(0xc010), method]
    // Moves the insertion point to the end of the last line of the document
    short EndOfDocument(TAutoVal& Select); // [id(0xc011), method]
    // Changes the outside borders of the selected paragraphs, table cells, and pictures
    short BorderOutside(TAutoVal& On); // [id(0xc018), method]
    // Removes borders from the selected paragraphs, table cells, and pictures
    short BorderNone(TAutoVal& Remove); // [id(0xc019), method]
    // Changes the top borders of the selected paragraphs, table cells, and pictures
    short BorderTop(TAutoVal& On); // [id(0xc024), method]
    // Changes the left border of the selected paragraphs, table cells, and pictures
    short BorderLeft(TAutoVal& On); // [id(0xc025), method]
    // Changes the bottom border of the selected paragraphs, table cells, and pictures
    short BorderBottom(TAutoVal& On); // [id(0xc026), method]
    // Changes the right border of the selected paragraphs, table cells, and pictures
    short BorderRight(TAutoVal& On); // [id(0xc027), method]
    // Changes the inside borders of the selected paragraphs, table cells, and pictures
    short BorderInside(TAutoVal& On); // [id(0xc028), method]
    // (Word 95 only)
    short DocumentProtection(); // [id(0xc02b), method]
    // (Word 95 only)
    short IsAutoCorrectException(TAutoVal& Tab, TAutoString Source); // [id(0x820c), method]
    // (Word 95 only)
    void MailCheckNames(); // [id(774), method]
    // (Word 95 only)
    void MailHideMessageHeader(); // [id(763), method]
    // (Word 95 only)
    void MailMessageDelete(); // [id(771), method]
    // (Word 95 only)
    void MailMessageForward(); // [id(776), method]
    // (Word 95 only)
    void MailMessageMove(); // [id(770), method]
    // (Word 95 only)
    void MailMessageNext(); // [id(773), method]
    // (Word 95 only)
    void MailMessagePrevious(); // [id(772), method]
    // (Word 95 only)
    void MailMessageProperties(); // [id(764), method]
    // (Word 95 only)
    void MailMessageReply(); // [id(768), method]
    // (Word 95 only)
    void MailMessageReplyAll(); // [id(769), method]
    // (Word 95 only)
    void MailSelectNames(); // [id(775), method]
    // (Word 95 only)
    void AutomaticChange(); // [id(4070), method]
    // (Word 95 only)
    short CountAutoCorrectExceptions(short Tab); // [id(0x820a), method]
    // (Word 95 only)
    short CountDocumentProperties(); // [id(0x81fb), method]
    // (Word 95 only)
    void DeleteDocumentProperty(TAutoString PropertyName); // [id(0x8200), method]
    // (Word 95 only)
    short DocumentHasMisspellings(); // [id(0x81f9), method]
    // (Word 95 only)
    short DocumentPropertyExists(TAutoString PropertyName); // [id(0x8204), method]
    // (Word 95 only)
    TAutoString DocumentPropertyName(short PropertyNumber); // [id(0x8201), method]
    // (Word 95 only)
    short DocumentPropertyType(TAutoString PropertyName); // [id(7941), method]
    // (Word 95 only)
    void EditFindHighlight(); // [id(780), method]
    // (Word 95 only)
    void EditFindNotHighlight(); // [id(782), method]
    // (Word 95 only)
    void EditReplaceHighlight(); // [id(781), method]
    // (Word 95 only)
    void EditReplaceNotHighlight(); // [id(783), method]
    // (Word 95 only)
    void FilePost(TAutoString FolderName); // [id(760), method]
    // (Word 95 only)
    void FileProperties(); // [id(750), method]
    // (Word 95 only)
    TAutoString GetAutoCorrectException(short Tab, short EntryNumber); // [id(0x820b), method]
    // (Word 95 only)
    TAutoString GetAddress(TAutoVal& Name, TAutoVal& Addressproperties, TAutoVal& UseAutoText, TAutoVal& DisplaySelectDialog, TAutoVal& SelectDialogModus, TAutoVal& CheckResolveNamesDialog, TAutoVal& MRUChoice, TAutoVal& UpdateMRU); // [id(0x81fa), method]
    // (Word 95 only)
    TAutoString GetDocumentPropertyStr(TAutoString Name, TAutoVal& CustomOrBuildIn); // [id(0x81fc), method]
    // (Word 95 only)
    long GetDocumentProperty(TAutoString Name, TAutoVal& CustomOrBuildIn); // [id(0x81fd), method]
    // (Word 95 only)
    void InsertAddress(); // [id(758), method]
    // (Word 95 only)
    short IsCustomDocumentProperty(TAutoString Name); // [id(0x8203), method]
    // (Word 95 only)
    short IsDocumentPropertyReadOnly(TAutoString Name); // [id(0x8202), method]
    // (Word 95 only)
    void MailMergeUseAddressBook(short AddressBookType); // [id(779), method]
    // (Word 95 only)
    void NextMisspelling(); // [id(759), method]
    // (Word 95 only)
    void SetDocumentProperty(TAutoString Name, short Type, TAutoVal& Value, short CustomOrBuiltIn); // [id(0x81fe), method]
    // (Word 95 only)
    void SetDocumentPropertyLink(TAutoString Name, TAutoString Source); // [id(0x81ff), method]
    // (Word 95 only)
    void ShowMe(); // [id(4068), method]
    // (Word 95 only)
    TAutoVal SpellChecked(short Yes); // [id(0x820e), method]
    // (Word 95 only)
    void TipWizard(); // [id(4067), method]
    // (Word 95 only)
    TAutoVal ToolsAutoCorrectCapsLockOff(TAutoVal& On); // [id(767), method]
    // (Word 95 only)
    void ToolsAutoCorrectExceptions(short Tab, TAutoString Name, short AutoAdd, TAutoVal& Add, TAutoVal& Delete); // [id(762), method]
    // (Word 95 only)
    void ToolsSpellingRecheckDocument(); // [id(777), method]
};
