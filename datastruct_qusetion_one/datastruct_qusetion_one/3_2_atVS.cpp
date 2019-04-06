#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val, TreeNode *left = NULL, TreeNode *right = NULL)
	{
		this->val = val;
		this->left = left;
		this->right = right;
	}
};

// int maxPathSum(TreeNode * root)
// {
// 	if (root == NULL)
// 	{
// 		return 0;
// 	}
// 	if (root->left == NULL&&root->right == NULL)
// 	{
// 		return 1;
// 	}
// 	else
// 	{
// 		int leftlevel = maxPathSum(root->left);
// 		int rightlevel = maxPathSum(root->right);
// 		return rightlevel > leftlevel ? ++rightlevel : ++leftlevel;
// 	}
// }

int getDepth(TreeNode* root)
{
	int depth = 0;
	TreeNode* preNode = root;
	stack<TreeNode*> tree;
	stack<bool> tag;
	while (preNode != NULL || tree.size() != 0)
	{
		while (preNode != NULL)
		{
			tree.push(preNode);
			tag.push(0);
			preNode = preNode->left;
		}
		if (tag.top() == 1)
		{
			depth = depth > tree.size() ? depth : tree.size();
			tree.pop();
			tag.pop();
			preNode = NULL;
		}
		else
		{
			preNode = tree.top();
			preNode = preNode->right;
			tag.pop();
			tag.push(1);
		}
	}
	return depth;
}



int printMaxpath(TreeNode * root)//输出该节点所在的最大路径;
{
	vector<TreeNode*> pathleft;
	vector<TreeNode*> pathright;
	vector<TreeNode*> branch;
	std::vector<TreeNode*>::iterator it;
	TreeNode* preNode = NULL;
	int rightLevel = 0, leftLevel = 0;
	bool inBranch = 0;
	for (int i = 0; i < 2; i++)
	{
		inBranch = 0;
		i == 0 ? preNode = root->left : preNode = root->right;
		while (preNode != NULL || branch.size() != 0)
		{
			rightLevel = getDepth(preNode->right);
			leftLevel = getDepth(preNode->left);
			if (rightLevel == leftLevel&&rightLevel != 0)
			{
				for (int j = 0; j < branch.size(); j++)
				{
					if (branch[j] == preNode->right)
					{
						if (i == 0)
							pathleft.insert(pathleft.begin(), preNode);
						else
							pathright.insert(pathright.end(), preNode);
						preNode = preNode->right;
						inBranch = 1;
						it = branch.begin() + j;
						branch.erase(it);
						break;
					}
					else
						inBranch = 0;
				}
				if (inBranch == 1)
					continue;
				else
				{
					branch.insert(branch.begin(), preNode->right);
					if (i == 0)
						pathleft.insert(pathleft.begin(), preNode);
					else
						pathright.insert(pathright.end(), preNode);
					preNode = preNode->left;
				}
			}
			else
			{
				if (rightLevel == leftLevel&&rightLevel == 0)
				{
					if (i == 0)
					{
						pathleft.insert(pathleft.begin(), preNode);
						if (branch.size() != 0)
							preNode = root->left;
						else
							preNode = NULL;
					}
					else
					{
						pathright.insert(pathright.end(), preNode);
						if (branch.size() != 0)
							preNode = root->right;
						else
							preNode = NULL;
					}
					
				}
				else
				{
					if (i == 0)
						pathleft.insert(pathleft.begin(), preNode);
					else
						pathright.insert(pathright.end(), preNode);
					rightLevel > leftLevel ? preNode = preNode->right : preNode = preNode->left;
				}
			}
		}
	}
// 	for (int i = 0; i < pathleft.size(); i++)
// 	{
// 		cout << pathleft[i]->val << " ";
// 	}
// 	cout << endl;
// 	for (int j = 0; j < pathright.size(); j++)
// 	{
// 		cout << pathright[j]->val << " ";
// 	}
// 	cout << endl;
	rightLevel = getDepth(root->right);
	leftLevel = getDepth(root->left);
	int times = 1;
	int othertimes = 1;
	for (int i = 0; i < pathleft.size(); )
	{
		for (int j = 0; j < pathright.size(); j++)
		{

			cout << pathleft[i]->val << "," << pathright[rightLevel*othertimes - 1]->val << "   ";
			while (i < leftLevel*times)
			{
				cout << pathleft[i]->val << " ";
				i++;
			}
			cout << root->val << " ";
			while (j < rightLevel *othertimes)
			{
				cout << pathright[j]->val << " ";
				j++;
			}
			j--;
			othertimes++;
			i = leftLevel*(times - 1);
			cout << endl;
		}
		times++;
		othertimes = 1;
		i = leftLevel*(times - 1);
	}
	return 0;
}


