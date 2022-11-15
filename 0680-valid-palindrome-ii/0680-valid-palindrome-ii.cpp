class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        int count = 0;
        while(i<j){
            if(s[i] != s[j])count++,j--;
            else i++,j--;
        }
        i = 0, j = s.size()-1;
        int count2 = 0;
        while(i<j){
            if(s[i] != s[j])count2++,i++;
            else i++,j--;
        }
        return min(count, count2) <= 1;
    }
};