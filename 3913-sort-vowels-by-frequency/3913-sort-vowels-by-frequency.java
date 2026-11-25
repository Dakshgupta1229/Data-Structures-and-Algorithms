class Solution {
    public String sortVowels(String s) {
        Map<Character,Integer> map = new LinkedHashMap<>();
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                if(!map.containsKey(ch)) map.put(ch,1);
                else map.put(ch,map.get(ch)+1);
            }
        }
        Map<Integer,List<Character>> map2 = new TreeMap<>();
        for(Character p:map.keySet()){
            int ele = map.get(p);
            map2.computeIfAbsent(ele,k -> new ArrayList<>()).add(p);
        }
        List<Integer> list = new ArrayList<>();
        for(Integer p:map2.keySet()){
            list.add(p);
        }
        Collections.reverse(list);
        List<Character> list2 = new ArrayList<>();
        for(int i=0;i<list.size();i++){
            int ele = list.get(i);
            List<Character> list3 = map2.get(ele);
            for(int j=0;j<list3.size();j++){
                for(int k=0;k<ele;k++) list2.add(list3.get(j));
            }
        }
        int index = 0;
        StringBuilder str = new StringBuilder(s);
        for(int i=0;i<str.length();i++){
            char ch = str.charAt(i);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                str.setCharAt(i,list2.get(index));
                index++;
            }
        }
        return str.toString();
    }
}