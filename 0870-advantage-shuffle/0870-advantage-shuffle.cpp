class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        multiset<long long>mp(nums1.begin(), nums1.end());
        vector<int>ans;
        for(int i(0) ; i < n ; i++){
            auto itr = mp.upper_bound(nums2[i]);
            if(itr == mp.end()){
                ans.push_back(*mp.begin());
                mp.erase(mp.lower_bound(*mp.begin()));
            }else{
                ans.push_back(*itr);
                mp.erase(mp.lower_bound(*itr));
            }
        }
        return ans;
    }
};