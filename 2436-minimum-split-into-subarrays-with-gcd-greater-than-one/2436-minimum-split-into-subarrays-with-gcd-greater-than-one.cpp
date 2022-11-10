class Solution {
public:
    int n;
    int minimumSplits(vector<int>& nums) {
        n = nums.size();
        int gc = nums[0];
        int counto = 1;
        for(int i = 0 ; i < n ; i++){
            if(__gcd(gc, nums[i]) > 1){
                gc = __gcd(gc, nums[i]);
            }else{
                gc = nums[i];
                counto++;
            }
        }
        return counto;                           
    }
};