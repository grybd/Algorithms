#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
    public:
       int kfen(vector<int>&red,vector<int>&blue,int k){
           //sort(red.begin(),red.end());
           //sort(blue.begin(),blue.end());
           int n = red.size();
           int m = blue.size();
           int count = 0;
           for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                   if(abs(red[i]-blue[j])<=k) count++;
                   else continue;
               }
           }
           return count;
       }
};

int main(){

    int n,m,k,g;
    vector<int>red,blue;
    while(cin>>n){
        cin>>m;
        int temp1,temp2;
        for(int i=0;i<m;i++){
            cin>>temp1;
            red.push_back(i);
        }
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>temp2;
            blue.push_back(temp2);
        }
        cin>>g;
        Solution s;
        cout<< s.kfen(red,blue,g)<<endl;
        red.clear();
        blue.clear();
    }
  }
