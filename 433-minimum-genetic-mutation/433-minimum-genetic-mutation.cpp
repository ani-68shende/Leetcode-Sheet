class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int count = 0;
        queue<string>q;
        int n = bank.size();
        vector<bool>visited(n, false);
        q.push(start);
        for(auto i = 0 ; i < bank.size() ; i++){
            if(start == bank[i]){
                visited[i] = true;
            }
        }
        while(!q.empty()){
            count++;
            int siz = q.size();
            for(int i = 0 ; i < siz ; i++){
                string front = q.front();
                q.pop();
                for(auto k = 0 ; k < n ; k++){
                    if(visited[k]==false){
                        string x = bank[k];
                        int difference = 0;
                        for(auto i = 0 ; i < x.size() ; i++){
                            if(front[i]!=x[i])difference++;
                        }
                        if(difference == 1){
                            if(x == end)return count;
                            visited[k] =true;
                            q.push(x);
                        }
                    }
                }
            }
        }
        return -1;
    }
};