#include <bits/stdc++.h>
using namespace std;
struct cmp{
  bool operator()(vector<int>&a,vector<int>&b){
    return a[1]-b[1];
  }
};
int intervalSchedule(vector<vector<int>>&intvs){
  if(intvs.size()==0) return 0;
  sort(intvs.begin(),intvs.end(),cmp());
  int count=1;
  int x_end = intvs[0][1];
  for(auto it:intvs){
    int start = it[0];
    if(start>=x_end){
      count++;
      x_end = it[1];
    }
  }
  return count;
}
