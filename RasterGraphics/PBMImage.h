#pragma once
#include "Image.h"
#include "DynamicSet.h"
#include "Vector.hpp"

class PBMImage : public Image
{
private:
	DynamicSet* data = nullptr;

	void free();
	void copyFrom(const PBMImage& other);

public:
	PBMImage(const char* filePath);

	PBMImage(const PBMImage& other);
	PBMImage& operator=(const PBMImage& other);

	PBMImage(PBMImage&&) noexcept = delete;
	PBMImage& operator=(PBMImage&&) noexcept = delete;

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

