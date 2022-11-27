#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        int gsize = guards.size();
        int wsize = walls.size();
        vector<vector<int>> grid(m, vector<int>(n, 0));
        set<pair<int, int>> guard, wall;
        for (int i = 0; i < gsize; i++)
        {
            guard.insert({guards[i][0], guards[i][1]});
        }
        for (int i = 0; i < wsize; i++)
        {
            wall.insert({walls[i][0], walls[i][1]});
        }
        for (int i = 0; i < gsize; i++)
        {
            int l = guards[i][1] - 1;
            int r = guards[i][1] + 1;
            int u = guards[i][0] - 1;
            int d = guards[i][0] + 1;
            int x = guards[i][0];
            int y = guards[i][1];
            while (l >= 0 && guard.count({x, l}) == 0 && wall.count({x, l}) == 0)
            {
                grid[x][l] = 1;
                l--;
            }
            while (r < n && guard.count({x, r}) == 0 && wall.count({x, r}) == 0)
            {
                grid[x][r] = 1;
                r++;
            }
            while (u >= 0 && guard.count({u, y}) == 0 && wall.count({u, y}) == 0)
            {
                grid[u][y] = 1;
                u--;
            }
            while (d < m && guard.count({d, y}) == 0 && wall.count({d, y}) == 0)
            {
                grid[d][y] = 1;
                d++;
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    res++;
                }
            }
        }
        return m * n - res - gsize - wsize;
    }
};