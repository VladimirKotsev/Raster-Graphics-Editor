#include "Image.h"
#pragma warning(disable: 4996)

void Image::copyFrom(const Image& other)
{
	filePath = new char[strlen(other.filePath) + 1];
	magicFormat = new char[strlen(other.filePath) + 1];

	strcpy(filePath, other.filePath);
	strcpy(magicFormat, other.magicFormat);

	width = other.width;
	height = other.height;
	colorMax = other.colorMax;
}

void Image::free()
{
	delete[] filePath;
	delete[] magicFormat;
}

void Image::setFilePath(const char* filePath)
{
	if (!filePath)
		throw std::invalid_argument("Null-pointer passed for filePath!");

	this->filePath = new char[strlen(filePath) + 1];
	strcpy(this->filePath, filePath);
}

void Image::setMagicFormat(const char* format)
{
	if (!format)
		throw std::invalid_argument("Null-pointer passed for image magic number!");
}

unsigned Image::getFormatNumber() const
{
	return (*(getMagicFormat() + 1) - '0'); //return the number from magic format
}

Image::Image(const char* filePath)
{
	setFilePath(filePath);
}

Image::Image(const Image& other)
{
	copyFrom(other);
}

Image& Image::operator=(const Image& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Image::~Image()
{
	free();
}

const uint16_t Image::getWidth() const
{
	return width;
}

const uint16_t Image::getHeight() const
{
	return height;
}

const uint16_t Image::getColorMax() const
{
	return colorMax;
}

const char* Image::getFilePath() const
{
	return filePath;
}

const char* Image::getMagicFormat() const
{
	return magicFormat;
}
