#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv) {
  cv::Mat image, realce;
  int width, height;
  int nobjects, corDeFundo,nBuracos;
  bool fundoMudado;
  cv::Point p;
  image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

  if (!image.data) {
    std::cout << "imagem nao carregou corretamente\n";
    return (-1);
  }

  width = image.cols;
  height = image.rows;
  std::cout << width << "x" << height << std::endl;

  p.x = 0;
  p.y = 0;

  // busca objetos presentes
  nobjects = 0;
  nBuracos=0;
  corDeFundo=100;
  fundoMudado=false;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
        if (image.at<uchar>(i, j) == 255 ) {
        p.x = j;
        p.y = i; 
       
            if(j==0 || i==0 || j==width-1 || i==height-1 ){
                cv::floodFill(image, p, 0);
            }                
      } 
      if(fundoMudado==false && i ==height-1 && j==width-1){
                p.x = 0;
                p.y = 0;
                cv::floodFill(image, p, corDeFundo);
                fundoMudado=true;
            } 
    }
    
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
        if (image.at<uchar>(i, j) == 0 ) {
        p.x = j;
        p.y = i; 
        nBuracos++;
        cv::floodFill(image, p, nBuracos);
        }
        if (image.at<uchar>(i, j) == 255 ) {
        p.x = j;
        p.y = i; 
        nobjects++;
        cv::floodFill(image, p, 200);
        }
    }
  }
  std::cout << "a figura tem " << nobjects << " bolhas\n";
  std::cout << "a figura tem " << nBuracos << " buracos\n";
  cv::imshow("image", image);
  cv::imwrite("labeling2.png", image);
  cv::waitKey();
  return 0;
}