#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
  static void printInt(){
    cout<<"qqqqq"<<endl;
  }
};

int main(){
  Solution::printInt();
  int num[4]={4,3,2,1};
  sort(num,num+4,[=](int x,int y)->bool{return x<y;});
  for(int n:num){
    cout<<n<<" ";
  }
  return 0;
}
