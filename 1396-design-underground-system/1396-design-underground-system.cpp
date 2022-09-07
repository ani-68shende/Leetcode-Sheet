class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> userinfo;
                // id ,     station, time
    unordered_map<string, pair<double, int>> routeinfo;
                //start ,     total, count to find the average which is required
                // and
                //end station
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        userinfo[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto xx = userinfo[id];
        userinfo.erase(id);
        string new_name = xx.first + "-_-" + stationName;
        routeinfo[new_name].first += t-xx.second;
        routeinfo[new_name].second+= 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string start_end = startStation + "-_-" + endStation;
        return routeinfo[start_end].first/routeinfo[start_end].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */