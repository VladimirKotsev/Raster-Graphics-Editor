#pragma once
#include "Image.h"

class PGMImage : public Image
{
private:
	uint8_t** data;

	void free();
	void copyFrom(const PGMImage& other);
public:
	PGMImage(const char* filePath);

	PGMImage(const PGMImage& other);
	PGMImage& operator=(const PGMImage& other);

	PGMImage(PGMImage&& other) noexcept = delete;
	PGMImage& operator=(PGMImage&& other) noexcept = delete;

	// Inherited via Image
	Image* clone() const override;
	void load() override;
	void save() const override;
	void saveAs(const char* direction) const override;
	void saveToFile(const char* filePath) const override;
};

