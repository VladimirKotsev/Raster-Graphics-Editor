#pragma once
#include "SessionContainer.h"

class SessionManager
{
private:
	SessionContainer container;

	unsigned currentSession; // public??
public:
	SessionManager(const char* fileName);

	void createSession(MyString* fileNames, size_t n);

	void undo(); //undoes the last added transformation
	void collage(/*TO DO*/); //makes a collage between to image from the same format and adds to image collection
	void switchSession(unsigned sessionId); //switches to other session
	void addCommandToSession(const Command& command); //adds a command to current session

	void saveSession(); //save current session
	void saveAsSession(); //saves only first loaded image

	unsigned getCurrSession() const; //gets current session id
	void printSessionInfo() const; //prints sesion info
};

