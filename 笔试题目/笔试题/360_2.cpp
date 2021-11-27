#include<bits/stdc++.h>
using namespace std;

int MinCost(vector<int>&ans){

}

int main(){

  vector<int>ans;

  int n;
  cin>>n;
  while(n--){
    int a;
    cin >> a;
    ans.push_back(a);
  }

  int min_cost = MinCost(ans);
  return min_cost;
}
