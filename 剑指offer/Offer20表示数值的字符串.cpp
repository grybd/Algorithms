#include <string>
using namespace std;
class Solution {
    private:
     int index = 0;//全局索引
     bool scanUnsignedInteger(string str) {
        //是否包含无符号数
        int before = index;
        while(str[index] >= '0' && str[index] <= '9')
            index++;
        return index > before;
    }
    bool scanInteger(string str) {
        //是否包含有符号数
        if(str[index] == '+' || str[index] == '-')
               index++;
        return scanUnsignedInteger(str);
    }
    public:
     bool isNumber(string s) {
        //空字符串
        if(s.length() == 0)
            return false;
        //跳过首部的空格
        while(s[index] == ' ')
            index++;
        bool numeric = scanInteger(s); //是否包含整数部分
        if(s[index] == '.') {
            index++;
            //有小数点，处理小数部分
            //小数点两边只要有一边有数字就可以，所以用||，
            //注意scanUnsignedInteger要在前面，否则不会进
            numeric = scanUnsignedInteger(s) || numeric;
        }
        if((s[index] == 'E' || s[index] == 'e')) {
            index++;
            //指数部分
            //e或E的两边都要有数字，所以用&&
            numeric = numeric && scanInteger(s);
        }
        //跳过尾部空格
        while(s[index] == ' ')
            index++;
        return numeric && index ==(int)s.length() ;
    }
};
