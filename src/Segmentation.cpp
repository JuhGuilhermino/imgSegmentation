#include "Segmentation.h"

double Segmentation::calculateAvarege(int* begin, int* end){
    double sum = 0.0;
    int divisor = 0;
    while (begin < end){
        sum += img[*begin].rgb;
        ++begin;
        divisor++;
    }
    return std::round(((sum/divisor) * 100) / 100);
}

double Segmentation::calculateVar(int* begin, int* end, double m){
    double sum = 0.0;
    int divisor = 0;
    while (begin < end){
        sum += pow(img[*begin].rgb-m,2);
        ++begin;
        divisor++;
    }
    return std::round(((sum/divisor) * 100) / 100);
}

void Segmentation::calculateWeight(){
    int size = img.size();
    double x;

    for (int i = 0; i < size; i++){
        x = std::pow(img[i].rgb - m1, 2)/(2*var1);
        img[i].D1 = std::round(x * 100) / 100;

        x = std::pow(img[i].rgb - m0, 2)/(2*var0);
        img[i].D0 = std::round(x * 100) / 100;
    }
}

void Segmentation::buildGraph(){
    
}

Segmentation::Segmentation(std::string filePath, int algorithmName){
    file = filePath;
    algorithm = algorithmName;
}

Segmentation::~Segmentation(){}

void Segmentation::readImage(){
    std::ifstream input(file); 

    if (!input) {
        std::cout << "ERRO: Cannot read the file: " << file << "\n";
    } else {
        input >> format >> width >> height >> rgbMax;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int r, g, b;
                input >> r >> g >> b;
                img.push_back({r, i, j, -1, -1});
            }
        }
    }
    input.close();
}

void Segmentation::preProcessing(int* fsBegin, int* fsEnd, int* bsBegin, int* bsEnd){
    m1 = calculateAvarege(fsBegin, fsEnd);
    m0 = calculateAvarege(bsBegin, bsEnd);
    var1 = calculateVar(fsBegin, fsEnd, m1);
    var0 = calculateVar(bsBegin, bsEnd, m0);
    calculateWeight();
    buildGraph();

    int x = img.size();
    std::cout << "RGB - X - Y - D1 - D0 \n";
    for (int i = 0; i < x; i++){
        std::cout <<  img[i].rgb << " - " <<img[i].i << " - " << img[i].j << " - " << img[i].D1 << " - " << img[i].D0 << "\n";  
    }
}

void Segmentation::segmentation(){}

void Segmentation::saveImage(){}
