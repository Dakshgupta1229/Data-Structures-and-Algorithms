class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_len = 0;
        for(int i=0;i<nums.size();i++){
            if(i>max_len) return false;
            else{
                max_len = max(max_len,i+nums[i]);
            }
        }
        return true;
    }
};