#include "PGMImage.h"

Image* PGMImage::clone() const
{
    Image* toReturn = new (std::nothrow) PGMImage(*this);
    return toReturn;
}

void PGMImage::load()
{

}

void PGMImage::save() const
{

}

void PGMImage::saveAs(const char* direction) const
{

}
