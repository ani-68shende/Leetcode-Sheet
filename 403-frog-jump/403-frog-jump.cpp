class Solution {
public:
    
    // discuss as usual op
    
    bool helper(int i, vector<int> & stones, int jump, vector<vector<int>> & dp){
        if(i >= stones.size())return false;
        if(i == stones.size()-1)return true;
        if(dp[i][jump]!=-1)return dp[i][jump];
        bool bol_bhai_jaa_sakta_kya = false;
        for(int j = -1 ; j <= 1 ; j++){
            int length_of_jump = jump + j;
            if(length_of_jump > 0){
                int idx = lower_bound(stones.begin(), stones.end(), stones[i] + length_of_jump) - stones.begin();
                if(idx == stones.size())continue;
                // aage aur piche kud ke kya fayda agar wo stone na ho toh...
                // means stone hi hona chahiye
                if(stones[idx]!=stones[i] + length_of_jump)continue;
                bol_bhai_jaa_sakta_kya =bol_bhai_jaa_sakta_kya || helper(idx, stones, length_of_jump, dp);
            }
        }
        return dp[i][jump] = bol_bhai_jaa_sakta_kya;
    }
    bool canCross(vector<int>& stones) {
        //dhoka mila jump 1 leke
        // int jump = 1;
        int jump = 0;
        // index || jump
        vector<vector<int>> dp(stones.size(), vector<int>(2001, -1));
        return helper(0, stones, jump, dp);
    }
};