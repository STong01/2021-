#include <iostream>
using namespace std;

//���ֵĸ�ʽ��A[.[B]][e|EC]����.B[e|EC]��ʾ������A��C���������������������ţ�Ҳ����û�У�����B��һ���޷�������

//����ɨ���ַ�����0-9����λ��������һ���޷���������
bool scanUnsignedInteger(const char** str)
{
	const char* before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
	{
		++(*str);
	}
	//��str�д�������0-9������ʱ������true
	return *str > before;
}

//ɨ������Ա�ʾ�����ġ�+�����ߡ�-��Ϊ��ʼ��0-9����λ��������һ�����ܴ��������ŵ�������
bool scanInteger(const char** str)
{
	if (**str == '+' || **str == '-')
	{
		++(*str);
	}
	return scanUnsignedInteger(str);
}

bool isNumeric(const char* str)
{
	if (str == nullptr)
	{
		return false;
	}

	bool numeric = scanInteger(&str);

	//������֡�.����������������ֵ�С������
	if (*str == '.')
	{
		++str;

		//����һ�д�����||��ԭ��
		//1.С������û���������֣���.123
		//2.С����������û�����֣���233.
		//3.��Ȼ��С����ǰ��ͺ�����Զ������֣���233.666
		numeric = scanUnsignedInteger(&str) || numeric;
	}

	//������֡�e�����ߡ�E����������������ֵ�ָ������
	if (*str == 'e' || *str == 'E')
	{
		++str;

		//����һ�д�����&&��ԭ��
		//1.��e����Eǰ��û������ʱ�������ַ������ܱ�ʾ���֣���.e1����e1
		//2.��e����E����û������ʱ�������ַ������ܱ�ʾ���֣���12e����12e+5.4
		numeric = numeric && scanInteger(&str);
	}

	return numeric && *str == '\0';
}

int main()
{
	const char* str = "12e";

	cout << isNumeric(str) << endl;

	system("pause");
	return 0;
}