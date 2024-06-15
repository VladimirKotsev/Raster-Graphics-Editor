#pragma once
#include "IExecutableCommand.h"
#include "MyString.h"

class LoadCommand : public IExecutableCommand
{
private:
	MyString* images;
	size_t n;
public:

	LoadCommand(SessionManager* const sesManager, MyString* images, size_t n);

	// Inherited via IExecutableCommand
	void execute() const override;

};

