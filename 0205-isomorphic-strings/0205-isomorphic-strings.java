class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length()) return false;
        int[] arr1 = new int[256];
        int[] arr2 = new int[256];
        Arrays.fill(arr1,1000);
        Arrays.fill(arr2,1000);
        for(int i=0;i<s.length();i++){
            int index = (int)(s.charAt(i));
            if(arr1[index]==1000){
                arr1[index] = (int)(s.charAt(i) - t.charAt(i));
            }
            else if(arr1[index]==(int)(s.charAt(i)-t.charAt(i))) continue;
            else return false;
        }
        for(int i=0;i<t.length();i++){
            int index = (int)(t.charAt(i));
            if(arr2[index]==1000){
                arr2[index] = (int)(t.charAt(i) - s.charAt(i));
            }
            else if(arr2[index]==(int)(t.charAt(i) - s.charAt(i))) continue;
            else return false;
        }
        return true;
    }
}