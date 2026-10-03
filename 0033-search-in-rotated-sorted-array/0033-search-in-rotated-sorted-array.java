class Solution {
    public int search(int[] nums, int target) {
        if(nums.length==0) return -1;
        if(nums.length==1){
            if(nums[0]==target) return 0;
            else return -1;
        }
        if(nums.length==2){
            if(nums[0]==target) return 0;
            else if(nums[1]==target) return 1;
            else return -1;
        }
        int pivot_idx = -1;
        int low = 0;
        int high = nums.length - 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid==0) low++;
            else if(mid==nums.length-1) high--;
            else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                pivot_idx = mid;
                break;
            }
            else if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]){
                pivot_idx = mid - 1;
                break;
            }
            else if(nums[mid]>nums[low]) low = mid + 1;
            else high = mid - 1;
        }
        if(pivot_idx==-1){
            low = 0;
            high = nums.length-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) high = mid - 1;
                else low = mid + 1;
            }
        }
        else{
            low = 0;
            high = pivot_idx;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) high = mid - 1;
                else low = mid + 1;
            }
            low = pivot_idx+1;
            high = nums.length-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) high = mid - 1;
                else low = mid + 1;
            }
        }
        return -1;
    }
}