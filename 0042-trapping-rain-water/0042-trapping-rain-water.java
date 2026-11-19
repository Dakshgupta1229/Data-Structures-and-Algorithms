class Solution {
    public int trap(int[] height) {
        int[] prev = new int[height.length];
        int[] next = new int[height.length];
        prev[0] = -1;
        int ele = height[0];
        for(int i=1;i<height.length;i++){
            prev[i] = ele;
            if(ele<height[i]) ele = height[i];
        }
        next[height.length-1] = -1;
        int ele2 = height[height.length-1];
        for(int i=height.length-2;i>=0;i--){
            next[i] = ele2;
            if(ele2<height[i]) ele2 = height[i];
        }
        int sum = 0;
        for(int i=1;i<height.length-1;i++){
            int min_ele = Math.min(prev[i],next[i]);
            if(height[i]<min_ele){
                sum = sum + (min_ele - height[i]);
            }
        }
        return sum;
    }
}