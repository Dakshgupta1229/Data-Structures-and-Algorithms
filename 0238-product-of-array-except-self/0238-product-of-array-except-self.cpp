class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        prefix[0] = 1;
        int product = nums[0];
        suffix[suffix.size()-1] = 1;
        for(int i=1;i<prefix.size();i++){
            prefix[i] = product;
            product = product * nums[i];
        }
        product = nums[nums.size()-1];
        for(int i=suffix.size()-2;i>=0;i--){
            suffix[i] = product;
            product = product * nums[i];
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = prefix[i] * suffix[i];
        }
        return nums;
    }
};