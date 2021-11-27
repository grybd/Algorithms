#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
      int count=0;
    public:
       vector<int>path;
       vector<vector<int>>ans;
       int min_w(vector<vector<int>>&m){
           vector<bool>used(m.size(),false);
           if(m.size()==0) return 0;
           backtrack(m,used,0);
          int min_t = ans[0][0];
          for(int i=1;i<(int)ans.size();i++){
            if(ans[i][0]<min_t){
              min_t = ans[i][0];
            }
          }
          return min_t;
       }
       void backtrack(vector<vector<int>>&m,vector<bool>&used,int n){
         if(n==(int)m.size()){
           ans.push_back(path);
           return ;
         }
         for(int i=0;i<(int)m.size();i++){
           if(!used[i]){
             if(count==0){
               count = m[i][0];
             }
           }
           if (used[i]) continue;
           if(count-m[i][0]<0) break;
           used[i] = true;
           count +=m[i][1];
           path.push_back(m[i][0]);
           backtrack(m,used,n+1);
           path.pop_back();
           used[i] =  false;
           count-=m[i][1];
         }
       }
};

int main(){
    vector<vector<int>>map;
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        map.push_back({a,b});
    }
    solution s;
    cout << s.min_w(map) <<endl;
    return 0;
}
