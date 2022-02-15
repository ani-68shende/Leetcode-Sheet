class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>b;
        for(int k = 0; k < l.size() ; k++){
            vector<int>v;
            int flag = 0;
            for(int j = l[k] ; j <= r[k]  ; j++ ){
                v.push_back(nums[j]);
            }
            sort(v.begin() , v.end());
            int u = v[1]-v[0];
            for(int i = 1 ; i < v.size() ; i++){
                if(u!=v[i]-v[i-1]){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                b.push_back(false);
            }else b.push_back(true);
        }
        return b;
    }
};