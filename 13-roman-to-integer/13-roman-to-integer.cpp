class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        unordered_map<char, int>m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        if(s.size() == 1){
            return m[s[0]];
        }
        int n = s.size();
        for(int i = 1 ; i < n ; i++){
            if((s[i-1] == 'I' && s[i] == 'X') || (s[i-1] == 'I' && s[i] == 'V')){
                sum-=1;
            }else if((s[i-1] == 'X' && s[i] == 'L') || (s[i-1] == 'X' && s[i] == 'C')){
                sum-=10;
            }else if((s[i-1] == 'C' && s[i] == 'D') || (s[i-1] == 'C' && s[i] == 'M')){
                sum -= 100;
            }else{
                sum += m[s[i-1]];
            }
        }
        sum += m[s[n-1]];
        return sum;
    }
};