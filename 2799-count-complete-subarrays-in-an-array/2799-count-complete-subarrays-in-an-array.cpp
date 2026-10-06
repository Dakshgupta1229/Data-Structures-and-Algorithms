class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int n = s.size();
        int count = 0;
        for(int i=0;i<nums.size();i++){
            map<int,int> m;
            for(int j=i;j<nums.size();j++){
                m[nums[j]]++;
                int n1 = m.size();
                if(n1==n) count++;
            }
        }
        return count;
    }
};