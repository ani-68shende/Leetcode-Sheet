class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int  i = 0 ;
        int j = 0;
        int n = answerKey.size();
        int res = 0;
        int count =0 ;
        ///  maximum substring of 'T' which contains k 'F'
        while(j < n){
            if(answerKey[j] == 'F')count++;
            while(count > k){
                if(answerKey[i] == 'F')count--;
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        i = 0;
        j = 0;
        count= 0;
        while(j < n){
            if(answerKey[j] == 'T')count++;
            while(count > k){
                if(answerKey[i] == 'T')count--;
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};