class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        int if_not_gound = nums[0];
        int high = n-1;
        while(low <= high){
            if(nums[low] <= nums[high]){
                return nums[low];
            }
            int mid = low +(high-low)/2;
            int pre = (mid-1+n)%n;
            int next = (mid+1)%n;
            if(nums[mid] <= nums[pre] && nums[mid] <= nums[next])return nums[mid];
            else if(nums[low] <= nums[mid]){
                low = mid+1;
            }else if(nums[mid] <= nums[high]){
                high = mid-1;
            }
        }
        return if_not_gound;
    }
};