#pragma once
#include "ITransformableCommand.h"
class NegativeCommand : public ITransformableCommand
{
public:
	NegativeCommand(SessionManager* const sesManagaer) : ITransformableCommand(sesManagaer) {}

	// Inherited via ITransformableCommand
	void execute() const override;
	Command* clone() const override;
};

