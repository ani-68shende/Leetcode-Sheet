class Solution {
public:
    bool buddyStrings(string s, string goal) {
        string h1, h2;
        if(s.size() != goal.size())return false;
        map<int, int>mp1;
        for(int i = 0 ; i < s.size() ; i++){
            mp1[s[i]]++;
            if(s[i]!=goal[i]){
                h1.push_back(s[i]);
                h2.push_back(goal[i]);
            }
        }
        bool flag = false;
        for(auto x : mp1){
            if(x.second > 1){
                flag = true;
                break;
            }
        }
        if(h1.size() == 2){
            string temp = h2;
            reverse(temp.begin(), temp.end());
            return h1 == temp;
        }      
        if(s.size() >= 2 and s == goal and flag){
            return true;
        }
        return false;
    }
};