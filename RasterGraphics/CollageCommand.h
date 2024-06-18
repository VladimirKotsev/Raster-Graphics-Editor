#pragma once
#include "IAddableCommand.h"
class CollageCommand : public IAddableCommand
{
public:
	CollageCommand(SessionManager* const sesManager, MyString filePath);

	// Inherited via IAddableCommand
	void execute() const override;
	Command* clone() const override;
};

