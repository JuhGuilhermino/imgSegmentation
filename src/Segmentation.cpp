
#include "segmentation.h"

double Segmentation::calculateAvarege(int* begin, int* end){
    double sum = 0.0;
    int divisor = 0;
    while (begin < end){
        sum += img[*begin];
        ++begin;
        divisor++;
    }
    return std::round((sum/divisor) * 100) / 100;
}
    
double Segmentation::calculateSigma(int* begin, int* end, double m){
    double sum = 0.0;
    int divisor = 0;
    while (begin < end){
        sum += pow(img[*begin]-m,2);
        ++begin;
        divisor++;
    }
    return std::round((sum/divisor) * 100) / 100;
}

Segmentation::Segmentation(){}

Segmentation::~Segmentation(){}

void Segmentation::getPixels(int pixel){
    img.push_back(pixel);
}

void Segmentation::getSeeds(int* fsBegin, int* fsEnd, int* bsBegin, int* bsEnd){
    m1 = calculateAvarege(fsBegin, fsEnd);
    m0 = calculateAvarege(bsBegin, bsEnd);
    var1 = calculateSigma(fsBegin, fsEnd, m1);
    var0 = calculateSigma(bsBegin, bsEnd, m0);
}

void Segmentation::calculateWeight(){
    int size = img.size();
    double x,y;
    for (int i = 0; i < size; i++){
        x = pow(img[i]-m1, 2)/(2*var1);
        D1.push_back(std::round(x * 100) / 100);

        y = pow(img[i]-m0, 2)/(2*var0);
        D0.push_back(std::round(y * 100) / 100);
    }
}

void Segmentation::buildGraph(int w, int h){
    width = w;
    height = h;

    // Calcular pesos
    calculateWeight();

    // Gerar pixels
   
    

    // Adicionar arestas terminais
    
    
    
}
