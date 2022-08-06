class Solution {
public:
    vector<string>v{"a","e","i","o","u"};
    
    int f(string prev, int n){
        if(n == 0)return 1;
        int count = 0;
        for(int i = 0 ; i < 5 ; i++){
            if(prev <= v[i]){
                count += f(v[i], n-1);
            }
        }
        return count;
    }
        
    int countVowelStrings(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string prev = "a";
        return f(prev, n);
    }
};