#pragma once
#include <iostream>
#include <iomanip>
#include <string>


#define OVERFLOWED 1E-12

class Matrix
{
	// ����(����)����
public:
	Matrix(int m, int n);             //����һ��m*n��ȫ�����
	Matrix(int n);                 //����һ��n*n�ĵ�λ����
	Matrix(const Matrix&);         //�������캯�������
	Matrix(double* items, int m, int n);//�������鿽��һ������
	~Matrix();
	static Matrix FromFile(std::string file);
	int getRowNum() const;                //���ؾ��������
	int getColNum() const;                //���ؾ��������

	Matrix Trans() const;                //������ת��

	double get(int i, int j) const;            //���ؾ����i��j��Ԫ��
	void set(int i, int j, double val);        //���þ����i��j��Ԫ��

	Matrix operator +(const Matrix& m);         //�����������
	Matrix operator -(const Matrix& m);         //�����������
	Matrix operator *(const Matrix& m);         //�����������
	Matrix operator *(const double f);         //������Գ���
	Matrix& operator=(const Matrix& m);
	Matrix Inverse();

	friend std::ostream& operator <<(std::ostream& os, const Matrix& m);

	// ��������
private:
	double* item;        //ָ�������Ԫ��
	int rowNum;        //��������
	int colNum;        //��������

	// ���巽��
private:
	//��������б任
	//���j=-1,���i����multiply��
	//���j��ȡֵ��Χ�ڣ��򽫵�i������multiply���ӵ�j��
	void RowSwap(int i, int j, double multiply);
	//��������
	void RowSwap(int i, int j);
	void FlowOver();
};
