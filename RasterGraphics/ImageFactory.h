#pragma once
#include "Image.h"
#include "MyString.h"

class ImageFactory
{
private:
	static void getImageFormat(char* format, MyString& filePath);
public:
	static Image* createImage(MyString& filePath);
};

