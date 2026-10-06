class Solution {
    public int[] replaceElements(int[] arr) {
        int max_ele = arr[arr.length-1];
        arr[arr.length-1] = -1;
        for(int i=arr.length-2;i>=0;i--){
            int ele = arr[i];
            arr[i] = max_ele;
            if(max_ele<ele) max_ele = ele;
        }
        return arr;
    }
}