class Solution {
public:
    string getSmallestString(int n, int k) {
        string mar = "";
        int n1 = n;
        while(n1--){
            mar.push_back('a');
            k--;
        }
        int y = n-1;
        while(y >= 0 && k>0){
            int j(0);
            if(k >= 25){
                j = 25;
                k-=25;
            }
            else if(k >= 1){
                j = k%25;
                k = 0;
            }
            mar[y]+=j;
            y--;
        }
        return mar;
    }
};