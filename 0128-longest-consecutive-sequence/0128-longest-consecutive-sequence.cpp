class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int> s;
        int max_len = 0;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int first = INT_MIN;
        int count = 1;
        for(auto p:s){
            if(first==INT_MIN) first = p;
            else if(p-first==1){
                count++;
                first = p;
            }
            else{
                if(max_len<count) max_len = count;
                first = p;
                count = 1;
            }
        }
        if(max_len<count) max_len = count;
        return max_len;
    }
};