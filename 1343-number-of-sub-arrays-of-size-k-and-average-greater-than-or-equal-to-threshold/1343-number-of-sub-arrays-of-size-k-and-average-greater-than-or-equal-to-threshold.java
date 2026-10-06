class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int count = 0;
        double sum = 0;
        double n = (double)k;
        for(int i=0;i<k;i++){
            sum = sum + (double)arr[i];
        }
        if(sum/n>=threshold) count++;
        for(int i=1;i<=arr.length-k;i++){
            sum = sum - (double)arr[i-1];
            sum = sum + (double)arr[i+k-1];
            if(sum/n>=threshold) count++;
        }
        return count;
    }
}