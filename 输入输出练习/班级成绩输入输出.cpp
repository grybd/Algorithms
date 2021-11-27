#include <bits/stdc++.h>
using namespace std;

int main(){
  float a[10][10];
  for (int i=0;i<5;i++){
    for (int j=0;j<5;j++){
      cin>>a[i][j];
      a[i][5]+=a[i][j];
    }
  }
  for(int i =0;i<5;i++){
    for(int j=0;j<=5;j++){
      printf("%.1f ",a[i][j]);
    }
    cout<<"\n"<<endl;
  }
}
