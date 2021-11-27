#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool cmp (vector<int>&a,vector<int>&b){
  if(a[1]==b[1]){
    return a[0]<b[0];
  }
  return a[1]<b[1];
}

int main(){
  int n;
  cin>>n;
  while(n--){
    int num;
    cin>>num;
    vector<vector<int>>vec(num,vector<int>(2,0));
    for(int i=0;i<num;i++){
      int a,b;
      cin>>a;cin>>b;
      vec[i][0] = a;
      vec[i][1] = b;
    }
    sort(vec.begin(),vec.end(),cmp);
    int sum = 0;
    bool flag = true;
    for(int i=0;i<num;i++){
      sum += vec[i][0];
      if(sum>vec[i][1]){
        flag = false;
        break;
      }
    }
    if(flag) cout<< "Yes" << endl;
    else{
      cout << "No" << endl;
    }
  }
  return 0;
}
