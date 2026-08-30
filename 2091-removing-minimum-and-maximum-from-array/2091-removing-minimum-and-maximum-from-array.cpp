class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()==1) return 1;
        if(nums.size()==2) return 2;
        int max_ele = INT_MIN;
        int min_ele = INT_MAX;
        int idx1 = -1;
        int idx2 = -1;
        for(int i=0;i<nums.size();i++){
            if(max_ele<nums[i]){
                max_ele = nums[i];
                idx1 = i;
            }
            if(min_ele>nums[i]){
                min_ele = nums[i];
                idx2 = i;
            }
        }
        int first_min = 0;
        int second_min = 0;
        int third_min = 0;
        if(idx1<=idx2){
            first_min = (idx1+1) + (nums.size()-idx2);
        }
        else{
            first_min = (idx2+1) + (nums.size()-idx1);
        }
        if(idx1>=idx2) second_min = idx1+1;
        else second_min = idx2+1;
        if(idx1<=idx2) third_min = nums.size()-idx1;
        else third_min = nums.size()-idx2;

        return min(first_min,min(second_min,third_min));
    }
};