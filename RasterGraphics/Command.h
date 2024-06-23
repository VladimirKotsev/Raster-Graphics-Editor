#pragma once
#include <iostream>

class MyString;
class Session;
class Image;

class Command
{
public:
	virtual ~Command() = default;

	virtual void execute(Session* session) const = 0;
	virtual void execute(Image* image) const = 0;
	virtual Command* clone() const = 0;

	virtual const char* toString() const = 0;
};

