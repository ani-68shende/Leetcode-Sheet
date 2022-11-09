class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0 ;
        int j = 0;
        int n = nums.size();
        int sum =0 ;
        int count = 1000000;
        sum = target;
        while(j < n){
            sum -= nums[j];
            while(sum <= 0){
                count = min(count, j-i+1);
                sum += nums[i];
                i++;
            }
            j++;
        }
        return count ==1000000 ? 0 : count;
    }
};