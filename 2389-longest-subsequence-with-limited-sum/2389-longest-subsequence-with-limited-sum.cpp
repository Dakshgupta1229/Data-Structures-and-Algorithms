class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++) nums[i] = nums[i] + nums[i-1];
        for(int i=0;i<queries.size();i++){
            int low = 0;
            int high = nums.size()-1;
            int idx = -1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]<=queries[i]){
                    idx = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            v.push_back(idx+1);
        }
        return v;
    }
};