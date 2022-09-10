class Solution {
public:
    bool isRobotBounded(string inst) {
        set<pair<int, int>> s;
        int x = 0, y = 0;
        // s.insert({0,0});
        string dir = "N";
        // vector<string>d{"N","E","S","W"};
        int j=0;
        for(auto i(0) ; i < 4; i++){
            inst += inst;
        }
        vector<pair<int, int>>v1, v2;
        for(auto i(0) ; i < 4; i++){
        for(int i =0 ; i < inst.size() ; i++){
            if(inst[i] == 'G'){
                // cout << i << " " << x << " " << y << endl;
                if(dir == "N")y++;
                if(dir == "S")y--;
                if(dir == "E")x++;
                if(dir == "W")x--;
            }else if(inst[i] == 'R'){
                if(dir == "N")dir = "E";
                else if(dir == "S")dir = "W";
                else if(dir == "E")dir = "S";
                else if(dir == "W")dir = "N";
            }else{
                if(dir == "N")dir = "W";
                else if(dir == "S")dir = "E";
                else if(dir == "E")dir = "N";
                else if(dir == "W")dir = "S";
            }
            v1.push_back({x, y});
        }
        }
        for(auto i(0) ; i < 4; i++){
        for(int i =0 ; i < inst.size() ; i++){
            if(inst[i] == 'G'){
                // cout << i << " " << x << " " << y << endl;
                // if(s.count({x,y}))return true;
                // s.insert({x, y});
                if(dir == "N")y++;
                if(dir == "S")y--;
                if(dir == "E")x++;
                if(dir == "W")x--;
            }else if(inst[i] == 'R'){
                if(dir == "N")dir = "E";
                else if(dir == "S")dir = "W";
                else if(dir == "E")dir = "S";
                else if(dir == "W")dir = "N";
            }else{
                if(dir == "N")dir = "W";
                else if(dir == "S")dir = "E";
                else if(dir == "E")dir = "N";
                else if(dir == "W")dir = "S";
            }
            v2.push_back({x, y});
        }
        }
        if(v1 == v2)return true;
        return false;
    }
};