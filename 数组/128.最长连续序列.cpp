#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution{
public:
    int longestConsecutive(vector<int>&nums){
      if(nums.size() == 0) return 0;
      sort(nums.begin(),nums.end());
      int n=nums.size();
      int maxval=1,cur=1;
      for(int i=1;i<n;i++){
        if(nums[i]==nums[i-1]) cur++;
        else{
          maxval=max(maxval,cur);
          cur=1;
        }
      }
      return max(maxval,cur);
    }
    int longestConsecutive_(vector<int>&nums){
      unordered_set<int> set;
      for(const int&num:nums){
        set.insert(num);
      }
      int longestStreak=0;
      for(const int&num:set){
        if(!set.count(num-1)){
          int currentNum=num;
          int currentStreak=1;
          while(set.count(currentNum+1)){
            currentNum++;
            currentStreak++;
          }
          longestStreak=max(longestStreak,currentStreak);
        }
      }
      return longestStreak;
    }
};
