#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> path;
    vector<vector<string>> result;
    void backtracking(const string&s,int startIndex){
      if(startIndex>=(int)s.size()){
        result.push_back(path);
        return;
      }
      for(int i=startIndex;i<(int)s.size();i++){
        if(isPalindrome(s,startIndex,i)){
          string str=s.substr(startIndex,i-startIndex+1);
          path.push_back(str);
        }
        else{
          continue;
        }
        backtracking(s,i+1);
        path.pop_back();
      }
      }
      bool isPalindrome(const string&s,int start,int end){
        while(start<end){
          if(s[start++]!=s[end--]) return false;
        }
        return true;
      }
  public:
    vector<vector<string>> partition(string s) {
      result.clear();
      path.clear();
      backtracking(s,0);
      return result;
    }
    };
