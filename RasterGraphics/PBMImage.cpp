#include "PBMImage.h"

Image* PBMImage::clone() const
{
    Image* toReturn = new (std::nothrow) PBMImage(*this);
    return toReturn;
}

void PBMImage::load()
{
}

void PBMImage::save() const
{

}

void PBMImage::saveAs(const char* direction) const
{

}
