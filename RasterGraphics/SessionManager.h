#pragma once
#include "SessionContainer.h"
#include "MyString.h"

class SessionManager
{
private:
	SessionContainer container;

	unsigned currentSession; // public??
public:
	SessionManager(Session* const session);

	void createSession(Session* const session);

	void addImage(MyString filePath);
	void undo(); //undoes the last added transformation
	void collage(/*TO DO*/); //makes a collage between to image from the same format and adds to image collection
	void switchSession(unsigned sessionId); //switches to other session
	void addCommandToSession(const Command& command); //adds a command to current session

	void saveSession(); //save current session
	void saveAsSession(); //saves only first loaded image

	unsigned getCurrSession() const; //gets current session id
	//TO DO
	void printSessionInfo() const; //prints sesion info
};

