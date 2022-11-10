class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, int>mp;
        mp['6'] = '9';
        mp['9'] = '6';
        mp['0'] = '0';
        mp['8'] = '8';
        mp['1'] = '1';
        string ans = "";
        int n = num.size();
        string temp = num;
        for(int i(0) ; i < n ; i++){
            if(mp.count(num[i])){
                temp[i] = mp[temp[i]];
            }else{
                return false;
            }
        }
        reverse(temp.begin(),temp.end());
        return temp == num;
    }
};