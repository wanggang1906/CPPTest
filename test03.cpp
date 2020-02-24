#include<iostream>

//using namespace std; // 命名空间，保证命名不重复


void u1(){
	char answer;
	std::cout << "输入y/n" << "\n";
	std::cin >> answer;
	switch (answer)
	{
	case 'Y':
	case 'y':
		std::cout << "确定" << "\n";
		break;
	case 'N':
	case'n':
		std::cout << "否" << "\n";
		break;
	default:
		std::cout << "没有符合的选项" << answer << "\n";
		// endl为什么不能用，是std的原因
		//std::cout << "没有符合的选项" << answer << endl;
		break;
	}
	std::cout << "输入任何字符结束程序" << "\n";

	// 100个字符内的回车符忽略
	std::cin.ignore(100, '\n');

	// 键盘缓存区会留有字符
	std::cin.get(); // 伪装接受输入，让控制台停留，功能同c的pause
}


// 温度转换
// 公式：℉ = ℃ * 9.0 / 5.0 + 32
int CandF() {
	const unsigned short ADD_SUBTRACT = 32; // 静态变量，类似于宏常量,#define是宏定义
	const double RATIO = 9.0 / 5.0;
	
	double temperature, result;
	char typeIn,typeOut;
	std::cout << "输入要转换的温度,格式为【xx.x C】或【xx.x F】" << "\n";
	std::cin >> temperature >> typeIn;
	std::cin.ignore(100, '\n');

	switch (typeIn)
	{
	case 'c':
	case 'C':
		result = temperature * RATIO + ADD_SUBTRACT;
		typeOut = 'F'; // 字符型的是单引号，双引号会报错
		typeIn = 'C';
		break;

	case 'f':
	case 'F':
		result = (temperature - ADD_SUBTRACT) / RATIO;
		typeOut = 'C'; // 字符型的是单引号，双引号会报错
		typeIn = 'F';
		break;

	default:
		result = '1';
	}

	if (result != 1)
	{
		std::cout << temperature << typeIn << " = " << result << typeOut;
	}
	else
	{
		std::cout << "输入错误" << "\n";
	}
	return 0;
}

