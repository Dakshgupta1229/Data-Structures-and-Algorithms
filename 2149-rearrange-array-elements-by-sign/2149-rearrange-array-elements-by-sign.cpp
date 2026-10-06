class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v(nums.size());
        int i1=0;
        int j1=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                v[i1] = nums[i];
                i1+=2;
            }
            else{
                v[j1] = nums[i];
                j1+=2;
            }
        }
        return v;
    }
};