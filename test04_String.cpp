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










