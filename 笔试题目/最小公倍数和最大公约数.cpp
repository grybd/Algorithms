#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
//    最大公约数
//思路：辗转相除法，博客里面有
long long gcd(long long m,long long n)
{
//m用来存放较大值，n用来存放较小值
    long long rem;
    while(n)
    {
        rem=m%n;//对较大值求出与较小值的余数
        m=n;//调换一下mn的位置
        n=rem;
    }
    return m;
}
//求最小公倍数
//思路：两数相乘再除以最大公约数 当然要考录到两个都为0的情况
long long lcm(long m,long n)
{
    if(m*n==0)return 0;
    return m*n/gcd(m,n);
}
//2020校招：最小公倍数与最大公约数
//思路：一定不要暴力，首先想到啥的是那两个数的是最大的lcm 那两个数是最小的gcd，用最大的lcm -最小的gcd就是答案！！！
//最大的最小公倍数lcm(a,b)就是lcm(n,n-1)，最小的最大公约数gcd(a,b)是gcd(1,1)=1;
};
int main()
{
  Solution solution;
  int n;
  cin>>n;
  vector<int>res;
  while(n--){
    set<int>set;
    vector<vector<int>>vec;
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
      int tmp = N/i;
      if(solution.lcm(tmp,i)==N){
        set.insert(i);
        set.insert(tmp);
      }
    }
    res.push_back(set.size()/2);
  }
  for(int i=0;i<(int)res.size();i++){
    cout << res[i] << endl;
  }
  return 0;
}
