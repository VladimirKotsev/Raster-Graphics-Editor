#pragma once
#include "Image.h"
#include "Pixel.h"

class PPMImage : public Image
{
private:
	Pixel** pixels;

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
	void saveToFile(const char* filePath) const override;
};

