/*  COMOBJEC.H

    Template helper class for easy usage of COM interfaces.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1999, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $ */


#ifndef COMOBJECT_H
#define COMOBJECT_H

#ifndef __cplusplus
#error Must use C++ for the TComObject class.
#endif

#include <typeinfo>
#include <windows.h>
#include <objbase.h>


template <class T>
class __stdcall TComObject : public T {
protected:
	TComObject()
		: refc(1)
	{ }

	template <class T1>
	TComObject(T1 arg)
		: T(arg), refc(1)
	{ }

	template <class T1, class T2>
	TComObject(T1 arg1, T2 arg2)
		: T(arg1, arg2), refc(1)
	{ }

	template <class T1, class T2, class T3>
	TComObject(T1 arg1, T2 arg2, T3 arg3)
		: T(arg1, arg2, arg3), refc(1)
	{ }

	template <class T1, class T2, class T3, class T4>
	TComObject(T1 arg1, T2 arg2, T3 arg3, T4 arg4)
		: T(arg1, arg2, arg3, arg4), refc(1)
	{ }

	template <class T1, class T2, class T3, class T4, class T5>
	TComObject(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5)
		: T(arg1, arg2, arg3, arg4, arg5), refc(1)
	{ }

	template <class T1, class T2, class T3, class T4, class T5, class T6>
	TComObject(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6)
		: T(arg1, arg2, arg3, arg4, arg5, arg6), refc(1)
	{ }

public:
	// constructor methods
	static TComObject *Create()
	{
		return new TComObject;
	}

	template <class T1>
	static TComObject *Create(T1 arg)
	{
		return new TComObject(arg);
	}

	template <class T1, class T2>
	static TComObject *Create(T1 arg1, T2 arg2)
	{
		return new TComObject(arg1, arg2);
	}

	template <class T1, class T2, class T3>
	static TComObject *Create(T1 arg1, T2 arg2, T3 arg3)
	{
		return new TComObject(arg1, arg2, arg3);
	}

	template <class T1, class T2, class T3, class T4>
	static TComObject *Create(T1 arg1, T2 arg2, T3 arg3, T4 arg4)
	{
		return new TComObject(arg1, arg2, arg3, arg4);
	}

	template <class T1, class T2, class T3, class T4, class T5>
	static TComObject *Create(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5)
	{
		return new TComObject(arg1, arg2, arg3, arg4, arg5);
	}

	template <class T1, class T2, class T3, class T4, class T5, class T6>
	static TComObject *Create(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6)
	{
		return new TComObject(arg1, arg2, arg3, arg4, arg5, arg6);
	}


	// IUnknown "implementation"
	HRESULT QueryInterface(REFIID rid, void **p)
	{
		if (rid == IID_IUnknown)
			*p = this;
		else if (IUnknown *q = FindInterface(typeid(*this), rid))
			*p = q;
		else {
			*p = NULL;
			return E_NOINTERFACE;
		}

		AddRef();
		return S_OK;
	}

	ULONG AddRef()
	{
		return InterlockedIncrement(&refc);
	}

	ULONG Release()
	{
		ULONG rc = InterlockedDecrement(&refc);
		if (!rc)
			delete this;
		return rc;
	}

protected:
#pragma option push -w-inl
    IUnknown *FindInterface(std::type_info const &tp, REFIID rid)
	{
		IUnknown *rc = NULL;
		if ((tp._guid() != NULL) && (*((GUID*)tp._guid()) == rid))
			rc = (IUnknown *)tp._rtti_cast(this);
		else
		{
			std::type_info::_base_info b;
			for (std::type_info const *p = tp._first_base(b); p; p = tp._next_base(b))
			{
				rc = FindInterface(*p, rid);
				if (rc)
					break;
			}
		}
		return rc;
	}
#pragma option pop // -w-inl

private:
	LONG refc;

	// no copies
	TComObject(TComObject const &);
	TComObject const &operator=(TComObject const &);
};

#endif // ! COMOBJECT_H
