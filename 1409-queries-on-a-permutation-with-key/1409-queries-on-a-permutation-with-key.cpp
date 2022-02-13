class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>u;
        vector<int>v;
        for(int i = 1 ; i <= m ; i++){
            v.push_back(i);
        }
        for(auto i = 0 ;i < queries.size() ; i++){
            int pos;
            int q = 0;
            for(auto j = 0 ; j < m; j++){
                if(v[j] == queries[i]){
                    pos = j;break;
                }
            }
            u.push_back(pos);
            int temp = v[pos];
            v.erase(v.begin()+ pos);
            v.insert(v.begin(), temp);
            
        }
        return u;
    }
};