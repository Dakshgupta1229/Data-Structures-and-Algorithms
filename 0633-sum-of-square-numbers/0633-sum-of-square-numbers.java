class Solution {
    public boolean judgeSquareSum(int c) {
        long a = 0;
        long b = (int)Math.sqrt(c);
        while(a<=b){
            long sum = (a*a) + (b*b);
            if(sum==(long)c) return true;
            else if(sum>(long)c) b--;
            else a++;
        }
        return false;
    }
}