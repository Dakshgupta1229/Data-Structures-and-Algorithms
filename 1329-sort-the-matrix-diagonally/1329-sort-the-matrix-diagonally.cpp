class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int,vector<int>> m;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                int diff = i-j;
                m[diff].push_back(mat[i][j]);
            }
        }
        for(auto p:m){
            int ele = p.first;
            sort(m[ele].begin(),m[ele].end());
        }

        for(int i=mat.size()-1;i>=0;i--){
            for(int j=mat[i].size()-1;j>=0;j--){
                mat[i][j] = m[i-j].back();
                m[i-j].pop_back();
            }
        }
        return mat;
    }
};