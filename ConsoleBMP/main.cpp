#include "BMPReader.h"

int main() {
    std::string filePath = "../data/1.bmp";

    BMPReader reader;
    if (reader.openBMP(filePath)) {
        reader.displayBMP();
    }

    return 0;
}