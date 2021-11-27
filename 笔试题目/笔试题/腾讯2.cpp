#include <bits/stdc++.h>
using namespace std;

/*
class Solution{
  int count=0;
  int max_ = INT_MIN;
  void backtrack(vector<int>&ans,int s,int e){
       if(s>e) return ;
       for(int i=s;i<e;i++){
          count+=ans[i];

       }
  }
  int getMax(vector<int>&ans){
     int n = (int)ans.size();
     if(n==0) return 0;
     backtrack(ans,0,n-1);
     return max_;
  }
};

int getMax(vector<int>&ans){
   int n = (int)ans.size();
   if(n==0) return 0;
   int max_=0;
   for(int i=0;i<n;i++){
     int count=0;
      int j=i;
      count+=ans[j];
      while(j+ans[j]<n){
        count+=ans[j+ans[j]];
        j=j+ans[j];
      }
      max_=max(max_,count);
   }
   return max_;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<int>ans;
  while(m--){
    int a;
    cin>>a;
    ans.push_back(a);
  }
  int res = getMax(ans);
  cout<<res<<endl;
  return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

int main () {
    int T;
    cin >> T;
    for (int p = 0; p < T; p++) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        int m = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i + a[i] >= n) dp[i] = a[i];
            else dp[i] = a[i] + dp[i + a[i]];
            if (dp[i] > m) m = dp[i];
        }
        cout << m << endl;
    }
    return 0;
}
