class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int window_size = nums.size()-k;
        sort(nums.begin(),nums.end());
        int diff = INT_MAX;
        for(int i=0;i<=window_size;i++){
            int ele = nums[i+k-1] - nums[i];
            if(diff>ele) diff = ele;
        }
        return diff;
    }
};