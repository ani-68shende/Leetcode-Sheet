class Solution {
public:
    long long smallestNumber(long long num) {
        bool pos = true;
        if(num <= 0){
            if(num == 0)return 0;
            pos = !pos;
            num *= -1;
        }
        string s = to_string(num);
        if(pos){
            char first = '#';
            int mini = 10;
            for(auto x : s){
                if(x-'0' > 0){
                    mini = min(x-'0', mini);
                }
            }
            bool flag = true;
            string gg = "";
            for(auto x : s){
                if(flag && mini==x-'0'){
                    flag = false;
                    continue;
                }
                gg.push_back(x);
            }
            sort(gg.begin(), gg.end());
            string h = to_string(mini) + gg;
            return stoll(h);
        }else{
            char first = '#';
            int maxu = 0;
            for(auto x : s){
                if(x-'0' > 0){
                    maxu = max(x-'0', maxu);
                }
            }
            bool flag = true;
            string gg = "";
            for(auto x : s){
                if(flag && maxu==x-'0'){
                    flag = false;
                    continue;
                }
                gg.push_back(x);
            }
            sort(gg.begin(), gg.end(), greater<char>());
            string h = to_string(maxu) + gg;
            return (stoll(h)*-1);
        }
        return 0;
    }
};