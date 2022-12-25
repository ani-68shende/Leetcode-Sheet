#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        sort(nums.begin(), nums.end());
        vector<int> kk;
        for (int i = 0; i < queries.size(); i++)
        {
            int sum = 0;
            int temp = 0;
            int j = 0;
            for (; j < nums.size(); j++)
            {
                if (sum + nums[j] <= queries[i])
                {
                    sum += nums[j];
                }
                else
                {
                    break;
                }
            }
            kk.push_back(j);
        }
        return kk;
    }
};