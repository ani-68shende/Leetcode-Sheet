class Solution {
public:
    bool judgeCircle(string moves) {
        int hori = 0;
        int verti = 0;
        for(auto x : moves){
            if(x == 'U'){
                verti++;
            }
            if(x == 'D'){
                verti--;
            }
            if(x == 'R'){
                hori++;
            }
            if(x == 'L'){
                hori--;
            }
        }
        return hori == 0 && verti == 0;
    }
};