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

//#define CASCADENAME			".\\model\\haarcascade_frontalface_alt2.xml"
//#define NESTEDCASCADENAME	".\\model\\haarcascade_eye_tree_eyeglasses.xml"
//#define FACEPHOTO_FACENAME  ".\\image\\face\\fa01.jpeg"
//#define DETECT_IMAGE		".\\image\\face\\fa02.jpeg"

public:
	// cv������
	void opencvMain() {
		
		int stature = 0;
		std::string result = "��ʼ��";
		//stature = this->shwoImage();
		//stature = this->openCamera();
		//this->openVideo();
		//stature = this->rgbOrGbr();
		stature = this->findMultFace();
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




	int findMultFace()
	{
		// �궨��ɷ��ڷ������ڣ������С������
		#define CASCADENAME			".\\model\\haarcascade_frontalface_alt2.xml"
		#define NESTEDCASCADENAME	".\\model\\haarcascade_eye_tree_eyeglasses.xml"
		#define FACEPHOTO_FACENAME  ".\\image\\face\\fa01.jpeg" // ����ͼû�õ�
		#define DETECT_IMAGE		".\\image\\face\\fa02.jpeg"

		Mat frame, image;
		bool tryflip = true;
		CascadeClassifier cascade, nestedCascade;
		double scale = 1.3;

		/* ���ط����� */
		if (!nestedCascade.load(NESTEDCASCADENAME))
		{
			cerr << "WARNING: Could not load classifier cascade for nested objects" << endl;
		}
		if (!cascade.load(CASCADENAME))
		{
			cerr << "ERROR: Could not load classifier cascade" << endl;
			return -1;
		}

		/* ����ͼƬ */
		image = imread(DETECT_IMAGE, 1);
		if (image.empty())
		{
			cout << "Couldn't read iamge" << DETECT_IMAGE << endl;

		}

		cout << "Detecting face(s) in " << DETECT_IMAGE << endl;

		/* ����������۾���������⵽������ */
		if (!image.empty())
		{
			// ��Σ�ͼƬ������������ʶ�����棬ͼƬ��С������
			this->detectAndDraw(image, cascade, nestedCascade, scale, tryflip);
			waitKey(0);
		}
		return 0;
	}

	// ���ͱ��
	void detectAndDraw(Mat& img, CascadeClassifier& cascade,
		CascadeClassifier& nestedCascade, double scale, bool tryflip)
	{
		double t = 0;
		vector<Rect> faces, faces2;
		/* ����������ɫ����������� */
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

		/* ��Ϊ�õ�����haar���������Զ��ǻ��ڻҶ�ͼ��ģ�����Ҫת���ɻҶ�ͼ�� */
		cvtColor(img, gray, COLOR_BGR2GRAY);

		/* ��ͼƬ��С���ӿ����ٶ� */
		double fx = 1 / scale;
		/* ���ߴ���С��1/scale, �����Բ�ֵ */
		resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR);
		/* ֱ��ͼ���⻯ */
		equalizeHist(smallImg, smallImg);

		/* ���������㷨ִ��ʱ�� */
		t = (double)getTickCount(); // �õ�ʱ�Ӽ���ʱ��

		/*detectMultiScale - ������⺯�����ɼ���ͼƬ����������������vector�������������λ�ã���С(�þ��α�ʾ)
			smallImg�������ԭͼ
			faces	����ʾ��⵽������Ŀ������
			1.1		��ÿ��ͼ��ߴ��С�ı���Ϊ1.1
			3		��ÿһ��Ŀ������Ҫ����⵽3�β��������Ŀ��
			CV_HAAR_SCALE_IMAGE����ʾ�������ŷ���������⣬��������ͼ��
			Size(30, 30) Ŀ��������С�ߴ�
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

		/* ���Ϊ�㷨ִ�е�ʱ�� */
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

			/* ���������������0.75-1.3 �仭Բ��������Χ������ */
			double aspect_ratio = (double)r.width / r.height;
			if (0.75 < aspect_ratio && aspect_ratio < 1.3)
			{
				/*��ԭԭ���ߴ� ����Բ�ĺ�Բ�뾶 */
				center.x = cvRound((r.x + r.width * 0.5) * scale);
				center.y = cvRound((r.y + r.height * 0.5) * scale);
				radius = cvRound((r.width + r.height) * 0.25 * scale);
				/* ��������������� ��Բ */
				circle(img, center, radius, color, 3, 8, 0);
			}
			else
			{
				/* ����������򣬻����� */
				rectangle(img, cvPoint(cvRound(r.x * scale), cvRound(r.y * scale)),
					cvPoint(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)), color, 3, 8, 0);
			}

			/* ��⵽���ۣ��������ϻ������� */
			if (nestedCascade.empty())
			{
				continue;
			}

			smallImgROI = smallImg(r);

			/* ���ۼ�� */
			nestedCascade.detectMultiScale(smallImgROI, nestedObjects, 1.1, 2, CASCADE_SCALE_IMAGE, Size(30, 30));
			for (size_t j = 0; j < nestedObjects.size(); j++)
			{
				Rect nr = nestedObjects[j];
				/*��ԭԭ���ߴ� ����Բ�ĺ�Բ�뾶 */
				center.x = cvRound((r.x + nr.x + nr.width * 0.5) * scale);
				center.y = cvRound((r.y + nr.y + nr.height * 0.5) * scale);
				radius = cvRound((nr.width + nr.height) * 0.25 * scale);
				/* �������ۼ������ ��Բ*/
				circle(img, center, radius, color, 3, 8, 0);
			}
		}
		/* ��ʾͼ�� img */
		imshow("result", img);
	}


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

