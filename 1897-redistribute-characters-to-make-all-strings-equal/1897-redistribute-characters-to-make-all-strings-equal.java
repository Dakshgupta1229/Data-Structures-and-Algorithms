class Solution {
    public boolean makeEqual(String[] words) {
        if(words.length==1) return true;
        Map<Character,Integer> map = new HashMap<>();
        for(int i=0;i<words.length;i++){
            String str = words[i];
            for(int j=0;j<str.length();j++){
                char ch = str.charAt(j);
                if(!map.containsKey(ch)) map.put(ch,1);
                else map.put(ch,map.get(ch)+1);
            }
        }
        int sum = 0;
        for(Character p:map.keySet()){
            sum = sum + map.get(p);
            int freq = map.get(p);
            if(freq%words.length!=0) return false;
        }
        if(sum%words.length!=0) return false;
        return true;
    }
}