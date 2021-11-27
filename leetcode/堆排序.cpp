#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

class Solution{
public:
  void adjust(vector<int>&arr,int len,int index){
    int left = 2*index+1;
    int right = 2*index+2;
    if(left>len) return ;
    int maxIdx=index;
    if(left<len&&arr[left]>arr[maxIdx]) maxIdx = left;
    if(right<len&&arr[right]>arr[maxIdx]) maxIdx = right;
    if(maxIdx!=index){
      swap(arr[maxIdx], arr[index]);
      adjust(arr,len,maxIdx);
    }
  }
  //堆排序
  void heapSort(vector<int>&arr,int size){
    //构建大根堆(从最后一个非叶子节点向上)
    for(int i=size/2-1;i>=0;i--){
      adjust(arr,size,i);
    }
    //调整大根堆
    for(int i=size-1;i>=1;i--){
      swap(arr[0],arr[i]);//将当前最大的数放置到数组末尾
      adjust(arr,i,0);//将未完成排序的部分继续进行堆排序
    }
  }
};
//堆排序
class heapSort{
public:
  void display(vector<int>&arr,int size){
    for(int i:arr) cout<< i << " ";
  }
  void Down(vector<int>&arr,int i,int n){
    int parent = i;
    int child = 2*i+1;
    while(child<n){
      if(child+1<n&&arr[child]<arr[child+1]) child++;
      if(arr[parent]<arr[child]){
        swap(arr[parent],arr[child]);
        parent=child;
      }
      child = child*2+1;
    }
  }

  void BuildHead(vector<int>&arr,int size){
    for(int i=size/2-1;i>=0;i--){
      Down(arr,i,size);
    }
  }

  void HeadSort(vector<int>&arr,int size){
    cout<<"初始化数组："<<endl;
    BuildHead(arr,size);
    display(arr,size);
    for(int i=size-1;i>0;i--){
      swap(arr[0],arr[i]);//交换顶点和第i个数据
      Down(arr,0,i);//重新建立大顶堆
    }
    cout<<"排序的数组："<<"\n";
    display(arr,size);
  }
};
int main(){
   vector<int> arr={49,38,65,97,76,13,27,49,10};
   heapSort hs;
   hs.HeadSort(arr,arr.size());
}
