//#include <iostream>
//using namespace std;
//
//class TreeNode {
//	public int val;
//	public TreeNode left, right;
//	public TreeNode(int val)
//	{
//		this.val = val;
//		this.left = this.right = null;
//	}
//}
//
//public class Solution 
//{
//	public TreeNode insertNode(TreeNode root, TreeNode node) 
//	{
//		if (root == null)
//		{
//			return node;
//		}
//		if (root.val > node.val)
//		{
//			if (root.left == null)
//			{
//				root.left = node;
//				return root;
//			}
//			insertNode(root.left, node);
//			return root;
//		}
//		else if (root.val<node.val)
//		{
//			if (root.right == null)
//			{
//				root.right = node;
//				return root;
//			}
//			insertNode(root.right, node);
//			return root;
//		}
//		return root;
//	}
//}
//
//int main()
//{
//
//	system("pause");
//	return 0;
//}