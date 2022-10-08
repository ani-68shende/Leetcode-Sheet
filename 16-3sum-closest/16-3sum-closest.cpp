class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int start = i+1;
            int end = n-1;
            while(start < end){
                int sum = nums[i]+nums[start]+nums[end];
                if( sum == target ){
                    return sum;
                }else if( abs(sum - target) < diff){
                    diff = abs(sum - target);
                    ans = sum;
                }
                if( sum > target )end--;
                else start++;
            }
        }
        return ans;
    }
};