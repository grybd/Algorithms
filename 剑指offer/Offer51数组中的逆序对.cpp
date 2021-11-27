#include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        if(len<2) return 0;
        vector<int>helper(len);
        return reversePairs(nums,0,len-1,helper);
    }
private:
    int reversePairs(vector<int>&nums,int left,int right,vector<int>&helper){
        if(left==right) return 0;
        int mid = left + (right-left)/2;
        int leftPairs=reversePairs(nums,left,mid,helper);
        int rightPairs=reversePairs(nums,mid+1,right,helper);
        if(nums[mid]<=nums[mid+1]) return leftPairs+rightPairs;
        int crossPairs=mergerCount(nums,left,mid,right,helper);
        return leftPairs+rightPairs+crossPairs;
    }
    int mergerCount(vector<int>&nums,int left,int mid,int right,vector<int>&helper){
        for(int i=left;i<=right;i++){
            helper[i]=nums[i];
        }
        int i=left,j=mid+1;
        int count=0;
        for(int k=left;k<=right;k++){
            if(i==mid+1) {
                nums[k]=helper[j];
                j++;
            }else if(j==right+1){
                nums[k]=helper[i];
                i++;
            }else if(helper[i]<=helper[j]){
                nums[k]=helper[i];
                i++;
            }else{
                nums[k]=helper[j];
                count+=mid-i+1;
                j++;
            }
        }
        return count;
    }   
};
