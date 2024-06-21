#include "Engine.h"
#include "CommandFactory.h"

void Engine::run()
{
	SessionManager sessionManager;
	std::cout << " >";
	Vector<MyString> input = InputService::readSplitedInput(' '); //const seperator
	
	while (input[0] != "exit")
	{
		try
		{
			MyString command = input[0];
			command.toLower();

			if (command == "add")
			{
				Command* createCommand = CommandFactory::createAddCommand(input[1]);
				sessionManager.addCommand(createCommand);
			}
			else if (command == "help")
			{
				OutputService::printHelp();
			}
			else if (command == "load")
			{
				if (input.getSize() == 1)
					throw std::invalid_argument("No image file path given to load a session");

				Session* session = new Session();
				sessionManager.createSession(session);
				for (size_t i = 1; i < input.getSize(); i++)
				{
					Command* createCommand = CommandFactory::createAddCommand(input[i]);
					sessionManager.addCommand(createCommand);
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
				Command* transformableCommand = CommandFactory::createTransformableCommand(command, MyString());
				sessionManager.addCommand(transformableCommand);
			}
			else if (command == "rotate")
			{
				MyString direction = input[1];
				direction.toLower();

				Command* transformableCommand = CommandFactory::createTransformableCommand(command, direction);
				sessionManager.addCommand(transformableCommand);
			}
			else if (command == "monochrome")
			{
				Command* transformableCommand = CommandFactory::createTransformableCommand(command, MyString());
				sessionManager.addCommand(transformableCommand);
			}
			else if (command == "negative")
			{
				Command* transformableCommand = CommandFactory::createTransformableCommand(command, MyString());
				sessionManager.addCommand(transformableCommand);
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
					std::cout << sessionManager;
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
				if (input.getSize() <= 1)
					throw std::invalid_argument("Not enough data give to make a collage!");

				MyString direction = input[1];
				direction.toLower();

				Command* command = CommandFactory::createCollageCommand(direction, input[2], input[3], input[4]);
				sessionManager.addCommand(command);
			}
			else
			{
				std::cout << "Invalid command!" << std::endl;
			}

			std::cout << " >";
			input = InputService::readSplitedInput(' '); // separator should be constant
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what();
		}
	}
}
