#include<iostream>

//using namespace std; // �����ռ䣬��֤�������ظ�


void u1(){
	char answer;
	std::cout << "����y/n" << "\n";
	std::cin >> answer;
	switch (answer)
	{
	case 'Y':
	case 'y':
		std::cout << "ȷ��" << "\n";
		break;
	case 'N':
	case'n':
		std::cout << "��" << "\n";
		break;
	default:
		std::cout << "û�з��ϵ�ѡ��" << answer << "\n";
		// endlΪʲô�����ã���std��ԭ��
		//std::cout << "û�з��ϵ�ѡ��" << answer << endl;
		break;
	}
	std::cout << "�����κ��ַ���������" << "\n";

	// 100���ַ��ڵĻس�������
	std::cin.ignore(100, '\n');

	// ���̻������������ַ�
	std::cin.get(); // αװ�������룬�ÿ���̨ͣ��������ͬc��pause
}


// �¶�ת��
// ��ʽ���H = �� * 9.0 / 5.0 + 32
int CandF() {
	const unsigned short ADD_SUBTRACT = 32; // ��̬�����������ں곣��,#define�Ǻ궨��
	const double RATIO = 9.0 / 5.0;
	
	double temperature, result;
	char typeIn,typeOut;
	std::cout << "����Ҫת�����¶�,��ʽΪ��xx.x C����xx.x F��" << "\n";
	std::cin >> temperature >> typeIn;
	std::cin.ignore(100, '\n');

	switch (typeIn)
	{
	case 'c':
	case 'C':
		result = temperature * RATIO + ADD_SUBTRACT;
		typeOut = 'F'; // �ַ��͵��ǵ����ţ�˫���Żᱨ��
		typeIn = 'C';
		break;

	case 'f':
	case 'F':
		result = (temperature - ADD_SUBTRACT) / RATIO;
		typeOut = 'C'; // �ַ��͵��ǵ����ţ�˫���Żᱨ��
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
		std::cout << "�������" << "\n";
	}
	return 0;
}

