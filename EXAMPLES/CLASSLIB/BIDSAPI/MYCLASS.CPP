// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
//  myclass.cpp
// ---------------------------------------------------------------------------

#include "..\myclass.h"

MyClass::MyClass()
{
    TRACE("Empty MyClass");
}

MyClass::MyClass(const string& s)
    : Str(s)
{
    TRACE("Con string '" << Str << "'");
}

MyClass::MyClass(const MyClass& mc)
    : Str(mc.Str)
{
    TRACE("Copy string '" << Str << "'");
}

MyClass::~MyClass()
{
    TRACE("Des string '" << Str << "'");
}

MyClass& MyClass::operator=(const MyClass& mc)
{
    Str = mc.Str;
    return *this;
}

int MyClass::operator==(const MyClass& mc) const
{
    return Str == mc.Str;
}

int MyClass::operator<(const MyClass& mc) const
{
    return Str < mc.Str;
}

unsigned MyClass::HashValue() const
{
    return Str.hash();
}

ostream& operator<<(ostream& os, const MyClass mc)
{
    return os << "'" << mc.Str << "' hash = " << mc.HashValue();
}

// 
// MyValue
// 
MyValue::MyValue()
{
    TRACE("Empty MyValue");
}

MyValue::MyValue(const string& s)
    : Str(s)
{
    TRACE("Con string '" << Str << "'");
}

MyValue::MyValue(const MyValue& mv)
    : Str(mv.Str)
{
    TRACE("Copy string '" << Str << "'");
}

MyValue::~MyValue()
{
    TRACE("Des string '" << Str << "'");
}

MyValue& MyValue::operator=(const MyValue& mv)
{
    Str = mv.Str;
    return *this;
}

int MyValue::operator==(const MyValue& mv) const
{
    return Str == mv.Str;
}

int MyValue::operator<(const MyValue& mv) const
{
    return Str < mv.Str;
}

unsigned MyValue::HashValue() const
{
    return Str.hash();
}


ostream& operator<<(ostream& os, const MyValue mv)
{
    return os << "'" << mv.Str << "' hash = " << mv.HashValue();
}

