#include <string>
#include <vector>
using namespace std;

class Solution{
public:
  //常规解法
  int minArray_(vector<int>&numbers){
    if(numbers.empty()) return -1;
    if(numbers.size()==1) return numbers[0];
    for(int i=0;i<(int)numbers.size();i++){
      if(i+1<(int)numbers.size()){
        if(numbers[i+1]<numbers[i]) return numbers[i+1];
      }
      else break;
    }
    return numbers[0];
    }
    //二分查找法
    int minArray(vector<int>&numbers){
      int i=0,j=numbers.size()-1;
      while(i<j){
        int m=(i+j)/2;
        if(numbers[m]>numbers[j]) i=m+1;
        else if(numbers[m]<numbers[j]) j=m;
        else{
          int x=i;
          for(int k=i+1;k<j;k++){
            if(numbers[k]<numbers[x]) x=k;
          }
          return numbers[x];
        }
      }
      return numbers[i];
    }
  };
