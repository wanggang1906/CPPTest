#include<iostream>
#include<string>
#include <opencv2/opencv.hpp>

// ����������
// #include <opencv/cv.h>
// #include <opencv/highgui.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>

#include<vector>


//#include "test40_opencv.h" // ������Զ����ɵ�

using namespace cv;
using namespace std;

class opencvTest {
public:
	// cv������
	void opencvMain() {
		
		int stature;
		std::string result;
		//stature = this->shwoImage();
		//stature = this->openCamera();
		std::cout << "ִ�н��" << stature << "\n";

		result = this->findHumanFace();
		std::cout << "ִ�н��" << result << "\n";
	}

	// ��ʾͼƬ
	int shwoImage() {
		Mat imageJpg = imread(".\\image\\01.jpg"); // .��ǰ�ļ����µ�·��������.. ����ʾ���ļ����µ�·��
		Mat imagePng = imread(".\\image\\02.png");
		Mat imageJpeg = imread(".\\image\\03.jpeg");
		bool a = false;
		a = imageJpg.empty(); // ͼƬ��data��zise,dimsΪ��ʱ�����ʾͼƬΪ�գ�������ʾ
		if (imageJpg.empty()) {

			printf("could not load image...\n");

			return -1;

		}

		namedWindow("test_opencv_setup-jpg", 0); // �½�����
		imshow("test_opencv_setup-jpg", imageJpg); // װ��ͼƬ

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

		// �ȴ�ʱ��
		waitKey(0);
		return 0;


	}

	// ������ͷ
	int openCamera() {

		namedWindow("Example", WINDOW_AUTOSIZE);
		VideoCapture cap;
		cap.open(0);
		// VideoCapture cap(0);��仰�����������������䣬Ч����һ�µġ�
		if (!cap.isOpened())
		{
			std::cout << "���ܴ�����ͷ������" << "\n";
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

	// ��ȡ��ƵΪͼ��
	void openVideo() {

		VideoCapture cap;
		cap.open("E://2.avi"); //����Ƶ,��������ȼ���VideoCapture cap("E://2.avi");
		
	     //cap.open("http://www.laganiere.name/bike.avi");//Ҳ����ֱ�Ӵ���ҳ�л�ȡͼƬ��ǰ������ҳ����Ƶ���Լ����ٹ���
		if (!cap.isOpened()) return; //�����Ƶ�����������򷵻�
		 Mat frame;
		 while (1)
		{
			 cap >> frame;//�ȼ���cap.read(frame);
			 if (frame.empty()) break; //���ĳ֡Ϊ�����˳�ѭ��
			 imshow("video", frame);
			 waitKey(20);//ÿ֡��ʱ20����
		}
		cap.release();//�ͷ���Դ
	}


	// �������
	// ��Դ
	// https://zhuanlan.zhihu.com/p/31852169
	// ���˼·��
	// �Ȱ�ͼƬתΪ�Ҷȣ����Ž�ͼƬֱ�����Ȼ��������洦����ͼƬ�����м����������Ȼ�������һ��Ȧ����ȥ����۾���
	std::string findHumanFace()
	{
		// opencv���е���
		CascadeClassifier faceCascade;
		CascadeClassifier eyes_Cascade;

		VideoCapture cap;
		if (!cap.open("C:\\Users\\cb\\Downloads\\b.mp4")) { // �����Ƶ�е�����
			std::cout << "����ͷ��ʧ��!!" << "\n";
			return "ʧ��";
		}
		if (!faceCascade.load(".\\model\\haarcascade_frontalface_alt2.xml")) { // ��������������
			std::cout << "������⼶��������û�ҵ�����" << "\n";
			return "ʧ��";
		}
		if (!eyes_Cascade.load(".\\model\\haarcascade_eye_tree_eyeglasses.xml")) { // �������۷�����
			std::cout << "�۾���⼶��������û�ҵ�����" << "\n";
			return "ʧ��";
		}
		Mat img, imgGray;
		int fps = 60; // ֡��
		while (true) {
			cap >> img;
			cvtColor(img, imgGray, CV_BGR2GRAY);
			equalizeHist(imgGray, imgGray);//ֱ��ͼ���Ȼ� - ֱ��ͼ���⻯
			this->DetectFace(img, imgGray, faceCascade, eyes_Cascade);

			waitKey(1000 / fps);
		}
		return 0;
	}

	void DetectFace(Mat img, Mat imgGray, CascadeClassifier faceCascade,CascadeClassifier eyes_Cascade) {

		// opencv���е���
		//CascadeClassifier faceCascade;
		//CascadeClassifier eyes_Cascade;

		namedWindow("src", WINDOW_AUTOSIZE);
		vector<Rect> faces, eyes; // ��using namespace std��
		faceCascade.detectMultiScale(imgGray, faces, 1.2, 5, 0, Size(30, 30));
		for (auto b : faces) {
			std::cout << "���һ������λ�ã�(x,y):" << "(" << b.x << "," << b.y << ") , (width,height):(" << b.width << "," << b.height << ")" << "\n";
		}
		if (faces.size() > 0) {
			for (size_t i = 0; i < faces.size(); i++) {
				putText(img, "ugly man!", cvPoint(faces[i].x, faces[i].y - 10), FONT_HERSHEY_PLAIN, 2.0, Scalar(0, 0, 255));

				rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 1, 8);
				std::cout << faces[i] << "\n";
				//�������ӻҶ�ͼ�пٳ���
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



	// ��һ�ַ�ʽ
	// https://blog.csdn.net/li_wen01/article/details/78369751

	// ��Ȥ������
	// https://blog.csdn.net/weixin_42142612/article/details/80804039

	// ������



















};

