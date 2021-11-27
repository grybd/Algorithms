#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
  unordered_map<char,string>map={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
  vector<string>result;
  string path;
  void backtracking(string &digits,int index){
      if(index==(int)digits.size()){
        result.push_back(path);
        return ;
      }
      for(int i=0;i<(int)map[digits[index]].size();i++){
         path.push_back(map[digits[index]][i]);
         backtracking(digits,index+1);
         path.pop_back();
      }
    }
  };
