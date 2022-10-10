class Solution {
public:
    // my bike's seat is only for the closed ones 
    bool isPalindrome(string &h){
        int start = 0, end = h.size()-1;
        while(start <= end){
            if(h[start++]!=h[end--])return false;
        }
        return true;
    }
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1)return "";
        int i = 0;
        string s, temp;
        int n = palindrome.size();
        string h = "";
        for(int i(0) ; i < n ; i++)s+="z";
        for(int i = n-1 ; i >= 0 ; i-=1){
            for(auto x = 'a' ; x <= 'z' ; x++){
                h = palindrome;
                if(palindrome[i]!=x){
                    h[i] = x;
                    if(!isPalindrome(h))
                        s = min(s, h);
                }
            }
        }
        return s;
    }
};