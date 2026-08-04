class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> v;
        int min_ele = INT_MAX;
        int max_ele = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(min_ele>nums[i]) min_ele = nums[i];
            if(max_ele<nums[i]) max_ele = nums[i];
        }
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(int i=min_ele;i<=max_ele;i++){
            if(s.find(i)==s.end()) v.push_back(i);
        }
        return v;
    }
};