#include <unordered_map>
#include <string>
using namespace std;

class Solution{
public:
  char firstUniqChar(string s)
  {
    unordered_map<char,bool> map;
    for(char c:s)
    {
      map[c]=map.find(c)==map.end();
    }
    for(char c:s)
    {
      if(map[c]) return c;
    }
    return ' ';
  }
};
