class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx = -1;
        for(int i = 0 ; i < haystack.size() ; i++){
            if(haystack[i] == needle[0]){
                int count = 0;
                int d = i;
                for(int j = 0 ; j < needle.size() ; j++ ){
                    if(haystack[d] == needle[j]){
                        d++;
                        count++;
                    }
                } 
                if(count == needle.size()){
                    return idx = i;
                }
            }
        }
        return idx;
    }
};