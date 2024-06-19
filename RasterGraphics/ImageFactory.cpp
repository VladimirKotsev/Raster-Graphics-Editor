#pragma warning (disable:4996)
#include "ImageFactory.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"

void ImageFactory::getImageFormat(char* format, MyString& filePath)
{
	const char* data = filePath.c_str();
	size_t size = filePath.getSize();

	// Find the position of the last dot
	int lastDotPos = -1;
	for (size_t i = 0; i < size; ++i)
	{
		if (data[i] == '.')
		{
			lastDotPos = i;
		}
	}

	if (lastDotPos != -1)
	{
		size_t formatLength = size - lastDotPos - 1;
		std::strncpy(format, data + lastDotPos + 1, formatLength);
		format[formatLength] = '\0'; // Null-terminate the format string
	}
	else
	{
		format[0] = '\0'; // No dot found, set format to an empty string
	}
}

Image* ImageFactory::createImage(MyString& filePath)
{
	char buffer[1024]; //should be a constant
	getImageFormat(buffer, filePath);
	MyString format(buffer);

	format.toLower();
	Image* image = nullptr;

	if (format == "pbm")
	{
		image = new PBMImage(filePath.c_str());
	}
	else if (format == "pgm")
	{
		image = new PGMImage(filePath.c_str());
	}
	else if (format == "ppm")
	{
		image = new PPMImage(filePath.c_str());
	}

	return image;
}
