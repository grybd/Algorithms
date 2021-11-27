class Solution{
public:
  //暴力解法
    int countDigitOne_(int n){
      int num=0;
      for(int i=1;i<=n;i++){
        int temp=i;
        while(temp>0){
          if(temp%10==1){
            num++;
          }
          temp/=10;
        }
      }
      return num;
    }
    int countDigitOne(int n){
      if(n<1) return 0;
      long digit = 1;
      int high = n/10,cur=n%10,low=0;
      int res=0;
      while(high!=0||cur!=0){
        if(cur==0) res+=high*digit;
        else if(cur==1) res+=high*digit+low+1;
        else{
          res+=(high+1)*digit;
        }
        low+=cur*digit;
        cur=high%10;
        high/=10;
        digit*=10;
      }
      return res;
    }
};
