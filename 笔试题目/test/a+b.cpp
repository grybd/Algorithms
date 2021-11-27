#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main(){
    queue<int>q;
    int num=0;
    int n;
    cin>>n;
    while(n!=0){
      num++;
      int ans=0;
      for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        ans+=temp;
        }
      q.push(ans);
      cin>>n;
    }
    for(int i=0;i<num;i++)
    {
      cout<<q.front()<<'\n';
      q.pop();
    }
  }
