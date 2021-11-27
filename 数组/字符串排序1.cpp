#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<string> str;
  string s;
  for(int i=0;i<n;i++)
  {
    cin>>s;
    str.push_back(s);
  }
  sort(str.begin(),str.end());
  cout<<str[0];
  for (int i=1;i<str.size();i++){
    cout<<" "<<str[i];
  }
}
