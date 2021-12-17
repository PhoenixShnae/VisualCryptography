#include <iostream>
#include <opencv2/opencv.hpp>


using namespace cv;
int main()
{

    Mat image = imread("C:/Users/phoen/Downloads/680482.jpg", IMREAD_GRAYSCALE);
    Mat img;
    namedWindow("FINAL", WINDOW_AUTOSIZE);
    threshold(image,img,127,255,THRESH_BINARY);
    imwrite("C:/Users/phoen/Documents/Demo/Project.png", img);
    Mat A(img.rows*2,img.cols*2,CV_8UC1,Scalar(255));  
    Mat B(img.rows*2,img.cols*2,CV_8UC1,Scalar(255));
    for(int i=0;i<img.rows;i++)
    {
        for(int j=0;j<img.cols;j++){
            if(img.at<uchar>(i,j)==0)
            {
                int k=i*2;
                int l=j*2;
                srand(l);
                int c=rand()%6+1;
                switch(c){
                case 1:
                    A.at<uchar>(k,l)=0;
                    A.at<uchar>(k+1,l+1)=0;
                    B.at<uchar>(k,l+1)=0;
                    B.at<uchar>(k+1,l)=0;
                    break;
                case 2:
                    A.at<uchar>(k,l+1)=0;
                    A.at<uchar>(k+1,l)=0;
                    B.at<uchar>(k,l)=0;
                    B.at<uchar>(k+1,l+1)=0;
                    break;
                case 3:
                    A.at<uchar>(k,l)=0;
                    A.at<uchar>(k,l+1)=0;
                    B.at<uchar>(k+1,l+1)=0;
                    B.at<uchar>(k+1,l)=0;
                    break;
                case 4:
                    A.at<uchar>(k+1,l)=0;
                    A.at<uchar>(k+1,l+1)=0;
                    B.at<uchar>(k,l+1)=0;
                    B.at<uchar>(k,l)=0;
                    break;
                case 5:
                    A.at<uchar>(k,l)=0;
                    A.at<uchar>(k+1,l)=0;
                    B.at<uchar>(k,l+1)=0;
                    B.at<uchar>(k+1,l+1)=0;
                    break;
                case 6:
                    A.at<uchar>(k,l+1)=0;
                    A.at<uchar>(k+1,l+1)=0;
                    B.at<uchar>(k,l)=0;
                    B.at<uchar>(k+1,l)=0;
                    break;
                }
            }
            else
            {
                int k=i*2;
                int l=j*2;
                srand(k);
                int c=rand()%6+1;
                switch(c){
                case 1:
                    A.at<uchar>(k,l)=0;
                    A.at<uchar>(k+1,l+1)=0;
                    B.at<uchar>(k,l)=0;
                    B.at<uchar>(k+1,l+1)=0;
                    break;
                case 2:
                    A.at<uchar>(k,l+1)=0;
                    A.at<uchar>(k+1,l)=0;
                    B.at<uchar>(k,l+1)=0;
                    B.at<uchar>(k+1,l)=0;
                    break;
                case 3:
                    A.at<uchar>(k,l)=0;
                    A.at<uchar>(k,l+1)=0;
                    B.at<uchar>(k,l+1)=0;
                    B.at<uchar>(k,l)=0;
                    break;
                case 4:
                    A.at<uchar>(k+1,l)=0;
                    A.at<uchar>(k+1,l+1)=0;
                    B.at<uchar>(k+1,l+1)=0;
                    B.at<uchar>(k+1,l)=0;
                    break;
                case 5:
                    A.at<uchar>(k,l)=0;
                    A.at<uchar>(k+1,l)=0;
                    B.at<uchar>(k,l)=0;
                    B.at<uchar>(k+1,l)=0;
                    break;
                case 6:
                    A.at<uchar>(k,l+1)=0;
                    A.at<uchar>(k+1,l+1)=0;
                    B.at<uchar>(k,l+1)=0;
                    B.at<uchar>(k+1,l+1)=0;
                    break;
                }
            }
        }
    }
    imwrite("C:/Users/phoen/Documents/Demo/Share1.png", A);
    imwrite("C:/Users/phoen/Documents/Demo/Share2.png", B);
    Mat Final(img.rows*2,img.cols*2,CV_8UC1,Scalar(255));
    for(int i=0;i<Final.rows;i++)
    {
        for(int j=0;j<Final.cols;j++){
            if( A.at<uchar>(i,j)==0 || B.at<uchar>(i,j)==0){
                 Final.at<uchar>(i,j)=0;
            }
        }
    }
    imwrite("C:/Users/phoen/Documents/Demo/Final.png", Final);
    waitKey(0);
    return 0;
}
