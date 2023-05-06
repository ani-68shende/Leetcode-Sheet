#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int mod = (int)1e9 + 7;

class Solution
{
public:
    ll mod_mul(ll a, ll b)
    {
        ll res = 0;
        a %= mod;
        while (b)
        {
            if (b & 1)
                res = (res + a) % mod;
            a = (2 * a) % mod;
            b >>= 1;
        }
        return res;
    }
    ll mod_add(ll a, ll b)
    {
        return (a % mod + b % mod) % mod;
    }
    ll mod_sub(ll a, ll b)
    {
        return (a % mod - b % mod + mod) % mod;
    }
    ll mod_pow(ll a, ll b)
    {
        ll res = 1;
        while (b)
        {
            if (b & 1)
                res = mod_mul(res, a);
            a = mod_mul(a, a);
            b >>= 1;
        }
        return res;
    }
    ll divide(ll a, ll b)
    {
        return mod_mul(a, mod_pow(b, mod - 2));
    }

    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while (i <= j)
        {
            if (nums[i] + nums[j] > target)
            {
                j--;
            }
            else
            {
                ans = mod_add(ans, mod_pow(2, j - i));
                i++;
            }
        }
        return ans;
    }
};