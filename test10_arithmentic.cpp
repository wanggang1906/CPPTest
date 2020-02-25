// ���ݽṹ���㷨

#include<iostream>
#include<fstream>
#include<string>

class DataStructuresAndAlgorithms
{
public:
	// �㷨˼�룺
	// https://blog.csdn.net/weixin_41190227/article/details/86600821


/*
1.��������
˼�룺ɨ��δ����Ĳ�������õ������У�����O(1)�Ŀռ临�Ӷȣ����ź����Ԫ���������ƶ�
ʱ�临�Ӷȣ�ƽ��O(n2)�����O(n)���O(n2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ��ȶ�
*/
void insertSort(int a[], int n)
{
	std::cout << "�������� \n";
	int i, j, t;
	// ���źõ�����
	int sortList[7] = {}; // �����С�̶���������n����Ϊn��ֵ��ͨ��ָ��ı䣬�Ǳ���
	for (i = 1; i < n; i++) // ѭ�����ӵ�һ����ʼ����һ��Ĭ�����򣬴ӵڶ���Ԫ�ؿ�ʼ���в���
	{
		t = a[i];
		for (j = i - 1; j >= 0 && t < a[j]; --j)
		{
			a[j + 1] = a[j];
			a[j + 1] = t;
		}
		sortList[i] = a[i]; // i���ڴ��ַ
		std::cout << "������õ����У�" << sortList[i] << "\n";
	}
	std::cout << "����";
}

/*
2.ϣ������
ʱ�临�Ӷȣ�ƽ��O(n1.3)�����O(n)���O(n2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ�
*/
void shellSort(int a[], int n)
{
	int d, i, j, x;
	d = n / 2;//����
	while (d >= 1)//ѭ��������Ϊ1ʱ����
	{
		for (i = d; i < n; i++)
		{
			x = a[i];//��������һ������
			j = i - d;//������ǰһ�����ݵ����
			while (j >= 0 && a[j] > x)//��һ��������ǰһ����
			{
				a[j + d] = a[j];//����һ������ǰ�ƶ�
				j = j - d;//�޸���ţ�������ǰ�ƶ�
			}
			a[j + d] = x;//��������
		}
		d = d / 2;//��С����
	}
}


/*
3.ѡ������
ʱ�临�Ӷȣ�ƽ��O(n2)�����O(n2)���O(n2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ�
*/
void selectSort(int a[], int n)
{
	int t, k;
	for (int i = 0; i < n - 1; i++)
	{
		k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[k] > a[j])
				k = j;
		}
		t = a[i];
		a[i] = a[k];
		a[k] = t;
	}
}


/*
4.������
ʱ�临�Ӷȣ�ƽ��O(nlogn)�����O(nlogn)���O(nlogn)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ�
*/
void createHeap(int a[], int s, int n)
{
	//���ɶ�
	//s���ڵ����
	//����
	int j, t;
	while (2 * s + 1 < n)//��s���ڵ���������
	{
		j = 2 * s + 1;
		if ((j + 1) < n)
		{
			if (a[j] < a[j + 1])//������С������������Ҫ�Ƚ�������
				j++;
		}
		if (a[s] < a[j])
		{
			t = a[s];
			a[s] = a[j];
			a[j] = t;
			s = j;//�ѱ��ƻ�����Ҫ���µ���
		}
		else
		{
			break;
		}
	}
}
void heapSort(int a[], int n)
{
	int t;
	int j;
	for (int i = n / 2 - 1; i >= 0; i--)//��a[0,n-1]���ɴ����
	{
		createHeap(a, i, n);
	}
	for (int i = n - 1; i > 0; i--)
	{
		t = a[0];//���i����¼����
		a[0] = a[i];
		a[i] = t;
		createHeap(a, 0, i);//��a[0]��a[i]���µ���Ϊ��
	}
}


/*
5.ð������
ʱ�临�Ӷȣ�ƽ��O(n2)�����O(n)���O(n2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ��ȶ�
*/
void bubbleSort(int a[], int n)
{
	int tmp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > 0; j--)
		{
			if (a[j] < a[j - 1])
			{
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}
}


/*
6.��������
ʱ�临�Ӷȣ�ƽ��O(nlogn)�����O(nlogn)���O(n2)
�ռ临�Ӷȣ�O(nlogn)
�ȶ��ԣ����ȶ�
*/
int devideData(int a[], int left, int right)
{
	int base = a[left];
	while (left < right)
	{
		while (left<right && a[right]>base)
			right--;
		a[left] = a[right];
		while (left < right && a[left] < base)
			left++;
		a[right] = a[left];
	}
	a[left] = base;
	return left;
}
void quickSort(int a[], int left, int right)
{
	int i;
	if (left < right)
	{
		i = devideData(a, left, right);
		quickSort(a, left, i - 1);
		quickSort(a, i + 1, right);
	}
}


/*
7.�鲢����
ʱ�临�Ӷȣ�ƽ��O(nlogn)�����O(nlogn)���O(nlogn)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ��ȶ�
*/
void mergeTwoSortedSeq(int a[], int r[], int s, int m, int n)
{
	//���������������еĺϲ�
	//a ����
	//s������ʼ���
	//m��һ�����еĽ��������
	//n�ڶ������н������
	int i, j, k;
	k = s;
	i = s;
	j = m + 1;
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			r[k++] = a[i++];
		else
			r[k++] = a[j++];

	}
	while (i <= m)
		r[k++] = a[i++];
	while (j <= n)
		r[k++] = a[j++];

}
void mergeTwo(int a[], int r[], int n, int len)
{//���һ�γ���Ϊn�ĺϲ�
	int s = 0, e;
	while (s + len < n)//���������������
	{
		e = s + 2 * len - 1;
		if (e >= n)
			e = n - 1;
		mergeTwoSortedSeq(a, r, s, s + len - 1, e);
		s = e + 1;
	}
	if (s < n)//��ʣһ�������
	{
		for (; s < n; s++)
		{
			r[s] = a[s];
		}
	}

}
void mergeSrot(int a[], int n)
{
	int* p = new int[n];
	int len = 1;
	int f = 0;
	while (len < n)
	{
		if (f)
			mergeTwo(p, a, n, len);
		else
			mergeTwo(a, p, n, len);
		len *= 2;
		f = 1 - f;
	}
	if (f)
		for (int i = 0; i < n; i++)
			a[i] = p[i];
	delete p;

}


void printData(int a[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout<< "����";
}


void testSort()
{
	int op, a[] = { 3,4,1,6,2,7,5 };
	std::cout << "ԭʼ����:";
	printData(a, 7);
	std::cout << "/n";
	std::cout << "1--��������--";
	std::cout << "2--ϣ������--";
	std::cout << "3--ѡ������--";
	std::cout << "4--������----";
	std::cout << "5--ð������--";
	std::cout << "6--��������--";
	std::cout << "7--�鲢����--";
	std::cout << "�������";
	std::cin >> op;
	switch (op)
	{
	case 1:
		insertSort(a, 7);
		break;
	case 2:
		shellSort(a, 7);
		break;
	case 3:
		selectSort(a, 7);
		break;
	case 4:
		heapSort(a, 7);
		break;
	case 5:
		bubbleSort(a, 7);
		break;
	case 6:
		quickSort(a, 0, 6);
		break;
	case 7:
		mergeSrot(a, 7);
		break;
	}
	std::cout << "�������:";
	printData(a, 7);
}





};