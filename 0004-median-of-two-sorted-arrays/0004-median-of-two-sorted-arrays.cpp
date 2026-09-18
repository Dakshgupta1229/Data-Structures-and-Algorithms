class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            v.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            v.push_back(nums2[j]);
            j++;
        }
        int idx = v.size()/2;
        if(v.size()%2!=0) return (double)v[idx];
        return (double)((v[idx-1] + v[idx])/2.0);
    }
};