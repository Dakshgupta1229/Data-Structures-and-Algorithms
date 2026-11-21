class Solution {
    public int bestClosingTime(String customers) {
        int[] prefix = new int[customers.length()+1];
        int[] suffix = new int[customers.length()+1];
        prefix[0] = 0;
        for(int i=0;i<customers.length();i++){
            if(customers.charAt(i)=='N') prefix[i+1] = prefix[i] + 1;
            else prefix[i+1] = prefix[i];
        }
        suffix[suffix.length-1] = 0;
        for(int i=customers.length()-1;i>=0;i--){
            if(customers.charAt(i)=='Y') suffix[i] = suffix[i+1] + 1;
            else suffix[i] = suffix[i+1];
        }
        int value = Integer.MAX_VALUE;
        int index = -1;
        for(int i=0;i<prefix.length;i++){
            int sum = prefix[i] + suffix[i];
            if(value>sum){
                value = sum;
                index = i;
            }
        }
        return index;
    }
}