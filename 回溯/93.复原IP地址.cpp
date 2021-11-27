#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution{
private:
    vector<string> paths;
    vector<string> result;
    void backtracking(string&s,int start){
      if(start==(int)s.size()&&paths.size()==4){
        //temp中有4段且s结束
        string str=paths[0];
        for(int i=0;i<3;++i){
          str=str+'.'+paths[i+1];
        }
        result.push_back(str);
        return ;
      }
      else if(start<(int)s.size()&&paths.size()==4){
        //s中有字符没用完
        return ;
      }
      for(int i=1;i<=3;i++){
        //指针越界直接返回
        if(start>(int)s.size()) return;
        if(i!=1&&s[start]=='0') return;
        string str=s.substr(start,i);//切割字符串
        if(isValid(str)){
          paths.push_back(str);
          backtracking(s,start+i);
          paths.pop_back();
        }
        else{
          break;
        }
      }
    }
    bool isValid(string&s){
      //if(i!=1&&s[start]=='0') return false;
      int num=0;
      for(int j=0;j<(int)s.size();j++){
        if(s[j]>'9'||s[j]<'0') return false;
        num=num*10+(s[j]-'0');
        if(num>255) return false;
      }
      return true;
    //  if(i==3&&atoi(s.c_str())>255) return false;
    }
public:
  vector<string> restoreIpAddresses(string s) {
     backtracking(s,0);
     return result;
 }
};
