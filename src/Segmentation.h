#ifndef SEGMENTATION
#define SEGMENTATION

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

enum Algorithm {
    FORD_FULKERSON,
    BOYKOV_KOLMOGOROV
};

struct Pixel {
    int rgb;
    int i;
    int j;
    double D0;
    double D1;
};

struct Edge {
    int index;
    double weight;
};

class Segmentation {
private:
    /* DADOS NA IMAGEM */
    std::string file;                      /*!< Path da imagem*/
    std::string algorithm;                 /*!< Operação a ser realizada na imagem */
    std::string format;                    /*!< Formato da imagem (ex.: P3 para PPM) */
    std::string rgbMax;                    /*!< Valor máximo para os componentes RGB */
    int height;                            /*!< Altura da imagem */
    int width;                             /*!< Largura da imagem */

    /* DADOS RELACIONADO AO CÁLCULO DOS PESOS DAS ARESTAS*/
    double m0;
    double m1;
    double var0;
    double var1;
    double lambda = 3;

    /* REPRESENTAÇÃO DA IMAGEM E GRAFO EM ESTRUTURA DE DADOS*/
    std::vector <Pixel> img;
    std::vector <std::vector<Edge>> graph;
    Pixel source = {255, -1, -1, -1, -1};  /*!< s (foreground) */ 
    Pixel sink = {0, -2, -2, -1, -1};    /*!< t (background) */

    /* MÉTODOS AUXILIARES */
    double calculateAvarege(int* begin, int* end);

    double calculateVar(int* begin, int* end, double m);

    void calculateWeight();

    void buildGraph();

public:
    Segmentation(std::string imgPath, int algorithmName);
    
    ~Segmentation();

    void readImage();

    void preProcessing(int* fsBegin, int* fsEnd, int* bsBegin, int* bsEnd);

    void segmentation();

    void saveImage();
};
#endif