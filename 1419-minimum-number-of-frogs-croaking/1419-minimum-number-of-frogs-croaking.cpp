class Solution {
public:
    int minNumberOfFrogs(string s) {
        map<char, int>mp; int count = 0;
        int maxu = 0;
        map<char, int>mp2;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'r'){
                if(mp['c']>0){
                    mp['c']--;
                    if(mp['c'] == 0){
                        mp.erase('c');
                    }
                    mp['r']++;
                }
            }else if(s[i] == 'o'){
                if(mp['r']>0){
                    mp['r']--;
                    if(mp['r'] == 0){
                        mp.erase('r');
                    }
                    mp['o']++;
                }
            }else if(s[i] == 'a'){
                if(mp['o']>0){
                    mp['o']--;
                    if(mp['o'] == 0){
                        mp.erase('o');
                    }
                    mp['a']++;
                }
            }else if(s[i] == 'k'){
                if(mp['a']>0){
                    mp['a']--;
                    if(mp['a'] == 0){
                        mp.erase('a');
                    }
                    mp2['c']--;
                    count++;
                }
            }else{
                mp['c']++;
                mp2['c']++;
                // cout << mp2['c'] << endl;
                maxu = max(maxu, mp2['c']);
            }
        }
        return mp.size() >0 ? -1 : maxu;
    }
};