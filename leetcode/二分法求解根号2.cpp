#include <iostream>
using namespace std;

double CalcSqrt(double number){
  double mid;
  double l=0;
  double r = number;
  while (r-l>1e-7){
    mid = l+(r-l)/2;
    double tmp = mid*mid;
    if(tmp>number){
      r=mid;
    }else{
      l=mid;
    }
  }
  return mid;
}
int main(){
  std::cout<<"根号2的结果是:"<<CalcSqrt(2.0)<<std::endl;
}
