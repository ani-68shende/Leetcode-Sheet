#define ll long long int
class Solution {
public:
    // lol votrubac at its best... i am thinking of dry running it once
    int minimizeArrayValue(vector<int>& nums) {
        ll ans = 0, sum =0, n = nums.size(), i=1;
        for(auto x : nums)sum+=x,ans=max(ans, (sum%i) ? 1+sum/i : sum/i), i++;
        return ans;
    }
};