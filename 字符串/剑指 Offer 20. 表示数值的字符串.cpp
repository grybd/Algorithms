#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution{
  private:
    int index = 0;
    bool isUnSigInt(string s){
      int begin = index;
      while(s[index]>='0'&&s[index]<='9'){
        index++;
      }
      return index>begin;
    }
    bool isSigInt(string s){
      if(s[index]=='+'||s[index]=='-') index++;
        return isUnSigInt(s);
    }
  public:
    bool isNumber(string s){
      //空字符
      if(s.length()==0) return false;
      while(s[index]==' ') index++;
      bool number = isSigInt(s);
      if(s[index]=='.'){
        index++;
        number = isUnSigInt(s) || number;
      }
      if(s[index]=='E'||s[index]=='e'){
        index++;
        number = number&&isSigInt(s);
      }
      while(s[index]==' ') index++;
      return number&&(int)s.length()==index;
    return number&&index==(int)s.length();
    }
};
