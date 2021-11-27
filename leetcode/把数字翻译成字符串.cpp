#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  /*
    int translateNum(int num) {
      string s=to_string(num);
      int len = (int)s.length();
      vector<int> dp(len+1);
      dp[0]=1;
      dp[1]=1;
      for(int i=2;i<len+1;i++)
      {
        string temp=s.substr(i-2,2);
        if(temp>="10"&&temp<="25")
        {
          dp[i]=dp[i-2]+dp[i-1];
        }
        else{
          dp[i]=dp[i-1];
        }
      }
      return dp[len];
}
*/
    int translateNum(int num){
      string s=to_string(num);
      int len=s.length();

      int prev=1;
      int curv=1;

      for(int i=2;i<len+1;i++)
      {
        string temp=s.substr(i-2,2);
        if(temp>="10"&&temp<="25")
        {
          int p=curv;
          curv=curv+prev;
          prev=p;
        }
        else{
        prev=curv;
        }
      }
      return curv;
    }
};
