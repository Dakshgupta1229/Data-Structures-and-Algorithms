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

    public int smallestValue(int n) {
        while(true){
            int num = n;
            int sum = 0;
            for(int i=2;i<=num;i++){
                if(num!=0 && num%i==0 && isPrime(i)){
                    while(num!=0 && num%i==0){
                        num = num/i;
                        sum = sum + i;
                    }
                }
            }
            if(sum==n) break;
            n = sum;
            if(isPrime(n)) break;
        }
        return n;
    }
}