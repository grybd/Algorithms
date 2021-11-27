#include<vector>
using namespace std;

class Solution{
public:
  int majorityElement(vector<int>&nums){
    int x=0,votes=0;
    for(int num:nums){
      if(votes==0) x=num;
      if(x==num) votes++;
      else votes--;
    }
    return x;
  }
};
