#pragma once
#include "IAddableCommand.h"

class CollageCommand : public IAddableCommand
{
private:
	MyString firstFilePath;
	MyString secondFilePath;
public:
	CollageCommand(const MyString& firstFilePath, const MyString& secondFilePath, const MyString& outFilePath);

	Command* clone() const override;


	// Inherited via IAddableCommand
	void execute(Session* session) const override;
};

