#include <bits/stdc++.h>
using namespace std;
/*
class Solution{
public:
  int substr_length(string str){
    if(str.size()==0) return 0;
    if(str.size()==1) return 1;
    unordered_map<char,int>map;
    int i=0,j=1;
    int len = 1;
    map[str[0]]=0;
    while(j<(int)str.length()){
      if(map.size()!=0&&map.count(str[j])){
        len = max(len,j-i);
        i = map[str[j]]+1;
        j++;
        continue;
      }
      map[str[j]] = j;
      len++;
      j++;
    }
    return len;
  }
};
*/
class Solution {
public:
    int substr_length(string s) {
        if(s.length()==1)
            return 1;
        else if(s.length()<1)
            return 0;
        int a = 0;
        int b = 0;
        for(int i=1; i<(int)s.length(); i++)   //遍历尾到头之间的字符
        {
            for(int j=b; j<i; j++)
            {
                if(s[i]==s[j])
                {
                    b = j+1;     //更新尾指针，下次遍历从尾指针开始
                    if(a<i-j)
                        a = i-j;     //更新最大不重复值，即头尾距离
                    break;
                }
            }
            if(a<i-b+1)     //如果没有找到相同字符，更新长度即最大不重复值
                a = i-b+1;     //计算距离要包含尾指针
        }
        return a;
    }
};
