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

void PBMImage::saveToFile(const char* filePath) const
{
}

void PBMImage::free()
{
	//delete[] bits; //handles by class DynamicSet
}

void PBMImage::copyFrom(const PBMImage& other)
{
	//bits = new DynamicSet[other.getHeight()];
}

//PBMImage::PBMImage(const char* filePath) : Image(filePath)
//{
//
//}

PBMImage::PBMImage(const char* filePath) : Image(filePath)
{
}

PBMImage::PBMImage(const PBMImage& other) : Image(other)
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

//PBMImage& PBMImage::operator=(const PBMImage& other)
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
