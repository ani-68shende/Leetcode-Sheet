class Solution {
public:
    // learn it ... no other option
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(i > reachable)return false;
            reachable = max(reachable, nums[i]+i);
        }
        return true;
    }
};