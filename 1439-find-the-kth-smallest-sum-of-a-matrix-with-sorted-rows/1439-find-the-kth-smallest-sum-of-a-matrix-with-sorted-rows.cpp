class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<int, vector<int> , greater<int>>pq;
        int n = mat.size();
        int m = mat[0].size();
        set<pair<int, vector<int>>>s;
        int sum = 0;
        for(int i(0) ; i < n ; i++){
            sum += mat[i][0];
        }
        vector<int>temp(n, 0);
        s.insert({sum, temp});
        for(int i(0) ; i < k - 1; i++){
            auto top = *s.begin();
            int sum = top.first;
            vector<int>t = top.second;
            s.erase(s.begin());
            for(int j(0) ; j < n ; j++){
                if(t[j]+1 >= m)continue;
                t[j]+=1;
                int temp = sum;
                sum = sum + mat[j][t[j]] - mat[j][t[j]-1];
                s.insert({sum, t});
                t[j]-=1;
                sum=temp;
            }
            // for(auto x : s){
            //     cout << x.first << " ";
            // }
            // cout << "\n---";
        }
        return (*s.begin()).first;
    }
};