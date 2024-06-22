#pragma once
#include "Image.h"
#include "DynamicSet.h"
#include "Vector.hpp"

class PBMImage : public Image
{
private:
	DynamicSet data;

	void free();
	void copyFrom(const PBMImage& other);

public:
	PBMImage(const char* filePath);

	PBMImage(const PBMImage& other);
	PBMImage& operator=(const PBMImage& other);

	PBMImage(PBMImage&&) noexcept = delete;
	PBMImage& operator=(PBMImage&&) noexcept = delete;

	~PBMImage();

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
	void negative() override;
	void grayscale() override;
	void monochrome() override;
	void rotateLeft() override;
	void rotateRight() override;

	// Inherited via Image
	bool isLoaded() const override;

	// Inherited via Image
	void collageWith(const Image* other, bool isHorizontal) const override;
	void collageWithPGM(const PGMImage* other, bool isHorizontal) const override;
	void collageWithPPM(const PPMImage* other, bool isHorizontal) const override;
	void collageWithPBM(const PBMImage* other, bool isHorizontal) const override;
};

