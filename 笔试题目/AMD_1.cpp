#include<iostream>
#include <vector>
using namespace std;
//x = 54321 , y = 9876
//a = {1,2,3,4,5} ; b = {6,7,8,9}
//Please implement the following function which calculates the product of two huge integers. Please be aware that the huge integers are stored in vector<int> data structure. For example, vector<int> val stores 12345. You will get val[0]=5, val[1]=4, 鈥�, val[4]=1
void multiply_two_huge_integers(const vector<int>& a, const vector<int>& b, vector<int>& product)
{
  vector<vector<int>> tmp(b.size(),vector<int>());
  int n = a.size();
  int m = b.size();
  for(int i=0;i<m;i++){
    int b_ = b[i];
    int cin = 0;
    for(int j=0;j<n;j++){
      int a_ = b_*a[j]+cin;
      //cout << b_ << " " << a_ <<" "<< cin << endl;
      if(a_>10){
        int b_1 = a_/10;
        a_ = a_%10;
        tmp[i].push_back(a_);
        cin = b_1;
      }else{
        tmp[i].push_back(a_);
      }
    }
    tmp[i].push_back(cin);
  }
/*
  for(auto vec:tmp){
    for(auto i:vec){
      cout << i << " ";
    }
    cout<< endl ;
  }*/
int cin_=0;
for(int j=0;j<=n;j++){
     int total_col_val_ = 0;
     int k=0;
     while(k<m){
       total_col_val_+=tmp[k][j];
       k++;
     }
     total_col_val_+=cin_;
     //cout << total_col_val_ << " ";
     if(total_col_val_>10) {
       int b_1 = total_col_val_ / 10;
       total_col_val_ = total_col_val_%10;
       cin_ = b_1;
       product.push_back(total_col_val_);
       //cout <<" "<<total_col_val_<< " "<<endl;
     }else{
       product.push_back(total_col_val_);
       //cout<<" hello" <<endl;
     }
  }
  if(cin_!=0){
    product.push_back(cin_);
  }
  for(auto i:product){
      cout << i <<" ";
    }
  cout << endl;
}
int main(){
  vector<int> a = {1,2,3,4,5};
  vector<int> b = {6,7,8,9};
  vector<int> product;
  multiply_two_huge_integers(a,b,product);
  return 0;
}
