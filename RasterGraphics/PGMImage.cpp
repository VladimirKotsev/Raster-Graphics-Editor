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

	unsigned col = 0;
	for (size_t i = 0; i < data.getSize(); i++)
	{
		if (col == getWidth())
		{
			col = 0;
			ofs << '/n';
		}

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
	char buffer[1024]; // Should be a constant
	std::stringstream ss;

	while (ifs.getline(buffer, 1024))
	{
		if (strlen(buffer) == 0)
			continue;

		ss.clear();
		ss.str(buffer);

		uint16_t num;

		// Extract numbers from the current line
		while (ss >> num)
		{
			data.pushBack(num);
		}
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

Image* PGMImage::clone() const
{
	Image* cloned = new (std::nothrow) PGMImage(*this);
	return cloned;
}

void PGMImage::load()
{
	std::ifstream ifs(getFilePath(), std::ios::in);

	char magicFormat[1024]; // should be constant
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
