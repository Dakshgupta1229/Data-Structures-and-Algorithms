class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int[] suffix = Arrays.copyOf(satisfaction,satisfaction.length);
        for(int i=satisfaction.length-2;i>=0;i--){
            suffix[i] = suffix[i] + suffix[i+1];
        }
        int pivot_idx = -1;
        for(int i=0;i<satisfaction.length;i++){
            if(suffix[i]>=0){
                pivot_idx = i;
                break;
            }
        }
        if(pivot_idx==-1) return 0;
        int sum = 0;
        int index = 1;
        for(int i=pivot_idx;i<satisfaction.length;i++){
            sum = sum + (satisfaction[i] * index);
            index++;
        }
        return sum;
    }
}