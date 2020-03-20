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

//#define CASCADENAME			".\\model\\haarcascade_frontalface_alt2.xml"
//#define NESTEDCASCADENAME	".\\model\\haarcascade_eye_tree_eyeglasses.xml"
//#define FACEPHOTO_FACENAME  ".\\image\\face\\fa01.jpeg"
//#define DETECT_IMAGE		".\\image\\face\\fa02.jpeg"

public:
	// cv主函数
	void opencvMain() {
		
		int stature = 0;
		std::string result = "初始化";
		//stature = this->shwoImage();
		//stature = this->openCamera();
		//this->openVideo();
		//stature = this->rgbOrGbr();
		stature = this->findMultFace();
		std::cout << "执行结果" << stature << "\n";

		//result = this->findHumanFace();

		std::cout << "执行结果：" << result << "\n";
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

		namedWindow("test_opencv_setup-jpg", 10); // 新建窗口,并设置显示类型，其类型是一个枚举。若为WINDOW_AUTOSIZE则自适应图像大小。
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
		cap.open(".\\image\\video\\v.mp4"); //打开视频,以上两句等价于VideoCapture cap("E://2.avi");
		
	     //cap.open("http://www.laganiere.name/bike.avi");//也可以直接从网页中获取图片，前提是网页有视频，以及网速够快
		if (!cap.isOpened()) return; //如果视频不能正常打开则返回
		 Mat frame;
		 while (1)
		{
			 cap >> frame;//等价于cap.read(frame);
			 if (frame.empty()) break; //如果某帧为空则退出循环
			 imshow("video", frame);
			 waitKey(50);//每帧延时20毫秒
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
		CascadeClassifier faceCascade; // 人脸分类器
		CascadeClassifier eyes_Cascade;

		VideoCapture cap;
		if (!cap.open(".\\image\\video\\faceVideo.mp4")) { // 检测视频中的人脸
			std::cout << "摄像头打开失败!!" << "\n";
			return "摄像头打开失败";
		}
		if (!faceCascade.load(".\\model\\haarcascade_frontalface_alt2.xml")) { // 加载人脸分类器
			std::cout << "人脸检测级联分类器没找到！！" << "\n";
			return "加载人脸分类器失败";
		}
		if (!eyes_Cascade.load(".\\model\\haarcascade_eye_tree_eyeglasses.xml")) { // 加载人眼分类器
			std::cout << "眼睛检测级联分类器没找到！！" << "\n";
			return "加载人眼分类器失败";
		}
		Mat img, imgGray;
		int fps = 60; // 帧数
		while (true) {
			cap >> img;
			if (img.empty()) break;
			else
			{
				cvtColor(img, imgGray, CV_BGR2GRAY);
				equalizeHist(imgGray, imgGray);//直方图均匀化 - 直方图均衡化
				this->DetectFace(img, imgGray, faceCascade, eyes_Cascade);
				waitKey(1000 / fps); // 等待若干毫秒后关闭窗口，若为0或()，则一直等待
			}
		}
		cap.release(); // 释放资源
		return "成功";
	}

	void DetectFace(Mat img, Mat imgGray, CascadeClassifier faceCascade,CascadeClassifier eyes_Cascade) {

		// opencv库中的类
		//CascadeClassifier faceCascade;
		//CascadeClassifier eyes_Cascade;

		namedWindow("src", WINDOW_AUTOSIZE); // 原始图窗口
		namedWindow("gray_face", WINDOW_AUTOSIZE); // 灰度图窗口
		namedWindow("binary_face", WINDOW_AUTOSIZE); // 二值图窗口
		vector<Rect> faces, eyes; // 在using namespace std中，也可通过 #include<vector>引入

		faceCascade.detectMultiScale(imgGray, faces, 1.2, 5, 0, Size(30, 30)); // 检测的参数，表示框的范围

		for (auto b : faces) { // auto的变量类型是由编译器推导的出的
			// x,y是人脸左下角的坐标
			std::cout << "输出一张人脸位置：(x,y):" << "(" << b.x << "," << b.y << ") , (宽度,高度):(" << b.width << "," << b.height << ")" << "\n";
		}
		
		// 在每一帧上把检测到的人脸标记出来
		if (faces.size() > 0) {
			for (size_t i = 0; i < faces.size(); i++) { // size_t 是size type，保存的是表示大小类型的整数，类似int，long
				putText(img, "big face !!!", cvPoint(faces[i].x, faces[i].y - 10), FONT_HERSHEY_PLAIN, 2.0, Scalar(0, 0, 255));

				// 绘制矩形
				// Point是点的模板类，Scalar是颜色的模板类，是一个向量
				rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 1, 8);
				std::cout << faces[i] << "\n";

				// 将人脸从灰度图中抠出来
				Mat face_ = imgGray(faces[i]);
				Mat result;
				imshow("gray_face", face_); // 显示灰度图
				eyes_Cascade.detectMultiScale(face_, eyes, 1.2, 2, 0, Size(30, 30));

				threshold(face_, result, 170, 255, CV_THRESH_BINARY); // 把face_进行二值化后输出到resule中
				imshow("binary_face", result);
				for (size_t j = 0; j < eyes.size(); j++) {

					// 级联分类器
					Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
					int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
					circle(img, eye_center, radius, Scalar(65, 105, 255), 4, 8, 0);
				}
			}
		}
		imshow("src", img); // 输出原图
	}



	// 另一种方式
	// https://blog.csdn.net/li_wen01/article/details/78369751




	int findMultFace()
	{
		// 宏定义可放在方法体内，但会减小作用域
		#define CASCADENAME			".\\model\\haarcascade_frontalface_alt2.xml"
		#define NESTEDCASCADENAME	".\\model\\haarcascade_eye_tree_eyeglasses.xml"
		#define FACEPHOTO_FACENAME  ".\\image\\face\\fa01.jpeg" // 这张图没用到
		#define DETECT_IMAGE		".\\image\\face\\fa02.jpeg"

		Mat frame, image;
		bool tryflip = true;
		CascadeClassifier cascade, nestedCascade;
		double scale = 1.3;

		/* 加载分类器 */
		if (!nestedCascade.load(NESTEDCASCADENAME))
		{
			cerr << "WARNING: Could not load classifier cascade for nested objects" << endl;
		}
		if (!cascade.load(CASCADENAME))
		{
			cerr << "ERROR: Could not load classifier cascade" << endl;
			return -1;
		}

		/* 加载图片 */
		image = imread(DETECT_IMAGE, 1);
		if (image.empty())
		{
			cout << "Couldn't read iamge" << DETECT_IMAGE << endl;

		}

		cout << "Detecting face(s) in " << DETECT_IMAGE << endl;

		/* 检测人脸及眼睛并画出检测到的区域 */
		if (!image.empty())
		{
			// 入参：图片，人脸，人眼识别引擎，图片缩小比例，
			this->detectAndDraw(image, cascade, nestedCascade, scale, tryflip);
			waitKey(0);
		}
		return 0;
	}

	// 检测和标记
	void detectAndDraw(Mat& img, CascadeClassifier& cascade,
		CascadeClassifier& nestedCascade, double scale, bool tryflip)
	{
		double t = 0;
		vector<Rect> faces, faces2;
		/* 定义七种颜色用于人脸标记 */
		const static Scalar colors[] =
		{
			Scalar(255,0,0),
			Scalar(255,128,0),
			Scalar(255,255,0),
			Scalar(0,255,0),
			Scalar(0,128,255),
			Scalar(0,255,255),
			Scalar(0,0,255),
			Scalar(255,0,255)
		};

		Mat gray, smallImg;

		/* 因为用的是类haar特征，所以都是基于灰度图像的，这里要转换成灰度图像 */
		cvtColor(img, gray, COLOR_BGR2GRAY);

		/* 将图片缩小，加快检测速度 */
		double fx = 1 / scale;
		/* 将尺寸缩小到1/scale, 用线性插值 */
		resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR);
		/* 直方图均衡化 */
		equalizeHist(smallImg, smallImg);

		/* 用来计算算法执行时间 */
		t = (double)getTickCount(); // 得到时钟计数时间

		/*detectMultiScale - 人脸检测函数，可检测出图片中所有人脸，并用vector保存各个人脸的位置，大小(用矩形表示)
			smallImg：输入的原图
			faces	：表示检测到的人脸目标序列
			1.1		：每次图像尺寸减小的比例为1.1
			3		：每一个目标至少要被检测到3次才算是真的目标
			CV_HAAR_SCALE_IMAGE：表示不是缩放分类器来检测，而是缩放图像
			Size(30, 30) 目标的最大最小尺寸
		*/
		cascade.detectMultiScale(smallImg, faces, 1.1, 3, CASCADE_SCALE_IMAGE, Size(30, 30));
		if (tryflip)
		{
			flip(smallImg, smallImg, 1);
			cascade.detectMultiScale(smallImg, faces2, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
			for (vector<Rect>::const_iterator r = faces2.begin(); r != faces2.end(); ++r)
			{
				faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
			}
		}

		/* 相减为算法执行的时间 */
		t = (double)getTickCount() - t;
		printf("detection time = %g ms\n", t * 1000 / getTickFrequency());

		for (size_t i = 0; i < faces.size(); i++)
		{
			Rect r = faces[i];
			Mat smallImgROI;
			vector<Rect> nestedObjects;
			Point center;
			Scalar color = colors[i % 8];
			int radius;

			/* 人脸长宽比例，在0.75-1.3 间画圆，其他范围画矩形 */
			double aspect_ratio = (double)r.width / r.height;
			if (0.75 < aspect_ratio && aspect_ratio < 1.3)
			{
				/*还原原来尺寸 计算圆心和圆半径 */
				center.x = cvRound((r.x + r.width * 0.5) * scale);
				center.y = cvRound((r.y + r.height * 0.5) * scale);
				radius = cvRound((r.width + r.height) * 0.25 * scale);
				/* 画出人脸检测区域 画圆 */
				circle(img, center, radius, color, 3, 8, 0);
			}
			else
			{
				/* 画出检测区域，画矩形 */
				rectangle(img, cvPoint(cvRound(r.x * scale), cvRound(r.y * scale)),
					cvPoint(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)), color, 3, 8, 0);
			}

			/* 检测到人眼，在人脸上画出人眼 */
			if (nestedCascade.empty())
			{
				continue;
			}

			smallImgROI = smallImg(r);

			/* 人眼检测 */
			nestedCascade.detectMultiScale(smallImgROI, nestedObjects, 1.1, 2, CASCADE_SCALE_IMAGE, Size(30, 30));
			for (size_t j = 0; j < nestedObjects.size(); j++)
			{
				Rect nr = nestedObjects[j];
				/*还原原来尺寸 计算圆心和圆半径 */
				center.x = cvRound((r.x + nr.x + nr.width * 0.5) * scale);
				center.y = cvRound((r.y + nr.y + nr.height * 0.5) * scale);
				radius = cvRound((nr.width + nr.height) * 0.25 * scale);
				/* 画出人眼检测区域 画圆*/
				circle(img, center, radius, color, 3, 8, 0);
			}
		}
		/* 显示图像 img */
		imshow("result", img);
	}


	// 有趣的例子
	// https://blog.csdn.net/weixin_42142612/article/details/80804039
	// 像素可视化插件
	// https://blog.csdn.net/u011574296/article/details/73286820
	int rgbOrGbr()
	{
		cv::Mat src = cv::imread(".\\image\\face\\fa01.jpeg", 1);
		if (src.empty() || src.channels() != 3)
		{
			cout << "Source image load error!" << endl;
			return -1;
		}

		//采用CV_BGR2GRAY,转换公式Gray = 0.1140*B + 0.5870*G + 0.2989*R
		cv::Mat bgr2grayImg;
		cvtColor(src, bgr2grayImg, CV_BGR2GRAY);

		//采用CV_RGB2GRAY,转换公式Gray = 0.1140*R + 0.5870*G + 0.2989*B
		cv::Mat rgb2grayImg;
		cvtColor(src, rgb2grayImg, CV_RGB2GRAY);

		//采用CV_GRAY2BGR,转换公式B = G = R = Gray
		cv::Mat gray2bgrImg;
		cvtColor(bgr2grayImg, gray2bgrImg, CV_GRAY2BGR);

		//采用CV_GRAY2RGB,转换公式R = G = B = Gray
		cv::Mat gray2rgbImg;
		cvtColor(rgb2grayImg, gray2rgbImg, CV_GRAY2RGB);

		waitKey(0);
		return 0;
	}

	// 活体检测



















};

