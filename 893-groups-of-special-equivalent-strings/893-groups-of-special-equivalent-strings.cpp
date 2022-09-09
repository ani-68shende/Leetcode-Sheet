class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n = (words.size());
        unordered_map<string, int>mp;
        for(int i = 0 ;i < n ; i++){
            string od = "", even="";
            for(int k = 0 ; k < words[i].size() ; k+=1){
                if(k%2)od+=words[i][k];
                else even+=words[i][k];
            }
            sort(od.begin(), od.end());
            sort(even.begin(), even.end());
            od += even;
            mp[od]++;
        }
        return mp.size();
    }
};