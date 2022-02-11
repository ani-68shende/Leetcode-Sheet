class Solution {
public:
    string bringall(string s, int n){
        if(n == 0)return s;
        string y = s;
        for(int i= 0 ; i < y.size() ; i++){
            if(y[i] == '0')y[i] = '1';
            else y[i] = '0';
        }
        reverse(y.begin(), y.end());
        return bringall(s + "1" + y, n-1);
    }
    char findKthBit(int n, int k) {
        string s ="0";
        string h = bringall(s, n);
        // cout << h << endl;
        return h[k-1];
    }
};