
#include <fstream>
#include <iostream>

using namespace std;

/**
��txt�ļ��ж�ȡ�ַ����������Ļ
*/
int main2()
{
	printf("hao");
	cout << "hao";
	ofstream out;
	// ofstream�������������Ļ���,�����ռ����Ϊstd

	out << "��ʼִ��" << endl;
	out.open("1.txt"); // ���ļ�

	if (!out)
	{
		cerr << "�ļ���ʧ��" << endl;
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		out << i;
		cout << i; // ��Ļ���
		out << "ѭ�����" << endl;
	}
	out << endl;
	out.close();
	return 0;
}




int m2()
{
	cout << "д���ļ�" << endl;
	ifstream in;

	in.open("1.txt");

	if (!in)
	{
		cerr << "�ļ���ʧ��" << endl;
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

// �ַ���������룬���ļ�д��
int m3()
{
	using namespace std;

	char automobile[50];
	int year;
	double a_price;
	double d_price;

	// wg�Զ���
	int s;

	ofstream outfile; // �ļ�������

	outfile.open("E:/Cpp/XIANGMU/VisualStudio/01CppProject/CPPTest/m3.txt");//ע��,����ʹ��"/"������"\"
	//outfile.open("carinfo.txt");
	cout << "Enter the make and model of automobile:����������������ݺ��ͺ�";

	cin.getline(automobile, 50); // ��ʲô���ܼ������룿������


	cout << "Enter the model year:�������";
	cin >> year; // �Ѽ�����������year������
	cout << year << endl;
	cout << "Enter the original asking price:����۸�";
	cin >> a_price;
	d_price = 0.913 * a_price;

	cout << fixed;//cout<<fixed����һ���ʽ�����ǿ�ѧ���������������
	cout.precision(4);//�����������ʾ�����������ָ���

	// ����С�����ȣ���λ��
	cout.setf(ios_base::showpoint);//��ʾ���һλС�������0;
	cout << "Make and model:�������" << automobile << endl;
	cout << "Year:" << year << endl;
	cout << "Was asking 's" << a_price << endl;
	cout << "Now asking 's" << d_price << endl;

	// ������ļ�
	outfile << fixed;//fixedδ�����壬��ô����fix��ʲô?
	outfile.precision(2);
	outfile.setf(ios_base::showpoint);
	outfile << "Make and model:" << automobile << endl;
	outfile << "Year:" << year << endl;
	outfile << "Was asking 's" << a_price << endl;
	outfile << "Now asking 's" << d_price << endl;
	outfile.close();
	system("pause"); // ����̨ͣ����������
	return 0;
}



