#include <bits/stdc++.h>
using namespace std;

int main(){

  int n,m,cx,cy;
  cin>>n>>m>>cx>>cy;
  long long f[40][40],g[40][40];
  f[0][0]=1;
  g[cx][cy]=1;

  if(cx-1>=0&&cy-2>=0)g[cx-1][cy-2]=1;
  if(cx-1>=0&&cy+2<=m)g[cx-1][cy+2]=1;
  if(cx+1<=n&&cy-2>=0)g[cx+1][cy-2]=1;
  if(cx+1<=n&&cy+2<=m)g[cx+1][cy+2]=1;
  if(cx-2>=0&&cy-1>=0)g[cx-2][cy-1]=1;
  if(cx-2>=0&&cy+1<=m)g[cx-2][cy+1]=1;
  if(cx+2<=n&&cy+1<=m)g[cx+2][cy+1]=1;
  if(cx+2<=n&&cy-1>=0)g[cx+2][cy-1]=1;

  //递推边界
  for(int i=1;i<=n;i++){
    if(!g[i][0]) f[i][0]=f[i-1][0];
  }
  for(int j=1;j<=m;j++){
    if(!g[0][j]) f[0][j]=f[0][j-1];
  }
  for(int i=0;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(g[i][j]) f[i][j]=0;
      if(!g[i][j]) f[i][j]=f[i][j-1]+f[i-1][j];
    }
  }
  cout<<f[n][m];
}
