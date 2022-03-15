class Solution {
public:
    void helper(int idx, vector<int>&c, int t, vector<int>&z, vector<vector<int>>& ans, int k){
        if(t == 0 && z.size() == k){
            ans.push_back(z);
            return ;
        }
        for(int i = idx; i < c.size() ; i++){
            if(i > idx && c[i] == c[i-1])continue;
            if(c[i] > t)break;
            z.push_back(c[i]);
            helper(i + 1, c, t-c[i], z, ans, k);
            z.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int t) {
        vector<int>c;
        for(int i = 1 ; i <= 9 ; i++){
            c.push_back(i);
        }
        vector<vector<int>>ans;
        vector<int>z;
        sort(c.begin(), c.end());
        helper(0,c,t,z,ans,k);
        return ans;
    }
};