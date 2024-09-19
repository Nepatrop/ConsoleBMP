#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

class BMPReader {
public:
	std::ifstream* bmpFile;

	bool openBMP(const std::string& fileName);
	void displayBMP();
	void closeBMP();
};