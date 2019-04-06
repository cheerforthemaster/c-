#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//int maximalRectangle(vector<vector<bool>> &matrix)
//{
//	int thesize = 0;
//	int length = matrix.size();
//	if (length == 0)
//		return thesize;
//	int width = matrix[length - 1].size();
//	if (width == 0)
//		return thesize;
//	int temone = 0, temtwo = 0;//暂时储存i，j;
//	int temsize = 0;//暂时储存当前的矩阵大小;
//	int temwidth = width - 1;//当前矩阵的宽度;
//	int temlength = length - 1;//当前矩阵的长度;
//	int minwidth = width;//当前矩阵中宽度最小的;
//	for (int i = 0; i < length; i++)
//		for (int j = 0; j < width; j++)
//		{
//			temone = i;
//			temtwo = j;
//			temsize = 0;
//			temwidth = width - 1;
//			temlength = length - 1;
//			minwidth = width;
//			if (matrix[i][j] == 1)
//			{
//				while (matrix[i][j] == 1)//获取当前矩阵的长度;i到temlength都是1;
//				{
//					i++;
//					if (i == length)
//						break;
//				}
//				temlength = i;
//				i = temone;
//
//				for (int k = i; k < temlength; k++)//遍历每层;
//				{
//					while (matrix[i][j] == 1)
//					{
//						j++;
//						if (j == width)
//							break;
//					}
//					temwidth = j - 1;
//					if (temwidth < minwidth)
//						minwidth = temwidth;
//					temsize = (i - temone + 1)*(minwidth - temtwo + 1);
//					if (temsize > thesize)
//						thesize = temsize;
//					i++;
//					j = temtwo;
//				}
//				j = temtwo;
//				i = temone;
//			}
//		}
//	return thesize;
//}



int maximalRectangle(vector<vector<bool>> &matrix)
{
	int thesize = 0;
	int length = matrix.size();
	if (length == 0)
		return thesize;
	int width = matrix[length - 1].size();
	if (width == 0)
		return thesize;
	int temone = 0, temtwo = 0;//暂时储存i，j;
	int temsize = 0;//暂时储存当前的矩阵大小;
	int temlength = 0;//当前矩阵的长度;
	int maxwidth = 0;//当前矩阵中最大宽度;

	int **arr = new int *[length];//每行下面连续1的个数;
	for (int i = 0; i < length; i++)
		arr[i] = new int[width];

	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++)
			arr[i][j] = -1;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			temone = i;
			temtwo = j;
			if (matrix[i][j] == 1)
			{
				if (i > 0)
				{
					if (arr[i - 1][j] != -1)
					{
						arr[i][j] = arr[i - 1][j] - 1;
					}
					else
					{
						while (matrix[i][j] == 1)//获取当前矩阵的长度;i到temlength都是1;
						{
							i++;
							if (i == length)
								break;
						}
						temlength = i;
						i = temone;
						arr[i][j] = temlength - i;
					}
				}
				else
				{
					while (matrix[i][j] == 1)//获取当前矩阵的长度;i到temlength都是1;
					{
						i++;
						if (i == length)
							break;
					}
					temlength = i;
					i = temone;
					arr[i][j] = temlength - i;
				}
			}
		}
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			temone = i;
			temtwo = j;
			if (arr[i][j] != -1)
			{
				temlength = arr[i][j];
				while (arr[i][j] != -1)
				{
					j++;
					if (j == width)
						break;
					if (arr[i][j] < temlength)
					{
						maxwidth = j - temtwo;
						temsize = temlength*maxwidth;
						if (temsize > thesize)
							thesize = temsize;
						temlength = arr[i][j];
					}
				}
				maxwidth = j - temtwo;
				temsize = temlength*maxwidth;
				if (temsize > thesize)
					thesize = temsize;
				j = temtwo;
			}
		}
	}

	cout << endl;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
			cout << arr[i][j];
		cout << endl;
	}


	for (int i = 0; i < length; i++)
		delete[]arr[i];
	delete[]arr;
	return thesize;
}

//int main()
//{
//	vector<vector<bool>> theone(5, vector<bool>(5, 0));
//// 		[1, 1, 0, 0, 1],
//// 		[0, 1, 0, 0, 1],
//// 		[0, 0, 1, 1, 1],
//// 		[0, 0, 1, 1, 1],
//// 		[0, 0, 0, 0, 1];
//	theone[0][4] = 1;
//	theone[1][4] = 1;
//	theone[1][2] = 1;
//	theone[2][0] = 1;
//	theone[2][2] = 1;
//	theone[2][3] = 1;
//	theone[2][4] = 1;
//	theone[3][1] = 1;
//	theone[3][2] = 1;
//	theone[3][3] = 1;
//	theone[3][4] = 1;
//	theone[4][2] = 1;
//	//theone[4][3] = 1;
//	theone[4][4] = 1;
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//			cout << theone[i][j];
//		cout << endl;
//	}
//
//	cout << maximalRectangle(theone) << endl;
//
//
//	return 0;
//}





// int main()
// {
// 	ListNode* one;
// 	one = new ListNode(1);
// 	one->next = new ListNode(2);
// 	one->next->next = new ListNode(3);
// 	one->next->next->next = new ListNode(4);
// 	//one->next->next->next->next = new ListNode(5);
// 
// 	ListNode* two;
// 	two = reverseKGroup(one, 4);
// 	for (int i = 0; i < 4; i++)
// 	{
// 		cout << two->val << " " << endl;
// 		two = two->next;
// 	}
// 
// 	ListNode* temNode = one;
// 
// 	while (one->next != NULL)
// 	{
// 		temNode = one->next;
// 		one->next = temNode->next;
// 		delete temNode;
// 	}
// 
// 	return 0;
// }