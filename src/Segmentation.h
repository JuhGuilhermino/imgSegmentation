
#include <vector>
#include <iostream>
#include <cmath>
#include <utility>

struct Pixel {
    int x;
    int y;
};

class Segmentation{
private:
    std::vector <int> img;     /*!< Pixels da imagem*/
    int height;                /*!< Altura da imagem */
    int width;                 /*!< Largura da imagem */

    std::vector <double> D1;   /*!< Custo do pixel i pertencer ao objeto*/
    std::vector <double> D0;   /*!< Custo do pixel i pertencer ao fundo*/

    double m0;
    double m1;
    double var0;
    double var1;

    double lambda = 3;

    Pixel source = {-1, -1};  /*!< s (foreground) */ 
    Pixel sink = {-2, -2};    /*!< t (background) */

    std::vector <std::pair<Pixel, double>> graph;

    double calculateAvarege(int* begin, int* end);

    double calculateSigma(int* begin, int* end, double m);

    void calculateWeight();

public:
    Segmentation();

    ~Segmentation();

    void getPixels(int pixel);

    void getSeeds(int* fsBegin, int* fsEnd, int* bsBegin, int* bsEnd);

    void buildGraph(int w, int h);

};



