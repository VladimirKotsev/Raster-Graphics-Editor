#pragma once
#include "ITransformableCommand.h"

class GrayscaleCommand : public ITransformableCommand
{
public:
	GrayscaleCommand(SessionManager* const sesManager);

	// Inherited via ITransformableCommand
	void execute() const override;
};

