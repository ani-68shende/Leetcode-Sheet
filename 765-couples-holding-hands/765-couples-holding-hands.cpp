class Solution {
public:
    unordered_map<int, int>mp;
    //this aint possible in real life atleast I can experience this question in virtual life
    void rr(vector<int>& row, int i, int j){
        swap(row[i], row[j]);
        mp[row[i]]=i;
        mp[row[j]]=j;
    }
    int minSwapsCouples(vector<int>& row) {
        int countya =0;
        for(int i = 0 ; i < row.size() ; i++) mp[row[i]] = i;
        for(int i = 0 ; i < row.size() ; i+=2){
            int first = row[i];
            int second = first ^ 1;
            if(second != row[i+1]){
                countya++;
                rr(row, i+1, mp[second]);
            }
        }
        return countya;
    }
};