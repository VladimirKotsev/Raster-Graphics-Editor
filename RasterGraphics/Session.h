#pragma once
#include <iostream>

class Session
{
private:
	static unsigned initializationCount;

	unsigned ID;
	
	//image container
public:

	Session();
	Session* clone() const;
};

