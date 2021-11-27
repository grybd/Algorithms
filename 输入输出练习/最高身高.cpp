#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,index_i,index_j,max=INT_MIN;
  cin>>n>>m;
  int a[n][m];
  for(int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin>>a[i][j];
      if(a[i][j]>max){
        max = a[i][j];
        index_i = i+1;
        index_j = j+1;
      }
    }
  }
  cout<< index_i << " " <<index_j << endl;
  return 0;
}
