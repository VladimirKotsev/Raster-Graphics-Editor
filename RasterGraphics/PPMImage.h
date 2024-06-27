#pragma once
#include <sstream>

#include "Image.h"
#include "Pixel.h"
#include "Vector.hpp"

const double Red = 0.299;
const double Green = 0.587;
const double Blue = 0.114;

class PPMImage : public Image
{
private:
	Vector<Pixel> data;
	uint16_t maxColor = 0;

public:
	PPMImage(const char* filePath);

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

	const uint16_t getColorMax() const;

	// Inherited via Image
	void negative() override;
	void grayscale() override;
	void monochrome() override;
	void rotateLeft() override;
	void rotateRight() override;

	// Inherited via Image
	bool isLoaded() const override;

	// Inherited via Image
	void collageWith(Image* other, bool isHorizontal) override;

	void collageWithPGM(const PGMImage* other, bool isHorizontal) override;
	void collageWithPPM(const PPMImage* other, bool isHorizontal) override;
	void collageWithPBM(const PBMImage* other, bool isHorizontal) override;

};

