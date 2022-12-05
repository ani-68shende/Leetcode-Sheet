class Solution {
public:
    //fedup and hence..... you know  -_-
    
    
    int leastInterval(vector<char>& tasks, int k) {
        
        //k is the wait time between 2 same tasks
        
        unordered_map<char,int> hash;
        for(int i = 0; i<tasks.size(); i++) hash[tasks[i]]++;
        
        priority_queue<int> pq; // max queue
        
        for(auto it : hash) pq.push(it.second);
        
        int timer = 0;
        
        while(!pq.empty()) {
            vector<int> temp;
            for(int i = 0; i<=k; i++) { // block of size (k+1)
                if(!pq.empty()) {
                    temp.push_back(pq.top()); // pick frequently occuring tasks (greedy)
                    pq.pop();
                }
            }
            
            for(int i = 0; i<temp.size(); i++) {
                if(--temp[i] > 0) pq.push(temp[i]); //(if tasks of the kind remain push them back in)
            }
            
            timer += pq.empty() ? temp.size() : k+1; // if queue is empty then we got no remaining tasks hence the current block size 
			// is temp.size() else we got a block of size k+1
        }
        return timer;
    }
};