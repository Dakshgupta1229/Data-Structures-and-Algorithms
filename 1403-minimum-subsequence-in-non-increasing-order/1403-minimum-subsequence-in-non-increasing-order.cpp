class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) sum = sum + nums[i];
        int sum2 = 0;
        vector<int> v;
        for(int i=nums.size()-1;i>=0;i--){
            sum = sum - nums[i];
            sum2 = sum2 + nums[i];
            v.push_back(nums[i]);
            if(sum2>sum) break;
        }
        return v;
    }
};