class Solution {
    public int lengthOfLongestSubstring(String s) {
        int i=0;
        int j=0;
        int max_length = 0;
        Map<Character,Integer> map = new HashMap<>();
        while(j<s.length()){
            char ch = s.charAt(j);
            if(!map.containsKey(ch)) map.put(ch,j);
            else{
                if(max_length<(j-i)) max_length = j - i;
                if(i<map.get(ch)+1) i = map.get(ch)+1;
                map.put(ch,j);
            }
            j++;
        }
        if(max_length<(j-i)) max_length = j-i;
        return max_length;
    }
}