class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int sum = 0;
        for(int i=0;i<arr.length;i++){
            int sum1 = 0;
            for(int j=i;j<arr.length;j++){
                sum1 = sum1 + arr[j];
                if((j-i)%2==0) sum = sum + sum1;
            }
        }
        return sum;
    }
}