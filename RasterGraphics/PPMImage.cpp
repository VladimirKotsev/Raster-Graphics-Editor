#include "PPMImage.h"
#include <sstream>

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

    char magicFormat[1024]; // should be constant
    ifs >> magicFormat;
    setMagicFormat(magicFormat);

    ifs >> width >> height;
    ifs.ignore();
    ifs >> colorMax;
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

    while (ifs.getline(buffer, 1024))
    {
        if (strlen(buffer) == 0)
            continue;

        ss.clear();
        ss.str(buffer);

        uint16_t red;
        uint16_t blue;
        uint16_t green;

        // Extract numbers from the current line
        while (ss >> red >> blue >> green)
        {
            Pixel pixel;
            pixel.red;
            pixel.blue;
            pixel.green;
            data.pushBack(pixel);
        }
    }

    ifs.close();
}

void PPMImage::loadContentFromBinary()
{

}
