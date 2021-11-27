#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //1.排序
        sort(nums.begin(), nums.end());
        //2.遍历找出
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            if(nums[i]==nums[j])
            {
                return nums[i];
            }
        }
        return -1;
    }
};
