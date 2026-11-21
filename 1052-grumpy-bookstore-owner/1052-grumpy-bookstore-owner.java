class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int max_diff = Integer.MIN_VALUE;
        int idx = -1;
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0;i<minutes;i++){
            sum1 = sum1 + customers[i];
            if(grumpy[i]==0) sum2 = sum2 + customers[i];
            if(max_diff<(sum1-sum2)){
                max_diff = sum1 - sum2;
                idx = 0;
            }
        }
        for(int i=1;i<=customers.length-minutes;i++){
            sum1 = sum1 - customers[i-1];
            sum1 = sum1 + customers[i+minutes-1];
            if(grumpy[i-1]==0) sum2 = sum2 - customers[i-1];
            if(grumpy[i+minutes-1]==0) sum2 = sum2 + customers[i+minutes-1];
            if(max_diff<(sum1-sum2)){
                max_diff = sum1 - sum2;
                idx = i;
            }
        }
        for(int i=idx;i<idx+minutes;i++){
            grumpy[i] = 0;
        }
        int sum = 0;
        for(int i=0;i<customers.length;i++){
            if(grumpy[i]==0) sum = sum + customers[i];
        }
        return sum;
    }
}