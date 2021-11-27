#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

class Solution{
public:
    //小顶堆
    int findKthLargest(vector<int>&nums,int k){
      if(nums.empty()||k<1) return INT_MIN;
      int len=nums.size();
      //小顶堆，升序排列
      priority_queue<int,vector<int>,greater<int>> min_heap;
      //构建大顶堆，降序排列
      priority_queue<int,vector<int>,less<int>> max_heap;

      for(int i=0;i<k;i++){
        min_heap.push(nums[i]);
      }

      for(int i=k;i<len;i++){
        if(nums[i]>=min_heap.top()){
          //若 nums[i] 大于等于堆顶元素，弹出堆顶元素并将 nums[i] 入堆
          min_heap.pop();
          min_heap.push(nums[i]);
        }
      }
      return min_heap.top();
    }
    //快速选择排序
    int findKthLargest_(vector<int>&nums,int k){
     if(nums.size()==0||k<1) return INT_MIN;
     return quickSelection(nums,0,nums.size()-1,nums.size()-k);
   }
   int quickSelection(vector<int>&nums,int left,int right,int index)
   {
     if(left>=right) return nums[index];
     int j=partition(nums,left,right);
     if(j==index) return nums[j];
     return j<index?quickSelection(nums,j+1,right,index):quickSelection(nums,left,j-1,index);
   }
   int partition(vector<int>&nums,int left,int right){
     int value=nums[left];
     int i=left,j=right+1;
     while(true){
       //while(i<j&&nums[j]>value) j--;
       while(++i<=right&&nums[i]<value) ;
       while(--j>=left&&nums[j]>value) ;
       if(i>=j) break;
       swap(nums[i],nums[j]);
     }
     swap(nums[left],nums[j]);
     return j;
   }
};
