#include<iostream>
using namespace std;

int main(){
    int n;
    int sum=0;
    while(cin>>n){
        sum+=n;
        if(cin.get() == '\n'){
            cout<<sum<<endl;
            sum=0;
        }
    }   
}
