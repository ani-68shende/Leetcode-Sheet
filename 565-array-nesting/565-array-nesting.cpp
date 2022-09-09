class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxu = 0;
        vector<int>visited(nums.size(), 0);
        for(int i = 0 ; i < nums.size() ; i++){
            if(visited[i])continue;
            int count = 1;
            int index = i;
            visited[index] = 1;
            int prev = index;
            index = nums[i];
            while(prev != index){
                count++;
                int temp = nums[index];
                visited[index] = 1;
                index = temp;
            }
            // for(auto x : visited)cout << x << " ";
            // cout << endl;
            maxu = max(maxu, count);
        }
        return maxu;
    }
};