class Solution {
public:
    // just check whether We(Packman\U0001f608\U0001f608\U0001f608) can reach the goal before the hero reaches so that we can kill him\U0001f601\U0001f601\U0001f601
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int distance_of_me = abs(target[0])+abs(target[1]);
        for(auto x : ghosts){
            if(abs(target[0] -x[0])+abs(target[1] -x[1]) <= distance_of_me)return false; 
        }
        return true;
    }
};