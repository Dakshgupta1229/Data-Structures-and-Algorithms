class Solution {
    public int maxArea(int[] height) {
        int i=0;
        int j=height.length-1;
        int max_volume = 0;
        while(i<j){
            int volume = (j-i) * Math.min(height[i],height[j]);
            if(max_volume<volume) max_volume = volume;
            if(height[i]<height[j]) i++;
            else j--;
        }
        return max_volume;
    }
}