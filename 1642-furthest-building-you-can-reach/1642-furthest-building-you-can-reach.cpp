#define ll long long int
ll mod = (ll)1000000007;
 
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        ll n = heights.size();
        priority_queue<ll> pq;
        ll farthestIndx = 0;
        for(ll i = 1 ; i < n ; i++){
            ll diff = heights[i-1]-heights[i];
            // cout << diff << " " << bricks << " " << ladders << endl;
            if(diff >= 0){
                farthestIndx = i;
                continue;
            }else{
                diff*=-1;
                bricks -= diff;
                pq.push(diff);
                if(bricks<0){
                    if(ladders){
                        bricks += pq.top();
                        pq.pop();
                        ladders--;
                    }else{
                        break;
                    }
                }
                farthestIndx = i;
            }
        }
        // cout << "\n";
        return farthestIndx;
    }
};