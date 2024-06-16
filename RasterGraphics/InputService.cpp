#include "InputService.h"
const size_t BUFFER_SIZE = 1024;

Vector<MyString> InputService::readSplitedInput(char separator)
{
	MyString str = readInput();
	Vector<MyString> result;

	size_t start = 0;
	size_t end = 0;

	while (end < str.getSize())
	{
		while (end < str.getSize() && str[end] != separator)
		{
			++end;
		}

		if (end > start)
		{
			result.pushBack(str.substr(start, end - start));
		}

		start = ++end;
	}

	return result;
}

MyString& InputService::readInput()
{
	char buffer[1024]; //should be constant
	std::cin.getline(buffer, 1024);
	MyString toReturn(buffer);

	return toReturn;
}
