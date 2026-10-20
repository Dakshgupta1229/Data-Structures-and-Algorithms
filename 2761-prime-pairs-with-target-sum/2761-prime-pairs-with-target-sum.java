class Solution {
    public List<List<Integer>> findPrimePairs(int n) {
        List<List<Integer>> list = new ArrayList<>();
        int[] sieve = new int[n+1];
        Arrays.fill(sieve,1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2;i<=Math.sqrt(n);i++){
            for(int j=i*i;j<sieve.length;j+=i){
                sieve[j] = 0;
            }
        }
        List<Integer> list1 = new ArrayList<>();
        for(int i=0;i<sieve.length;i++){
            if(sieve[i]==1) list1.add(i);
        }

        int i=0;
        int j=list1.size()-1;
        while(i<=j){
            int sum = list1.get(i) + list1.get(j);
            if(sum==n){
                list.add(new ArrayList<>(List.of(list1.get(i),list1.get(j))));
                i++;
                j--;
            }
            else if(sum>n) j--;
            else i++;
        }

        return list;
    }
}