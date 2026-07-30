class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        while(low<=high){
            int mid = low + (high-low)/2;
            if((long long)mid*mid==(long long)x) return mid;
            else if((long long)mid*mid>(long long)x) high = mid - 1;
            else low = mid + 1;
        }
        return high;
    }
};