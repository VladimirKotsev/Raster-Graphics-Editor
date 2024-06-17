#include "OutputService.h"
#include "ImageContainer.h"
#include "ITransformableCommand.h"

void OutputService::printSessionInfo(const Session& session)
{
	std::cout << "Session ID: " << session.getID() << std::endl;
	std::cout << "Images in session: ";
	
	const ImageContainer& images = session.getImages();
	size_t imageCount = images.getSize();
	for (size_t i = 0; i < imageCount; i++)
	{
		std::cout << images[i]->getFilePath();

		if (i + 1 < imageCount)
			std::cout << ", ";
	}

	std::cout << std::endl;

	const Vector<Command>& commands = session.getCommands();
	size_t commandCount = commands.getSize();

	std::cout << "Transfomation in current session: ";
	for (size_t i = 0; i < commandCount; i++)
	{
		const ITransformableCommand* command = 
			dynamic_cast<const ITransformableCommand*>(&commands[i]);
		if (command != nullptr)
		{
			const IRotate
		}
	}
}
