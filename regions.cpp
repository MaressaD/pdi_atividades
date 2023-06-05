#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char** argv){
  cv::Mat image;
  cv::Vec3b val;
  int a0,a1;
  int b0,b1;


  std::cout<<"Digite as quatro coordenadas da caixa (X0,X1,Y0,Y1):";
  std::cin>>a0>>a1>>b0>>b1;
  while(a1>256 || b1>256){
    std::cout<<"Coordenadas devem ser valores entre 0 e 256:! Digite novamente:";
    std::cin>>a0>>a1>>b0>>b1;
  }

  image= cv::imread(argv[1],cv::IMREAD_COLOR);
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