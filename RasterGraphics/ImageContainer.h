#pragma once
#include "Image.h"

class ImageContainer
{
private:
	Image** images;
	size_t capacity;
	size_t size;

	void free();
	void copyFrom(const ImageContainer& other);
	void moveFrom(ImageContainer&& other);
	void resize(size_t newCap);

public:
	ImageContainer();

	ImageContainer(const ImageContainer& other);
	ImageContainer& operator=(const ImageContainer& other);

	ImageContainer(ImageContainer&& other) noexcept;
	ImageContainer& operator=(ImageContainer&& other) noexcept;

	void addImage(Image* image);
	void addImage(const Image& image);

	size_t getCapacity() const;
	size_t getSize() const;
	Image* operator[](size_t index);
	const Image* operator[](size_t index) const;
};

