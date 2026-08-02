class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        int i=0;
        while(i<nums.size()){
            int correct_pos = nums[i] - 1;
            if(nums[correct_pos]==nums[i]) i++;
            else if(i!=correct_pos){
                swap(nums[i],nums[correct_pos]);
            }
            else i++;
        }
        for(int i=0;i<nums.size();i++){
            if((i+1)!=nums[i]) v.push_back(i+1);
        }
        return v;
    }
};