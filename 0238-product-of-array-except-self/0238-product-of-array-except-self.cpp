class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        prefix[0] = 1;
        suffix[suffix.size()-1] = 1;
        int product1 = 1;
        for(int i=1;i<nums.size();i++){
            product1 = product1 * nums[i-1];
            prefix[i] = product1;
        }
        int product2 = 1;
        for(int i=nums.size()-2;i>=0;i--){
            product2 = product2 * nums[i+1];
            suffix[i] = product2;
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = prefix[i] * suffix[i];
        }
        return nums;
    }
};