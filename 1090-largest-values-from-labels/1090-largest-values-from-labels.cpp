class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        priority_queue<int>pq;
        map<int, vector<int>>mp;
        int n = values.size();
        for(int i = 0 ; i < n ; i++){
            mp[labels[i]].push_back(values[i]);
        }
        for(auto x : mp){
            priority_queue<int>xy;
            for(auto y : x.second){
                xy.push(y);
            }
            int si = xy.size();
            for(int i = 0 ; i < min(si,useLimit) ; i++){
                pq.push(xy.top());
                xy.pop();
            }
        }
        long long sum = 0;
        while(pq.size() && numWanted){
            sum += pq.top();
            pq.pop();
            numWanted--;
        }
        return sum;
    }
};