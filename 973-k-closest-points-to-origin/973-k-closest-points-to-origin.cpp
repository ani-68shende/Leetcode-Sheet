class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int, int>>>pq;
        for(auto u : points){
            int x = u[0];
            int y = u[1];
            double distance = sqrt(x*x+y*y);
            pq.push({distance, {x, y}});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(pq.size()){
            auto p = pq.top();
            pq.pop();
            vector<int>v;
            v.push_back(p.second.first);
            v.push_back(p.second.second);
            ans.push_back(v);
        }
        return ans;
    }
};