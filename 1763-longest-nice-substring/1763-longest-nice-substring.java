class Solution {
    public String longestNiceSubstring(String s) {
        String result = "";
        for(int i=0;i<s.length();i++){
            String str = "";
            Map<Character,Integer> map = new HashMap<>();
            for(int j=i;j<s.length();j++){
                char ch = s.charAt(j);
                map.put(ch,j);
                str = str + ch;
                boolean flag = true;
                for(Character p:map.keySet()){
                    char ch2 = p;
                    int ascii = (int)ch2;
                    if(ascii>=97 && ascii<=122){
                        char c = (char)(ascii-32);
                        if(!map.containsKey(c)){
                            flag = false;
                            break;
                        }
                    }
                    else{
                        char c = (char)(ascii+32);
                        if(!map.containsKey(c)){
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag==true && result.length()<str.length()) result = str;
            }
        }
        return result;
    }
}