unit ReConst;

interface

uses Windows;

const
  ENGLISH = (SUBLANG_ENGLISH_US shl 10) or LANG_ENGLISH;
  GERMAN  = (SUBLANG_GERMAN shl 10) or LANG_GERMAN;
  FRENCH  = (SUBLANG_FRENCH shl 10) or LANG_FRENCH;

resourcestring
  SUntitled = 'Untitled';
  SPercent_s = '%s - %s';
  SSaveChanges = 'Save Changes?';
  SConfirmation = 'Confirmation';
  SNumberbetween = 'The number must be between 1 and 1638.';
  SLcid = '1033'; { US = 1033; DE = 1031; FR = 1036 }

implementation

end.