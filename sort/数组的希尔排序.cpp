#include <bits/stdc++.h>
using namespace std;

class ShellSort{
public:
    void sort(vector<int>&arr){
      for(int gap=arr.size()/2;gap>0;gap/=2){
        for(int i=gap; i<(int)arr.size();i++){
          for(int j=i;j>=gap;j-=gap){
             if(arr[i]<arr[j-gap]){
               swap(arr[j],arr[j-gap]);
             }
          }
        }
      }
    }
};
int main(){
    ShellSort shell;
    vector<int>arr={1,3,5,2,4,6,7,8,9};
    shell.sort(arr);
    for(auto it:arr){
      cout <<it <<" ";
    }
    return 0;
}
