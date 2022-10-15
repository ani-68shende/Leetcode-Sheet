class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // reverse(nums1.begin(), nums1.end());
        reverse(nums2.begin(), nums2.end());
        int maxu = 0;
        int n = nums1.size(), n2 = nums2.size();
        for(int i = 0 ; i < n ; i++){
            auto idx = lower_bound(nums2.begin(), nums2.end(), nums1[i]);
            int id = idx-nums2.begin();
            if(idx == nums2.end()){
                continue;
            }
            // cout << i << " " <<  (nums2.size()-1)-id << endl;
            maxu = max(maxu, (n2-1)-id-i);
        }
        cout << "---"<< "\n";
        return maxu;
    }
};