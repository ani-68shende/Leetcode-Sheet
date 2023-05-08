class Solution {
public:
    /*
    [a^b,    b^c,   c^d,   d^e]
    X = a ^    (b^c)     ^   (d^e)
    X = a ^ (encoded[1]) ^ (encoded[3])
    => a = X ^ (encoded[1] ^ encoded[3])
    */
    vector<int> decode(vector<int>& encoded) {
        vector<int>v;
        int n = encoded.size();
        int xoro = 0;
        for(int i = 1 ; i <= n+1 ; i++){
            xoro ^= i;
        }
        for(int i = 1 ; i < n ; i+=2){
            xoro  ^=  encoded[i];
        }
        v.push_back(xoro);
        for(int i = 0 ; i < n ; i++){
            v.push_back(v.back()^encoded[i]);
        }
        return v;
    }
};