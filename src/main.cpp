#include "Segmentation.h"

#include <iostream>
#include <vector>
#include <chrono>

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

        //auto start = std::chrono::high_resolution_clock::now();
        Segmentation test(argv[1], Algorithm::BOYKOV_KOLMOGOROV);
        test.readImage();
        test.preProcessing(fBegin, fEnd, bBegin, bEnd);
        //test.segmentation();
        //test.~Segmentation();
        //auto end = std::chrono::high_resolution_clock::now();

        //auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        //std::cout << "Tempo de execução: " << duration.count() << "segundos" << std::endl;
    }
    return 0;
}
