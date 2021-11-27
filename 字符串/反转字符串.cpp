#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    string reverseStr(string s,int k){
      for(int i=0;i<(int)s.size();i+=2*k){
        if(i+k<=(int)s.size()){
          reverse(s.begin()+i,s.begin()+i+k);
        }else{
          reverse(s.begin()+i,s.begin()+s.size());
        }
      }
      return s;
    }
};


class Solution_{
private:
  void reverse(string&s,int start,int end){
    for(int i=start,j=end;i<j;i++,j--){
      swap(s[i],s[j]);
    }
  }
public:
    string reverseStr(string s,int k){
      for(int i=0;i<(int)s.size();i+=2*k){
        if(i+k<=(int)s.size()){
          reverse(s,i,i+k-1);
        }else{
          reverse(s,i,s.size()-1);
        }
      }
      return s;
    }
};
