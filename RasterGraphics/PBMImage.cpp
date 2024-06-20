#include "PBMImage.h"

PBMImage::~PBMImage()
{
	free();
}

Image* PBMImage::clone() const
{
	Image* toReturn = new (std::nothrow) PBMImage(*this);
	return toReturn;
}

void PBMImage::load()
{
	std::ifstream ifs(getFilePath(), std::ios::in);

	if (!ifs.is_open())
		throw std::logic_error("File cannot be found!");

	char buffer[2 + 1]; // CONSTANT SHOULD NOT BE HERE
	ifs.getline(buffer, 2);
	setMagicFormat(buffer);

	ifs.close();

	if (strcmp(getMagicFormat(), "P4") == 0) //BINARY
	{
		std::ifstream ifs(getFilePath(), std::ios::in | std::ios::binary);

		if (!ifs.is_open())
			throw std::logic_error("File cannot be found!");

		char buffer[2 + 1]; // CONSTANT SHOULD NOT BE HERE
		ifs.getline(buffer, 2);

		ifs >> width >> height;
		ifs.ignore();

		unsigned bits = getWidth() * getHeight();
		int dataSize = (width * height + 7) / 8;
		uint8_t currentBit = 0;

		data = new DynamicSet(bits);
		uint8_t* fileData = new uint8_t[dataSize];

		ifs.read((char*)(data), dataSize);
		ifs.close();

		for (int i = 0; i < dataSize; ++i)
		{
			int byteIndex = i / 8;
			int bitIndex = 7 - (i % 8);
			if (fileData[byteIndex] & (1 << bitIndex))
				data->add(i);
		}
	}
	else // ASCII
	{
		std::ifstream ifs(getFilePath(), std::ios::in);

		if (!ifs.is_open())
			throw std::logic_error("File cannot be found!");

		char buffer[2 + 1]; // CONSTANT SHOULD NOT BE HERE
		ifs.getline(buffer, 2);

		ifs >> width >> height;
		ifs.ignore();

		unsigned bits = getWidth() * getHeight();
		uint8_t currentBit = 0;

		data = new DynamicSet(bits);

		for (size_t i = 0; i < bits; i++)
		{
			ifs >> currentBit;
			if (currentBit == 1)
				data->add(i);
		}

		ifs.close();
	}
}

void PBMImage::save() const
{

}

void PBMImage::saveAs(const char* direction) const
{

}

void PBMImage::saveToASCII(const char* filePath) const
{
}

void PBMImage::saveToBinary(const char* filePath) const
{
}

void PBMImage::loadContentFromASCII()
{
}

void PBMImage::loadContentFromBinary()
{
}

void PBMImage::negative()
{
}

void PBMImage::grayscale()
{
}

void PBMImage::monochrome()
{
}

void PBMImage::rotateLeft()
{
}

void PBMImage::rotateRight()
{
}

bool PBMImage::isLoaded() const
{
	return (getWidth() != 0 && getHeight() != 0);
}

void PBMImage::free()
{
	//delete[] bits; //handles by class DynamicSet
}

void PBMImage::copyFrom(const PBMImage& other)
{
	data = new DynamicSet(other.getHeight() * other.getWidth());
	for (size_t i = 0; i < other.data->getCount(); i++)
	{
		data[i] = other.data[i];
	}
}

PBMImage::PBMImage(const char* filePath) : Image(filePath)
{
}

PBMImage::PBMImage(const PBMImage& other) : Image(other)
{
	copyFrom(other);
}

PBMImage& PBMImage::operator=(const PBMImage& other)
{
	if (this != &other)
	{
		Image::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}
