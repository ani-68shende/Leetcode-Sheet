class Solution {
public:
    void helper(int idx, vector<int>v, vector<vector<int>>&b,int n,  vector<int>&ans){
        if(idx == n){
            b.push_back(ans);
            return ;
        }
        ans.push_back(v[idx]);
        helper(idx+1, v, b, n, ans);
        ans.pop_back();
        helper(idx+1, v, b, n, ans);
    }
    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>>b;
        vector<int>ans;
        helper(0,v,b,v.size(),ans);
        vector<vector<int>>r;
        for(auto x : b){
            r.push_back(x);
        }
        return b;
    }
};