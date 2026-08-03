class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        m[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
            int rem = sum - k;
            if(m.find(rem)!=m.end()){
                count = count + m[rem];
            }
            m[sum]++;
        }
        return count;
    }
};