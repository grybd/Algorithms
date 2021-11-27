#include <bits/stdc++.h>
using namespace std;
//递归二分法求解
vector<int> GetMid(vector<int>& A, vector<int>& B, int a_start,int a_end,int b_start,int b_end,int N)
{
	vector<int> result;
	//初始化中间位置
	int a_mid = (a_start + a_end) / 2;
	int b_mid = (b_start + b_end) / 2;
	//如果有答案了
	if (A[a_mid] == B[b_mid])
	{
		result.push_back(A[a_mid]);
		result.push_back(A[a_mid] > B[b_mid] ? B[b_mid] : A[a_mid]);
		return result;
	}
	if (a_start == a_end || b_start == b_end)
	{
		//判断两个start的值的大小
		if (A[a_start] > B[b_start])
		{
			result.push_back(B[b_start]);
			if (b_start + 1 < N)
			{
				if (A[a_start] > B[b_start + 1])
					result.push_back(B[b_start + 1]);
				else
					result.push_back(A[a_start]);
			}
			else
				result.push_back(A[a_start]);
		}
		else
		{
			result.push_back(A[a_start]);
			if (a_start + 1 < N)
			{
				if (A[a_start + 1] <= B[b_start])
					result.push_back(A[a_start + 1]);
				else
					result.push_back(B[b_start]);
			}
			else
				result.push_back(B[b_start]);
		}
		return result;
	}
	//递归更新边界值
	if (A[a_mid] > B[b_mid])
	{
		//如果当前a_start-a_end之间的长度为偶数，那么中间值就是mid
		if ((a_start + a_end) % 2 == 0)
		{
			return GetMid(A, B, a_start, a_mid, b_mid, b_end, N);
		}
		else
		{
			return GetMid(A, B, a_start, a_mid, b_mid + 1, b_end, N);
		}
	}
		//如果A的中位数<B的中位数，说明此时第N大的数在A的右边，B的左边，所以需要更新a_start以及b_end
	else
	{
		//如果当前a_start-a_end之间的长度为偶数，那么中间值就是mid
		if ((a_start + a_end) % 2 == 0)
		{
			return GetMid(A, B, a_mid, a_end, b_start, b_mid, N);
		}
		else
		{
			return GetMid(A, B, a_mid + 1, a_end, b_start, b_mid, N);
		}
	}
}

int main()
{
	vector<int> A = { 2,4,5,6,9 };
	//vector<int> B = { 2,4,5,6,9 };
	int N = A.size();
	vector<int> B = { 1,3,7,8,10 };
	vector<int> result = GetMid(A, B, 0, N-1,0,N-1,N);
	for(int i = 0;i <(int)result.size();i++)
		cout << result[i] << endl;
	cout << "结束" << endl;
	return 0;
}
