#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int>findAnagram(string s,string t){

    unordered_map<char,int> need,window;

    for(char c:t) need[c]++;

    int left=0,right=0;

    int valid=0;

    vector<int> res;

    while(right<(int)s.size()){

      char c=s[right];

      right++;

      if(need.count(c))
      {
        if(need[c]==window[c])
        {
          valid++;
        }
        window[c]++;
      }

      while(right-left==(int)t.size())
      {
        if(valid==(int)need.size())
        {

        }
        res.push_back(left);
        char d=s[left];

        left++;
        if(need.count(d)){
          if(need[d]==window[d]){
            valid--;
          }
          window[d]--;
        }
      }
    }
    return res;
  }
};
