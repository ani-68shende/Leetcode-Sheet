class MedianFinder {
public:
    // two priority queues... one for elements less than median and the other for the elements greater than median
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>>right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || left.top() >= num){
            left.push(num);
        }else{
            right.push(num);
        }
        if(left.size()>1+(right.size())){
            right.push(left.top());
            left.pop();
        }else if(right.size()>1+(left.size())){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        // compare sizes ...don't forget
        if(left.size()>right.size())return left.top();
        else if (left.size()<right.size()) return right.top();
        return (right.top() + left.top())/2.00;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */