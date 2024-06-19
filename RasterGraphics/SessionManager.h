#pragma once

#include "SessionContainer.h"
#include "CommandFactory.h"
#include "MyString.h"
#include "Session.h"

class Command;

class SessionManager
{
private:
	SessionContainer container;

	unsigned currentSession;
public:
	SessionManager() = default;
	SessionManager(Session& session);

	void createSession(Session* const session);

	void undo(); //undoes the last added transformation
	void collage(); //makes a collage between to image from the same format and adds to image collection
	void switchSession(unsigned sessionId); //switches to other session
	void addCommand(Command* command); //adds a command to current session

	void rotateLeft();
	void rotateRight();
	void grayscale();
	void monochrome();
	void negative();

	void closeSession();

	void saveSession(); //save current session
	void saveAsSession(); //saves only first loaded image
	
	friend std::ostream& operator<<(std::ostream&, const SessionManager&);

	unsigned getCurrSessionID() const; //gets current session id
	const Session& getCurrentSession() const;
};

