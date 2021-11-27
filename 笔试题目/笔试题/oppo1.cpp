#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 对两个整型数组arr1,arr2进行异或运算，并把结果升序排列后输出
     * @param arr1 int整型vector 输入数组1
     * @param arr2 int整型vector 输入数组2
     * @return int整型vector
     */
    map<int,int>map1,map2;
    vector<int> arrayXOR(vector<int>& arr1, vector<int>& arr2) {
        // write code here
        vector<int>ans;
        for(auto it:arr1){
          map1[it]++;
        }
        for(auto it:arr2){
          map2[it]++;
        }
        for(auto it:map1){
          if(map2.find(it.first)!=map2.end()){
            auto iter = map2.find(it.first);
            it.second = abs(iter->second-it.second);
            map2.erase(iter);
          }
          }
          for(auto it:map1){
            for(int i=0;i<it.second;++i){
              ans.push_back(it.first);
            }
          }
          for(auto it:map2){
            for(int i=0;i<it.second;++i){
              ans.push_back(it.first);
            }
          }
          sort(ans.begin(),ans.end());
          return ans;
        }
    };

    int main(){
      Solution s;
      vector<int>a1 = {1,1,1,1,3,5};
      std::vector<int> v = {1,1,2,4,6};
      vector<int>ans = s.arrayXOR(v,a1);
      for(auto it:ans){
        cout << it << " ";
      }
    }
