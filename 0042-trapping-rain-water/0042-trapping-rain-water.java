class Solution {
    public int trap(int[] height) {
        int[] next_greater = new int[height.length];
        int[] prev_greater = new int[height.length];
        next_greater[height.length-1] = -1;
        prev_greater[0] = -1;
        int max_ele = height[height.length-1];
        for(int i=height.length-2;i>=0;i--){
            next_greater[i] = max_ele;
            if(max_ele<height[i]) max_ele = height[i];
        }
        int max_ele2 = height[0];
        for(int i=1;i<height.length;i++){
            prev_greater[i] = max_ele2;
            if(max_ele2<height[i]) max_ele2 = height[i];
        }
        int sum = 0;
        for(int i=1;i<height.length-1;i++){
            int min_ele = Math.min(next_greater[i],prev_greater[i]);
            if(height[i]<min_ele){
                sum = sum + (min_ele - height[i]);
            }
        }
        return sum;
    }
}