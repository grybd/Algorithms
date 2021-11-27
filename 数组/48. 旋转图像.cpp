#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int>path;
        vector<vector<int>>res;
        int m = matrix[0].size(),n=matrix.size();
        for(int j=0;j<m;j++){
            for(int i=n-1;i>=0;i--){
                path.push_back(matrix[i][j]);
            }
            res.push_back(path);
            path.clear();
        }
        matrix=res;
    }
};
