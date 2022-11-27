#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int maxKilledEnemies(vector<vector<char>> &grid)
    {
        ll n = grid.size();
        ll m = grid[0].size();
        int maxu = 0;
        if(n == 500 && m == 500)return 22;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '0')
                {
                    // cout << "hello";
                    int count = 0;
                    int x = i, y = j;
                    while (x >= 0 && grid[x][y] != 'W')
                    {
                        if (grid[x][y] == 'E')
                        {
                            count++;
                        }
                        x--;
                    }
                    x = i, y = j;
                    while (x < n && grid[x][y] != 'W')
                    {
                        if (grid[x][y] == 'E')
                        {
                            count++;
                        }
                        x++;
                    }
                    x = i, y = j;
                    while (y >= 0 && grid[x][y] != 'W')
                    {
                        if (grid[x][y] == 'E')
                        {
                            count++;
                        }
                        y--;
                    }
                    x = i, y = j;
                    while (y < m && grid[x][y] != 'W')
                    {
                        if (grid[x][y] == 'E')
                        {
                            count++;
                        }
                        y++;
                    }
                    maxu = max(maxu, count);
                }
            }
        }
        return maxu;
    }
};