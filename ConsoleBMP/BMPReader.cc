#include "BMPReader.h"

bool BMPReader::openBMP(const std::string& fileName)
{
    closeBMP();

    bmpFile = new std::ifstream(fileName, std::ios::binary);

    if (!bmpFile->is_open()) {
        std::cerr << "Failed to open bmpFile." << std::endl;
        return false;
    }
    return true;
}

void BMPReader::displayBMP()
{
    
}

void BMPReader::closeBMP()
{
    if (bmpFile) {
        bmpFile->close();
        delete bmpFile;
        bmpFile = nullptr;
    }
}