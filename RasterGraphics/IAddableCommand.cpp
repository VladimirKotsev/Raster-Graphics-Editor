#include "IAddableCommand.h"

IAddableCommand::IAddableCommand(const MyString& filePath) :filePath(filePath)
{
}

void IAddableCommand::execute(SessionManager* sessionManager) const
{
}
