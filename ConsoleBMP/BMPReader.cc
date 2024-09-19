#include "BMPReader.h"

bool BMPReader::openBMP(const std::string& fileName)
{
    bmpFile.open(fileName, std::ios::binary);

    if (!bmpFile.is_open()) {
        std::cerr << "Failed to open BMP file." << std::endl;
        return false;
    }

    bmpFile.read(reinterpret_cast<char*>(&fileHeader), sizeof(BITMAPFILEHEADER));
    bmpFile.read(reinterpret_cast<char*>(&infoHeader), sizeof(BITMAPINFOHEADER));
    if (fileHeader.bfType != 0x4D42 || (infoHeader.biBitCount != 24 && infoHeader.biBitCount != 32)) {
        std::cerr << "Incorrect format. Supported format 24 or 32 bit." << std::endl;
        bmpFile.close();
        return false;
    }

    return true;
}

void BMPReader::displayBMP()
{
    bmpFile.seekg(fileHeader.bfOffBits, std::ios::beg);
    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;
    std::vector<std::vector<char>> pixels(height, std::vector<char>(width));

    int bytesPerPixel = infoHeader.biBitCount / 8;
    int rowSize = ((width * infoHeader.biBitCount + 31) / 32) * 4;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            char b, g, r;
            bmpFile.read(&b, 1);
            bmpFile.read(&g, 1);
            bmpFile.read(&r, 1);
            if (r == 0 && g == 0 && b == 0) {
                pixels[y][x] = '#';
            }
            else {
                pixels[y][x] = '_';
            }
        }
        bmpFile.seekg(rowSize - (width * bytesPerPixel), std::ios::cur);
    }

    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            std::cout << pixels[y][x];
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