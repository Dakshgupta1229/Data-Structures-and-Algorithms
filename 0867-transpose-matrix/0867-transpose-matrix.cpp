class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> v(matrix[0].size(),vector<int>(matrix.size()));
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                v[i][j] = matrix[j][i];
            }
        }
        return v;
    }
};