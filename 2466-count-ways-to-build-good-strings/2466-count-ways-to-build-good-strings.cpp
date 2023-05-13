#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    ll ans = 0;
    int mod = (int)1e9 + 7;
    int z, o, low, high;
    vector<int> dp;
    int f()
    {
        dp[0] = 1;
        for (int i = 1; i <= high; i++)
        {
            if (i - o >= 0)
                dp[i] = (dp[i] + dp[i - o]) % mod;
            if (i - z >= 0)
                dp[i] = (dp[i] + dp[i - z]) % mod;
        }
        return dp[high];
    }
    int countGoodStrings(int l, int h, int zero, int one)
    {
        low = l, high = h, o = one, z = zero;
        dp.resize(high + 1);
        int temp = 0;
        // cout << "---\n";
        f();
        ll sum = 0;
        for (int i = low; i <= high; i++)
        {
            sum = (sum + dp[i]) % mod;
        }
        return sum;
    }
};