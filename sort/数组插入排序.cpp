#include <bits/stdc++.h>
using namespace std;

class InsertionSort{
public:
    void sort(vector<int>&arr){
       int n = arr.size();
       for(int i = 0;i<n;i++){
         for(int j=i;j>0;j--){
           if(arr[j]<arr[j-1]){
             swap(arr[j],arr[j-1]);
           }else{
             break;
           }
         }
       }
    }
};
int main(){
  InsertionSort insert;
  vector<int>arr={1,3,2,4,7,7,5,6};
  insert.sort(arr);
  for(auto i:arr){
    cout<<i<<" ";
  }
  return 0;
}
