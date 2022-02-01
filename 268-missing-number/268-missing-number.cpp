class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(auto c : nums){
            sum += c;
        }
        int z = ((n*(n+1))/2)-sum;
        return z;
    }
};