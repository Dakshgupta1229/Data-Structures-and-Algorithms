class Solution {
    public int findKthPositive(int[] arr, int k) {
        Set<Integer> set = new HashSet<>();
        for(int i=0;i<arr.length;i++) set.add(arr[i]);
        for(int i=1;i<=1000000;i++){
            if(!set.contains(i)) k--;
            if(k==0) return i;
        }
        return arr.length + 1;
    }
}