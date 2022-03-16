class Solution {
public:
    //and in this is the type of backtracking where we don't have to pass the idx variable
    void helper(int idx, vector<int>& s, vector<vector<int>>&ans){
        if(idx == s.size()){
            ans.push_back(s);
            return;
        }
        for(int i = idx ; i < s.size() ; i++){
            swap(s[i],s[idx]);
            helper(idx+1, s, ans);
            swap(s[i],s[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& s) {
        vector<vector<int>>ans;
        helper(0,s,ans);
        return ans;
    }
};