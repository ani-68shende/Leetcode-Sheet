class SeatManager {
public:
    set<int>res, unres;
    int no = 0, N;
    SeatManager(int n) {
        N=n;
    }
    
    int reserve() {
        if(unres.size() == 0){
            res.insert(no+1);
            no++;
            return no;
        }
        int x = *unres.begin();
        res.insert(x);
        unres.erase(x);
        return x;
    }
    
    void unreserve(int seatNumber) {
        unres.insert(seatNumber);
        res.erase(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */