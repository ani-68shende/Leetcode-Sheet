class Solution {
public:
    long long mod = 1e9+7;
    // lin op
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>>v;
        for(int i =0 ; i <n ; i++){
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        long long sum = 0;
        long long mini = LLONG_MAX;
        long long max_per = 0;
        priority_queue<int, vector<int>, greater<int>>pq;    
        for(int i = 0 ; i < n ; i++){
            sum+=v[i].second;
            pq.push(v[i].second);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }max_per = max((sum*v[i].first*1LL),max_per);
        }
        return max_per%mod;
    }
};