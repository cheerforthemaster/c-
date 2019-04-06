#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

//double findTheNumber(vector<int>& nums1, vector<int>& nums2, double k)
//{
//	int firstSize = nums1.size();
//	int secondSize = nums2.size();
//
//	if (k == 0.5 || k == 1)
//	{
//		vector<int> nums3;
//		if (firstSize > 0)
//			nums3.insert(nums3.begin(), nums1[0]);
//		if (secondSize > 0)
//			nums3.insert(nums3.begin(), nums2[0]);
//		if (firstSize > 1)
//			nums3.insert(nums3.begin(), nums1[1]);
//		if (secondSize > 1)
//			nums3.insert(nums3.begin(), nums2[1]);
//		int themin = nums3[0];
//		int othermin = nums3[0];
//		for (int i = 0; i < nums3.size(); i++)
//		{
//			if (nums3[i]<themin)
//			{
//				themin = nums3[i];
//			}
//		}
//		for (int i = 0; i < nums3.size(); i++)
//		{
//			if (nums3[i] < othermin&&nums3[i] != themin)
//			{
//				othermin = nums3[i];
//			}
//		}
//		if (k == 1)
//		{
//			return themin;
//		}
//		if (k == 0.5)
//		{
//			return (double)(themin + othermin) / 2;
//		}
//	}
//	
//
//	double f_mid = 0;
//	int f_pos = 0;
//	if (firstSize % 2 == 0)
//	{
//		f_mid = (double)(nums1[firstSize / 2] + nums1[firstSize / 2 - 1]) / 2;
//		f_pos = firstSize / 2;
//	}
//	else
//	{
//		f_pos = firstSize / 2;
//		f_mid = nums1[f_pos];
//	}
//
//	double s_mid = 0;
//	int s_pos = 0;
//	if (secondSize % 2 == 0)
//	{
//		s_mid = (double)(nums2[secondSize / 2] + nums2[secondSize / 2 - 1]) / 2;
//		s_pos = secondSize / 2;
//	}
//	else
//	{
//		s_pos = secondSize / 2;
//		s_mid = nums2[s_pos];
//	}
//	if (f_mid > s_mid)
//	{
//		nums2.erase(nums2.begin(), nums2.begin() + s_pos);
//		return findTheNumber(nums1, nums2, k - s_pos);
//	}
//	else
//	{
//		if (f_mid == s_mid)
//		{
//			if (nums1[0]>nums2[0])
//			{
//				nums2.erase(nums2.begin(), nums2.begin() + s_pos);
//				return findTheNumber(nums1, nums2, k - s_pos);
//			}
//			else
//			{
//				nums1.erase(nums1.begin(), nums1.begin() + f_pos);
//				return findTheNumber(nums1, nums2, k - f_pos);
//			}
//		}
//		nums1.erase(nums1.begin(), nums1.begin() + f_pos);
//		return findTheNumber(nums1, nums2, k - f_pos);
//	}
//
//}
//
// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
// {
// 	int firstSize = nums1.size();
// 	int secondSize = nums2.size();
//	vector<int>num1 = nums1;
//	vector<int>num2 = nums2;
//
//	if (firstSize == 0)
//	{
//		if (secondSize % 2 == 0)
//		{
//			return (double)(nums2[secondSize / 2] + nums2[secondSize / 2 - 1]) / 2;
//		}
//		else
//		{
//			secondSize = secondSize / 2;
//			return nums2[secondSize];
//		}
//	}
//	if (secondSize == 0)
//	{
//		if (firstSize == 0)
//		{
//			return (double)(nums1[firstSize / 2] + nums1[firstSize / 2 - 1]) / 2;
//		}
//		else
//		{
//			firstSize = firstSize / 2;
//			return nums1[firstSize];
//		}
//	}
//
//	bool same = true;
//	int tem = nums1[0];
//	for (int i = 0; i < firstSize; i++)
//	{
//		if (nums1[i] != tem)
//		{
//			same = false;
//			break;
//		}
//	}
//
//	bool issame = true;
//	tem = nums2[0];
//	for (int i = 0; i < secondSize; i++)
//	{
//		if (nums2[i] != tem)
//		{
//			issame = false;
//			break;
//		}
//	}
//	if (same&&issame)
//	{
//		return nums1[0];
//	}
//
//	same = true;
//	if (firstSize == secondSize)
//	{
//		for (int i = 0; i < secondSize; i++)
//		{
//			if (nums1[i] != nums2[i])
//			{
//				same = false;
//				break;
//			}
//		}
//		if (same)
//		{
//			num1 = {};
//			return findMedianSortedArrays(num1, nums1);
//		}
//	}
//
//
//	return findTheNumber(num1, num2, (firstSize + secondSize + 1) / 2);
//
// }

// int findKthLargest(vector<int>& nums, int k)
// {
// 	int preNum = nums[0];
// 	int postion = 0, temNum = 0;
// 	bool isSorted = true;
// 	for (int i = 0; i < nums.size(); i++)
// 	{
// 		if (nums[i] > preNum)
// 		{
// 			postion++;
// 			temNum = nums[i];
// 			nums.erase(nums.begin() + i);
// 			nums.insert(nums.begin(), temNum);
// 			isSorted = false;
// 		}
// 	}
// 	if (isSorted)
// 	{
// 		for (int i = 1; i < nums.size(); i++)
// 		{
// 			if (nums[i - 1] < nums[i])
// 			{
// 				isSorted = false;
// 				break;
// 			}
// 		}
// 		if (isSorted)
// 			return nums[k - 1];
// 		else
// 		{
// 			temNum = nums[nums.size() - 1];
// 			nums[nums.size() - 1] = nums[0];
// 			nums[0] = temNum;
// 			return findKthLargest(nums, k);
// 		}
// 	}
// 	if (postion + 1 > k)
// 	{
// 		nums.erase(nums.begin() + postion, nums.end());
// 		return findKthLargest(nums, k);
// 	}
// 	if (postion + 1 < k)
// 	{
// 		nums.erase(nums.begin(), nums.begin() + postion);
// 		return findKthLargest(nums, k - postion);
// 	}
// 	if (postion + 1 == k)
// 		return nums[postion];
// }



int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
	int g_sum = 0;
	int c_sum = 0;
	for (int i = 0; i < gas.size(); i++)
	{
		g_sum += gas[i];
		c_sum += cost[i];
	}
	if (g_sum < c_sum)
		return -1;

	int rest = 0;
	int m_start = 0;
	for (int i = 0; i < cost.size(); i++)
	{
		rest += gas[i] - cost[i];
		if (rest < 0)
		{
			m_start = (i + 1) % cost.size();
			rest = 0;
		}
	}
	return m_start;
}


int main()
{
	vector<int> numb = { 5,9,3,2,1,0,2,3,3,1,0,0 };
	//cout << canJump(numb) << endl;
	return 0;
}