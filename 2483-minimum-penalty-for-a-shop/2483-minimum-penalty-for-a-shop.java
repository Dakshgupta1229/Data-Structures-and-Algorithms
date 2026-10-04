class Solution {
    public int bestClosingTime(String customers) {
        int[] prefix = new int[customers.length()+1];
        int[] suffix = new int[customers.length()+1];
        prefix[0] = 0;
        suffix[suffix.length-1] = 0;
        for(int i=0;i<customers.length();i++){
            if(customers.charAt(i)=='N') prefix[i+1] = 1 + prefix[i];
            else prefix[i+1] = 0 + prefix[i];
        }
        for(int i=customers.length()-1;i>=0;i--){
            if(customers.charAt(i)=='Y') suffix[i] = 1 + suffix[i+1];
            else suffix[i] = 0 + suffix[i+1];
        }
        int min_ele = Integer.MAX_VALUE;
        int idx = -1;
        for(int i=0;i<prefix.length;i++){
            if(min_ele>(prefix[i] + suffix[i])){
                min_ele = prefix[i] + suffix[i];
                idx = i;
            }
        }
        return idx;
    }
}