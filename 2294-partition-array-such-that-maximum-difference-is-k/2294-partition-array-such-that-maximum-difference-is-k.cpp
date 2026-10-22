class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        if(nums.size()==1) return 1;
        sort(nums.begin(),nums.end());
        int min_ele = nums[0];
        int max_ele = nums[0];
        int count = 0;
        for(int i=0;i<nums.size();i++){
            max_ele = nums[i];
            int diff = max_ele - min_ele;
            if(diff>k){
                count++;
                min_ele = nums[i];
                max_ele = nums[i];
            }
        }
        return count+1;
    }
};