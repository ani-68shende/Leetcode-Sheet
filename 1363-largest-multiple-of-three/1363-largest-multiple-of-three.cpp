class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        // sort(digits.begin(), digits.end(),greater<int>());
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        map<int, int>mp;
        long long sum = 0;
        int n = digits.size();
        vector<int>prajwa{1,4,7,2,5,8}, ani{2,5,8,1,4,7};
        
        for(int i =0 ; i < n ; i++){
            mp[digits[i]]++;
            sum += digits[i];
        }
        int i = 0;
        int j = 0;
        int flag = 0;
        while(sum % 3 != 0){
            if(sum % 3 == 1){
                if(i >= prajwa.size()){
                    flag = 1;
                    break;
                }
                if(mp.find(prajwa[i])!=mp.end()){
                    sum -= prajwa[i];
                    mp[prajwa[i]]--;
                    if(mp[prajwa[i]] == 0){
                        mp.erase(prajwa[i]);
                    }
                }
                else 
                    i++;
            }else if(sum%3 == 0){
                break;
            }else if(sum % 3 == 2){
                if(j >= ani.size()){
                    flag = 1;
                    break;
                }
                if(mp.find(ani[j])!=mp.end()){
                    sum -= ani[j];
                    mp[ani[j]]--;
                    if(mp[ani[j]] == 0){
                        mp.erase(ani[j]);
                    }
                }
                else 
                    j++;
            }
        }
        // if(flag)return "";
        // for(auto x : mp){
        //     cout << x.first << " " << x.second << endl;
        // }
        string h = "";
        if(mp.size() == 0)return "";
        if((mp.size() == 1 && mp.count(0)))return "0";
        for(auto x : mp){
            char chu = x.first+'0';
            for(int i = 0 ;i < x.second ; i++){
                h.push_back(chu);
            }
        }
        sort(h.begin(), h.end(), greater<char>());
        return h;
    }
};