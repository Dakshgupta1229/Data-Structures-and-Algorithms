class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> list = new ArrayList<>();
        int low = 0;
        int high = arr.length - 1;
        int pivot_idx = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==x){
                pivot_idx = mid;
                break;
            }
            else if(arr[mid]>x) high = mid - 1;
            else low = mid + 1;
        }
        if(pivot_idx==-1){
            while(list.size()<k && high>=0 && low<arr.length){
                if(Math.abs(arr[high]-x)<=Math.abs(arr[low]-x)){
                    list.add(arr[high]);
                    high--;
                }
                else{
                    list.add(arr[low]);
                    low++;
                }
            }
            while(list.size()<k && high>=0){
                list.add(arr[high]);
                high--;
            }
            while(list.size()<k && low<arr.length){
                list.add(arr[low]);
                low++;
            }
        }
        else{
            low = pivot_idx;
            high = pivot_idx+1;
            while(list.size()<k && low>=0 && high<arr.length){
                if(Math.abs(arr[low]-x)<=Math.abs(arr[high]-x)){
                    list.add(arr[low]);
                    low--;
                }
                else{
                    list.add(arr[high]);
                    high++;
                }
            }
            while(list.size()<k && low>=0){
                list.add(arr[low]);
                low--;
            }
            while(list.size()<k && high<arr.length){
                list.add(arr[high]);
                high++;
            }
        }
        Collections.sort(list);
        return list;
    }
}