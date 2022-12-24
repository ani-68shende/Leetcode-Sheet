#define ll long long
class Solution {
public:
    bool helper(vector<int>& position, int m, ll min_dis){
        ll conut = 1;
        // cout << "\n\n---" << min_dis <<  "----\n\n" ;
        ll prev = position[0];
        for(int i = 1; i < position.size() ; i++){
            if(position[i]-prev >= min_dis){
                // cout << i << " " << conut << endl;
                prev = position[i];
                conut++;
            }
        }
        return conut >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        ll low = 0;
        ll high = 1e9+10;
        ll ans = -1;
        sort(position.begin(), position.end());
        while(low <= high){
            ll mid = low + (high - low)/2;
            if(helper(position, m, mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};