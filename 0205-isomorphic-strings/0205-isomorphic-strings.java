class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] ascii1 = new int[254];
        Arrays.fill(ascii1,1024);
        int[] ascii2 = new int[254];
        Arrays.fill(ascii2,1024);
        for(int i=0;i<s.length();i++){
            int index = (int)s.charAt(i);
            int diff = (int)s.charAt(i) - (int)t.charAt(i);
            if(ascii1[index]==1024) ascii1[index] = diff;
            else if(ascii1[index]==diff) continue;
            else return false;
        }
        for(int i=0;i<t.length();i++){
            int index = (int)t.charAt(i);
            int diff = (int)t.charAt(i) - (int)s.charAt(i);
            if(ascii2[index]==1024) ascii2[index] = diff;
            else if(ascii2[index]==diff) continue;
            else return false;
        }
        return true;
    }
}