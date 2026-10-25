class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int count = 0;
        while(i<j){
            if(nums[i]>nums[j]){
                j--;
                count++;
            }
            else break;
        }
        vector<int> v1;
        for(int i=nums.size()-count;i<nums.size();i++){
            v1.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()-count;i++){
            v1.push_back(nums[i]);
        }
        vector<int> v2 = nums;
        sort(v2.begin(),v2.end());
        if(v2==v1) return count;
        else return -1;
    }
};