class Solution {
public:

    void subset(vector<int> &nums,int idx,vector<int> v,vector<vector<int>> &result){
        if(idx==nums.size()){
            result.push_back(v);
            return;
        }
        subset(nums,idx+1,v,result);
        v.push_back(nums[idx]);
        subset(nums,idx+1,v,result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> v1;
        subset(nums,0,v1,v);
        return v;
    }
};