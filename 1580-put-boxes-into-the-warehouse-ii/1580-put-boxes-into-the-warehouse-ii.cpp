class Solution {
public:
    //idk how it got ac literally anything T-T
    int helper(vector<int>& boxes, vector<int>& warehouse){
        sort(boxes.begin(),boxes.end(),greater<int>());
        int j = 0;
        int count = 0;
        int mini = INT_MAX;
        unordered_map<int, int>visited;
        int idx = min_element(warehouse.begin(),warehouse.end())-warehouse.begin();
        // cout << idx << endl;
        for(int i = 0 ; i <= idx && j< boxes.size() ; i++){
            mini = min(mini, warehouse[i]);
            if(mini >= boxes[j]){
                if(visited.find(j)==visited.end()){
                    // cout << j << endl;
                    count++;
                    visited[j]++;
                }else{
                    i--;
                }
                j+=1;
            }else{
                j+=1;
                i--;
            }
        }
        cout << count<< endl;
        mini =INT_MAX;
        j=0;
        for(int i = warehouse.size()-1 ; i >=idx+1 && j< boxes.size() ; i--){
            mini = min(mini, warehouse[i]);
            if(mini >= boxes[j]){
                if(visited.find(j)==visited.end()){
                    // cout << j << endl;
                    count++;
                    visited[j]++;
                }else{
                    i++;
                }
                j+=1;
            }else{
                j+=1;
                i++;
            }
        }
        cout << count << endl;
        return count;
    }
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int m1 = helper(boxes, warehouse);
        sort(warehouse.begin(), warehouse.end());
        int m2 = helper(boxes, warehouse);
        cout << "--\n\n";
        return m1;
    }
};