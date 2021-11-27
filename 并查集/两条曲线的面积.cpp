#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
long long mod = 1000000007;
int compare(double x)
{
    if(abs(x)<eps)
        return 0;
    if(x>0)
        return 1;
    return x;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
      int A,B,C;
      cin>>A>>B>>C;
      double a,b,c;
      a=B*B;
      b=2*B*C-2*A;
      c=C*C;
      double dt = b*b-4*a*c;
      if(compare(dt)<=0){
        cout<<0<<endl;
      }else{
        double x1 = (-b+sqrt(dt))/(2*a);
        double x2 = (-b-sqrt(dt))/(2*a);
        double y1 = B*x1+C;
        double y2 = B*x2+C;
        if(y1<y2){
          swap(y1,y2);}
          double ans = (y1*y1/(2*B)-y2*y2/(2*B))+(C*y2/B-C*y1/B)+(y2*y2*y2/(6*A)-y1*y1*y1/(6*A));
          printf("%.61f\n",ans);
      }
    }
    return 0;
}
