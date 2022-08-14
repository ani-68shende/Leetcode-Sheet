#define ll long long int
class Solution {
public:
    int leastBricks(vector<vector<int>>& walls) {
        ll counto_maxu = 0;
        unordered_map<ll, ll>mp;
        int n = walls.size();
        ll suma =0 ;
        for(auto x : walls[0])suma+=x;
        for(ll i(0) ; i < walls.size() ;i++){
            ll sum = 0;
            for(ll j(0) ; j < walls[i].size() ; j++){
                sum += walls[i][j];
                mp[sum]++;
            }
        }
        ll maxu = 0;
        for(auto x : mp){
            // cout << x.first << " " << x.second << endl;
            if(x.first!=suma)
            maxu = max(maxu, x.second);
        }   
        // cout << maxu << "\n";
        return n-maxu;
    }
};