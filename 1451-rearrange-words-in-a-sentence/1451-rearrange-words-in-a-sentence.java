class Solution {
    public String arrangeWords(String text) {
        Map<Integer,List<String>> map = new TreeMap<>();
        String[] str = text.split(" ");
        for(int i=0;i<str.length;i++){
            String s = str[i];
            map.computeIfAbsent(s.length(),k -> new ArrayList<>()).add(s);
        }
        StringBuilder result = new StringBuilder();
        for(Integer p:map.keySet()){
            List<String> list = map.get(p);
            for(int i=0;i<list.size();i++){
                StringBuilder ss = new StringBuilder(list.get(i).toLowerCase());
                if(result.length()==0){
                    char ch = ss.charAt(0);
                    ss.setCharAt(0,(char)((int)ch-32));
                }
                result.append(ss);
                result.append(" ");
            }
        }
        return result.toString().trim();
    }
}