#pragma once

#include<iostream>
#include<string>

#ifndef _test06_oop_H_ // 开头和结尾加上，表示预编译
#define _test06_oop_H_ // 宏定义


// 头文件写类的定义

// 基类Personal
class Personal
{
public:
	std::string name;
	float age;
	int a;
	void saidWord(); // 只写方法的定义，cpp中写方法的实现
};

// 子类PerA
class PerA : public Personal
{
public:
	int perAParticularAttribute;

	void saidSelfName();

};





#endif