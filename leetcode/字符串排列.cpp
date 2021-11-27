#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool checkInclusion(string t,string s)
  {
    unordered_map<char,int> need,window;

    for(char c:t) need[c]++;

    int right=0,left=0;
    int vaild=0,start=0;

    while(right<(int)s.size())
    {
      char c=s[right];
      right++;
      if(need.count(c))
      {
        window[c]++;
        if(window[c]==need[c]) vaild ++;
      }

      while(right-left>=(int)t.size())
      {
        char d=s[left];

        left ++;

        if(vaild==(int)need.size())
        {
          return true;
        }

        if(need.count(d))
        {
          if(window[d]== need[d]) vaild--;
          window[d]--;
        }
      }
    }
    return false;
  }
};
