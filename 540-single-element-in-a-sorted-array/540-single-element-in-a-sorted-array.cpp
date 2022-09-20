class Solution {
public:
    int singleNonDuplicate(vector<int>& nums, int xo = 0) {
        for(auto x : nums)xo ^= x;return xo;
    }
};