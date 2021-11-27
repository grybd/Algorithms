#include <bits/stdc++.h>
using namespace std;
int main(){
  pair<string,int>psi;
  vector<pair<string,int>> str_int; string str;
  cout <<"please enter charater and integer(ctrl+z to end:)"<<endl;
  string str1;
  cin>>str1;
  int n;
  cin>>n;
  psi = make_pair(str1,n);
  str_int.push_back(psi);
  vector<pair<string,int>>::iterator read;
  read = str_int.begin();
  while( read != str_int.end() )
  {
    cout << (*read).first << endl;
    read++;
  }
   return 0;
}
