#include<iostream>


// ָ����ĸ�����

// ָ������� --- ��ָ���������ָ������ȥ����ʣ�µĲ�����ָ�������
// ָ����ָ������� --- ����ͨ��ָ��������ָ����ָ����ڴ���ʱ��ָ����ָ������;����˱�����������Ƭ�ڴ���������ݵ���ʲô��������
// ָ�뱾���ֵ --- 
// ָ����ָ����ڴ������ֵ

void pointTest() {
	printf("ָ����ظ���");
	// ��Դ�� 
    // https://www.cnblogs.com/sumuncle/p/9773955.html
	// https://blog.csdn.net/weixin_39640298/article/details/84900326
	// ��������ָ��
	int *ptr; // ָ���������int *	// ָ����ָ���������int
	char *ptr; // ָ���������char *	// ָ����ָ���������char
	int **ptr; // ָ���������int **	// ָ����ָ���������int *
	int(*ptr)[3]; // ָ���������int (*)[3]		// ָ����ָ���������int()[3]	// ()�ɽ�����ȼ�����
	int *(*ptr)[4]; // ָ���������int *(*)[4]	// ָ����ָ���������int *()[4]

	// ���������ָ��
	int num = 97;
	float score = 10.00F;
	int arr[3] = { 1,2,3 };

	int* p_num = &num;
	int* p_arr1 = arr;		//p_arr1��˼��ָ�������һ��Ԫ�ص�ָ��
	float* p_score = &score;
	int(*p_arr)[3] = &arr;
	int (*fp_add)(int, int) = add;  //p_add��ָ����add�ĺ���ָ��
	const char* p_msg = "Hello world";//p_msg��ָ���ַ������ָ��

}

int add(int a,int b) {
	return 0;
}

void pointSize() {
	printf("ָ���С���");
}