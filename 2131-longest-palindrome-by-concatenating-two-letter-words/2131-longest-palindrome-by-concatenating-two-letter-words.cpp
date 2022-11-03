#define ll long long int
class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        ll count = 0;
        int flag = 0;
        map<string, int>mp2;
        vector<string>words;
        for(auto x : w){
            if(x[0] == x[1]){
                mp2[x]++;
            }else{
                words.push_back(x);
            }
        }
        ll size = 0;
        for(auto x : mp2){
            if(x.second%2 == 1){
                flag=2;
            }
            cout << x.first << " " << x.second << endl;
            //if(x.second > 0 && (x.second)%2 == 0)
            if(x.second>=2){
                if(x.second%2==1){
                    size+= x.second-1;
                }
                else{
                    size+= x.second;
                }
            }
        }
        unordered_map<string, int>mp;
        for(auto x : words){
            string s1(x);
            reverse(s1.begin(),s1.end());
            if(mp.find(s1)==mp.end()){
                mp[x]++;
            }else{
                if(mp[s1]>0)
                {
                    mp[s1]--;
                    if(mp[s1] == 0){
                        mp.erase(s1);
                    }
                    count+=2;
                }
            }
        }
        return count*2+flag+size*2;
    }
};