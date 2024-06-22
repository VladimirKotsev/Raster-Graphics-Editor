#include "Engine.h"
#include "CommandFactory.h"
#include "ExceptionMessages.h"

void Engine::run()
{
	SessionManager sessionManager;
	std::cout << "> ";
	Vector<MyString> input = InputService::readSplitedInput(GlobalConstants::INPUT_SEPARATOR);
	
	while (input[0] != "exit")
	{
		try
		{
			MyString command = input[0];
			command.toLower();

			if (command == "add")
			{
				if (!sessionManager.checkIfSessionOpened())
					throw std::logic_error(ExceptionMessages::NO_OPENED_SESSION);

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
					throw std::invalid_argument(ExceptionMessages::NO_IMAGE_PATH);

				Session* session = new Session();
				sessionManager.createSession(session);
				std::cout << "Started session with ID: " << sessionManager.getCurrSessionID() << std::endl;
				for (size_t i = 1; i < input.getSize(); i++)
				{
					Command* createCommand = CommandFactory::createAddCommand(input[i]);
					sessionManager.addCommand(createCommand);
				}
			}
			else if (command == "close")
			{
				sessionManager.closeSession(); //check for switched session
			}
			else if (command == "save")
			{
				if (!sessionManager.checkIfSessionOpened())
					throw std::logic_error(ExceptionMessages::NO_OPENED_SESSION);

				sessionManager.saveSession();
				std::cout << "Changes applied succesfully!" << std::endl;
			}
			else if (command == "saveas")
			{
				if (!sessionManager.checkIfSessionOpened())
					throw std::logic_error(ExceptionMessages::NO_OPENED_SESSION);

				MyString filePath = input[1];
				filePath.toLower();
				sessionManager.saveAsSession(filePath);
			}
			else if (command == "grayscale")
			{
				if (!sessionManager.checkIfSessionOpened())
					throw std::logic_error(ExceptionMessages::NO_OPENED_SESSION);

				Command* transformableCommand = CommandFactory::createTransformableCommand(command, MyString());
				sessionManager.addCommand(transformableCommand);
			}
			else if (command == "rotate")
			{
				if (!sessionManager.checkIfSessionOpened())
					throw std::logic_error(ExceptionMessages::NO_OPENED_SESSION);

				MyString direction = input[1];
				direction.toLower();

				Command* transformableCommand = CommandFactory::createTransformableCommand(command, direction);
				sessionManager.addCommand(transformableCommand);
			}
			else if (command == "monochrome")
			{
				if (!sessionManager.checkIfSessionOpened())
					throw std::logic_error(ExceptionMessages::NO_OPENED_SESSION);

				Command* transformableCommand = CommandFactory::createTransformableCommand(command, MyString());
				sessionManager.addCommand(transformableCommand);
			}
			else if (command == "negative")
			{
				if (!sessionManager.checkIfSessionOpened())
					throw std::logic_error(ExceptionMessages::NO_OPENED_SESSION);

				Command* transformableCommand = CommandFactory::createTransformableCommand(command, MyString());
				sessionManager.addCommand(transformableCommand);
			}
			else if (command == "undo")
			{
				if (!sessionManager.checkIfSessionOpened())
					throw std::logic_error(ExceptionMessages::NO_OPENED_SESSION);

				sessionManager.undo();
			}
			else if (command == "session")
			{
				if (!sessionManager.checkIfSessionOpened())
					throw std::logic_error(ExceptionMessages::NO_OPENED_SESSION);

				MyString& additional = input[1];
				additional.toLower();
				if (additional == "info")
					std::cout << sessionManager;
			}
			else if (command == "switch")
			{
				if (input.getSize() == 1)
					throw std::invalid_argument(ExceptionMessages::NO_ID_GIVEN);

				unsigned id = input[1][0] - '0';
				sessionManager.switchSession(id);
			}
			else if (command == "collage")
			{
				if (!sessionManager.checkIfSessionOpened())
					throw std::logic_error(ExceptionMessages::NO_OPENED_SESSION);

				if (input.getSize() <= 1)
					throw std::invalid_argument(ExceptionMessages::UNSUFFICIENT_DATA_FOR_COLLAGE);

				MyString direction = input[1];
				direction.toLower();

				Command* command = CommandFactory::createCollageCommand(direction, input[2], input[3], input[4]);
				sessionManager.addCommand(command);
			}
			else
			{
				std::cout << "Invalid command!" << std::endl;
			}

			std::cout << "> ";
			input = InputService::readSplitedInput(GlobalConstants::INPUT_SEPARATOR);
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what();
		}
	}
}
