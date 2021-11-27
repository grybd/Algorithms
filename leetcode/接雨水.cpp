#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
    int trap(vector<int>&height){
      int sum = 0;
      for(int i=1;i<(int)height.size()-1;i++){
        int max_left = 0;
        for(int j=i-1;j>=0;j--){
          if(height[j]>max_left){
            max_left = height[j];
          }
        }
        int max_right=0;
        //找出最右边最高
        for(int j=i+1;j<(int)height.size();j++){
          if(height[j]>max_right){
            max_right = height[j];
          }
        }
        //找出两端较小
        int min_ = min(max_left,max_right);
        if(min_>height[i]){
          sum = sum + (min_-height[i]);
        }
      }
      return sum;
    }
    //动态规划
    int trap__(vector<int>&height){
      int n = height.size();
      int sum=0;
      vector<int> max_left(n);
      vector<int>max_right(n);
      for(int i=1;i<(int)height.size()-1;i++){
        max_left[i] = max(max_left[i-1],height[i-1]);
      }
      for(int i=height.size()-2;i>=0;i--){
        max_right[i]=max(max_right[i+1],height[i+1]);
      }
      for(int i=1;i<(int)height.size()-1;i++){
        int min_ = min(max_left[i],max_right[i]);
        if(min_>height[i]){
          sum = sum + (min_-height[i]);
        }
      }
      return sum;
    }
    //单调栈
    int _trap_(vector<int>&height){
      stack<int>sta;
      int i=0,ans=0;
      while(i<(int)height.size()){
        while(!sta.empty()&&height[i]>height[sta.top()]){
          int top = sta.top();
          sta.pop();
          if(sta.empty()) break;
          int distance = i-sta.top()-1;
          int bounded_height = min(height[i],height[sta.top()])-height[top];
          ans+=distance*bounded_height;
        }
        sta.push(i++);
      }
      return ans;
    }
};
