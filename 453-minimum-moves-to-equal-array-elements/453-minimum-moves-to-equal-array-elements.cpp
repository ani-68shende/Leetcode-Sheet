class Solution {
public:
    int minMoves(vector<int>& nums) {
        int counto = 0;
        int mini = *min_element(nums.begin(),nums.end());
        for(auto x : nums){
            counto+=x-mini;
        }
        return counto;   
    }
};