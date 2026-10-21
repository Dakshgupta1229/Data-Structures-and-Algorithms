class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max_length = 0;
        int i=0;
        int j=0;
        Map<Character,Integer> map = new HashMap<>();
        while(i<s.length()){
            if(!map.containsKey(s.charAt(i))){
                map.put(s.charAt(i),i);
            }
            else{
                if(max_length<(i-j)) max_length = i-j;
                if(j<(map.get(s.charAt(i)) + 1)) j = map.get(s.charAt(i)) + 1;
                map.put(s.charAt(i),i);
            }
            i++;
        }
        if(max_length<(i-j)) max_length = i-j;
        return max_length;
    }
}