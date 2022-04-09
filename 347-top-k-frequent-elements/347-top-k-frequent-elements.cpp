class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int,int>mp;
        for(int i  = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        for(auto c : mp){
            pq.push({c.second,c.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>y;
        while(pq.size()!=0) {
            auto x = pq.top();pq.pop();
            y.push_back(x.second);
        }
        return y;
    }
};