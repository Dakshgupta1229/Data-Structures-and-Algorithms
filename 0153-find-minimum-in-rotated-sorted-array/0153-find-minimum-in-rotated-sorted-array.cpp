class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return min(nums[0],nums[1]);
        int pivot_idx = -1;
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid==0) low++;
            else if(mid==nums.size()-1) high--;
            else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                pivot_idx = mid+1;
                break;
            }
            else if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                pivot_idx = mid;
                break;
            }
            else if(nums[mid]>nums[0]) low = mid + 1;
            else high = mid - 1;
        }
        if(pivot_idx==-1) return nums[0];
        return nums[pivot_idx];
    }
};