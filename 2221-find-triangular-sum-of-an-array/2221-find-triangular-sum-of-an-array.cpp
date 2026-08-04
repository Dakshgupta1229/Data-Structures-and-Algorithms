class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()>1){
            vector<int> v;
            for(int i=1;i<nums.size();i++){
                int sum = (nums[i] + nums[i-1])%10;
                v.push_back(sum);
            }
            nums = v;
        }
        return nums[0];
    }
};