// ���ݽṹ���㷨

/*
1.��������
ʱ�临�Ӷȣ�ƽ��O(n2)�����O(n)���O(n2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ��ȶ�
*/
void insertSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
	{
		t = a[i];
		for (j = i - 1; j >= 0 && t < a[j]; --j)
			a[j + 1] = a[j];
		a[j + 1] = t;
	}
}