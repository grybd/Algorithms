#include <iostream>
using namespace std;

void shellsort(int arr[], int len)
{
  if(arr==nullptr||len==0)
  {
    return ;
  }
  //假设传入的len=14.则增量为7,3,1;
  for(int d=len/2;d>0;d/=2)
  {
    for(int i=d;i<len;i++)
    {
      for(int j=i-d;j>=0;j-=d)
      {
        if(arr[j]>arr[j+d])
        {
          //升序;
          int temp=arr[j];
          arr[j]=arr[j+d];
          arr[j+d]=temp;
        }
      }
    }
  }
}
