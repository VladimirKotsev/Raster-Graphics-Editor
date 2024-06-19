#include "CommandFactory.h"
//#include "Command.h"
#include "AddCommand.h"

Command* CommandFactory::createAddCommand(const MyString& filePath)
{
    return new AddCommand(filePath);
}

Command* CommandFactory::createCollageCommand(const MyString& direction, const MyString& firstFilePath, const MyString& secondFilePath, const MyString& outFilePath)
{
    

    return nullptr;
}

Command* CommandFactory::createTransformableCommand(const MyString& type)
{
    if (type == "grayscale")
    {

    }
    else if (type == "rotate")
    {

    }
    else if (type == "monochrome")
    {

    }
    else if (type == "negative")
    {

    }

    return nullptr;
}
