#include <vector>
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
      int n=matrix.size()-1,m=0;
      while(n>=0&&m<=(int)matrix[0].size()-1){
        if(matrix[n][m]>target) n--;
        else if(matrix[n][m]<target) m++;
        else return true;
      }
      return false;
    }
};
