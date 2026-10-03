class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix[i].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
            int i1 = 0;
            int j1 = matrix.size()-1;
            while(i1<j1){
                swap(matrix[i][i1],matrix[i][j1]);
                i1++;
                j1--;
            }
        }
    }
};