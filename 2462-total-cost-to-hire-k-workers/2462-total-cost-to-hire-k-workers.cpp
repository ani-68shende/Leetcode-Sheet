#define ll long long
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        ll i = 0, n = costs.size(), ans = 0;
        ll j = n - 1;
        ll times = candidates;
        ll maxu = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        if ((n + 1) / 2 <= candidates)
        {
            for (auto x : costs)
            {
                ll z = x;
                pq.push({z, 1});
            }
            while (k)
            {
                auto x = pq.top().first;
                pq.pop();
                ans += x;
                k--;
            }
        }
        else
        {
            while (times--)
            {
                pq.push({costs[i], -2});
                i++;
            }
            times = candidates;
            while (times--)
            {
                pq.push({costs[j], -1});
                j--;
            }
            while (i < n && j >= 0 && i <= j && k > 0 && pq.size() > 0)
            {
                ll top = pq.top().first;
                ll type = pq.top().second;
                ans += top;
                pq.pop();
                if (type == -2)
                {
                    pq.push({costs[i], -2});
                    i++;
                }
                else
                {
                    pq.push({costs[j], -1});
                    j--;
                }
                k--;
            }
            while (pq.size() > 0 && k > 0)
            {
                ll top = pq.top().first;
                ll type = pq.top().second;
                ans += top;
                pq.pop();
                k--;
            }
        }
        return ans;
    }
};