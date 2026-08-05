class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=ele2){
                cnt1++;
                ele1 = nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1){
                cnt2++;
                ele2 = nums[i];
            }
            else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> v;
        int count1 = 0;
        int count2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1) count1++;
            if(nums[i]==ele2) count2++;
        }
        if(count1>(int)nums.size()/3) v.push_back(ele1);
        if(count2>(int)nums.size()/3) v.push_back(ele2);
        return v;
    }
};