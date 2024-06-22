#include "PPMImage.h"
#include "ExceptionMessages.h"

void PPMImage::free()
{
	data.clear();
}

void PPMImage::copyFrom(const PPMImage& other)
{
	for (size_t i = 0; i < other.data.getSize(); i++)
	{
		data[i] = other.data[i];
	}
}

PPMImage::PPMImage(const char* filePath) : Image(filePath) {}

PPMImage::PPMImage(const PPMImage& other) : Image(other)
{
	copyFrom(other);
}

PPMImage& PPMImage::operator=(const PPMImage& other)
{
	if (this != &other)
	{
		Image::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

PPMImage::~PPMImage()
{
	free();
}

Image* PPMImage::clone() const
{
	Image* cloned = new (std::nothrow) PPMImage(*this);
	return cloned;
}

void PPMImage::load()
{
	std::ifstream ifs(getFilePath(), std::ios::in);
	if (!ifs.is_open())
		throw std::logic_error(ExceptionMessages::FILE_NOT_OPENED);

	char magicFormat[GlobalConstants::BUFFER_SIZE]; // should be constant
	ifs >> magicFormat;
	setMagicFormat(magicFormat);

	ifs >> width >> height;
	ifs.ignore();
	ifs >> maxColor;
	ifs.close();

	if (strcmp(getMagicFormat(), "P6") == 0) //BINARY
	{

	}
	else //ASCII
	{
		loadContentFromASCII();
	}
}

void PPMImage::save() const
{
	if (strcmp(getMagicFormat(), "P3") == 0)
	{
		saveToASCII(getFilePath());
	}
	else
	{
		saveToBinary(getFilePath());
	}
}

void PPMImage::saveAs(const char* direction) const
{
	if (strcmp(getMagicFormat(), "P3") == 0)
	{
		saveToASCII(direction);
	}
	else
	{
		saveToBinary(direction);
	}
}

void PPMImage::saveToASCII(const char* filePath) const
{
	std::ofstream ofs(filePath);
	if (!ofs.is_open())
		throw std::logic_error(ExceptionMessages::FILE_NOT_OPENED);

	ofs << getMagicFormat() << '\n';
	ofs << getWidth() << ' ' << getHeight() << '\n';
	ofs << getColorMax() << '\n';

	unsigned col = 0;

	for (size_t i = 0; i < data.getSize(); i++)
	{
		ofs << data[i].red << ' ' << data[i].green << ' ' << data[i].blue;
		if (i + 1 < data.getSize())
			ofs << ' ';
	}

	ofs.close();
}

void PPMImage::saveToBinary(const char* filePath) const
{

}

void PPMImage::loadContentFromASCII()
{
	std::ifstream ifs(getFilePath(), std::ios::in);
	char buffer[GlobalConstants::BUFFER_SIZE]; // Should be a constant

	ifs.getline(buffer, GlobalConstants::BUFFER_SIZE);
	ifs.getline(buffer, GlobalConstants::BUFFER_SIZE);
	ifs >> maxColor;
	ifs.ignore();

	while (true)
	{
		if (ifs.eof())
			break;

		uint16_t red;
		uint16_t green;
		uint16_t blue;
		ifs >> red >> green >> blue;

		Pixel pixel;
		pixel.red = red;
		pixel.green = green;
		pixel.blue = blue;
		data.pushBack(pixel);
	}

	ifs.close();
}

void PPMImage::loadContentFromBinary()
{

}

const uint16_t PPMImage::getColorMax() const
{
	return maxColor;
}

void PPMImage::negative()
{
	for (size_t i = 0; i < data.getSize(); i++)
	{
		data[i].red = this->maxColor - data[i].red;
		data[i].green = this->maxColor - data[i].green;
		data[i].blue = this->maxColor - data[i].blue;
	}
}

void PPMImage::grayscale()
{
	unsigned int oldRed = 0;
	unsigned int oldGreen = 0;
	unsigned int oldBlue = 0;

	for (size_t i = 0; i < data.getSize(); i++)
	{
		oldRed = data[i].red;
		oldGreen = data[i].green;
		oldBlue = data[i].blue;

		data[i].red = (oldRed * Red) + (oldGreen * Green) + (oldBlue * Blue);
		data[i].green = (oldRed * Red) + (oldGreen * Green) + (oldBlue * Blue);
		data[i].blue = (oldRed * Red) + (oldGreen * Green) + (oldBlue * Blue);
	}
	isGrayscale = true;
}

void PPMImage::monochrome()
{
	unsigned avgSum = 0; // we need integer

	for (size_t i = 0; i < data.getSize(); i++)
	{
		int avg = data[i].red + data[i].green + data[i].blue;
		avgSum += avg / 3; // rounding down to integer number automatic
	}

	uint16_t threshold = avgSum / (getHeight() * getWidth());

	int pixel = 0;

	for (size_t i = 0; i < data.getSize(); i++)
	{
		uint16_t sum = (data[i].red + data[i].green + data[i].blue) / 3;

		if (sum >= threshold)
			pixel = maxColor;

		data[i].red = pixel;
		data[i].green = pixel;
		data[i].blue = pixel;

		pixel = 0;
	}
	isMonochrome = true;
}

void PPMImage::rotateLeft()
{ 
	size_t count = getWidth() * getHeight();
	Vector<Pixel> newData(count);

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

void PPMImage::rotateRight()
{
	size_t count = getWidth() * getHeight();
	Vector<Pixel> newData(count);

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
	data = newData;
}

bool PPMImage::isLoaded() const
{
	return (getWidth() != 0 && getHeight() != 0 && getColorMax() != 0);
}

void PPMImage::collageWith(const Image* other, bool isHorizontal) const
{
}

void PPMImage::collageWithPGM(const PGMImage* other, bool isHorizontal) const
{
}

void PPMImage::collageWithPPM(const PPMImage* other, bool isHorizontal) const
{
}

void PPMImage::collageWithPBM(const PBMImage* other, bool isHorizontal) const
{
}
