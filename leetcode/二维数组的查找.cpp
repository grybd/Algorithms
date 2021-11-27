#include <vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int n=matrix.size();
        int m = matrix[0].size();

        bool tmp=false;
        for(int i=0;i<n;i++)
        {

            bool fres=findT(matrix[i],target);

            if(fres)
            {
                tmp=fres;
                break;
            }

        }

       return tmp;

    }

    bool findT(vector<int>&nums,int target)
    {
        int k=nums.size();
        bool flag=false;
        for(int i=0;i<k;i++)
        {
            if(nums[i]==target)
            {
                 flag=true;
                 break;
            }
        }
        return flag;
    }
};
