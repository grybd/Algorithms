#include <vector>
#include <iostream>
using namespace std;

//快速排序（从小到大）
void quickSort(int left, int right, vector<int>& arr)
{
	if(left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if(i < j)
		{
			swap(arr[i],arr[j]);
		}
	}
	//基准数归位
	swap(arr[i],arr[left]);
	quickSort(left, i - 1, arr);//递归左边
	quickSort(i + 1, right, arr);//递归右边
}

int main(){
  vector<int>arr={9,8,9,5,2,2,4,5,3,2,1};
  quickSort(0,arr.size()-1,arr);
  for(int i:arr){
    cout<<i<<' ';
  }
}
