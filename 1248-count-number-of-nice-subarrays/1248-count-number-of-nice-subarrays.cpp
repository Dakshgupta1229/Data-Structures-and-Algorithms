class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) nums[i] = 0;
            else nums[i] = 1;
        }
        int sum = 0;
        map<int,int> m;
        m[0] = 1;
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