#define ll long long
#define all(v) v.begin(), v.end()
class Solution {
public:
    // no_of_bits(n1)+no_of_bits(n2) = no_of_bits(n1|n2)+no_of_bits(n1&n2)
    // 99% problem solved here itself
    long long countExcellentPairs(vector<int>& nums, int k) {
        ll count = 0;
        vector<int>temp_bs;
        int n = nums.size();
        set<int>s;
        for(auto x : nums)s.insert(x);
        for(auto x : s){
          temp_bs.push_back(__builtin_popcount(x));
        }
        sort(all(temp_bs));
        for(int i = 0 ; i < temp_bs.size() ; i++){
            int low = i+1;
            int right = temp_bs.size()-1;
            int idx = lower_bound(all(temp_bs),k-temp_bs[i])-temp_bs.begin();
            count += temp_bs.size()-idx;
        }
        return count;
    }
};