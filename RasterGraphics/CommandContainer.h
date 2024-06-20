#pragma once
#include "Command.h"

class Command;

class CommandContainer
{
private:
	Command** data;

	size_t capacity;
	size_t size;

	void free();
	void copyFrom(const CommandContainer& other);
	void moveFrom(CommandContainer&& other);
	void resize(unsigned newCap);
public:
	CommandContainer();

	CommandContainer(const CommandContainer& other);
	CommandContainer& operator=(const CommandContainer& other);

	CommandContainer(CommandContainer&& other) noexcept;
	CommandContainer& operator=(CommandContainer&& other) noexcept;

	~CommandContainer();

	void addCommand(Command* command);
	void removeAt(size_t index);

	const Command* operator[](size_t index) const;
	Command* operator[](size_t index);

	size_t getSize() const;
	size_t getCapacity() const;

};

