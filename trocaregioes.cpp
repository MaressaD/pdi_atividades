#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char** argv){
  cv::Mat image;
  cv::Vec3b val;
  
  image=cv::imread(argv[1],cv::IMREAD_GRAYSCALE);
  if(!image.data)
    std::cout << "Falha ao abrir imagem" << std::endl;
  cv::namedWindow("janela", cv::WINDOW_AUTOSIZE);

 
  //int linhas=cv::i  

 image= cv::imread(argv[1],cv::IMREAD_COLOR);
 
  cv::imshow("janela", image);  
  cv::waitKey();
  cv::Mat aux;
  aux= cv::imread(argv[1],cv::IMREAD_COLOR);
  //=Mat::zeros(linhas,colunas,CV_8UC3);
int linhas = image.rows;
int colunas = image.cols;
//  int colunas=cv::image.cols;

  for(int i=0;i<linhas;i++){
   for(int j=0;j<colunas;j++){
     if(i<linhas/2 && j<colunas/2){
        aux.at<cv::Vec3b>(i,j)= image.at<cv::Vec3b>(i+linhas/2,j+colunas/2);
      }
     if(i<linhas/2 && j>=colunas/2){
            aux.at<cv::Vec3b>(i,j)= image.at<cv::Vec3b>(i+linhas/2,j-colunas/2);
     }
      if(i>=linhas/2 && j<colunas/2){
            aux.at<cv::Vec3b>(i,j)=image.at<cv::Vec3b>(i-linhas/2,j+colunas/2);
      }
      if(i>=linhas/2 && j>=colunas/2){
            aux.at<cv::Vec3b>(i,j)=image.at<cv::Vec3b>(i-linhas/2,j-colunas/2);
      }
 //     if(){}
   //   if(){}    
   }
   }

 // cv::imshow("janela", image);   
//  cv::waitKey();
  cv::imshow("janela", aux);
  cv::waitKey();
 imwrite("trocaregies.png",aux);
  return 0;
}