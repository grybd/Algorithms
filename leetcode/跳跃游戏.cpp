#include <vector>
using namespace std;

class Solution{
public:
    bool canJump(vector<int>&nums){
      if(nums.size()==0) return false;
      int longestPos=0,len=nums.size();
      for(int i=0;i<len;i++){
        if(longestPos<i) return false;
        longestPos = max(longestPos,i+nums[i]);
        if(longestPos>=len-1) return true;
      }
      return false;
    }
};
