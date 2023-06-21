#define ll long long int
class Solution
{
public:
    long long int f(vector<int> &nums, vector<int> &cost, ll num)
    {
        ll sum = 0;
        for (ll i = 0; i < nums.size(); i++)
        {
            sum += abs(num - nums[i]) * cost[i];
        }return sum;
    }
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        ll n = nums.size();
        ll lo = *min_element(nums.begin(), nums.end());
        ll hi = *max_element(nums.begin(), nums.end());

        ll ans = LLONG_MAX;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            ll d = f(nums, cost, mid);
            if (d < ans)
            {
                ans = d;
            }
            ll d1 = f(nums, cost, mid - 1);
            ll d2 = f(nums, cost, mid + 1);
            if (d1 < d2)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};