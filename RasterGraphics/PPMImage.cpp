#include "PPMImage.h"

void PPMImage::free()
{
    for (size_t i = 0; i < getHeight(); i++)
    {
        delete[] pixels[i];
    }

    delete[] pixels;
}

void PPMImage::copyFrom(const PPMImage& other)
{
    pixels = new Pixel*[other.getHeight()];
    for (size_t i = 0; i < other.getHeight(); i++)
    {
        for (size_t j = 0; j < other.getWidth(); j++)
        {
            pixels[i][j] = other.pixels[i][j];
        }
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
