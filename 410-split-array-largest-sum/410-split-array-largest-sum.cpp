class Solution {
public:
    bool isPossible(int groupsiz, vector<int>& nums, int m){
        int sum = 0;
        int count_groups = 1;
        for(auto x : nums){
            if(sum + x <= groupsiz){
                sum += x;
            }else if(sum + x > groupsiz){
                count_groups++;
                if(x > groupsiz || count_groups > m)return false;
                sum = x;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int l = 0;
        int r = 0;
        int ans_res = 0;
        for(auto x : nums)r+=x;
        while(l <= r){
            int mid = l + ((r-l)>>2);
            if(isPossible(mid, nums ,m)){
                ans_res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans_res;
    }
};