class Solution {
    public int minRotations(String s) {
        int count = 0;
        int start = 0;
        for(int i=0;i<s.length();i++){
            int target = s.charAt(i) - 48;
            int reach1 = Math.abs(target - start);
            int reach2 = 10 - reach1;
            start = target;
            count = count + Math.min(reach1,reach2);
        }
        return count;
    }
}