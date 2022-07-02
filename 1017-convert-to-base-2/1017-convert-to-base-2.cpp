class Solution {
public:
    string baseNeg2(int n) {
        string s = "";
        while(n){
            s=to_string(n & 1)+s;
            n = -(n >> 1);
        }
        return s == "" ? "0" : s;
    }
};