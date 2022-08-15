class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp){
        if(i >= nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int mini = 1e8;
        for(int k = 1 ; k <= nums[i] ; k++){
            mini = min(mini,1 + f(i+k, nums, dp));
        }
        return dp[i] = mini;
    }
    int jump(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)return 0;
        int maxReach = arr[0];
        int i = 0;
        int steps = 1;
        int index_of_maxReach = 0;
        while(maxReach < n-1){
            steps++;
            for(int j= i+1 ; j <= arr[i]+i ; j++){
                if(maxReach < arr[j] + j){
                    maxReach = arr[j]+j;
                    index_of_maxReach = j;
                }
            }
            i = index_of_maxReach;
        }
        return steps;  
    }
};