#define LittletoBig16(A) ((((uint16)(A) & 0xff00) >> 8) | (((uint16)(A) & 0x00ff) << 8))
#define LittletoBig32(A) ((((uint32)(A) & 0xff000000) >> 24) | (((uint32)(A) & 0x00ff0000) >> 8) | (((uint32)(A) & 0x0000ff00) << 8) | (((uint32)(A) & 0x000000ff) << 24))
#include <iostream>
using namespace std;

bool IsBigEndian1()
{
	int a = 0x1234;
	char b = *(char*)&a;//通过将int强制类型转换成char单字节，通过判断起始存储位置，即等于a的低地址部分
	if (b == 0x12)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//联合体union的存放顺序是所有成员都从低地址开始存放，利用该特性可以轻松获得了cpu对内存采用Little-endian还是big-endian模式读写
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
		cout << "大端存储" << endl;
	}
	else
	{
		cout << "小端存储" << endl;
	}

	if (IsBigEndian2())
	{
		cout << "大端存储" << endl;
	}
	else
	{
		cout << "小端存储" << endl;
	}

	system("pause");
	return 0;
}