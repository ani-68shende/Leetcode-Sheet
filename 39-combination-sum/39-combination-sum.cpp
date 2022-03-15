class Solution {
public:
    void helper(int idx, vector<int>& candidates, int target, vector<int>& z, vector<vector<int>>&ans){
        if(idx == candidates.size()){
            if(target == 0)
            ans.push_back(z);
            return ;
        }
        if(candidates[idx] <= target){
            z.push_back(candidates[idx]);
            helper(idx, candidates, target-candidates[idx], z, ans);                               z.pop_back();
        }
        helper(idx+1, candidates, target, z, ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>z;
        helper(0, candidates, target, z, ans);
        return ans;
    }
};