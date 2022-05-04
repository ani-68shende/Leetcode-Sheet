class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(k - nums[i]) != mp.end() && mp[k - nums[i]]!=0)
            {
                ans += 1;
                mp[k - nums[i]]--;
            }
            else
            {
                mp[nums[i]]++;
            }
        }
        return ans;
    }
};