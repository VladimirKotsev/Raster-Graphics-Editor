#pragma once
#include "IAddableCommand.h"

class CollageCommand : public IAddableCommand
{
public:
	enum Direction
	{
		horizontal,
		vertical
	};

private:
	Direction direction;
	MyString firstFilePath;
	MyString secondFilePath;
	
public:
	CollageCommand(Direction direction, const MyString& firstFilePath, const MyString& secondFilePath, const MyString& outFilePath);

	Command* clone() const override;

	// Inherited via IAddableCommand
	void execute(Session* session) const override;

	// Inherited via IAddableCommand
	MyString& toString() const override;
};

