#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution{
public:
  void find_ans(vector<int>&nums)
  {  
    unordered_map<int,char>map;
    vector<char>ans;
    vector<int>res;

    vector<char>vec={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for(int i=0;i<26;i++)
    {
      map[i+1]=vec[i];
    }
    int tem=0;
    int temp=0;
    int tem_pre;
    for(int num:nums)
    {
       tem=num%5;
       tem_pre=tem;
      if(tem){
        tem=1;
      }
      else{
        tem=0;
      }
     temp=num/5+tem;
     ans.push_back(map[temp]);

     if(tem_pre==0) res.push_back(5);
     else{
       res.push_back(tem_pre);
     }
    }
    for(int i=0;i<ans.size();i++)
    {
      cout<<ans[i]<<res[i]<<'\n';
    }
  }
};

int main(){
  int a,b,c;
  cin>>a;
  cin>>b;
  vector<int> vec;
  for(int i=0;i<a;i++)
  {
    cin>>c;
    vec.push_back(c);
  }

  Solution s;
  s.find_ans(vec);
}
