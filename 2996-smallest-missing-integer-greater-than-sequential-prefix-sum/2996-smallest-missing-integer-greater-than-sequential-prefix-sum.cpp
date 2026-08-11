class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        set<int> s(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                sum = sum + nums[i];
            }
            else break;
        }
        for(int i=sum;i<=1275;i++){
            if(s.find(i)==s.end()) return i;
        }

        return -1;
    }
};