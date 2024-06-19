#include "Engine.h"
#include "CommandFactory.h"

void Engine::run()
{
	SessionManager sessionManager;
	Vector<MyString> input = InputService::readSplitedInput(' '); //const seperator
	
	while (input[0] != "exit")
	{
		MyString command = input[0];
		command.toLower();
		if (command == "add")
		{
			//Create add command from factory and give it to session
		}
		else if (command == "help")
		{
			//outputService prints info
		}
		else if (command == "load")
		{
			if (input.getSize() == 1)
				throw std::invalid_argument("No image file path given to load a session");
			
			Session session;
			sessionManager.createSession(&session);
			for (size_t i = 1; i < input.getSize(); i++)
			{
				//create commands and add to session
			}
		}
		else if (command == "close")
		{
			sessionManager.closeSession();
		}
		else if (command == "save")
		{
			sessionManager.saveSession();
		}
		else if (command == "saveas")
		{
			sessionManager.saveAsSession();
		}
		else if (command == "grayscale")
		{
			//Create grayscale command and add to session
		}
		else if (command == "rotate")
		{
			//Create rotate command with give rotation and add to session
		}
		else if (command == "monochrome")
		{
			//creates monochrome command and adds to session
		}
		else if (command == "negative")
		{
			//creates negative command and adds to session
		}
		else if (command == "undo")
		{
			sessionManager.undo();
		}
		else if (command == "session")
		{
			MyString& additional = input[1];
			additional.toLower();
			if (additional == "info")
			{
				std::cout << sessionManager;
			}
		}
		else if (command == "switch")
		{
			if (input.getSize() == 1)
				throw std::invalid_argument("Session ID needed!");

			unsigned id = input[1][0] - '0';
			sessionManager.switchSession(id);
		}
		else if (command == "collage")
		{
			//creates a colage
		}
		else
		{
			std::cout << "Invalid command!" << std::endl;
		}


		input = InputService::readSplitedInput(' '); // separator should be constant
	}
}
