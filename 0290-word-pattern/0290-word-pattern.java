class Solution {
    public boolean wordPattern(String pattern, String s) {
        Map<Character,String> map = new HashMap<>();
        String[] str = s.split(" ");
        if(str.length!=pattern.length()) return false;
        for(int i=0;i<pattern.length();i++){
            char ch = pattern.charAt(i);
            if(!map.containsKey(ch)){
                map.put(ch,str[i]);
            }
            else{
                if(map.get(ch).equals((str[i]))) continue;
                else{
                    return false;
                }
            }
        }
        Map<String,Character> map2 = new HashMap<>();
        for(int i=0;i<str.length;i++){
            String stt = str[i];
            if(!map2.containsKey(stt)){
                map2.put(stt,pattern.charAt(i));
            }
            else{
                if(map2.get(stt).equals((pattern.charAt(i)))) continue;
                else return false;
            }
        }
        return true;
    }
}