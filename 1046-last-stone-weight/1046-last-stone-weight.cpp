class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>pq;
        for(int i = 0 ; i < n ; i++)pq.push(stones[i]);
        while(pq.size()!=1){
            int t1 = pq.top();pq.pop();
            int t2 = pq.top();pq.pop();
            pq.push(t1-t2);
        }
        return pq.top();
    }
};