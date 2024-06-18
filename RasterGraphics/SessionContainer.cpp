#include "SessionContainer.h"
#include "Session.h"

void SessionContainer::resize(size_t newCap)
{
	capacity = newCap;
	Session** newData = new Session*[newCap];
	
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
}

void SessionContainer::copyFrom(const SessionContainer& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new Session*[capacity];

	for (size_t i = 0; i < capacity; i++)
	{
		data[i] = other.data[i];
	}
}

void SessionContainer::moveFrom(SessionContainer&& other)
{
	data = other.data;
	other.data = nullptr;

	capacity = other.capacity;
	size = other.size;

	other.size = other.capacity = 0;
}

void SessionContainer::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}
	delete[] data;
}

SessionContainer::SessionContainer()
{
	capacity = 2;
	size = 0;
	data = new Session*[capacity];
}

SessionContainer::SessionContainer(const SessionContainer& other)
{
	copyFrom(other);
}

SessionContainer& SessionContainer::operator=(const SessionContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

SessionContainer::SessionContainer(SessionContainer&& other) noexcept
{
	moveFrom(std::move(other));
}

SessionContainer& SessionContainer::operator=(SessionContainer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

SessionContainer::~SessionContainer() noexcept
{
	free();
}

void SessionContainer::addSession(const Session& other)
{
	Session* cloned = other.clone();
	addSession(cloned);
}

void SessionContainer::addSession(Session* session)
{
	if (size == capacity)
		resize(capacity * 2);

	data[size++] = session; //pray to be dynamic
	session = nullptr;
}

void SessionContainer::removeAt(size_t index)
{
	if (index >= size)
		throw std::out_of_range("Index out of range");

	delete data[index];
	for (size_t i = index; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}

	data[--size] = nullptr;  // Optional: nullify the last element
}

const Session* SessionContainer::operator[](size_t index) const
{
	if (index < 0 || index >= size)
		throw std::invalid_argument("Given index out of bounds!");

	return data[index];
}

Session* SessionContainer::operator[](size_t index)
{
	if (index < 0 || index >= size)
		throw std::invalid_argument("Given index out of bounds!");

	return data[index];
}

size_t SessionContainer::getSize() const
{
	return size;
}

size_t SessionContainer::getCapacity() const
{
	return capacity;
}
