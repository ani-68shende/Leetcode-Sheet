class Solution {
public:
    int N;
    int maxu =0;
    int f(int i, vector<string>& words, vector<char>& letters, unordered_map<char, int> mp, vector<int>& score){
        if(i == N)return 0;
        int notpick = 0 + f(i+1,words, letters, mp, score);
        int pick = 0;
        int idx = 0;
        int flagu = 0;
        for(auto x : words[i]){
            if(mp[x] > 0){
                idx++;
                mp[x]--;
                pick += score[x-'a'];
            }else{
                pick = 0;
                flagu = 1;
                break;
            }
        }
        if(pick == 0 && flagu == 1){
            for(int k = 0 ; k < idx; k++){
                mp[words[i][k]]++;
            }
        }
        pick +=  f(i+1,words, letters, mp, score);
        maxu = max({maxu, pick, notpick});
        return max({pick, notpick});
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        N= n;
        unordered_map<char, int>mp;
        for(auto x : letters){
            mp[x]++;
        }
        return f(0, words, letters, mp, score);
    }
};