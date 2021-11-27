#include <vector>
#include <queue>
using namespace std;
/*
class Solution{
public:
  vector<int> getLeastNumbers(vector<int>& arr,int k)
  {
    quickSort(arr,0,arr.size()-1);
    vector<int>res;
    for(int i=0;i<k;i++)
    {
      res.push_back(arr[i]);
    }
    return res;
  }
private:
  void quickSort(vector<int>&arr,int l,int r)
  {
    if(l>=r) return;
    int i=l;int j=r;
    while(i<j)
    {
      while(i<j&&arr[j]>=arr[l]) j--;
      while(i<j&&arr[i]<=arr[l]) i++;
      swap(arr[i],arr[j]);
    }
    swap(arr[i],arr[l]);
    quickSort(arr,l,i-1);
    quickSort(arr,i+1,r);
  }
};*/

class Solution{
public:
  vector<int> getLeastNumbers(vector<int>&arr,int k)
  {
    vector<int> vec(k,0);
    if(k==0)
    {
      return vec;
    }
    priority_queue<int> Q;
    for(int i=0;i<k;++i)
    {
      Q.push(arr[i]);
    }
    for(int i=k;i<(int)arr.size();++i)
    {
      if(Q.top()>arr[i])
      {
        Q.pop();
        Q.push(arr[i]);
      }
    }

    for(int i=0;i<k;++i)
    {
      vec[i]=Q.top();
      Q.pop();
    }
    return vec;
  }
};
