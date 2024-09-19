#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>

class BMPReader {
public:
	std::ifstream bmpFile;
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	bool openBMP(const std::string& fileName);
	void displayBMP();
	void closeBMP();
};