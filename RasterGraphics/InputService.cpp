#include "InputService.h"
#include "GlobalConstants.h"

Vector<MyString> InputService::readSplitedInput(char separator)
{
	const MyString str = readInput();
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

MyString InputService::readInput()
{
	char buffer[GlobalConstants::BUFFER_SIZE]; //should be constant
	std::cin.getline(buffer, GlobalConstants::BUFFER_SIZE);
	MyString toReturn(buffer);

	return toReturn;
}
