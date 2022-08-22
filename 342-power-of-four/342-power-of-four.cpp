class Solution {
public:
    // 16 8 4 2 1
    bool isPowerOfFour(int n) {
        if(n == 1)return true;
        else if(n <= 3)return false;
        return __builtin_popcount(n) == 1 && ffs(n)%2;
    }
};