class Solution {
    public String getSmallestString(String s) {
        String result = s;
        List<String> list = new ArrayList<>();
        for(int i=0;i<s.length()-1;i++){
            StringBuffer str = new StringBuffer(s);
            char ch1 = str.charAt(i);
            char ch2 = str.charAt(i+1);
            int digit1 = (int)ch1-48;
            int digit2 = (int)ch2-48;
            if(digit1%2==0 && digit2%2==0){
                char ch = ch1;
                str.setCharAt(i,ch2);
                str.setCharAt(i+1,ch);
                list.add(str.toString());
            }
            if(digit1%2!=0 && digit2%2!=0){
                char ch = ch1;
                str.setCharAt(i,ch2);
                str.setCharAt(i+1,ch);
                list.add(str.toString());
            }
            
        }
        for(int i=0;i<list.size();i++){
            if(result.length()==0) result = list.get(i);
            else if(result.compareTo(list.get(i))>0) result = list.get(i);
        }

        return result;
    }
}