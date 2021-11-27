#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
  int left=0,right=0;
  unordered_map<char,int>win;
  int res=0;//记录长度
  while(right<(int)s.size()){
    char c1 = s[right];
    win[c1]++;
    right++;
    while(win[c1]>1){
      char c2=s[left];
      win[c2--];
      left++;
    }
    res = max(res,right-left);
  }
  return res;
}
