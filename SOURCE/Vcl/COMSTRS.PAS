
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1996,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit ComStrs;

interface

resourcestring
  sTabFailClear = 'Failed to clear tab control';
  sTabFailDelete = 'Failed to delete tab at index %d';
  sTabFailRetrieve = 'Failed to retrieve tab at index %d';
  sTabFailGetObject = 'Failed to get object at index %d';
  sTabFailSet = 'Failed to set tab "%s" at index %d';
  sTabFailSetObject = 'Failed to set object at index %d';
  sTabMustBeMultiLine = 'MultiLine must be True when TabPosition is tpLeft or tpRight';

  sInvalidLevel = 'Invalid item level assignment';
  sInvalidLevelEx = 'Invalid level (%d) for item "%s"';
  sInvalidIndex = 'Invalid index';
  sInsertError = 'Unable to insert an item';

  sInvalidOwner = 'Invalid owner';
  sUnableToCreateColumn = 'Unable to create new column';
  sUnableToCreateItem = 'Unable to create new item';

  sRichEditInsertError = 'RichEdit line insertion error';
  sRichEditLoadFail = 'Failed to Load Stream';
  sRichEditSaveFail = 'Failed to Save Stream';

  sTooManyPanels = 'StatusBar cannot have more than 64 panels';

  sHKError = 'Error assigning Hot-Key to %s. %s';
  sHKInvalid = 'Hot-Key is invalid';
  sHKInvalidWindow = 'Window is invalid or a child window';
  sHKAssigned = 'Hot-Key is assigned to another window';

  sUDAssociated = '%s is already associated with %s';

  sPageIndexError = '%d is an invalid PageIndex value.  PageIndex must be ' +
    'between 0 and %d';

  sInvalidComCtl32 = 'This control requires version 4.70 or greater of COMCTL32.DLL';

  sDateTimeMax = 'Date exceeds maximum of %s';
  sDateTimeMin = 'Date is less than minimum of %s';
  sNeedAllowNone = 'You must be in ShowCheckbox mode to set to this date';
  sFailSetCalDateTime = 'Failed to set calendar date or time';
  sFailSetCalMaxSelRange = 'Failed to set maximum selection range';
  sFailSetCalMinMaxRange = 'Failed to set calendar min/max range';
  sCalRangeNeedsMultiSelect = 'Date range can only be used in multiselect mode';
  sFailsetCalSelRange = 'Failed to set calendar selected range';

implementation

end.
