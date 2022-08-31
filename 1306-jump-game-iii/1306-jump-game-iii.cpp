class Solution {
public:
    vector<int>visited;
    // here we use visited so that we don't visit the same index twice
    bool f(int i, vector<int> & arr){
        if(i < 0 || i >= arr.size())return false;
        if(visited[i])return false;
        visited[i] = 1;
        if(i >= 0 && i < arr.size() && arr[i] == 0){
                return true;
        }
        bool left = f(i-arr[i], arr);
        bool right = f(i+arr[i], arr);
        return left | right;
    }
    bool canReach(vector<int>& arr, int start) {
        visited.resize(arr.size(), 0);
        return f(start, arr);
    }
};