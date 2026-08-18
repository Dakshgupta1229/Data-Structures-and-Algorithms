class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        set<int> s;
        map<int,int> m;
        for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        for(int i=0;i<=nums.size()-k;i++){
            set<int> s1;
            for(int j=i;j<i+k;j++){
                s1.insert(nums[j]);
            }
            for(auto p:s){
                for(auto p1:s1){
                    if(p==p1) m[p1]++;
                }
            }
        }
        int result = -1;
        for(auto p:m){
            if(p.second==1) result = p.first;
        }
        return result;
    }
};