#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  stack<int>sta;
  int count(vector<int>&high,int n,int m){
    if(high.size()==0) return 0;
    int count = 0;
      sta.push(high[0]);
      for(int i=1;i<n;i++){
        if(high[i]>sta.top()){
          sta.push(high[i]);
          continue;
        }
        while(!sta.empty()&&sta.top()<=high[i]){
           count++;
           sta.pop();
        }
        sta.push(high[i]);
      }
      return count;
    }

  };

  int main(){
    Solution s;
    int n;
    cin>>n;
    while(n--){
      int a,b;
      cin>>a;
      cin>>b;
      vector<int>ans;
      while(a--){
        int t;
        cin>>t;
        ans.push_back(t);
      }
      cout<<s.count(ans,a,b)<<endl;
    }
    return 0;
  }
