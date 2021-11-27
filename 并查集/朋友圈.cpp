//并查集的应用 亲戚问题
/*
#include <cstdio>
using namespace std;
#define MAXN 5005

int fa[MAXN],rank[MAXN];

inline void init(int n) {
  for(int i=1; i<=n; ++i){
    fa[i] = i;
    rank[i] = 1;
  }
}
int find(int x){
  return x==fa[x]?x:(fa[x]=find(fa[x]));
}
inline void merge(int i,int j){
  int x =find(i),y=find(j);
  if(rank[x]<=rank[y]) fa[x]=y;
  else{
    fa[y]=x;
  }
  if(rank[x]==rank[y]&&x!=y) rank[y]++;
}

int main(){
  int n,m,p,x,y;
  scanf("%d%d%d",&n,&m,&p);
  init(n);
  for(int i=0;i<m;++i){
    scanf("%d%d",&x,&y);
    merge(x,y);
  }
  for(int i=0;i<p;++i){
    scanf("%d%d",&x,&y);
    printf("%s\n",find(x)==find(y)?"Yes":"No");
  }
  return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
class friendsCircle{
private:
  // curMap记录父节点，sizeMap记录该点所在朋友圈的大小，rankMap记录根节点的秩
  unordered_map<int,int>curMap,sizeMap,rankMap;
private:
  //寻找根节点
  int findroot(int x){
    return x == curMap[x]?x:findroot(curMap[x]);
  }

public:
  //向朋友圈插入新的朋友组合
  void append(int x,int y){
    if(curMap.find(x)==curMap.end()&&curMap.find(y)==curMap.end()){
      //插入的两点都不在朋友圈中
      curMap[x] = x;
      curMap[y] = x;
      rankMap[x] = 1;
    }else if(curMap.find(x)!=curMap.end()&&curMap.find(y)==curMap.end()){
      //x在朋友圈中，y不在朋友圈中,将y更新为x根节点的子节点
      int xroot = findroot(x);
      curMap[y] = xroot;
    }else if(curMap.find(x)==curMap.end()&&curMap.find(y)!=curMap.end()){
      int yroot = findroot(y);
      curMap[x] = yroot;
    }else{
      // 若 x 和 y 都在朋友圈中，根据他们根节点的秩对两个朋友圈合并
      int xroot = findroot(x);
      int yroot = findroot(y);
      if(rankMap[xroot]>=rankMap[yroot]){
        curMap[yroot] = xroot;
        rankMap[xroot] = max(rankMap[xroot],rankMap[yroot]+1);
      }else{
        curMap[xroot] = yroot;
      }
    }
  }
  //计算最大朋友圈的大小
  int maxCircle(){
    int maxSize=0;
    for (auto &it:curMap){
      maxSize=max(maxSize,++sizeMap[findroot(it.first)]);
    }
   return maxSize;
  }
};

int main(){
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    friendsCircle FRDC;
    int x,y;
    while(n--){
      cin>>x>>y;
      FRDC.append(x,y);
    }
    cout<<FRDC.maxCircle()<<endl;
  }
}
