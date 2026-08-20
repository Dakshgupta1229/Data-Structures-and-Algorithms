class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        for(int i=0;i<nums.size();i++){
            if(i==0) v1.push_back(nums[i]);
            else if(i==1) v2.push_back(nums[i]);
            else if(v1[v1.size()-1]>v2[v2.size()-1]) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }
        for(int i=0;i<v2.size();i++) v1.push_back(v2[i]);
        return v1;
    }
};