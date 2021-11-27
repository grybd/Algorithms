#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution{
public:
  vector<int>getLeastNumbers_1(vector<int>&arr,int k){
    vector<int>res;
    if(arr.empty()||k==0) return res;
    sort(arr.begin(),arr.end());
    for(int i:arr){
      res.push_back(i);
    }
    return res;
  }
  vector<int>getLeastNumbers_2(vector<int>&arr,int k){
    vector<int>res(k);
    priority_queue<int,vector<int>,less<int>>max_heap;
    if(arr.empty()||k==0) return res;
    for(int i=0;i<k;++i) {max_heap.push(arr[i]);}
    for(int i=k;i<(int)max_heap.size();++i){
      if(arr[i]<max_heap.top()){
        max_heap.pop();
        max_heap.push(arr[i]);
      }
    }
    for(int i=0;i<k;++i){
      res[i]=max_heap.top();
      max_heap.pop();
    }
    return res;
  }
};
