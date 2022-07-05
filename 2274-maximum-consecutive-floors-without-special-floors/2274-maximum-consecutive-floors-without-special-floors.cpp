#define ll long long int

class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        long long maxu = 0;
        sort(special.begin(), special.end());
        long long n = special.size();
        for (ll i = 0; i <= n; i++)
        {
            if (i == 0)
            {
                maxu = max(maxu, 1LL * (special[i] - bottom));
            }
            else if (i == n)
            {
                maxu = max(maxu, 1LL * (top - special[i - 1]));
            }
            else
            {
                maxu = max(maxu, 1LL * (special[i] - special[i - 1] - 1));
            }
        }
        return maxu;
    }
};