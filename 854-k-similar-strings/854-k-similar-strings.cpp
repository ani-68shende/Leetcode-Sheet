class Solution {
public:
    // sia's unstoppable reminds me of prajwa i swear... not joking
    int kSimilarity(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        set<string>s;
        queue<pair<string, int>>q;
                            //depththththt
        int n = s2.size();
        n = s1.size();
        q.push({s1, 0});
        s.insert(s1);
        while(!q.empty()){
            int qu = q.size();
            for(int h = 0 ; h < qu ; h++){
                auto fron  = q.front();
                string parent = fron.first;
                int depth = fron.second;
                q.pop();
                if(s2 == parent)return depth;
                int i = 0;
                for(i = 0 ; i < n ; i++){
                    if(s2[i] != parent[i])break;
                }
                for(int j = i+1 ; j < n ; j++){
                    if(s2[i] == parent[j]){
                        swap(parent[j], parent[i]);
                        if(!s.count(parent)){
                            q.push({parent, depth+1});
                            s.insert(parent);
                        }
                        swap(parent[j], parent[i]);
                    }
                }
            }
        }
        return -69;
    }
};