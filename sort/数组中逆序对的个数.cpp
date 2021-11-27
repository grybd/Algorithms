#include<vector>
using namespace std;

class Solution{
private:
  int count=0;
public:
int reversePair(vector<int>&nums){
    int count = 0;
    int len=nums.size();
    for(int i=0;i<len-1;i++){
      for(int j=i+1;j<len-1;j++){
        if(nums[i]>nums[j]){
          count++;
        }
      }
    }
    return count;
  }
int _reversePair(vector<int>&nums){
  mergeSort(nums,0,nums.size()-1);
  return count;
}
void mergeSort(vector<int>&nums,int left,int right){
  if(left>=right) return;
  int mid=left+(right-left)/2;
  mergeSort(nums,left,mid);
  mergeSort(nums,mid+1,right);
  merge(nums,left,mid,right);
}
void merge(vector<int>&nums,int left,int mid,int right){
  vector<int>temp(right-left+1);
  int i=left;
  int j=mid+1;
  int tempIndex=0;
  while(i<=mid&&j<=right){
    if(nums[i]<=nums[j]) temp[tempIndex++]=nums[i++];
    else {
      temp[tempIndex++]=nums[j++];
      count+=mid-i+1;
    }
  }
  while(i<=mid){
    temp[tempIndex++]=nums[i++];
  }
  while(j<=right){
    temp[tempIndex++]=nums[j++];
  }
  for(int i=0;i<tempIndex;++i){
    nums[left+i]=temp[i];
  }
}
};
