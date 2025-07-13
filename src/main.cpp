#include "Segmentation.h"

#include <iostream>
#include <vector>

void print_usage() {
    std::cerr << "Usage: ./main <input_image_file>\n";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_usage();
    } else {
        std::vector <int> foregroundSeeds = {0,1};
        std::vector <int> backgroundSeeds = {7,8};

        int* fBegin = foregroundSeeds.data();
        int* fEnd = fBegin + foregroundSeeds.size();
        int* bBegin = backgroundSeeds.data();
        int* bEnd = bBegin + backgroundSeeds.size();

        Segmentation test(argv[1], Algorithm::BOYKOV_KOLMOGOROV);
        test.readImage();
        test.preProcessing(fBegin, fEnd, bBegin, bEnd);
        //test.segmentation();
        //test.~Segmentation();

    }
    return 0;
}
