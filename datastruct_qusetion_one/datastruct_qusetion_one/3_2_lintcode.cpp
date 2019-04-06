//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//using namespace std;
//
//class TreeNode
//{
//public:
//	int val;
//	TreeNode *left, *right;
//	TreeNode(int val)
//	{
//		this->val = val;
//		this->left = this->right = NULL;
//	}
//};
//
//int maxPathSum(TreeNode * root)
//{
//	if (root == NULL)
//		return 0;
//	TreeNode* preNode = root;
//	TreeNode* rightNode = root->right;
//	TreeNode* leftNode = root->left;
//	stack<TreeNode*> sta;
//	stack<TreeNode*> int_stack;
//	int rightVal = 0;
//	int leftVal = 0;
//	int size = root->val;
//	TreeNode* temNode = NULL;
//	TreeNode* tem = NULL;
//
//	for (int i = 0; i < 2; i++)
//	{
//		if (i == 0)
//		{
//			preNode = rightNode;
//			if (preNode == NULL)
//				i++;
//		}
//		if (i == 1)
//		{
//			preNode = leftNode;
//			if (preNode == NULL)
//				break;
//			while (int_stack.size() != 0)
//				int_stack.pop();
//		}
//		do
//		{
//			if (preNode == NULL)
//				int_stack.push(NULL);
//			else
//			{
//				if (preNode->left == NULL && preNode->right == NULL)
//				{
//					int_stack.push(preNode);
//					if (preNode->val > size)
//						size = preNode->val;
//				}
//				else
//				{
//					sta.push(preNode);
//					sta.push(preNode->left);
//					sta.push(preNode->right);
//					if (int_stack.size() != 0)
//					{
//						temNode = int_stack.top();
//						int_stack.pop();
//						if (int_stack.size() != 0)
//						{
//							tem = int_stack.top();
//							if ((preNode->left == temNode && preNode->right == tem) || (preNode->left == tem && preNode->right == temNode))
//							{
//								int_stack.push(temNode);
//								if (int_stack.size() != 0)
//								{
//									temNode = int_stack.top();
//									if (temNode == NULL)
//										leftVal = 0;
//									else
//									{
//										leftVal = temNode->val;
//										if (temNode->val > size)
//											size = temNode->val;
//									}
//									int_stack.pop();
//									if (int_stack.size() != 0)
//									{
//										temNode = int_stack.top();
//										if (temNode == NULL)
//											rightVal = 0;
//										else
//										{
//											rightVal = temNode->val;
//											if (temNode->val > size)
//												size = temNode->val;
//										}
//										int_stack.pop();
//										if (preNode->val > size)
//											size = preNode->val;
//										if (rightVal + leftVal + preNode->val > size)
//											size = rightVal + leftVal + preNode->val;
//										if (rightVal > 0 || leftVal > 0)
//											rightVal > leftVal ? preNode->val += rightVal : preNode->val += leftVal;
//										if (preNode->val > size)
//											size = preNode->val;
//										int_stack.push(preNode);
//										sta.pop();
//										sta.pop();
//										sta.pop();
//									}
//									else
//										int_stack.push(temNode);
//								}
//
//							}
//							else
//								int_stack.push(temNode);
//						}
//						else
//							int_stack.push(temNode);
//					}
//				}
//			}
//			if (sta.size() != 0)
//			{
//				preNode = sta.top();
//				sta.pop();
//			}
//			else
//				preNode = NULL;
//			leftVal = 0;
//			rightVal = 0;
//			if (preNode == rightNode&&i == 0)
//			{
//				preNode = NULL;
//				sta.push(preNode);
//				preNode = rightNode;
//			}
//			if (preNode == leftNode&&i == 1)
//			{
//				preNode = NULL;
//				sta.push(preNode);
//				preNode = leftNode;
//			}
//		} while (sta.size() != 0);
//	}
//	if (rightNode != NULL)
//		rightVal = rightNode->val;
//	else
//		rightVal = 0;
//	if (leftNode != NULL)
//		leftVal = leftNode->val;
//	else
//		leftVal = 0;
//	if (root->val + leftVal + rightVal > size)
//	{
//		size = root->val + leftVal + rightVal;
//	}
//	return size;
//}
