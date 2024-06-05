#pragma once
#include <iostream>

#include "ImageContainer.h"

class Session
{
private:
	static unsigned initializationCount;

	unsigned ID;
	
	//image container
	ImageContainer images;
public:
	Session();
	Session* clone() const;
};

