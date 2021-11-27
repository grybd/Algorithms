#include <vector>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
      if(n<4) return n-1;
      else if(n==4) return n;
      long res=1;
      while(n>4){
        res*=3;
        res%=1000000007;
        n-=3;
      }
      return (int)(res*n%1000000007);
    }
};
