class Solution {
public:
    // dont know does map doesnt work.. thats why needed to copy votrubac 
    int longestAwesome(string s) {
        vector<int> dp(1024, s.size());
        int res = 0, mask = 0;
        dp[0] = -1;
        for (auto i = 0; i < s.size(); ++i) {
            mask ^= 1 << (s[i] - '0');
            dp[mask] = min(dp[mask], i);
            res = max(res, i - dp[mask]);
            for (auto j = 0; j <= 9; ++j)
                res = max(res, i - dp[mask ^ (1 << j)]);
        }
        return res;
    }
};