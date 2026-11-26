class Solution {
    public int longestBalanced(String s) {
        int result = 0;
        for(int i=0;i<s.length();i++){
            Map<Character,Integer> map = new HashMap<>();
            for(int j=i;j<s.length();j++){
                char ch = s.charAt(j);
                if(!map.containsKey(ch)) map.put(ch,1);
                else map.put(ch,map.get(ch)+1);
                int freq = map.get(ch);
                boolean flag = true;
                for(Character p:map.keySet()){
                    int freq2 = map.get(p);
                    if(freq2!=freq){
                        flag = false;
                        break;
                    }
                }
                if(flag==true){
                    if(result<(freq*map.size())) result = freq * map.size();
                }
            }
        }
        return result;
    }
}