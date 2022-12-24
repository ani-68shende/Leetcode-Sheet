#define ll long long
class Solution {
public:
    bool helper(vector<int>& dist, double hour, ll speed){
        double total_time = 0;
        for(int i = 0 ; i < dist.size()-1 ; i++){
            total_time += ceil((dist[i]*1.00)/speed);
        }
        total_time += (dist[dist.size()-1]*1.00)/speed;
        return hour >= total_time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        ll low = 1;
        ll high = 1e9+7;
        ll ans = -1;
        while(low <= high){
            ll mid = low + (high - low)/2;
            if(helper(dist, hour, mid)){
                ans = mid;
                // cout << ans << " ";
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};