#pragma once

#include<iostream>
#include<string>
#include <opencv2/opencv.hpp>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>

// ÍòÄÜÄ£°å£¿£¿£¿
#include <stdio.h>
#include <tchar.h>

#include <fstream>

#define CV_VERSION_ID CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)

#ifdef _DEBUG
#define cvLIB(name) "opencv_" name CV_VERSION_ID "d"
#else
#define cvLIB(name) "opencv_" name CV_VERSION_ID
#endif

#pragma comment( lib, cvLIB("core") )
#pragma comment( lib, cvLIB("imgproc") )
#pragma comment( lib, cvLIB("highgui") )
#pragma comment( lib, cvLIB("flann") )
#pragma comment( lib, cvLIB("features2d") )
#pragma comment( lib, cvLIB("calib3d") )
#pragma comment( lib, cvLIB("gpu") )
#pragma comment( lib, cvLIB("legacy") )
#pragma comment( lib, cvLIB("ml") )
#pragma comment( lib, cvLIB("objdetect") )
#pragma comment( lib, cvLIB("ts") )
#pragma comment( lib, cvLIB("video") )
#pragma comment( lib, cvLIB("contrib") )
#pragma comment( lib, cvLIB("nonfree") )







#ifndef _test40_opencv_H_

class opencvTest {
public:
	void opencvMain();
	void showImage();
	void openCamera();
	void openVideo();

	std::string findHumanFace();
	//void DetectFace(cv::Mat img, cv::Mat imgGray, CascadeClassifier faceCascade, CascadeClassifier eyes_Cascade);
	int rgbOrGbr();

	int findFace2();
	//void detectAndDraw(Mat& img, CascadeClassifier& cascade,
	//	CascadeClassifier& nestedCascade, double scale, bool tryflip);

	
};



#endif
