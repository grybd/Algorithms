#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) {
            return vector<int>{-1, -1};
        }

        int firstPosition = findFirstPosition(nums, target);
        // 如果第 1 次出现的位置都找不到，肯定不存在最后 1 次出现的位置
        if (firstPosition == -1) {
            return vector<int>{-1, -1};
        }
        int lastPosition = findLastPosition(nums, target);
        return vector<int>{firstPosition, lastPosition};
    }

private:
    int findFirstPosition(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                // ① 不可以直接返回，应该继续向左边找，即 [left, mid - 1] 区间里找
                right = mid - 1;
            } else if (nums[mid] < target) {
                // 应该继续向右边找，即 [mid + 1, right] 区间里找
                left = mid + 1;
            } else {
                // 此时 nums[mid] > target，应该继续向左边找，即 [left, mid - 1] 区间里找
                right = mid - 1;
            }
        }

        // 此时 left 和 right 的位置关系是 [right, left]，注意上面的 ①，此时 left 才是第 1 次元素出现的位置
        // 因此还需要特别做一次判断
        if (left != nums.size() && nums[left] == target) {
            return left;
        }
        return -1;
    }

    int findLastPosition(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                // 只有这里不一样：不可以直接返回，应该继续向右边找，即 [mid + 1, right] 区间里找
                left = mid + 1;
            } else if (nums[mid] < target) {
                // 应该继续向右边找，即 [mid + 1, right] 区间里找
                left = mid + 1;
            } else {
                // 此时 nums[mid] > target，应该继续向左边找，即 [left, mid - 1] 区间里找
                right = mid - 1;
            }
        }
        // 由于 findFirstPosition 方法可以返回是否找到，这里无需单独再做判断
        return right;
    }
};
