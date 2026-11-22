class Solution {
    public List<List<Integer>> findPrimePairs(int n) {
        int[] sieve = new int[n+1];
        Arrays.fill(sieve,1);
        sieve[0] = 0;
        sieve[1] = 0;
        List<List<Integer>> list = new ArrayList<>();
        for(int i=2;i<=Math.sqrt(n);i++){
            for(int j=i*i;j<sieve.length;j+=i){
                sieve[j] = 0;
            }
        }
        List<Integer> list2 = new ArrayList<>();
        for(int i=2;i<sieve.length;i++){
            if(sieve[i]==1) list2.add(i);
        }
        int i=0;
        int j=list2.size()-1;
        while(i<=j){
            int sum = list2.get(i) + list2.get(j);
            if(sum==n){
                List<Integer> list3 = new ArrayList<>();
                list3.add(list2.get(i));
                list3.add(list2.get(j));
                list.add(list3);
                i++;
            }
            else if(sum<n) i++;
            else j--;
        }
        return list;

    }
}