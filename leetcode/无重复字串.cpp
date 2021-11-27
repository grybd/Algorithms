#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution{
public:
  int lengthOfLongestSubstring(string s){

    unordered_map<char,int> window;

    int right=0,left=0;

    int len=0;

    while(right<(int)s.size()){

      char c=s[right];

      right++;

      window[c]++;

      while(window[c]>1)
      {
        char d=s[left];
        left++;
        window[d]--;
      }

      len = max(len,right-left);
    }

    return len;

  }
};

int main(){

  string s="bacab";
  Solution sol;
  cout << sol.lengthOfLongestSubstring(s);
}
