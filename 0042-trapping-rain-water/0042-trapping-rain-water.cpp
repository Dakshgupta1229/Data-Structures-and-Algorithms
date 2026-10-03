class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> next_greater(height.size());
        vector<int> prev_greater(height.size());
        next_greater[height.size()-1] = -1;
        int max_ele = height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            next_greater[i] = max_ele;
            if(max_ele<height[i]) max_ele = height[i];
        }
        prev_greater[0] = -1;
        int max_ele2 = height[0];
        for(int i=1;i<height.size();i++){
            prev_greater[i] = max_ele2;
            if(max_ele2<height[i]) max_ele2 = height[i];
        }

        int sum = 0;
        for(int i=1;i<height.size()-1;i++){
            int min_ele = min(next_greater[i],prev_greater[i]);
            if(height[i]<min_ele){
                sum = sum + (min_ele - height[i]);
            }
        }
        return sum;
    }
};