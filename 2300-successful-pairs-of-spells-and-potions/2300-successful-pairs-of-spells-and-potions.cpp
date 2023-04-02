#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll countGreater(vector<int> &arr, ll n, ll k, long long success)
{
    ll l = 0;
    ll r = n - 1;
    ll leftGreater = n;
    while (l <= r)
    {
        ll m = l + (r - l) / 2;
        if (arr[m] * 1LL * k >= success)
        {
            leftGreater = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return (n - leftGreater);
}

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> res;
        ll n = spells.size();
        ll m = potions.size();
        sort(potions.begin(), potions.end());
        ll j = 0;
        for (ll i = 0; i < n; i++)
        {
            ll counto = countGreater(potions, m, spells[i], success);
            res.push_back(counto);
        }
        return res;
    }
};