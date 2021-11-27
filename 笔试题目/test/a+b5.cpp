#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main(){
    queue<int>q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int ans=0,tem=0;
        cin>>tem;
        for(int i=0;i<tem;i++)
        {
            int temp=0;
            cin>>temp;
            ans+=temp;
        }
        q.push(ans);
    }
    while(n){
         cout<<q.front()<<'\n';
         q.pop();
         n--;
    }
}
