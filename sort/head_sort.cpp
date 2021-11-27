#include <iostream>
#include <algorithm>
using namespace std;

void adjustHead(int arr[],int,int);
void swap(int arr[],int,int);

void HeadSort(int arr[],int size)
{
  int length=size*sizeof(arr)/sizeof(arr[0]);
  std::cout <<length << '\n';
  for(int i=length/2-1;i>=0;i--)
  {
    adjustHead(arr,i,length);
  }

  for(int j=length-1;j>0;j--)
  {
    swap(arr,0,j);
    adjustHead(arr,0,j);
  }

  for(int i=0;i<length;i++)
  {
    cout<<arr[i]<<" ";
  }
}

void adjustHead(int arr[],int i,int len)
{
  int temp=arr[i];
  for(int k=i*2+1;k<len;k=k*2+1)
  {
    if(k+1<len&&arr[k]<arr[k+1])
    {
      k++;
    }

    if(arr[k]>temp)
    {
      arr[i]=arr[k];
      i=k;
    }
    else{
      break;
    }
  }
  arr[i]=temp;
}

void swap(int arr[],int a,int b)
{
  int temp=arr[a];
  arr[a]=arr[b];
  arr[b]=temp;
}

int main()
{
  int arr[]={9,8,7,6,5,4,3,2,1};
  HeadSort(arr,9);
}
