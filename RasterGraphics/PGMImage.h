#pragma once
#include "Image.h"
#include "Vector.hpp"
#include <sstream>

class PGMImage : public Image
{
private:
	Vector<uint16_t> data;
	uint16_t maxColor;

	void free();
	void copyFrom(const PGMImage& other);

	void saveToASCII(const char* filePath) const override;
	void saveToBinary(const char* filePath) const override;
	void loadContentFromASCII() override;
	void loadContentFromBinary() override;
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

	const uint16_t getColorMax() const;

	// Inherited via Image
	void negative() override;
	void grayscale() override;
	void monochrome() override;
	void rotateLeft() override;
	void rotateRight() override;

	// Inherited via Image
	bool isLoaded() const override;
};

