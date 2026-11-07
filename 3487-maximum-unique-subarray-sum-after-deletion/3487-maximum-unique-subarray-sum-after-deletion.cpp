class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        int max_ele = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) s.insert(nums[i]);
            if(max_ele<nums[i]) max_ele = nums[i];
        }
        if(s.size()==0) return max_ele;
        int sum = 0;
        for(auto p:s){
            sum = sum + p;
        }
        return sum;
    }
};