class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int[] prefix = new int[words.length];
        int count = 0;
        for(int i=0;i<words.length;i++){
            String str = words[i];
            char ch1 = str.charAt(0);
            char ch2 = str.charAt(str.length()-1);
            if(ch1=='a' || ch1=='e' || ch1=='i' || ch1=='o' || ch1=='u'){
                if(ch2=='a' || ch2=='e' || ch2=='i' || ch2=='o' || ch2=='u'){
                    count++;
                }
            }
            prefix[i] = count;
        }
        int[] result = new int[queries.length];
        for(int i=0;i<queries.length;i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int sum = prefix[end];
            if(start-1>=0) sum = sum - prefix[start-1];
            result[i] = sum;
        }
        return result;
    }
}