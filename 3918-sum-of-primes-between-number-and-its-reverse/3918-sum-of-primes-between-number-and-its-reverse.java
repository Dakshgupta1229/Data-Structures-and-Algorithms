class Solution {

    boolean isPrime(int num){
        boolean flag = true;
        for(int i=2;i<=Math.sqrt(num);i++){
            if(num%i==0){
                flag = false;
                break;
            }
        }
        if(flag==true && num!=1) return true;
        return false;
    }

    public int sumOfPrimesInRange(int n) {
        int r = 0;
        int num = n;
        while(num!=0){
            r = r * 10;
            r = r + num%10;
            num = num/10;
        }
        int sum = 0;
        for(int i=Math.min(n,r);i<=Math.max(n,r);i++){
            int ele = i;
            if(isPrime(ele)){
                sum = sum + ele;
            }
        }
        return sum;
    }
}