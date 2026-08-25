class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> s;
        for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        for(int i=k;i<500;i+=k){
            if(s.find(i)==s.end()) return i;
        }
        return -1;
    }
};