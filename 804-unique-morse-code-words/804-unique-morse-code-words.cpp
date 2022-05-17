class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>v{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string, int>mp;
        for(auto x : words){
            string h = "";
            for(auto y : x){
                h += (v[y-'a']);
            }
            mp[h]++;
        }
        return mp.size();
    }
};