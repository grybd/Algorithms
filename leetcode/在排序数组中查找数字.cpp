#include <vector>
using namespace std;

class Solution {
    public:
     int search(vector<int> nums, int target) {
        return helper(nums, target) - helper(nums, target - 1);
    }
    int helper(vector<int> nums, int tar) {
        int i = 0, j = nums.size() - 1;
        while(i <= j) {
            int m = i+(j-i) / 2;
            if(nums[m] <= tar) i = m + 1;
            else j = m-1;
        }
        return i;
    }
};
