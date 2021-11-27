#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isStraight(vector<int>&nums)
  {
    int joker=0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<4;i++)
    {
      if(nums[i]==0) joker++;
      else if(nums[i+1]==nums[i]) return false;
    }
    return nums[4]-nums[joker]<5;
  }
};
