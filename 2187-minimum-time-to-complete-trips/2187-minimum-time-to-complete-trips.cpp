class Solution {
public:

    bool check(vector<int> &time,long long t,int totalTrips){
        long long count = 0;
        for(int i=0;i<time.size();i++){
            // if(time[i]%t==0) count = count + (long long)time[i]/t;
            // else{
            //     if(t>=time[i]) count = count + t/time[i];
            //     else count = count + time[i]/t + 1;
            // }
            if((long long)time[i]<=(long long)t) count = count + (long long)t/time[i];
        }
        if(count>=totalTrips) return true;
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long sum = 0;
        for(int i=0;i<time.size();i++){
            sum = sum + (long long)time[i];
        }
        long long low = 1;
        long long high = sum * totalTrips;
        long long ans = -1;
        while(low<=high){
            long long mid = low + (high - low)/2;
            if(check(time,mid,totalTrips)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};