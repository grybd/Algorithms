#include <bits/stdc++.h>
using namespace std;
class DataContainer
{
  public:
    void dataInsert(int d){
      if(size >=length){
        int* temp = new int[length*2];
        for(int j=0;j<length;j++){
          temp[j]=data[j];
        }
        delete[] data;
        data = temp;
        data[size++]=d;
      }else{
        data[size++] = d;
      }
    }
  private:
    int length = 10;
    int *data = new int[length];
    int size = 0;
};
