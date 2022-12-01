class Solution {
public:
    set<char>s1{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool halvesAreAlike(string s) {
        int c1(0), c2(0);
        for(int i = 0 ; i < s.size() ; i++){
            if(i < s.size()/2){
                c1 += s1.count(s[i]) == true;
            }else{
                c2 += s1.count(s[i]) == true;
            }
        }
        return c1 == c2;
    }
};