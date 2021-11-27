#include <vector>
#include <string>
using namespace std;

class Solution{
    public:
       bool canJump(vector<int>&nums){
           if(nums.size()==0) return false;
           int longestPos=0,len=nums.size();
           //longestPos表示在当前index处最远能到达的index
           longestPos=nums[0];
           for(int i=0;i<len;i++){
               //如果当前能到达的最远index小于i，直接return false
               if(longestPos<i) return false;
               //更新longestPos
               longestPos=max(longestPos,i+nums[i]);
               if(longestPos>=len-1) return true;
           }
           return true;
       }
  };