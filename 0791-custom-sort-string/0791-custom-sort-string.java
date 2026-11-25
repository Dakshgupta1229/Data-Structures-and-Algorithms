class Solution {
    public String customSortString(String order, String s) {
        Map<Character,Integer> map = new HashMap<>();
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(!map.containsKey(ch)) map.put(ch,1);
            else map.put(ch,map.get(ch)+1);
        }
        StringBuffer str = new StringBuffer();
        for(int i=0;i<order.length();i++){
            char ch = order.charAt(i);
            if(map.containsKey(ch)){
                int freq = map.get(ch);
                while(freq>0){
                    str.append(ch);
                    freq--;
                }
                if(freq==0) map.remove(ch);
            }
        }
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(map.containsKey(ch)) str.append(ch);
        }
        return str.toString();
    }
}