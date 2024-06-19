#pragma once
#include "ITransformableCommand.h"

class MonochromeCommand : public ITransformableCommand
{
public:
	// Inherited via ITransformableCommand
	void execute() const override;
	Command* clone() const override;
};

