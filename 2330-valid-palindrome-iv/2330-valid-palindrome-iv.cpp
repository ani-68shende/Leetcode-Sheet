class Solution {
public:
    bool makePalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        int count = 0;
        while(i<j){
            if(s[i] != s[j])count++;
            i++,j--;
        }
        return count <= 2;
    }
};