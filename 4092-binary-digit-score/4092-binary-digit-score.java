class Solution {
    public int calculateScore(int a, int b) {
        int count1 = 0;
        int count2 = 0;
        while(a!=0){
            if(a%2==1) count1++;
            a = a/2;
        }
        while(b!=0){
            if(b%2==1) count2++;
            b = b/2;
        }
        if(count1>=count2) return count1 * count2;
        else return count2/count1;
    }
}