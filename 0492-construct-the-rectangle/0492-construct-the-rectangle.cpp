class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width = -1;
        int length = -1;
        int low = 1;
        int high = area;
        while(low<=high){
            int result = low * high;
            if(result==area){
                length = high;
                width = low;
            }
            if(result>area) high--;
            else low++;
        }
        return {length,width};
    }
};