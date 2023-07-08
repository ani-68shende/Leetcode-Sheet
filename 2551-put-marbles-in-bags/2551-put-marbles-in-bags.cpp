#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int mod = (int)1e9 + 7;
class Solution
{
public:
    long long putMarbles(vector<int> &weights, int kk)
    {
        vector<lli> poais, jvhb;
        lli knl = 0, jbh = 0, jj = kk - 1, ff;
        if (kk == 1 || kk == weights.size())
            return 0;
        kk = jj;
        for (lli i = 0; i < weights.size() - 1; i++)
        {
            poais.push_back(weights[i] + weights[i + 1]);
        }
        sort(poais.begin(), poais.end(), greater<lli>());
        for (lli i = 0; i < kk; i++)jbh += poais[i];
        for (lli i = 0; i < weights.size() - 1; i++)
        {
            jvhb.push_back(weights[i] + weights[i + 1]);
        }
        sort(jvhb.begin(), jvhb.end());
        for (lli i = 0; i < kk; i++)knl += jvhb[i];
        ff = jbh - knl;
        return ff;
    }
};