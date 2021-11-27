#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    void sortColors(vector<int>&nums){
        int len=nums.size();
        if(len<2) return;
        //all in [0,p0)==0;
        //all in [p0,i)==1;
        //all in [p2,len);
        int p0=0;
        int i=0;
        int p2=len;
        while(i<p2){
            if(nums[i]==0){
                swap(nums,i,p0);
                p0++;
                i++;
            }
            else if(nums[i]==1){
                i++;
            }
            else{
                p2--;
                swap(nums,i,p2);  
            }
        }
    }
};