class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int>mp;
        int counts = 0, n = nums1.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int sum=nums1[i]+nums2[j]; 
                mp[sum]++;
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int sum=nums3[i]+nums4[j]; 
                counts+=mp[(-sum)];
            }
        }
        return counts;
    }
};