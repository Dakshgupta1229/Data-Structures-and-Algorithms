class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int low = 0;
        int high = arr.length-1;
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
        if(pivot_idx==-1) pivot_idx = high;
        int index1 = pivot_idx;
        int index2 = pivot_idx+1;
        List<Integer> list = new ArrayList<>();
        while(list.size()!=k && index1>=0 && index2<arr.length){
            int diff1 = Math.abs(arr[index1] - x);
            int diff2 = Math.abs(arr[index2] - x);
            if(diff1<=diff2){
                list.add(arr[index1]);
                index1--;
            }
            else{
                list.add(arr[index2]);
                index2++;
            }
        }
        while(list.size()!=k && index1>=0){
            list.add(arr[index1]);
            index1--;
        }
        while(list.size()!=k && index2<arr.length){
            list.add(arr[index2]);
            index2++;
        }
        Collections.sort(list);
        return list;
    }
}