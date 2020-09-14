#define LittletoBig16(A) ((((uint16)(A) & 0xff00) >> 8) | (((uint16)(A) & 0x00ff) << 8))
#define LittletoBig32(A) ((((uint32)(A) & 0xff000000) >> 24) | (((uint32)(A) & 0x00ff0000) >> 8) | (((uint32)(A) & 0x0000ff00) << 8) | (((uint32)(A) & 0x000000ff) << 24))
#include <iostream>
using namespace std;

bool IsBigEndian1()
{
	int a = 0x1234;
	char b = *(char*)&a;//ͨ����intǿ������ת����char���ֽڣ�ͨ���ж���ʼ�洢λ�ã�������a�ĵ͵�ַ����
	if (b == 0x12)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//������union�Ĵ��˳�������г�Ա���ӵ͵�ַ��ʼ��ţ����ø����Կ������ɻ����cpu���ڴ����Little-endian����big-endianģʽ��д
bool IsBigEndian2()
{
	union NUM
	{
		int a;
		char b;
	}num;
	num.a = 0x1234;
	if (num.b == 0x12)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	if (IsBigEndian1())
	{
		cout << "��˴洢" << endl;
	}
	else
	{
		cout << "С�˴洢" << endl;
	}

	if (IsBigEndian2())
	{
		cout << "��˴洢" << endl;
	}
	else
	{
		cout << "С�˴洢" << endl;
	}

	system("pause");
	return 0;
}