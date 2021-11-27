
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        int n=array.size();
        int js=0,os=0;
        vector<int> JS,OS;
        for(int i=0;i<n;i++)
        {
            if(array[i]%2==1){
                js++;
                JS.push_back(array[i]);
            }
            else{
                os++;
                OS.push_back(array[i]);
            }
        }

        for(int i=0;i<js;i++)
        {
            cout<<JS[i]<<" ";
        }

        for(int j=0;j<js;j++)
        {
            array[j]=JS[j];
        }

        for(int k=0;k<os;k++){
            array[js+k]=OS[k];
        }

        return array;
    }
};

int main(){
  Solution s;
  vector<int>vec={1,3,5,7,2,4,6};
  s.reOrderArray(vec);
}
