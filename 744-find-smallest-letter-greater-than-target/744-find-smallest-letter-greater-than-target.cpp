class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //samajh ke bahar wala solution
        
        auto begin = letters.begin();
        auto end = letters.end();
        auto itr = upper_bound(begin, end, target);
        return itr!=end ? *itr : *begin;
    }
};