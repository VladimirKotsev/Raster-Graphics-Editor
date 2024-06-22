#include "PGMImage.h"

void PGMImage::free()
{
	data.clear();
}

void PGMImage::copyFrom(const PGMImage& other)
{
	for (size_t i = 0; i < other.data.getSize(); i++)
	{
		data[i] = other.data[i]; // copy
	}
}

void PGMImage::saveToASCII(const char* filePath) const
{
	std::ofstream ofs(getFilePath(), std::ios::out);
	if (!ofs.is_open())
		throw std::logic_error("File cannot be found!");

	ofs << getMagicFormat() << '\n';
	ofs << getWidth() << ' ' << getHeight() << '\n';
	ofs << getColorMax() << '\n';

	for (size_t i = 0; i < data.getSize(); i++)
	{
		ofs << data[i] << ' ';
	}

	ofs.close(); //calls flush()
}

void PGMImage::saveToBinary(const char* filePath) const
{

}

void PGMImage::loadContentFromASCII()
{
	std::ifstream ifs(getFilePath(), std::ios::in);
	char buffer[GlobalConstants::BUFFER_SIZE]; //should be constant somewhere

	ifs.getline(buffer, GlobalConstants::BUFFER_SIZE);
	ifs.getline(buffer, GlobalConstants::BUFFER_SIZE);
	ifs >> maxColor;
	ifs.ignore();

	while (true)
	{
		if (ifs.eof())
			break;

		uint16_t num;
		ifs >> num;
		data.pushBack(num);
	}

	ifs.close();
}

void PGMImage::loadContentFromBinary()
{

}

PGMImage::PGMImage(const char* filePath) : Image(filePath)
{
}

PGMImage::PGMImage(const PGMImage& other) : Image(other)
{
	copyFrom(other);
}

PGMImage& PGMImage::operator=(const PGMImage& other)
{
	if (this != &other)
	{
		Image::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

PGMImage::~PGMImage()
{
	free();
}

Image* PGMImage::clone() const
{
	Image* cloned = new (std::nothrow) PGMImage(*this);
	return cloned;
}

const uint16_t PGMImage::getColorMax() const
{
	return maxColor;
}

void PGMImage::load()
{
	std::ifstream ifs(getFilePath(), std::ios::in);

	char magicFormat[GlobalConstants::BUFFER_SIZE]; // should be constant
	ifs >> magicFormat;
	setMagicFormat(magicFormat);

	ifs >> width >> height;
	ifs.close();

	if (strcmp(getMagicFormat(), "P5") == 0) //BINARY
	{

	}
	else //ASCII
	{
		loadContentFromASCII();
	}
}

void PGMImage::save() const
{
	if (strcmp(getMagicFormat(), "P5") == 0) //BINARY
	{
		saveToBinary(getFilePath());

	}
	else //P2 ASCII
	{
		saveToASCII(getFilePath());
	}
}

void PGMImage::saveAs(const char* direction) const
{
	if (strcmp(getMagicFormat(), "P5") == 0)
	{
		saveToBinary(direction);
	}
	else //ASCII
	{
		saveToASCII(direction);
	}
}

void PGMImage::negative()
{
	for (size_t i = 0; i < data.getSize(); i++)
	{
		data[i] = maxColor - data[i];
	}
}

void PGMImage::grayscale()
{
	
}

void PGMImage::monochrome()
{
	unsigned sum = 0;

	for (unsigned int i = 0; i < data.getSize(); i++)
	{
		sum += data[i]; // we want integer
	}

	uint16_t threshold = sum / (getHeight() * getWidth());

	int pixel = 0;

	for (size_t i = 0; i < data.getSize(); i++)
	{
		if (data[i] > threshold)
			pixel = maxColor;

		data[i] = pixel;

		pixel = 0;
	}

	isMonochrome = true;
}

void PGMImage::rotateLeft()
{
	size_t count = getWidth() * getHeight();
	Vector<uint16_t> newData(count);

	size_t newWidth = height;
	size_t newHeight = width;

	for (int j = width - 1; j >= 0; --j)
	{
		for (int i = 0; i < height; ++i)
		{
			size_t oldIndex = i * width + j;
			newData.pushBack(data[oldIndex]);
		}
	}

	std::swap(width, height);
	data = newData;
}

void PGMImage::rotateRight()
{
	size_t count = getWidth() * getHeight();
	Vector<uint16_t> newData(count);

	size_t newWidth = height;
	size_t newHeight = width;

	for (int j = 0; j < width; ++j)
	{
		for (int i = height - 1; i >= 0; --i)
		{
			int oldIndex = i * width + j;
			newData.pushBack(data[oldIndex]);
		}
	}

	std::swap(width, height);
	data = newData; //copy
}

bool PGMImage::isLoaded() const
{
	return (getWidth() != 0 && getHeight() != 0 && getColorMax() != 0);
}
