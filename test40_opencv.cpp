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
		
		int stature = 0;
		std::string result;
		//stature = this->shwoImage();
		//stature = this->openCamera();
		//this->openVideo();
		stature = this->rgbOrGbr();
		std::cout << "ִ�н��" << stature << "\n";

		//result = this->findHumanFace();
		std::cout << "ִ�н����" << result << "\n";
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

		namedWindow("test_opencv_setup-jpg", 10); // �½�����,��������ʾ���ͣ���������һ��ö�١���ΪWINDOW_AUTOSIZE������Ӧͼ���С��
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
		cap.open(".\\image\\video\\v.mp4"); //����Ƶ,��������ȼ���VideoCapture cap("E://2.avi");
		
	     //cap.open("http://www.laganiere.name/bike.avi");//Ҳ����ֱ�Ӵ���ҳ�л�ȡͼƬ��ǰ������ҳ����Ƶ���Լ����ٹ���
		if (!cap.isOpened()) return; //�����Ƶ�����������򷵻�
		 Mat frame;
		 while (1)
		{
			 cap >> frame;//�ȼ���cap.read(frame);
			 if (frame.empty()) break; //���ĳ֡Ϊ�����˳�ѭ��
			 imshow("video", frame);
			 waitKey(50);//ÿ֡��ʱ20����
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
		CascadeClassifier faceCascade; // ����������
		CascadeClassifier eyes_Cascade;

		VideoCapture cap;
		if (!cap.open(".\\image\\video\\faceVideo.mp4")) { // �����Ƶ�е�����
			std::cout << "����ͷ��ʧ��!!" << "\n";
			return "����ͷ��ʧ��";
		}
		if (!faceCascade.load(".\\model\\haarcascade_frontalface_alt2.xml")) { // ��������������
			std::cout << "������⼶��������û�ҵ�����" << "\n";
			return "��������������ʧ��";
		}
		if (!eyes_Cascade.load(".\\model\\haarcascade_eye_tree_eyeglasses.xml")) { // �������۷�����
			std::cout << "�۾���⼶��������û�ҵ�����" << "\n";
			return "�������۷�����ʧ��";
		}
		Mat img, imgGray;
		int fps = 60; // ֡��
		while (true) {
			cap >> img;
			if (img.empty()) break;
			else
			{
				cvtColor(img, imgGray, CV_BGR2GRAY);
				equalizeHist(imgGray, imgGray);//ֱ��ͼ���Ȼ� - ֱ��ͼ���⻯
				this->DetectFace(img, imgGray, faceCascade, eyes_Cascade);
				waitKey(1000 / fps); // �ȴ����ɺ����رմ��ڣ���Ϊ0��()����һֱ�ȴ�
			}
		}
		cap.release(); // �ͷ���Դ
		return "�ɹ�";
	}

	void DetectFace(Mat img, Mat imgGray, CascadeClassifier faceCascade,CascadeClassifier eyes_Cascade) {

		// opencv���е���
		//CascadeClassifier faceCascade;
		//CascadeClassifier eyes_Cascade;

		namedWindow("src", WINDOW_AUTOSIZE); // ԭʼͼ����
		namedWindow("gray_face", WINDOW_AUTOSIZE); // �Ҷ�ͼ����
		namedWindow("binary_face", WINDOW_AUTOSIZE); // ��ֵͼ����
		vector<Rect> faces, eyes; // ��using namespace std�У�Ҳ��ͨ�� #include<vector>����

		faceCascade.detectMultiScale(imgGray, faces, 1.2, 5, 0, Size(30, 30)); // ���Ĳ�������ʾ��ķ�Χ

		for (auto b : faces) { // auto�ı����������ɱ������Ƶ��ĳ���
			// x,y���������½ǵ�����
			std::cout << "���һ������λ�ã�(x,y):" << "(" << b.x << "," << b.y << ") , (���,�߶�):(" << b.width << "," << b.height << ")" << "\n";
		}
		
		// ��ÿһ֡�ϰѼ�⵽��������ǳ���
		if (faces.size() > 0) {
			for (size_t i = 0; i < faces.size(); i++) { // size_t ��size type��������Ǳ�ʾ��С���͵�����������int��long
				putText(img, "big face !!!", cvPoint(faces[i].x, faces[i].y - 10), FONT_HERSHEY_PLAIN, 2.0, Scalar(0, 0, 255));

				// ���ƾ���
				// Point�ǵ��ģ���࣬Scalar����ɫ��ģ���࣬��һ������
				rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 1, 8);
				std::cout << faces[i] << "\n";

				// �������ӻҶ�ͼ�пٳ���
				Mat face_ = imgGray(faces[i]);
				Mat result;
				imshow("gray_face", face_); // ��ʾ�Ҷ�ͼ
				eyes_Cascade.detectMultiScale(face_, eyes, 1.2, 2, 0, Size(30, 30));

				threshold(face_, result, 170, 255, CV_THRESH_BINARY); // ��face_���ж�ֵ���������resule��
				imshow("binary_face", result);
				for (size_t j = 0; j < eyes.size(); j++) {

					// ����������
					Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
					int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
					circle(img, eye_center, radius, Scalar(65, 105, 255), 4, 8, 0);
				}
			}
		}
		imshow("src", img); // ���ԭͼ
	}



	// ��һ�ַ�ʽ
	// https://blog.csdn.net/li_wen01/article/details/78369751

	// ��Ȥ������
	// https://blog.csdn.net/weixin_42142612/article/details/80804039
	// ���ؿ��ӻ����
	// https://blog.csdn.net/u011574296/article/details/73286820
	int rgbOrGbr()
	{
		cv::Mat src = cv::imread(".\\image\\face\\fa01.jpeg", 1);
		if (src.empty() || src.channels() != 3)
		{
			cout << "Source image load error!" << endl;
			return -1;
		}

		//����CV_BGR2GRAY,ת����ʽGray = 0.1140*B + 0.5870*G + 0.2989*R
		cv::Mat bgr2grayImg;
		cvtColor(src, bgr2grayImg, CV_BGR2GRAY);

		//����CV_RGB2GRAY,ת����ʽGray = 0.1140*R + 0.5870*G + 0.2989*B
		cv::Mat rgb2grayImg;
		cvtColor(src, rgb2grayImg, CV_RGB2GRAY);

		//����CV_GRAY2BGR,ת����ʽB = G = R = Gray
		cv::Mat gray2bgrImg;
		cvtColor(bgr2grayImg, gray2bgrImg, CV_GRAY2BGR);

		//����CV_GRAY2RGB,ת����ʽR = G = B = Gray
		cv::Mat gray2rgbImg;
		cvtColor(rgb2grayImg, gray2rgbImg, CV_GRAY2RGB);

		waitKey(0);
		return 0;
	}

	// ������



















};

