class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> m1, m2;
        for (auto x : nums1)
        {
            m1[x]++;
        }
        for (auto x : nums2)
        {
            m2[x]++;
        }
        vector<vector<int>> sa;
        vector<int> v1, v2;
        for (auto x : m1)
        {
            if (m2.find(x.first) == m2.end())
            {
                v1.push_back(x.first);
            }
        }
        for (auto x : m2)
        {
            if (m1.find(x.first) == m1.end())
            {
                v2.push_back(x.first);
            }
        }
        sa.push_back(v1);
        sa.push_back(v2);
        return sa;
    }
};