#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
/*
class Solution{
public:
vector<vector<int>> findContinuousSequence(int target) {
    int i = 1; // 滑动窗口的左边界
    int j = 1; // 滑动窗口的右边界
    int sum = 0; // 滑动窗口中数字的和
    vector<vector<int>> res;
    while (i <= target / 2) {
        if (sum < target) {
            // 右边界向右移动
            sum += j;
            j++;
        } else if (sum > target) {
            // 左边界向右移动
            sum -= i;
            i++;
        } else {
            // 记录结果
            vector<int> arr;
            for (int k = i; k < j; k++) {
                arr.push_back(k);
            }
            res.push_back(arr);
            // 左边界向右移动
            sum -= i;
            i++;
        }
    }
    return res;
}
};

int main()
{
  Solution s;
  vector<vector<int>> res=s.findContinuousSequence(9);
  int n=res.size();
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<(int)res[i].size();j++)
    {
      cout<<res[i][j]<<" ";
    }
    cout<< "\n";
  }
}
*/
/*
class Solution{
public:
  vector<vector<int>> findContinuousSequence(int target)
  {
    int i=1;
    double j=2.0;
    vector<vector<int>> res;
    while(i<j){
      j=(-1+sqrt(1+4*(2*target+(long)i*i-i)))/2;
      if(j==(int)j)
      {
        vector<int>ans;
        for(int k=i;k<=(int)j;k++)
        {
          ans.push_back(k);
        }
        res.push_back(ans);
      }
      i++;
    }

    return res;

  }
};
*/

class Solution{
public:
  vector<vector<int>> findContinuousSequence(int target)
  {
    int i=1,j=2,s=0;
    vector<vector<int>> res;
    while(i<j)
    {
      if(s==target){
        vector<int>ans;
        for(int k=i;k<=j;k++)
        {
          ans.push_back(k);
        }
        res.push_back(ans);
      }

      if(s>target)
      {
        s-=1;
        i++;
      }
      else {
        j++;
        s += j;
      }

    }
    return res;
  }
};
