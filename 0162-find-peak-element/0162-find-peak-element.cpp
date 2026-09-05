class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid==0) low++;
            else if(mid==nums.size()-1) high--;
            else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]) low = mid + 1;
            else high = mid - 1;
        }
        if(nums.size()>=2){
            if(nums[0]>nums[1]) return 0;
            else if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;
        }
        return 0;
    }
};