#define pb push_back
#define ppb pop_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define ll long long int
class CombinationIterator {
public:
    vector<string> ans;
    int itr = -1;
    void f(int i, int n, string & cha, string &tmp){
        if(tmp.size() == n){
            // cout << "hello"<<endl;
            // cout << tmp << endl;
            ans.pb(tmp);
            return ;
        }
        for(int j = i ; j < cha.size() ; j++){
            tmp.pb(cha[j]);
            f(j+1, n, cha, tmp);
            tmp.ppb();
        }
    }
    CombinationIterator(string cha, int cl) {
        sort(all(cha));
        string tmp;
        int n = cl;
        f(0, n, cha, tmp);
        // for(auto x : ans)cout << x << " ";
        // cout << endl;
    }
    
    string next() {
        itr++;
        return ans[itr];
    }
    
    bool hasNext() {
        if(itr == sz(ans)-1)return false;
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */