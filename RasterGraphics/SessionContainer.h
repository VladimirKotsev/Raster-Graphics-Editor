#pragma once
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

	SessionContainer(SessionContainer&& other);
	SessionContainer& operator=(SessionContainer&& other);

	~SessionContainer();

	void addSession(const Session& other);
	void addSession(Session&& other);
};


