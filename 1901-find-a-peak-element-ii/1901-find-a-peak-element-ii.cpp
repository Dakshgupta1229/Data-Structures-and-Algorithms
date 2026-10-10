class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> v;
        int low = 0;
        int high = mat[0].size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int max_ele = INT_MIN;
            int idx = -1;
            for(int i=0;i<mat.size();i++){
                if(max_ele<mat[i][mid]){
                    max_ele = mat[i][mid];
                    idx = i;
                }
            }
            if(mid-1>=0 && mat[idx][mid-1]>max_ele) high = mid - 1;
            else if(mid+1<mat[0].size() && mat[idx][mid+1]>max_ele) low = mid + 1;
            else return {idx,mid};
        }
        return {-1,-1};
    }
};