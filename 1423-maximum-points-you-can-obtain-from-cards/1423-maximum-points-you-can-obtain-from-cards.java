class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int sum = 0;
        int max_sum = 0;
        for(int i=0;i<k;i++) sum = sum + cardPoints[i];
        if(max_sum<sum) max_sum = sum;
        int index = cardPoints.length-1;
        for(int i=k-1;i>=0;i--){
            sum = sum - cardPoints[i];
            sum = sum + cardPoints[index];
            index--;
            if(max_sum<sum) max_sum = sum;
        }
        return max_sum;
    }
}