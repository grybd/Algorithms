#include <bits/stdc++.h>
using namespace std;
int cnt=0;
bool visit[30][30]={0};
bool g[30][30]={0};
int n,m,cx,cy;
int next[2][2]={{1,0},{0,1}};

void dfs(int x,int y){
  if(x==n&&y==m){
    cnt++;
    return ;
  }
  if(x<0||y<0||g[x][y]) return;
  if(x+1<=n&&!g[x+1][y]&&!visit[x+1][y]){
    visit[x+1][y]=1;
    dfs(x+1,y);
    visit[x+1][y]=0;
  }
  if(x-1>=0&&!g[x-1][y]&&!visit[x-1][y]){
    visit[x-1][y]=1;
    dfs(x-1,y);
    visit[x-1][y]=0;
  }
  if(y+1<=m&&!g[x][y+1]&&!visit[x][y+1]){
    visit[x][y+1]=1;
    dfs(x,y+1);
    visit[x][y+1]=0;
  }
}

int main(){
  g[cx][cy]=1;
  cin>>n>>m>>cx>>cy;
  if(cx-1>=0&&cy-2>=0)g[cx-1][cy-2]=1;
  if(cx-1>=0&&cy+2<=m)g[cx-1][cy+2]=1;
  if(cx+1<=n&&cy-2>=0)g[cx+1][cy-2]=1;
  if(cx+1<=n&&cy+2<=m)g[cx+1][cy+2]=1;
  if(cx-2>=0&&cy-1>=0)g[cx-2][cy-1]=1;
  if(cx-2>=0&&cy+1<=m)g[cx-2][cy+1]=1;
  if(cx+2<=n&&cy+1<=m)g[cx+2][cy+1]=1;
  if(cx+2<=n&&cy-1>=0)g[cx+2][cy-1]=1;
  dfs(0,0);
  cout<<cnt;
  return 0;
}
