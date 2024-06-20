#pragma once

class Session;

class Command
{
public:
	virtual ~Command() = default;

	virtual void execute(Session* session) const = 0;
	virtual Command* clone() const = 0;
};

