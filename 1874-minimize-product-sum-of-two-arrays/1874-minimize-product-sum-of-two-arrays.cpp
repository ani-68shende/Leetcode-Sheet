class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end(),greater<int>());
        sort(nums2.begin(), nums2.end());
        int mul1 = 0, mul2 = 0;
        for(int i = 0 ; i < nums1.size() ; i++){
            mul1 += nums1[i]*nums2[i];
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end(),greater<int>());
        for(int i = 0 ; i < nums1.size() ; i++){
            mul2 += nums1[i]*nums2[i];
        }
        return min(mul1, mul2);
    }
};