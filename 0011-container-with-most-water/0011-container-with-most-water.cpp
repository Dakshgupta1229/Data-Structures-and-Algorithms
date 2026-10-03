class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j= height.size()-1;
        int max_volume = 0;
        while(i<j){
            int min_ele = min(height[i],height[j]);
            int volume = (j-i) * min_ele;
            if(max_volume<volume) max_volume = volume;
            if(height[i]<height[j]) i++;
            else j--;
        }
        return max_volume;
    }
};