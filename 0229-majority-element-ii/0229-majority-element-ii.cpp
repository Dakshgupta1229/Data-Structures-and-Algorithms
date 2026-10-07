class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(count1==0 && ele2!=nums[i]){
                count1++;
                ele1 = nums[i];
            }
            else if(count2==0 && ele1!=nums[i]){
                count2++;
                ele2 = nums[i];
            }
            else if(ele1==nums[i]) count1++;
            else if(ele2==nums[i]) count2++;
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1) count1++;
            if(nums[i]==ele2) count2++;
        }
        if(count1>nums.size()/3) v.push_back(ele1);
        if(count2>nums.size()/3) v.push_back(ele2);
        return v;
    }
};