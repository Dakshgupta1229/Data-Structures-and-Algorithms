class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i] + nums[i-1];
        }
        vector<int> v;
        for(int i=0;i<queries.size();i++){
            int ele = queries[i];
            int low = 0;
            int high = nums.size()-1;
            int ans = 0;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]<=ele){
                    ans = mid+1;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            v.push_back(ans);
        }
        return v;
    }
};