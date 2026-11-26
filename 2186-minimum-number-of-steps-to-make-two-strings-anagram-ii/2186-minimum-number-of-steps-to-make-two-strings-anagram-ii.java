class Solution {
    public int minSteps(String s, String t) {
        Map<Character,Integer> map1 = new HashMap<>();
        Map<Character,Integer> map2 = new HashMap<>();
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(!map1.containsKey(ch)) map1.put(ch,1);
            else map1.put(ch,map1.get(ch)+1);
        }
        for(int i=0;i<t.length();i++){
            char ch = t.charAt(i);
            if(!map2.containsKey(ch)) map2.put(ch,1);
            else map2.put(ch,map2.get(ch)+1);
        }
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(map2.containsKey(ch)){
                int freq = map2.get(ch);
                if(freq==1) map2.remove(ch);
                else map2.put(ch,freq-1);
            }
        }
        for(int i=0;i<t.length();i++){
            char ch = t.charAt(i);
            if(map1.containsKey(ch)){
                int freq = map1.get(ch);
                if(freq==1) map1.remove(ch);
                else map1.put(ch,freq-1);
            }
        }
        int sum = 0;
        for(Character p:map1.keySet()){
            sum = sum + map1.get(p);
        }
        System.out.println();
        for(Character p:map2.keySet()){
            sum = sum + map2.get(p);
        }

        return sum;
    }
}