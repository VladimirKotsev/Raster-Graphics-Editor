#pragma warning(disable: 4996)
#include "Image.h"
#include "ExceptionMessages.h"

void Image::copyFrom(const Image& other)
{
	filePath = new char[strlen(other.filePath) + 1];
	magicFormat = new char[strlen(other.filePath) + 1];

	strcpy(filePath, other.filePath);
	strcpy(magicFormat, other.magicFormat);

	width = other.width;
	height = other.height;
}

void Image::free()
{
	delete[] filePath;
	delete[] magicFormat;
}

void Image::setFilePath(const char* filePath)
{
	if (!filePath)
		throw std::invalid_argument(ExceptionMessages::NULLPOINTER_FILEPATH);

	this->filePath = new char[strlen(filePath) + 1];
	strcpy(this->filePath, filePath);
}

void Image::setMagicFormat(const char* format)
{
	if (!format)
		throw std::invalid_argument(ExceptionMessages::NULLPOINTER_MAGIC_NUMBER);

	magicFormat = new char[strlen(format) + 1];
	strcpy(magicFormat, format);
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

void Image::changeFilePath(const char* filePath)
{
	setFilePath(filePath);
}

const uint16_t Image::getWidth() const
{
	return width;
}

const uint16_t Image::getHeight() const
{
	return height;
}

const char* Image::getFilePath() const
{
	return filePath;
}

const char* Image::getMagicFormat() const
{
	return magicFormat;
}

bool Image::getIsGrayscale() const
{
	return isGrayscale;
}

bool Image::getIsMonochrome() const
{
	return isMonochrome;
}

std::ostream& operator<<(std::ostream& os, const Image& image)
{
	return os << image.getFilePath();
}
