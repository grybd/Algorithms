#include<bits/stdc++.h>
using namespace std;

int main()
{int n,m=1;
int a[15][15];
cin>>n;
for(int i=0;i<n;i++)
{
 for(int j=0;j<n;j++)
   {

   cin>>a[i][j];
   if((i>j)&&(a[i][j]!=0))
    m=0;

   }
   }if(m==1)
    cout<<"YES"<<endl;
   else
    cout<<"NO"<<endl;

return 0;
}
