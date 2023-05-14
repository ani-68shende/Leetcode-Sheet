class Solution {
public:
    int num;
    int dp[10][(1<<15)];
    int gg(int count, int n, vector<int>& nums, int mask){
        if(mask == num){
            return 0;
        }
        if(dp[count][mask]!=-1)return dp[count][mask];
        int total = 0;
        for(int i = 0 ; i < n ; i++){
            if(mask&(1<<i)) continue;
            for(int j = 0 ; j < n ; j++){
                if(mask&(1<<j) || j==i) continue;
                int mul = count+1;
                int val = mul*(__gcd(nums[i], nums[j]));
                int temp = mask;
                temp = temp | (1<<i);
                temp = temp | (1<<j);
                // cout << i << " " << j << " " << temp << endl;
                total= max(total,val + gg(count+1, n, nums, temp));
            }
        }
        return dp[count][mask]=total;
    }
    int maxScore(vector<int>& nums) {
        int mask = 0;
        memset(dp, -1, sizeof(dp));
        int n  = nums.size();
        num = (1<<n)-1;
        return gg(0, n, nums, mask);
    }
};