#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode 
{
	public:
		int val;
		TreeNode *left, *right;
		TreeNode(int val)
		{
			this->val = val;
			this->left = this->right = NULL;
		}
		
};

vector<vector<int>> zigzagLevelOrder(TreeNode * root) 
{
	vector<vector<int>> vec;
	vector<int> temvector;
	if (root == NULL)
		return vec;

	TreeNode * temNode = root;
	queue<TreeNode*> prequeue, nextqueue;
	bool isOrder = 1;
	prequeue.push(root);

	while (prequeue.size() != 0)
	{
		while (prequeue.size() != 0)
		{
			temNode = prequeue.front();
			prequeue.pop();
			while (temNode == NULL&&prequeue.size() != 0)
			{
				temNode = prequeue.front();
				prequeue.pop();
			}
			if (temNode != NULL)
			{
				if (isOrder)
				{
					temvector.insert(temvector.end(), temNode->val);
				}
				else
				{
					temvector.insert(temvector.begin(), temNode->val);
				}
				nextqueue.push(temNode->left);
				nextqueue.push(temNode->right);
			}
		}
		isOrder = 1 - isOrder;
		prequeue = nextqueue;
		while (nextqueue.size() != 0)
			nextqueue.pop();
		if (temvector.size() != 0)
			vec.insert(vec.end(), temvector);
		temvector.clear();
	}
	return vec;
}

//int main()
//{
//	TreeNode theone(1);
//	theone.left = new TreeNode(3);
//	theone.right = new TreeNode(2);
//	theone.right->left = new TreeNode(4);
//	theone.right->right = new TreeNode(5);
//
//	vector<vector<int>> thevector;
//	thevector = zigzagLevelOrder(&theone);
//
//	for (int i = 0; i < thevector.size(); i++)
//	{
//		for (int j = 0; j < thevector[i].size(); j++)
//			cout << thevector[i][j];
//		cout << endl;
//	}
//
//	return 0;
//}