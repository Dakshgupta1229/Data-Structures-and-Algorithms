class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int first = -1;
        int second = -1;
        int min_product = INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                int sum = nums[i] + nums[j];
                int p = nums[i] * nums[j];
                if(sum==target && min_product<p && nums[i]>nums[j] && i!=j){
                    first = i;
                    second = j;
                    min_product = p;
                }
            }
        }
        if(first==-1) return {-1,-1};
        return {first,second};
    }
};