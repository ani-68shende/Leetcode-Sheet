class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        vector<int> v(27, 0), v2(27, 0);
        for(auto x : s1){
            v[x-'a']++;
        }
        // vector<int>temp(v);
        int i = 0, j = 0;
        int n2 = s1.size();
        while(j < n){
            v2[s2[j]-'a']++;
            if(j-i+1 == n2){
                if(v == v2){
                    return true;
                }else{
                    v2[s2[i]-'a']--;
                }
                i++;
            }
            j+=1;
        }
        return false;
    }
};