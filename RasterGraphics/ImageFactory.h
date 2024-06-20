#pragma once
#include "Image.h"
#include "MyString.h"

class ImageFactory
{
private:
	static void getImageFormat(char* format, const MyString& filePath);
public:
	static Image* createImage(const MyString& filePath);
};

