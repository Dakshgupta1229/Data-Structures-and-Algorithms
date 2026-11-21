class Solution {
    public int[] replaceElements(int[] arr) {
        int ele = arr[arr.length-1];
        arr[arr.length-1] = -1;
        for(int i=arr.length-2;i>=0;i--){
            int value = arr[i];
            arr[i] = ele;
            if(ele<value) ele = value;
        }
        return arr;
    }
}