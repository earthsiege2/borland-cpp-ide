#include	<system.hpp>
#include	<sysutils.hpp>

namespace System
{
	TDateTime __fastcall TDateTime::CurrentDate()
	{
		return Sysutils::Date();
	}

	TDateTime __fastcall TDateTime::CurrentTime()
	{
		return Sysutils::Time();
	}

	TDateTime __fastcall TDateTime::CurrentDateTime()
	{
		return Sysutils::Now();
	}

	TDateTime __fastcall TDateTime::FileDateToDateTime(int fileDate)
	{
		return Sysutils::FileDateToDateTime(fileDate);
	}

//ctors
	__fastcall TDateTime::TDateTime(const AnsiString& src, TDateTimeFlag flag)
	{
		TDateTime tmp;
		if (flag == DateTime )
			tmp = Sysutils::StrToDateTime(src);
		else if (flag == Date)
			tmp = Sysutils::StrToDate(src);
		else // flag == Time
			tmp	= Sysutils::StrToTime(src);
		Val = tmp.Val;
	}

	__fastcall TDateTime::TDateTime(unsigned short year, unsigned short month,
									unsigned short day)
	{
		TDateTime tmp = Sysutils::EncodeDate(year, month, day);
		Val = tmp.Val;
	}

	__fastcall TDateTime::TDateTime(unsigned short hour, unsigned short min,
									unsigned short sec, unsigned short msec)
	{
		TDateTime tmp = Sysutils::EncodeTime(hour, min, sec, msec);
		Val = tmp.Val;
	}

//other TDateTime functions
	__fastcall TDateTime::operator AnsiString() const
	{
		if (Val < 1)
			return Sysutils::TimeToStr(*this);
		else if ((Val - int(Val)))
			return Sysutils::DateTimeToStr(*this);
		return Sysutils::DateToStr(*this);
	}

	AnsiString __fastcall TDateTime::FormatString(const AnsiString& format)
	{
		return Sysutils::FormatDateTime(format, *this);
	}

	AnsiString __fastcall TDateTime::DateString() const
	{
		return Sysutils::DateToStr(*this);
	}

	AnsiString __fastcall TDateTime::TimeString() const
	{
		return Sysutils::TimeToStr(*this);
	}

	AnsiString __fastcall TDateTime::DateTimeString() const
	{
		return Sysutils::DateTimeToStr(*this);
	}

	int __fastcall TDateTime::DayOfWeek() const
	{
		return Sysutils::DayOfWeek(*this);
	}

	int __fastcall TDateTime::FileDate() const
	{
		return Sysutils::DateTimeToFileDate(*this);
	}
	void __fastcall TDateTime::DecodeDate(unsigned short* year,
										  unsigned short* month, unsigned short* day) const
	{
		Sysutils::DecodeDate(*this, *year, *month, *day);
	}
	void __fastcall TDateTime::DecodeTime(unsigned short* hour,
										  unsigned short* min, unsigned short* sec, unsigned short* msec) const
	{
		Sysutils::DecodeTime(*this, *hour, *min, *sec, *msec);
	}
}
