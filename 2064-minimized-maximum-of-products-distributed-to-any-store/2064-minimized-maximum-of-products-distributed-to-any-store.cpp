#define ll long long int
class Solution {
public:
    ll helper(vector<int>& quantities, int divisor){
        ll sum = 0;
        for(auto x : quantities){
            sum += ceil((1.0*x) / divisor);
        }
        return sum;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1, hi = 0;
        for(auto x : quantities){
            hi = max(x,hi);
        }
        int nas = 0;
        while(lo <= hi){
            int mid = lo+(hi-lo)/2;
            ll products = helper(quantities, mid);
            if(products <= n){
                nas = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};