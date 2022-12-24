#define ll long long
class Solution {
public:
    bool helper(vector<int>& nums, int maxOperations, ll k){
        ll total = 0;
        for(ll i = 0 ; i < nums.size() ; i++){
            ll balls = nums[i];
            total += (balls%k == 0) ? ((balls/k)-1) : (balls/k);
        }
        return maxOperations >= total;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        ll low = 1;
        ll high = 1e9+1;
        ll ans = -1;
        while(low <= high){
            ll mid = low + (high - low)/2;
            if(helper(nums, maxOperations, mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};