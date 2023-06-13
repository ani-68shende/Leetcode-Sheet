#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int count = 0;
        for (auto i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j < n; j++)
            {
                v.push_back(grid[i][j]);
            }
            for (int m = 0; m < n; m++)
            {
                int l = 0;
                for (int k = 0; k < n; k++)
                {
                    if (grid[k][m] != v[k])
                    {
                        l = 1;
                        break;
                    }
                }
                if (!l)
                    count++;
            }
        }
        return count;
    }
};