#pragma once
#include <iostream>
#include <fstream>

class MyString;

class Image
{
private:
	char* filePath;
	char* magicFormat;
	
	void copyFrom(const Image& other);
	void free();

	void setFilePath(const char* filePath);

	virtual void saveToASCII(const char* filePath) const = 0;
	virtual void saveToBinary(const char* filePath) const = 0;
	virtual void loadContentFromASCII() = 0;
	virtual void loadContentFromBinary() = 0;
protected:
	void setMagicFormat(const char* format);

	uint16_t width;
	uint16_t height;

	bool isGrayscale = false;
	bool isMonochrome = false;
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

	virtual void negative() = 0;
	virtual void grayscale() = 0;
	virtual void monochrome() = 0;
	virtual void rotateLeft() = 0;
	virtual void rotateRight() = 0;

	//virtual void getType() const = 0;

	const uint16_t getWidth() const;
	const uint16_t getHeight() const;
	const char* getFilePath() const;
	const char* getMagicFormat() const;
	virtual bool isLoaded() const = 0;

	bool getIsGrayscale() const;
	bool getIsMonochrome() const;

	friend std::ostream& operator<<(std::ostream& os, const Image& image);
};
