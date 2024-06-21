#pragma once
#include "ITransformableCommand.h"

class GrayscaleCommand : public ITransformableCommand
{
public:
	// Inherited via ITransformableCommand
	Command* clone() const override;

	// Inherited via ITransformableCommand
	void execute(Session* session) const override;
	void execute(Image* image) const override;

};

