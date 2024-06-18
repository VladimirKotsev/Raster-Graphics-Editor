#pragma once
#include <sstream>

#include "Image.h"
#include "Pixel.h"
#include "Vector.hpp"

class PPMImage : public Image
{
private:
	Vector<Pixel> data;

	void free();
	void copyFrom(const PPMImage& other);

public:
	PPMImage(const char* filePath);

	PPMImage(const PPMImage& other);
	PPMImage& operator=(const PPMImage& other);

	PPMImage(PPMImage&& other) noexcept = delete;
	PPMImage& operator=(PPMImage&& other) noexcept = delete;

	// Inherited via Image
	Image* clone() const override;

	void load() override;

	void save() const override;

	void saveAs(const char* direction) const override;

	// Inherited via Image
	void saveToASCII(const char* filePath) const override;
	void saveToBinary(const char* filePath) const override;
	void loadContentFromASCII() override;
	void loadContentFromBinary() override;
};

