#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution{
public:
  vector<int> find(vector<int>&nums)
  {
    unordered_map<int,int>map;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++)
    {
      cout <<nums.size()<<' '<< nums[i]<<'\n';
    }
  //  int res=nums[0];
  //  int temp=0;

    //int ans=0;
    for(int i=0;i<(int)nums.size();i++){
      map[nums[i]]=0;
    }
    for(int num:nums)
    {
      if(map.count(num))
      {
        map[num]++;
      }
      else{
        map[0]=num;
      }
      /*
      if(res==num)
      {
        temp++;
      }
      else{
        res=num;
        temp=0;
      }
      ans=max(ans,temp);
    }
    return {res,ans};
    */
  }
 int temp=1;
 int ans;
 for(int i=0;i<nums.size();i++)
 {
   if(temp<map[nums[i]])
   {
     temp=map[nums[i]];
     ans=nums[i];
   }
 }
 return {ans,temp};
}
};

int main(){
  int a=0,b=0,c=0;
  cin>>a; cin>>b;
  vector<int> vec,vec1(2);
  for(int i=0;i<a;i++)
  {
    cin>>c;
    vec.push_back(c);
  }
  Solution s;
  vec1=s.find(vec);
  cout << vec1[0]<<' '<<vec1[1];
}
