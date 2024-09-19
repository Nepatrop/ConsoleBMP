#include "BMPReader.h"

int main() {
    std::string filePath = "../data/3.bmp";

    BMPReader reader;
    if (reader.openBMP(filePath)) {
        reader.displayBMP();
        reader.closeBMP();
    }

    return 0;
}