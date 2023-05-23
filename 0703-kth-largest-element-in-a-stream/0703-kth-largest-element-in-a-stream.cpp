class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int siz; // this siz variable is basically designed to be used in the second function where we don't have the value of k ...in short k cannot be used there
    KthLargest(int k, vector<int>& nums) {
        siz = k;
        for(int i = 0 ; i < nums.size() ; i++){
            pq.push(nums[i]);
            if(pq.size() > siz)pq.pop();
        }
    }
    
    int add(int val) {
        //same operations as above function see the inner for loop for more details 
            pq.push(val);
            if(pq.size() > siz)pq.pop();
     //here we just need to return the topmost element of the heap;
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */