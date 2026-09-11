class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        if(m[nums[nums.size()/2]]==1) return true;
        return false;
    }
};