class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        if(low%2 == 0 && high%2 == 0)count = (high-low)/2;
        else count = 1+(high-low)/2;
        return count;
    }
};