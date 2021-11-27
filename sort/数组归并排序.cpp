#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void merge(vector<int>&arr,int left,int mid,int right);
void mergesort(vector<int>&arr, int left,int right)
{
  if(left>=right) return;
  int mid=(left+right)/2;
  mergesort(arr,left,mid);//左边归并排序，使得左子序列有序；
  mergesort(arr,mid+1,right);//右边归并排序，使得右子序列有序；
  merge(arr,left,mid,right);//将两个有序子数组合并操作；
}

void merge(vector<int>&arr,int left,int mid,int right)
{
  vector<int>temp(right-left+1);
  int i=left;//左序列指针
  int j=mid+1;//右序列指针；
  int t=0;//临时数组指针；
  while(i<=mid&&j<=right)
  {
    if(arr[i]<=arr[j])
    {
      temp[t++]=arr[i++];
    }
    else
    {
      temp[t++]=arr[j++];
    }
  }
  while(i<=mid)
  {
    //将左边剩余元素填充进temp中
    temp[t++]=arr[i++];
  }
  while(j<=right)
  {
    //将右序列剩余元素填充进temp中
    temp[t++]=arr[j++];
  }
  t=0;
  //将temp中的元素全部拷贝到原数组中
  while(left<=right)
  {
    arr[left++]=temp[t++];
  }
}

int main()
{
  std::vector<int> arr = {1,4,3,2,6,7,5,9,8};
  mergesort(arr,0,8);
  for(int i=0;i<9;i++)
  {
    cout<<arr[i]<<endl;
  }
}
