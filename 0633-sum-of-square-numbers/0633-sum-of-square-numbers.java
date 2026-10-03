class Solution {
    public boolean judgeSquareSum(int c) {
        long a = 0;
        long b = (long)Math.sqrt(c);
        System.out.println(a);
        System.out.println(b);
        while(a<=b){
            long first = a * a;
            long second = b * b;
            long sum = first + second;
            if(sum==(long)c) return true;
            else if(sum>(long)c) b--;
            else a++;
        }
        return false;
    }
}