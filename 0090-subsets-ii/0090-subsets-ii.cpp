class Solution {
public:
    void helper(int idx, vector<int>&v, vector<vector<int>>&b,int n,  vector<int>&ans){
        b.push_back(ans);
        for(int i = idx;  i < v.size()  ; i++){
            if(i != idx && v[i] == v[i-1])continue;
            ans.push_back(v[i]);
            helper(i+1, v, b, n, ans);
            ans.pop_back();
        }
    }
vector<vector<int>> subsetsWithDup(vector<int>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>>b;
        vector<int>ans;
        helper(0,v,b,v.size(),ans);
        return b;
    }
};