#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

class Solution
{
public:
	vector<vector<int>> threeOrders(TreeNode* root)
	{
		//定义输出的数组
		vector<vector<int>> ans;
		//定义先序遍历数组
		vector<int> preo;
		//定义中序遍历数组
		vector<int> ino;
		//定义后序遍历数组
		vector<int> pos;

		stack<TreeNode*> st;
		TreeNode* p = root;

		//迭代先序遍历
		while (p || !st.empty())
		{
			if (p)
			{
				st.push(p);
				preo.push_back(st.top()->val);
				p = p->left;
			}
			else
			{
				p = st.top();
				st.pop();
				p = p->right;
			}
		}
		ans.push_back(preo);

		//迭代中序遍历
		TreeNode* q = root;
		while (q || !st.empty())
		{
			if (q)
			{
				st.push(q);
				q = q->left;
			}
			else
			{
				q = st.top();
				ino.push_back(st.top()->val);
				st.pop();
				q = q->right;
			}
		}
		ans.push_back(ino);

		//迭代后序遍历
		TreeNode* r = root;
		while (r || !st.empty())
		{
			if (r)
			{
				st.push(r);
				pos.push_back(st.top()->val);
				r = r->right;
			}
			else
			{
				r = st.top();
				st.pop();
				r = r->left;
			}
		}
		reverse(pos.begin(), pos.end());
		ans.push_back(pos);
		return ans;
	}
};

int main()
{
	int num = 10;
	int s = 3;
	int n = s >> 1;
	while (n < 9)
	{
		num = num - s;
		s++;
		n = s >> 1;
	}

	cout << num << " " << s << endl;

	/*for (int i = 0; i + 1; i++)
		cout << i << " ";*/

	system("pause");
	return 0;
}