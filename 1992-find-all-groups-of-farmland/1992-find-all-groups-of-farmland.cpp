class Solution {
public:
    void dfs(vector<vector<int>> &land, vector<vector<bool>> &vis, int r, int c, vector<int> &ans)
    {
        int R = land.size(), C = land[0].size();
        vis[r][c] = true;

        // conditions to return and add to ans
        if (r == R - 1 && c == C - 1)
        {
            ans.push_back(r);
            ans.push_back(c);
        }
        else if (r + 1 < R && c + 1 < C && land[r + 1][c] == 0 && land[r][c + 1] == 0)
        {
            ans.push_back(r);
            ans.push_back(c);
        }
        else if (r + 1 < R && c == C - 1 && land[r + 1][c] == 0)
        {
            ans.push_back(r);
            ans.push_back(c);
        }
        else if (r == R - 1 && c + 1 < C && land[r][c + 1] == 0)
        {
            ans.push_back(r);
            ans.push_back(c);
        }
        // traversing through all the neighbours
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int rr = r + dr[i];
            int cc = c + dc[i];

            if (rr >= 0 && rr < land.size() && cc >= 0 && cc < land[0].size() && land[rr][cc] == 1 && !vis[rr][cc])
            {
                dfs(land, vis, rr, cc, ans);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int R = land.size();
        int C = land[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> vis(R + 1, vector<bool>(C + 1, false));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (land[i][j] == 1 && !vis[i][j])
                {
                    vector<int> ans;
                    ans.push_back(i);
                    ans.push_back(j);
                    dfs(land, vis, i, j, ans);
                    res.push_back(ans);
                }
            }
        }
        return res;
    }
};