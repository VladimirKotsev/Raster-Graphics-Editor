#include "CommandFactory.h"
#include "AddCommand.h"
#include "GrayscaleCommand.h"
#include "MonochromeCommand.h"
#include "RotateCommand.h"
#include "NegativeCommand.h"

Command* CommandFactory::createAddCommand(const MyString& filePath)
{
    return new AddCommand(filePath);
}

Command* CommandFactory::createCollageCommand(const MyString& direction, const MyString& firstFilePath, const MyString& secondFilePath, const MyString& outFilePath)
{
    
    return new AddCommand(outFilePath);
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
            throw std::invalid_argument("Rotation not specified!");

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
