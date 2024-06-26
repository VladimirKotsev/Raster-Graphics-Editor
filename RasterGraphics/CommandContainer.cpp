#include "CommandContainer.h"
#include <iostream>
#include "ExceptionMessages.h"

void CommandContainer::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}

	delete[] data;
}

void CommandContainer::copyFrom(const CommandContainer& other)
{
	data = new Command*[other.capacity];
	capacity = other.capacity;
	size = other.size;

	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

void CommandContainer::moveFrom(CommandContainer&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;
}

void CommandContainer::resize(unsigned newCap)
{
	Command** newData = new Command*[newCap];
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
}

CommandContainer::CommandContainer()
{
	capacity = 8;
	size = 0;
	data = new Command*[capacity];
}

CommandContainer::CommandContainer(const CommandContainer& other)
{
	copyFrom(other);
}

CommandContainer& CommandContainer::operator=(const CommandContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

CommandContainer::CommandContainer(CommandContainer&& other) noexcept
{
	moveFrom(std::move(other));
}

CommandContainer& CommandContainer::operator=(CommandContainer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

CommandContainer::~CommandContainer()
{
	free();
}

void CommandContainer::addCommand(Command* command)
{
	if (size == capacity)
		resize(capacity * 2);

	data[size++] = command;
	command = nullptr;
}

void CommandContainer::removeAt(size_t index)
{
	if (index >= size)
		throw std::out_of_range(ExceptionMessages::INDEX_OUT_OF_RANGE);

	delete data[index];
	for (size_t i = index; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}

	data[--size] = nullptr;
}

void CommandContainer::empty()
{
	for (size_t i = 0; i < size; ++i)
	{
		delete data[i];
	}

	size = 0; // Reset the size to zero
	capacity = 8;
	delete[] data; // Deallocate the data array
	data = new Command* [capacity];
}

const Command* CommandContainer::operator[](size_t index) const
{
	return data[index];
}

Command* CommandContainer::operator[](size_t index)
{
	return data[index];
}

size_t CommandContainer::getSize() const
{
	return size;
}

size_t CommandContainer::getCapacity() const
{
	return capacity;
}
