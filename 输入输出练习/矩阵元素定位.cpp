#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[10000][10000];
  int n,m,x,y;
  cin>>n>>m;
  for (int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  cin>>x>>y;
  cout<<a[x-1][y-1];
  return 0;
}
