#pragma once

#include<iostream>
#include<string>

#ifndef _test06_oop_H_ // ��ͷ�ͽ�β���ϣ���ʾԤ����
#define _test06_oop_H_ // �궨��


// ͷ�ļ�д��Ķ���

// ����Personal
class Personal
{
public:
	std::string name;
	float age;
	int a;
	void saidWord(); // ֻд�����Ķ��壬cpp��д������ʵ��
};

// ����PerA
class PerA : public Personal
{
public:
	int perAParticularAttribute;

	void saidSelfName();

};





#endif