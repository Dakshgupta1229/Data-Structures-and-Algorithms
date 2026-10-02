class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i=0;i<numRows;i++){
            vector<int> v1;
            int current = 1;
            v1.push_back(current);
            for(int j=0;j<i;j++){
                current = current * (i-j)/(j+1);
                v1.push_back(current);
            }
            v.push_back(v1);
        }
        return v;
    }
};