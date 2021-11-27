#include <iostream>
#include <queue>
using namespace std;

int main(){
  deque<int> dp;
  for(int i=0;i<5;i++)
  {
    if(i%2==1) dp.push_front(i);
    else{
      dp.push_back(i);
    }
  }

  for(int j=0;j<5;j++){
   int temp=dp.front();
   cout<<temp<<"\n";
   dp.pop_front();
  }
}
