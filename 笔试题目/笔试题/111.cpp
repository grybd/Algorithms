#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>a,b;
        for(auto it:nums){
            if(it==0){
                a.push_back(it);
            }else{
                b.push_back(it);
            }
        }

        int n=nums.size();
        nums.clear();
        for(int i=0;i<(int)b.size();i++){
            nums[i] = b[i];
        }
        for(int i=b.size();i<n;i++){
            nums[i] = 0;
        }
        for(auto it:nums){
          cout<< it << " ";
        }
        cout<< endl;

    }
};

int main(){
  Solution s;
  vector<int>a={0,1,0,1,0,1,0,1,0,1};
  s.moveZeroes(a);
  return 0;
}
