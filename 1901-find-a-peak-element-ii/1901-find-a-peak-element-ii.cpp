class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int high = mat[0].size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int max_ele = INT_MIN;
            int r = -1;
            int c = -1;
            for(int i=0;i<mat.size();i++){
                if(max_ele<mat[i][mid]){
                    max_ele = mat[i][mid];
                    r = i;
                    c = mid;
                }
            }
            if(c-1>=0 && mat[r][c-1]>max_ele) high = mid - 1;
            else if(c+1<mat[0].size() && mat[r][c+1]>max_ele) low = mid + 1;
            else return {r,c};
        }
        return {-1,-1};
    }
};