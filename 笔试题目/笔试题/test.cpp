#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
public:
   unordered_map<char, int>res
   unordered_map<char,int> UinC(unordered_map<char,int>&C,unordered_map<char,int>U){
     int n=C.size();
     int m=U.size();
     for(int i=0;i<m;i++){
       char tmp = U[i].first;
       for(int j=0;j<n;j++){
         if(C[i].first==tmp)
       }
     }
   }
}
