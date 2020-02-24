
#include <fstream>
#include <iostream>

using namespace std;

/**
从txt文件中读取字符，输出到屏幕
*/
int main2()
{
	printf("hao");
	cout << "hao";
	ofstream out;
	// ofstream是所有流操作的基类,命名空间必须为std

	out << "开始执行" << endl;
	out.open("1.txt"); // 打开文件

	if (!out)
	{
		cerr << "文件打开失败" << endl;
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		out << i;
		cout << i; // 屏幕输出
		out << "循环输出" << endl;
	}
	out << endl;
	out.close();
	return 0;
}




int m2()
{
	cout << "写入文件" << endl;
	ifstream in;

	in.open("1.txt");

	if (!in)
	{
		cerr << "文件打开失败" << endl;
		return 0;
	}
	char x;
	while (in >> x)
	{
		cout << x;
	}
	cout << endl;
	in.close();
	return 0;
}

// 字符的输出输入，和文件写入
int m3()
{
	using namespace std;

	char automobile[50];
	int year;
	double a_price;
	double d_price;

	// wg自定义
	int s;

	ofstream outfile; // 文件流操作

	outfile.open("E:/Cpp/XIANGMU/VisualStudio/01CppProject/CPPTest/m3.txt");//注意,这里使用"/"而不是"\"
	//outfile.open("carinfo.txt");
	cout << "Enter the make and model of automobile:输入汽车的制造年份和型号";

	cin.getline(automobile, 50); // 用什么接受键盘输入？？？？


	cout << "Enter the model year:制造年份";
	cin >> year; // 把键盘输入流到year？？？
	cout << year << endl;
	cout << "Enter the original asking price:最初价格";
	cin >> a_price;
	d_price = 0.913 * a_price;

	cout << fixed;//cout<<fixed是以一般格式而不是科学计数法输出浮点数
	cout.precision(4);//控制输出流显示浮点数的数字个数

	// 控制小数精度，即位数
	cout.setf(ios_base::showpoint);//显示最后一位小数后面的0;
	cout << "Make and model:制造年份" << automobile << endl;
	cout << "Year:" << year << endl;
	cout << "Was asking 's" << a_price << endl;
	cout << "Now asking 's" << d_price << endl;

	// 输出到文件
	outfile << fixed;//fixed未被定义，那么这里fix是什么?
	outfile.precision(2);
	outfile.setf(ios_base::showpoint);
	outfile << "Make and model:" << automobile << endl;
	outfile << "Year:" << year << endl;
	outfile << "Was asking 's" << a_price << endl;
	outfile << "Now asking 's" << d_price << endl;
	outfile.close();
	system("pause"); // 控制台停留，不闪退
	return 0;
}



