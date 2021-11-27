class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param matrix int整型vector<vector<>> 输入矩阵
     * @return int整型vector
     */
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        // write code here
        vector<int>res;
        if(matrix.size()==0) return res;
        int r1=0,r2=matrix.size()-1;
        int c1=0,c2=matrix[0].size;
        int i=0,j=0;
        int sum=matrix.size*matrix[0].size();
        while(res.size()<sum){
          if(j==c1&&i==r1){
            while(j<=c2) res.push_back(matrix[i][j++]);
            ++r1;
            --j;
            ++i;
          }
          else if(j==c2&&i==r1){
            while(i<=r2)res.push_back(matrix[i++][j]);
            --c2;
            --i;

            --j;
          }
          else if(j==c2&&i==r2){
            while(j>=c1)res.push_back(matrix[i][j--]);
            --r2;
            --i;

            ++j;
          }

          else {
            while(i>=r1)res.push_back(matrix[i--][j]);
            ++c1;
            ++i;

            ++j;
          }
        }
        return res;
    }
};
