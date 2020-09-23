#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

//���LRU����ṹ���ýṹ�ڹ���ʱȷ����С�������СΪK������������������
//set(key, value)������¼(key, value)����ýṹ
//get(key)������key��Ӧ��valueֵ

//set��get������ʱ�临�Ӷ�ΪO(1)
//ĳ��key��set��get����һ����������Ϊ���key�ļ�¼�����ʹ�õġ�
//������Ĵ�С����Kʱ���Ƴ������ʹ�õļ�¼����set��get���Զ�ġ�
//��opt = 1����������������x, y����ʾset(x, y)
//��opt = 2��������һ������x����ʾget(x)����xδ���ֹ����ѱ��Ƴ����򷵻� - 1
//����ÿ������2�����һ����

//����
//[[1, 1, 1], [1, 2, 2], [1, 3, 2], [2, 1], [1, 4, 4], [2, 2]], 3
//���
//[1, -1]
//˵��
//��һ�β������ʹ�õļ�¼Ϊ("1", 1)
//�ڶ��β������ʹ�õļ�¼Ϊ("2", 2)��("1", 1)��Ϊ����õ�
//�����β������ʹ�õļ�¼Ϊ("3", 2)��("1", 1)��������õ�
//���Ĵβ�������õļ�¼Ϊ("1", 1)��("2", 2)��Ϊ����õ�
//����β����󣺴�С������3�������Ƴ���ʱ���ʹ�õļ�¼("2", 2)�������¼("4", 4)������Ϊ�ʹ�õļ�¼��Ȼ��("3", 2)��Ϊ���ʹ�õļ�¼

class Solution 
{
public:
	vector<int> LRU(vector<vector<int> >& operators, int k) 
	{
		caps = k;
		for (auto op : operators)
		{
			if (op[0] == 1)
			{
				set(op[1], op[2]);
			}
			else if (op[0] == 2)
			{
				get(op[1]);
			}
		}
		return res;
	}

private:

	int caps;
	vector<int> res;

	list<pair<int, int>> cache;
	unordered_map<int, int> maps;

	void set(int key, int val)
	{
		if (maps.find(key) != maps.end())
		{
			maps.erase(key);
		}
		if (cache.size() == caps)
		{
			maps.erase(cache.back().first);
			cache.pop_back();
		}
		cache.push_front({ key, val });
		maps[key] = cache.front().second;
		return;
	}

	void get(int key)
	{
		if (maps.find(key) == maps.end())
		{
			res.push_back(-1);
			return;
		}
		cache.remove({ key, maps[key] });
		cache.push_front({ key, maps[key] });
		res.push_back(maps[key]);
		return;
	}
};

int main()
{

	system("pause");
	return 0;
}