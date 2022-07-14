class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int ie = 0;
        for(auto x : nums)
            if(x%2==0)ie+=x;
        for(auto x : queries){
            int val = x[0];
            int idx = x[1];
            if(nums[idx]%2==0){
                int new_val = nums[idx] + val;
                ie -= nums[idx];
                nums[idx] = new_val;
                if(new_val%2==0){
                    ie+=new_val;
                }
            }else{
                int new_val = nums[idx] + val;
                nums[idx] = new_val;
                if(new_val%2==0){
                    ie+=new_val;
                }
            }
            ans.push_back(ie);
        }
        return ans;
    }
};