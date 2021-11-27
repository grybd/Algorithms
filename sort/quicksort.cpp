#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void quicksort(vector<int>&arr,int left,int right){
  int i=left,j=right,temp=arr[right];
  if(left>=right) return;
  while(i!=j)
  {
    while(arr[i]<=temp&&i<j) i++;
    while(arr[j]>=temp&&i<j) j--;
    if(i<j)
    {
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i],arr[right]);
  quicksort(arr,left,i-1);
  quicksort(arr,i+1,right);
}
int main(){
  vector<int>arr={1,3,3,2,2,5,4,6,7};
  quicksort(arr,0,arr.size()-1);
  for(int i=0;i<(int)arr.size();i++)
  cout<<arr[i]<<" ";
  return 0;
}
