#pragma once
#include "ITransformableCommand.h"
class NegativeCommand : public ITransformableCommand
{
public:
	// Inherited via ITransformableCommand
	void execute() const override;
	Command* clone() const override;
};

