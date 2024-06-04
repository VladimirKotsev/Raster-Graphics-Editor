#include "ImageContainer.h"

void ImageContainer::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete images[i];
	}

	delete[] images;
}

void ImageContainer::copyFrom(const ImageContainer& other)
{
	images = new Image*[other.capacity];
	capacity = other.capacity;
	size = other.size;
	for (size_t i = 0; i < size; i++)
	{
		images[i] = other.images[i];
	}
}

void ImageContainer::moveFrom(ImageContainer&& other)
{
	images = other.images;
	other.images = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.capacity = other.size = 0;
}

void ImageContainer::resize(size_t newCap)
{
	capacity = newCap;
	Image** newData = new Image*[capacity];
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = images[i];
	}

	delete[] images;
	images = newData;
}

ImageContainer::ImageContainer()
{
	size = 0;
	capacity = 4;
	images = new Image*[capacity];
}

ImageContainer::ImageContainer(const ImageContainer& other)
{
	copyFrom(other);
}

ImageContainer& ImageContainer::operator=(const ImageContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

ImageContainer::ImageContainer(ImageContainer&& other) noexcept
{
	moveFrom(std::move(other));
}

ImageContainer& ImageContainer::operator=(ImageContainer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

void ImageContainer::addImage(Image* image)
{
	if (size == capacity)
		resize(capacity * 2);

	images[size++] = image; //pray to be dynamic
	image = nullptr;
}

void ImageContainer::addImage(const Image& image)
{
	Image* cloned = image.clone();
	addImage(cloned);
}

size_t ImageContainer::getCapacity() const
{
	return capacity;
}

size_t ImageContainer::getSize() const
{
	return size;
}

Image* ImageContainer::operator[](size_t index)
{
	if (index < 0 || index >= size)
		throw std::invalid_argument("Given index out of bounds!");

	return images[index];
}

const Image* ImageContainer::operator[](size_t index) const
{
	if (index < 0 || index >= size)
		throw std::invalid_argument("Given index out of bounds!");

	return images[index];
}
