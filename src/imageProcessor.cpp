/**
 * @file segmentation.h
 * @author Júlia Guilhermino (juh.guilhermino03@gmail.com)
 * @brief Implementação da classe Segmentation responsável por realizar a segemntação da imagem
 * @version 0.1
 * @date 2025-07-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "imageProcessor.h"


ImageProcessor::ImageProcessor(std::string filePath, std::string algorithmName){
    file = filePath;
    algorithm = algorithmName;
}

ImageProcessor::~ImageProcessor(){}

void ImageProcessor::read(){
    std::ifstream input(file); 

    if (!input) {
        std::cout << "ERRO: Cannot read the file: " << file << "\n";
    } else {
        input >> format >> width >> height >> rgbMax;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int r, g, b;
                input >> r >> g >> b;
                img.getPixels(r);
            }
        }
    }

    input.close();
}

void ImageProcessor::segmentation(int* fsBegin, int* fsEnd, int* bsBegin, int* bsEnd){
    img.getSeeds(fsBegin, fsEnd, bsBegin, bsEnd);
    img.buildGraph(width, height);
    //img.teste();
}

void ImageProcessor::write(){
    /*std::ofstream output("imgs/nova-img.ppm");
    if (!output) {
        std::cout << "ERRO: Cannot create new file: imgs/nova-img.ppm.\n";
    } else {
        output << format << "\n" << width << " " << height << "\n" << rgbMax << "\n";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                output << img[i][j] << " " << img[i][j] << " " << img[i][j];
                if (j == width-1) {
                    output << "\n";
                } else {
                    output << " ";
                }
            }
        }
        std::cout << "Imagem salva como: 'nova-img.ppm' em 'imgs'.\n";
        output.close();
    } */
}

