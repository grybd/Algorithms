//冒泡排序；
#include <iostream>
using namespace std;
template<typename T>

void bubble_sort(T arr[],int len)
{
  int i,j;
  for(i=0;i<len-1;i++)
  {
    for(j=0;j<len-1-i;j++)
    {
      if(arr[j]>arr[j+1])
      {
        swap(arr[j],arr[j+1]);
      }
    }
  }
}

int main()
{
  int arr[] = {1,4,5,3,7,8,6,9};
  int len = (int) sizeof(arr)/sizeof(*arr);
  bubble_sort(arr,len);
  for(int i=0;i<len;i++)
  {
    cout<<arr[i]<<' '<<endl;
  }
  cout<<'\n';
  float arrf[]={1.1,4.1,5.2,3.3,7.1,8.5,6.9,9.0};
  len = (float) sizeof(arrf)/sizeof(*arrf);
  bubble_sort(arrf,len);
  for(int i=0;i<len;i++)
  {
    cout<<arrf[i]<< ' '<<endl;
  }
  return 0;
}
