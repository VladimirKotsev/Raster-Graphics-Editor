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
}

void PPMImage::save() const
{
}

void PPMImage::saveAs(const char* direction) const
{

}

void PPMImage::saveToFile(const char* filePath) const
{
}

void PPMImage::saveToASCII(const char* filePath) const
{

}

void PPMImage::saveToBinary(const char* filePath) const
{

}

void PPMImage::loadContentFromASCII()
{

}

void PPMImage::loadContentFromBinary()
{

}
