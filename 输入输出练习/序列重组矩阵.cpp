#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,s[100];
  int a[100][100];
  cin>>n>>m;
  for(int i=0;i<n*m;i++){
    cin>>s[i];
  }

  int k=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      a[i][j] = s[k];
      k++;
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
}
