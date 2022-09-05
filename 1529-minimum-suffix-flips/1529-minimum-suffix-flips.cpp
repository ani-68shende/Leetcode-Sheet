class Solution {
public:
    int minFlips(string target) {
        int count =0;
        char prev = '0';
        // reverse(target.begin(), target.end());
        // int j = -1 + target.size();
        // while(j >= 0 && target[j]=='0'){
        //     target.pop_back();
        //     j--;
        // }
        reverse(target.begin(), target.end());
        for(int i = target.size()-1; i >= 0 ; i--){
            if(prev!=target[i]){
                prev = target[i];
                count++;
            }
        }
        return count;
    }
};