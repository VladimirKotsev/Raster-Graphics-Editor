#pragma once
#include "ITransformableCommand.h"
class NegativeCommand : public ITransformableCommand
{
public:

	Command* clone() const override;

	// Inherited via ITransformableCommand
	void execute(SessionManager* sessionManager) const override;
};

