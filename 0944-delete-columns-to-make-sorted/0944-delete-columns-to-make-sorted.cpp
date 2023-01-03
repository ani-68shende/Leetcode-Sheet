class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int counto = 0;
        for(int j=0 ; j < strs[0].size() ; j++){
            char prev = 'A';
            int flag = 0;
            for(int i=0; i < strs.size() ; i++){
                if(strs[i][j]>=prev){
                    prev = strs[i][j];
                }else{
                    flag = 1;
                    break;
                }
            }
            if(flag){
                counto++;
            }
        }
        return counto;
    }
};