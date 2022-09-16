class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xo = 0;
        for(auto x: nums)xo ^= x;
        return (xo == 0 || nums.size()%2==0) ? 1 : 0;
    }
};