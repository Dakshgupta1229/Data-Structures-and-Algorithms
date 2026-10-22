class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] arr1 = s.split(" ");
        char[] arr2 = pattern.toCharArray();
        if(arr1.length!=arr2.length) return false;
        Map<String,Character> map = new HashMap<>();
        for(int i=0;i<arr1.length;i++){
            if(!map.containsKey(arr1[i])){
                map.put(arr1[i],arr2[i]);
            }
            else{
                if(map.get(arr1[i])==arr2[i]) continue;
                else return false;
            }
        }
        Map<Character,String> map1 = new HashMap<>();
        for(int i=0;i<arr2.length;i++){
            if(!map1.containsKey(arr2[i])){
                map1.put(arr2[i],arr1[i]);
            }
            else{
                if(map1.get(arr2[i]).equals(arr1[i])) continue;
                else{
                    return false;
                }
            }
        }
        return true;
    }
}