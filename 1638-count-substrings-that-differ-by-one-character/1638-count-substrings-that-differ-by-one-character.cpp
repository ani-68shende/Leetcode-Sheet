class Solution {
public:
    int countSubstrings(string s, string t) {
        int count(0);
        for(int i = 0 ; i < s.size() ; i++){
            string ss;
            for(int j=i ; j < s.size() ; j++){
                ss+=s[j];
                int len = ss.size();
                for(int k(0) ; k <= t.size()-len ; k++){
                    string h = t.substr(k, len);
                    int flag = 0;
                    for(auto l(0) ; l < len ; l++){
                        if(h[l]!=ss[l])flag++;
                    }
                    if(flag == 1)count++;
                }
            }
        }
        return count;
    }
};