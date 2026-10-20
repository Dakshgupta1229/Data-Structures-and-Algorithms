class Solution {
    public int[] closestPrimes(int left, int right) {
        int[] sieve = new int[right+1];
        Arrays.fill(sieve,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=Math.sqrt(right);i++){
            for(int j=i*i;j<sieve.length;j+=i){
                sieve[j] = 0;
            }
        }
        List<Integer> list = new ArrayList<>();
        for(int i=left;i<=right;i++){
            if(sieve[i]==1) list.add(i);
        }
        if(list.size()<=1) return new int[]{-1,-1};
        int first = list.get(0);
        int min_diff = Integer.MAX_VALUE;
        int res1 = -1;
        int res2 = -1;
        for(int i=1;i<list.size();i++){
            int second = list.get(i);
            if(min_diff>second - first){
                min_diff = second - first;
                res1 = first;
                res2 = second;
            }
            first = second;
        }
        return new int[]{res1,res2};

    }
}