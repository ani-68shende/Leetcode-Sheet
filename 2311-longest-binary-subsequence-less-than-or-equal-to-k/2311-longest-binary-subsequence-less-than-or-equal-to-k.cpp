class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count_zeros = 0;
        for(auto x : s){
            if(x == '0')count_zeros++;
        }
        
        int sum = 0;
        int base = 1;
        int len = 0;
        for(int i = s.size()-1 ; i>= 0 ; i--){
            if(sum + base > k)break;
            if(s[i] == '1')
                sum += base;
            else
                count_zeros--;
            base *= 2;
            len++;
        }
        return len + count_zeros;
    }
};