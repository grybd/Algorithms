#include <iostream>
#include <vector>
using namespace std;

//递归版本和非递归版本
class solution{
public:
  void HeadSort(vector<int>&arr){
    int n=arr.size();
    cout<<"未排序数组："<<"\n";
    display(arr);
    BuildHead(arr);
    for(int i=n-1;i>0;i--){
      swap(arr[0],arr[i]);
      Adjust(arr,0,i);
    }
   cout<<"排序后数组："<<"\n";
   display(arr);
  }
  void Adjust(vector<int>&arr,int index,int len){
    int left = 2*index+1;
    int right = 2*index+2;
    if(left>len) return ;
    int maxIdx = index;
    if(left<len&&arr[left]>arr[maxIdx]) maxIdx = left;
    if(right<len&&arr[right]>arr[maxIdx]) maxIdx = right;
    if(maxIdx!=index){
      swap(arr[maxIdx],arr[index]);
      Adjust(arr,maxIdx,len);
    }
  }
  void BuildHead(vector<int>&arr){
    for(int i=arr.size()/2-1;i>=0;i--){
      Adjust(arr,i,arr.size());
    }
  }
 void display(vector<int>&arr){
   for(int i:arr) cout<< i << " " <<endl;
 }
};
//非递归方式
class headSort{
public:
  void HeadSort(vector<int>&arr){
    cout << "初始化数组：" <<'\n';
    BuildHead(arr);
    display(arr);
    for(int i=arr.size()-1;i>0;i--){
      swap(arr[0],arr[i]);
      Adjust(arr,0,i);
    }
    cout<<"\n";
    display(arr);
  }
 void display(vector<int>&arr){
   for(int i=0;i<(int)arr.size();i++){
     cout<< arr[i] << " ";
   }
 }
 void Adjust(vector<int>&arr,int index,int len){
   int parent = index;
   int child = 2*index+1;
   while(child<len){
     //注意child+1<len,容易出错;
     if(child+1<len&&arr[child]<arr[child+1]) child++;
     if(arr[parent]<arr[child]){
       swap(arr[parent],arr[child]);
       parent = child;
     }
     child = child*2+1;
   }
 }
 void BuildHead(vector<int>&arr){
   for(int i=arr.size()/2;i>=0;i--){
     Adjust(arr,i,arr.size());
   }
 }
};

int main(){
  vector<int>arr={3,4,7,6,8,9,1,2,5,10};
  headSort hs;
  hs.HeadSort(arr);
  return 0;
}
