class Solution {
public:
    int counto = 0;
    unordered_map<string, int> vis;
    int maxu = 0;
    void f(int i, vector<string> & arr, string &temp){
        map<char, int>s;
        for(auto x : temp)s[x]++;
        if(maxu < temp.size()){
            set<char>ss;
            for(auto x : temp)ss.insert(x);
            if(ss.size() == temp.size()){maxu = temp.size();}
        }
        if(i == arr.size())return ;
        for(int k = i; k < arr.size() ; k++){
            int flga = 0;
            for(auto x : arr[k]){
                if(s.find(x)!=s.end())flga = 1;break;
            } 
            if(flga)continue;
            // cout << temp << " " << arr[k ] << endl;
            string h = temp;
            temp += arr[k];
            f(k+1, arr, temp);
            temp = h;
        }
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        f(0,arr, temp);
        // for(auto x : vis)cout << x.first << " ";
        return maxu;
    }
};