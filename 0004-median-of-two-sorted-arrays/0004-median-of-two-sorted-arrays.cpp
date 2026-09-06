class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int idx1 = n/2;
        int idx2 = n/2-1;
        int i=0;
        int j=0;
        int count = 0;
        double val1 = 0;
        double val2 = 0;
        // cout<<idx1<<" "<<idx2<<endl;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                if(count==idx1) val1 = (double)nums1[i];
                if(count==idx2) val2 = (double)nums1[i];
                i++;
            }
            else{
                if(count==idx1) val1 = (double)nums2[j];
                if(count==idx2) val2 = (double)nums2[j];
                j++;
            }
            count++;
            if(count>idx1) break;
        }
        cout<<val1<<" "<<val2;
        while(i<nums1.size() && count<=idx1){
            if(count==idx1) val1 = (double)nums1[i];
            if(count==idx2) val2 = (double)nums1[i];
            i++;
            count++;
        }
        while(j<nums2.size() && count<=idx1){
            if(count==idx1) val1 = (double)nums2[j];
            if(count==idx2) val2 = (double)nums2[j];
            j++;
            count++;
        }
        if(n%2!=0) return (double)val1;
        return (double)(val1 + val2)/2.0;
    }
};