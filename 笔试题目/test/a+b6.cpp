#include<bits/stdc++.h>
using namespace std;
/*
int main()
{
    int length;
    vector<int> nums;
    cin>>length;
    while(cin)
    {
        int ans=0;
        for(int i=0;i<length;i++)
        {
            int temp;
            cin>>temp;
            ans+=temp;
        }
        nums.push_back(ans);
        cin>>length;
    }
    for(auto it:nums)
        cout<<it<<endl;
}
*/
#include <iostream>
#include<stdio.h>
using namespace std;
int main() {
    int a, s, n;
    while (cin >> n) {
        s = 0;
        while (n != 0) {
            cin >> a;
            s += a;
            n--;
        }
        cout << s << endl;
    }
}
