#define pb push_back
#define ppb pop_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define ll long long int
#define cc continue
class Solution {
public:
    string pajwa;
    vector<string> v = {"a","b","c"};
    void f(int i, int n, string & s, int k, int &countya){
        if(i == n){
            countya++;
            if(countya == k)
                pajwa = s;
            return ;
        }
        for(int j = 0 ; j < 3; j++){
            if(s.size() >= 1 && s[s.size()-1] == v[j][0])continue;
            s += v[j];
            f(i+1, n, s, k, countya);
            s.ppb();
        }
    }
    string getHappyString(int n, int k) {
        string s = "";
        int countya = 0;
        f(0, n, s, k, countya);
        return pajwa;
    }
};