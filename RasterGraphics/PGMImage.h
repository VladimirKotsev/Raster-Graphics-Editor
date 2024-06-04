#pragma once
#include "Image.h"

class PGMImage : public Image
{
	// Inherited via Image
	Image* clone() const override;
	void load() override;
	void save() const override;
	void saveAs(const char* direction) const override;
};

