{ *********************************************************************** }
{                                                                         }
{ Delphi / Kylix Cross-Platform Runtime Library                           }
{                                                                         }
{ Copyright (c) 1995, 2001 Borland Software Corporation                   }
{                                                                         }
{ *********************************************************************** }

unit SysConst;                                   

interface

resourcestring
  SUnknown = '<unknown>';
  SInvalidInteger = '''%s'' is not a valid integer value';
  SInvalidFloat = '''%s'' is not a valid floating point value';
  SInvalidCurrency = '''%s'' is not a valid currency value';
  SInvalidDate = '''%s'' is not a valid date';
  SInvalidTime = '''%s'' is not a valid time';
  SInvalidDateTime = '''%s'' is not a valid date and time';
  SInvalidDateTimeFloat = '''%g'' is not a valid date and time';
  SInvalidTimeStamp = '''%d.%d'' is not a valid timestamp';
  SInvalidGUID = '''%s'' is not a valid GUID value';
  SInvalidBoolean = '''%s'' is not a valid boolean value';
  STimeEncodeError = 'Invalid argument to time encode';
  SDateEncodeError = 'Invalid argument to date encode';
  SOutOfMemory = 'Out of memory';
  SInOutError = 'I/O error %d';
  SFileNotFound = 'File not found';
  SInvalidFilename = 'Invalid filename';
  STooManyOpenFiles = 'Too many open files';
  SAccessDenied = 'File access denied';
  SEndOfFile = 'Read beyond end of file';
  SDiskFull = 'Disk full';
  SInvalidInput = 'Invalid numeric input';
  SDivByZero = 'Division by zero';
  SRangeError = 'Range check error';
  SIntOverflow = 'Integer overflow';
  SInvalidOp = 'Invalid floating point operation';
  SZeroDivide = 'Floating point division by zero';
  SOverflow = 'Floating point overflow';
  SUnderflow = 'Floating point underflow';
  SInvalidPointer = 'Invalid pointer operation';
  SInvalidCast = 'Invalid class typecast';
{$IFDEF MSWINDOWS}
  SAccessViolation = 'Access violation at address %p. %s of address %p';
{$ENDIF}
{$IFDEF LINUX}
  SAccessViolation = 'Access violation at address %p, accessing address %p';
{$ENDIF}
  SStackOverflow = 'Stack overflow';
  SControlC = 'Control-C hit';
  SQuit = 'Quit key hit';
  SPrivilege = 'Privileged instruction';
  SOperationAborted = 'Operation aborted';
  SException = 'Exception %s in module %s at %p.' + sLineBreak + '%s%s' + sLineBreak;
  SExceptTitle = 'Application Error';
{$IFDEF LINUX}
  SSigactionFailed = 'sigaction call failed';
{$ENDIF}
  SInvalidFormat = 'Format ''%s'' invalid or incompatible with argument';
  SArgumentMissing = 'No argument for format ''%s''';
  SDispatchError = 'Variant method calls not supported';
  SReadAccess = 'Read';
  SWriteAccess = 'Write';
  SResultTooLong = 'Format result longer than 4096 characters';
  SFormatTooLong = 'Format string too long';

  SVarArrayCreate = 'Error creating variant array';
  SVarArrayBounds = 'Variant array index out of bounds';
  SVarArrayLocked = 'Variant array is locked';

  SInvalidVarCast = 'Invalid variant type conversion';
  SInvalidVarOp = 'Invalid variant operation';
  SInvalidVarOpWithHResult = 'Invalid variant operation ($%.8x)';

  SVarNotArray = 'Variant is not an array' deprecated; // use SVarInvalid
  SVarTypeUnknown = 'Unknown custom variant type (%.4x)' deprecated; // not used anymore

  SVarTypeOutOfRange = 'Custom variant type (%.4x) is out of range';
  SVarTypeAlreadyUsed = 'Custom variant type (%.4x) already used by %s';
  SVarTypeNotUsable = 'Custom variant type (%.4x) is not usable';
  SVarTypeTooManyCustom = 'Too many custom variant types have been registered';

  SVarTypeCouldNotConvert = 'Could not convert variant of type (%s) into type (%s)';
  SVarTypeConvertOverflow = 'Overflow while converting variant of type (%s) into type (%s)';
  SVarOverflow = 'Variant overflow';
  SVarInvalid = 'Invalid argument';
  SVarBadType = 'Invalid variant type';
  SVarNotImplemented = 'Operation not supported';
  SVarOutOfMemory = 'Variant operation ran out memory';
  SVarUnexpected = 'Unexpected variant error';

  SVarDataClearRecursing = 'Recursion while doing a VarDataClear';
  SVarDataCopyRecursing = 'Recursion while doing a VarDataCopy';
  SVarDataCopyNoIndRecursing = 'Recursion while doing a VarDataCopyNoInd';
  SVarDataInitRecursing = 'Recursion while doing a VarDataInit';
  SVarDataCastToRecursing = 'Recursion while doing a VarDataCastTo';
  SVarIsEmpty = 'Variant is empty';
  sUnknownFromType = 'Cannot convert from the specified type';
  sUnknownToType = 'Cannot convert to the specified type';
  SExternalException = 'External exception %x';
  SAssertionFailed = 'Assertion failed';
  SIntfCastError = 'Interface not supported';
  SSafecallException = 'Exception in safecall method';
  SAssertError = '%s (%s, line %d)';
  SAbstractError = 'Abstract Error';
  SModuleAccessViolation = 'Access violation at address %p in module ''%s''. %s of address %p';
  SCannotReadPackageInfo = 'Cannot access package information for package ''%s''';
  sErrorLoadingPackage = 'Can''t load package %s.'+sLineBreak+'%s';
  SInvalidPackageFile = 'Invalid package file ''%s''';
  SInvalidPackageHandle = 'Invalid package handle';
  SDuplicatePackageUnit = 'Cannot load package ''%s.''  It contains unit ''%s,''' +
    'which is also contained in package ''%s''';
  SOSError = 'System Error.  Code: %d.'+sLineBreak+'%s';
  SUnkOSError = 'A call to an OS function failed';
{$IFDEF MSWINDOWS}
  SWin32Error = 'Win32 Error.  Code: %d.'#10'%s' deprecated; // use SOSError
  SUnkWin32Error = 'A Win32 API function failed' deprecated; // use SUnkOSError
{$ENDIF}
  SNL = 'Application is not licensed to use this feature';

  SConvIncompatibleTypes2 = 'Incompatible conversion types [%s, %s]';
  SConvIncompatibleTypes3 = 'Incompatible conversion types [%s, %s, %s]';
  SConvIncompatibleTypes4 = 'Incompatible conversion types [%s - %s, %s - %s]';
  SConvUnknownType = 'Unknown conversion type %s';
  SConvDuplicateType = 'Conversion type (%s) already registered';
  SConvUnknownFamily = 'Unknown conversion family %s';
  SConvDuplicateFamily = 'Conversion family (%s) already registered';
  SConvUnknownDescription = '[%.8x]';
  SConvIllegalType = 'Illegal type';
  SConvIllegalFamily = 'Illegal family';
  SConvFactorZero = '%s has a factor of zero';

  SShortMonthNameJan = 'Jan';
  SShortMonthNameFeb = 'Feb';
  SShortMonthNameMar = 'Mar';
  SShortMonthNameApr = 'Apr';
  SShortMonthNameMay = 'May';
  SShortMonthNameJun = 'Jun';
  SShortMonthNameJul = 'Jul';
  SShortMonthNameAug = 'Aug';
  SShortMonthNameSep = 'Sep';
  SShortMonthNameOct = 'Oct';
  SShortMonthNameNov = 'Nov';
  SShortMonthNameDec = 'Dec';

  SLongMonthNameJan = 'January';
  SLongMonthNameFeb = 'February';
  SLongMonthNameMar = 'March';
  SLongMonthNameApr = 'April';
  SLongMonthNameMay = 'May';
  SLongMonthNameJun = 'June';
  SLongMonthNameJul = 'July';
  SLongMonthNameAug = 'August';
  SLongMonthNameSep = 'September';
  SLongMonthNameOct = 'October';
  SLongMonthNameNov = 'November';
  SLongMonthNameDec = 'December';

  SShortDayNameSun = 'Sun';
  SShortDayNameMon = 'Mon';
  SShortDayNameTue = 'Tue';
  SShortDayNameWed = 'Wed';
  SShortDayNameThu = 'Thu';
  SShortDayNameFri = 'Fri';
  SShortDayNameSat = 'Sat';

  SLongDayNameSun = 'Sunday';
  SLongDayNameMon = 'Monday';
  SLongDayNameTue = 'Tuesday';
  SLongDayNameWed = 'Wednesday';
  SLongDayNameThu = 'Thursday';
  SLongDayNameFri = 'Friday';
  SLongDayNameSat = 'Saturday';

{$IFDEF LINUX}
  SEraEntries = '';
{$ENDIF}

  SCannotCreateDir = 'Unable to create directory';

implementation

end.
