#pragma once
#include "Image.h"
#include "DynamicSet.h"
#include "Vector.hpp"

class PBMImage : public Image
{
private:
	DynamicSet data;

public:
	PBMImage(const char* filePath);

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

	// Inherited via Image
	void collageWith(Image* other, bool isHorizontal);

	void collageWithPGM(const PGMImage* other, bool isHorizontal);
	void collageWithPPM(const PPMImage* other, bool isHorizontal);
	void collageWithPBM(const PBMImage* other, bool isHorizontal);

	// Inherited via Image
	void negative() override;
	void grayscale() override;
	void monochrome() override;
	void rotateLeft() override;
	void rotateRight() override;

	// Inherited via Image
	bool isLoaded() const override;
};

