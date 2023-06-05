#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char**argv) {
  cv::Mat imagemCodificada, imagemDecodificada;
  cv::Vec3b valCodificada, valDecodificada;
  int nbits = 5;

  imagemCodificada = cv::imread(argv[1], cv::IMREAD_COLOR);
  //imagemEscondida = cv::imread(argv[2], cv::IMREAD_COLOR);

  if (imagemCodificada.empty()) {
    std::cout << "imagem nao carregou corretamente" << std::endl;
    return (-1);
  }

  imagemDecodificada = imagemCodificada.clone();

  for (int i = 0; i < imagemCodificada.rows; i++) {
    for (int j = 0; j < imagemCodificada.cols; j++) {
      valCodificada = imagemCodificada.at<cv::Vec3b>(i, j);
     // valDecodificada[0] = valCodificada[0] >> (8-nbits) << (8-nbits);
     // valDecodificada[1] = valCodificada[0] >> (8-nbits) << (8-nbits);
     // valDecodificada[2] = valCodificada[0] >> (8-nbits) << (8-nbits);

      valDecodificada[0] = valCodificada[0] << (nbits);
      valDecodificada[1] = valCodificada[0] << (nbits);
      valDecodificada[2] = valCodificada[0] << (nbits);
      imagemDecodificada.at<cv::Vec3b>(i, j) = valDecodificada;
    }
  }
  
  imwrite("imagemDecodificada.png", imagemDecodificada);
  imagemDecodificada = cv::imread("imagemDecodificada.png", cv::IMREAD_COLOR);
  cv::imshow("image decodificada", imagemDecodificada);
  cv::waitKey();
  return 0;
}
