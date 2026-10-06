class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            set<int> s;
            for(int j=i;j<nums.size();j++){
                s.insert(nums[j]);
                int n = s.size();
                sum = sum + (n*n);
            }
        }
        return sum;
    }
};