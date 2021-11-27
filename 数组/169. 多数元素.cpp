#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
      int majorityElement(vector<int>& nums) {
        unordered_map<int,int> record;//元素->频率
        for(int i=0;i<(int)nums.size();++i)
        {
            record[nums[i]]++;
            if(record[nums[i]]>(int)nums.size()/2)return nums[i];
        }
        return -1;
    }
};
