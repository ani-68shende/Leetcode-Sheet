class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        vector<int> ans;
        int n = v.size();
        int m = v[0].size();
        int dir = 0;
        int top = 0;
        int down = n-1;
        int left = 0;
        int right = m-1;
        int val = 1;
        while(top<=down && left<=right){
            if(dir == 0){
                for(int i = left ; i <= right ; i++){
                    ans.push_back(v[top][i]);
                }
                top++;
            }
            else if(dir == 1){
                for(int i = top ; i <= down ; i++){
                    ans.push_back(v[i][right]);
                }
                right--;
            }
            else if(dir == 2){
                for(int i = right ; i >= left ; i--){
                    ans.push_back(v[down][i]);
                }
                down--;
            }
            else if(dir == 3){
                for(int i = down ; i >= top ; i--){
                    ans.push_back(v[i][left]);
                }
                left++;
            }
            dir++;
            dir %= 4;
        }
        return ans;
    }
};