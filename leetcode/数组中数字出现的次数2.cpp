//在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int singleNumber(vector<int>&nums){
    unordered_map<int,int>mp;
    for(int n : nums) mp[n]++;

    int ans;
    for(auto pr:mp)
    {
      if(pr.second==1){
        ans=pr.first;
        break;
      }
    }
    return ans;
  }
};
