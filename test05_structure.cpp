#include<iostream>



// ������ǰ�� ������
//class StructClass;

class StructClass
{

private:
	// ����ṹ����������
	typedef struct info {
		std::string name;
		int age;
	};

	typedef struct infoName {
		int af;
	};
	
	// �ṹ�����Ҫ��ʼ��

	
public:
	void structureTestMain()
	{
		this->getStructureOfClass();
	}

	// �ṹ��
	// .�� -> ��������ṹ����ʱ��. ָ��ָ��ʱ�� -> 
	int structureTypeTest()
	{
		struct FishOil
		{
			std::string name; // �ַ�������
			int age;
			char sex;
		};
		return 0;
	}


	// ʹ�����еĽṹ��

	void getStructureOfClass()
	{
		struct info inf001 = { "",0 };
		inf001.name = "inf01";
		inf001.age = 10;
		std::cout << "�ṹ�����ĵ�ַ��" << &inf001 << "\n";

		//Inm02* inm002 = NULL;
		//inm002->af = 20;
		//std::cout << inm002->af << "\n";


	}

	// ����������
	void jiaoHuan()
	{
		int s = 1;
		int d = 2;
		//swap(&s, &d);
	}

	void swap(int* x, int* y) 
	{
		*x ^= *y;
		*y ^= *x; // ������
		*x ^= *y;
	}




};
