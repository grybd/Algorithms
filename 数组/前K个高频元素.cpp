#include<bits/stdc++.h>
using namespace std;

int top_M_sum_1(vector<int>&nums,int M){
//sort(nums.begin(),nums.end());
priority_queue<int,gr()>q;
  int sum = 0;
  for(int i=0;i<M;i++){
    sum += nums[i];
  }
  return sum;
}

int top_M_sum_2(vector<int>&nums){
  int sum=0;
  for(int i=0;i<(int)nums.size();i++){
    sum+=nums[i];
  }
  return sum;
}
int main(){
  vector<int>nums;
  int N,M;
  cin>>N>>M;
  while(N--){
    int in;
    cin>>in;
    nums.push_back(in);
  }
  if(N>=M){
   cout<<top_M_sum_1(nums,M)<<endl;
 }else{
   cout<<top_M_sum_2(nums)<<endl;
 }
}


/*
class Solution {
public:
    struct cmp{
      bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.second>b.second;
      }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<int>res;
      unordered_map<int, int>map;
      for(int i=0;i<(int)nums.size();i++){
        map[nums[i]]++;
      }
      priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>freq;
      for(auto i:map){
        freq.push(i);
        if((int)freq.size()>k) freq.pop();
      }
      while(!freq.empty()){
        res.push_back(freq.top().first);
        freq.pop();
      }
      return res;
    }
};
*/
