class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int[] suffix = Arrays.copyOf(satisfaction,satisfaction.length);
        for(int i=suffix.length-2;i>=0;i--){
            suffix[i] = suffix[i] + suffix[i+1];
        }
        int idx = -1;
        for(int i=suffix.length-1;i>=0;i--){
            if(suffix[i]<0){
                idx = i;
                break;
            }
        }
        int sum = 0;
        int cnt = 1;
        for(int i=idx+1;i<suffix.length;i++){
            sum = sum + (satisfaction[i] * cnt);
            cnt++;
        }
        return sum;
    }
}