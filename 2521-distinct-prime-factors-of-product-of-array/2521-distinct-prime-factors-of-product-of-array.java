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

    public int distinctPrimeFactors(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int i=0;i<nums.length;i++){
            int ele = nums[i];
            for(int j=2;j<=ele;j++){
                if(!set.contains(j)){
                    if(nums[i]%j==0 && isPrime(j)) set.add(j);
                }
            }
        }
        return set.size();
    }
}