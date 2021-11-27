#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  bool isEqu_1(string& s1,string& s2)
  {
    int n=s1.size();
    for(int i=0;i<n;i++)
    {
      if(s1[i]=!s2[i]) return false;
    }
    return true;
  }

  bool isEqu_2(string &s1,string &s2)
  {
    int m=s1.size();
    if(m%2==1) return isEqu_1(s1,s2);
    string s1_1,s1_2,s2_1,s2_2;
    for(int i=0;i<m/2;i++){
      s1_1[i]=s1[i];
      s1_2[i+2/m]=s1[i+2/m];
      s2_1[i]=s2[i];
      s2_2[i+2/m]=s2[i+2/m];
    }
    return  isEqu_2(s1_1,s2_1)&&isEqu_2(s1_2,s2_2)&&isEqu_2(s1_2,s2_1)&&isEqu_2(s1_1,s2_2);
  }
};
int main()
{
    unordered_map<bool,string> map;
    map[true]="YES";
    map[false]="NO";
    Solution s;
    int n=0;
    cin>>n;
    vector<string> vec;
    string str;
    for(int i=0;i<2*n;i++)
    {
      cin>>str;
      vec.push_back(str);
    }
    int i=0;
    while(i<2*n){
      if(vec[i].size()%2==1){
        cout<<vec[i].size();
        cout<<map[s.isEqu_1(vec[i],vec[i+1])]<<'\n';
      }
      cout<<map[s.isEqu_2(vec[i],vec[i+1])]<<'\n';
      i=i+2;
    }
    }
