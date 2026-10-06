class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=0;j<nums.size()-i-1;j++){
                nums[j] = (nums[j] + nums[j+1])%10;
            }
        }
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        return nums[0];
    }
};