class Solution {
public:
    int minFlips(string target) {
        int count = 0;
        char prev = '0';
        for(int i = 0; i < target.size() ; i++){
            if(prev!=target[i]){
                prev = target[i];
                count++;
            }
        }
        return count;
    }
};