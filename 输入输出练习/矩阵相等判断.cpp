#include<bits/stdc++.h>
using namespace std;
int main()
{int n,m,flag=1;
cin>>n>>m;
int a[n][m],b[n][m];
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
        cin>>a[i][j];
}
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
        cin>>b[i][j];
}
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
        if(a[i][j]==b[i][j])
            {flag=1;}
            else
            {
              flag=0;
              break;
            }
}
if(flag==1)
    cout<<"Yes"<<endl;
else
    cout<<"No"<<endl;
return 0;
}
