class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int max_ele = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(max_ele<nums[i]) max_ele = nums[i];
        }
        int high = max_ele;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int sum = 0;
            for(int i=0;i<nums.size();i++){
                float result = (float)nums[i]/(float)mid;
                sum = sum + ceil(result);
            }
            if(sum<=threshold){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};