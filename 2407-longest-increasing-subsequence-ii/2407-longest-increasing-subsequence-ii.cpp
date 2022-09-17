#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class Solution
{
public:

    void update(ll ind, ll low, ll high, ll i, ll val, vector<ll> &seg)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        ll mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val, seg);
        else
            update(2 * ind + 2, mid + 1, high, i, val, seg);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    // low high changes
    ll query(ll ind, ll low, ll high, ll l, ll r, vector<ll> &seg)
    {
        // no overlap [l r] low high OR low high [l r]
        if (high < l || r < low)
        {
            return LLONG_MIN;
        }
        // full overlap [l low high r]
        if (l <= low && high <= r)
        {
            return seg[ind];
        }
        ll mid = low + (high - low) / 2;
        ll left = query(ind * 2 + 1, low, mid, l, r, seg);
        ll right = query(ind * 2 + 2, mid + 1, high, l, r, seg);
        return max(right, left);
    }

    void build(ll ind, ll low, ll high, vector<ll> &arr, vector<ll> &seg)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        ll mid = low + (high - low) / 2;
        build(ind * 2 + 1, low, mid, arr, seg);
        build(ind * 2 + 2, mid + 1, high, arr, seg);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    int lengthOfLIS(vector<int> &dd, int k)
    {
        vector<ll>arr(100001, 0);
        int n = 100001;
        vector<ll> seg(4 * n);
        int maxu = 0;
        build(0, 0, n - 1, arr, seg);
        for(int i = dd.size() - 1 ; i >=0 ; i--){
            int s = dd[i]+1;
            int e = dd[i]+k;
            e = min(e,100001);
            int fetch = query(0,0,n-1,s,e,seg);
            maxu = max(maxu, fetch+1);
            update(0,0,n-1,dd[i] ,1+fetch, seg);
        }
        // for(auto x : seg)cout << x << " ";
        // cout << endl;
        return maxu;
    }
};