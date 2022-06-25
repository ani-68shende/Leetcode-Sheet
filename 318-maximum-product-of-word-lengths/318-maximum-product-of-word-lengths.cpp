class Solution {
public:
    int maxProduct(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int count = 0;
        sort(words.begin(), words.end(), greater<string>());
        for(int i = 0 ; i < words.size() ; i++){
            int h = words[i].size();
            vector<int>mp(26,0);
            for(auto x : words[i]){
                mp[x-'a']=1;
            }
            for(int j = i+1 ; j < words.size() ; j++){
                int flag = 0;
                for(auto g : words[j]){
                    if(mp[g-'a']==1){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    int q = words[j].size();
                    count = max(h * q, count);
                }
            }
        }
        return count;
    }
};