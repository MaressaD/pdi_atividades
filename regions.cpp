#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char** argv){
  cv::Mat image;
  cv::Vec3b val;
  int a0,a1;
  int b0,b1;

  image= cv::imread(argv[1],cv::IMREAD_COLOR);
  int linhas = image.rows;
  int colunas = image.cols;
  std::cout<<"Digite as quatro coordenadas da caixa a0 a1 b0 b1 dentro dos limites \n numero de linhas:"<<linhas<< "\n numero de colunas:"<<colunas<<std::endl;
  std::cin>>a0>>a1>>b0>>b1;

  
  while(a1>linhas || b1>colunas || a0>linhas || b0>colunas ){
    std::cout<<"Coordenadas devem ser valores dentro da imagem! Digite novamente:";
   std::cin>>a0>>a1>>b0>>b1;
 }
  if(!image.data)
    std::cout << "nao abriu bolhas.png" << std::endl;

  cv::namedWindow("janela", cv::WINDOW_AUTOSIZE);

  val[0] = 255;   //B
  val[1] = 255;   //G
  val[2] = 255; //R
  
  for(int i=a0;i<a1;i++){
    for(int j=b0;j<b1;j++){
      image.at<cv::Vec3b>(i,j)=val-image.at<cv::Vec3b>(i,j);
    }
  }

  cv::imshow("janela", image);  
  cv::waitKey();
  
 imwrite("regions.png",image);
  return 0;
}