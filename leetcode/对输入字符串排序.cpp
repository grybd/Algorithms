#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int mian(){
  vector<string> vec;
  int n=0;
  cin>>n;
  while(n){
    string str;
    cin>>str;
    vec.push_back(str);
    n--;
  }
  sort(vec.begin(),vec.end());
  for(int i=0;i<n;i++){
    cout<<vec[i]<<' '<<endl;
  }
  return 0;
}
