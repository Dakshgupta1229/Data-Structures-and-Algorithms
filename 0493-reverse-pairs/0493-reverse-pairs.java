class Solution {

    void merge(int[] nums,int low,int mid,int high){
        int left = low;
        int right = mid+1;
        List<Integer> list = new ArrayList<>();
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                list.add(nums[left]);
                left++;
            }
            else{
                list.add(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            list.add(nums[left]);
            left++;
        }
        while(right<=high){
            list.add(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i] = list.get(i-low);
        }
    }

    void merge_sort(int[] nums,int low,int high,long[] count){
        if(low>=high) return;
        int mid = low + (high-low)/2;
        merge_sort(nums,low,mid,count);
        merge_sort(nums,mid+1,high,count);
        int right = mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i]>((long)2*(long)nums[right])) right++;
            count[0] = count[0] + ((long)right - ((long)mid + (long)1));
        }
        merge(nums,low,mid,high);
    }

    public int reversePairs(int[] nums) {
        long[] count = {0};
        merge_sort(nums,0,nums.length-1,count);
        for(int i=0;i<nums.length;i++){
            System.out.print(nums[i]+" ");
        }
        return (int)count[0];
    }
}