#include <string>
#include <vector>
#include <limits.h>
#include <unordered_map>

using namespace std;

/*
int left=0,right=0;

while(right<s.size())
{
  //增大窗口
  window.add(s[right]);
  right++;

  while(window needs shrink){
  //缩小窗口
  window.remove(s[left]);
  left++;
}
}
*/

string slidingWindow(string s,string t){

  unordered_map<char,int> need,window;

  for(char c:t) need[c]++;

  int left=0,right=0;

  //完成字符匹配的个数;
  int valid=0;

  //记录最小覆盖字串的起始索引及长度
  int start=0,len=INT_MAX;

  while(right<s.size())
  {
    //c 是将移入窗口的字符
    char c=s[right];
    //右移窗口
    right++;

    //进行窗口内数据的一系列更新
    if(need.count(c)){
      window[c]++;
      if(window[c]==need[c])
      {
        valid++;
      }
    }
    //判断左侧窗口是否要收缩
    while(valid==(int)need.size())
    {
      //在这里更新最小覆盖字串
      if(right-left<len)
      {
        start=left;
        len = right-left;
      }

      //d 是将移出窗口的字符
      char d=s[left];

      //左移窗口
      left++;

      //进行窗口内数据的一系列更新

      if(need.count(d))
      {
        if(window[d]==need[d])
        {
          valid--;
          window[d]--;
        }
      }
    }

  }
return len==INT_MAX?"":s.substr(start,len);
}
