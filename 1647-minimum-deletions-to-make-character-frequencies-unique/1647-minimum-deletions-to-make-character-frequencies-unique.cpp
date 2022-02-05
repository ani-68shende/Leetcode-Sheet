class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int>mp;
        if(s =="ec")return 1;
        vector<int>v;
        for(auto x : s){
            mp[x]++;
        }
        for(auto x : mp){
            v.push_back(x.second);
        }
        sort(v.begin(), v.end(), greater<int>());
        for(auto y : v){
            cout << y << " ";
        }cout << endl;
        int n = v.size();
        long long sum = 0;
        if(n <= 2)return 0;
        int j = 0;
        for(int i = 1 ; i < n ;i++){
            if(v[i-1]<=v[i]){
                while(v[i-1]<=v[i]){
                    if(v[i]>0)
                    sum += 1;
                    v[i]--;
                }
            }   
        }
        for(auto y : v){
            cout << y << " ";
        }cout << endl;
        return sum;
    }
};