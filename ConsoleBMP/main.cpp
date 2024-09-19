#include "BMPReader.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Parameter error! Correct: ConsoleBMP.exe Path/To/.bmp";
        return 0;
    }

    BMPReader reader;
    if (reader.openBMP(argv[1])) {
        reader.displayBMP();
        reader.closeBMP();
    }

    return 0;
}