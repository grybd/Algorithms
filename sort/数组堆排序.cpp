#include <bits/stdc++.h>
using namespace std;

class Solution{

  private:
    void adjust(vector<int>&nums,int len,int index){
        int left = 2*index+1;int right = 2*index+2;
        if(left>len) return;
        int maxIdx = index;
        if(left<len&&nums[left]>nums[maxIdx]){
          maxIdx = left;
        }
        if(right<len&&nums[right]>nums[maxIdx]){
          maxIdx = right;
        }
        if(maxIdx!=index){
          swap(nums[index],nums[maxIdx]);
          adjust(nums,len,maxIdx);
        }
    }

  public:
    void HeadSort(vector<int>&nums,int size){
        //构建大根堆
        for(int i=size/2-1;i>=0;i--){
          adjust(nums,size,i);
        }
        //堆排序开始
        for(int i=nums.size()-1;i>=1;i--){
          swap(nums[0],nums[i]);
          adjust(nums,i,0);
        }

    }
};

int main(){
  vector<int>vec = {1,9,2,5,3,2,4,6,7};
  Solution s;
  s.HeadSort(vec,vec.size());
  for(auto i:vec){
    cout << i << " ";
  }
  return 0;
}
