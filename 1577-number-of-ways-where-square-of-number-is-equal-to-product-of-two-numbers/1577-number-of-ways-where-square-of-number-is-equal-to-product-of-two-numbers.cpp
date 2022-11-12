class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<unsigned long long int, int>mp1;for(auto x : nums1)mp1[(unsigned long long int)x*x]++;
        unordered_map<unsigned long long, int>mp2;for(auto x : nums2)mp2[(unsigned long long int)x*x]++;
        long long int counto = 0;
        for(int  i= 0 ; i < nums1.size() ; i++){
            for(int j = i+1 ; j < nums1.size() ; j++){
                if(mp2.count((unsigned long long int)nums1[i] * nums1[j]))counto+=mp2[(unsigned long long int)nums1[i] * nums1[j]];
            }
        }
        for(int  i= 0 ; i < nums2.size() ; i++){
            for(int j = i+1 ; j < nums2.size() ; j++){
                if(mp1.count((unsigned long long int)nums2[i] * nums2[j]))counto+=mp1[(unsigned long long int)nums2[i] * nums2[j]];
            }
        }
        return counto;
    }
};