class Solution {
    public int distinctPrimeFactors(int[] nums) {
        int max_ele = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            if(max_ele<nums[i]) max_ele = nums[i];
        }
        boolean[] sieve = new boolean[max_ele+1];
        Arrays.fill(sieve,true);
        sieve[0] = false;
        sieve[1] = false;
        for(int i=2;i<=Math.sqrt(max_ele);i++){
            for(int j=i*i;j<sieve.length;j+=i){
                sieve[j] = false;
            }
        }
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<sieve.length;i++){
            if(sieve[i]==true) list.add(i);
        }
        Set<Integer> set = new HashSet<>();
        for(int i=0;i<nums.length;i++){
            int ele = nums[i];
            for(int j=0;j<list.size();j++){
                int ele2 = list.get(j);
                if(ele%ele2==0){
                    while(ele%ele2==0){
                        set.add(ele2);
                        ele = ele/ele2;
                    }
                }
            }
        }
        return set.size();
    }
}