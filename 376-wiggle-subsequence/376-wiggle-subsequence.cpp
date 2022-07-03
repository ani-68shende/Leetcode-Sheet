class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 1;
        if(n == 2){
            if(nums[0] ==nums[1])return 1;
            else return 2;
        }
        int prev = nums[1]-nums[0];
        int curr = 1;
        if(prev!=0)curr++;
        int diff;
        for(int i = 2 ; i < n ; i++){
            diff = nums[i] - nums[i-1];
            if(diff > 0 && prev <= 0){
                curr++;
                prev = diff;
            }
            if(diff < 0 && prev >= 0){
                curr++;
                prev = diff;
            }
        }
        return curr;
    }
};