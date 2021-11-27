#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
  //哈希表
    int findRepeatNumber_(vector<int>& nums) {
      unordered_map<int,bool> map;
      for(int num:nums){
        if(map[num]) return num;
        map[num]=true;
      }
      return -1;
    }
    //原地置换
  int findRepeatNumber(vector<int>&nums){
    for(int i=0;i<(int)nums.size();i++){
      while(i!=nums[i]){
        swap(nums[i],nums[nums[i]]);
        if(nums[i]==nums[nums[i]]) return nums[i];
      }
      return -1;
    }
  }
};
