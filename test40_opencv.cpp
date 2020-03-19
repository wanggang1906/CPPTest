#include<iostream>
#include<string>
#include <opencv2/opencv.hpp>


//#include "test40_opencv.h" // 这个是自动生成的

using namespace cv;

class opencvTest {
public:
	// cv主函数
	void opencvMain() {
		
		int stature;
		stature = this->shwoImage();
		std::cout << stature << "\n";
	}

	// 显示图片
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