int maxPathSum(TreeNode * root)
{
	if (root == NULL)
	{
		cout << "NULL" << endl;
		return 0;
	}
	while (root->left == NULL || root->right == NULL)//根节点不能为起点或终点;
	{
		if (root->left != NULL)
			root = root->left;
		if (root->right != NULL)
			root = root->right;
		if (root->left == NULL && root->right == NULL)
			cout << root->val << "," << root->val << "   " << root->val << endl;
		return 0;
	}
	stack<TreeNode*> maxpath;
	stack<int> maxLength;
	int maxsize = 0;
	maxsize = 1 + getDepth(root->left) + getDepth(root->right);
	TreeNode* preNode = root;
	stack<TreeNode*> temstack;
	stack<bool> tag;
	int temlength = 0;
	while (preNode != NULL || temstack.size() != 0)//后序遍历查找最长路径中的根结点;
	{
		while (preNode != NULL)
		{
			temstack.push(preNode);
			tag.push(0);
			preNode = preNode->left;
		}
		if (tag.top() == 1)
		{
			preNode = temstack.top();
			temlength = 1 + getDepth(preNode->left) + getDepth(preNode->right);
			maxsize <= temlength ? (maxpath.push(preNode), maxsize = temlength, maxLength.push(temlength)) : void(0);
			temstack.pop();
			tag.pop();
			preNode = NULL;
		}
		else
		{
			preNode = temstack.top();
			tag.pop();
			tag.push(1);
			preNode = preNode->right;
		}
	}
	if (maxLength.size() == 0)//根节点所在路径最长;
	{
		printMaxpath(root);
	}
	else
	{
		while (maxLength.top() == maxsize)
		{
			printMaxpath(maxpath.top());
			maxpath.pop();
			maxLength.pop();
			if (maxLength.size() == 0)
				break;
		}
	}
	return 0;
}





int main()
{

	TreeNode theone(1, new TreeNode(2, new TreeNode(3, new TreeNode(10), new TreeNode(11)), new TreeNode(7, new TreeNode(8), new TreeNode(9))), new TreeNode(3, NULL, new TreeNode(4, new TreeNode(5), new TreeNode(6))));
// 	TreeNode theone(1);
// 	theone.left = new TreeNode(2);
// 	theone.right = new TreeNode(3);
// 	theone.left->left = new TreeNode(4);
// 	theone.left->right = new TreeNode(7);
// // 	theone.left->left->right = new TreeNode(7);
// // 	theone.right->left = new TreeNode(5);
// 	theone.right->right = new TreeNode(6);
// 	theone.right->right->left = new TreeNode(8);
// 	theone.right->right->right = new TreeNode(9);
// 	//cout << maxPathSum(theone.right) << endl;
// 	//cout << maxPathSumone(theone.left) << endl;
	maxPathSum(&theone);
// 	delete theone.right->right->right;
// 	delete theone.right->right->left;
// 	delete theone.right->right;
// 	delete theone.right->left;
// 	delete theone.right;
// 	delete theone.left->left->right;
// 	delete theone.left->left;
// 	delete theone.left;
	return 0;
}