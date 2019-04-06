#pragma once
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// ListNode* Swap(ListNode* one, ListNode* two)
// {
// 	ListNode* head = one;
// 	ListNode* middle = one->next;
// 	ListNode* nail = NULL;
// 
// 	while (middle != two->next)
// 	{
// 		nail = middle->next;
// 		middle->next = head;
// 		head = middle;
// 		middle = nail;
// 	}
// 	return head;
// }


ListNode * reverseKGroup(ListNode * head, int k)
{
	if (k == 1)
		return head;

	int nowPos = 1;//��ǰλ��;
	int preMultiple = 1;//��ǰ����;
	ListNode* preNode = head;//��ǰ��������λ��;
	ListNode* exNode = head, *expreNode = head, *temNodeone = NULL, *temNodetwo = NULL;//�������õ���ʱָ��;
	ListNode* followNode = NULL;//preNode��ǰ��һ��ָ��;
	//exNode �� followNode ��һ�������������;
	//expreNode �� exNode ��ǰһ����preNode �� followNode ��ǰһ��;

	while (preNode != NULL)
	{
		if (k*preMultiple == nowPos)//������Ҫ��ת�ĵط�;
		{
			followNode = preNode;
			preNode = preNode->next;
			temNodeone = exNode->next;
			temNodetwo = temNodeone->next;
			if (expreNode == head)
			{
				head = followNode;
				expreNode = exNode;
			}
			else
			{
				expreNode->next = followNode;
				expreNode = exNode;
			}
			exNode->next = preNode;
			while (temNodeone != preNode)
			{
				temNodeone->next = exNode;
				exNode = temNodeone;
				temNodeone = temNodetwo;
				if (temNodetwo!=NULL)
					temNodetwo = temNodetwo->next;
				else
					continue;
			}
			exNode = preNode;
			followNode = expreNode;
			nowPos++;
			preMultiple++;
		}
		else
		{
			nowPos++;
			followNode = preNode;
			preNode = preNode->next;
		}
	}
	return head;
}
// 	while (preNode != NULL)
// 	{
// 		if (nowPos == k*preMultiple)
// 		{
// 			if (preMultiple == 1)
// 			{
// 				temNodeThree = preNode->next;
// 				head = preNode;
// 				temNodeOne = followNode->next;
// 				temNodeTwo = temNodeOne->next;
// 				followNode->next = preNode->next;
// 				while (followNode != preNode)
// 				{
// 					temNodeOne->next = followNode;
// 					followNode = temNodeOne;
// 					temNodeOne = temNodeTwo;
// 					temNodeTwo = temNodeTwo->next;
// 				}
// 				followNode = temNodeThree;
// 				preNode = temNodeThree;
// 				temNodeOne = head;
// 				while (temNodeOne->next != followNode)
// 					temNodeOne = temNodeOne->next;
// 				preMultiple++;
// 				nowPos++;
// 			}
// 			else
// 			{
// 				temNodeOne->next = preNode;
// 				followNode->next = preNode;
// 				Swap(followNode, preNode);
// 				preMultiple++;
// 				nowPos++;
// 
// 			}
// 		}
// 		else
// 		{
// 			nowPos++;
// 			preNode = preNode->next;
// 		}
// 	}
// 	return temNodeTwo;
//}

