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
    Edge e;

    std::vector <Edge> edgs;
    for (int i = 0; i < width*height; i++){
        // Adicionar aresta terminal ligada ao foreground
        e.index = -1;
        e.weight = img[i].D1;
        edgs.push_back(e);

        // Adicionar aresta terminal ligada ao background
        e.index = -2;
        e.weight = img[i].D0;
        edgs.push_back(e);

        // Adicionar aresta do vizinho ao norte, se existir
        if (i - width >= 0){ 
            e.index = i-width;
            e.weight =lambda;
            edgs.push_back(e);
        }

        // Adicionar aresta do vizinho ao sul, se existir
        if (i + width < width*height){
            e.index = i+width;
            e.weight =lambda;
            edgs.push_back(e);
        }

        // Adicionar aresta do vizinho ao oeste, se existir
        if (i % width > 0){
            e.index = i-1;
            e.weight =lambda;
            edgs.push_back(e);
        }

        // Adicionar aresta do vizinho ao leste, se existir
        if (((i+1) % width) !=0){ 
            e.index = i+1;
            e.weight =lambda;
            edgs.push_back(e);
        }

        graph.push_back(edgs);
        edgs.clear();
    }
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
}

void Segmentation::segmentation(){}

void Segmentation::saveImage(){}
