#include <vector>
#include <deque>
using namespace std;

class Solution{
public:
  vector<int> maxSlidingWindow(vector<int>&nums,int k)
  {
    vector<int> res;
    deque<int> tem;

    for(int i=0;i<nums.size();i++)
    {
      while(!tem.empty()&&nums[i]>nums[tem.back()])
      {
        tem.pop_back();
      }

      if(!tem.empty()&&i-tem.front()>k-1)
      {
        tem.pop_front();
      }
      tem.push_back(i);
      if(i>=k-1) res.push_back(nums[tem.front()]);
    }
    return res;
  }
};
