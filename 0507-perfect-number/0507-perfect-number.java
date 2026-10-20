class Solution {
    public boolean checkPerfectNumber(int num) {
        int sum = 0;
        for(int i=1;i<=Math.sqrt(num);i++){
            if(num%i==0){
                if(i!=num) sum = sum + i;
                if(num/i!=i && num/i!=num) sum = sum + num/i;
            }
        }
        if(sum==num) return true;
        return false;
    }
}