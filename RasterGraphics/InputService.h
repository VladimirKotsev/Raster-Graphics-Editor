#pragma once
#include "MyString.h"
#include "Vector.hpp"

class InputService
{
public:
	static Vector<MyString> readSplitedInput(char separator);
	static MyString& readInput();
};

