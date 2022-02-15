class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int>s;
        vector<int>v;
        for(int i = 0 ; i < points.size() ; i++){
            s.insert(points[i][0]);
        }
        for(auto x:  s){
            v.push_back(x);
        }
        int maxu = 0;
        sort(v.begin(), v.end());
        for(int i = 1 ;i < v.size() ; i++){
            maxu = max(maxu, v[i]-v[i-1]);
        }
        return maxu;
    }
};