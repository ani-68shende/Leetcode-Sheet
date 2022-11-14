class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), ans = 0, i, p, j;
        vector <bool> vis(n, false);
        queue <int> q;
        for (i=0;i<n;i++) {
            if (!vis[i]) {
                vis[i] = true;
                ans++;
                q.push(i);
                while (!q.empty()) {
                    p = q.front();
                    q.pop();
                    for (j=0;j<n;j++) {
                        if (!vis[j] && (stones[p][0] == stones[j][0] || stones[p][1] == stones[j][1])) {
                            q.push(j);
                            vis[j] = true;
                        }
                    }
                }
            }
        }
        return n - ans;
    }
};