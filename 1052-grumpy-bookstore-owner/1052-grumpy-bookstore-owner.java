class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int[] arr1 = new int[customers.length-minutes+1];
        int[] arr2 = new int[customers.length-minutes+1];
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0;i<minutes;i++){
            sum1 = sum1 + customers[i];
            if(grumpy[i]==0) sum2 = sum2 + customers[i];
        }
        arr1[0] = sum1;
        arr2[0] = sum2;
        for(int i=1;i<=customers.length-minutes;i++){
            sum1 = sum1 - customers[i-1];
            sum1 = sum1 + customers[i+minutes-1];
            if(grumpy[i-1]==0) sum2 = sum2 - customers[i-1];
            if(grumpy[i+minutes-1]==0) sum2 = sum2 + customers[i+minutes-1];
            arr1[i] = sum1;
            arr2[i] = sum2;
        }
        int max_ele = Integer.MIN_VALUE;
        int idx = -1;
        for(int i=0;i<arr1.length;i++){
            if(max_ele<(arr1[i]-arr2[i])){
                max_ele = arr1[i] - arr2[i];
                idx = i;
            }
        }
        for(int i=idx;i<idx+minutes;i++){
            grumpy[i] = 0;
        }
        int result = 0;
        for(int i=0;i<customers.length;i++){
            if(grumpy[i]==0) result = result + customers[i];
        }
        return result;
    }
}