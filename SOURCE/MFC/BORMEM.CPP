#include "stdafx.h"

// This function is for the "placement new operator" used with Borland C++

void *operator new(size_t size, void *ptr)
{
	return ptr;
}
