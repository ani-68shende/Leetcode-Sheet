//24/01/2022

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        string temp = "";
        for(int i = 1 ; i < n ; i++){
            temp.push_back(word[i]);
        }
        string h = "";
        for(auto x : temp){
            h+=tolower(x);
        }
        int flag = 1;
        for(auto x : word){
            if(x>='A' && x <= 'Z'){
            }else{
                flag = 0;
                break;
            }
        }
        if(flag)return true;
        return h == temp;
    }
};