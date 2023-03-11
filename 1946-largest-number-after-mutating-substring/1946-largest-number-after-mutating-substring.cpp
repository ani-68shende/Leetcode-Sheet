class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        unordered_map<char, char>mp;
        for(int i = 0 ; i < change.size() ; i++){
            mp[i+'0'] = change[i]+'0';
        }
        int i = 0;
        int flag = 0;
        while(i < num.size() && !flag){
            if(i < num.size() && num[i] < mp[num[i]]){
                while(i < num.size() && num[i] <= mp[num[i]]){
                    num[i] = mp[num[i]];
                    flag = 1;
                    i++;
                }
            }
            i++;
        }
        return num;
    }
};