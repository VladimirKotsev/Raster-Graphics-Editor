#pragma once
#include "IExecutableCommand.h"
#include "MyString.h"

class LoadCommand : public IExecutableCommand
{
public:
	LoadCommand(SessionManager* const sesManager, MyString* images, size_t n);
};

