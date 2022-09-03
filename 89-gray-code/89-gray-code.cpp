class Solution {
public:
    // dekh kya raha hai... add to list
    vector<int>ans;
    void f(int n, bitset<32>&bits){
        if(n == 0){
            ans.push_back(bits.to_ulong());
            return ;
        }
        f(n-1, bits);
        bits.flip(n-1);
        f(n-1, bits);
    }
    vector<int> grayCode(int n) {
        bitset<32>bits;
        f(n, bits);
        return ans;
    }
};