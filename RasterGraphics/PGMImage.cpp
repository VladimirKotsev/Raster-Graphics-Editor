#include "PGMImage.h"
//#include "PGMImage.h"
//
//Image* PGMImage::clone() const
//{
//	Image* toReturn = new (std::nothrow) PGMImage(*this);
//	return toReturn;
//}
//
//void PGMImage::load() //reads from file
//{
//	unsigned format = getFormatNumber();
//
//	std::ifstream ifs(getFilePath(), std::ios::in);
//	ifs >> width >> height;
//	ifs.get();
//	ifs >> colorMax;
//	ifs.get();
//
//	data = new uint8_t*[getHeight()];
//
//	if (format <= 3) //ASCII!
//	{
//		for (size_t i = 0; i < getHeight(); i++)
//		{
//			data[i] = new uint8_t[];
//			for (size_t j = 0; j < getWidth(); j++)
//			{
//				ifs >> data[i][j];
//			}
//		}
//
//		ifs.close();
//	}
//	else if (format >= 4) // BINARY!
//	{
//		ifs.close();
//
//		std::ifstream ifs(getFilePath(), std::ios::in | std::ios::binary);
//		if (!ifs.is_open())
//			throw std::logic_error("File not opened!");
//
//		for (size_t i = 0; i < getHeight(); i++)
//		{
//			ifs.read((char*)data[i], getWidth() * sizeof(uint8_t));
//		}
//		ifs.close();
//	}
//}
//
//void PGMImage::save() const
//{
//	saveToFile(getFilePath());
//}
//
//void PGMImage::saveAs(const char* direction) const
//{
//	saveToFile(direction);
//}
//
//void PGMImage::saveToFile(const char* filePath) const
//{
//	unsigned format = getFormatNumber(); // get the magic number format;
//
//	std::ofstream ofs(filePath, std::ios::out);
//	if (!ofs.is_open())
//		throw std::logic_error("File not opened!");
//
//	const char* magicFormat = getMagicFormat();
//	uint16_t width = getWidth();
//	uint16_t height = getHeight();
//
//	ofs << magicFormat << '\n';
//	ofs << width << ' ' << height;
//
//	if (format <= 3) // ASCII!!
//	{
//		for (size_t i = 0; i < getHeight(); i++)
//		{
//			for (size_t j = 0; j < getWidth(); j++)
//			{
//				ofs << data[i][j];
//			}
//		}
//
//		ofs.close();
//	}
//	else if (format >= 4) // BINARY!!
//	{
//		ofs.close();
//
//		std::ofstream ofs(filePath, std::ios::out | std::ios::binary | std::ios::app);
//
//		if (!ofs.is_open())
//			throw std::logic_error("File not opened!");
//
//		for (size_t i = 0; i < getHeight(); i++)
//		{
//			ofs.write((const char*)(data[i]), getWidth() * sizeof(uint8_t));
//		}
//
//		ofs.close(); //flush()
//	}
//}
//
//void PGMImage::free()
//{
//	for (size_t i = 0; i < getHeight(); i++)
//	{
//		delete[] data[i];
//	}
//	delete[] data;
//}
//
//PGMImage::PGMImage(const char* filePath) : Image(filePath)
//{
//}
//
//PGMImage::PGMImage(const PGMImage& other) : Image(other)
//{
//	copyFrom(other);
//}
//
//PGMImage& PGMImage::operator=(const PGMImage& other)
//{
//	if (this != &other)
//	{
//		Image::operator=(other);
//		free();
//		copyFrom(other);
//	}
//
//	return *this;
//}

void PGMImage::free()
{
	for (size_t i = 0; i < data.getSize(); i++)
	{
		data[i].clear();
	}
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

	for (size_t i = 0; i < data.getSize(); i++)
	{
		size_t currRowSize = data[i].getSize();
		for (size_t j = 0; j < currRowSize; j++)
		{
			ofs << data[i][j] << ' ';
		}

		ofs << '\n';
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
		if (strlen(buffer) == 0) // Skip empty lines
			continue;

		ss.clear(); // Clear any previous state of stringstream
		ss.str(buffer); // Set stringstream's content to the current line

		Vector<uint16_t> row; // Creates a row
		uint16_t num;

		// Extract numbers from the current line
		while (ss >> num)
		{
			row.pushBack(num);
		}

		data.pushBack(std::move(row)); // Add the row to the data vector
	}

	ifs.close();
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

	char* magicFormat;
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

	}
	else //ASCII
	{
		saveToASCII(direction);
	}
}
