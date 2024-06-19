#pragma once
#include "ITransformableCommand.h"

class SessionManager;

class GrayscaleCommand : public ITransformableCommand
{
public:

	// Inherited via ITransformableCommand
	Command* clone() const override;


	// Inherited via ITransformableCommand
	void execute(SessionManager* sessionManager) const override;

};

