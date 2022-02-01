class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // new stl method to generate next permutation
        next_permutation(nums.begin(), nums.end());
    }
};