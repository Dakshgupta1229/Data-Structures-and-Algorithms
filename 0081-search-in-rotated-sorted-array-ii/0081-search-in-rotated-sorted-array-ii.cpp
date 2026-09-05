class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==2){
            if(nums[0]==target) return true;
            if(nums[1]==target) return true;
            return false;
        }
        int pivot_idx = -1;
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target || nums[low]==target || nums[high]==target) return true;
            if(mid==0) low++;
            else if(mid==nums.size()-1) high--;
            else if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                low++;
                high--;
            }
            else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                pivot_idx = mid + 1;
                if(nums[mid]==nums[mid+1]) low = mid + 1;
                else break;
            }
            else if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                pivot_idx = mid;
                if(nums[mid]==nums[mid-1]) high = mid - 1;
                else break;
            }
            else if(nums[mid]>=nums[0]) low = mid + 1;
            else high = mid - 1;
        }
        cout<<pivot_idx<<endl;
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