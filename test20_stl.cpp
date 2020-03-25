#include <string>

#include <iostream>
#include <vector>
#include<algorithm> // sort
#include<functional>

#include<cstdlib> // abort()
#include<cstdio> // snprintf()
#include<ctime>
#include<stdexcept>

#include<array>



// �̳���ַ
// http://c.biancheng.net/stl/

// STL�������ļ��ϣ�Ҳ������ļ��ϡ�
// ��������list, vector����, set, map ��
// ����������������������㷨���º���
// ���� - �洢������ĳ�����ļ��ϡ�������Ϊ���������͹�������
// ������ - ��һ������Ⱥ�Ͻ��б����������������࣬˫��������������ȡ������
// �㷨 - �㷨���ڴ���Ⱥ�ڵ�Ԫ�أ���ʵ����Ѱ�������޸ģ�ʹ��
// �º��� - ���з��ͱ��ǿ����������Ǵ���������֤


using namespace std;
const int NUM = 5;
int tVector()
{
	// ����
	vector <string>names(NUM);    //����ʸ������
	vector <int> sexs(NUM);    //ͬ��
	cout << "Please Do Exactly As Told You Will enter \n" << NUM << " Personal Name and Their Sex.\n";
	int i = 0;
	for (i = 0; i < NUM; i++)    //������Ϣ
	{
		cout << "Enter title # " << i + 1 << ": ";
		getline(cin, names[i]); //��ȡ������Ϣ
		cout << "Enter sex (0/1) #";
		cin >> sexs[i];    //��ȡ������Ϣ
		cin.get();    //�ȴ�
	}
	cout << "Thank you. You entered the following:    \n" << "name/sex" << endl;
	for (i = 0; i < NUM; i++)    //�����Ϣ
	{
		cout << names[i] << "\t" << sexs[i] << endl;
	}
	return 0;
}


// stl�ۺ�ʹ��
int stlUse()
{
	int ia[6] = {};
	vector<int, allocator<int>> vi(ia, ia + 6);
	std::cout << count_if(vi.begin(), vi.end(),
		not1(bind2nd(less<int>(), 40)));
	return 0;
}

// ��������
void testVector(long& value)
{
	cout << "����";
	vector<string> c;
	char buf[10];
	clock_t timeStart = clock(); // ��ʱ����

	for (long  i = 0; i < value; ++i)
	{
		try {
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));
		}
		catch (exception & p) {
			cout << i << p.what() << endl;
			abort();
		}
	}
	// ���õķ���
	cout << (clock() - timeStart) << endl;
	cout << c.size() << endl;
	cout << c.front() << endl;
	cout << c.back() << endl;
	cout << c.data() << endl;
	cout << c.capacity() << endl;
}


// 
void testArray()
{
#define ASIZE 10;
	cout << "";
	array<long, 10> c;
	clock_t timeStart = clock();
	for (long i = 0; i < 10; ++i) {
		c[i] = rand();
	}

	//
	cout << (clock() - timeStart) << endl;
	cout << c.size() << endl;
	cout << c.front() << endl;
	cout << c.back() << endl;
	cout << c.data() << endl;

	long target;
	timeStart = clock();
	//qsort(c.data(), 10, sizeof(long), compareLongs);
	//long* pItem = (long*)bsearch(&target, (c.data(), 10, sizeof(long));
	//cout << (clock() - timeStart) << endl;
	//if (pItem != NULL)
	//	cout << *pItem << endl;
	//else
	//	cout << "not found" << endl;
}