#pragma once
#include <iostream>

class Image
{
private:
	char* filePath;
	char* magicFormat;

	uint16_t width;
	uint16_t height;
	uint16_t colorMax;
	
	void copyFrom(const Image& other);
	void free();

	void setFilePath(const char* filePath);
	void setMagicFormat(const char* format);
public:
	Image(const char* filePath);

	Image(const Image& other);
	Image& operator=(const Image& other);

	Image(Image&&) noexcept = delete;
	Image operator=(Image&&) noexcept = delete;

	virtual ~Image();

	virtual Image* clone() const = 0;

	virtual void load() = 0;
	virtual void save() const = 0;
	virtual void saveAs(const char* direction) const = 0;

	//virtual void getType() const = 0;

	const uint16_t getWidth() const;
	const uint16_t getHeight() const;
	const uint16_t getColorMax() const;
	const char* getFilePath() const;
	const char* getImageFormat() const;
};
