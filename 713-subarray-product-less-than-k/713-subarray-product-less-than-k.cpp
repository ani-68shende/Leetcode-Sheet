class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // if(k == 0)return 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        long long int fa = 1;
        int sum = 0;
        while(j < n){
            fa *= nums[j];
            if(fa < k)sum+=j-i+1;
            else{
                while(i<n && fa >= k){
                    fa /= nums[i];
                    i++;
                }
                sum += j-i+1;
            }
            j++;
        }
        return max(sum,0);
    }
};