#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
/*
class Solution{
public:
  int lengthOfLongestSubstring(string s){
  int maxLen=0;
  unordered_set<char> chars;
  for(int i=0;i<(int)s.size();i++)
  {
    int len=1;
    chars.clear();
    chars.insert(s[i]);

    for(int j=i+1;j<(int)s.size();j++)
    {
      if(chars.count(s[j])) break;
      else{
        chars.insert(s[j]);
        len++;
      }
    }
    maxLen=max(maxLen,len);
  }
  return maxLen;
  }
};
*/
class Solution{
public:
  int lengthOfLongestSubstring(string s){
    int maxLen=0;
    if(s.size()==0) return 0;
    unordered_set<char> chars;
    int right=0;

    for(int left=0;left<(int)s.size();left++){

      while(right<(int)s.size()&&!chars.count(s[right]))
      {
        chars.insert(s[right]);
        right++;
      }

      maxLen=max(maxLen,right-left);
      if(right==(int)s.size()) break;

      chars.erase(s[left]);

    }
    return maxLen;
  }
  };
