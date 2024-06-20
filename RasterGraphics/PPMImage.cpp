#include "PPMImage.h"

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

PPMImage::PPMImage(const char* filePath) : Image(filePath) { }

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

Image* PPMImage::clone() const
{
    Image* cloned = new (std::nothrow) PPMImage(*this);
    return cloned;
}

void PPMImage::load()
{
    std::ifstream ifs(getFilePath(), std::ios::in);
    if (!ifs.is_open())
    {
        std::cout << "error";
        throw std::logic_error("File cannot be open!");
    }

    char magicFormat[1024]; // should be constant
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
    std::ofstream ofs(filePath, std::ios::out);
    if (!ofs.is_open())
        throw std::logic_error("File cannot be opened!");

    ofs << getMagicFormat() << '\n';
    ofs << getWidth() << ' ' << getHeight() << '\n';
    ofs << getColorMax();

    unsigned col = 0;

    for (size_t i = 0; i < data.getSize(); i++)
    {
        if (col == getWidth())
        {
            col = 0;
            ofs << '/n';
        }

        ofs << data[i].red << ' ' << data[i].green << ' ' << data[i].blue << ' ';
        col++;
    }

    ofs.close();
}

void PPMImage::saveToBinary(const char* filePath) const
{

}

void PPMImage::loadContentFromASCII()
{
    std::ifstream ifs(getFilePath(), std::ios::in);
    char buffer[1024]; // Should be a constant
    std::stringstream ss;

    ifs.getline(buffer, 1024);
    ifs.getline(buffer, 1024);
    ifs >> maxColor;

    char* line = new char[getWidth() + getWidth()];

    while (true)
    {
        ifs.getline(line, getWidth() + getWidth() - 1, '\n');

        if (ifs.eof())
            break;

        if (strlen(line) == 0)
            continue;

        ss.clear();
        ss.str(line);

        uint16_t red;
        uint16_t green;
        uint16_t blue;

        // Extract numbers from the current line
        while (ss >> red >> green >> blue)
        {
            Pixel pixel;
            pixel.red = red;
            pixel.green = green;
            pixel.blue = blue;
            data.pushBack(pixel);
        }
    }

    delete[] line;
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
    for (unsigned int i = 0; i < data.getSize(); i++)
    {
            data[i].red = this->maxColor - data[i].red;
            data[i].green = this->maxColor - data[i].green;
            data[i].blue = this->maxColor - data[i].blue;
    }
}

void PPMImage::grayscale()
{

    for (size_t i = 0; i < data.getSize(); i++)
    {
        uint16_t gray = std::round((0.299 * data[i].red) + (0.587 * data[i].green) + (0.114 * data[i].blue));
        data[i].red = data[i].green = data[i].blue = gray;
    }
}

void PPMImage::monochrome()
{
    unsigned int avgSum = 0; // we need integer

    for (unsigned int i = 0; i < data.getSize(); i++)
    {
            int avg = data[i].red + data[i].green + data[i].blue;
            avgSum += avg / 3; // rounding down to integer number automatic
    }

    unsigned short threshold = avgSum / (getHeight() * getWidth());

    int pixel = 0;

    for (unsigned int i = 0; i < data.getSize(); i++)
    {
            unsigned short sum = (data[i].red + data[i].green + data[i].blue) / 3;

            if (sum >= threshold)
                pixel = maxColor;

            data[i].red = pixel;
            data[i].green = pixel;
            data[i].blue = pixel;

            pixel = 0;
    }
}

void PPMImage::rotateLeft()
{
}

void PPMImage::rotateRight()
{
    Vector<Pixel> newPixels;
    for (size_t i = 0; i < data.getSize(); i++)
    {
        Pixel pixel;
        pixel.red = data[i].red;
        pixel.green = data[i].red;
        pixel.blue = data[i].blue;
        data.pushBack(pixel);
        newPixels.pushBack(pixel);
    }

    /*int temp = rows;
    this->rows = this->cols;
    this->cols = temp;

    for (unsigned int i = 0; i < cols; i++)
    {
        Pixel* arrTemp = new Pixel[rows];
        for (unsigned int j = 0; j < rows; j++)
        {
            arrTemp[j] = newPixels[i][j];
        }

        for (unsigned index = 0; index < rows; index++)
        {
            newPixels[i][index] = arrTemp[rows - 1 - index];
        }
    }*/

    data = newPixels; // copy
}

bool PPMImage::isLoaded() const
{
    return (getWidth() != 0 && getHeight() != 0 && getColorMax() != 0);
}
