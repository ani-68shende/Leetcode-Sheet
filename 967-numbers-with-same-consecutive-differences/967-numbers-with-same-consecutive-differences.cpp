class Solution {
public:
    vector<int> ans;
    void f(char ini, int i, int n, string s, int k){
        if(i == n){
            ans.push_back(stoi(s));
            return ;
        }
        for(char j = '0' ; j <= '9'  ; j++){
            if(ini == '#' && j >= '1'){
                f(j, i+1, n, s+j, k);
            }
            else if(s.size() && abs(j-s.back()) == k){
                f(j, i+1, n, s+j, k);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string s;
        int i = 0;
        f('#', i, n, s, k);
        return ans;
    }
};