#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param num string字符串
     * @return string字符串
     */
    string maxLexicographical(string num) {
        // write code here
        if(num.size()==1) return "1";
        bool flag = false;
        for(auto it:num){
          if(it=='0') flag = true;
        }
        if(flag==false) return num;
        map<int,int>map;
        string a = num;
        int i=0,j=0;
        while(j<(int)a.size()){
          /*
          if(a[i]=='0'&&a[j]!='0'){
            map[i]++;
            i++;
            j++;
          }*/
          if(a[i]=='0'&&a[j]=='0'){
            while(a[j]=='0'){
              j++;
            }
            map[i] = j-i;
            i=j;
          }
          j++;
          i++;
        }
        string b = num;
        for(auto it:map){
          int k=it.first;
          for(int i=0;i<=it.second;i++){
            cout<<k<<endl;
            cout<<it.second<<endl;
            b[k++] = '1';
          }
        }
        return b;
    }
};

int main(){
  Solution s;
  string str="1001";
  cout<<s.maxLexicographical(str)<<endl;
}
