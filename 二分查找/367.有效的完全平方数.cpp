#include <vector>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left=0,right=num;
        while(left<=right){
            int mid=left+(right-left)/2;
            if((long long)mid*mid==num) return true;
            else if((long long) mid*mid<num) left=mid+1;
            else right=mid-1;
        }
        return false;
    }
};
