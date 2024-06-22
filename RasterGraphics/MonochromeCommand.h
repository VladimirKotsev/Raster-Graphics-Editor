#pragma once
#include "ITransformableCommand.h"

class MonochromeCommand : public ITransformableCommand
{
public:
	Command* clone() const override;

	// Inherited via ITransformableCommand
	void execute(Session* session) const override;
	void execute(Image* image) const override;

	// Inherited via ITransformableCommand
	MyString& toString() const override;
};

