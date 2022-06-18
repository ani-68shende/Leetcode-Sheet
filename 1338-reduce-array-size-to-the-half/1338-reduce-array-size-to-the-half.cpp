class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int>mp;
        for(auto x : arr){
            mp[x]++;
        }
        vector<int>m;
        for(auto x : mp){
            m.push_back(x.second);
        }
        sort(m.begin(), m.end(),greater<int>());
        int n = arr.size();
        int sum = 0;
        int count = 0;
        int i = 0;
        while(n/2>sum){
            sum += m[i];
            count++;
            i++;
        }
        return count;
    }
};