class Solution {
public:
    int shortestDistance(vector<string>& w, string word1, string word2) {
        unordered_map<string, vector<int>>mp;
        for(int i = 0 ; i < w.size() ; i++){
            mp[w[i]].push_back(i);
        }
        vector<int>ind = mp[word1];
        vector<int>ind2 = mp[word2];
        int mini_overall = INT_MAX;
        for(int i =0 ; i < ind.size() ; i++){
            int ele = ind[i];
            int mini = INT_MAX;
            int low = 0;
            int high = -1+ind2.size();
            while(low <= high){
                int mid = (high-low)/2 + low;
                if(ind2[mid] == ele){
                    mini = min(mini, abs(ind2[mid]-ele));
                }else if(ele < ind2[mid]){
                    mini = min(mini, abs(ind2[mid]-ele));
                    high = mid-1;
                }else{
                    mini = min(mini, abs(ind2[mid]-ele));
                    low = mid+1;
                }
            }
            mini_overall = min(mini_overall, mini);
        }
        return mini_overall;
    }
};