class Solution {
public:
    int hlper(vector<int>piles, int speed){
        int hours = 0;
        for(auto i : piles){
            hours += ceil(1.0*i/speed); 
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 0;
        for(auto x: piles){
            hi = max(hi, x);
        }
        int ans = 0;
        while(lo <= hi){
            int mid = (lo) + (hi-lo)/2;
            int hours = hlper(piles, mid);
            if(hours <= h){
                ans = mid;
                hi = mid-1;
            }else lo = mid+1;
        }
        return ans;
    }
};