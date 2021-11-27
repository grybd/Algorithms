#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  for(int i=0;i<n;i++){
    string s1 = s;
    s1.erase(s1.begin()+i);
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    if(s2==s1){
      cout << s1 << endl;
      return 0;
    }
  }
  cout << "false" << endl;
  return 0;
}
