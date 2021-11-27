#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {

      if(s.empty())
      {
        return {};
      }

    sort(s.begin(),s.end());
    vector<string> res;
    //标记字符是否遍历过;
    vector<bool> used(s.size(),false);
    string path;

    DFS(s,path,res,used);
    return res;
    }

    void DFS(string &s,string &path,vector<string> &res,vector<bool> &used)
    {
      //回溯结束条件;
      if(path.size()==s.size())
      {
        res.push_back(path);
        return ;
      }

      for(int i=0;i<(int)s.size();i++)
      {
        //排除不合法的选择


        if(i>0&&!used[i-1]&&s[i-1]==s[i])
        {
          continue;
        }

        if(used[i]==false)
        {
          used[i]=true;

          //做选择
          path.push_back(s[i]);
          DFS(s,path,res,used);
          //撤销选择
          path.pop_back();
          used[i]=false;
        }

      }
    }
};
