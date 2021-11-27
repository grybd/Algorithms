#include <vector>
using namespace std;

class Solution {
public:
  vector<int> constructArr(vector<int>&a){
    int n=a.size();
    vector<int>result(n,1);
    int left=1;
    for(int i=0;i<n;i++){
      result[i]=left;
      left=left*a[i];
    }
    int right=1;
    for(int i=n-1;i>=0;i--){
      result[i]*=right;
      right *=a[i];
    }
    return result;
  }
};
