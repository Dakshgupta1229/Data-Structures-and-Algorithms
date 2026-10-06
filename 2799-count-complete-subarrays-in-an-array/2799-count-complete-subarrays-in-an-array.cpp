class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int count = 0;
        set<int> s;
        for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        for(int i=0;i<nums.size();i++){
            set<int> s1;
            int idx = -1;
            for(int j=i;j<nums.size();j++){
                s1.insert(nums[j]);
                if(s1.size()==s.size()){
                    idx = j;
                    break;
                }
            }
            if(idx==-1) break;
            count = count + (nums.size() - idx);
        }
        return count;
    }
};