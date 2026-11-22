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

    public int diagonalPrime(int[][] nums) {
        int max_ele = 0;
        for(int i=0;i<nums.length;i++){
            int first = nums[i][i];
            int second = nums[i][nums.length-i-1];
            if(isPrime(first)){
                if(max_ele<first) max_ele = first;
            }
            if(isPrime(second)){
                if(max_ele<second) max_ele = second;
            }
        }
        return max_ele;
    }
}