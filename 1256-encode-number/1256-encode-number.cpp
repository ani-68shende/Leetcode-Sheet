class Solution {
public:
    string encode(int num) {
        num++;
        string ans = "";
        while(num>1){
            int rem = num%2;
            ans+= to_string(rem);
            num/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};