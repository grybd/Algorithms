#include <vector>
using namespace std;

class Solution {
public:
    vector<int>v1 = {-1,-1};
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
        {
            return v1;
        }
        v1[0] = findfirstPosition(nums,target);
        if(v1[0]==-1)
        {
            return v1;
        }
        v1[1] =  findlastPosition(nums,target);
        return v1;
    }
private:
       int findfirstPosition(vector<int>nums,int target)
       {
           int left = 0 ;
           int right = nums.size()-1;
           while(left<=right)
           {
               int mid = left + (right-left)/2;
               if(nums[mid]==target)
               {
                   right = mid - 1;
               }
               else if(nums[mid]<target)
               {
                   left = mid + 1;
               }
               else{
                   right = mid - 1;
               }
           }
           //
           if(left!=(int)nums.size()&&nums[left]==target)
           {
               return left;
           }
           return -1;
       }
       int findlastPosition(vector<int>nums,int target)
       {
           int left = 0 ;
           int right = nums.size()-1;
           while(left<=right)
           {
               int mid = left + (right-left)/2;
               if(nums[mid]==target)
               {
                   left = mid + 1;
               }
                else if(nums[mid]<target)
               {
                   left = mid + 1;
               }
               else{
                   right = mid - 1 ;
               }
           }
           if(right!=-1&&nums[right]==target) return right;
           return -1;
       }
};
