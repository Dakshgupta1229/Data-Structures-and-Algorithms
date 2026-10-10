class Solution {
    public int titleToNumber(String columnTitle) {
        int sum = 0;
        int idx = 0;
        for(int i=columnTitle.length()-1;i>=0;i--){
            sum = sum + ((int)columnTitle.charAt(i)-65+1) * (int)Math.pow(26,idx);
            idx++;
        }
        return sum;
    }
}