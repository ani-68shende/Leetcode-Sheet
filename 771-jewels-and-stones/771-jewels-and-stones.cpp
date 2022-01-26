class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count =0;
        for(auto x : jewels){
            for(auto y : stones){
                if(x == y)count++;
            }
        }
        return count;
    }
};