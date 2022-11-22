class WordDistance {
public:
    vector<string>w;
    unordered_map<string, vector<int>>mp;
    WordDistance(vector<string>& wordsDict) {
        w=wordsDict;
        for(int i = 0 ; i < w.size() ; i++){
            mp[w[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
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

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */