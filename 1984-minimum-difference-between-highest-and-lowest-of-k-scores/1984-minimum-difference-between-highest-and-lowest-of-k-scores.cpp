class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int result = INT_MAX;
        for(int i=0;i<=nums.size()-k;i++){
            int max_ele = INT_MIN;
            int min_ele = INT_MAX;
            for(int j=i;j<i+k;j++){
                if(max_ele<nums[j]) max_ele = nums[j];
                if(min_ele>nums[j]) min_ele = nums[j];
                
            }
            int diff = max_ele - min_ele;
            if(result>diff) result = diff;
        }
        return result;
    }
};