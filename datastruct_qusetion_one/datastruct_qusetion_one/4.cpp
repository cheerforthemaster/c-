#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class ListNode {
public:
	int val;
    ListNode *next;
    ListNode(int val) 
	{
        this->val = val;
        this->next = NULL;
    }
};

vector<ListNode*> rehashing(vector<ListNode*> hashTable) 
{
	vector<ListNode*> temVec;
	int capacity = hashTable.size();
	if (capacity == 0)
		return temVec;

	int reCapacity = capacity * 2;
	vector<ListNode*> listVec(reCapacity, NULL);
	ListNode* temNode = NULL;
	ListNode* temlistNode = NULL;
	int key = 0;
	for (int i = 0; i < capacity; i++)
	{
		temNode = hashTable[i];
		while (temNode != NULL)
		{
			key = (temNode->val%reCapacity + reCapacity) % reCapacity;
			if (listVec[key] == NULL)
			{
				listVec[key] = temNode;
				hashTable[i] = temNode->next;
				temNode->next = NULL;
				temNode = hashTable[i];
			}
			else
			{
				temlistNode = listVec[key];
				while (temlistNode->next != NULL)
					temlistNode = temlistNode->next;
				temlistNode->next = temNode;
				hashTable[i] = temNode->next;
				temNode->next = NULL;
				temNode = hashTable[i];
			}
		}
	}
	return listVec;
}


// int main()
// {
// 	vector<ListNode*> vec(5, NULL);
// 	ListNode* temlist = new ListNode(2);
// 	vec[2] = temlist;
// 	temlist = new ListNode(18);
// 	temlist->next = new ListNode(13);
// 	vec[3] = temlist;
// 	vector<ListNode*> outvector;
// 	outvector = rehashing(vec);
// 	cout << "over" << endl;
// 	return 0;
// }