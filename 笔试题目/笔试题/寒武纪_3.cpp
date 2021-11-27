#include<bits/stdc++.h>
using namespace std;

int main(){
  priority_queue<long long,vector<long long>,greater<long long>>q;
  long long n,k;
  cin>>n>>k;
  while(n--){
    long long a;
    cin>>a;
    q.push(a);
  }
  long long count=0;
  while(!q.empty()&&q.top()<k){
    long long first = q.top();
    q.pop();
    if(!q.empty()){
    long long second = q.top();
    q.pop();
    long long t = first+2*second;
    q.push(t);
    count++;
    }
    else{
        break;
    }
  }
  cout<< count << endl;
  return 0;
}
