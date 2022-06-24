class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        //here the value of k is 1;
        int k = 1;
        
        int count = 0;
        int res = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(j < n){
            if(nums[j] == 0)count++;
            while(count > k){
                if(nums[i] == 0)count--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res-1;
    }
};