class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v(nums.size());
        int i=0;
        int j=1;
        int idx = 0;
        while(idx<nums.size()){
            if(nums[idx]>=0){
                v[i] = nums[idx];
                i+=2;
            }
            else{
                v[j] = nums[idx];
                j+=2;
            }
            idx++;
        }
        return v;
    }
};