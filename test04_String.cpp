#include <iostream>
#include <string>

using namespace std;

int testString() {

	std::string str; // �ַ�����һ��������C++��׼���У����ܷǳ��࣬����ȡ���Ƚϣ������ַ���

	cout << "����һ���ַ���";
	std::getline(std::cin,str);
	cout << str;
	return 0;
}


// ָ��
// ָ��������Ǵ�ŵ�ַ
// ����ָ���ǿո�Ӱ�죬��int *p; int * p; int* p;��ͬ
// *��������;��@1-����ָ�롣@2-��ָ����н�����
// ������ָ��ָ����ͬ��ֵ����ͬ���ı�
// ֧��������ָ�룬��void *vPointer������Ӧ��ǰҪת��Ϊ�ʵ�����������
int pointerTest()
{
	const unsigned short ITEM = 5;
	int intArray[ITEM] = { 1,2,3,4,5 };
	char charArray[ITEM] = { 'f','i','s','a','q' };

	int* intPtr = intArray;
	char* charPtr = charArray;
	std::cout << "�����������" << '\n';
	for (int i = 0; i < ITEM; i++)
	{
		// reinterpret_cast<unsigned long>()�ǶԵ�ַ����ǿ��ת��
		std::cout << *intPtr << " at " << reinterpret_cast<unsigned long>(intPtr)
			<< '\n';
		intPtr++;

	}
	std::cout << "�ַ����������" << '\n';
	for (int i = 0; i < ITEM; i++)
	{
		std::cout << *charPtr << " at " << reinterpret_cast<unsigned long>(charPtr)
			<< '\n';
		charPtr++;
	}
	return 0;
}


// �������ͼ�����ռ�ڴ�ռ��С
void dataSize() {
	// ������������
	int a;
	float b;
	double c;
	bool d;
	char e;
	void; // ������
	wchar_t i; // ���ַ���
	//std::cout<< 

	// ������������
	cout << "type: \t\t" << "************size**************" << endl;
	cout << "bool: \t\t" << "��ռ�ֽ�����" << sizeof(bool);
	cout << "\t���ֵ��" << (numeric_limits<bool>::max)(); // numeric_limits��C++��ģ���࣬�ṩ�������ݵļ�ֵ����ѧ��Ϣ�����е�max,min�Ǻ곣��
	cout << "\t\t��Сֵ��" << (numeric_limits<bool>::min)() << endl;

	cout << "char: \t\t" << "��ռ�ֽ�����" << sizeof(char);
	cout << "\t���ֵ��" << (numeric_limits<char>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<char>::min)() << endl;

	cout << "signed char: \t" << "��ռ�ֽ�����" << sizeof(signed char);
	cout << "\t���ֵ��" << (numeric_limits<signed char>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<signed char>::min)() << endl;

	cout << "unsigned char: \t" << "��ռ�ֽ�����" << sizeof(unsigned char);
	cout << "\t���ֵ��" << (numeric_limits<unsigned char>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<unsigned char>::min)() << endl;

	cout << "wchar_t: \t" << "��ռ�ֽ�����" << sizeof(wchar_t);
	cout << "\t���ֵ��" << (numeric_limits<wchar_t>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<wchar_t>::min)() << endl;

	cout << "short: \t\t" << "��ռ�ֽ�����" << sizeof(short);
	cout << "\t���ֵ��" << (numeric_limits<short>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<short>::min)() << endl;

	cout << "int: \t\t" << "��ռ�ֽ�����" << sizeof(int);
	cout << "\t���ֵ��" << (numeric_limits<int>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<int>::min)() << endl;

	cout << "unsigned: \t" << "��ռ�ֽ�����" << sizeof(unsigned);
	cout << "\t���ֵ��" << (numeric_limits<unsigned>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<unsigned>::min)() << endl;

	cout << "long: \t\t" << "��ռ�ֽ�����" << sizeof(long);
	cout << "\t���ֵ��" << (numeric_limits<long>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<long>::min)() << endl;

	cout << "unsigned long: \t" << "��ռ�ֽ�����" << sizeof(unsigned long);
	cout << "\t���ֵ��" << (numeric_limits<unsigned long>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<unsigned long>::min)() << endl;

	cout << "double: \t" << "��ռ�ֽ�����" << sizeof(double);
	cout << "\t���ֵ��" << (numeric_limits<double>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<double>::min)() << endl;

	cout << "long double: \t" << "��ռ�ֽ�����" << sizeof(long double);
	cout << "\t���ֵ��" << (numeric_limits<long double>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<long double>::min)() << endl;

	cout << "float: \t\t" << "��ռ�ֽ�����" << sizeof(float);
	cout << "\t���ֵ��" << (numeric_limits<float>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<float>::min)() << endl;

	cout << "size_t: \t" << "��ռ�ֽ�����" << sizeof(size_t);
	cout << "\t���ֵ��" << (numeric_limits<size_t>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<size_t>::min)() << endl;

	cout << "string: \t" << "��ռ�ֽ�����" << sizeof(string);
	cout << "\t���ֵ��" << (numeric_limits<string>::max)();
	cout<< "\t��Сֵ��" << (numeric_limits<string>::min)() << endl;  

	cout << "type: \t\t" << "************size**************" << endl;
}










