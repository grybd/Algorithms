#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    string multiply(string num1,string num2){
      int m=num1.size(),n=num2.size();
      //结果最多为m+n位数
      vector<int>res(m+n,0);
      //从个位数开始相乘
      for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
          int mul = (num1[i]-'0')*(num2[j]-'0');
          //乘积在res对应的索引位置
          int p1=i+j,p2=i+j+1;
          //叠加到res上
          int sum = mul + res[p2];
          res[p2] = sum%10;
          res[p1]+= sum/10;
         }
       }
      //结果前缀可能存的0
        int k=0;
        while(k<(int)res.size()&&res[k]==0) k++;
        //将计算结果转化成字符串
        string str;
        for(int i=k;i<(int)res.size();i++){
          str.push_back('0'+res[i]);
        }
        return str.size()==0 ? "0":str;
      }
};
