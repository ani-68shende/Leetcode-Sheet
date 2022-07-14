class Solution {
public:
    long mod = (int)1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x : nums){
            pq.push(x);
        }
        while(k--){
            int t = pq.top();
            pq.pop();
            t+=1;
            pq.push(t);
        }
        long long ans = 1;
        while(pq.size()){
            int t = pq.top();
            pq.pop();
            ans = (ans*t)%mod;
        }
        return ans;
    }
};