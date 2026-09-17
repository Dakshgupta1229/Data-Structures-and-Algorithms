class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target) return true;
            else return false;
        }
        if(nums.size()==2){
            if(nums[0]==target || nums[1]==target) return true;
            else return false;
        }
        int pivot_idx = -1;
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid==0) low = mid + 1;
            else if(mid==nums.size()-1) high = mid - 1;
            else if(nums[mid]==target || nums[low]==target || nums[high]==target) return true;
            else if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                low++;
                high--;
            }
            else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                pivot_idx = mid+1;
                if(nums[mid]==nums[mid+1]) low = mid + 1;
                else break;
            }
            else if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                pivot_idx = mid;
                if(nums[mid]==nums[mid+1]) high = mid - 1;
                else break;
            }
            else if(nums[mid]>=nums[0]) low = mid + 1;
            else high = mid - 1;
        }
        if(pivot_idx==-1){
            low = 0;
            high = nums.size()-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]==target) return true;
                else if(nums[mid]>target) high = mid - 1;
                else low = mid + 1;
            }
            return false;
        }
        else{
            low = 0;
            high = pivot_idx-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]==target) return true;
                else if(nums[mid]>target) high = mid - 1;
                else low = mid + 1;
            }
            low = pivot_idx;
            high = nums.size()-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]==target) return true;
                else if(nums[mid]>target) high = mid - 1;
                else low = mid + 1;
            }
        }
        return false;
    }
};