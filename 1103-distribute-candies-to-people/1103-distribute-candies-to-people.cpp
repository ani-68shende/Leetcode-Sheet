class Solution {
public:
    vector<int> distributeCandies(int c, int n) {
        vector<int>ans(n);
        int sum = 0;
        int i = 0;
        while(c>0){
            sum += 1;
            c -= sum;
            if(c < 0){
                c += sum;
                int y = abs(c);
                ans[i%n] += c;
                break;
            }
            ans[i%n] += sum;
            i++;
        }
        return ans;
    }
};