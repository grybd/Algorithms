#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
   private:
      vector<string>result;
      string path;
    public:
        vector<string> permutation(string s){
        sort(s.begin(),s.end());
        int n = s.size();
        vector<bool>used(n,false);
        backtracking(s,used,n);
        return result;
      }
    void backtracking(string& s,vector<bool>&used,int n){
      if((int)path.size()==n){
        result.push_back(path);
        return ;
      }
      for(int i=0;i<n;i++){
        if(i>0&&(s[i]==s[i-1])&&used[i-1]==false) continue;
        if(!used[i]){
            used[i] = true;
            path.push_back(s[i]);
            backtracking(s,used,n);
            path.pop_back();
            used[i] = false;
          }else{
          continue;
        }
      }
    }
};
