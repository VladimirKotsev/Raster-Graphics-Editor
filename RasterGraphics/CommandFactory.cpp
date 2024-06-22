#include "CommandFactory.h"
#include "AddCommand.h"
#include "CollageCommand.h"
#include "GrayscaleCommand.h"
#include "MonochromeCommand.h"
#include "RotateCommand.h"
#include "NegativeCommand.h"
#include "ExceptionMessages.h"

Command* CommandFactory::createAddCommand(const MyString& filePath)
{
    return new AddCommand(filePath);
}

Command* CommandFactory::createCollageCommand(const MyString& direction, const MyString& firstFilePath, const MyString& secondFilePath, const MyString& outFilePath)
{
    if (direction == "horizontal")
        return new CollageCommand(CollageCommand::Direction::horizontal, firstFilePath, secondFilePath, outFilePath);
    else if (direction == "vertical")
        return new CollageCommand(CollageCommand::Direction::vertical, firstFilePath, secondFilePath, outFilePath);
    else
        throw std::invalid_argument(ExceptionMessages::INVALID_COLLAGE_DIRECTION);
}

Command* CommandFactory::createTransformableCommand(const MyString& type, const MyString& direction)
{
    if (type == "grayscale")
    {
        return new GrayscaleCommand();
    }
    else if (type == "rotate")
    {
        if (direction != "right" && direction != "left")
            throw std::invalid_argument(ExceptionMessages::UNSUFFICIENT_DATA_FOR_ROTATION);

        if (direction == "right")
            return new RotateCommand(RotateCommand::right);

        return new RotateCommand(RotateCommand::left);
    }
    else if (type == "monochrome")
    {
        return new MonochromeCommand();
    }
    else
    {
        return new NegativeCommand();
    }
}
