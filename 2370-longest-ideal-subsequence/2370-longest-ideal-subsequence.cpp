#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    int K;
    int f(char prev, int i, vector<vector<int>> &dp, string& s)
    {
        if (i == s.size())
        {
            return 0;
        }
        if (dp[i][prev] != -1)return dp[i][prev];
        int nottake = 0;
        int take = 0;
        if (prev == '$' ||  abs(s[i] - prev) <= K)
        {
            take = 1 + f(s[i], i + 1, dp, s);
        }
        nottake = f(prev, i + 1, dp, s);
        return dp[i][prev] = max(nottake, take);
    }
    int longestIdealString(string s, int k)
    {
        K = k;
        int i = 0;
        int n = s.size();
        int count = 0;
        int maxu = 0;
        vector<vector<int>>dp(n, vector<int>(200, -1));
        return f('$', i, dp, s);
    }
};