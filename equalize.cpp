#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
int main(int argc, char** argv){
    cv::Mat image, imageEqualized;
    int width, height;
    cv::Mat hist, histEqualized;
    int nbins = 64;
    float range[] = {0, 255};
    const float *histrange = { range };
    bool uniform = true;
    bool acummulate = false;
  
    image=cv::imread(argv[1],cv::IMREAD_GRAYSCALE);

    if(!image.data){
        std::cout << "Falha ao abrir imagem"<<std::endl;
        return 0;
    }

    height = image.rows;
    width = image.cols;

    std::cout << "largura = " << width << std::endl;
    std::cout << "altura  = " << height << std::endl;

    cv::equalizeHist( image, imageEqualized );

    int histw = nbins, histh = nbins / 2;
    cv::Mat histImage(histh, histw, CV_8UC1, cv::Scalar(0,0,0));
    cv::Mat histImageEqualized(histh, histw, CV_8UC1, cv::Scalar(0,0,0));
        
    cv::calcHist(&image, 1, 0, cv::Mat(), hist, 1,
                 &nbins, &histrange,
                 uniform, acummulate);
    cv::calcHist(&imageEqualized, 1, 0, cv::Mat(), histEqualized, 1,
                 &nbins, &histrange,
                 uniform, acummulate);            

    cv::normalize(hist, hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
    cv::normalize(histEqualized, histEqualized, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());

    histImage.setTo(cv::Scalar(0));
    histImageEqualized.setTo(cv::Scalar(0));

    for(int i=0; i<nbins; i++){
        cv::line(histImage,
                cv::Point(i, histh),
                cv::Point(i, nbins - histh - cvRound(hist.at<float>(i))),
                cv::Scalar(255, 255, 255), 1, 8, 0);
        cv::line(histImageEqualized,
                cv::Point(i, histh),
                cv::Point(i, nbins - histh - cvRound(histEqualized.at<float>(i))),
                cv::Scalar(255, 255, 255), 1, 8, 0);
    }
    histImage.copyTo(image(cv::Rect(0, 0,nbins, histh)));
    histImageEqualized.copyTo(imageEqualized(cv::Rect(0, 0,nbins, histh)));

    cv::namedWindow("imagem original", cv::WINDOW_AUTOSIZE);
    cv::imshow("imagem original", image);  
    cv::imshow( "imagem equalizada", imageEqualized );
    
    cv::imwrite("histogram.png", image);
    cv::imwrite("equalize.png", imageEqualized);
    cv::waitKey();
    
return 0;
}