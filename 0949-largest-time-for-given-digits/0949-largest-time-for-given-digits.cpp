class Solution {
public:
    string maxu = "";
    
    void func(vector<int>& arr, int mask, string num){
        if(__builtin_popcount(mask) == 4){
            // reverse(num.begin(), num.end());
            if(num[0] == '2' and num[1] <= '3' and num[2] <= '5'){
                maxu = max(maxu, num);
            }else if(num[0] < '2' and num[2] <= '5'){
                maxu = max(maxu, num);
            }
            return ;
        }
        for(int i = 0 ; i < 4 ; i++){
            if((mask & (1 << i)))continue;
            int temp = mask;
            func(arr, (temp | (1 << i)), num+to_string(arr[i]));
        }
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        int mask = 0, num = 0;
        func(arr, mask, "");
        string temp = maxu;
        string ans;
        sort(arr.begin(), arr.end());
        if(arr[0] > 2)return "";
        for(int i = 0 ; i < temp.size() ; i++){
            ans.push_back(temp[i]);
            if(i == 1){
                ans.push_back(':');
            }
        }
        return ans;
    }
};