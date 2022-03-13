class Solution {
public:
    int helper(vector<int>&nums, int divisor){
        int sum = 0;
        for(auto x : nums){
            sum += ceil((x*1.0)/divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1,hi = INT_MIN;
        for(auto x : nums){
            hi = max(hi, x);
        }
        int nas = 0;
        while(lo<= hi){
            int mid = lo+(hi-lo)/2;
            int suma = helper(nums,mid);
            if(suma <= threshold){
                nas = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return nas;
    }
};