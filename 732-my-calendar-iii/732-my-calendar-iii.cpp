class MyCalendarThree {
public:
    int maxu = 0;
    map<long, long>mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum = 0;
        for(auto x : mp){
            sum += x.second;
            maxu = max(maxu, sum);
        }
        return maxu;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */