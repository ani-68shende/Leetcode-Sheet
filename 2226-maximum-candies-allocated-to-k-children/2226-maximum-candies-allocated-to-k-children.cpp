#define ll long long
class Solution {
public:
    bool helper(vector<int>& candies, long long k, ll candy_size){
        ll total = 0;
        for(auto x: candies){
            total += x/candy_size;
        }
        return total >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        ll low = 1;
        ll high = 1e9+1;
        ll ans = 0;
        while(low <= high){
            ll mid = low + (high - low)/2;
            if(helper(candies,k, mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};