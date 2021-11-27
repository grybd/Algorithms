#include <bits/stdc++.h>
using namespace std;

bool isOperator(char ch){
  if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
    return true;
  }
  return false;
}

int getPriority(char ch){
  int lever = 0;
  switch(ch){
    case '(':
       lever = 1;
       break;
    case '+':
       lever = 2;
       break;
    case '-':
       lever = 2;
       break;
    case '*':
       lever = 3;
       break;
    case '/':
       lever = 3;
       break;
    default:
      break;
}
 return lever;
}

int Calculate(char ch,int a,int b){
  int result = 0;
  switch(ch){
    case '+':
       result = b+a;
       break;
    case '-':
       result = b-a;
       break;
    case '*':
       result = b*a;
       break;
    case '/':
       if(a==0){
         cerr<<"除数不能为0\n";
         exit(1);
       }else{
         result = b/a;
         break;
       }
    default:
      break;
  }
  return result;
}

int main(){
  stack<int>inte;
  stack<char>op;
  char ch;
  //cin.get(ch);
  while(1){
    cin.get(ch);
    while (ch!='\n'){
      if(isdigit(ch)){
        int num = 0;
        while(isdigit(ch)){
          num = 10*num+(ch-'0');
          cin.get(ch);
        }
        inte.push(num);
      }
      else if(isOperator(ch)){
        if(op.empty()){
          op.push(ch);
          cin.get();
        }else{
          while(!op.empty()){
            int c = op.top();
            if(getPriority(c)>=getPriority(ch)){
              int count = 0;
              int a = inte.top();
              inte.pop();
              int b = inte.top();
              inte.pop();
              count = Calculate(c,a,b);
              inte.push(count);
              op.pop();
            }else break;
          }
          op.push(ch);
          cin.get();

        }
      }else if(ch==')'){
          while(op.top()!='('){
            int num=0;
            int a = inte.top();
            inte.pop();
            int b = inte.top();
            inte.pop();
            char c = op.top();
            num = Calculate(c,a,b);
            op.pop();
            inte.push(num);
          }
          op.pop();
          cin.get();
        }else {
          cin.get(ch);
        }
      }
      while(!op.empty()){
        int num=0;
        int a = inte.top();
        inte.pop();
        int b = inte.top();
        inte.pop();
        char c = op.top();
        num = Calculate(c,a,b);
        op.pop();
        inte.push(num);
      }
      cout<<inte.top();
      inte.pop();
    }
  return 0;
}
