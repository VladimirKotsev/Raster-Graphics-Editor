#pragma once
#include "MyString.h"
//#include "SessionManager.h"

class MyString;
class SessionManager;
class Command;

class CommandFactory
{
public:
	static Command* createAddCommand(const MyString& filePath);
	static Command* createCollageCommand(const MyString& direction, const MyString& firstFilePath, const MyString& secondFilePath, const MyString& outFilePath);
	static Command* createTransformableCommand(const MyString& type, const MyString& direction);
};