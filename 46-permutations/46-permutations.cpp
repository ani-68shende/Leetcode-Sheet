class Solution {
public:
    //this is the type of backtracking where we don't have to pass the idx variable
    void helper(vector<int> s, vector<int> &z, vector<vector<int>>&ans, vector<bool> &visited){
        if(z.size() == s.size()){
            ans.push_back(z);
            return;
        }
        for(int i = 0 ; i < s.size() ; i++){
            if(!visited[i]){
                visited[i] = true;
                z.push_back(s[i]);
                helper(s,z,ans, visited);
                visited[i] = false;
                z.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& s) {
        vector<vector<int>>ans;
        vector<int> z;
        vector<bool>visited(s.size(), false);
        helper(s,z,ans,visited);
        return ans;
    }
};