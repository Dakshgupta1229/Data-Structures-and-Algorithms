class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int first = INT_MIN;
        int second = INT_MIN;
        int max_ele = 0;
        int freq1 = 0;
        int freq2 = 0;
        for(auto p:m){
            if(first==INT_MIN){
                first = p.first;
                freq1 = p.second;
            }
            else if(second==INT_MIN){
                second = p.first;
                freq2 = p.second;
                if(second-first==1){
                    if(max_ele<(freq1+freq2)) max_ele = freq1 + freq2;
                }
                first = p.first;
                freq1 = p.second;
                second = INT_MIN;
            }
        }
        return max_ele;
    }
};