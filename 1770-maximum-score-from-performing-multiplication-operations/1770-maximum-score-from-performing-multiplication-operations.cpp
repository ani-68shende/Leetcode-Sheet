class Solution {
public:
    vector<vector<int>> kgf;
    int f(int l, int i, vector<int>&nums, vector<int>& multipliers){
        if(i == multipliers.size())return 0;
        if(kgf[l][i]!=INT_MAX)return kgf[l][i];
            
        int r = nums.size()-1-(i-l);
        int left =  nums[l] * multipliers[i] + f(l+1, i+1, nums, multipliers);
        int right = nums[r] * multipliers[i] + f(l, i+1, nums, multipliers);
        // no need of r =>due to move
        return kgf[l][i] = max(left, right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        kgf.resize(1001, vector<int>(1001, INT_MAX));
        return f(0, 0, nums, multipliers);
    }
};