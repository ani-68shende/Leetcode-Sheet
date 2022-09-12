class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxu = 0;
        int n = tokens.size();
        if(n==0)return 0;
        int ini = power;
        sort(tokens.begin(), tokens.end());
        int mini = *min_element(tokens.begin(), tokens.end());
        if(ini < mini)return 0;
        int i = 0, j = n-1;
        int score = 0;
        while(i< n && j >= 0  && i <= j){
            if(tokens[i] <= ini){
                ini -= tokens[i];
                score+=1;
                i++;
            }else if(score>=1){
                ini += tokens[j];
                score-=1;
                j--;
            }
            maxu = max(maxu, score);
        }
        return maxu;
    }
};