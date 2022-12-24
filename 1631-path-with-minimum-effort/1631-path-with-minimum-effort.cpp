#define ll long long int
class Solution {
public:
    vector<int>dir{1,0,-1,0,1};
    bool swimInWater(vector<vector<int>>& grid, ll maxu) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, pair<int, int>>>>pq;
        set<pair<int, int>>vis;
        pq.push({0, {grid[0][0],{0,0}}});
        vis.insert({0,0});
        while(!pq.empty()){
            auto top = pq.front();
            pq.pop();
            int cost = top.first;
            // cout << cost << " ";
            int prev = top.second.first;
            int x = top.second.second.first;
            int y = top.second.second.second;
            if(x == n-1 && y == m-1 && cost <= maxu){
                return true;
            }
            for(int i = 0 ; i < 4 ; i++){
                int x1 = dir[i]+x;
                int y1 = dir[i+1]+y;
                if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= m || vis.count({x1,y1})){
                    continue;
                }
                if(abs(grid[x1][y1]-prev) > maxu){
                    continue;
                }
                pq.push({abs(grid[x1][y1]-prev), {grid[x1][y1],{x1,y1}}});
                vis.insert({x1,y1});
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& grid) {
        ll low = 0;
        ll high = 0;
        for(auto x : grid){
            for(auto y : x){
                high = max(1LL*y, high);
            }
        }
        // cout << high << endl;
        ll ans = -1;
        // cout << swimInWater(grid, 2) << endl;
        // cout << " \n\n------\n\n";
        while(low <= high){
            ll mid = low + (high-low)/2;
            if(swimInWater(grid, mid)){
                ans = mid;
                // cout << ans << " ";
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};