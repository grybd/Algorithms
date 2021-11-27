#include <string>
using namespace std;
class Solution{
public:
    string replaceSpace(string s){
      int len = s.length();
      string tmp = "";
      for(int i=0;i<len;i++){
        if(s[i]==' '){
          tmp+="%20";
        }else{
          tmp+=s[i];
        }
      }
      return tmp;
    }
};
