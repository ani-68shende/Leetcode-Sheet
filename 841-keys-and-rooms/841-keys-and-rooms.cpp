class Solution {
public:
    void dfsifpathfrom0(int src, vector<vector<int>>& rooms, vector<int>&vis){
        vis[src] = 1;
        for(auto x : rooms[src]){
            if(!vis[x]){
                dfsifpathfrom0(x, rooms, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n, 0);
        dfsifpathfrom0(0, rooms, vis);
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};