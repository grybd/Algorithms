/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        vector<string> vec;
        string temp;
        for(char c:str)
        {
            if(c == ',')
            {
                vec.push_back(temp);
                temp = "";
            }
            else temp += c;
        }
        vec.push_back(temp);
        sort(vec.begin(), vec.end());
        for(auto it = vec.begin(); it!=vec.end()-1; it++)
        {
            cout<<*it<<",";
        }
        cout<<vec.back()<<endl;
    }
    return 0;
}
*/
#include<iostream>
using namespace std;

int main(){
    long a,b;
    while(cin>>a>>b){
            cout<<a+b<<endl;
    }
}
