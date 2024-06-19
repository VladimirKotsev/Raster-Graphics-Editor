#pragma once
#include "ITransformableCommand.h"

class GrayscaleCommand : public ITransformableCommand
{
public:

	// Inherited via ITransformableCommand
	void execute() const override;

	// Inherited via ITransformableCommand
	Command* clone() const override;
};

