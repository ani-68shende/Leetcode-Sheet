#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> sjd;
        priority_queue<int, vector<int>, greater<int>> isod;
        ll vv = 0, bb = nums2.size(), ybuvf = 0;
        for (int i = 0; i < bb; i++)
        {
            sjd.push_back({nums2[i], nums1[i]});
        }
        sort(sjd.begin(), sjd.end());
        for (int i = bb - 1; i >= 0; i--)
        {
            isod.push(sjd[i].second);
            ybuvf += sjd[i].second;
            if (isod.size() == k)
            {
                vv = max(vv, 1LL * ybuvf * sjd[i].first);
                int tt = isod.top();
                isod.pop();
                ybuvf = ybuvf - tt;
            }
        }
        return vv;
    }
};