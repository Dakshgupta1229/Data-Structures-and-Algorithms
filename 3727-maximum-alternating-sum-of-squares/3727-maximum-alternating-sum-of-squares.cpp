class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = 0;
        for(int i=0;i<nums.size();i++) nums[i] = abs(nums[i]);
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            sum = sum + pow(nums[j],2);
            sum = sum - pow(nums[i],2);
            i++;
            j--;
        }
        if(i==j) sum = sum + pow(nums[i],2);
        return sum;
    }
};