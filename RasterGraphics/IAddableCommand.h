#pragma once

#include "Command.h"
#include "MyString.h"

class IAddableCommand : public Command
{
protected:
	MyString imagePath;
public:
	IAddableCommand(SessionManager* const sesManager, MyString filePath);

	const MyString& getImagePath() const;

	// Inherited via Command
	void execute() const override;
	Command* clone() const = 0;
};