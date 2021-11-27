#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  string str;
  vector<string>vec;
  while(cin>>str){
    vec.push_back(str);
    if(cin.get()=='\n'){
      sort(vec.begin(),vec.end());
      cout<<vec[0];
      for(int i=1;i<(int)vec.size();i++){
        cout<<" "<<vec[i];
      }
    }
    vec.clear();
  }
}
