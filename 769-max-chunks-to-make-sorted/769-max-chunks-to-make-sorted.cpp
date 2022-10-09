class Solution {
public:
    int tres = 0;
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>visited(arr.size(), 0);
        int prev = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            visited[arr[i]] = 1;
            int sum(0);
            for(int j = prev ; j <= i ; j++){
                sum += visited[j];
            }
            if(i-prev+1 == sum){
                tres++;
                prev = i+1;
            }
        }
        return tres;
    }
};