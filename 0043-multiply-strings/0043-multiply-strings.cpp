class Solution {
public:
    string multiply(string num1, string num2) {
        // vector<vector<int>>v(num2.size(), vector<int>(num1.size()+num2.size()-1, 0));
        vector<vector<int>>v(num2.size(), vector<int>(num1.size()+1, 0));
        int j1 = 0;
        int nnn = num1.size();
        for(int i = num2.size()-1 ; i >= 0 ; i--){
            int carry = 0;
            int kk = 0;
            int j = num1.size()-1;
            for(; j >= 0 ; j--){
                int sum = (num1[j]-'0')*(num2[i]-'0')+carry;
                int val = (sum)%10;
                carry = sum/10;
                v[i][j+1] = val;
                kk++;
            }
            if(carry!=0){
                v[i][j+1] = carry;
            }
            // reverse(v[i].begin(), v[i].end());
            j1++;
        }
        // reverse(v[j].begin(), v[j].end());
        reverse(v.begin(), v.end());
        int carry = 0;
        string ans = "";
        // for(auto x : v){
        //     for(auto y : x){
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        for(int j = v[0].size() - 1 ; j >= 0 ; j--){
            int sum=0+carry;
            int x = 0;
            int y = j;
            while(x < v.size() and y < v[0].size()){
                sum += v[x][y];
                x++, y++;
            }
            int val = (sum)%10;
            carry = sum/10;
            ans = to_string(val) + ans;
        }
        for(int j = 1 ; j < v.size() ; j++){
            int sum=0+carry;
            int x = j;
            int y = 0;
            while(x < v.size() and y < v[0].size()){
                sum += v[x][y];
                x++, y++;
            }
            int val = (sum)%10;
            carry = sum/10;
            ans = to_string(val) + ans;
        }
        if(carry!=0){
            ans = to_string(carry) + ans;
        }
        reverse(ans.begin(),ans.end());
        while(ans.back() == '0')ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans == "" ? "0" : ans;
    }
};