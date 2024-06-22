#include "PBMImage.h"
#include "ExceptionMessages.h"

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
		throw std::logic_error(ExceptionMessages::FILE_NOT_OPENED);

	char buffer[GlobalConstants::BUFFER_SIZE]; // CONSTANT SHOULD NOT BE HERE
	ifs.getline(buffer, GlobalConstants::BUFFER_SIZE);
	setMagicFormat(buffer);
	ifs >> width >> height;

	ifs.close();

	if (strcmp(getMagicFormat(), "P4") == 0) //BINARY
	{
		
	}
	else //ASCII
	{
		loadContentFromASCII();
	}
	//if (strcmp(getMagicFormat(), "P4") == 0) //BINARY
	//{
	//	std::ifstream ifs(getFilePath(), std::ios::in | std::ios::binary);

	//	if (!ifs.is_open())
	//		throw std::logic_error("File cannot be found!");

	//	char buffer[2 + 1]; // CONSTANT SHOULD NOT BE HERE
	//	ifs.getline(buffer, 2);

	//	ifs >> width >> height;
	//	ifs.ignore();

	//	unsigned bits = getWidth() * getHeight();
	//	int dataSize = (width * height + 7) / 8;
	//	uint8_t currentBit = 0;

	//	data = new DynamicSet(bits);
	//	uint8_t* fileData = new uint8_t[dataSize];

	//	ifs.read((char*)(data), dataSize);
	//	ifs.close();

	//	for (int i = 0; i < dataSize; ++i)
	//	{
	//		int byteIndex = i / 8;
	//		int bitIndex = 7 - (i % 8);
	//		if (fileData[byteIndex] & (1 << bitIndex))
	//			data->add(i);
	//	}
	//}
}

void PBMImage::save() const
{
	if (strcmp(getMagicFormat(), "P4") == 0)
	{
		saveToBinary(getFilePath());

	}
	else //P2 ASCII
	{
		saveToASCII(getFilePath());
	}
}

void PBMImage::saveAs(const char* direction) const
{
	if (strcmp(getMagicFormat(), "P4") == 0)
	{
		saveToBinary(direction);
	}
	else //ASCII
	{
		saveToASCII(direction);
	}
}

void PBMImage::saveToASCII(const char* filePath) const
{
	std::ofstream ofs(getFilePath(), std::ios::out);

	if (!ofs.is_open())
		throw std::logic_error(ExceptionMessages::FILE_NOT_OPENED);

	ofs << getMagicFormat() << '\n';
	ofs << getWidth() << ' ' << getHeight() << '\n';

	size_t bits = getWidth() * getHeight();

	for (size_t i = 0; i < bits; i++)
	{
		ofs << data.contains(i) << ' ';
	}

	ofs.close(); //calls flush()
}

void PBMImage::saveToBinary(const char* filePath) const
{
}

void PBMImage::loadContentFromASCII()
{
	std::ifstream ifs(getFilePath(), std::ios::in);

	if (!ifs.is_open())
		throw std::logic_error(ExceptionMessages::FILE_NOT_OPENED);

	char buffer[GlobalConstants::BUFFER_SIZE]; // CONSTANT SHOULD NOT BE HERE
	ifs.getline(buffer, GlobalConstants::BUFFER_SIZE);
	ifs.getline(buffer, GlobalConstants::BUFFER_SIZE);
	//ifs.ignore();

	unsigned bits = getWidth() * getHeight();
	uint8_t currentBit = 0;

	data = DynamicSet(bits);

	for (size_t i = 0; i < bits; i++)
	{
		ifs >> currentBit;
		if (currentBit == '1')
			data.add(i);
	}

	ifs.close();
}

void PBMImage::loadContentFromBinary()
{
}

void PBMImage::negative()
{
	size_t count = getWidth() * getHeight();
	DynamicSet newData(count);

	for (size_t i = 0; i < count; i++)
	{
		if (!data.contains(i))
			newData.add(i);
	}

	data = newData;
}

void PBMImage::grayscale()
{
	std::cout << "PBM image cannot be grayscaled!" << std::endl;
}

void PBMImage::monochrome()
{
	std::cout << "PBM image cannot be monochromed!" << std::endl;
}

void PBMImage::rotateLeft()
{
	size_t count = getWidth() * getHeight();
	DynamicSet newData(count);

	size_t newWidth = height;
	size_t newHeight = width;

	size_t number = 0;
	for (int j = width - 1; j >= 0; --j)
	{
		for (int i = 0; i < height; ++i)
		{
			int oldIndex = i * width + j;
			if (data.contains(oldIndex))
				newData.add(number);

			number++;
		}
	}

	std::swap(width, height);
	data = newData;
}

void PBMImage::rotateRight()
{
	size_t bits = getWidth() * getHeight();
	DynamicSet newData(bits);

	size_t newWidth = height;
	size_t newHeight = width;

	size_t number = 0;
	for (int j = 0; j < width; ++j)
	{
		for (int i = height - 1; i >= 0; --i)
		{
			int oldIndex = i * width + j;
			if (data.contains(oldIndex))
				newData.add(number);

			number++;
		}
	}

	std::swap(width, height);
	data = newData;
}

bool PBMImage::isLoaded() const
{
	return (getWidth() != 0 && getHeight() != 0);
}

void PBMImage::collageWith(Image* other, bool isHorizontal)
{
}

void PBMImage::collageWithPGM(const PGMImage* other, bool isHorizontal)
{
}

void PBMImage::collageWithPPM(const PPMImage* other, bool isHorizontal)
{
}

void PBMImage::collageWithPBM(const PBMImage* other, bool isHorizontal)
{
}

void PBMImage::free()
{
	//delete[] bits; //handles by class DynamicSet
}

void PBMImage::copyFrom(const PBMImage& other)
{
	//data = DynamicSet(other.getHeight() * other.getWidth());
	for (size_t i = 0; i < other.data.getCount(); i++)
	{
		if (other.data.contains(i))
			data.add(i);
	}
}

PBMImage::PBMImage(const char* filePath) : data(0), Image(filePath)
{
}

PBMImage::PBMImage(const PBMImage& other) : data(other.data.getCount()), Image(other)
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
