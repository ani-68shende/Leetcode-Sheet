class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(),boxes.end(),greater<int>());
        int j = 0;
        int count = 0;
        int mini = INT_MAX;
        for(int i = 0 ; i < warehouse.size() && j< boxes.size() ; i++){
            mini = min(mini, warehouse[i]);
            if(mini >= boxes[j]){
                count++;
                j+=1;
            }else{
                j+=1;
                i--;
            }
        }
        return count;
    }
};