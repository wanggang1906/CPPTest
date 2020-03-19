#include<iostream>
#include<string>
#include <opencv2/opencv.hpp>

// 人脸检测相关
// #include <opencv/cv.h>
// #include <opencv/highgui.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>

#include<vector>


//#include "test40_opencv.h" // 这个是自动生成的

using namespace cv;
using namespace std;

class opencvTest {
public:
	// cv主函数
	void opencvMain() {
		
		int stature;
		std::string result;
		//stature = this->shwoImage();
		//stature = this->openCamera();
		std::cout << "执行结果" << stature << "\n";

		result = this->findHumanFace();
		std::cout << "执行结果" << result << "\n";
	}

	// 显示图片
	int shwoImage() {
		Mat imageJpg = imread(".\\image\\01.jpg"); // .当前文件夹下的路径，不是.. 他表示父文件夹下的路径
		Mat imagePng = imread(".\\image\\02.png");
		Mat imageJpeg = imread(".\\image\\03.jpeg");
		bool a = false;
		a = imageJpg.empty(); // 图片的data，zise,dims为空时，则表示图片为空，不能显示
		if (imageJpg.empty()) {

			printf("could not load image...\n");

			return -1;

		}

		namedWindow("test_opencv_setup-jpg", 0); // 新建窗口
		imshow("test_opencv_setup-jpg", imageJpg); // 装入图片

		if (imagePng.empty()) {
			printf("could not load image...\n");
			return -1;
		}
		namedWindow("test_opencv_setup-png", 0);
		imshow("test_opencv_setup-png", imagePng);

		if (imageJpeg.empty()) {
			printf("could not load image...\n");
			return -1;
		}
		namedWindow("test_opencv_setup-jpeg", 0);
		imshow("test_opencv_setup-jpeg", imageJpeg);

		// 等待时间
		waitKey(0);
		return 0;


	}

	// 打开摄像头
	int openCamera() {

		namedWindow("Example", WINDOW_AUTOSIZE);
		VideoCapture cap;
		cap.open(0);
		// VideoCapture cap(0);这句话可以替代上面两个语句，效果是一致的。
		if (!cap.isOpened())
		{
			std::cout << "不能打开摄像头。。。" << "\n";
			return -1;
		}

		cv::Mat frame;
		while (1)
		{
			cap >> frame;
			if (frame.empty())
			{
				break;
			}
			imshow("Example", frame);
			if (waitKey(33) >= 0) break;
		}
		getchar();
		return 0;
	}

	// 读取视频为图像
	void openVideo() {

		VideoCapture cap;
		cap.open("E://2.avi"); //打开视频,以上两句等价于VideoCapture cap("E://2.avi");
		
	     //cap.open("http://www.laganiere.name/bike.avi");//也可以直接从网页中获取图片，前提是网页有视频，以及网速够快
		if (!cap.isOpened()) return; //如果视频不能正常打开则返回
		 Mat frame;
		 while (1)
		{
			 cap >> frame;//等价于cap.read(frame);
			 if (frame.empty()) break; //如果某帧为空则退出循环
			 imshow("video", frame);
			 waitKey(20);//每帧延时20毫秒
		}
		cap.release();//释放资源
	}


	// 人脸检测
	// 来源
	// https://zhuanlan.zhihu.com/p/31852169
	// 检测思路：
	// 先把图片转为灰度，接着将图片直方均匀化，在上面处理后的图片矩阵中检测脸的区域，然后把脸这一块圈出来去检测眼睛。
	std::string findHumanFace()
	{
		// opencv库中的类
		CascadeClassifier faceCascade;
		CascadeClassifier eyes_Cascade;

		VideoCapture cap;
		if (!cap.open("C:\\Users\\cb\\Downloads\\b.mp4")) { // 检测视频中的人脸
			std::cout << "摄像头打开失败!!" << "\n";
			return "失败";
		}
		if (!faceCascade.load(".\\model\\haarcascade_frontalface_alt2.xml")) { // 加载人脸分类器
			std::cout << "人脸检测级联分类器没找到！！" << "\n";
			return "失败";
		}
		if (!eyes_Cascade.load(".\\model\\haarcascade_eye_tree_eyeglasses.xml")) { // 加载人眼分类器
			std::cout << "眼睛检测级联分类器没找到！！" << "\n";
			return "失败";
		}
		Mat img, imgGray;
		int fps = 60; // 帧数
		while (true) {
			cap >> img;
			cvtColor(img, imgGray, CV_BGR2GRAY);
			equalizeHist(imgGray, imgGray);//直方图均匀化 - 直方图均衡化
			this->DetectFace(img, imgGray, faceCascade, eyes_Cascade);

			waitKey(1000 / fps);
		}
		return 0;
	}

	void DetectFace(Mat img, Mat imgGray, CascadeClassifier faceCascade,CascadeClassifier eyes_Cascade) {

		// opencv库中的类
		//CascadeClassifier faceCascade;
		//CascadeClassifier eyes_Cascade;

		namedWindow("src", WINDOW_AUTOSIZE);
		vector<Rect> faces, eyes; // 在using namespace std中
		faceCascade.detectMultiScale(imgGray, faces, 1.2, 5, 0, Size(30, 30));
		for (auto b : faces) {
			std::cout << "输出一张人脸位置：(x,y):" << "(" << b.x << "," << b.y << ") , (width,height):(" << b.width << "," << b.height << ")" << "\n";
		}
		if (faces.size() > 0) {
			for (size_t i = 0; i < faces.size(); i++) {
				putText(img, "ugly man!", cvPoint(faces[i].x, faces[i].y - 10), FONT_HERSHEY_PLAIN, 2.0, Scalar(0, 0, 255));

				rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 1, 8);
				std::cout << faces[i] << "\n";
				//将人脸从灰度图中抠出来
				Mat face_ = imgGray(faces[i]);
				eyes_Cascade.detectMultiScale(face_, eyes, 1.2, 2, 0, Size(30, 30));
				for (size_t j = 0; j < eyes.size(); j++) {
					Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
					int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
					circle(img, eye_center, radius, Scalar(65, 105, 255), 4, 8, 0);
				}
			}
		}
		imshow("src", img);
	}



	// 另一种方式
	// https://blog.csdn.net/li_wen01/article/details/78369751

	// 有趣的例子
	// https://blog.csdn.net/weixin_42142612/article/details/80804039

	// 活体检测



















};

