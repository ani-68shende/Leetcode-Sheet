class Solution {
public:
    
    // prajwa learning hungarian algo
    
    int ladderLength(string bw, string ew, vector<string>& w) {
        //bfs bois
        queue<string>q;
        q.push(bw);
        unordered_map<string, int>mp;
        for(auto x : w)
            mp[x]++;
        if(mp.count(bw))mp.erase(bw);
        if(mp.count(ew) == 0)return 0;
        int steps = 1;
        while(!q.empty()){
            int siz = q.size();
            for(int kk = 0 ; kk < siz ; kk++){
                string node = q.front();
                q.pop();
                if(node == ew){
                    return steps;
                }
                for(int i = 0 ; i < node.size() ; i++){
                    string temp = node;
                    for(int j = 'a' ; j <= 'z' ; j++){
                        temp[i] = j;
                        if(mp.count(temp)){
                            q.push(temp);
                            mp.erase(temp);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};