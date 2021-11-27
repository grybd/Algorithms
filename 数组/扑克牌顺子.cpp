#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
       set<int>set;
       int max1 = 0; int min1 = 14;
       for(int num:nums){
         if(num==0) continue;
         max1 = max(max1,num);
         min1 = min(min1,num);
         if(set.count(num)) return false;
         set.insert(num);
       }
       return max1-min1<5;
    }
};
