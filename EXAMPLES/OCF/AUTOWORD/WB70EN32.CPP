#include "WB70EN32.HXX"

// TKIND_DISPATCH: WordBasic 7.0 {00020400-0000-0000-C000-000000000046}\9

void WordBasic::AOCEAddRecipient(TAutoString Recipient, short AddressType, TAutoString Mailslot)
{
  AUTONAMES0("AOCEAddRecipient")
  AUTOARGS3(Recipient, AddressType, Mailslot)
  AUTOCALL_METHOD_VOID
}

short WordBasic::AOCEAuthenticateUser(short AllowPrompt)
{
  AUTONAMES0("AOCEAuthenticateUser")
  AUTOARGS1(AllowPrompt)
  AUTOCALL_METHOD_RET
}

void WordBasic::AOCEClearMailerField(short FieldNumber)
{
  AUTONAMES0("AOCEClearMailerField")
  AUTOARGS1(FieldNumber)
  AUTOCALL_METHOD_VOID
}

short WordBasic::AOCECountRecipients(short AddressType)
{
  AUTONAMES0("AOCECountRecipients")
  AUTOARGS1(AddressType)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::AOCEGetRecipient(short RecipientNumber, short AddressType)
{
  AUTONAMES0("AOCEGetRecipient")
  AUTOARGS2(RecipientNumber, AddressType)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::AOCEGetSender()
{
  AUTONAMES0("AOCEGetSender")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::AOCEGetSubject()
{
  AUTONAMES0("AOCEGetSubject")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::AOCESendMail(short SignLetter, short Priority, short SendAppleMail, short SendImage, short SendWordDoc, TAutoString Format)
{
  AUTONAMES0("AOCESendMail")
  AUTOARGS6(SignLetter, Priority, SendAppleMail, SendImage, SendWordDoc, Format)
  AUTOCALL_METHOD_VOID
}

void WordBasic::AOCESetSubject(TAutoString Subject)
{
  AUTONAMES0("AOCESetSubject")
  AUTOARGS1(Subject)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditCopyAsPicture()
{
  AUTONAMES0("EditCopyAsPicture")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditCreatePublisher(TAutoString FileName, short Apperance, short RTF, short Pict)
{
  AUTONAMES0("EditCreatePublisher")
  AUTOARGS4(FileName, Apperance, RTF, Pict)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditFindBorder(short ApplyTo, short Shadow, short TopBorder, short LeftBorder, short BottomBorder, short RightBorder, short HorizBorder, short VertBorder, short TopColor, short LeftColor, short BottomColor, short RightColor, short HorizColor, short VertColor, TAutoVal& FromText, short Shading, short Foreground, short Background, short Tab, short FineShading)
{
  AUTONAMES0("EditFindBorder")
  AUTOARGS20(ApplyTo, Shadow, TopBorder, LeftBorder, BottomBorder, RightBorder, HorizBorder, VertBorder, TopColor, LeftColor, BottomColor, RightColor, HorizColor, VertColor, FromText, Shading, Foreground, Background, Tab, FineShading)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditFindFrame(short Wrap, short WidthRule, TAutoVal& FixedWidth, short HeightRule, TAutoVal& FixedHeight, TAutoVal& PositionHorz, short PositionHorzRel, TAutoVal& DistFromText, TAutoVal& PositionVert, short PositionVertRel, TAutoVal& DistVertFromText, short MoveWithText, short LockAnchor, TAutoVal& RemoveFrame)
{
  AUTONAMES0("EditFindFrame")
  AUTOARGS14(Wrap, WidthRule, FixedWidth, HeightRule, FixedHeight, PositionHorz, PositionHorzRel, DistFromText, PositionVert, PositionVertRel, DistVertFromText, MoveWithText, LockAnchor, RemoveFrame)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditFindTabs(TAutoString Position, TAutoString DefTabs, short Align, short Leader, TAutoVal& Set, TAutoVal& Clear, TAutoVal& ClearAll)
{
  AUTONAMES0("EditFindTabs")
  AUTOARGS7(Position, DefTabs, Align, Leader, Set, Clear, ClearAll)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditPublishOptions(short SendManually, short SendEditionNow, short SendEditionWhenEdited, TAutoVal& Delete, short Apperance, short RTF, short Pict)
{
  AUTONAMES0("EditPublishOptions")
  AUTOARGS7(SendManually, SendEditionNow, SendEditionWhenEdited, Delete, Apperance, RTF, Pict)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditReplaceBorder(short ApplyTo, short Shadow, short TopBorder, short LeftBorder, short BottomBorder, short RightBorder, short HorizBorder, short VertBorder, short TopColor, short LeftColor, short BottomColor, short RightColor, short HorizColor, short VertColor, TAutoVal& FromText, short Shading, short Foreground, short Background, short Tab, short FineShading)
{
  AUTONAMES0("EditReplaceBorder")
  AUTOARGS20(ApplyTo, Shadow, TopBorder, LeftBorder, BottomBorder, RightBorder, HorizBorder, VertBorder, TopColor, LeftColor, BottomColor, RightColor, HorizColor, VertColor, FromText, Shading, Foreground, Background, Tab, FineShading)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditReplaceFrame(short Wrap, short WidthRule, TAutoVal& FixedWidth, short HeightRule, TAutoVal& FixedHeight, TAutoVal& PositionHorz, short PositionHorzRel, TAutoVal& DistFromText, TAutoVal& PositionVert, short PositionVertRel, TAutoVal& DistVertFromText, short MoveWithText, short LockAnchor, TAutoVal& RemoveFrame)
{
  AUTONAMES0("EditReplaceFrame")
  AUTOARGS14(Wrap, WidthRule, FixedWidth, HeightRule, FixedHeight, PositionHorz, PositionHorzRel, DistFromText, PositionVert, PositionVertRel, DistVertFromText, MoveWithText, LockAnchor, RemoveFrame)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditReplaceTabs(TAutoString Position, TAutoString DefTabs, short Align, short Leader, TAutoVal& Set, TAutoVal& Clear, TAutoVal& ClearAll)
{
  AUTONAMES0("EditReplaceTabs")
  AUTOARGS7(Position, DefTabs, Align, Leader, Set, Clear, ClearAll)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditSubscribeOptions(short GetManually, short GetEditionNow, short Format, short KeepFormatting)
{
  AUTONAMES0("EditSubscribeOptions")
  AUTOARGS4(GetManually, GetEditionNow, Format, KeepFormatting)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditSubscribeTo(TAutoString FileName, short Format, short GetManually)
{
  AUTONAMES0("EditSubscribeTo")
  AUTOARGS3(FileName, Format, GetManually)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileAOCEAddMailer()
{
  AUTONAMES0("FileAOCEAddMailer")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileAOCEDeleteMailer()
{
  AUTONAMES0("FileAOCEDeleteMailer")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileAOCEExpandMailer()
{
  AUTONAMES0("FileAOCEExpandMailer")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileAOCEForwardMail()
{
  AUTONAMES0("FileAOCEForwardMail")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileAOCENextLetter()
{
  AUTONAMES0("FileAOCENextLetter")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileAOCEReplyAllMail()
{
  AUTONAMES0("FileAOCEReplyAllMail")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileAOCEReplyMail()
{
  AUTONAMES0("FileAOCEReplyMail")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileAOCESendMail()
{
  AUTONAMES0("FileAOCESendMail")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::FileCreator(TAutoString File)
{
  AUTONAMES0("FileCreator")
  AUTOARGS1(File)
  AUTOCALL_METHOD_RET
}

void WordBasic::FileMacCustomPageSetupGX(TAutoVal& PageWidth, TAutoVal& PageHeight, short Orientation, short ApplyPropsTo)
{
  AUTONAMES0("FileMacCustomPageSetupGX")
  AUTOARGS4(PageWidth, PageHeight, Orientation, ApplyPropsTo)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileMacPageSetup(TAutoVal& PageWidth, TAutoVal& PageHeight, short Orientation, short ApplyPropsTo, TAutoVal& Default)
{
  AUTONAMES0("FileMacPageSetup")
  AUTOARGS5(PageWidth, PageHeight, Orientation, ApplyPropsTo, Default)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileMacPageSetupGX(TAutoVal& PageWidth, TAutoVal& PageHeight, short Orientation)
{
  AUTONAMES0("FileMacPageSetupGX")
  AUTOARGS3(PageWidth, PageHeight, Orientation)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FilePrintOneCopy()
{
  AUTONAMES0("FilePrintOneCopy")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::FileType(TAutoString File)
{
  AUTONAMES0("FileType")
  AUTOARGS1(File)
  AUTOCALL_METHOD_RET
}

void WordBasic::ListCommands(TAutoVal& ListType)
{
  AUTONAMES0("ListCommands")
  AUTOARGS1(ListType)
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::MacID(TAutoString Identifier)
{
  AUTONAMES0("MacID")
  AUTOARGS1(Identifier)
  AUTOCALL_METHOD_RET
}

void WordBasic::MacScript()
{
  AUTONAMES0("MacScript")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::MacScriptStr(TAutoString Script)
{
  AUTONAMES0("MacScriptStr")
  AUTOARGS1(Script)
  AUTOCALL_METHOD_RET
}

short WordBasic::MountVolume(TAutoString Zone, TAutoString Server, TAutoString Volume, TAutoString User, TAutoString UserPassword, TAutoString VolumePassword)
{
  AUTONAMES0("MountVolume")
  AUTOARGS6(Zone, Server, Volume, User, UserPassword, VolumePassword)
  AUTOCALL_METHOD_RET
}

void WordBasic::Outline(short On)
{
  AUTONAMES0("Outline")
  AUTOARGS1(On)
  AUTOCALL_METHOD_VOID
}

void WordBasic::SetFileCreatorAndType(TAutoString File, TAutoString Creator, TAutoString Type)
{
  AUTONAMES0("SetFileCreatorAndType")
  AUTOARGS3(File, Creator, Type)
  AUTOCALL_METHOD_VOID
}

void WordBasic::Shadow(short On)
{
  AUTONAMES0("Shadow")
  AUTOARGS1(On)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowClipboard()
{
  AUTONAMES0("ShowClipboard")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Help()
{
  AUTONAMES0("Help")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpMSN()
{
  AUTONAMES0("HelpMSN")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpTool()
{
  AUTONAMES0("HelpTool")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpUsingHelp()
{
  AUTONAMES0("HelpUsingHelp")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpActiveWindow()
{
  AUTONAMES0("HelpActiveWindow")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpKeyboard()
{
  AUTONAMES0("HelpKeyboard")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpIndex()
{
  AUTONAMES0("HelpIndex")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpQuickPreview()
{
  AUTONAMES0("HelpQuickPreview")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpExamplesAndDemos()
{
  AUTONAMES0("HelpExamplesAndDemos")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpAbout(TAutoVal& Appname, TAutoVal& AppCopyright, TAutoVal& AppUserName, TAutoVal& AppOrganization, TAutoVal& AppSerialNumber)
{
  AUTONAMES0("HelpAbout")
  AUTOARGS5(Appname, AppCopyright, AppUserName, AppOrganization, AppSerialNumber)
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpWordPerfectHelp(TAutoVal& WPCommand, TAutoVal& HelpText, TAutoVal& DemoGuidance)
{
  AUTONAMES0("HelpWordPerfectHelp")
  AUTOARGS3(WPCommand, HelpText, DemoGuidance)
  AUTOCALL_METHOD_VOID
}

void WordBasic::GrowFont()
{
  AUTONAMES0("GrowFont")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShrinkFont()
{
  AUTONAMES0("ShrinkFont")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Spike()
{
  AUTONAMES0("Spike")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertSpike()
{
  AUTONAMES0("InsertSpike")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MoveText()
{
  AUTONAMES0("MoveText")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::CopyText()
{
  AUTONAMES0("CopyText")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertAutoText()
{
  AUTONAMES0("InsertAutoText")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::OtherPane()
{
  AUTONAMES0("OtherPane")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::NextWindow()
{
  AUTONAMES0("NextWindow")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::PrevWindow()
{
  AUTONAMES0("PrevWindow")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::RepeatFind()
{
  AUTONAMES0("RepeatFind")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DeleteWord()
{
  AUTONAMES0("DeleteWord")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DeleteBackWord()
{
  AUTONAMES0("DeleteBackWord")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertFieldChars()
{
  AUTONAMES0("InsertFieldChars")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::UpdateFields()
{
  AUTONAMES0("UpdateFields")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::UnlinkFields()
{
  AUTONAMES0("UnlinkFields")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToggleFieldDisplay()
{
  AUTONAMES0("ToggleFieldDisplay")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::LockFields()
{
  AUTONAMES0("LockFields")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::UnlockFields()
{
  AUTONAMES0("UnlockFields")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::UpdateSource()
{
  AUTONAMES0("UpdateSource")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Indent()
{
  AUTONAMES0("Indent")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::UnIndent()
{
  AUTONAMES0("UnIndent")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::HangingIndent()
{
  AUTONAMES0("HangingIndent")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::UnHang()
{
  AUTONAMES0("UnHang")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FontSizeSelect()
{
  AUTONAMES0("FontSizeSelect")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditRepeat()
{
  AUTONAMES0("EditRepeat")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::GoBack()
{
  AUTONAMES0("GoBack")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::SaveTemplate()
{
  AUTONAMES0("SaveTemplate")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::OK()
{
  AUTONAMES0("OK")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Cancel()
{
  AUTONAMES0("Cancel")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::CopyFormat()
{
  AUTONAMES0("CopyFormat")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DocumentStatistics(TAutoVal& FileName, TAutoVal& Directory, TAutoVal& Template, TAutoVal& Title, TAutoVal& Created, TAutoVal& LastSaved, TAutoVal& LastSavedBy, TAutoVal& Revision, TAutoVal& Time, TAutoVal& Printed, TAutoVal& Pages, TAutoVal& Words, TAutoVal& Characters, TAutoVal& Paragraphs, TAutoVal& Lines, TAutoVal& FileSize)
{
  AUTONAMES0("DocumentStatistics")
  AUTOARGS16(FileName, Directory, Template, Title, Created, LastSaved, LastSavedBy, Revision, Time, Printed, Pages, Words, Characters, Paragraphs, Lines, FileSize)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileNew(TAutoVal& Template, TAutoVal& NewTemplate)
{
  AUTONAMES0("FileNew")
  AUTOARGS2(Template, NewTemplate)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileOpen(TAutoVal& Name, TAutoVal& ConfirmConversions, TAutoVal& ReadOnly, TAutoVal& LinkToSource, TAutoVal& AddToMru, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& Revert, TAutoVal& WritePasswordDoc, TAutoVal& WritePasswordDot, TAutoVal& Connection, TAutoVal& SQLStatement, TAutoVal& SQLStatement1)
{
  AUTONAMES0("FileOpen")
  AUTOARGS13(Name, ConfirmConversions, ReadOnly, LinkToSource, AddToMru, PasswordDoc, PasswordDot, Revert, WritePasswordDoc, WritePasswordDot, Connection, SQLStatement, SQLStatement1)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeOpenDataSource(TAutoVal& Name, TAutoVal& ConfirmConversions, TAutoVal& ReadOnly, TAutoVal& LinkToSource, TAutoVal& AddToMru, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& Revert, TAutoVal& WritePasswordDoc, TAutoVal& WritePasswordDot, TAutoVal& Connection, TAutoVal& SQLStatement, TAutoVal& SQLStatement1)
{
  AUTONAMES0("MailMergeOpenDataSource")
  AUTOARGS13(Name, ConfirmConversions, ReadOnly, LinkToSource, AddToMru, PasswordDoc, PasswordDot, Revert, WritePasswordDoc, WritePasswordDot, Connection, SQLStatement, SQLStatement1)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeOpenHeaderSource(TAutoVal& Name, TAutoVal& ConfirmConversions, TAutoVal& ReadOnly, TAutoVal& LinkToSource, TAutoVal& AddToMru, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& Revert, TAutoVal& WritePasswordDoc, TAutoVal& WritePasswordDot, TAutoVal& Connection, TAutoVal& SQLStatement, TAutoVal& SQLStatement1)
{
  AUTONAMES0("MailMergeOpenHeaderSource")
  AUTOARGS13(Name, ConfirmConversions, ReadOnly, LinkToSource, AddToMru, PasswordDoc, PasswordDot, Revert, WritePasswordDoc, WritePasswordDot, Connection, SQLStatement, SQLStatement1)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileSave()
{
  AUTONAMES0("FileSave")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileSaveAs(TAutoVal& Name, TAutoVal& Format, TAutoVal& LockAnnot, TAutoVal& Password, TAutoVal& AddToMru, TAutoVal& WritePassword, TAutoVal& RecommendReadOnly, TAutoVal& EmbedFonts, TAutoVal& NativePictureFormat, TAutoVal& FormsData, TAutoVal& SaveAsAOCELetter)
{
  AUTONAMES0("FileSaveAs")
  AUTOARGS11(Name, Format, LockAnnot, Password, AddToMru, WritePassword, RecommendReadOnly, EmbedFonts, NativePictureFormat, FormsData, SaveAsAOCELetter)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileSummaryInfo(TAutoVal& Title, TAutoVal& Subject, TAutoVal& Author, TAutoVal& Keywords, TAutoVal& Comments, TAutoVal& FileName, TAutoVal& Directory, TAutoVal& Template, TAutoVal& CreateDate, TAutoVal& LastSavedDate, TAutoVal& LastSavedBy, TAutoVal& RevisionNumber, TAutoVal& EditTime, TAutoVal& LastPrintedDate, TAutoVal& NumPages, TAutoVal& NumWords, TAutoVal& NumChars, TAutoVal& NumParas, TAutoVal& NumLines, TAutoVal& Update, TAutoVal& FileSize)
{
  AUTONAMES0("FileSummaryInfo")
  AUTOARGS21(Title, Subject, Author, Keywords, Comments, FileName, Directory, Template, CreateDate, LastSavedDate, LastSavedBy, RevisionNumber, EditTime, LastPrintedDate, NumPages, NumWords, NumChars, NumParas, NumLines, Update, FileSize)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileTemplates(TAutoVal& Store, TAutoVal& Template, TAutoVal& LinkStyles)
{
  AUTONAMES0("FileTemplates")
  AUTOARGS3(Store, Template, LinkStyles)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FilePrint(TAutoVal& Background, TAutoVal& Printer, TAutoVal& OutputPrinter, TAutoVal& AppendPrFile, TAutoVal& Range, TAutoVal& PrToFileName, TAutoVal& From, TAutoVal& To, TAutoVal& Type, TAutoVal& NumCopies, TAutoVal& Pages, TAutoVal& Order, TAutoVal& PrintToFile, TAutoVal& Collate, TAutoVal& FileName)
{
  AUTONAMES0("FilePrint")
  AUTOARGS15(Background, Printer, OutputPrinter, AppendPrFile, Range, PrToFileName, From, To, Type, NumCopies, Pages, Order, PrintToFile, Collate, FileName)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeReset()
{
  AUTONAMES0("MailMergeReset")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FilePrintSetup(TAutoVal& Printer, TAutoVal& Options, TAutoVal& Network, TAutoVal& DoNotSetAsSysDefault)
{
  AUTONAMES0("FilePrintSetup")
  AUTOARGS4(Printer, Options, Network, DoNotSetAsSysDefault)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileFind(TAutoVal& SearchName, TAutoVal& SearchPath, TAutoVal& Name, TAutoVal& SubDir, TAutoVal& Title, TAutoVal& Author, TAutoVal& Keywords, TAutoVal& Subject, TAutoVal& Options, TAutoVal& MatchCase, TAutoVal& Text, TAutoVal& PatternMatch, TAutoVal& DateSavedFrom, TAutoVal& DateSavedTo, TAutoVal& SavedBy, TAutoVal& DateCreatedFrom, TAutoVal& DateCreatedTo, TAutoVal& View, TAutoVal& SortBy, TAutoVal& ListBy, TAutoVal& SelectedFile, TAutoVal& Add, TAutoVal& Delete, TAutoVal& ShowFolders)
{
  AUTONAMES0("FileFind")
  AUTOARGS24(SearchName, SearchPath, Name, SubDir, Title, Author, Keywords, Subject, Options, MatchCase, Text, PatternMatch, DateSavedFrom, DateSavedTo, SavedBy, DateCreatedFrom, DateCreatedTo, View, SortBy, ListBy, SelectedFile, Add, Delete, ShowFolders)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatAddrFonts(TAutoVal& Points, TAutoVal& Underline, TAutoVal& Color, TAutoVal& Strikethrough, TAutoVal& Superscript, TAutoVal& Subscript, TAutoVal& Hidden, TAutoVal& SmallCaps, TAutoVal& AllCaps, TAutoVal& Spacing, TAutoVal& Position, TAutoVal& Kerning, TAutoVal& KerningMin, TAutoVal& Default, TAutoVal& Tab, TAutoVal& Font, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Outline, TAutoVal& Shadow)
{
  AUTONAMES0("FormatAddrFonts")
  AUTOARGS20(Points, Underline, Color, Strikethrough, Superscript, Subscript, Hidden, SmallCaps, AllCaps, Spacing, Position, Kerning, KerningMin, Default, Tab, Font, Bold, Italic, Outline, Shadow)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeEditDataSource()
{
  AUTONAMES0("MailMergeEditDataSource")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditCut()
{
  AUTONAMES0("EditCut")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditCopy()
{
  AUTONAMES0("EditCopy")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditPaste()
{
  AUTONAMES0("EditPaste")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditPasteSpecial(TAutoVal& IconNumber, TAutoVal& Link, TAutoVal& DisplayIcon, TAutoVal& Class, TAutoVal& DataType, TAutoVal& IconFilename, TAutoVal& Caption)
{
  AUTONAMES0("EditPasteSpecial")
  AUTOARGS7(IconNumber, Link, DisplayIcon, Class, DataType, IconFilename, Caption)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditFind(TAutoVal& Find, TAutoVal& Replace, TAutoVal& Direction, TAutoVal& MatchCase, TAutoVal& WholeWord, TAutoVal& PatternMatch, TAutoVal& SoundsLike, TAutoVal& FindNext, TAutoVal& ReplaceOne, TAutoVal& ReplaceAll, TAutoVal& Format, TAutoVal& Wrap, TAutoVal& FindAllWordForms)
{
  AUTONAMES0("EditFind")
  AUTOARGS13(Find, Replace, Direction, MatchCase, WholeWord, PatternMatch, SoundsLike, FindNext, ReplaceOne, ReplaceAll, Format, Wrap, FindAllWordForms)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditFindFont(TAutoVal& Points, TAutoVal& Underline, TAutoVal& Color, TAutoVal& Strikethrough, TAutoVal& Superscript, TAutoVal& Subscript, TAutoVal& Hidden, TAutoVal& SmallCaps, TAutoVal& AllCaps, TAutoVal& Spacing, TAutoVal& Position, TAutoVal& Kerning, TAutoVal& KerningMin, TAutoVal& Default, TAutoVal& Tab, TAutoVal& Font, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Outline, TAutoVal& Shadow)
{
  AUTONAMES0("EditFindFont")
  AUTOARGS20(Points, Underline, Color, Strikethrough, Superscript, Subscript, Hidden, SmallCaps, AllCaps, Spacing, Position, Kerning, KerningMin, Default, Tab, Font, Bold, Italic, Outline, Shadow)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditFindPara(TAutoVal& LeftIndent, TAutoVal& RightIndent, TAutoVal& Before, TAutoVal& After, TAutoVal& LineSpacingRule, TAutoVal& LineSpacing, TAutoVal& Alignment, TAutoVal& WidowControl, TAutoVal& KeepWithNext, TAutoVal& KeepTogether, TAutoVal& PageBreak, TAutoVal& NoLineNum, TAutoVal& DontHyphen, TAutoVal& Tab, TAutoVal& FirstIndent)
{
  AUTONAMES0("EditFindPara")
  AUTOARGS15(LeftIndent, RightIndent, Before, After, LineSpacingRule, LineSpacing, Alignment, WidowControl, KeepWithNext, KeepTogether, PageBreak, NoLineNum, DontHyphen, Tab, FirstIndent)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditFindStyle(TAutoVal& Style)
{
  AUTONAMES0("EditFindStyle")
  AUTOARGS1(Style)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditFindClearFormatting()
{
  AUTONAMES0("EditFindClearFormatting")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditReplace(TAutoVal& Find, TAutoVal& Replace, TAutoVal& Direction, TAutoVal& MatchCase, TAutoVal& WholeWord, TAutoVal& PatternMatch, TAutoVal& SoundsLike, TAutoVal& FindNext, TAutoVal& ReplaceOne, TAutoVal& ReplaceAll, TAutoVal& Format, TAutoVal& Wrap, TAutoVal& FindAllWordForms)
{
  AUTONAMES0("EditReplace")
  AUTOARGS13(Find, Replace, Direction, MatchCase, WholeWord, PatternMatch, SoundsLike, FindNext, ReplaceOne, ReplaceAll, Format, Wrap, FindAllWordForms)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditReplaceFont(TAutoVal& Points, TAutoVal& Underline, TAutoVal& Color, TAutoVal& Strikethrough, TAutoVal& Superscript, TAutoVal& Subscript, TAutoVal& Hidden, TAutoVal& SmallCaps, TAutoVal& AllCaps, TAutoVal& Spacing, TAutoVal& Position, TAutoVal& Kerning, TAutoVal& KerningMin, TAutoVal& Default, TAutoVal& Tab, TAutoVal& Font, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Outline, TAutoVal& Shadow)
{
  AUTONAMES0("EditReplaceFont")
  AUTOARGS20(Points, Underline, Color, Strikethrough, Superscript, Subscript, Hidden, SmallCaps, AllCaps, Spacing, Position, Kerning, KerningMin, Default, Tab, Font, Bold, Italic, Outline, Shadow)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditReplacePara(TAutoVal& LeftIndent, TAutoVal& RightIndent, TAutoVal& Before, TAutoVal& After, TAutoVal& LineSpacingRule, TAutoVal& LineSpacing, TAutoVal& Alignment, TAutoVal& WidowControl, TAutoVal& KeepWithNext, TAutoVal& KeepTogether, TAutoVal& PageBreak, TAutoVal& NoLineNum, TAutoVal& DontHyphen, TAutoVal& Tab, TAutoVal& FirstIndent)
{
  AUTONAMES0("EditReplacePara")
  AUTOARGS15(LeftIndent, RightIndent, Before, After, LineSpacingRule, LineSpacing, Alignment, WidowControl, KeepWithNext, KeepTogether, PageBreak, NoLineNum, DontHyphen, Tab, FirstIndent)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditReplaceStyle(TAutoVal& Style)
{
  AUTONAMES0("EditReplaceStyle")
  AUTOARGS1(Style)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditReplaceClearFormatting()
{
  AUTONAMES0("EditReplaceClearFormatting")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditGoTo(TAutoVal& Destination)
{
  AUTONAMES0("EditGoTo")
  AUTOARGS1(Destination)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditAutoText(TAutoVal& Name, TAutoVal& Context, TAutoVal& InsertAs, TAutoVal& Insert, TAutoVal& Add, TAutoVal& Define, TAutoVal& InsertAsText, TAutoVal& Delete)
{
  AUTONAMES0("EditAutoText")
  AUTOARGS8(Name, Context, InsertAs, Insert, Add, Define, InsertAsText, Delete)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditLinks(TAutoVal& UpdateMode, TAutoVal& Locked, TAutoVal& SavePictureInDoc, TAutoVal& UpdateNow, TAutoVal& OpenSource, TAutoVal& KillLink, TAutoVal& Link, TAutoVal& Application, TAutoVal& Item, TAutoVal& FileName)
{
  AUTONAMES0("EditLinks")
  AUTOARGS10(UpdateMode, Locked, SavePictureInDoc, UpdateNow, OpenSource, KillLink, Link, Application, Item, FileName)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditObject(TAutoVal& Verb)
{
  AUTONAMES0("EditObject")
  AUTOARGS1(Verb)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ActivateObject()
{
  AUTONAMES0("ActivateObject")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::TextToTable(TAutoVal& ConvertFrom, TAutoVal& NumColumns, TAutoVal& NumRows, TAutoVal& InitialColWidth, TAutoVal& Wizard, TAutoVal& Format, TAutoVal& Apply)
{
  AUTONAMES0("TextToTable")
  AUTOARGS7(ConvertFrom, NumColumns, NumRows, InitialColWidth, Wizard, Format, Apply)
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableToText(TAutoVal& ConvertTo)
{
  AUTONAMES0("TableToText")
  AUTOARGS1(ConvertTo)
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableInsertTable(TAutoVal& ConvertFrom, TAutoVal& NumColumns, TAutoVal& NumRows, TAutoVal& InitialColWidth, TAutoVal& Wizard, TAutoVal& Format, TAutoVal& Apply)
{
  AUTONAMES0("TableInsertTable")
  AUTOARGS7(ConvertFrom, NumColumns, NumRows, InitialColWidth, Wizard, Format, Apply)
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableInsertCells(TAutoVal& ShiftCells)
{
  AUTONAMES0("TableInsertCells")
  AUTOARGS1(ShiftCells)
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableInsertRow(TAutoVal& NumRows)
{
  AUTONAMES0("TableInsertRow")
  AUTOARGS1(NumRows)
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableInsertColumn()
{
  AUTONAMES0("TableInsertColumn")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableDeleteCells(TAutoVal& ShiftCells)
{
  AUTONAMES0("TableDeleteCells")
  AUTOARGS1(ShiftCells)
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableDeleteRow()
{
  AUTONAMES0("TableDeleteRow")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableDeleteColumn()
{
  AUTONAMES0("TableDeleteColumn")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableMergeCells()
{
  AUTONAMES0("TableMergeCells")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableSplitCells(TAutoVal& NumColumns)
{
  AUTONAMES0("TableSplitCells")
  AUTOARGS1(NumColumns)
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableSplit()
{
  AUTONAMES0("TableSplit")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableSelectTable()
{
  AUTONAMES0("TableSelectTable")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableSelectRow()
{
  AUTONAMES0("TableSelectRow")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableSelectColumn()
{
  AUTONAMES0("TableSelectColumn")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableRowHeight(TAutoVal& RulerStyle, TAutoVal& LineSpacingRule, TAutoVal& LineSpacing, TAutoVal& LeftIndent, TAutoVal& Alignment, TAutoVal& AllowRowSplit, TAutoVal& PrevRow, TAutoVal& NextRow)
{
  AUTONAMES0("TableRowHeight")
  AUTOARGS8(RulerStyle, LineSpacingRule, LineSpacing, LeftIndent, Alignment, AllowRowSplit, PrevRow, NextRow)
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableColumnWidth(TAutoVal& ColumnWidth, TAutoVal& SpaceBetweenCols, TAutoVal& PrevColumn, TAutoVal& NextColumn, TAutoVal& AutoFit, TAutoVal& RulerStyle)
{
  AUTONAMES0("TableColumnWidth")
  AUTOARGS6(ColumnWidth, SpaceBetweenCols, PrevColumn, NextColumn, AutoFit, RulerStyle)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsCustomize(TAutoVal& KeyCode, TAutoVal& KeyCode2, TAutoVal& MenuType, TAutoVal& Position, TAutoVal& AddAll, TAutoVal& Category, TAutoVal& Name, TAutoVal& Menu, TAutoVal& AddBelow, TAutoVal& MenuText, TAutoVal& Rename, TAutoVal& Add, TAutoVal& Remove, TAutoVal& ResetAll, TAutoVal& CommandValue, TAutoVal& Context, TAutoVal& Tab)
{
  AUTONAMES0("ToolsCustomize")
  AUTOARGS17(KeyCode, KeyCode2, MenuType, Position, AddAll, Category, Name, Menu, AddBelow, MenuText, Rename, Add, Remove, ResetAll, CommandValue, Context, Tab)
  AUTOCALL_METHOD_VOID
}

void WordBasic::NormalViewHeaderArea(TAutoVal& Type, TAutoVal& FirstPage, TAutoVal& OddAndEvenPages, TAutoVal& HeaderDistance, TAutoVal& FooterDistance)
{
  AUTONAMES0("NormalViewHeaderArea")
  AUTOARGS5(Type, FirstPage, OddAndEvenPages, HeaderDistance, FooterDistance)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertFrame()
{
  AUTONAMES0("InsertFrame")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertBreak(TAutoVal& Type)
{
  AUTONAMES0("InsertBreak")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertAnnotation()
{
  AUTONAMES0("InsertAnnotation")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertSymbol(TAutoVal& Font, TAutoVal& Tab, TAutoVal& CharNum)
{
  AUTONAMES0("InsertSymbol")
  AUTOARGS3(Font, Tab, CharNum)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertPicture(TAutoVal& Name, TAutoVal& LinkToFile, TAutoVal& New)
{
  AUTONAMES0("InsertPicture")
  AUTOARGS3(Name, LinkToFile, New)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertFile(TAutoVal& Name, TAutoVal& Range, TAutoVal& ConfirmConversions, TAutoVal& Link)
{
  AUTONAMES0("InsertFile")
  AUTOARGS4(Name, Range, ConfirmConversions, Link)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertDateTime(TAutoVal& DateTimePic, TAutoVal& InsertAsField)
{
  AUTONAMES0("InsertDateTime")
  AUTOARGS2(DateTimePic, InsertAsField)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertField(TAutoVal& Field)
{
  AUTONAMES0("InsertField")
  AUTOARGS1(Field)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertMergeField(TAutoVal& MergeField, TAutoVal& WordField)
{
  AUTONAMES0("InsertMergeField")
  AUTOARGS2(MergeField, WordField)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditBookmark(TAutoVal& Name, TAutoVal& SortBy, TAutoVal& Add, TAutoVal& Delete, TAutoVal& Goto)
{
  AUTONAMES0("EditBookmark")
  AUTOARGS5(Name, SortBy, Add, Delete, Goto)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MarkIndexEntry(TAutoVal& MarkAll, TAutoVal& Entry, TAutoVal& Range, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& CrossReference, TAutoVal& EntryAutoText, TAutoVal& CrossReferenceAutoText)
{
  AUTONAMES0("MarkIndexEntry")
  AUTOARGS8(MarkAll, Entry, Range, Bold, Italic, CrossReference, EntryAutoText, CrossReferenceAutoText)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertIndex(TAutoVal& Outline, TAutoVal& Fields, TAutoVal& From, TAutoVal& To, TAutoVal& TableId, TAutoVal& AddedStyles, TAutoVal& Caption, TAutoVal& HeadingSeparator, TAutoVal& Replace, TAutoVal& MarkEntry, TAutoVal& AutoMark, TAutoVal& MarkCitation, TAutoVal& Type, TAutoVal& RightAlignPageNumbers, TAutoVal& Passim, TAutoVal& KeepFormatting, TAutoVal& Columns, TAutoVal& Category, TAutoVal& Label)
{
  AUTONAMES0("InsertIndex")
  AUTOARGS19(Outline, Fields, From, To, TableId, AddedStyles, Caption, HeadingSeparator, Replace, MarkEntry, AutoMark, MarkCitation, Type, RightAlignPageNumbers, Passim, KeepFormatting, Columns, Category, Label)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertTableOfContents(TAutoVal& Outline, TAutoVal& Fields, TAutoVal& From, TAutoVal& To, TAutoVal& TableId, TAutoVal& AddedStyles, TAutoVal& Caption, TAutoVal& HeadingSeparator, TAutoVal& Replace, TAutoVal& MarkEntry, TAutoVal& AutoMark, TAutoVal& MarkCitation, TAutoVal& Type, TAutoVal& RightAlignPageNumbers, TAutoVal& Passim, TAutoVal& KeepFormatting, TAutoVal& Columns, TAutoVal& Category, TAutoVal& Label)
{
  AUTONAMES0("InsertTableOfContents")
  AUTOARGS19(Outline, Fields, From, To, TableId, AddedStyles, Caption, HeadingSeparator, Replace, MarkEntry, AutoMark, MarkCitation, Type, RightAlignPageNumbers, Passim, KeepFormatting, Columns, Category, Label)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertObject(TAutoVal& IconNumber, TAutoVal& FileName, TAutoVal& Link, TAutoVal& DisplayIcon, TAutoVal& Tab, TAutoVal& Class, TAutoVal& IconFilename, TAutoVal& Caption)
{
  AUTONAMES0("InsertObject")
  AUTOARGS8(IconNumber, FileName, Link, DisplayIcon, Tab, Class, IconFilename, Caption)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsCreateEnvelope(TAutoVal& ExtractAddress, TAutoVal& LabelListIndex, TAutoVal& LabelIndex, TAutoVal& LabelDotMatrix, TAutoVal& LabelTray, TAutoVal& LabelAcross, TAutoVal& LabelDown, TAutoVal& EnvAddress, TAutoVal& EnvOmitReturn, TAutoVal& EnvReturn, TAutoVal& PrintBarCode, TAutoVal& SingleLabel, TAutoVal& LabelRow, TAutoVal& LabelColumn, TAutoVal& PrintEnvLabel, TAutoVal& AddToDocument, TAutoVal& EnvWidth, TAutoVal& EnvHeight, TAutoVal& EnvPaperSize, TAutoVal& PrintFIMA, TAutoVal& UseEnvFeeder, TAutoVal& Tab, TAutoVal& LabelAutoText, TAutoVal& LabelText, TAutoVal& AddrFromLeft, TAutoVal& AddrFromTop, TAutoVal& RetAddrFromLeft, TAutoVal& RetAddrFromTop, TAutoVal& LabelTopMargin, TAutoVal& LabelSideMargin, TAutoVal& LabelVertPitch, TAutoVal& LabelHorPitch, TAutoVal& LabelHeight, TAutoVal& LabelWidth)
{
  AUTONAMES0("ToolsCreateEnvelope")
  AUTOARGS34(ExtractAddress, LabelListIndex, LabelIndex, LabelDotMatrix, LabelTray, LabelAcross, LabelDown, EnvAddress, EnvOmitReturn, EnvReturn, PrintBarCode, SingleLabel, LabelRow, LabelColumn, PrintEnvLabel, AddToDocument, EnvWidth, EnvHeight, EnvPaperSize, PrintFIMA, UseEnvFeeder, Tab, LabelAutoText, LabelText, AddrFromLeft, AddrFromTop, RetAddrFromLeft, RetAddrFromTop, LabelTopMargin, LabelSideMargin, LabelVertPitch, LabelHorPitch, LabelHeight, LabelWidth)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatFont(TAutoVal& Points, TAutoVal& Underline, TAutoVal& Color, TAutoVal& Strikethrough, TAutoVal& Superscript, TAutoVal& Subscript, TAutoVal& Hidden, TAutoVal& SmallCaps, TAutoVal& AllCaps, TAutoVal& Spacing, TAutoVal& Position, TAutoVal& Kerning, TAutoVal& KerningMin, TAutoVal& Default, TAutoVal& Tab, TAutoVal& Font, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Outline, TAutoVal& Shadow)
{
  AUTONAMES0("FormatFont")
  AUTOARGS20(Points, Underline, Color, Strikethrough, Superscript, Subscript, Hidden, SmallCaps, AllCaps, Spacing, Position, Kerning, KerningMin, Default, Tab, Font, Bold, Italic, Outline, Shadow)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatParagraph(TAutoVal& LeftIndent, TAutoVal& RightIndent, TAutoVal& Before, TAutoVal& After, TAutoVal& LineSpacingRule, TAutoVal& LineSpacing, TAutoVal& Alignment, TAutoVal& WidowControl, TAutoVal& KeepWithNext, TAutoVal& KeepTogether, TAutoVal& PageBreak, TAutoVal& NoLineNum, TAutoVal& DontHyphen, TAutoVal& Tab, TAutoVal& FirstIndent)
{
  AUTONAMES0("FormatParagraph")
  AUTOARGS15(LeftIndent, RightIndent, Before, After, LineSpacingRule, LineSpacing, Alignment, WidowControl, KeepWithNext, KeepTogether, PageBreak, NoLineNum, DontHyphen, Tab, FirstIndent)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatSectionLayout(TAutoVal& SectionStart, TAutoVal& VertAlign, TAutoVal& Endnotes, TAutoVal& LineNum, TAutoVal& StartingNum, TAutoVal& FromText, TAutoVal& CountBy, TAutoVal& NumMode)
{
  AUTONAMES0("FormatSectionLayout")
  AUTOARGS8(SectionStart, VertAlign, Endnotes, LineNum, StartingNum, FromText, CountBy, NumMode)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatColumns(TAutoVal& Columns, TAutoVal& ColumnNo, TAutoVal& ColumnWidth, TAutoVal& ColumnSpacing, TAutoVal& EvenlySpaced, TAutoVal& ApplyColsTo, TAutoVal& ColLine, TAutoVal& StartNewCol)
{
  AUTONAMES0("FormatColumns")
  AUTOARGS8(Columns, ColumnNo, ColumnWidth, ColumnSpacing, EvenlySpaced, ApplyColsTo, ColLine, StartNewCol)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FilePageSetup(TAutoVal& Tab, TAutoVal& PaperSize, TAutoVal& TopMargin, TAutoVal& BottomMargin, TAutoVal& LeftMargin, TAutoVal& RightMargin, TAutoVal& Gutter, TAutoVal& PageWidth, TAutoVal& PageHeight, TAutoVal& Orientation, TAutoVal& FirstPage, TAutoVal& OtherPages, TAutoVal& VertAlign, TAutoVal& ApplyPropsTo, TAutoVal& Default, TAutoVal& FacingPages, TAutoVal& HeaderDistance, TAutoVal& FooterDistance, TAutoVal& SectionStart, TAutoVal& OddAndEvenPages, TAutoVal& DifferentFirstPage, TAutoVal& Endnotes, TAutoVal& LineNum, TAutoVal& StartingNum, TAutoVal& FromText, TAutoVal& CountBy, TAutoVal& NumMode)
{
  AUTONAMES0("FilePageSetup")
  AUTOARGS27(Tab, PaperSize, TopMargin, BottomMargin, LeftMargin, RightMargin, Gutter, PageWidth, PageHeight, Orientation, FirstPage, OtherPages, VertAlign, ApplyPropsTo, Default, FacingPages, HeaderDistance, FooterDistance, SectionStart, OddAndEvenPages, DifferentFirstPage, Endnotes, LineNum, StartingNum, FromText, CountBy, NumMode)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatTabs(TAutoVal& Position, TAutoVal& DefTabs, TAutoVal& Align, TAutoVal& Leader, TAutoVal& Set, TAutoVal& Clear, TAutoVal& ClearAll)
{
  AUTONAMES0("FormatTabs")
  AUTOARGS7(Position, DefTabs, Align, Leader, Set, Clear, ClearAll)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatStyle(TAutoVal& Name, TAutoVal& Delete, TAutoVal& Merge, TAutoVal& NewName, TAutoVal& BasedOn, TAutoVal& NextStyle, TAutoVal& Type, TAutoVal& FileName, TAutoVal& Source, TAutoVal& AddToTemplate, TAutoVal& Define, TAutoVal& Rename, TAutoVal& Apply)
{
  AUTONAMES0("FormatStyle")
  AUTOARGS13(Name, Delete, Merge, NewName, BasedOn, NextStyle, Type, FileName, Source, AddToTemplate, Define, Rename, Apply)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatDefineStyleFont(TAutoVal& Points, TAutoVal& Underline, TAutoVal& Color, TAutoVal& Strikethrough, TAutoVal& Superscript, TAutoVal& Subscript, TAutoVal& Hidden, TAutoVal& SmallCaps, TAutoVal& AllCaps, TAutoVal& Spacing, TAutoVal& Position, TAutoVal& Kerning, TAutoVal& KerningMin, TAutoVal& Default, TAutoVal& Tab, TAutoVal& Font, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Outline, TAutoVal& Shadow)
{
  AUTONAMES0("FormatDefineStyleFont")
  AUTOARGS20(Points, Underline, Color, Strikethrough, Superscript, Subscript, Hidden, SmallCaps, AllCaps, Spacing, Position, Kerning, KerningMin, Default, Tab, Font, Bold, Italic, Outline, Shadow)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatDefineStylePara(TAutoVal& LeftIndent, TAutoVal& RightIndent, TAutoVal& Before, TAutoVal& After, TAutoVal& LineSpacingRule, TAutoVal& LineSpacing, TAutoVal& Alignment, TAutoVal& WidowControl, TAutoVal& KeepWithNext, TAutoVal& KeepTogether, TAutoVal& PageBreak, TAutoVal& NoLineNum, TAutoVal& DontHyphen, TAutoVal& Tab, TAutoVal& FirstIndent)
{
  AUTONAMES0("FormatDefineStylePara")
  AUTOARGS15(LeftIndent, RightIndent, Before, After, LineSpacingRule, LineSpacing, Alignment, WidowControl, KeepWithNext, KeepTogether, PageBreak, NoLineNum, DontHyphen, Tab, FirstIndent)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatDefineStyleTabs(TAutoVal& Position, TAutoVal& DefTabs, TAutoVal& Align, TAutoVal& Leader, TAutoVal& Set, TAutoVal& Clear, TAutoVal& ClearAll)
{
  AUTONAMES0("FormatDefineStyleTabs")
  AUTOARGS7(Position, DefTabs, Align, Leader, Set, Clear, ClearAll)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatDefineStyleFrame(TAutoVal& Wrap, TAutoVal& WidthRule, TAutoVal& FixedWidth, TAutoVal& HeightRule, TAutoVal& FixedHeight, TAutoVal& PositionHorz, TAutoVal& PositionHorzRel, TAutoVal& DistFromText, TAutoVal& PositionVert, TAutoVal& PositionVertRel, TAutoVal& DistVertFromText, TAutoVal& MoveWithText, TAutoVal& LockAnchor, TAutoVal& RemoveFrame)
{
  AUTONAMES0("FormatDefineStyleFrame")
  AUTOARGS14(Wrap, WidthRule, FixedWidth, HeightRule, FixedHeight, PositionHorz, PositionHorzRel, DistFromText, PositionVert, PositionVertRel, DistVertFromText, MoveWithText, LockAnchor, RemoveFrame)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatDefineStyleBorders(TAutoVal& ApplyTo, TAutoVal& Shadow, TAutoVal& TopBorder, TAutoVal& LeftBorder, TAutoVal& BottomBorder, TAutoVal& RightBorder, TAutoVal& HorizBorder, TAutoVal& VertBorder, TAutoVal& TopColor, TAutoVal& LeftColor, TAutoVal& BottomColor, TAutoVal& RightColor, TAutoVal& HorizColor, TAutoVal& VertColor, TAutoVal& FromText, TAutoVal& Shading, TAutoVal& Foreground, TAutoVal& Background, TAutoVal& Tab, TAutoVal& FineShading)
{
  AUTONAMES0("FormatDefineStyleBorders")
  AUTOARGS20(ApplyTo, Shadow, TopBorder, LeftBorder, BottomBorder, RightBorder, HorizBorder, VertBorder, TopColor, LeftColor, BottomColor, RightColor, HorizColor, VertColor, FromText, Shading, Foreground, Background, Tab, FineShading)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatDefineStyleLang(TAutoVal& Language, TAutoVal& Default)
{
  AUTONAMES0("FormatDefineStyleLang")
  AUTOARGS2(Language, Default)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatPicture(TAutoVal& SetSize, TAutoVal& CropLeft, TAutoVal& CropRight, TAutoVal& CropTop, TAutoVal& CropBottom, TAutoVal& ScaleX, TAutoVal& ScaleY, TAutoVal& SizeX, TAutoVal& SizeY)
{
  AUTONAMES0("FormatPicture")
  AUTOARGS9(SetSize, CropLeft, CropRight, CropTop, CropBottom, ScaleX, ScaleY, SizeX, SizeY)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsLanguage(TAutoVal& Language, TAutoVal& Default)
{
  AUTONAMES0("ToolsLanguage")
  AUTOARGS2(Language, Default)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatBordersAndShading(TAutoVal& ApplyTo, TAutoVal& Shadow, TAutoVal& TopBorder, TAutoVal& LeftBorder, TAutoVal& BottomBorder, TAutoVal& RightBorder, TAutoVal& HorizBorder, TAutoVal& VertBorder, TAutoVal& TopColor, TAutoVal& LeftColor, TAutoVal& BottomColor, TAutoVal& RightColor, TAutoVal& HorizColor, TAutoVal& VertColor, TAutoVal& FromText, TAutoVal& Shading, TAutoVal& Foreground, TAutoVal& Background, TAutoVal& Tab, TAutoVal& FineShading)
{
  AUTONAMES0("FormatBordersAndShading")
  AUTOARGS20(ApplyTo, Shadow, TopBorder, LeftBorder, BottomBorder, RightBorder, HorizBorder, VertBorder, TopColor, LeftColor, BottomColor, RightColor, HorizColor, VertColor, FromText, Shading, Foreground, Background, Tab, FineShading)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatFrame(TAutoVal& Wrap, TAutoVal& WidthRule, TAutoVal& FixedWidth, TAutoVal& HeightRule, TAutoVal& FixedHeight, TAutoVal& PositionHorz, TAutoVal& PositionHorzRel, TAutoVal& DistFromText, TAutoVal& PositionVert, TAutoVal& PositionVertRel, TAutoVal& DistVertFromText, TAutoVal& MoveWithText, TAutoVal& LockAnchor, TAutoVal& RemoveFrame)
{
  AUTONAMES0("FormatFrame")
  AUTOARGS14(Wrap, WidthRule, FixedWidth, HeightRule, FixedHeight, PositionHorz, PositionHorzRel, DistFromText, PositionVert, PositionVertRel, DistVertFromText, MoveWithText, LockAnchor, RemoveFrame)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsSpelling()
{
  AUTONAMES0("ToolsSpelling")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsSpellSelection()
{
  AUTONAMES0("ToolsSpellSelection")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsGrammar()
{
  AUTONAMES0("ToolsGrammar")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsThesaurus()
{
  AUTONAMES0("ToolsThesaurus")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsHyphenation(TAutoVal& AutoHyphenation, TAutoVal& HyphenateCaps, TAutoVal& HyphenationZone, TAutoVal& LimitConsecutiveHyphens)
{
  AUTONAMES0("ToolsHyphenation")
  AUTOARGS4(AutoHyphenation, HyphenateCaps, HyphenationZone, LimitConsecutiveHyphens)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsBulletsNumbers(TAutoVal& Replace, TAutoVal& Font, TAutoVal& CharNum, TAutoVal& Type, TAutoVal& FormatOutline, TAutoVal& AutoUpdate, TAutoVal& FormatNumber, TAutoVal& Punctuation, TAutoVal& StartAt, TAutoVal& Points, TAutoVal& Hang, TAutoVal& Indent, TAutoVal& Remove)
{
  AUTONAMES0("ToolsBulletsNumbers")
  AUTOARGS13(Replace, Font, CharNum, Type, FormatOutline, AutoUpdate, FormatNumber, Punctuation, StartAt, Points, Hang, Indent, Remove)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsRevisions(TAutoVal& MarkRevisions, TAutoVal& ViewRevisions, TAutoVal& PrintRevisions, TAutoVal& AcceptAll, TAutoVal& RejectAll)
{
  AUTONAMES0("ToolsRevisions")
  AUTOARGS5(MarkRevisions, ViewRevisions, PrintRevisions, AcceptAll, RejectAll)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsCompareVersions(TAutoVal& Name)
{
  AUTONAMES0("ToolsCompareVersions")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableSort(TAutoVal& DontSortHdr, TAutoVal& FieldNum, TAutoVal& Type, TAutoVal& Order, TAutoVal& FieldNum2, TAutoVal& Type2, TAutoVal& Order2, TAutoVal& FieldNum3, TAutoVal& Type3, TAutoVal& Order3, TAutoVal& Separator, TAutoVal& SortColumn, TAutoVal& CaseSensitive)
{
  AUTONAMES0("TableSort")
  AUTOARGS13(DontSortHdr, FieldNum, Type, Order, FieldNum2, Type2, Order2, FieldNum3, Type3, Order3, Separator, SortColumn, CaseSensitive)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsRepaginate()
{
  AUTONAMES0("ToolsRepaginate")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsOptions(TAutoVal& Tab)
{
  AUTONAMES0("ToolsOptions")
  AUTOARGS1(Tab)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsOptionsGeneral(TAutoVal& Pagination, TAutoVal& WPHelp, TAutoVal& WPDocNavKeys, TAutoVal& BlueScreen, TAutoVal& ErrorBeeps, TAutoVal& Effects3d, TAutoVal& UpdateLinks, TAutoVal& SendMailAttach, TAutoVal& RecentFiles, TAutoVal& RecentFileCount, TAutoVal& Units, TAutoVal& ButtonFieldClicks, TAutoVal& ShortMenuNames, TAutoVal& RTFInClipboard, TAutoVal& ConfirmConversions, TAutoVal& TipWizardActive)
{
  AUTONAMES0("ToolsOptionsGeneral")
  AUTOARGS16(Pagination, WPHelp, WPDocNavKeys, BlueScreen, ErrorBeeps, Effects3d, UpdateLinks, SendMailAttach, RecentFiles, RecentFileCount, Units, ButtonFieldClicks, ShortMenuNames, RTFInClipboard, ConfirmConversions, TipWizardActive)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsOptionsView(TAutoVal& DraftFont, TAutoVal& WrapToWindow, TAutoVal& PicturePlaceHolders, TAutoVal& FieldCodes, TAutoVal& BookMarks, TAutoVal& FieldShading, TAutoVal& StatusBar, TAutoVal& HScroll, TAutoVal& VScroll, TAutoVal& StyleAreaWidth, TAutoVal& Tabs, TAutoVal& Spaces, TAutoVal& Paras, TAutoVal& Hyphens, TAutoVal& Hidden, TAutoVal& ShowAll, TAutoVal& Drawings, TAutoVal& Anchors, TAutoVal& TextBoundaries, TAutoVal& VRuler, TAutoVal& Highlight)
{
  AUTONAMES0("ToolsOptionsView")
  AUTOARGS21(DraftFont, WrapToWindow, PicturePlaceHolders, FieldCodes, BookMarks, FieldShading, StatusBar, HScroll, VScroll, StyleAreaWidth, Tabs, Spaces, Paras, Hyphens, Hidden, ShowAll, Drawings, Anchors, TextBoundaries, VRuler, Highlight)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsAdvancedSettings(TAutoVal& Application, TAutoVal& Option, TAutoVal& Setting, TAutoVal& Delete, TAutoVal& Set)
{
  AUTONAMES0("ToolsAdvancedSettings")
  AUTOARGS5(Application, Option, Setting, Delete, Set)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsOptionsPrint(TAutoVal& Draft, TAutoVal& Reverse, TAutoVal& UpdateFields, TAutoVal& Summary, TAutoVal& ShowCodes, TAutoVal& Annotations, TAutoVal& ShowHidden, TAutoVal& EnvFeederInstalled, TAutoVal& FractionalWidths, TAutoVal& PSOverText, TAutoVal& WidowControl, TAutoVal& DfltTrueType, TAutoVal& UpdateLinks, TAutoVal& Background, TAutoVal& DrawingObjects, TAutoVal& FormsData, TAutoVal& DefaultTray)
{
  AUTONAMES0("ToolsOptionsPrint")
  AUTOARGS17(Draft, Reverse, UpdateFields, Summary, ShowCodes, Annotations, ShowHidden, EnvFeederInstalled, FractionalWidths, PSOverText, WidowControl, DfltTrueType, UpdateLinks, Background, DrawingObjects, FormsData, DefaultTray)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsOptionsSave(TAutoVal& CreateBackup, TAutoVal& FastSaves, TAutoVal& SummaryPrompt, TAutoVal& GlobalDotPrompt, TAutoVal& NativePictureFormat, TAutoVal& EmbedFonts, TAutoVal& FormsData, TAutoVal& AutoSave, TAutoVal& SaveInterval, TAutoVal& Password, TAutoVal& WritePassword, TAutoVal& RecommendReadOnly)
{
  AUTONAMES0("ToolsOptionsSave")
  AUTOARGS12(CreateBackup, FastSaves, SummaryPrompt, GlobalDotPrompt, NativePictureFormat, EmbedFonts, FormsData, AutoSave, SaveInterval, Password, WritePassword, RecommendReadOnly)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsOptionsSpelling(TAutoVal& AlwaysSuggest, TAutoVal& SuggestFromMainDictOnly, TAutoVal& IgnoreAllCaps, TAutoVal& IgnoreMixedDigits, TAutoVal& ResetIgnoreAll, TAutoVal& Type, TAutoVal& CustomDict1, TAutoVal& CustomDict2, TAutoVal& CustomDict3, TAutoVal& CustomDict4, TAutoVal& CustomDict5, TAutoVal& CustomDict6, TAutoVal& CustomDict7, TAutoVal& CustomDict8, TAutoVal& CustomDict9, TAutoVal& CustomDict10, TAutoVal& AutomaticSpelling, TAutoVal& HideSpellingErrors, TAutoVal& RecheckDocument)
{
  AUTONAMES0("ToolsOptionsSpelling")
  AUTOARGS19(AlwaysSuggest, SuggestFromMainDictOnly, IgnoreAllCaps, IgnoreMixedDigits, ResetIgnoreAll, Type, CustomDict1, CustomDict2, CustomDict3, CustomDict4, CustomDict5, CustomDict6, CustomDict7, CustomDict8, CustomDict9, CustomDict10, AutomaticSpelling, HideSpellingErrors, RecheckDocument)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsOptionsGrammar(TAutoVal& Options, TAutoVal& CheckSpelling, TAutoVal& ShowStatistics)
{
  AUTONAMES0("ToolsOptionsGrammar")
  AUTOARGS3(Options, CheckSpelling, ShowStatistics)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsOptionsUserInfo(TAutoVal& Name, TAutoVal& Initials, TAutoVal& Address)
{
  AUTONAMES0("ToolsOptionsUserInfo")
  AUTOARGS3(Name, Initials, Address)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsMacro(TAutoVal& Name, TAutoVal& Run, TAutoVal& Edit, TAutoVal& Show, TAutoVal& Delete, TAutoVal& Rename, TAutoVal& Description, TAutoVal& NewName, TAutoVal& SetDesc)
{
  AUTONAMES0("ToolsMacro")
  AUTOARGS9(Name, Run, Edit, Show, Delete, Rename, Description, NewName, SetDesc)
  AUTOCALL_METHOD_VOID
}

void WordBasic::PauseRecorder()
{
  AUTONAMES0("PauseRecorder")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::WindowNewWindow()
{
  AUTONAMES0("WindowNewWindow")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::WindowArrangeAll()
{
  AUTONAMES0("WindowArrangeAll")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeEditMainDocument()
{
  AUTONAMES0("MailMergeEditMainDocument")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatRetAddrFonts(TAutoVal& Points, TAutoVal& Underline, TAutoVal& Color, TAutoVal& Strikethrough, TAutoVal& Superscript, TAutoVal& Subscript, TAutoVal& Hidden, TAutoVal& SmallCaps, TAutoVal& AllCaps, TAutoVal& Spacing, TAutoVal& Position, TAutoVal& Kerning, TAutoVal& KerningMin, TAutoVal& Default, TAutoVal& Tab, TAutoVal& Font, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Outline, TAutoVal& Shadow)
{
  AUTONAMES0("FormatRetAddrFonts")
  AUTOARGS20(Points, Underline, Color, Strikethrough, Superscript, Subscript, Hidden, SmallCaps, AllCaps, Spacing, Position, Kerning, KerningMin, Default, Tab, Font, Bold, Italic, Outline, Shadow)
  AUTOCALL_METHOD_VOID
}

void WordBasic::Organizer(TAutoVal& Copy, TAutoVal& Delete, TAutoVal& Rename, TAutoVal& Source, TAutoVal& Destination, TAutoVal& Name, TAutoVal& NewName, TAutoVal& Tab)
{
  AUTONAMES0("Organizer")
  AUTOARGS8(Copy, Delete, Rename, Source, Destination, Name, NewName, Tab)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsOptionsEdit(TAutoVal& ReplaceSelection, TAutoVal& DragAndDrop, TAutoVal& AutoWordSelection, TAutoVal& InsForPaste, TAutoVal& Overtype, TAutoVal& SmartCutPaste, TAutoVal& AllowAccentedUppercase, TAutoVal& PictureEditor, TAutoVal& TabIndent)
{
  AUTONAMES0("ToolsOptionsEdit")
  AUTOARGS9(ReplaceSelection, DragAndDrop, AutoWordSelection, InsForPaste, Overtype, SmartCutPaste, AllowAccentedUppercase, PictureEditor, TabIndent)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsOptionsFileLocations(TAutoVal& Path, TAutoVal& Setting)
{
  AUTONAMES0("ToolsOptionsFileLocations")
  AUTOARGS2(Path, Setting)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsWordCount(TAutoVal& CountFootnotes, TAutoVal& Pages, TAutoVal& Words, TAutoVal& Characters, TAutoVal& Paragraphs, TAutoVal& Lines)
{
  AUTONAMES0("ToolsWordCount")
  AUTOARGS6(CountFootnotes, Pages, Words, Characters, Paragraphs, Lines)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DocRestore()
{
  AUTONAMES0("DocRestore")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ControlRun(TAutoVal& Application)
{
  AUTONAMES0("ControlRun")
  AUTOARGS1(Application)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShrinkSelection()
{
  AUTONAMES0("ShrinkSelection")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditSelectAll()
{
  AUTONAMES0("EditSelectAll")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertPageField()
{
  AUTONAMES0("InsertPageField")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertDateField()
{
  AUTONAMES0("InsertDateField")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertTimeField()
{
  AUTONAMES0("InsertTimeField")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatHeaderFooterLink()
{
  AUTONAMES0("FormatHeaderFooterLink")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ClosePane()
{
  AUTONAMES0("ClosePane")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::OutlinePromote()
{
  AUTONAMES0("OutlinePromote")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::OutlineDemote()
{
  AUTONAMES0("OutlineDemote")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::OutlineMoveUp()
{
  AUTONAMES0("OutlineMoveUp")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::OutlineMoveDown()
{
  AUTONAMES0("OutlineMoveDown")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::NormalStyle()
{
  AUTONAMES0("NormalStyle")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::OutlineExpand()
{
  AUTONAMES0("OutlineExpand")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::OutlineCollapse()
{
  AUTONAMES0("OutlineCollapse")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowHeading1()
{
  AUTONAMES0("ShowHeading1")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowHeading2()
{
  AUTONAMES0("ShowHeading2")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowHeading3()
{
  AUTONAMES0("ShowHeading3")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowHeading4()
{
  AUTONAMES0("ShowHeading4")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowHeading5()
{
  AUTONAMES0("ShowHeading5")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowHeading6()
{
  AUTONAMES0("ShowHeading6")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowHeading7()
{
  AUTONAMES0("ShowHeading7")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowHeading8()
{
  AUTONAMES0("ShowHeading8")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowHeading9()
{
  AUTONAMES0("ShowHeading9")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowAllHeadings()
{
  AUTONAMES0("ShowAllHeadings")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::OutlineShowFormat()
{
  AUTONAMES0("OutlineShowFormat")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowVars()
{
  AUTONAMES0("ShowVars")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertPageBreak()
{
  AUTONAMES0("InsertPageBreak")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertColumnBreak()
{
  AUTONAMES0("InsertColumnBreak")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DoFieldClick()
{
  AUTONAMES0("DoFieldClick")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertDrawing()
{
  AUTONAMES0("InsertDrawing")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertChart()
{
  AUTONAMES0("InsertChart")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::SelectCurFont()
{
  AUTONAMES0("SelectCurFont")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::SelectCurAlignment()
{
  AUTONAMES0("SelectCurAlignment")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::SelectCurSpacing()
{
  AUTONAMES0("SelectCurSpacing")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::SelectCurIndent()
{
  AUTONAMES0("SelectCurIndent")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::SelectCurTabs()
{
  AUTONAMES0("SelectCurTabs")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::SelectCurColor()
{
  AUTONAMES0("SelectCurColor")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::RemoveFrames()
{
  AUTONAMES0("RemoveFrames")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MenuMode()
{
  AUTONAMES0("MenuMode")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertPageNumbers(TAutoVal& Type, TAutoVal& Position, TAutoVal& FirstPage)
{
  AUTONAMES0("InsertPageNumbers")
  AUTOARGS3(Type, Position, FirstPage)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditPicture()
{
  AUTONAMES0("EditPicture")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatPageNumber(TAutoVal& ChapterNumber, TAutoVal& NumRestart, TAutoVal& NumFormat, TAutoVal& StartingNum, TAutoVal& Level, TAutoVal& Separator)
{
  AUTONAMES0("FormatPageNumber")
  AUTOARGS6(ChapterNumber, NumRestart, NumFormat, StartingNum, Level, Separator)
  AUTOCALL_METHOD_VOID
}

void WordBasic::CopyFile(TAutoVal& FileName, TAutoVal& Directory)
{
  AUTONAMES0("CopyFile")
  AUTOARGS2(FileName, Directory)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileNewDefault()
{
  AUTONAMES0("FileNewDefault")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FilePrintDefault()
{
  AUTONAMES0("FilePrintDefault")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewZoomWholePage()
{
  AUTONAMES0("ViewZoomWholePage")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewZoomPageWidth()
{
  AUTONAMES0("ViewZoomPageWidth")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewZoom100()
{
  AUTONAMES0("ViewZoom100")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::TogglePortrait(TAutoVal& Tab, TAutoVal& PaperSize, TAutoVal& TopMargin, TAutoVal& BottomMargin, TAutoVal& LeftMargin, TAutoVal& RightMargin, TAutoVal& Gutter, TAutoVal& PageWidth, TAutoVal& PageHeight, TAutoVal& Orientation, TAutoVal& FirstPage, TAutoVal& OtherPages, TAutoVal& VertAlign, TAutoVal& ApplyPropsTo, TAutoVal& Default, TAutoVal& FacingPages, TAutoVal& HeaderDistance, TAutoVal& FooterDistance, TAutoVal& SectionStart, TAutoVal& OddAndEvenPages, TAutoVal& DifferentFirstPage, TAutoVal& Endnotes, TAutoVal& LineNum, TAutoVal& StartingNum, TAutoVal& FromText, TAutoVal& CountBy, TAutoVal& NumMode)
{
  AUTONAMES0("TogglePortrait")
  AUTOARGS27(Tab, PaperSize, TopMargin, BottomMargin, LeftMargin, RightMargin, Gutter, PageWidth, PageHeight, Orientation, FirstPage, OtherPages, VertAlign, ApplyPropsTo, Default, FacingPages, HeaderDistance, FooterDistance, SectionStart, OddAndEvenPages, DifferentFirstPage, Endnotes, LineNum, StartingNum, FromText, CountBy, NumMode)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsBulletListDefault()
{
  AUTONAMES0("ToolsBulletListDefault")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToggleScribbleMode()
{
  AUTONAMES0("ToggleScribbleMode")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsNumberListDefault()
{
  AUTONAMES0("ToolsNumberListDefault")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatChangeCase(TAutoVal& Type)
{
  AUTONAMES0("FormatChangeCase")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewToolbars(TAutoVal& Toolbar, TAutoVal& Context, TAutoVal& ColorButtons, TAutoVal& LargeButtons, TAutoVal& ToolTips, TAutoVal& ToolTipsKey, TAutoVal& Reset, TAutoVal& Delete, TAutoVal& Show, TAutoVal& Hide)
{
  AUTONAMES0("ViewToolbars")
  AUTOARGS10(Toolbar, Context, ColorButtons, LargeButtons, ToolTips, ToolTipsKey, Reset, Delete, Show, Hide)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeDataForm()
{
  AUTONAMES0("MailMergeDataForm")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertDatabase(TAutoVal& Format, TAutoVal& Style, TAutoVal& LinkToSource, TAutoVal& Connection, TAutoVal& SQLStatement, TAutoVal& SQLStatement1, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& DataSource, TAutoVal& From, TAutoVal& To, TAutoVal& IncludeFields)
{
  AUTONAMES0("InsertDatabase")
  AUTOARGS12(Format, Style, LinkToSource, Connection, SQLStatement, SQLStatement1, PasswordDoc, PasswordDot, DataSource, From, To, IncludeFields)
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableFormula(TAutoVal& Formula, TAutoVal& NumFormat)
{
  AUTONAMES0("TableFormula")
  AUTOARGS2(Formula, NumFormat)
  AUTOCALL_METHOD_VOID
}

void WordBasic::TextFormField()
{
  AUTONAMES0("TextFormField")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::CheckBoxFormField()
{
  AUTONAMES0("CheckBoxFormField")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DropDownFormField()
{
  AUTONAMES0("DropDownFormField")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormFieldOptions(TAutoVal& Entry, TAutoVal& Exit, TAutoVal& Name, TAutoVal& Enable, TAutoVal& TextType, TAutoVal& TextWidth, TAutoVal& TextDefault, TAutoVal& TextFormat, TAutoVal& CheckSize, TAutoVal& CheckWidth, TAutoVal& CheckDefault, TAutoVal& Type, TAutoVal& OwnHelp, TAutoVal& HelpText, TAutoVal& OwnStat, TAutoVal& StatText)
{
  AUTONAMES0("FormFieldOptions")
  AUTOARGS16(Entry, Exit, Name, Enable, TextType, TextWidth, TextDefault, TextFormat, CheckSize, CheckWidth, CheckDefault, Type, OwnHelp, HelpText, OwnStat, StatText)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertCaption(TAutoVal& Label, TAutoVal& TitleAutoText, TAutoVal& Title, TAutoVal& Delete, TAutoVal& Position, TAutoVal& AutoCaption)
{
  AUTONAMES0("InsertCaption")
  AUTOARGS6(Label, TitleAutoText, Title, Delete, Position, AutoCaption)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertCaptionNumbering(TAutoVal& Label, TAutoVal& FormatNumber, TAutoVal& ChapterNumber, TAutoVal& Level, TAutoVal& Separator)
{
  AUTONAMES0("InsertCaptionNumbering")
  AUTOARGS5(Label, FormatNumber, ChapterNumber, Level, Separator)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertAutoCaption(TAutoVal& Clear, TAutoVal& ClearAll, TAutoVal& Object, TAutoVal& Label, TAutoVal& Position)
{
  AUTONAMES0("InsertAutoCaption")
  AUTOARGS5(Clear, ClearAll, Object, Label, Position)
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpPSSHelp()
{
  AUTONAMES0("HelpPSSHelp")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawTextbox()
{
  AUTONAMES0("DrawTextbox")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsOptionsAutoFormat(TAutoVal& PreserveStyles, TAutoVal& ApplyStylesHeadings, TAutoVal& ApplyStylesLists, TAutoVal& ApplyStylesOtherParas, TAutoVal& AdjustParaMarks, TAutoVal& AdjustTabsSpaces, TAutoVal& AdjustEmptyParas, TAutoVal& ReplaceQuotes, TAutoVal& ReplaceSymbols, TAutoVal& ReplaceBullets, TAutoVal& ApplyBulletedLists, TAutoVal& ReplaceOrdinals, TAutoVal& ReplaceFractions, TAutoVal& ApplyBorders, TAutoVal& ApplyNumberedLists, TAutoVal& ShowOptionsFor)
{
  AUTONAMES0("ToolsOptionsAutoFormat")
  AUTOARGS16(PreserveStyles, ApplyStylesHeadings, ApplyStylesLists, ApplyStylesOtherParas, AdjustParaMarks, AdjustTabsSpaces, AdjustEmptyParas, ReplaceQuotes, ReplaceSymbols, ReplaceBullets, ApplyBulletedLists, ReplaceOrdinals, ReplaceFractions, ApplyBorders, ApplyNumberedLists, ShowOptionsFor)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DemoteToBodyText()
{
  AUTONAMES0("DemoteToBodyText")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertCrossReference(TAutoVal& ReferenceType, TAutoVal& ReferenceKind, TAutoVal& ReferenceItem)
{
  AUTONAMES0("InsertCrossReference")
  AUTOARGS3(ReferenceType, ReferenceKind, ReferenceItem)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertFootnote(TAutoVal& Reference, TAutoVal& NoteType, TAutoVal& Symbol)
{
  AUTONAMES0("InsertFootnote")
  AUTOARGS3(Reference, NoteType, Symbol)
  AUTOCALL_METHOD_VOID
}

void WordBasic::NoteOptions(TAutoVal& FootnotesAt, TAutoVal& FootNumberAs, TAutoVal& FootStartingNum, TAutoVal& FootRestartNum, TAutoVal& EndnotesAt, TAutoVal& EndNumberAs, TAutoVal& EndStartingNum, TAutoVal& EndRestartNum)
{
  AUTONAMES0("NoteOptions")
  AUTOARGS8(FootnotesAt, FootNumberAs, FootStartingNum, FootRestartNum, EndnotesAt, EndNumberAs, EndStartingNum, EndRestartNum)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawLine()
{
  AUTONAMES0("DrawLine")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawRectangle()
{
  AUTONAMES0("DrawRectangle")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsAutoCorrect(TAutoVal& InitialCaps, TAutoVal& SentenceCaps, TAutoVal& Days, TAutoVal& CapsLock, TAutoVal& ReplaceText, TAutoVal& Formatting, TAutoVal& Replace, TAutoVal& With, TAutoVal& Add, TAutoVal& Delete, TAutoVal& SmartQuotes)
{
  AUTONAMES0("ToolsAutoCorrect")
  AUTOARGS11(InitialCaps, SentenceCaps, Days, CapsLock, ReplaceText, Formatting, Replace, With, Add, Delete, SmartQuotes)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatAutoFormat()
{
  AUTONAMES0("FormatAutoFormat")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsOptionsRevisions(TAutoVal& InsertedTextMark, TAutoVal& InsertedTextColor, TAutoVal& DeletedTextMark, TAutoVal& DeletedTextColor, TAutoVal& RevisedLinesMark, TAutoVal& RevisedLinesColor, TAutoVal& HighlightColor)
{
  AUTONAMES0("ToolsOptionsRevisions")
  AUTOARGS7(InsertedTextMark, InsertedTextColor, DeletedTextMark, DeletedTextColor, RevisedLinesMark, RevisedLinesColor, HighlightColor)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ResetNoteSepOrNotice()
{
  AUTONAMES0("ResetNoteSepOrNotice")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatBullet(TAutoVal& Points, TAutoVal& Color, TAutoVal& Before, TAutoVal& Type, TAutoVal& After, TAutoVal& StartAt, TAutoVal& Include, TAutoVal& Alignment, TAutoVal& Indent, TAutoVal& Space, TAutoVal& Hang, TAutoVal& RestartNum, TAutoVal& Level, TAutoVal& CharNum, TAutoVal& Font, TAutoVal& Strikethrough, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Underline, TAutoVal& Remove)
{
  AUTONAMES0("FormatBullet")
  AUTOARGS20(Points, Color, Before, Type, After, StartAt, Include, Alignment, Indent, Space, Hang, RestartNum, Level, CharNum, Font, Strikethrough, Bold, Italic, Underline, Remove)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatNumber(TAutoVal& Points, TAutoVal& Color, TAutoVal& Before, TAutoVal& Type, TAutoVal& After, TAutoVal& StartAt, TAutoVal& Include, TAutoVal& Alignment, TAutoVal& Indent, TAutoVal& Space, TAutoVal& Hang, TAutoVal& RestartNum, TAutoVal& Level, TAutoVal& CharNum, TAutoVal& Font, TAutoVal& Strikethrough, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Underline, TAutoVal& Remove)
{
  AUTONAMES0("FormatNumber")
  AUTOARGS20(Points, Color, Before, Type, After, StartAt, Include, Alignment, Indent, Space, Hang, RestartNum, Level, CharNum, Font, Strikethrough, Bold, Italic, Underline, Remove)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatMultilevel(TAutoVal& Points, TAutoVal& Color, TAutoVal& Before, TAutoVal& Type, TAutoVal& After, TAutoVal& StartAt, TAutoVal& Include, TAutoVal& Alignment, TAutoVal& Indent, TAutoVal& Space, TAutoVal& Hang, TAutoVal& RestartNum, TAutoVal& Level, TAutoVal& CharNum, TAutoVal& Font, TAutoVal& Strikethrough, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Underline, TAutoVal& Remove)
{
  AUTONAMES0("FormatMultilevel")
  AUTOARGS20(Points, Color, Before, Type, After, StartAt, Include, Alignment, Indent, Space, Hang, RestartNum, Level, CharNum, Font, Strikethrough, Bold, Italic, Underline, Remove)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ConvertObject(TAutoVal& IconNumber, TAutoVal& ActivateAs, TAutoVal& IconFilename, TAutoVal& Caption, TAutoVal& Class, TAutoVal& DisplayIcon)
{
  AUTONAMES0("ConvertObject")
  AUTOARGS6(IconNumber, ActivateAs, IconFilename, Caption, Class, DisplayIcon)
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableSortAToZ()
{
  AUTONAMES0("TableSortAToZ")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableSortZToA()
{
  AUTONAMES0("TableSortZToA")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatBulletsAndNumbering(TAutoVal& Remove, TAutoVal& Hang, TAutoVal& Tab, TAutoVal& Preset)
{
  AUTONAMES0("FormatBulletsAndNumbering")
  AUTOARGS4(Remove, Hang, Tab, Preset)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertAddCaption(TAutoVal& Name)
{
  AUTONAMES0("InsertAddCaption")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_VOID
}

void WordBasic::GoToNextPage()
{
  AUTONAMES0("GoToNextPage")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::GoToPreviousPage()
{
  AUTONAMES0("GoToPreviousPage")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::GoToNextSection()
{
  AUTONAMES0("GoToNextSection")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::GoToPreviousSection()
{
  AUTONAMES0("GoToPreviousSection")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::GoToNextFootnote()
{
  AUTONAMES0("GoToNextFootnote")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::GoToPreviousFootnote()
{
  AUTONAMES0("GoToPreviousFootnote")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::GoToNextEndnote()
{
  AUTONAMES0("GoToNextEndnote")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::GoToPreviousEndnote()
{
  AUTONAMES0("GoToPreviousEndnote")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::GoToNextAnnotation()
{
  AUTONAMES0("GoToNextAnnotation")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::GoToPreviousAnnotation()
{
  AUTONAMES0("GoToPreviousAnnotation")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Connect(TAutoVal& Drive, TAutoVal& Path, TAutoVal& Password)
{
  AUTONAMES0("Connect")
  AUTOARGS3(Drive, Path, Password)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditFindLang(TAutoVal& Language, TAutoVal& Default)
{
  AUTONAMES0("EditFindLang")
  AUTOARGS2(Language, Default)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditReplaceLang(TAutoVal& Language, TAutoVal& Default)
{
  AUTONAMES0("EditReplaceLang")
  AUTOARGS2(Language, Default)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsCustomizeKeyboard(TAutoVal& KeyCode, TAutoVal& KeyCode2, TAutoVal& MenuType, TAutoVal& Position, TAutoVal& AddAll, TAutoVal& Category, TAutoVal& Name, TAutoVal& Menu, TAutoVal& AddBelow, TAutoVal& MenuText, TAutoVal& Rename, TAutoVal& Add, TAutoVal& Remove, TAutoVal& ResetAll, TAutoVal& CommandValue, TAutoVal& Context, TAutoVal& Tab)
{
  AUTONAMES0("ToolsCustomizeKeyboard")
  AUTOARGS17(KeyCode, KeyCode2, MenuType, Position, AddAll, Category, Name, Menu, AddBelow, MenuText, Rename, Add, Remove, ResetAll, CommandValue, Context, Tab)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsCustomizeMenus(TAutoVal& KeyCode, TAutoVal& KeyCode2, TAutoVal& MenuType, TAutoVal& Position, TAutoVal& AddAll, TAutoVal& Category, TAutoVal& Name, TAutoVal& Menu, TAutoVal& AddBelow, TAutoVal& MenuText, TAutoVal& Rename, TAutoVal& Add, TAutoVal& Remove, TAutoVal& ResetAll, TAutoVal& CommandValue, TAutoVal& Context, TAutoVal& Tab)
{
  AUTONAMES0("ToolsCustomizeMenus")
  AUTOARGS17(KeyCode, KeyCode2, MenuType, Position, AddAll, Category, Name, Menu, AddBelow, MenuText, Rename, Add, Remove, ResetAll, CommandValue, Context, Tab)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsMergeRevisions(TAutoVal& Name)
{
  AUTONAMES0("ToolsMergeRevisions")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ClosePreview()
{
  AUTONAMES0("ClosePreview")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditConvertAllFootnotes()
{
  AUTONAMES0("EditConvertAllFootnotes")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditConvertAllEndnotes()
{
  AUTONAMES0("EditConvertAllEndnotes")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditSwapAllNotes()
{
  AUTONAMES0("EditSwapAllNotes")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MarkTableOfContentsEntry(TAutoVal& Entry, TAutoVal& EntryAutoText, TAutoVal& TableId, TAutoVal& Level)
{
  AUTONAMES0("MarkTableOfContentsEntry")
  AUTOARGS4(Entry, EntryAutoText, TableId, Level)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawEllipse()
{
  AUTONAMES0("DrawEllipse")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawArc()
{
  AUTONAMES0("DrawArc")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditConvertNotes()
{
  AUTONAMES0("EditConvertNotes")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MarkCitation(TAutoVal& LongCitation, TAutoVal& LongCitationAutoText, TAutoVal& Category, TAutoVal& ShortCitation, TAutoVal& NextCitation, TAutoVal& Mark, TAutoVal& MarkAll)
{
  AUTONAMES0("MarkCitation")
  AUTOARGS7(LongCitation, LongCitationAutoText, Category, ShortCitation, NextCitation, Mark, MarkAll)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawGroup()
{
  AUTONAMES0("DrawGroup")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawBringToFront()
{
  AUTONAMES0("DrawBringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawSendToBack()
{
  AUTONAMES0("DrawSendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawSendBehindText()
{
  AUTONAMES0("DrawSendBehindText")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawBringInFrontOfText()
{
  AUTONAMES0("DrawBringInFrontOfText")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertTableOfAuthorities(TAutoVal& Outline, TAutoVal& Fields, TAutoVal& From, TAutoVal& To, TAutoVal& TableId, TAutoVal& AddedStyles, TAutoVal& Caption, TAutoVal& HeadingSeparator, TAutoVal& Replace, TAutoVal& MarkEntry, TAutoVal& AutoMark, TAutoVal& MarkCitation, TAutoVal& Type, TAutoVal& RightAlignPageNumbers, TAutoVal& Passim, TAutoVal& KeepFormatting, TAutoVal& Columns, TAutoVal& Category, TAutoVal& Label)
{
  AUTONAMES0("InsertTableOfAuthorities")
  AUTOARGS19(Outline, Fields, From, To, TableId, AddedStyles, Caption, HeadingSeparator, Replace, MarkEntry, AutoMark, MarkCitation, Type, RightAlignPageNumbers, Passim, KeepFormatting, Columns, Category, Label)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertTableOfFigures(TAutoVal& Outline, TAutoVal& Fields, TAutoVal& From, TAutoVal& To, TAutoVal& TableId, TAutoVal& AddedStyles, TAutoVal& Caption, TAutoVal& HeadingSeparator, TAutoVal& Replace, TAutoVal& MarkEntry, TAutoVal& AutoMark, TAutoVal& MarkCitation, TAutoVal& Type, TAutoVal& RightAlignPageNumbers, TAutoVal& Passim, TAutoVal& KeepFormatting, TAutoVal& Columns, TAutoVal& Category, TAutoVal& Label)
{
  AUTONAMES0("InsertTableOfFigures")
  AUTOARGS19(Outline, Fields, From, To, TableId, AddedStyles, Caption, HeadingSeparator, Replace, MarkEntry, AutoMark, MarkCitation, Type, RightAlignPageNumbers, Passim, KeepFormatting, Columns, Category, Label)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeNextRecord()
{
  AUTONAMES0("MailMergeNextRecord")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergePrevRecord()
{
  AUTONAMES0("MailMergePrevRecord")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeFirstRecord()
{
  AUTONAMES0("MailMergeFirstRecord")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeLastRecord()
{
  AUTONAMES0("MailMergeLastRecord")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertFormField(TAutoVal& Entry, TAutoVal& Exit, TAutoVal& Name, TAutoVal& Enable, TAutoVal& TextType, TAutoVal& TextWidth, TAutoVal& TextDefault, TAutoVal& TextFormat, TAutoVal& CheckSize, TAutoVal& CheckWidth, TAutoVal& CheckDefault, TAutoVal& Type, TAutoVal& OwnHelp, TAutoVal& HelpText, TAutoVal& OwnStat, TAutoVal& StatText)
{
  AUTONAMES0("InsertFormField")
  AUTOARGS16(Entry, Exit, Name, Enable, TextType, TextWidth, TextDefault, TextFormat, CheckSize, CheckWidth, CheckDefault, Type, OwnHelp, HelpText, OwnStat, StatText)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawUngroup()
{
  AUTONAMES0("DrawUngroup")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::PasteFormat()
{
  AUTONAMES0("PasteFormat")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatDropCap(TAutoVal& Position, TAutoVal& Font, TAutoVal& DropHeight, TAutoVal& DistFromText)
{
  AUTONAMES0("FormatDropCap")
  AUTOARGS4(Position, Font, DropHeight, DistFromText)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsCreateLabels(TAutoVal& ExtractAddress, TAutoVal& LabelListIndex, TAutoVal& LabelIndex, TAutoVal& LabelDotMatrix, TAutoVal& LabelTray, TAutoVal& LabelAcross, TAutoVal& LabelDown, TAutoVal& EnvAddress, TAutoVal& EnvOmitReturn, TAutoVal& EnvReturn, TAutoVal& PrintBarCode, TAutoVal& SingleLabel, TAutoVal& LabelRow, TAutoVal& LabelColumn, TAutoVal& PrintEnvLabel, TAutoVal& AddToDocument, TAutoVal& EnvWidth, TAutoVal& EnvHeight, TAutoVal& EnvPaperSize, TAutoVal& PrintFIMA, TAutoVal& UseEnvFeeder, TAutoVal& Tab, TAutoVal& LabelAutoText, TAutoVal& LabelText, TAutoVal& AddrFromLeft, TAutoVal& AddrFromTop, TAutoVal& RetAddrFromLeft, TAutoVal& RetAddrFromTop, TAutoVal& LabelTopMargin, TAutoVal& LabelSideMargin, TAutoVal& LabelVertPitch, TAutoVal& LabelHorPitch, TAutoVal& LabelHeight, TAutoVal& LabelWidth)
{
  AUTONAMES0("ToolsCreateLabels")
  AUTOARGS34(ExtractAddress, LabelListIndex, LabelIndex, LabelDotMatrix, LabelTray, LabelAcross, LabelDown, EnvAddress, EnvOmitReturn, EnvReturn, PrintBarCode, SingleLabel, LabelRow, LabelColumn, PrintEnvLabel, AddToDocument, EnvWidth, EnvHeight, EnvPaperSize, PrintFIMA, UseEnvFeeder, Tab, LabelAutoText, LabelText, AddrFromLeft, AddrFromTop, RetAddrFromLeft, RetAddrFromTop, LabelTopMargin, LabelSideMargin, LabelVertPitch, LabelHorPitch, LabelHeight, LabelWidth)
  AUTOCALL_METHOD_VOID
}

void WordBasic::CreateSubdocument()
{
  AUTONAMES0("CreateSubdocument")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewFootnoteSeparator()
{
  AUTONAMES0("ViewFootnoteSeparator")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewFootnoteContSeparator()
{
  AUTONAMES0("ViewFootnoteContSeparator")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewFootnoteContNotice()
{
  AUTONAMES0("ViewFootnoteContNotice")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewEndnoteSeparator()
{
  AUTONAMES0("ViewEndnoteSeparator")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewEndnoteContSeparator()
{
  AUTONAMES0("ViewEndnoteContSeparator")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewEndnoteContNotice()
{
  AUTONAMES0("ViewEndnoteContNotice")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawBringForward()
{
  AUTONAMES0("DrawBringForward")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawSendBackward()
{
  AUTONAMES0("DrawSendBackward")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsProtectDocument(TAutoVal& DocumentPassword, TAutoVal& NoReset, TAutoVal& Type)
{
  AUTONAMES0("ToolsProtectDocument")
  AUTOARGS3(DocumentPassword, NoReset, Type)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsShrinkToFit()
{
  AUTONAMES0("ToolsShrinkToFit")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatStyleGallery(TAutoVal& Template, TAutoVal& Preview)
{
  AUTONAMES0("FormatStyleGallery")
  AUTOARGS2(Template, Preview)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsReviewRevisions(TAutoVal& ShowMarks, TAutoVal& HideMarks, TAutoVal& Wrap, TAutoVal& FindPrevious, TAutoVal& FindNext, TAutoVal& AcceptRevisions, TAutoVal& RejectRevisions)
{
  AUTONAMES0("ToolsReviewRevisions")
  AUTOARGS7(ShowMarks, HideMarks, Wrap, FindPrevious, FindNext, AcceptRevisions, RejectRevisions)
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpSearch()
{
  AUTONAMES0("HelpSearch")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpWordPerfectHelpOptions(TAutoVal& CommandKeyHelp, TAutoVal& DocNavKeys, TAutoVal& MouseSimulation, TAutoVal& DemoGuidance, TAutoVal& DemoSpeed, TAutoVal& HelpType)
{
  AUTONAMES0("HelpWordPerfectHelpOptions")
  AUTOARGS6(CommandKeyHelp, DocNavKeys, MouseSimulation, DemoGuidance, DemoSpeed, HelpType)
  AUTOCALL_METHOD_VOID
}

void WordBasic::GrowFontOnePoint()
{
  AUTONAMES0("GrowFontOnePoint")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShrinkFontOnePoint()
{
  AUTONAMES0("ShrinkFontOnePoint")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FilePrintPreviewFullScreen()
{
  AUTONAMES0("FilePrintPreviewFullScreen")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertSound()
{
  AUTONAMES0("InsertSound")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsUnprotectDocument(TAutoVal& DocumentPassword)
{
  AUTONAMES0("ToolsUnprotectDocument")
  AUTOARGS1(DocumentPassword)
  AUTOCALL_METHOD_VOID
}

void WordBasic::RemoveBulletsNumbers()
{
  AUTONAMES0("RemoveBulletsNumbers")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsOptionsCompatibility(TAutoVal& Product, TAutoVal& Default, TAutoVal& NoTabHangIndent, TAutoVal& NoSpaceRaiseLower, TAutoVal& PrintColBlack, TAutoVal& WrapTrailSpaces, TAutoVal& NoColumnBalance, TAutoVal& ConvMailMergeEsc, TAutoVal& SuppressSpBfAfterPgBrk, TAutoVal& SuppressTopSpacing, TAutoVal& OrigWordTableRules, TAutoVal& TransparentMetafiles, TAutoVal& ShowBreaksInFrames, TAutoVal& SwapBordersFacingPages, TAutoVal& LeaveBackslashAlone, TAutoVal& ExpandShiftReturn, TAutoVal& DontULTrailSpace, TAutoVal& DontBalanceSbDbWidth, TAutoVal& SuppressTopSpacingMac5, TAutoVal& SpacingInWholePoints, TAutoVal& PrintBodyTextBeforeHeader, TAutoVal& NoLeading, TAutoVal& NoSpaceForUL, TAutoVal& MWSmallCaps, TAutoVal& NoExtraLineSpacing, TAutoVal& TruncateFontHeight, TAutoVal& SubFontBySize)
{
  AUTONAMES0("ToolsOptionsCompatibility")
  AUTOARGS27(Product, Default, NoTabHangIndent, NoSpaceRaiseLower, PrintColBlack, WrapTrailSpaces, NoColumnBalance, ConvMailMergeEsc, SuppressSpBfAfterPgBrk, SuppressTopSpacing, OrigWordTableRules, TransparentMetafiles, ShowBreaksInFrames, SwapBordersFacingPages, LeaveBackslashAlone, ExpandShiftReturn, DontULTrailSpace, DontBalanceSbDbWidth, SuppressTopSpacingMac5, SpacingInWholePoints, PrintBodyTextBeforeHeader, NoLeading, NoSpaceForUL, MWSmallCaps, NoExtraLineSpacing, TruncateFontHeight, SubFontBySize)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawRoundRectangle()
{
  AUTONAMES0("DrawRoundRectangle")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawFreeformPolygon()
{
  AUTONAMES0("DrawFreeformPolygon")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::SelectDrawingObjects()
{
  AUTONAMES0("SelectDrawingObjects")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DialogEditor()
{
  AUTONAMES0("DialogEditor")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawFlipHorizontal()
{
  AUTONAMES0("DrawFlipHorizontal")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawFlipVertical()
{
  AUTONAMES0("DrawFlipVertical")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawRotateRight()
{
  AUTONAMES0("DrawRotateRight")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawRotateLeft()
{
  AUTONAMES0("DrawRotateLeft")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableAutoFormat(TAutoVal& HideAutoFit, TAutoVal& Preview, TAutoVal& Format, TAutoVal& Borders, TAutoVal& Shading, TAutoVal& Font, TAutoVal& Color, TAutoVal& AutoFit, TAutoVal& HeadingRows, TAutoVal& FirstColumn, TAutoVal& LastRow, TAutoVal& LastColumn)
{
  AUTONAMES0("TableAutoFormat")
  AUTOARGS12(HideAutoFit, Preview, Format, Borders, Shading, Font, Color, AutoFit, HeadingRows, FirstColumn, LastRow, LastColumn)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatDrawingObject(TAutoVal& Tab, TAutoVal& FillColor, TAutoVal& LineColor, TAutoVal& FillPatternColor, TAutoVal& FillPattern, TAutoVal& LineType, TAutoVal& LineStyle, TAutoVal& LineWeight, TAutoVal& ArrowStyle, TAutoVal& ArrowWidth, TAutoVal& ArrowLength, TAutoVal& Shadow, TAutoVal& RoundCorners, TAutoVal& HorizontalPos, TAutoVal& HorizontalFrom, TAutoVal& VerticalPos, TAutoVal& VerticalFrom, TAutoVal& LockAnchor, TAutoVal& Height, TAutoVal& Width, TAutoVal& InternalMargin)
{
  AUTONAMES0("FormatDrawingObject")
  AUTOARGS21(Tab, FillColor, LineColor, FillPatternColor, FillPattern, LineType, LineStyle, LineWeight, ArrowStyle, ArrowWidth, ArrowLength, Shadow, RoundCorners, HorizontalPos, HorizontalFrom, VerticalPos, VerticalFrom, LockAnchor, Height, Width, InternalMargin)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertExcelTable()
{
  AUTONAMES0("InsertExcelTable")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeFindRecord(TAutoVal& Find, TAutoVal& Field)
{
  AUTONAMES0("MailMergeFindRecord")
  AUTOARGS2(Find, Field)
  AUTOCALL_METHOD_VOID
}

void WordBasic::NormalFontSpacing()
{
  AUTONAMES0("NormalFontSpacing")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::NormalFontPosition()
{
  AUTONAMES0("NormalFontPosition")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewZoom200()
{
  AUTONAMES0("ViewZoom200")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewZoom75()
{
  AUTONAMES0("ViewZoom75")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawDisassemblePicture()
{
  AUTONAMES0("DrawDisassemblePicture")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewZoom(TAutoVal& AutoFit, TAutoVal& TwoPages, TAutoVal& FullPage, TAutoVal& NumColumns, TAutoVal& NumRows, TAutoVal& ZoomPercent)
{
  AUTONAMES0("ViewZoom")
  AUTOARGS6(AutoFit, TwoPages, FullPage, NumColumns, NumRows, ZoomPercent)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsProtectSection(TAutoVal& Protect, TAutoVal& Section)
{
  AUTONAMES0("ToolsProtectSection")
  AUTOARGS2(Protect, Section)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FontSubstitution(TAutoVal& UnavailableFont, TAutoVal& SubstituteFont)
{
  AUTONAMES0("FontSubstitution")
  AUTOARGS2(UnavailableFont, SubstituteFont)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToggleFull()
{
  AUTONAMES0("ToggleFull")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertSubdocument(TAutoVal& Name, TAutoVal& ConfirmConversions, TAutoVal& ReadOnly, TAutoVal& LinkToSource, TAutoVal& AddToMru, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& Revert, TAutoVal& WritePasswordDoc, TAutoVal& WritePasswordDot, TAutoVal& Connection, TAutoVal& SQLStatement, TAutoVal& SQLStatement1)
{
  AUTONAMES0("InsertSubdocument")
  AUTOARGS13(Name, ConfirmConversions, ReadOnly, LinkToSource, AddToMru, PasswordDoc, PasswordDot, Revert, WritePasswordDoc, WritePasswordDot, Connection, SQLStatement, SQLStatement1)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MergeSubdocument()
{
  AUTONAMES0("MergeSubdocument")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::SplitSubdocument()
{
  AUTONAMES0("SplitSubdocument")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::NewToolbar(TAutoVal& Name, TAutoVal& Context)
{
  AUTONAMES0("NewToolbar")
  AUTOARGS2(Name, Context)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToggleMainTextLayer()
{
  AUTONAMES0("ToggleMainTextLayer")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowPrevHeaderFooter()
{
  AUTONAMES0("ShowPrevHeaderFooter")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowNextHeaderFooter()
{
  AUTONAMES0("ShowNextHeaderFooter")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::GoToHeaderFooter()
{
  AUTONAMES0("GoToHeaderFooter")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::PromoteList()
{
  AUTONAMES0("PromoteList")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DemoteList()
{
  AUTONAMES0("DemoteList")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::GotoAnnotationScope()
{
  AUTONAMES0("GotoAnnotationScope")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::OpenSubdocument()
{
  AUTONAMES0("OpenSubdocument")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatDefineStyleNumbers(TAutoVal& Points, TAutoVal& Color, TAutoVal& Before, TAutoVal& Type, TAutoVal& After, TAutoVal& StartAt, TAutoVal& Include, TAutoVal& Alignment, TAutoVal& Indent, TAutoVal& Space, TAutoVal& Hang, TAutoVal& RestartNum, TAutoVal& Level, TAutoVal& CharNum, TAutoVal& Font, TAutoVal& Strikethrough, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Underline, TAutoVal& Remove)
{
  AUTONAMES0("FormatDefineStyleNumbers")
  AUTOARGS20(Points, Color, Before, Type, After, StartAt, Include, Alignment, Indent, Space, Hang, RestartNum, Level, CharNum, Font, Strikethrough, Bold, Italic, Underline, Remove)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatHeadingNumbering(TAutoVal& Remove, TAutoVal& Preset)
{
  AUTONAMES0("FormatHeadingNumbering")
  AUTOARGS2(Remove, Preset)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewBorderToolbar()
{
  AUTONAMES0("ViewBorderToolbar")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewDrawingToolbar()
{
  AUTONAMES0("ViewDrawingToolbar")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatHeadingNumber(TAutoVal& Points, TAutoVal& Color, TAutoVal& Before, TAutoVal& Type, TAutoVal& After, TAutoVal& StartAt, TAutoVal& Include, TAutoVal& Alignment, TAutoVal& Indent, TAutoVal& Space, TAutoVal& Hang, TAutoVal& RestartNum, TAutoVal& Level, TAutoVal& CharNum, TAutoVal& Font, TAutoVal& Strikethrough, TAutoVal& Bold, TAutoVal& Italic, TAutoVal& Underline, TAutoVal& Remove)
{
  AUTONAMES0("FormatHeadingNumber")
  AUTOARGS20(Points, Color, Before, Type, After, StartAt, Include, Alignment, Indent, Space, Hang, RestartNum, Level, CharNum, Font, Strikethrough, Bold, Italic, Underline, Remove)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawReshape()
{
  AUTONAMES0("DrawReshape")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FormatCallout(TAutoVal& Type, TAutoVal& Gap, TAutoVal& Angle, TAutoVal& Drop, TAutoVal& Length, TAutoVal& Border, TAutoVal& AutoAttach, TAutoVal& Accent)
{
  AUTONAMES0("FormatCallout")
  AUTOARGS8(Type, Gap, Angle, Drop, Length, Border, AutoAttach, Accent)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawCallout()
{
  AUTONAMES0("DrawCallout")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileSendMail()
{
  AUTONAMES0("FileSendMail")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsCustomizeMenuBar(TAutoVal& Context, TAutoVal& Position, TAutoVal& MenuType, TAutoVal& MenuText, TAutoVal& Menu, TAutoVal& Add, TAutoVal& Remove, TAutoVal& Rename)
{
  AUTONAMES0("ToolsCustomizeMenuBar")
  AUTOARGS8(Context, Position, MenuType, MenuText, Menu, Add, Remove, Rename)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileRoutingSlip(TAutoVal& Subject, TAutoVal& Message, TAutoVal& AllAtOnce, TAutoVal& ReturnWhenDone, TAutoVal& TrackStatus, TAutoVal& Protect, TAutoVal& AddSlip, TAutoVal& RouteDocument, TAutoVal& AddRecipient, TAutoVal& OldRecipient, TAutoVal& ResetSlip, TAutoVal& ClearSlip, TAutoVal& ClearRecipients, TAutoVal& Address)
{
  AUTONAMES0("FileRoutingSlip")
  AUTOARGS14(Subject, Message, AllAtOnce, ReturnWhenDone, TrackStatus, Protect, AddSlip, RouteDocument, AddRecipient, OldRecipient, ResetSlip, ClearSlip, ClearRecipients, Address)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditTOACategory(TAutoVal& Category, TAutoVal& CategoryName)
{
  AUTONAMES0("EditTOACategory")
  AUTOARGS2(Category, CategoryName)
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableUpdateAutoFormat()
{
  AUTONAMES0("TableUpdateAutoFormat")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ChooseButtonImage(TAutoVal& Face, TAutoVal& Button, TAutoVal& Context, TAutoVal& Text, TAutoVal& Toolbar)
{
  AUTONAMES0("ChooseButtonImage")
  AUTOARGS5(Face, Button, Context, Text, Toolbar)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsAddRecordDefault()
{
  AUTONAMES0("ToolsAddRecordDefault")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsRemoveRecordDefault()
{
  AUTONAMES0("ToolsRemoveRecordDefault")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsManageFields(TAutoVal& FieldName, TAutoVal& Add, TAutoVal& Remove, TAutoVal& Rename, TAutoVal& NewName)
{
  AUTONAMES0("ToolsManageFields")
  AUTOARGS5(FieldName, Add, Remove, Rename, NewName)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ViewToggleMasterDocument()
{
  AUTONAMES0("ViewToggleMasterDocument")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawSnapToGrid(TAutoVal& SnapToGrid, TAutoVal& XGrid, TAutoVal& YGrid, TAutoVal& XOrigin, TAutoVal& YOrigin)
{
  AUTONAMES0("DrawSnapToGrid")
  AUTOARGS5(SnapToGrid, XGrid, YGrid, XOrigin, YOrigin)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawAlign(TAutoVal& Horizontal, TAutoVal& Vertical, TAutoVal& RelativeTo)
{
  AUTONAMES0("DrawAlign")
  AUTOARGS3(Horizontal, Vertical, RelativeTo)
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpTipOfTheDay(TAutoVal& StartupTips)
{
  AUTONAMES0("HelpTipOfTheDay")
  AUTOARGS1(StartupTips)
  AUTOCALL_METHOD_VOID
}

void WordBasic::RemoveSubdocument()
{
  AUTONAMES0("RemoveSubdocument")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::CloseViewHeaderFooter()
{
  AUTONAMES0("CloseViewHeaderFooter")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::TableAutoSum(TAutoVal& Formula, TAutoVal& NumFormat)
{
  AUTONAMES0("TableAutoSum")
  AUTOARGS2(Formula, NumFormat)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeCreateDataSource(TAutoVal& FileName, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& HeaderRecord, TAutoVal& MSQuery, TAutoVal& SQLStatement, TAutoVal& SQLStatement1, TAutoVal& Connection, TAutoVal& LinkToSource)
{
  AUTONAMES0("MailMergeCreateDataSource")
  AUTOARGS9(FileName, PasswordDoc, PasswordDot, HeaderRecord, MSQuery, SQLStatement, SQLStatement1, Connection, LinkToSource)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeCreateHeaderSource(TAutoVal& FileName, TAutoVal& PasswordDoc, TAutoVal& PasswordDot, TAutoVal& HeaderRecord, TAutoVal& MSQuery, TAutoVal& SQLStatement, TAutoVal& SQLStatement1, TAutoVal& Connection, TAutoVal& LinkToSource)
{
  AUTONAMES0("MailMergeCreateHeaderSource")
  AUTOARGS9(FileName, PasswordDoc, PasswordDot, HeaderRecord, MSQuery, SQLStatement, SQLStatement1, Connection, LinkToSource)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawInsertWordPicture()
{
  AUTONAMES0("DrawInsertWordPicture")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToggleHeaderFooterLink()
{
  AUTONAMES0("ToggleHeaderFooterLink")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::AutoText()
{
  AUTONAMES0("AutoText")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MicrosoftMail()
{
  AUTONAMES0("MicrosoftMail")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MicrosoftExcel()
{
  AUTONAMES0("MicrosoftExcel")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MicrosoftAccess()
{
  AUTONAMES0("MicrosoftAccess")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MicrosoftSchedule()
{
  AUTONAMES0("MicrosoftSchedule")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MicrosoftFoxPro()
{
  AUTONAMES0("MicrosoftFoxPro")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MicrosoftPowerPoint()
{
  AUTONAMES0("MicrosoftPowerPoint")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MicrosoftPublisher()
{
  AUTONAMES0("MicrosoftPublisher")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MicrosoftProject()
{
  AUTONAMES0("MicrosoftProject")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ScreenRefresh()
{
  AUTONAMES0("ScreenRefresh")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawNudgeUp()
{
  AUTONAMES0("DrawNudgeUp")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawNudgeDown()
{
  AUTONAMES0("DrawNudgeDown")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawNudgeLeft()
{
  AUTONAMES0("DrawNudgeLeft")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawNudgeRight()
{
  AUTONAMES0("DrawNudgeRight")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeEditHeaderSource()
{
  AUTONAMES0("MailMergeEditHeaderSource")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMerge(TAutoVal& CheckErrors, TAutoVal& Destination, TAutoVal& MergeRecords, TAutoVal& From, TAutoVal& To, TAutoVal& Suppression, TAutoVal& MailMerge, TAutoVal& QueryOptions, TAutoVal& MailSubject, TAutoVal& MailAsAttachment, TAutoVal& MailAddress)
{
  AUTONAMES0("MailMerge")
  AUTOARGS11(CheckErrors, Destination, MergeRecords, From, To, Suppression, MailMerge, QueryOptions, MailSubject, MailAsAttachment, MailAddress)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeCheck(TAutoVal& CheckErrors)
{
  AUTONAMES0("MailMergeCheck")
  AUTOARGS1(CheckErrors)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeToDoc()
{
  AUTONAMES0("MailMergeToDoc")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeToPrinter()
{
  AUTONAMES0("MailMergeToPrinter")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeHelper(TAutoVal& Merge, TAutoVal& Options)
{
  AUTONAMES0("MailMergeHelper")
  AUTOARGS2(Merge, Options)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeQueryOptions(TAutoVal& SQLStatement, TAutoVal& SQLStatement1)
{
  AUTONAMES0("MailMergeQueryOptions")
  AUTOARGS2(SQLStatement, SQLStatement1)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertWordArt()
{
  AUTONAMES0("InsertWordArt")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertEquation()
{
  AUTONAMES0("InsertEquation")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::RunPrintManager()
{
  AUTONAMES0("RunPrintManager")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::HelpContents()
{
  AUTONAMES0("HelpContents")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileClosePicture()
{
  AUTONAMES0("FileClosePicture")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawResetWordPicture()
{
  AUTONAMES0("DrawResetWordPicture")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawNudgeUpPixel()
{
  AUTONAMES0("DrawNudgeUpPixel")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawNudgeDownPixel()
{
  AUTONAMES0("DrawNudgeDownPixel")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawNudgeLeftPixel()
{
  AUTONAMES0("DrawNudgeLeftPixel")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawNudgeRightPixel()
{
  AUTONAMES0("DrawNudgeRightPixel")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsHyphenationManual()
{
  AUTONAMES0("ToolsHyphenationManual")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::ClearFormField()
{
  AUTONAMES0("ClearFormField")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertSectionBreak()
{
  AUTONAMES0("InsertSectionBreak")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawUnselect()
{
  AUTONAMES0("DrawUnselect")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawSelectNext()
{
  AUTONAMES0("DrawSelectNext")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawSelectPrevious()
{
  AUTONAMES0("DrawSelectPrevious")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MicrosoftSystemInfo()
{
  AUTONAMES0("MicrosoftSystemInfo")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeInsertAsk(TAutoVal& Name, TAutoVal& Prompt, TAutoVal& DefaultBookmarkText, TAutoVal& AskOnce)
{
  AUTONAMES0("MailMergeInsertAsk")
  AUTOARGS4(Name, Prompt, DefaultBookmarkText, AskOnce)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeInsertFillIn(TAutoVal& Prompt, TAutoVal& DefaultFillInText, TAutoVal& AskOnce)
{
  AUTONAMES0("MailMergeInsertFillIn")
  AUTOARGS3(Prompt, DefaultFillInText, AskOnce)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeInsertIf(TAutoVal& MergeField, TAutoVal& Comparison, TAutoVal& CompareTo, TAutoVal& TrueAutoText, TAutoVal& TrueText, TAutoVal& FalseAutoText, TAutoVal& FalseText)
{
  AUTONAMES0("MailMergeInsertIf")
  AUTOARGS7(MergeField, Comparison, CompareTo, TrueAutoText, TrueText, FalseAutoText, FalseText)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeInsertMergeRec()
{
  AUTONAMES0("MailMergeInsertMergeRec")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeInsertMergeSeq()
{
  AUTONAMES0("MailMergeInsertMergeSeq")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeInsertNext()
{
  AUTONAMES0("MailMergeInsertNext")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeInsertNextIf(TAutoVal& MergeField, TAutoVal& Comparison, TAutoVal& CompareTo)
{
  AUTONAMES0("MailMergeInsertNextIf")
  AUTOARGS3(MergeField, Comparison, CompareTo)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeInsertSet(TAutoVal& Name, TAutoVal& ValueText, TAutoVal& ValueAutoText)
{
  AUTONAMES0("MailMergeInsertSet")
  AUTOARGS3(Name, ValueText, ValueAutoText)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMergeInsertSkipIf(TAutoVal& MergeField, TAutoVal& Comparison, TAutoVal& CompareTo)
{
  AUTONAMES0("MailMergeInsertSkipIf")
  AUTOARGS3(MergeField, Comparison, CompareTo)
  AUTOCALL_METHOD_VOID
}

double WordBasic::Rnd()
{
  AUTONAMES0("Rnd")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

long WordBasic::Instr(TAutoVal& Index, TAutoString Source, TAutoString Search)
{
  AUTONAMES0("Instr")
  AUTOARGS3(Index, Source, Search)
  AUTOCALL_METHOD_RET
}

double WordBasic::Abs(double n)
{
  AUTONAMES0("Abs")
  AUTOARGS1(n)
  AUTOCALL_METHOD_RET
}

short WordBasic::Sgn(double n)
{
  AUTONAMES0("Sgn")
  AUTOARGS1(n)
  AUTOCALL_METHOD_RET
}

short WordBasic::Int(short n)
{
  AUTONAMES0("Int")
  AUTOARGS1(n)
  AUTOCALL_METHOD_RET
}

long WordBasic::Len(TAutoString Source)
{
  AUTONAMES0("Len")
  AUTOARGS1(Source)
  AUTOCALL_METHOD_RET
}

short WordBasic::Asc(TAutoString a)
{
  AUTONAMES0("Asc")
  AUTOARGS1(a)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::Chr(short CharCode)
{
  AUTONAMES0("Chr")
  AUTOARGS1(CharCode)
  AUTOCALL_METHOD_RET
}

double WordBasic::Val(TAutoString a)
{
  AUTONAMES0("Val")
  AUTOARGS1(a)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::Str(double n)
{
  AUTONAMES0("Str")
  AUTOARGS1(n)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::Left(TAutoString Source, long Count)
{
  AUTONAMES0("Left")
  AUTOARGS2(Source, Count)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::Right(TAutoString Source, long Count)
{
  AUTONAMES0("Right")
  AUTOARGS2(Source, Count)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::Mid(TAutoString Source, long Start, TAutoVal& Count)
{
  AUTONAMES0("Mid")
  AUTOARGS3(Source, Start, Count)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::String(long Count, TAutoString Source)
{
  AUTONAMES0("String")
  AUTOARGS2(Count, Source)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::Date(TAutoVal& SerialNumber)
{
  AUTONAMES0("Date")
  AUTOARGS1(SerialNumber)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::Time(TAutoVal& SerialNumber)
{
  AUTONAMES0("Time")
  AUTOARGS1(SerialNumber)
  AUTOCALL_METHOD_RET
}

short WordBasic::ShowAll(TAutoVal& On)
{
  AUTONAMES0("ShowAll")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

void WordBasic::ColumnSelect()
{
  AUTONAMES0("ColumnSelect")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Insert(TAutoString Text)
{
  AUTONAMES0("Insert")
  AUTOARGS1(Text)
  AUTOCALL_METHOD_VOID
}

void WordBasic::InsertPara()
{
  AUTONAMES0("InsertPara")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::Selection()
{
  AUTONAMES0("Selection")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetBookmark(TAutoString Name)
{
  AUTONAMES0("GetBookmark")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

short WordBasic::CmpBookmarks(TAutoString Bookmark1, TAutoString Bookmark2)
{
  AUTONAMES0("CmpBookmarks")
  AUTOARGS2(Bookmark1, Bookmark2)
  AUTOCALL_METHOD_RET
}

void WordBasic::CopyBookmark(TAutoString Bookmark1, TAutoString Bookmark2)
{
  AUTONAMES0("CopyBookmark")
  AUTOARGS2(Bookmark1, Bookmark2)
  AUTOCALL_METHOD_VOID
}

void WordBasic::SetStartOfBookmark(TAutoString Bookmark1, TAutoVal& Bookmark2)
{
  AUTONAMES0("SetStartOfBookmark")
  AUTOARGS2(Bookmark1, Bookmark2)
  AUTOCALL_METHOD_VOID
}

void WordBasic::SetEndOfBookmark(TAutoString Bookmark1, TAutoVal& Bookmark2)
{
  AUTONAMES0("SetEndOfBookmark")
  AUTOARGS2(Bookmark1, Bookmark2)
  AUTOCALL_METHOD_VOID
}

short WordBasic::ExistingBookmark(TAutoString Name)
{
  AUTONAMES0("ExistingBookmark")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

short WordBasic::EmptyBookmark(TAutoString Name)
{
  AUTONAMES0("EmptyBookmark")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountBookmarks()
{
  AUTONAMES0("CountBookmarks")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::CountMergeFields()
{
  AUTONAMES0("CountMergeFields")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::BookmarkName(short Count)
{
  AUTONAMES0("BookmarkName")
  AUTOARGS1(Count)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::MergeFieldName(short Count)
{
  AUTONAMES0("MergeFieldName")
  AUTOARGS1(Count)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountStyles(TAutoVal& Context, TAutoVal& All)
{
  AUTONAMES0("CountStyles")
  AUTOARGS2(Context, All)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::StyleName(TAutoVal& Count, TAutoVal& Context, TAutoVal& All)
{
  AUTONAMES0("StyleName")
  AUTOARGS3(Count, Context, All)
  AUTOCALL_METHOD_RET
}

short WordBasic::IsDocumentDirty()
{
  AUTONAMES0("IsDocumentDirty")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::SetDocumentDirty(TAutoVal& Dirty)
{
  AUTONAMES0("SetDocumentDirty")
  AUTOARGS1(Dirty)
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::FileName(TAutoVal& Number)
{
  AUTONAMES0("FileName")
  AUTOARGS1(Number)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountFiles()
{
  AUTONAMES0("CountFiles")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetAutoText(TAutoString Name, TAutoVal& Context)
{
  AUTONAMES0("GetAutoText")
  AUTOARGS2(Name, Context)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountAutoTextEntries(TAutoVal& Context)
{
  AUTONAMES0("CountAutoTextEntries")
  AUTOARGS1(Context)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::AutoTextName(short Count, TAutoVal& Context)
{
  AUTONAMES0("AutoTextName")
  AUTOARGS2(Count, Context)
  AUTOCALL_METHOD_RET
}

void WordBasic::SetAutoText(TAutoString Name, TAutoString Text, TAutoVal& Context)
{
  AUTONAMES0("SetAutoText")
  AUTOARGS3(Name, Text, Context)
  AUTOCALL_METHOD_VOID
}

short WordBasic::MsgBox(TAutoString Message, TAutoVal& Title, TAutoVal& Type)
{
  AUTONAMES0("MsgBox")
  AUTOARGS3(Message, Title, Type)
  AUTOCALL_METHOD_RET
}

void WordBasic::Beep(TAutoVal& BeepType)
{
  AUTONAMES0("Beep")
  AUTOARGS1(BeepType)
  AUTOCALL_METHOD_VOID
}

void WordBasic::Shell(TAutoString Application, TAutoVal& WindowStyle)
{
  AUTONAMES0("Shell")
  AUTOARGS2(Application, WindowStyle)
  AUTOCALL_METHOD_VOID
}

short WordBasic::ResetChar()
{
  AUTONAMES0("ResetChar")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::ResetPara()
{
  AUTONAMES0("ResetPara")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::TabType(double Pos)
{
  AUTONAMES0("TabType")
  AUTOARGS1(Pos)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::TabLeader(double Pos)
{
  AUTONAMES0("TabLeader")
  AUTOARGS1(Pos)
  AUTOCALL_METHOD_RET
}

void WordBasic::DocMove(short HorizPos, short VertPos)
{
  AUTONAMES0("DocMove")
  AUTOARGS2(HorizPos, VertPos)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DocSize(short Width, short Height)
{
  AUTONAMES0("DocSize")
  AUTOARGS2(Width, Height)
  AUTOCALL_METHOD_VOID
}

void WordBasic::VLine(TAutoVal& Count)
{
  AUTONAMES0("VLine")
  AUTOARGS1(Count)
  AUTOCALL_METHOD_VOID
}

void WordBasic::HLine(TAutoVal& Count)
{
  AUTONAMES0("HLine")
  AUTOARGS1(Count)
  AUTOCALL_METHOD_VOID
}

void WordBasic::VPage(TAutoVal& Count)
{
  AUTONAMES0("VPage")
  AUTOARGS1(Count)
  AUTOCALL_METHOD_VOID
}

void WordBasic::HPage(TAutoVal& Count)
{
  AUTONAMES0("HPage")
  AUTOARGS1(Count)
  AUTOCALL_METHOD_VOID
}

double WordBasic::VScroll(TAutoVal& Percentage)
{
  AUTONAMES0("VScroll")
  AUTOARGS1(Percentage)
  AUTOCALL_METHOD_RET
}

double WordBasic::HScroll(TAutoVal& Percentage)
{
  AUTONAMES0("HScroll")
  AUTOARGS1(Percentage)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountWindows()
{
  AUTONAMES0("CountWindows")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::WindowName(TAutoVal& Number)
{
  AUTONAMES0("WindowName")
  AUTOARGS1(Number)
  AUTOCALL_METHOD_RET
}

short WordBasic::WindowPane()
{
  AUTONAMES0("WindowPane")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::DocSplit(TAutoVal& Percentage)
{
  AUTONAMES0("DocSplit")
  AUTOARGS1(Percentage)
  AUTOCALL_METHOD_RET
}

short WordBasic::Window()
{
  AUTONAMES0("Window")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::AppSize(TAutoString WindowName, short Width, TAutoVal& Heigth)
{
  AUTONAMES0("AppSize")
  AUTOARGS3(WindowName, Width, Heigth)
  AUTOCALL_METHOD_VOID
}

void WordBasic::AppMove(TAutoString WindowName, short HorizPos, TAutoVal& VertPos)
{
  AUTONAMES0("AppMove")
  AUTOARGS3(WindowName, HorizPos, VertPos)
  AUTOCALL_METHOD_VOID
}

short WordBasic::AppMinimize(TAutoVal& WindowName, TAutoVal& State)
{
  AUTONAMES0("AppMinimize")
  AUTOARGS2(WindowName, State)
  AUTOCALL_METHOD_RET
}

short WordBasic::AppMaximize(TAutoVal& WindowName, TAutoVal& State)
{
  AUTONAMES0("AppMaximize")
  AUTOARGS2(WindowName, State)
  AUTOCALL_METHOD_RET
}

short WordBasic::AppRestore(TAutoVal& WindowName)
{
  AUTONAMES0("AppRestore")
  AUTOARGS1(WindowName)
  AUTOCALL_METHOD_RET
}

short WordBasic::DocMaximize(TAutoVal& State)
{
  AUTONAMES0("DocMaximize")
  AUTOARGS1(State)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetProfileString(TAutoString Section, TAutoVal& KeyName)
{
  AUTONAMES0("GetProfileString")
  AUTOARGS2(Section, KeyName)
  AUTOCALL_METHOD_RET
}

short WordBasic::SetProfileString(TAutoString Section, TAutoString KeyName, TAutoVal& Setting)
{
  AUTONAMES0("SetProfileString")
  AUTOARGS3(Section, KeyName, Setting)
  AUTOCALL_METHOD_RET
}

short WordBasic::CharColor(TAutoVal& Color)
{
  AUTONAMES0("CharColor")
  AUTOARGS1(Color)
  AUTOCALL_METHOD_RET
}

short WordBasic::Bold(TAutoVal& On)
{
  AUTONAMES0("Bold")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::Italic(TAutoVal& On)
{
  AUTONAMES0("Italic")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::SmallCaps(TAutoVal& On)
{
  AUTONAMES0("SmallCaps")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::AllCaps(TAutoVal& On)
{
  AUTONAMES0("AllCaps")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::Strikethrough(TAutoVal& On)
{
  AUTONAMES0("Strikethrough")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::Hidden(TAutoVal& On)
{
  AUTONAMES0("Hidden")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::Underline(TAutoVal& On)
{
  AUTONAMES0("Underline")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::DoubleUnderline(TAutoVal& On)
{
  AUTONAMES0("DoubleUnderline")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::WordUnderline(TAutoVal& On)
{
  AUTONAMES0("WordUnderline")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::Superscript(TAutoVal& On)
{
  AUTONAMES0("Superscript")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::Subscript(TAutoVal& On)
{
  AUTONAMES0("Subscript")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::CenterPara()
{
  AUTONAMES0("CenterPara")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::LeftPara()
{
  AUTONAMES0("LeftPara")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::RightPara()
{
  AUTONAMES0("RightPara")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::JustifyPara()
{
  AUTONAMES0("JustifyPara")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::SpacePara1()
{
  AUTONAMES0("SpacePara1")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::SpacePara15()
{
  AUTONAMES0("SpacePara15")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::SpacePara2()
{
  AUTONAMES0("SpacePara2")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::OpenUpPara()
{
  AUTONAMES0("OpenUpPara")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::CloseUpPara()
{
  AUTONAMES0("CloseUpPara")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

short WordBasic::DDEInitiate(TAutoString Application, TAutoString Topic)
{
  AUTONAMES0("DDEInitiate")
  AUTOARGS2(Application, Topic)
  AUTOCALL_METHOD_RET
}

void WordBasic::DDETerminate(short ChanNum)
{
  AUTONAMES0("DDETerminate")
  AUTOARGS1(ChanNum)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DDETerminateAll()
{
  AUTONAMES0("DDETerminateAll")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::DDEExecute(short ChanNum, TAutoString Command)
{
  AUTONAMES0("DDEExecute")
  AUTOARGS2(ChanNum, Command)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DDEPoke(short ChanNum, TAutoString Item, TAutoString Data)
{
  AUTONAMES0("DDEPoke")
  AUTOARGS3(ChanNum, Item, Data)
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::DDERequest(short ChanNum, TAutoString Item)
{
  AUTONAMES0("DDERequest")
  AUTOARGS2(ChanNum, Item)
  AUTOCALL_METHOD_RET
}

void WordBasic::Activate(TAutoString WindowTitle, TAutoVal& PaneNum)
{
  AUTONAMES0("Activate")
  AUTOARGS2(WindowTitle, PaneNum)
  AUTOCALL_METHOD_VOID
}

void WordBasic::AppActivate(TAutoString WindowName, TAutoVal& Immediate)
{
  AUTONAMES0("AppActivate")
  AUTOARGS2(WindowName, Immediate)
  AUTOCALL_METHOD_VOID
}

void WordBasic::SendKeys(TAutoString Keys, TAutoVal& Wait)
{
  AUTONAMES0("SendKeys")
  AUTOARGS2(Keys, Wait)
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::StyleDesc(TAutoString StyleName)
{
  AUTONAMES0("StyleDesc")
  AUTOARGS1(StyleName)
  AUTOCALL_METHOD_RET
}

short WordBasic::ParaKeepLinesTogether(TAutoVal& On)
{
  AUTONAMES0("ParaKeepLinesTogether")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ParaKeepWithNext(TAutoVal& On)
{
  AUTONAMES0("ParaKeepWithNext")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ParaPageBreakBefore(TAutoVal& On)
{
  AUTONAMES0("ParaPageBreakBefore")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ParaWidowOrphanControl(TAutoVal& On)
{
  AUTONAMES0("ParaWidowOrphanControl")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewFootnotes()
{
  AUTONAMES0("ViewFootnotes")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewAnnotations(TAutoVal& On)
{
  AUTONAMES0("ViewAnnotations")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewFieldCodes(TAutoVal& On)
{
  AUTONAMES0("ViewFieldCodes")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewDraft(TAutoVal& On)
{
  AUTONAMES0("ViewDraft")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewStatusBar(TAutoVal& On)
{
  AUTONAMES0("ViewStatusBar")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewRuler(TAutoVal& On)
{
  AUTONAMES0("ViewRuler")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewRibbon(TAutoVal& On)
{
  AUTONAMES0("ViewRibbon")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewPage()
{
  AUTONAMES0("ViewPage")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewOutline()
{
  AUTONAMES0("ViewOutline")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewNormal()
{
  AUTONAMES0("ViewNormal")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewMenus()
{
  AUTONAMES0("ViewMenus")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::TableGridlines(TAutoVal& On)
{
  AUTONAMES0("TableGridlines")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::OutlineShowFirstLine(TAutoVal& On)
{
  AUTONAMES0("OutlineShowFirstLine")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::Overtype(TAutoVal& On)
{
  AUTONAMES0("Overtype")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountFonts()
{
  AUTONAMES0("CountFonts")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::Font(TAutoString Name, TAutoVal& Size)
{
  AUTONAMES0("Font")
  AUTOARGS2(Name, Size)
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::FontStr(TAutoVal& Count)
{
  AUTONAMES0("FontStr")
  AUTOARGS1(Count)
  AUTOCALL_METHOD_RET
}

double WordBasic::FontSize(TAutoVal& Size)
{
  AUTONAMES0("FontSize")
  AUTOARGS1(Size)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountLanguages()
{
  AUTONAMES0("CountLanguages")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::Language(TAutoString Language)
{
  AUTONAMES0("Language")
  AUTOARGS1(Language)
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::LanguageStr(TAutoVal& Language)
{
  AUTONAMES0("LanguageStr")
  AUTOARGS1(Language)
  AUTOCALL_METHOD_RET
}

void WordBasic::EditClear(TAutoVal& Count)
{
  AUTONAMES0("EditClear")
  AUTOARGS1(Count)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileList(short Number)
{
  AUTONAMES0("FileList")
  AUTOARGS1(Number)
  AUTOCALL_METHOD_VOID
}

void WordBasic::File1()
{
  AUTONAMES0("File1")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::File2()
{
  AUTONAMES0("File2")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::File3()
{
  AUTONAMES0("File3")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::File4()
{
  AUTONAMES0("File4")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::File5()
{
  AUTONAMES0("File5")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::File6()
{
  AUTONAMES0("File6")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::File7()
{
  AUTONAMES0("File7")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::File8()
{
  AUTONAMES0("File8")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::File9()
{
  AUTONAMES0("File9")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

short WordBasic::NextPage()
{
  AUTONAMES0("NextPage")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::PrevPage()
{
  AUTONAMES0("PrevPage")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::NextObject()
{
  AUTONAMES0("NextObject")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::PrevObject()
{
  AUTONAMES0("PrevObject")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::ExtendSelection(TAutoVal& Character)
{
  AUTONAMES0("ExtendSelection")
  AUTOARGS1(Character)
  AUTOCALL_METHOD_VOID
}

short WordBasic::ExtendMode()
{
  AUTONAMES0("ExtendMode")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::SelType(TAutoVal& Type)
{
  AUTONAMES0("SelType")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_RET
}

short WordBasic::OutlineLevel()
{
  AUTONAMES0("OutlineLevel")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

double WordBasic::NextTab(double Position)
{
  AUTONAMES0("NextTab")
  AUTOARGS1(Position)
  AUTOCALL_METHOD_RET
}

double WordBasic::PrevTab(double Position)
{
  AUTONAMES0("PrevTab")
  AUTOARGS1(Position)
  AUTOCALL_METHOD_RET
}

void WordBasic::DisableInput(TAutoVal& Disable)
{
  AUTONAMES0("DisableInput")
  AUTOARGS1(Disable)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DocClose(TAutoVal& Save)
{
  AUTONAMES0("DocClose")
  AUTOARGS1(Save)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileClose(TAutoVal& Save, TAutoVal& SaveAll)
{
  AUTONAMES0("FileClose")
  AUTOARGS2(Save, SaveAll)
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::Files(TAutoVal& FileSpec)
{
  AUTONAMES0("Files")
  AUTOARGS1(FileSpec)
  AUTOCALL_METHOD_RET
}

void WordBasic::FileSaveAll(TAutoVal& Save, TAutoVal& OriginalFormat)
{
  AUTONAMES0("FileSaveAll")
  AUTOARGS2(Save, OriginalFormat)
  AUTOCALL_METHOD_VOID
}

short WordBasic::FilePrintPreview(TAutoVal& On)
{
  AUTONAMES0("FilePrintPreview")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::FilePrintPreviewPages(TAutoVal& PagesAcross)
{
  AUTONAMES0("FilePrintPreviewPages")
  AUTOARGS1(PagesAcross)
  AUTOCALL_METHOD_RET
}

void WordBasic::Kill(TAutoString FileName)
{
  AUTONAMES0("Kill")
  AUTOARGS1(FileName)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ChDir(TAutoString Path)
{
  AUTONAMES0("ChDir")
  AUTOARGS1(Path)
  AUTOCALL_METHOD_VOID
}

void WordBasic::MkDir(TAutoString Name)
{
  AUTONAMES0("MkDir")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_VOID
}

void WordBasic::RmDir(TAutoString Name)
{
  AUTONAMES0("RmDir")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::UCase(TAutoString Source)
{
  AUTONAMES0("UCase")
  AUTOARGS1(Source)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::LCase(TAutoString Source)
{
  AUTONAMES0("LCase")
  AUTOARGS1(Source)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::InputBox(TAutoString Prompt, TAutoVal& Title, TAutoVal& Default)
{
  AUTONAMES0("InputBox")
  AUTOARGS3(Prompt, Title, Default)
  AUTOCALL_METHOD_RET
}

void WordBasic::OnTime(TAutoString When, TAutoString Name, TAutoVal& Tolerance)
{
  AUTONAMES0("OnTime")
  AUTOARGS3(When, Name, Tolerance)
  AUTOCALL_METHOD_VOID
}

short WordBasic::ChangeCase(TAutoVal& Type)
{
  AUTONAMES0("ChangeCase")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::AppInfo(short Type)
{
  AUTONAMES0("AppInfo")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_RET
}

short WordBasic::SelInfo(short Type)
{
  AUTONAMES0("SelInfo")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountMacros(TAutoVal& Context, TAutoVal& All, TAutoVal& Global)
{
  AUTONAMES0("CountMacros")
  AUTOARGS3(Context, All, Global)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::MacroName(short Count, TAutoVal& Context, TAutoVal& All, TAutoVal& Global)
{
  AUTONAMES0("MacroName")
  AUTOARGS4(Count, Context, All, Global)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountFoundFiles()
{
  AUTONAMES0("CountFoundFiles")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::FoundFileName(short Number)
{
  AUTONAMES0("FoundFileName")
  AUTOARGS1(Number)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::MacroDesc(TAutoString Name)
{
  AUTONAMES0("MacroDesc")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountKeys(TAutoVal& Context)
{
  AUTONAMES0("CountKeys")
  AUTOARGS1(Context)
  AUTOCALL_METHOD_RET
}

short WordBasic::KeyCode(short Coount, TAutoVal& Context, TAutoVal& FirstOrSecond)
{
  AUTONAMES0("KeyCode")
  AUTOARGS3(Coount, Context, FirstOrSecond)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::KeyMacro(short Count, TAutoVal& Context)
{
  AUTONAMES0("KeyMacro")
  AUTOARGS2(Count, Context)
  AUTOCALL_METHOD_RET
}

void WordBasic::MacroCopy(TAutoString Macro1, TAutoString Macro2, TAutoVal& ExecuteOnly)
{
  AUTONAMES0("MacroCopy")
  AUTOARGS3(Macro1, Macro2, ExecuteOnly)
  AUTOCALL_METHOD_VOID
}

short WordBasic::IsExecuteOnly(TAutoVal& Macro)
{
  AUTONAMES0("IsExecuteOnly")
  AUTOARGS1(Macro)
  AUTOCALL_METHOD_RET
}

short WordBasic::CommandValid(TAutoString CommandName)
{
  AUTONAMES0("CommandValid")
  AUTOARGS1(CommandName)
  AUTOCALL_METHOD_RET
}

short WordBasic::NextField()
{
  AUTONAMES0("NextField")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::PrevField()
{
  AUTONAMES0("PrevField")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::NextCell()
{
  AUTONAMES0("NextCell")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::PrevCell()
{
  AUTONAMES0("PrevCell")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::StartOfRow(TAutoVal& Select)
{
  AUTONAMES0("StartOfRow")
  AUTOARGS1(Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::EndOfRow(TAutoVal& Select)
{
  AUTONAMES0("EndOfRow")
  AUTOARGS1(Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::StartOfColumn(TAutoVal& Select)
{
  AUTONAMES0("StartOfColumn")
  AUTOARGS1(Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::EndOfColumn(TAutoVal& Select)
{
  AUTONAMES0("EndOfColumn")
  AUTOARGS1(Select)
  AUTOCALL_METHOD_RET
}

#if 0
void WordBasic::ExitWindows()
{
  AUTONAMES0("ExitWindows")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}
#endif

void WordBasic::DisableAutoMacros(TAutoVal& Disable)
{
  AUTONAMES0("DisableAutoMacros")
  AUTOARGS1(Disable)
  AUTOCALL_METHOD_VOID
}

short WordBasic::EditFindFound()
{
  AUTONAMES0("EditFindFound")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

double WordBasic::ToolsCalculate(TAutoVal& Expression)
{
  AUTONAMES0("ToolsCalculate")
  AUTOARGS1(Expression)
  AUTOCALL_METHOD_RET
}

void WordBasic::WindowList(short Number)
{
  AUTONAMES0("WindowList")
  AUTOARGS1(Number)
  AUTOCALL_METHOD_VOID
}

void WordBasic::Window1()
{
  AUTONAMES0("Window1")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Window2()
{
  AUTONAMES0("Window2")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Window3()
{
  AUTONAMES0("Window3")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Window4()
{
  AUTONAMES0("Window4")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Window5()
{
  AUTONAMES0("Window5")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Window6()
{
  AUTONAMES0("Window6")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Window7()
{
  AUTONAMES0("Window7")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Window8()
{
  AUTONAMES0("Window8")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::Window9()
{
  AUTONAMES0("Window9")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

short WordBasic::CountDirectories(TAutoVal& Directory)
{
  AUTONAMES0("CountDirectories")
  AUTOARGS1(Directory)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetDirectory(TAutoString Directory, TAutoVal& Count)
{
  AUTONAMES0("GetDirectory")
  AUTOARGS2(Directory, Count)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::LTrim(TAutoString Source)
{
  AUTONAMES0("LTrim")
  AUTOARGS1(Source)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::RTrim(TAutoString Source)
{
  AUTONAMES0("RTrim")
  AUTOARGS1(Source)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::Environ(TAutoString EnvironmentVariable)
{
  AUTONAMES0("Environ")
  AUTOARGS1(EnvironmentVariable)
  AUTOCALL_METHOD_RET
}

void WordBasic::WaitCursor(short Wait)
{
  AUTONAMES0("WaitCursor")
  AUTOARGS1(Wait)
  AUTOCALL_METHOD_VOID
}

double WordBasic::DateSerial(short Year, short Month, short Day)
{
  AUTONAMES0("DateSerial")
  AUTOARGS3(Year, Month, Day)
  AUTOCALL_METHOD_RET
}

double WordBasic::DateValue(TAutoString DateText)
{
  AUTONAMES0("DateValue")
  AUTOARGS1(DateText)
  AUTOCALL_METHOD_RET
}

short WordBasic::Day(double SerialNumber)
{
  AUTONAMES0("Day")
  AUTOARGS1(SerialNumber)
  AUTOCALL_METHOD_RET
}

long WordBasic::Days360(TAutoString StartDate, TAutoString EndDate)
{
  AUTONAMES0("Days360")
  AUTOARGS2(StartDate, EndDate)
  AUTOCALL_METHOD_RET
}

short WordBasic::Hour(double SerialNumber)
{
  AUTONAMES0("Hour")
  AUTOARGS1(SerialNumber)
  AUTOCALL_METHOD_RET
}

short WordBasic::Minute(double SerialNumber)
{
  AUTONAMES0("Minute")
  AUTOARGS1(SerialNumber)
  AUTOCALL_METHOD_RET
}

short WordBasic::Month(double SerialNumber)
{
  AUTONAMES0("Month")
  AUTOARGS1(SerialNumber)
  AUTOCALL_METHOD_RET
}

double WordBasic::Now()
{
  AUTONAMES0("Now")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::Weekday(double SerialNumber)
{
  AUTONAMES0("Weekday")
  AUTOARGS1(SerialNumber)
  AUTOCALL_METHOD_RET
}

short WordBasic::Year(double SerialNumber)
{
  AUTONAMES0("Year")
  AUTOARGS1(SerialNumber)
  AUTOCALL_METHOD_RET
}

short WordBasic::DocWindowHeight(TAutoVal& Height)
{
  AUTONAMES0("DocWindowHeight")
  AUTOARGS1(Height)
  AUTOCALL_METHOD_RET
}

short WordBasic::DocWindowWidth(TAutoVal& Width)
{
  AUTONAMES0("DocWindowWidth")
  AUTOARGS1(Width)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::DOSToWin(TAutoString StringToTranslate)
{
  AUTONAMES0("DOSToWin")
  AUTOARGS1(StringToTranslate)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::WinToDOS(TAutoString StringToTranslate)
{
  AUTONAMES0("WinToDOS")
  AUTOARGS1(StringToTranslate)
  AUTOCALL_METHOD_RET
}

double WordBasic::TimeSerial(short Hour, short Minute, short Second)
{
  AUTONAMES0("TimeSerial")
  AUTOARGS3(Hour, Minute, Second)
  AUTOCALL_METHOD_RET
}

short WordBasic::Second(double SerialNumber)
{
  AUTONAMES0("Second")
  AUTOARGS1(SerialNumber)
  AUTOCALL_METHOD_RET
}

double WordBasic::TimeValue(TAutoString TimeText)
{
  AUTONAMES0("TimeValue")
  AUTOARGS1(TimeText)
  AUTOCALL_METHOD_RET
}

double WordBasic::Today()
{
  AUTONAMES0("Today")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::ShowAnnotationBy(TAutoString ReviewerName)
{
  AUTONAMES0("ShowAnnotationBy")
  AUTOARGS1(ReviewerName)
  AUTOCALL_METHOD_VOID
}

void WordBasic::SetAttr(TAutoString FileName, short Attribute)
{
  AUTONAMES0("SetAttr")
  AUTOARGS2(FileName, Attribute)
  AUTOCALL_METHOD_VOID
}

short WordBasic::DocMinimize()
{
  AUTONAMES0("DocMinimize")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetSystemInfo(short Type)
{
  AUTONAMES0("GetSystemInfo")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_RET
}

void WordBasic::AppClose(TAutoVal& WindowName)
{
  AUTONAMES0("AppClose")
  AUTOARGS1(WindowName)
  AUTOCALL_METHOD_VOID
}

short WordBasic::AppCount()
{
  AUTONAMES0("AppCount")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::AppHide(TAutoVal& WindowName)
{
  AUTONAMES0("AppHide")
  AUTOARGS1(WindowName)
  AUTOCALL_METHOD_VOID
}

short WordBasic::AppIsRunning(TAutoString WindowName)
{
  AUTONAMES0("AppIsRunning")
  AUTOARGS1(WindowName)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetPrivateProfileString(TAutoString Section, TAutoString KeyName, TAutoString FileName)
{
  AUTONAMES0("GetPrivateProfileString")
  AUTOARGS3(Section, KeyName, FileName)
  AUTOCALL_METHOD_RET
}

short WordBasic::SetPrivateProfileString(TAutoString Section, TAutoString KeyName, TAutoString Setting, TAutoString FileName)
{
  AUTONAMES0("SetPrivateProfileString")
  AUTOARGS4(Section, KeyName, Setting, FileName)
  AUTOCALL_METHOD_RET
}

short WordBasic::GetAttr(TAutoString FileName)
{
  AUTONAMES0("GetAttr")
  AUTOARGS1(FileName)
  AUTOCALL_METHOD_RET
}

void WordBasic::AppSendMessage(TAutoString WindowName, double Message, double Wparam, TAutoVal& Lparam)
{
  AUTONAMES0("AppSendMessage")
  AUTOARGS4(WindowName, Message, Wparam, Lparam)
  AUTOCALL_METHOD_VOID
}

short WordBasic::ScreenUpdating(TAutoVal& On)
{
  AUTONAMES0("ScreenUpdating")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::AppWindowPosTop(TAutoVal& WindowName, TAutoVal& VertPos)
{
  AUTONAMES0("AppWindowPosTop")
  AUTOARGS2(WindowName, VertPos)
  AUTOCALL_METHOD_RET
}

void WordBasic::Style(TAutoString StyleName)
{
  AUTONAMES0("Style")
  AUTOARGS1(StyleName)
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::MailMergeDataSource(short Type)
{
  AUTONAMES0("MailMergeDataSource")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_RET
}

short WordBasic::MailMergeState(short Type)
{
  AUTONAMES0("MailMergeState")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_RET
}

void WordBasic::SelectCurWord()
{
  AUTONAMES0("SelectCurWord")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::SelectCurSentence()
{
  AUTONAMES0("SelectCurSentence")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

short WordBasic::IsTemplateDirty()
{
  AUTONAMES0("IsTemplateDirty")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::SetTemplateDirty(TAutoVal& Dirty)
{
  AUTONAMES0("SetTemplateDirty")
  AUTOARGS1(Dirty)
  AUTOCALL_METHOD_VOID
}

short WordBasic::ToolsAutoCorrectSmartQuotes(TAutoVal& On)
{
  AUTONAMES0("ToolsAutoCorrectSmartQuotes")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

void WordBasic::AppShow(TAutoVal& WindowName)
{
  AUTONAMES0("AppShow")
  AUTOARGS1(WindowName)
  AUTOCALL_METHOD_VOID
}

short WordBasic::ViewEndnoteArea(TAutoVal& On)
{
  AUTONAMES0("ViewEndnoteArea")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::MailMergeMainDocumentType(TAutoVal& Type)
{
  AUTONAMES0("MailMergeMainDocumentType")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountToolsGrammarStatistics()
{
  AUTONAMES0("CountToolsGrammarStatistics")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::DottedUnderline(TAutoVal& On)
{
  AUTONAMES0("DottedUnderline")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

long WordBasic::MailMergeGoToRecord(TAutoVal& RecordNumber)
{
  AUTONAMES0("MailMergeGoToRecord")
  AUTOARGS1(RecordNumber)
  AUTOCALL_METHOD_RET
}

short WordBasic::BorderLineStyle(TAutoVal& Style)
{
  AUTONAMES0("BorderLineStyle")
  AUTOARGS1(Style)
  AUTOCALL_METHOD_RET
}

short WordBasic::ShadingPattern(TAutoVal& Type)
{
  AUTONAMES0("ShadingPattern")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::MenuItemText(TAutoString Menu, short Type, short Item, TAutoVal& Context)
{
  AUTONAMES0("MenuItemText")
  AUTOARGS4(Menu, Type, Item, Context)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::MenuItemMacro(TAutoString Menu, short Type, short Item, TAutoVal& Context)
{
  AUTONAMES0("MenuItemMacro")
  AUTOARGS4(Menu, Type, Item, Context)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountMenus(short Type, TAutoVal& Context)
{
  AUTONAMES0("CountMenus")
  AUTOARGS2(Type, Context)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::MenuText(short Type, short MenuNumber, TAutoVal& Context)
{
  AUTONAMES0("MenuText")
  AUTOARGS3(Type, MenuNumber, Context)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountMenuItems(TAutoString Menu, short Type, TAutoVal& Context)
{
  AUTONAMES0("CountMenuItems")
  AUTOARGS3(Menu, Type, Context)
  AUTOCALL_METHOD_RET
}

short WordBasic::AppWindowPosLeft(TAutoVal& WindowName, TAutoVal& HorizPos)
{
  AUTONAMES0("AppWindowPosLeft")
  AUTOARGS2(WindowName, HorizPos)
  AUTOCALL_METHOD_RET
}

short WordBasic::AppWindowHeight(TAutoVal& WindowName, TAutoVal& Height)
{
  AUTONAMES0("AppWindowHeight")
  AUTOARGS2(WindowName, Height)
  AUTOCALL_METHOD_RET
}

short WordBasic::AppWindowWidth(TAutoVal& WindowName, TAutoVal& Width)
{
  AUTONAMES0("AppWindowWidth")
  AUTOARGS2(WindowName, Width)
  AUTOCALL_METHOD_RET
}

short WordBasic::DocWindowPosTop(TAutoVal& Position)
{
  AUTONAMES0("DocWindowPosTop")
  AUTOARGS1(Position)
  AUTOCALL_METHOD_RET
}

short WordBasic::DocWindowPosLeft(TAutoVal& Position)
{
  AUTONAMES0("DocWindowPosLeft")
  AUTOARGS1(Position)
  AUTOCALL_METHOD_RET
}

void WordBasic::RenameMenu(TAutoString Menu, TAutoString NewName, short Type, TAutoVal& Context)
{
  AUTONAMES0("RenameMenu")
  AUTOARGS4(Menu, NewName, Type, Context)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileCloseAll(TAutoVal& Save, TAutoVal& SaveAll)
{
  AUTONAMES0("FileCloseAll")
  AUTOARGS2(Save, SaveAll)
  AUTOCALL_METHOD_VOID
}

short WordBasic::SetDocumentVar(TAutoString VariableName, TAutoString VariableText)
{
  AUTONAMES0("SetDocumentVar")
  AUTOARGS2(VariableName, VariableText)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetDocumentVar(TAutoString VariableName)
{
  AUTONAMES0("GetDocumentVar")
  AUTOARGS1(VariableName)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::AnnotationRefFromSel()
{
  AUTONAMES0("AnnotationRefFromSel")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::SetFormResult(TAutoString BookmarkName, TAutoVal& Result, TAutoVal& DefaultResult)
{
  AUTONAMES0("SetFormResult")
  AUTOARGS3(BookmarkName, Result, DefaultResult)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EnableFormField(TAutoString BookmarkName, short Enable)
{
  AUTONAMES0("EnableFormField")
  AUTOARGS2(BookmarkName, Enable)
  AUTOCALL_METHOD_VOID
}

short WordBasic::IsMacro(TAutoVal& WindowName)
{
  AUTONAMES0("IsMacro")
  AUTOARGS1(WindowName)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::FileNameFromWindow(TAutoVal& WindowNumber)
{
  AUTONAMES0("FileNameFromWindow")
  AUTOARGS1(WindowNumber)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::MacroNameFromWindow(TAutoVal& WindowNumber)
{
  AUTONAMES0("MacroNameFromWindow")
  AUTOARGS1(WindowNumber)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetFieldData()
{
  AUTONAMES0("GetFieldData")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::PutFieldData(TAutoString FeildData)
{
  AUTONAMES0("PutFieldData")
  AUTOARGS1(FeildData)
  AUTOCALL_METHOD_RET
}

short WordBasic::MailMergeConvertChevrons(TAutoVal& Convert)
{
  AUTONAMES0("MailMergeConvertChevrons")
  AUTOARGS1(Convert)
  AUTOCALL_METHOD_RET
}

short WordBasic::MailMergeAskToConvertChevrons(TAutoVal& Prompt)
{
  AUTONAMES0("MailMergeAskToConvertChevrons")
  AUTOARGS1(Prompt)
  AUTOCALL_METHOD_RET
}

short WordBasic::AutoMarkIndexEntries(TAutoVal& ConcordanceFilename)
{
  AUTONAMES0("AutoMarkIndexEntries")
  AUTOARGS1(ConcordanceFilename)
  AUTOCALL_METHOD_RET
}

void WordBasic::MoveToolbar(TAutoString Toolbar, short Dock, short HorizPos, short VertPos)
{
  AUTONAMES0("MoveToolbar")
  AUTOARGS4(Toolbar, Dock, HorizPos, VertPos)
  AUTOCALL_METHOD_VOID
}

void WordBasic::SizeToolbar(TAutoString Toolbar, short Width)
{
  AUTONAMES0("SizeToolbar")
  AUTOARGS2(Toolbar, Width)
  AUTOCALL_METHOD_VOID
}

short WordBasic::DrawSetRange(TAutoString Bookmark)
{
  AUTONAMES0("DrawSetRange")
  AUTOARGS1(Bookmark)
  AUTOCALL_METHOD_RET
}

void WordBasic::DrawClearRange()
{
  AUTONAMES0("DrawClearRange")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

short WordBasic::DrawCount()
{
  AUTONAMES0("DrawCount")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::DrawSelect(short Object)
{
  AUTONAMES0("DrawSelect")
  AUTOARGS1(Object)
  AUTOCALL_METHOD_RET
}

short WordBasic::DrawExtendSelect(short Count)
{
  AUTONAMES0("DrawExtendSelect")
  AUTOARGS1(Count)
  AUTOCALL_METHOD_RET
}

void WordBasic::DrawSetInsertToTextbox(TAutoVal& Object)
{
  AUTONAMES0("DrawSetInsertToTextbox")
  AUTOARGS1(Object)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DrawSetInsertToAnchor(TAutoVal& Object)
{
  AUTONAMES0("DrawSetInsertToAnchor")
  AUTOARGS1(Object)
  AUTOCALL_METHOD_VOID
}

short WordBasic::DrawGetType(TAutoVal& Count)
{
  AUTONAMES0("DrawGetType")
  AUTOARGS1(Count)
  AUTOCALL_METHOD_RET
}

short WordBasic::DrawCountPolyPoints(TAutoVal& Object)
{
  AUTONAMES0("DrawCountPolyPoints")
  AUTOARGS1(Object)
  AUTOCALL_METHOD_RET
}

short WordBasic::Magnifier(TAutoVal& On)
{
  AUTONAMES0("Magnifier")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

long WordBasic::GetSelStartPos()
{
  AUTONAMES0("GetSelStartPos")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

long WordBasic::GetSelEndPos()
{
  AUTONAMES0("GetSelEndPos")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::SetSelRange(long Pos1, long Pos2)
{
  AUTONAMES0("SetSelRange")
  AUTOARGS2(Pos1, Pos2)
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::GetText(long Pos1, long Pos2)
{
  AUTONAMES0("GetText")
  AUTOARGS2(Pos1, Pos2)
  AUTOCALL_METHOD_RET
}

void WordBasic::MoveButton(TAutoString SourceToolbar, short SourcePosition, TAutoString TargetToolbar, short TargetpPosition, TAutoVal& Copy, TAutoVal& Context)
{
  AUTONAMES0("MoveButton")
  AUTOARGS6(SourceToolbar, SourcePosition, TargetToolbar, TargetpPosition, Copy, Context)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DeleteButton(TAutoString Toolbar, short Position, TAutoVal& Context)
{
  AUTONAMES0("DeleteButton")
  AUTOARGS3(Toolbar, Position, Context)
  AUTOCALL_METHOD_VOID
}

void WordBasic::AddButton(TAutoString Toolbar, short Position, short Category, TAutoString Name, TAutoVal& ButtonTxtOrImageNum, TAutoVal& Context, TAutoVal& CommandValue)
{
  AUTONAMES0("AddButton")
  AUTOARGS7(Toolbar, Position, Category, Name, ButtonTxtOrImageNum, Context, CommandValue)
  AUTOCALL_METHOD_VOID
}

void WordBasic::DeleteAddIn(TAutoString AddIn)
{
  AUTONAMES0("DeleteAddIn")
  AUTOARGS1(AddIn)
  AUTOCALL_METHOD_VOID
}

short WordBasic::AddAddIn(TAutoString AddIn, TAutoVal& Load)
{
  AUTONAMES0("AddAddIn")
  AUTOARGS2(AddIn, Load)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetAddInName(short AddInID)
{
  AUTONAMES0("GetAddInName")
  AUTOARGS1(AddInID)
  AUTOCALL_METHOD_RET
}

short WordBasic::FormatBulletDefault(TAutoVal& Add)
{
  AUTONAMES0("FormatBulletDefault")
  AUTOARGS1(Add)
  AUTOCALL_METHOD_RET
}

short WordBasic::FormatNumberDefault(TAutoVal& On)
{
  AUTONAMES0("FormatNumberDefault")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

void WordBasic::ResetButtonImage(TAutoString Toolbar, short Tool, TAutoVal& Context)
{
  AUTONAMES0("ResetButtonImage")
  AUTOARGS3(Toolbar, Tool, Context)
  AUTOCALL_METHOD_VOID
}

short WordBasic::SkipNumbering()
{
  AUTONAMES0("SkipNumbering")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::GetAddInId(TAutoString AddIn)
{
  AUTONAMES0("GetAddInId")
  AUTOARGS1(AddIn)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountAddIns()
{
  AUTONAMES0("CountAddIns")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::ClearAddIns(short RemoveFromList)
{
  AUTONAMES0("ClearAddIns")
  AUTOARGS1(RemoveFromList)
  AUTOCALL_METHOD_VOID
}

short WordBasic::AddInState(TAutoString AddIn, TAutoVal& Load)
{
  AUTONAMES0("AddInState")
  AUTOARGS2(AddIn, Load)
  AUTOCALL_METHOD_RET
}

short WordBasic::ToolsRevisionType()
{
  AUTONAMES0("ToolsRevisionType")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::ToolsRevisionAuthor()
{
  AUTONAMES0("ToolsRevisionAuthor")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

double WordBasic::ToolsRevisionDate()
{
  AUTONAMES0("ToolsRevisionDate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::ToolsRevisionDateStr()
{
  AUTONAMES0("ToolsRevisionDateStr")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::MailMergeViewData(TAutoVal& DisplayResults)
{
  AUTONAMES0("MailMergeViewData")
  AUTOARGS1(DisplayResults)
  AUTOCALL_METHOD_RET
}

void WordBasic::AddDropDownItem(TAutoString BookmarkName, TAutoString ItemText)
{
  AUTONAMES0("AddDropDownItem")
  AUTOARGS2(BookmarkName, ItemText)
  AUTOCALL_METHOD_VOID
}

void WordBasic::RemoveDropDownItem(TAutoString BookmarkName, TAutoString ItemText)
{
  AUTONAMES0("RemoveDropDownItem")
  AUTOARGS2(BookmarkName, ItemText)
  AUTOCALL_METHOD_VOID
}

short WordBasic::TableHeadings(TAutoVal& On)
{
  AUTONAMES0("TableHeadings")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::DefaultDir(short Type)
{
  AUTONAMES0("DefaultDir")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::FileNameInfo(TAutoString FileName, short InfoType)
{
  AUTONAMES0("FileNameInfo")
  AUTOARGS2(FileName, InfoType)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::MacroFileName(TAutoVal& MacroName)
{
  AUTONAMES0("MacroFileName")
  AUTOARGS1(MacroName)
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewHeader()
{
  AUTONAMES0("ViewHeader")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewFooter()
{
  AUTONAMES0("ViewFooter")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::PasteButtonImage(TAutoString Toolbar, short Tool, TAutoVal& Context)
{
  AUTONAMES0("PasteButtonImage")
  AUTOARGS3(Toolbar, Tool, Context)
  AUTOCALL_METHOD_VOID
}

void WordBasic::CopyButtonImage(TAutoString Toolbar, short Tool, TAutoVal& Context)
{
  AUTONAMES0("CopyButtonImage")
  AUTOARGS3(Toolbar, Tool, Context)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditButtonImage(TAutoString Toolbar, short Position, TAutoVal& Context)
{
  AUTONAMES0("EditButtonImage")
  AUTOARGS3(Toolbar, Position, Context)
  AUTOCALL_METHOD_VOID
}

short WordBasic::CountToolbars(TAutoVal& Context)
{
  AUTONAMES0("CountToolbars")
  AUTOARGS1(Context)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::ToolbarName(short Toolbar, TAutoVal& Context)
{
  AUTONAMES0("ToolbarName")
  AUTOARGS2(Toolbar, Context)
  AUTOCALL_METHOD_RET
}

void WordBasic::ChDefaultDir(TAutoString Path, short Type)
{
  AUTONAMES0("ChDefaultDir")
  AUTOARGS2(Path, Type)
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditUndo()
{
  AUTONAMES0("EditUndo")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditRedo()
{
  AUTONAMES0("EditRedo")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

short WordBasic::ViewMasterDocument()
{
  AUTONAMES0("ViewMasterDocument")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::ToolsAutoCorrectReplaceText(TAutoVal& On)
{
  AUTONAMES0("ToolsAutoCorrectReplaceText")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ToolsAutoCorrectInitialCaps(TAutoVal& On)
{
  AUTONAMES0("ToolsAutoCorrectInitialCaps")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ToolsAutoCorrectSentenceCaps(TAutoVal& On)
{
  AUTONAMES0("ToolsAutoCorrectSentenceCaps")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ToolsAutoCorrectDays(TAutoVal& On)
{
  AUTONAMES0("ToolsAutoCorrectDays")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetAutoCorrect(TAutoString AutoCorrectEntry)
{
  AUTONAMES0("GetAutoCorrect")
  AUTOARGS1(AutoCorrectEntry)
  AUTOCALL_METHOD_RET
}

short WordBasic::ViewFootnoteArea(TAutoVal& On)
{
  AUTONAMES0("ViewFootnoteArea")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::ConverterLookup(TAutoString FormatName)
{
  AUTONAMES0("ConverterLookup")
  AUTOARGS1(FormatName)
  AUTOCALL_METHOD_RET
}

short WordBasic::FileConfirmConversions(TAutoVal& On)
{
  AUTONAMES0("FileConfirmConversions")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetMergeField(TAutoString FieldName)
{
  AUTONAMES0("GetMergeField")
  AUTOARGS1(FieldName)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::Converter(short FormatNumber)
{
  AUTONAMES0("Converter")
  AUTOARGS1(FormatNumber)
  AUTOCALL_METHOD_RET
}

short WordBasic::MailMergeFoundRecord()
{
  AUTONAMES0("MailMergeFoundRecord")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::CountDocumentVars()
{
  AUTONAMES0("CountDocumentVars")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetDocumentVarName(short VariableNumber)
{
  AUTONAMES0("GetDocumentVarName")
  AUTOARGS1(VariableNumber)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::CleanString(TAutoString Source)
{
  AUTONAMES0("CleanString")
  AUTOARGS1(Source)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::PathFromWinPath(TAutoString Path)
{
  AUTONAMES0("PathFromWinPath")
  AUTOARGS1(Path)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::PathFromMacPath(TAutoString Path)
{
  AUTONAMES0("PathFromMacPath")
  AUTOARGS1(Path)
  AUTOCALL_METHOD_RET
}

short WordBasic::LockDocument(TAutoVal& Lock)
{
  AUTONAMES0("LockDocument")
  AUTOARGS1(Lock)
  AUTOCALL_METHOD_RET
}

void WordBasic::GoToNextSubdocument()
{
  AUTONAMES0("GoToNextSubdocument")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::GoToPreviousSubdocument()
{
  AUTONAMES0("GoToPreviousSubdocument")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::SelectionFileName()
{
  AUTONAMES0("SelectionFileName")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::SymbolFont(TAutoVal& TextToInsert)
{
  AUTONAMES0("SymbolFont")
  AUTOARGS1(TextToInsert)
  AUTOCALL_METHOD_VOID
}

void WordBasic::RemoveAllDropDownItems(TAutoString BookmarkName)
{
  AUTONAMES0("RemoveAllDropDownItems")
  AUTOARGS1(BookmarkName)
  AUTOCALL_METHOD_VOID
}

short WordBasic::FormShading(TAutoVal& On)
{
  AUTONAMES0("FormShading")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::GetFormResult(TAutoString BookmarkName)
{
  AUTONAMES0("GetFormResult")
  AUTOARGS1(BookmarkName)
  AUTOCALL_METHOD_RET
}

TAutoVal WordBasic::GetFormResultStr(TAutoString BookmarkName)
{
  AUTONAMES0("GetFormResultStr")
  AUTOARGS1(BookmarkName)
  AUTOCALL_METHOD_RET
}

short WordBasic::ToolbarState(TAutoString Toolbar)
{
  AUTONAMES0("ToolbarState")
  AUTOARGS1(Toolbar)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountToolbarButtons(TAutoString Toolbar, TAutoVal& Context)
{
  AUTONAMES0("CountToolbarButtons")
  AUTOARGS2(Toolbar, Context)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::ToolbarButtonMacro(TAutoString Toolbar, short Position, TAutoVal& Context)
{
  AUTONAMES0("ToolbarButtonMacro")
  AUTOARGS3(Toolbar, Position, Context)
  AUTOCALL_METHOD_RET
}

short WordBasic::AtEndOfDocument()
{
  AUTONAMES0("AtEndOfDocument")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::AtStartOfDocument()
{
  AUTONAMES0("AtStartOfDocument")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::FieldSeparator(TAutoVal& Separator)
{
  AUTONAMES0("FieldSeparator")
  AUTOARGS1(Separator)
  AUTOCALL_METHOD_RET
}

short WordBasic::CharLeft(TAutoVal& Count, TAutoVal& Select)
{
  AUTONAMES0("CharLeft")
  AUTOARGS2(Count, Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::CharRight(TAutoVal& Count, TAutoVal& Select)
{
  AUTONAMES0("CharRight")
  AUTOARGS2(Count, Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::WordLeft(TAutoVal& Count, TAutoVal& Select)
{
  AUTONAMES0("WordLeft")
  AUTOARGS2(Count, Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::WordRight(TAutoVal& Count, TAutoVal& Select)
{
  AUTONAMES0("WordRight")
  AUTOARGS2(Count, Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::SentLeft(TAutoVal& Count, TAutoVal& Select)
{
  AUTONAMES0("SentLeft")
  AUTOARGS2(Count, Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::SentRight(TAutoVal& Count, TAutoVal& Select)
{
  AUTONAMES0("SentRight")
  AUTOARGS2(Count, Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::ParaUp(TAutoVal& Count, TAutoVal& Select)
{
  AUTONAMES0("ParaUp")
  AUTOARGS2(Count, Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::ParaDown(TAutoVal& Count, TAutoVal& Select)
{
  AUTONAMES0("ParaDown")
  AUTOARGS2(Count, Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::LineUp(TAutoVal& Count, TAutoVal& Select)
{
  AUTONAMES0("LineUp")
  AUTOARGS2(Count, Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::LineDown(TAutoVal& Count, TAutoVal& Select)
{
  AUTONAMES0("LineDown")
  AUTOARGS2(Count, Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::PageUp(TAutoVal& Count, TAutoVal& Select)
{
  AUTONAMES0("PageUp")
  AUTOARGS2(Count, Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::PageDown(TAutoVal& Count, TAutoVal& Select)
{
  AUTONAMES0("PageDown")
  AUTOARGS2(Count, Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::StartOfLine(TAutoVal& Select)
{
  AUTONAMES0("StartOfLine")
  AUTOARGS1(Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::EndOfLine(TAutoVal& Select)
{
  AUTONAMES0("EndOfLine")
  AUTOARGS1(Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::StartOfWindow(TAutoVal& Select)
{
  AUTONAMES0("StartOfWindow")
  AUTOARGS1(Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::EndOfWindow(TAutoVal& Select)
{
  AUTONAMES0("EndOfWindow")
  AUTOARGS1(Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::StartOfDocument(TAutoVal& Select)
{
  AUTONAMES0("StartOfDocument")
  AUTOARGS1(Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::EndOfDocument(TAutoVal& Select)
{
  AUTONAMES0("EndOfDocument")
  AUTOARGS1(Select)
  AUTOCALL_METHOD_RET
}

short WordBasic::BorderOutside(TAutoVal& On)
{
  AUTONAMES0("BorderOutside")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::BorderNone(TAutoVal& Remove)
{
  AUTONAMES0("BorderNone")
  AUTOARGS1(Remove)
  AUTOCALL_METHOD_RET
}

short WordBasic::BorderTop(TAutoVal& On)
{
  AUTONAMES0("BorderTop")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::BorderLeft(TAutoVal& On)
{
  AUTONAMES0("BorderLeft")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::BorderBottom(TAutoVal& On)
{
  AUTONAMES0("BorderBottom")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::BorderRight(TAutoVal& On)
{
  AUTONAMES0("BorderRight")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::BorderInside(TAutoVal& On)
{
  AUTONAMES0("BorderInside")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

short WordBasic::DocumentProtection()
{
  AUTONAMES0("DocumentProtection")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::IsAutoCorrectException(TAutoVal& Tab, TAutoString Source)
{
  AUTONAMES0("IsAutoCorrectException")
  AUTOARGS2(Tab, Source)
  AUTOCALL_METHOD_RET
}

void WordBasic::MailCheckNames()
{
  AUTONAMES0("MailCheckNames")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailHideMessageHeader()
{
  AUTONAMES0("MailHideMessageHeader")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMessageDelete()
{
  AUTONAMES0("MailMessageDelete")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMessageForward()
{
  AUTONAMES0("MailMessageForward")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMessageMove()
{
  AUTONAMES0("MailMessageMove")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMessageNext()
{
  AUTONAMES0("MailMessageNext")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMessagePrevious()
{
  AUTONAMES0("MailMessagePrevious")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMessageProperties()
{
  AUTONAMES0("MailMessageProperties")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMessageReply()
{
  AUTONAMES0("MailMessageReply")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailMessageReplyAll()
{
  AUTONAMES0("MailMessageReplyAll")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::MailSelectNames()
{
  AUTONAMES0("MailSelectNames")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::AutomaticChange()
{
  AUTONAMES0("AutomaticChange")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

short WordBasic::CountAutoCorrectExceptions(short Tab)
{
  AUTONAMES0("CountAutoCorrectExceptions")
  AUTOARGS1(Tab)
  AUTOCALL_METHOD_RET
}

short WordBasic::CountDocumentProperties()
{
  AUTONAMES0("CountDocumentProperties")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

void WordBasic::DeleteDocumentProperty(TAutoString PropertyName)
{
  AUTONAMES0("DeleteDocumentProperty")
  AUTOARGS1(PropertyName)
  AUTOCALL_METHOD_VOID
}

short WordBasic::DocumentHasMisspellings()
{
  AUTONAMES0("DocumentHasMisspellings")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

short WordBasic::DocumentPropertyExists(TAutoString PropertyName)
{
  AUTONAMES0("DocumentPropertyExists")
  AUTOARGS1(PropertyName)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::DocumentPropertyName(short PropertyNumber)
{
  AUTONAMES0("DocumentPropertyName")
  AUTOARGS1(PropertyNumber)
  AUTOCALL_METHOD_RET
}

short WordBasic::DocumentPropertyType(TAutoString PropertyName)
{
  AUTONAMES0("DocumentPropertyType")
  AUTOARGS1(PropertyName)
  AUTOCALL_METHOD_RET
}

void WordBasic::EditFindHighlight()
{
  AUTONAMES0("EditFindHighlight")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditFindNotHighlight()
{
  AUTONAMES0("EditFindNotHighlight")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditReplaceHighlight()
{
  AUTONAMES0("EditReplaceHighlight")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::EditReplaceNotHighlight()
{
  AUTONAMES0("EditReplaceNotHighlight")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::FilePost(TAutoString FolderName)
{
  AUTONAMES0("FilePost")
  AUTOARGS1(FolderName)
  AUTOCALL_METHOD_VOID
}

void WordBasic::FileProperties()
{
  AUTONAMES0("FileProperties")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

TAutoString WordBasic::GetAutoCorrectException(short Tab, short EntryNumber)
{
  AUTONAMES0("GetAutoCorrectException")
  AUTOARGS2(Tab, EntryNumber)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetAddress(TAutoVal& Name, TAutoVal& Addressproperties, TAutoVal& UseAutoText, TAutoVal& DisplaySelectDialog, TAutoVal& SelectDialogModus, TAutoVal& CheckResolveNamesDialog, TAutoVal& MRUChoice, TAutoVal& UpdateMRU)
{
  AUTONAMES0("GetAddress")
  AUTOARGS8(Name, Addressproperties, UseAutoText, DisplaySelectDialog, SelectDialogModus, CheckResolveNamesDialog, MRUChoice, UpdateMRU)
  AUTOCALL_METHOD_RET
}

TAutoString WordBasic::GetDocumentPropertyStr(TAutoString Name, TAutoVal& CustomOrBuildIn)
{
  AUTONAMES0("GetDocumentPropertyStr")
  AUTOARGS2(Name, CustomOrBuildIn)
  AUTOCALL_METHOD_RET
}

long WordBasic::GetDocumentProperty(TAutoString Name, TAutoVal& CustomOrBuildIn)
{
  AUTONAMES0("GetDocumentProperty")
  AUTOARGS2(Name, CustomOrBuildIn)
  AUTOCALL_METHOD_RET
}

void WordBasic::InsertAddress()
{
  AUTONAMES0("InsertAddress")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

short WordBasic::IsCustomDocumentProperty(TAutoString Name)
{
  AUTONAMES0("IsCustomDocumentProperty")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

short WordBasic::IsDocumentPropertyReadOnly(TAutoString Name)
{
  AUTONAMES0("IsDocumentPropertyReadOnly")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

void WordBasic::MailMergeUseAddressBook(short AddressBookType)
{
  AUTONAMES0("MailMergeUseAddressBook")
  AUTOARGS1(AddressBookType)
  AUTOCALL_METHOD_VOID
}

void WordBasic::NextMisspelling()
{
  AUTONAMES0("NextMisspelling")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void WordBasic::SetDocumentProperty(TAutoString Name, short Type, TAutoVal& Value, short CustomOrBuiltIn)
{
  AUTONAMES0("SetDocumentProperty")
  AUTOARGS4(Name, Type, Value, CustomOrBuiltIn)
  AUTOCALL_METHOD_VOID
}

void WordBasic::SetDocumentPropertyLink(TAutoString Name, TAutoString Source)
{
  AUTONAMES0("SetDocumentPropertyLink")
  AUTOARGS2(Name, Source)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ShowMe()
{
  AUTONAMES0("ShowMe")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

TAutoVal WordBasic::SpellChecked(short Yes)
{
  AUTONAMES0("SpellChecked")
  AUTOARGS1(Yes)
  AUTOCALL_METHOD_RET
}

void WordBasic::TipWizard()
{
  AUTONAMES0("TipWizard")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

TAutoVal WordBasic::ToolsAutoCorrectCapsLockOff(TAutoVal& On)
{
  AUTONAMES0("ToolsAutoCorrectCapsLockOff")
  AUTOARGS1(On)
  AUTOCALL_METHOD_RET
}

void WordBasic::ToolsAutoCorrectExceptions(short Tab, TAutoString Name, short AutoAdd, TAutoVal& Add, TAutoVal& Delete)
{
  AUTONAMES0("ToolsAutoCorrectExceptions")
  AUTOARGS5(Tab, Name, AutoAdd, Add, Delete)
  AUTOCALL_METHOD_VOID
}

void WordBasic::ToolsSpellingRecheckDocument()
{
  AUTONAMES0("ToolsSpellingRecheckDocument")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

