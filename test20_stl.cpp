#include <iostream>
#include <string>
#include <vector>


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
int main20()
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