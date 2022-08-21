class Solution {
public:
    // takes too much time ...more implementation than logic
    int replacethen(int pos, int lenOFStamp, string & target){
        int countya = 0;
        for(int i = 0 ; i < lenOFStamp; i++){
            if(target[i+pos]!='?'){
                target[i+pos] = '?';
                countya++;
            }
        }
        return countya;
    }
    bool canbe(int pos, string & stamp, string & target){
        for(int j = 0 ; j < stamp.size(); j++){
            if(target[j+pos] != '?' && target[j+pos]!=stamp[j])return false;
        }
        return true;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        vector<bool>visited(n, false);
        string h = "";
        for(int i = 0 ;i < n ; i++){
            h.push_back('?');
        }
        int count = 0;
        vector<int>res;
        while(count != n){
            bool is_it_changing = false;
            for(int i = 0 ; i <= target.size()-stamp.size() ; i++){
                if(!visited[i] && canbe(i, stamp, target)){
                    count += replacethen(i, stamp.size(), target);
                    is_it_changing = true;
                    visited[i] = true;
                    res.push_back(i);
                    if(count == n)break;
                }
            }
            if(is_it_changing == false)return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
};