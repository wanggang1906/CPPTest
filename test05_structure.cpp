#include<iostream>


// �ṹ��
// .�� -> ��������ṹ����ʱ��. ָ��ָ��ʱ�� -> 
int structureTest()
{
	struct FishOil
	{
		std::string name; // �ַ�������
		int age;
		char sex;
	};
	return 0;
}


// ����������
void jiaoHuan() {
	int s = 1;
	int d = 2;
	//swap(&s, &d);
}

	void swap(int* x, int* y) {
		*x ^= *y;
		*y ^= *x; // ������
		*x ^= *y;
	}
