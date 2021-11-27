#include <iostream>
#include <string>
using namespace std;
/*
int main(){
    string str;
    while(cin >> str);
    cout << str.size() << endl;
}*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int sLen=0;
    for(auto i=s.end()-1;i>=s.begin();i--){
      if(*i!=' '){
        sLen++;
        continue;
      }
      if(sLen>0) break;
    }
    cout << sLen << endl;
}
