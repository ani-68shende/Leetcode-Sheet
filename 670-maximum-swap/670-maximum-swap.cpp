class Solution {
public:
    int maximumSwap(int num) {
        string ans = to_string(num);
        int n = ans.size();
        char maxu = *max_element(ans.begin(), ans.end());
        int i(0);
        int d(0);
        while(i < n && maxu == ans[i]){
            maxu = *max_element(ans.begin()+i+1, ans.end());
            i++;
        }
        // cout << num << " " <<  i << endl;
        d = i;
        maxu = *max_element(ans.begin()+i, ans.end());
        int j = i;
        int final_blow = j;
        for(; j < n ; j+=1 ){
            if(ans[j] == maxu){
                final_blow=j;
            }
        }
        swap(ans[final_blow], ans[i]);
        return stoi(ans);
    }
};