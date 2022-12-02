class Solution {
public:
    // copy paste bois added to list
    
    
    //
    long long pajjwa = LLONG_MAX; 
    //
    
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>s;
        int mm= t.size();
        vector<int>v(mm, 0);
        for(int i = mm-1 ; i >= 0 ; i--){
            while(s.size() && t[s.top()] <= t[i]){
                s.pop();
            }
            if(s.size()){
                v[i] = s.top()-i;
            }
            s.push(i);
        } 
        return v;
    }
};