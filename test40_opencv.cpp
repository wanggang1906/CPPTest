#include<iostream>
#include<string>
#include <opencv2/opencv.hpp>


//#include "test40_opencv.h" // ������Զ����ɵ�

using namespace cv;

class opencvTest {
public:
	// cv������
	void opencvMain() {
		
		int stature;
		stature = this->shwoImage();
		std::cout << stature << "\n";
	}

	// ��ʾͼƬ
	int shwoImage() {
		Mat image = imread("E:\\OpenCV\\image\\01.jpg");
		bool a = false;
		a = image.empty();
		if (image.empty()) {

			printf("could not load image...\n");

			return -1;

		}

		namedWindow("test_opencv_setup", 0);

		imshow("test_opencv_srtup", image);

		waitKey(0);
		return 0;


	}


};

