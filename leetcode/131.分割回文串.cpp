#include <string>
#include <vector>
using namespace std;

class Solution{
private:
  vector<vector<string>>result;
  vector<string>path;//存放回文串
  void backtracking(const string&s,int startIndex){
    if(startIndex>=(int)s.size()){
      result.push_back(path);
      return ;
    }
    for(int i=startIndex;i<(int)s.size();i++){
      if(isPalindrome(s,startIndex,i)){
        string str = s.substr(startIndex,i-startIndex+1);
        path.push_back(str);
      }else{
        continue;
      }
      backtracking(s,i+1);
      path.pop_back();
    }
  }
bool isPalindrome(const string&s,int start,int end){
    for(int i=start,j=end;i<j;i++,j--){
      if(s[i]!=s[j]) return false;
    }
    return true;
}
public:
    vector<vector<string>> partition(string s){
      result.clear();
      path.clear();
      backtracking(s,0);
      return result;
    }
};
