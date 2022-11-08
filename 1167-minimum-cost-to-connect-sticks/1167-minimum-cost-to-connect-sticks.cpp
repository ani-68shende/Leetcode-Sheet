class Solution {
public:
    //underestimated the qn ig we solved this one of the contestd
    int connectSticks(vector<int>& sticks) {
        int prev = 0;
        int super_total = 0;
        priority_queue<int, vector<int>,greater<int>>pq;
        for(auto x : sticks)pq.push(x);
        while(pq.size()>=2){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            prev = a+b;
            pq.push(prev);
            super_total += prev;
        }
        return super_total;
    }
};