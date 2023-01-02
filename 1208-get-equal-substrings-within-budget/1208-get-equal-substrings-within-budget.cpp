class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0;
        int j =0;
        int n  = s.size();
        vector<int>v;
        for(int i = 0 ; i < n ; i++){
            v.push_back(abs(s[i]-t[i]));
        }
        long long sum = 0;
        int maxu = 0;
        while(j < n){
            sum += v[j];
            if(sum>maxCost){
                while(i < n && sum>maxCost){
                    sum-=v[i];
                    i++;
                }
            }
            maxu = max(maxu,j-i+1);
            j++;
        }
        return maxu;
    }
};