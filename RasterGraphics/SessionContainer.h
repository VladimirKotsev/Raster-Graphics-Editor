#pragma once
#include <iostream>

#include "Session.h"

class SessionContainer
{
private:
	Session** data;
	size_t size;
	size_t capacity;

	void resize(size_t newCap);
	void copyFrom(const SessionContainer& other);
	void moveFrom(SessionContainer&& other);
	void free();

public:
	SessionContainer();

	SessionContainer(const SessionContainer& other);
	SessionContainer& operator=(const SessionContainer& other);

	SessionContainer(SessionContainer&& other) noexcept;
	SessionContainer& operator=(SessionContainer&& other) noexcept;

	~SessionContainer() noexcept;

	void addSession(const Session& other);
	//void addSession(Session&& other);
	void addSession(Session* other);

	//Remove for close() Session???? !!!

	const Session* operator[](size_t index) const;
	Session* operator[](size_t index);
	size_t getSize() const;
	size_t getCapacity() const;
};


