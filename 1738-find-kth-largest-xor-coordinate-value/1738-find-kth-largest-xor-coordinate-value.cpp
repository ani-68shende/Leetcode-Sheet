class Solution {
public:
    //was doing a simple row col mistake :(
    
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<long, vector<long>, greater<long>>pq;
        vector<vector<int>>v(matrix);
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 1 ; i < m ; i++){
            v[0][i] = v[0][i-1] ^ v[0][i];
        }
        for(int i = 1 ; i < n ; i++){
            v[i][0] = v[i-1][0] ^ v[i][0];
        }
        for(int i = 1; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                v[i][j] = v[i-1][j] ^ v[i][j-1] ^ v[i-1][j-1] ^ v[i][j];
            }
        }
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                pq.push(v[i][j]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};