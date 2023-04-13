#define ll long long
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<ll>v;
        int n = nums1.size();
        vector<pair<ll, ll>>b;
        for(int i = 0 ; i < n ; i++){
            b.push_back({nums1[i]*1LL, nums2[i]*1LL});
        }
        sort(b.begin(),b.end());
        ll sum = 0;
        for(int i = 0 ; i < n ; i++){
            v.push_back((ll)abs(b[i].first-b[i].second));
            sum += abs((ll)b[i].first-(ll)b[i].second);
        }
        sort(nums1.begin(),nums1.end());
        ll maxu = LLONG_MAX;
        for(int i = 0 ; i < n ; i++){
            ll temp = sum;
            temp = temp - v[i];
            auto it1 = lower_bound(nums1.begin(), nums1.end(), b[i].second);
            if(it1 == nums1.end()){
                it1--;
            }
            auto it2 = lower_bound(nums1.rbegin(), nums1.rend(), b[i].second, std::greater<int>());
            if(it2 == nums1.rend()){
                it2--;
            }
            maxu = min(min(abs(*it1-b[i].second),abs(*it2-b[i].second))+temp, maxu);
        }
        return maxu%1000000007;
    }
};