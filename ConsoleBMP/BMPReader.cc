#include "BMPReader.h"

bool BMPReader::openBMP(const std::string& fileName)
{
    bmpFile.open(fileName, std::ios::binary);

    if (!bmpFile.is_open()) {
        std::cerr << "Failed to open BMP file." << std::endl;
        return false;
    }

    if (infoHeader.biBitCount != 24 && infoHeader.biBitCount != 32) {
        std::cerr << "Unsupported format. Supported format 24 or 32 bit." << std::endl;
        bmpFile.close();
        return false;
    }

    bmpFile.read(reinterpret_cast<char*>(&fileHeader), sizeof(BITMAPFILEHEADER));
    bmpFile.read(reinterpret_cast<char*>(&infoHeader), sizeof(BITMAPINFOHEADER));

    return true;
}

void BMPReader::displayBMP()
{
    bmpFile.seekg(fileHeader.bfOffBits, std::ios::beg);
    char pixel;

    for (int y = 0; y < infoHeader.biHeight; ++y) {
        for (int x = 0; x < infoHeader.biWidth; ++x) {
            char b, g, r;
            bmpFile.read(&b, 1);
            bmpFile.read(&g, 1);
            bmpFile.read(&r, 1);
            if (r == 0 && g == 0 && b == 0) {
                pixel = '#';
            }
            else {
                pixel = ' ';
            }
            std::cout << pixel;
        }
        std::cout << std::endl;
    }
}

void BMPReader::closeBMP()
{
    if (bmpFile) {
        bmpFile.close();
    }
}