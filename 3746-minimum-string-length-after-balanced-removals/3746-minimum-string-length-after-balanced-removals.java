class Solution {
    public int minLengthAfterRemovals(String s) {
        Map<Character,Integer> map = new HashMap<>();
        int count1 = 0;
        int count2 = 0;
        for(int i=0;i<s.length();i++){
            if(map.containsKey(s.charAt(i))){
                map.put(s.charAt(i),map.get(s.charAt(i)) + 1);
            }
            else map.put(s.charAt(i),1);
        }
        if(map.containsKey('a')) count1 = map.get('a');
        if(map.containsKey('b')) count2 = map.get('b');
        return Math.abs(count1 - count2);
    }
}