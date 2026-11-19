class Solution {
    public int maxArea(int[] height) {
        int i=0;
        int j=height.length-1;
        int max_volume = Integer.MIN_VALUE;
        while(i<j){
            int width = j-i;
            int volume = Math.min(height[i],height[j]) * width;
            if(max_volume<volume){
                max_volume = volume;
            }
            if(height[i]<height[j]) i++;
            else j--;
        }
        return max_volume;
    }
}