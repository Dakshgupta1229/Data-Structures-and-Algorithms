class Solution {
public:

    void subset(vector<int> &nums,int index,vector<int> v1,vector<vector<int>> &v){
        if(index>=nums.size()){
            v.push_back(v1);
            return;
        }
        v1.push_back(nums[index]);
        subset(nums,index+1,v1,v);
        v1.pop_back();
        subset(nums,index+1,v1,v);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> v1;
        subset(nums,0,v1,v);
        return v;
    }
};