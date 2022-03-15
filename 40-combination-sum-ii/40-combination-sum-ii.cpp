class Solution {
public:
    void helper(int idx, vector<int>&c, int t, vector<int>&z, vector<vector<int>>& ans){
        if(t == 0){
            ans.push_back(z);
            return ;
        }
        for(int i = idx; i < c.size() ; i++){
            if(i > idx && c[i] == c[i-1])continue;
            if(c[i] > t)break;
            z.push_back(c[i]);
            helper(i + 1, c, t-c[i], z, ans);
            z.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>>ans;
        vector<int>z;
        sort(c.begin(), c.end());
        helper(0,c,t,z,ans);
        return ans;
    }
};