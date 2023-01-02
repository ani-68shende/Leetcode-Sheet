class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        string temp = "";
        long long sum=0,c1=0,c2=0;
        for(char & a : text){
            if(a == pattern[0]){
                c1++;
                temp+=a;
            }else if(a == pattern[1]){
                c2++;
                temp+=a;
            }
        }
        if(pattern[0] == pattern[1]){
            long long n = c1+c2+1;
            return n*(-1+n)/2;
        }
        if(c1>c2){
            long long total = 1;
            for(int i = temp.size() -1 ;i>=0; i--){
                if(pattern[1] == temp[i]){
                    total++;
                }else{
                    sum+=total;
                }
            }
        }else{
            long long total = 1;
            for(int i = 0 ; i < temp.size() ; i++){
                if(pattern[0] == temp[i]){
                    total++;
                }else{
                    sum+=total;
                }
            }
        }
        return sum;
    }
};